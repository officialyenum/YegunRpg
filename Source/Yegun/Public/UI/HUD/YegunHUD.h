// Copyright Yenum dot dev

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/Widget/YegunUserWidget.h"
#include "YegunHUD.generated.h"

/**
 * 
 */
UCLASS()
class YEGUN_API AYegunHUD : public AHUD
{
	GENERATED_BODY()
public:
	UPROPERTY()
	TObjectPtr<UYegunUserWidget> OverlayWidget;
protected:
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditAnywhere, Category="HUD")
	TSubclassOf<UYegunUserWidget> OverlayWidgetClass;
};
 