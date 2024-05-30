// Copyright Yenum dot dev


#include "AbilitySystem/YegunAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

UYegunAttributeSet::UYegunAttributeSet()
{
	InitHealth(50.f);
	InitMaxHealth(100.0f);
	InitMana(80.f);
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
