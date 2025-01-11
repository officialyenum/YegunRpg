// Copyright Yenum dot dev

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "YegunGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class YEGUN_API UYegunGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly, Category="Input")
	FGameplayTag StartupInputTag;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Damage")
	FScalableFloat Damage;
};
