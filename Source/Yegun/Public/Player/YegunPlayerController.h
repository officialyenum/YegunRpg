// Copyright Yenum dot dev

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Input/YegunInputConfig.h"
#include "YegunPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class UYegunInputConfig;
class UYegunAbilitySystemComponent;
class USplineComponent;

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
	
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> ShiftAction;

	void ShiftPressed() { bShiftKeyDown = true; };
	void ShiftReleased(){ bShiftKeyDown = false; };
	bool bShiftKeyDown = false;
	void Move(const FInputActionValue& InputActionValue);

	void CursorTrace();

	IEnemyInterface* LastActor;
	IEnemyInterface* ThisActor;

	void AbilityInputTagHeld(FGameplayTag InputTag);
	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UYegunInputConfig> InputConfig;
	
	UPROPERTY(EditAnywhere, Category="Ability System")
	TObjectPtr<UYegunAbilitySystemComponent> YegunAbilitySystemComponent;

	UYegunAbilitySystemComponent* GetASC();

	FVector CachedDestination = FVector::Zero();
	float FollowTime = 0.f;
	float ShortPressThreshold = 0.5f;
	bool bAutoRunning = false;
	bool bTargeting = false;

	UPROPERTY(EditDefaultsOnly)
	float AutoRunAcceptanceRadius = 50.0f;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USplineComponent> Spline;

	void AutoRun();
	FHitResult CursorHit;
};
