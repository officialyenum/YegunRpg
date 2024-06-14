// Copyright Yenum dot dev


#include "AbilitySystem/YegunAttributeSet.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/Character.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UYegunAttributeSet::UYegunAttributeSet()
{
	InitHealth(20.f);
	InitMaxHealth(100.0f);
	InitMana(10.f);
	InitMaxMana(100.f);
}

void UYegunAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UYegunAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UYegunAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UYegunAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UYegunAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void UYegunAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxMana());
	}
}

void UYegunAttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const
{
	// Source = effect causer (not owner of this), Target = effect target (owner of this)
	Props.EffectContextHandle = Data.EffectSpec.GetContext();
	Props.SourceASC = Props.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();

	if (IsValid(Props.SourceASC) && Props.SourceASC->AbilityActorInfo.IsValid() && Props.SourceASC->AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.SourceAvatarActor = Props.SourceASC->AbilityActorInfo->AvatarActor.Get();
		Props.SourceController = Props.SourceASC->AbilityActorInfo->PlayerController.Get();
		if (Props.SourceController == nullptr && Props.SourceAvatarActor !=nullptr)
		{
			if (APawn* Pawn = Cast<APawn>(Props.SourceAvatarActor))
			{
				Props.SourceController = Pawn->GetController();
			}
		}
		if (Props.SourceController)
		{
			Props.SourceCharacter = Cast<ACharacter>(Props.SourceController->GetPawn());
		}
	}

	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		Props.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		Props.TargetCharacter = Cast<ACharacter>(Props.TargetAvatarActor);

		Props.TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Props.TargetAvatarActor);
	}
	
}

void UYegunAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	// Remember to call the parent's implementation.
	Super::PostGameplayEffectExecute(Data);

	FEffectProperties Props;

	SetEffectProperties(Data, Props);
	
	
	
	
	
	// Check to see if this call affects our Health by using the Property Getter.
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		// This Gameplay Effect is changing Health. Apply it, but restrict the value first.
		// In this case, Health's base value must be non-negative.
		UE_LOG(LogTemp, Warning, TEXT("Health From GetHealth(): %f"), GetHealth())
		UE_LOG(LogTemp, Warning, TEXT("Magnitude: %f"), Data.EvaluatedData.Magnitude)
		SetHealth(FMath::Max(GetHealth(), 0.0f));
	}
	// Check to see if this call affects our Health by using the Property Getter.
	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		// This Gameplay Effect is changing Health. Apply it, but restrict the value first.
		// In this case, Health's base value must be non-negative.
		UE_LOG(LogTemp, Warning, TEXT("Mana From GetMana(): %f"), GetMana())
		UE_LOG(LogTemp, Warning, TEXT("Magnitude: %f"), Data.EvaluatedData.Magnitude)
		SetMana(FMath::Max(GetMana(), 0.0f));
	}
}

void UYegunAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UYegunAttributeSet, Health, OldHealth);
}

void UYegunAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UYegunAttributeSet, MaxHealth, OldMaxHealth);
}

void UYegunAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UYegunAttributeSet, Mana, OldMana);
}

void UYegunAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UYegunAttributeSet, MaxMana, OldMaxMana);
}


