// Copyright Yenum dot dev


#include "Player/YegunPlayerState.h"

#include "AbilitySystem/YegunAbilitySystemComponent.h"
#include "AbilitySystem/YegunAttributeSet.h"

AYegunPlayerState::AYegunPlayerState()
{
	

	AbilitySystemComponent = CreateDefaultSubobject<UYegunAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<UYegunAttributeSet>("AttributeSet");
	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* AYegunPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
