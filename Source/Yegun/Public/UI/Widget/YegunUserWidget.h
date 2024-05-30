// Copyright Yenum dot dev

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "YegunUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class YEGUN_API UYegunUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;
protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
