﻿// Copyright Yenum dot dev


#include "Input/YegunInputConfig.h"

const UInputAction* UYegunInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag,
	bool bLogNotFound) const
{
	for (auto Action : AbilityInputActions)
	{
		if (Action.InputAction && Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}
	}
	if (bLogNotFound)
	{
		UE_LOG(
			LogTemp,
			Error,
			TEXT("Can't find AbilityInputAction for InputTag [%s], on InputConfig [%s]"),
			*InputTag.ToString(),
			*GetNameSafe(this)
			)
	}

	return nullptr;
}