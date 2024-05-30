// Copyright Yenum dot dev


#include "UI/HUD/YegunHUD.h"

void AYegunHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}
