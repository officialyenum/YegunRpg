// Copyright Yenum dot dev


#include "UI/Widget/YegunUserWidget.h"

void UYegunUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
