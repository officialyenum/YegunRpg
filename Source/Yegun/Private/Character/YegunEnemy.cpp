// Copyright Yenum dot dev


#include "Character/YegunEnemy.h"

#include "Yegun/Yegun.h"

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
