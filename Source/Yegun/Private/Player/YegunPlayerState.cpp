// Copyright Yenum dot dev


#include "Player/YegunPlayerState.h"

#include "AbilitySystem/YegunAbilitySystemComponent.h"
#include "AbilitySystem/YegunAttributeSet.h"
#include "Net/UnrealNetwork.h"

AYegunPlayerState::AYegunPlayerState()
{
	

	AbilitySystemComponent = CreateDefaultSubobject<UYegunAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<UYegunAttributeSet>("AttributeSet");
	NetUpdateFrequency = 100.f;
}

void AYegunPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AYegunPlayerState, Level)
}

UAbilitySystemComponent* AYegunPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AYegunPlayerState::OnRep_Level(int32 OldLevel)
{
	Level = OldLevel;
}
