// Copyright Yenum dot dev


#include "AbilitySystem/YegunAbilitySystemLibrary.h"

#include "Game/YegunGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Player/YegunPlayerState.h"
#include "UI/WidgetController/YegunWidgetController.h"
#include "UI/HUD/YegunHUD.h"

UOverlayWidgetController* UYegunAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	if(APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AYegunHUD* YegunHUD = Cast<AYegunHUD>(PC->GetHUD()))
		{
			AYegunPlayerState* PS = PC->GetPlayerState<AYegunPlayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
			return YegunHUD->GetOverlayWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}

UAttributeMenuWidgetController* UYegunAbilitySystemLibrary::GetAttributeMenuWidgetController(
	const UObject* WorldContextObject)
{
	if(APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AYegunHUD* YegunHUD = Cast<AYegunHUD>(PC->GetHUD()))
		{
			AYegunPlayerState* PS = PC->GetPlayerState<AYegunPlayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
			return YegunHUD->GetAttributeMenuWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}

void UYegunAbilitySystemLibrary::InitializeDefaultAttributes(const UObject* WorldContextObject,
	ECharacterClass CharacterClass, float Level, UAbilitySystemComponent* ASC)
{
	AYegunGameModeBase* YegunGameMode = Cast<AYegunGameModeBase>(UGameplayStatics::GetGameMode(WorldContextObject));

	if (YegunGameMode == nullptr) return;

	AActor* AvatarActor = ASC->GetAvatarActor();

	UCharacterClassInfo* ClassInfo = YegunGameMode->CharacterClassInfo;

	FCharacterClassDefaultInfo ClassDefaultInfo = ClassInfo->GetCharacterClassDefaultInfo(CharacterClass);

	FGameplayEffectContextHandle PrimaryAttributesContextHandle = ASC->MakeEffectContext();
	PrimaryAttributesContextHandle.AddSourceObject(AvatarActor);
	const FGameplayEffectSpecHandle PrimaryAttributeSpecHandle = ASC->MakeOutgoingSpec(ClassDefaultInfo.PrimaryAttributes, Level, PrimaryAttributesContextHandle);
	ASC->ApplyGameplayEffectSpecToSelf(*PrimaryAttributeSpecHandle.Data.Get());

	
	FGameplayEffectContextHandle SecondaryAttributesContextHandle = ASC->MakeEffectContext();
	SecondaryAttributesContextHandle.AddSourceObject(AvatarActor);
	const FGameplayEffectSpecHandle SecondaryAttributeSpecHandle = ASC->MakeOutgoingSpec(ClassInfo->SecondaryAttributes, Level, SecondaryAttributesContextHandle);
	ASC->ApplyGameplayEffectSpecToSelf(*SecondaryAttributeSpecHandle.Data.Get());
	
	FGameplayEffectContextHandle VitalAttributesContextHandle = ASC->MakeEffectContext();
	VitalAttributesContextHandle.AddSourceObject(AvatarActor);
	const FGameplayEffectSpecHandle VitalAttributeSpecHandle = ASC->MakeOutgoingSpec(ClassInfo->VitalAttributes, Level, VitalAttributesContextHandle);
	ASC->ApplyGameplayEffectSpecToSelf(*VitalAttributeSpecHandle.Data.Get());
}
