// Copyright Yenum dot dev


#include "Actor/YegunEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/YegunAttributeSet.h"

AYegunEffectActor::AYegunEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	
	Sphere = CreateDefaultSubobject<USphereComponent>("Shere");
	Sphere->SetupAttachment(GetRootComponent());

}

void AYegunEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* otherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(otherActor))
	{
		const UYegunAttributeSet* YegunAttributeSet = Cast<UYegunAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UYegunAttributeSet::StaticClass()));
		//TODO: Change this later
		UYegunAttributeSet* MutableYegunAttributeSet = const_cast<UYegunAttributeSet*>(YegunAttributeSet);
		MutableYegunAttributeSet->SetHealth(YegunAttributeSet->GetHealth() + 25.0f);
		Destroy();
	}
	
}

void AYegunEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void AYegunEffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AYegunEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AYegunEffectActor::EndOverlap);
	
}


