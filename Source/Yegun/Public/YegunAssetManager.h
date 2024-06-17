// Copyright Yenum dot dev

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "YegunAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class YEGUN_API UYegunAssetManager : public UAssetManager
{
	GENERATED_BODY()
public:
	static UYegunAssetManager& Get();

protected:
	virtual void StartInitialLoading() override;
};
