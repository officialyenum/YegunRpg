// Copyright Yenum dot dev


#include "AbilitySystem/Data/CharacterClassInfo.h"

FCharacterClassDefaultInfo UCharacterClassInfo::GetCharacterClassDefaultInfo(ECharacterClass CharacterClass)
{
	return CharacterClassInformation.FindChecked(CharacterClass);
}
