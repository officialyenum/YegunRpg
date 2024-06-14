// Copyright Yenum dot dev


#include "AbilitySystem/YegunAbilitySystemComponent.h"

void UYegunAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UYegunAbilitySystemComponent::EffectApplied);
}

void UYegunAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
                                                 const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle EffectHandle)
{
	// GEngine->AddOnScreenDebugMessage(1, 8.f,FColor::Blue,FString("Effect Applied"));
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	EffectAssetTags.Broadcast(TagContainer);
	for (const FGameplayTag& Tag : TagContainer)
	{
			//TODO: Broadcast tag to Widget Controller
			const FString Msg = FString::Printf(TEXT("GE Tags : %s"), *Tag.GetTagName().ToString());
			GEngine->AddOnScreenDebugMessage(-1, 8.f,FColor::Blue,Msg);
	}
}
