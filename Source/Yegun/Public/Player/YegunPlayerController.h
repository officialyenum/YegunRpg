// Copyright Yenum dot dev

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "YegunPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

struct FInputValue;
/**
 * 
 */
UCLASS()
class YEGUN_API AYegunPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AYegunPlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> YegunContext;
	
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& InputActionValue);
};
