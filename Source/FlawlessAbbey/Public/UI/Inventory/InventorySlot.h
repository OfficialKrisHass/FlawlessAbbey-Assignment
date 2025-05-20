#pragma once

#include "CoreMinimal.h"
#include "UI/UserWidgetBase.h"
#include "InventorySlot.generated.h"

class UButton;
class UImage;

UCLASS()
class FLAWLESSABBEY_API UInventorySlot : public UUserWidgetBase {

	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Widgets", meta = (BindWidget))
	TObjectPtr<UButton> button = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Widgets", meta = (BindWidget))
	TObjectPtr<UImage> icon = nullptr;

	virtual void NativeOnInitialized() override;
	
};