// Copyright Yenum dot dev


#include "YegunAssetManager.h"
#include "YegunGameplayTags.h"
#include "AbilitySystemGlobals.h"

UYegunAssetManager& UYegunAssetManager::Get()
{
	check(GEngine);
	UYegunAssetManager* YegunAssetManager = Cast<UYegunAssetManager>(GEngine->AssetManager);
	return *YegunAssetManager;
}

void UYegunAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FYegunGameplayTags::InitializeNativeGameplayTags();

	//This is required to use target data
	UAbilitySystemGlobals::Get().InitGlobalData();
}
