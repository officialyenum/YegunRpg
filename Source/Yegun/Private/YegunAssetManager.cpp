// Copyright Yenum dot dev


#include "YegunAssetManager.h"
#include "YegunGameplayTags.h"

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
}
