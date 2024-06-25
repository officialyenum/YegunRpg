// Copyright Yenum dot dev


#include "AbilitySystem/Abilities/YegunProjectileSpell.h"

#include "Interaction/CombatInterface.h"
#include "Kismet/KismetSystemLibrary.h"

void UYegunProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                            const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                            const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

}

void UYegunProjectileSpell::SpawnProjectile()
{
	const bool bIsServer = GetAvatarActorFromActorInfo()->HasAuthority();
	if (!bIsServer) return;

	if (ICombatInterface* CombatInterface = Cast<ICombatInterface>(GetAvatarActorFromActorInfo()))
	{
		const FVector SocketLocation = CombatInterface->GetCombatSocketLocation();
		FTransform SpawnTransform;
		SpawnTransform.SetLocation(SocketLocation);
		//TODO: Set Projectile Rotation
		
		AYegunProjectile* Projectile = GetWorld()->SpawnActorDeferred<AYegunProjectile>(
			ProjectileClass,
			SpawnTransform,
			GetOwningActorFromActorInfo(),
			Cast<APawn>(GetOwningActorFromActorInfo()),
			ESpawnActorCollisionHandlingMethod::AlwaysSpawn
			);
		
		//TODO: Give the projectile a Gameplay Effect Spec for Causing Damage
		
		Projectile->FinishSpawning(SpawnTransform);
	}
}
