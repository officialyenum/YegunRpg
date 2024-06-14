// Copyright Yenum dot dev


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/YegunAbilitySystemComponent.h"
#include "AbilitySystem/YegunAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UYegunAttributeSet* YegunAttributeSet = CastChecked<UYegunAttributeSet>(AttributeSet);
	OnHealthChanged.Broadcast(YegunAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(YegunAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(YegunAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(YegunAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbackToDependencies()
{
	
	const UYegunAttributeSet* YegunAttributeSet = CastChecked<UYegunAttributeSet>(AttributeSet);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(YegunAttributeSet->GetHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data){OnHealthChanged.Broadcast(Data.NewValue);});
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(YegunAttributeSet->GetMaxHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data){OnMaxHealthChanged.Broadcast(Data.NewValue);});
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(YegunAttributeSet->GetManaAttribute()).AddLambda([this](const FOnAttributeChangeData& Data){OnManaChanged.Broadcast(Data.NewValue);});
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(YegunAttributeSet->GetMaxManaAttribute()).AddLambda([this](const FOnAttributeChangeData& Data){OnMaxManaChanged.Broadcast(Data.NewValue);});
	Cast<UYegunAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			
			for (const FGameplayTag& Tag : AssetTags)
			{
				// "Message.HealthPotion".MatchesTag("Message") will return True, "Message".MatchesTag("Message.HealthPotion") will return False
				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
				if(Tag.MatchesTag(MessageTag))
				{
					//TODO: Broadcast tag to Widget Controller
					const FString Msg = FString::Printf(TEXT("Broadcasted GE Tags : %s"), *Tag.GetTagName().ToString());
					GEngine->AddOnScreenDebugMessage(-1, 8.f,FColor::Blue,Msg);
					FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
					OnMessageWidgetRowDelegate.Broadcast(*Row);
				}
			}
		}
	);
}

