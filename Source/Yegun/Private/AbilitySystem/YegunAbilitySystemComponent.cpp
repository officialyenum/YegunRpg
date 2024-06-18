// Copyright Yenum dot dev


#include "AbilitySystem/YegunAbilitySystemComponent.h"

#include "YegunGameplayTags.h"

void UYegunAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UYegunAbilitySystemComponent::EffectApplied);
	const FYegunGameplayTags& GameplayTags = FYegunGameplayTags::Get();
	GEngine->AddOnScreenDebugMessage(
		-1,
		10.f,
		FColor::Orange,
		FString::Printf(TEXT("Tag: %s"), *GameplayTags.Attributes_Secondary_Armor.ToString())
		);
}

void UYegunAbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities)
{
	for (TSubclassOf<UGameplayAbility> AbilityClass : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
		// GiveAbility(AbilitySpec);
		GiveAbilityAndActivateOnce(AbilitySpec);
	}
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
