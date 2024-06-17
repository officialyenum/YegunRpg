// Copyright Yenum dot dev


#include "AbilitySystem/YegunAbilitySystemLibrary.h"

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
