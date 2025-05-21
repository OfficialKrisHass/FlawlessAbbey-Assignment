#pragma once

#include "CoreMinimal.h"
#include "UI/UserWidgetBase.h"
#include "MainLayout.generated.h"

class UInventory;

class UCanvasPanel;

UCLASS(Abstract)
class FLAWLESSABBEY_API UMainLayout : public UUserWidgetBase {

	GENERATED_BODY()

public:
	inline TObjectPtr<UInventory> GetInventory() const { return inventory; }

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Widgets", meta = (BindWidget))
	TObjectPtr<UInventory> inventory = nullptr;
	
};
