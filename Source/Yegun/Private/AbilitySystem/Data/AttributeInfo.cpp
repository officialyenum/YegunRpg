// Copyright Yenum dot dev


#include "AbilitySystem/Data/AttributeInfo.h"

FYegunAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& Tag, bool bLogNotFound) const
{
	for (const FYegunAttributeInfo& Info : AttributeInformation)
	{
		if (Info.AttributeTag.MatchesTagExact(Tag))
		{
			return Info;
		}
	}
	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find Info for AttributeTag [%s] on AttributeInfo [%s],"), *Tag.ToString(), *GetNameSafe(this))
	}
	return FYegunAttributeInfo();
}
