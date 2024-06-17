// Copyright Yenum dot dev


#include "UI/WidgetController/AttributeMenuWidgetController.h"

#include "YegunGameplayTags.h"
#include "AbilitySystem/YegunAttributeSet.h"

void UAttributeMenuWidgetController::BindCallbackToDependencies()
{
	const UYegunAttributeSet* AS = CastChecked<UYegunAttributeSet>(AttributeSet);
	check(AttributeInfo);
	
	for (const TTuple<FGameplayTag, FGameplayAttribute(*)()>& Pair : AS->TagsToAttribute)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
		[this, Pair, AS](const FOnAttributeChangeData& Data)
		{
			BroadcastAttributeInfo(Pair.Key, Pair.Value());
		});
	}
	
}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	UYegunAttributeSet* AS = CastChecked<UYegunAttributeSet>(AttributeSet);
	check(AttributeInfo);

	for (TTuple<FGameplayTag, FGameplayAttribute(*)()>& Pair : AS->TagsToAttribute)
	{
		BroadcastAttributeInfo(Pair.Key, Pair.Value());
	}
}

void UAttributeMenuWidgetController::BroadcastAttributeInfo(const FGameplayTag& AttributeTag,
	const FGameplayAttribute& Attribute) const
{
	FYegunAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(AttributeTag);
	Info.AttributeValue = Attribute.GetNumericValue(AttributeSet);
	AttributeInfoDelegate.Broadcast(Info);
}
