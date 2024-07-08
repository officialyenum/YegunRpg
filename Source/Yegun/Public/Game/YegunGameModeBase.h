// Copyright Yenum dot dev

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "YegunGameModeBase.generated.h"

class UCharacterClassInfo;
/**
 * 
 */
UCLASS()
class YEGUN_API AYegunGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, Category="Character Class Default")
	TObjectPtr<UCharacterClassInfo> CharacterClassInfo;
};
