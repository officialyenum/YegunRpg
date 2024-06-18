// Copyright Yenum dot dev


#include "Character/YegunCharacterBase.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/YegunAbilitySystemComponent.h"

AYegunCharacterBase::AYegunCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

UAbilitySystemComponent* AYegunCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AYegunCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AYegunCharacterBase::InitAbilityActorInfo()
{
}

void AYegunCharacterBase::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const
{
	check(IsValid(GetAbilitySystemComponent()))
	check(GameplayEffectClass)
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass,Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());

}

void AYegunCharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultSecondaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultVitalAttributes, 1.f);
}

void AYegunCharacterBase::AddCharacterAbilities()
{
	UYegunAbilitySystemComponent* YegunASC = CastChecked<UYegunAbilitySystemComponent>(AbilitySystemComponent);
	if (!HasAuthority()) return;
	
	YegunASC->AddCharacterAbilities(StartupAbilities);
}


