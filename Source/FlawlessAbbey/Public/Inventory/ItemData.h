#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemData.generated.h"

class UTexture2D;

UCLASS() class FLAWLESSABBEY_API UItemData : public UPrimaryDataAsset {

	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 id = -1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText displayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UTexture2D> icon = nullptr;

	inline bool operator==(const UItemData& other) const { return id == other.id; }
	
};
