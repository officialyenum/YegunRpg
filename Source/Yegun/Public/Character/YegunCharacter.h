// Copyright Yenum dot dev

#pragma once

#include "CoreMinimal.h"
#include "Character/YegunCharacterBase.h"
#include "YegunCharacter.generated.h"

/**
 * 
 */
UCLASS()
class YEGUN_API AYegunCharacter : public AYegunCharacterBase
{
	GENERATED_BODY()
public:
	AYegunCharacter();
	virtual void PossessedBy(AController* NewController) override;

	virtual void OnRep_PlayerState() override;
private:
	virtual void InitAbilityActorInfo() override;
};
