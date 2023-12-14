// Copyright Yenum dot dev


#include "Character/YegunCharacterBase.h"

AYegunCharacterBase::AYegunCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

UAbilitySystemComponent* AYegunCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AYegunCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

