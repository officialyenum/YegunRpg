// Copyright Yenum dot dev


#include "Character/YegunCharacterBase.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/YegunAbilitySystemComponent.h"
#include "Components/CapsuleComponent.h"
#include "Yegun/Yegun.h"

AYegunCharacterBase::AYegunCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetCapsuleComponent()->SetGenerateOverlapEvents(false);
	GetMesh()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECC_Projectile, ECR_Overlap);
	GetMesh()->SetGenerateOverlapEvents(true);
	
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

FVector AYegunCharacterBase::GetCombatSocketLocation()
{
	check(Weapon);
	return Weapon->GetSocketLocation(WeaponTipSocketName);
}

void AYegunCharacterBase::InitAbilityActorInfo()
{
}

void AYegunCharacterBase::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const
{
	check(IsValid(GetAbilitySystemComponent()))
	check(GameplayEffectClass)
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass,Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());

}

void AYegunCharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultSecondaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultVitalAttributes, 1.f);
}

void AYegunCharacterBase::AddCharacterAbilities() const
{
	UYegunAbilitySystemComponent* YegunASC = CastChecked<UYegunAbilitySystemComponent>(AbilitySystemComponent);
	if (!HasAuthority()) return;
	
	YegunASC->AddCharacterAbilities(StartupAbilities);
}


