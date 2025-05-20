#pragma once

#include "CoreMinimal.h"
#include "UI/UserWidgetBase.h"
#include "Inventory.generated.h"

class UTextBlock;
class UInventorySlot;

UCLASS(Abstract)
class FLAWLESSABBEY_API UInventory : public UUserWidgetBase {

	GENERATED_BODY()

public:
#if WITH_EDITOR
	virtual void OnDesignerChanged(const FDesignerChangedEventArgs& EventArgs) override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Widgets", meta = (BindWidget))
	TObjectPtr<UInventorySlot> slot0 = nullptr;
	UPROPERTY(BlueprintReadOnly, Category = "Widgets", meta = (BindWidget))
	TObjectPtr<UInventorySlot> slot1 = nullptr;
	UPROPERTY(BlueprintReadOnly, Category = "Widgets", meta = (BindWidget))
	TObjectPtr<UInventorySlot> slot2 = nullptr;
	UPROPERTY(BlueprintReadOnly, Category = "Widgets", meta = (BindWidget))
	TObjectPtr<UInventorySlot> slot3 = nullptr;

	virtual void NativeOnInitialized() override;

private:
	UPROPERTY()
	TArray<TObjectPtr<UInventorySlot>> m_slots;

	void UpdateWidget();
	
};
