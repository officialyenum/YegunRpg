// Copyright Yenum dot dev


#include "Character/YegunEnemy.h"

#include "AbilitySystem/YegunAbilitySystemComponent.h"
#include "AbilitySystem/YegunAttributeSet.h"
#include "Yegun/Yegun.h"

AYegunEnemy::AYegunEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UYegunAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	AttributeSet = CreateDefaultSubobject<UYegunAttributeSet>("AttributeSet");
}

void AYegunEnemy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_PASS);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_PASS);
	// bHighlighted = true;
}

void AYegunEnemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	// bHighlighted = false;
}

int32 AYegunEnemy::GetPlayerLevel()
{
	return Level;
}

void AYegunEnemy::BeginPlay()
{
	Super::BeginPlay();
	InitAbilityActorInfo();

}

void AYegunEnemy::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<UYegunAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
	
}
