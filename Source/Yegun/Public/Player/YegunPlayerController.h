// Copyright Yenum dot dev

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "YegunPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

struct FInputActionValue;
class IEnemyInterface;
/**
 * 
 */
UCLASS()
class YEGUN_API AYegunPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AYegunPlayerController();
	virtual void PlayerTick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> YegunContext;
	
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& InputActionValue);

	void CursorTrace();

	IEnemyInterface* LastActor;
	IEnemyInterface* ThisActor;
};
