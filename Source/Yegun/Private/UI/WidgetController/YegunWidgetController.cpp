// Copyright Yenum dot dev


#include "UI/WidgetController/YegunWidgetController.h"

void UYegunWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UYegunWidgetController::BroadcastInitialValues()
{
	
}

void UYegunWidgetController::BindCallbackToDependencies()
{
}
