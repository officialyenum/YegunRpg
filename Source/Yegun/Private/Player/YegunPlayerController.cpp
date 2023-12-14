// Copyright Yenum dot dev


#include "Player/YegunPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"

AYegunPlayerController::AYegunPlayerController()
{
	bReplicates = true;
	
}

void AYegunPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AYegunPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(YegunContext);
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(YegunContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AYegunPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AYegunPlayerController::Move);
}

void AYegunPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0,Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if(APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
		
	}
}

void AYegunPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if(!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor());

	/**
	 *
	 * Line Trace from cursor.
	 *
	 * A. Last Actor && This Actor is null
	 *		- Do Nothing
	 * B. Last Actor is null but this Actor is Valid
	 *		- Highlight This Actor
	 * C. Last Actor is Valid but This Actor is Null
	 *		- UnHighlight Last Actor
	 * D. Last Actor is Valid and This Actor is Valid But LastActor != This Actor
	 *		- UnHighlight Last Actor and Highlit This Actor
	 * E. Last Actor is Valid and This Actor is Valid And LastActor == This Actor
	 *		- Do Nothing
	 ***/

	if(LastActor == nullptr)
	{
		if (ThisActor != nullptr)
		{
			// CASE B
			ThisActor->HighlightActor();
		}else
		{
			// Case A Do Nothing
		}
	}else
	{
		if(ThisActor == nullptr)
		{
			// CASE C
			LastActor->UnHighlightActor();
		}
		else // Both Actors are Valid
		{
			if (LastActor != ThisActor)
			{
				// CASE D
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
				
			}
			else
			{
				// CASE E DO NOTHING
			}
		}
	}
}
