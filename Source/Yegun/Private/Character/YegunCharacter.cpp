// Copyright Yenum dot dev


#include "Character/YegunCharacter.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/YegunAbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/YegunPlayerController.h"
#include "Player/YegunPlayerState.h"
#include "UI/HUD/YegunHUD.h"

AYegunCharacter::AYegunCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f,400.f,0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AYegunCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init Ability Actor Info for the server
	InitAbilityActorInfo();
}

void AYegunCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	// Init Ability Actor Info for the client
	InitAbilityActorInfo();
}

void AYegunCharacter::InitAbilityActorInfo()
{
	AYegunPlayerState* YegunPlayerState =GetPlayerState<AYegunPlayerState>();
	check(YegunPlayerState);
	YegunPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(YegunPlayerState, this);
	Cast<UYegunAbilitySystemComponent>(YegunPlayerState->GetAbilitySystemComponent())->AbilityActorInfoSet();
	AbilitySystemComponent = YegunPlayerState->GetAbilitySystemComponent();
	AttributeSet = YegunPlayerState->GetAttributeSet();

	if(AYegunPlayerController* YegunPlayerController = Cast<AYegunPlayerController>(GetController()))
	{
		if(AYegunHUD* YegunHUD = Cast<AYegunHUD>(YegunPlayerController->GetHUD()))
		{
			YegunHUD->InitOverlay(YegunPlayerController,YegunPlayerState,AbilitySystemComponent,AttributeSet);
		}
	}
	
}
