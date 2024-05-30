// Copyright Yenum dot dev

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "YegunWidgetController.generated.h"

/**
 * 
 */
UCLASS()
class YEGUN_API UYegunWidgetController : public UObject
{
	GENERATED_BODY()
protected:
	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<APlayerController> PlayerController;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<APlayerState> PlayerState;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<UAttributeSet> AttributeSet;
};
