// Copyright Yenum dot dev

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "YegunCharacterBase.generated.h"

UCLASS(Abstract)
class YEGUN_API AYegunCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AYegunCharacterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

};
