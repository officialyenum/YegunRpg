// Copyright Yenum dot dev

#pragma once

#include "CoreMinimal.h"
#include "YegunWidgetController.h"
#include "AbilitySystem/Data/AttributeInfo.h"
#include "AttributeMenuWidgetController.generated.h"

class UAttributeInfo;
struct FYegunAttributeInfo;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeInfoSignature, const FYegunAttributeInfo&, Info);
/**
 * 
 */
UCLASS(BlueprintType,Blueprintable)
class YEGUN_API UAttributeMenuWidgetController : public UYegunWidgetController
{
	GENERATED_BODY()
public:
	virtual void BindCallbackToDependencies() override;
	virtual void BroadcastInitialValues() override;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnAttributeInfoSignature AttributeInfoDelegate;

protected:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UAttributeInfo> AttributeInfo;

private:
	void BroadcastAttributeInfo(const FGameplayTag& AttributeTag, const FGameplayAttribute& Attribute) const;
};
