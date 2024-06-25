// Copyright Yenum dot dev


#include "AbilitySystem/YegunAbilitySystemComponent.h"

#include "YegunGameplayTags.h"
#include "AbilitySystem/Abilities/YegunGameplayAbility.h"

void UYegunAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UYegunAbilitySystemComponent::ClientEffectApplied);
}

void UYegunAbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities)
{
	for (TSubclassOf<UGameplayAbility> AbilityClass : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
		if (const UYegunGameplayAbility* YegunAbility = Cast<UYegunGameplayAbility>(AbilitySpec.Ability))
		{
			AbilitySpec.DynamicAbilityTags.AddTag(YegunAbility->StartupInputTag);
			GiveAbility(AbilitySpec);
		}
		
	}
}

void UYegunAbilitySystemComponent::AbilityInputTagHeld(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid()) return;

	for (FGameplayAbilitySpec& AbilitySpec: GetActivatableAbilities())
	{
		if (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag))
		{
			AbilitySpecInputPressed(AbilitySpec);
			if (!AbilitySpec.IsActive())
			{
				TryActivateAbility(AbilitySpec.Handle);
			}
		}
	}
}

void UYegunAbilitySystemComponent::AbilityInputTagReleased(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid()) return;

	for (FGameplayAbilitySpec& AbilitySpec: GetActivatableAbilities())
	{
		if (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag))
		{
			AbilitySpecInputReleased(AbilitySpec);
		}
	}
}

void UYegunAbilitySystemComponent::ClientEffectApplied_Implementation(UAbilitySystemComponent* AbilitySystemComponent,
                                                 const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle EffectHandle) const
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
