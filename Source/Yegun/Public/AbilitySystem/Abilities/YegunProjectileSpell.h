// Copyright Yenum dot dev

#pragma once

#include "CoreMinimal.h"
#include "YegunGameplayAbility.h"
#include "Actor/YegunProjectile.h"
#include "YegunProjectileSpell.generated.h"

class UGameplayEffect;
/**
 * 
 */
UCLASS()
class YEGUN_API UYegunProjectileSpell : public UYegunGameplayAbility
{
	GENERATED_BODY()

protected:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	UFUNCTION(BlueprintCallable, Category="Projectile")
	void SpawnProjectile(const FVector& ProjectileTargetLocation);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AYegunProjectile> ProjectileClass;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> DamageEffectClass;
};
