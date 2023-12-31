// Copyright Yenum dot dev

#pragma once

#include "CoreMinimal.h"
#include "Character/YegunCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "YegunEnemy.generated.h"

/**
 * 
 */
UCLASS()
class YEGUN_API AYegunEnemy : public AYegunCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AYegunEnemy();

	// Enemy Interface
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	// End Enemy Interface

protected:
	virtual void BeginPlay() override;
};
