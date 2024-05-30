// Copyright Yenum dot dev


#include "UI/WidgetController/OverlayWidgetController.h"

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
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(YegunAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(YegunAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(YegunAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(YegunAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
