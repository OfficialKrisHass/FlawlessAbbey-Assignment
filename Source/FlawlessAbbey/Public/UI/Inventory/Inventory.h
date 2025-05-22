#pragma once

#include "CoreMinimal.h"
#include "UI/UserWidgetBase.h"
#include "Inventory.generated.h"

struct FItemSlot;

class UInventorySlot;
class UViewportSlot;
class UButton;

UCLASS(Abstract)
class FLAWLESSABBEY_API UInventory : public UUserWidgetBase {

	GENERATED_BODY()

public:
	void Update(const TArray<FItemSlot>& slots);

	UFUNCTION(BlueprintCallable)
	void CloseInventory();

	UFUNCTION(BlueprintCallable)
	void OpenInventory();

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Widgets", meta = (BindWidget))
	TObjectPtr<UInventorySlot> slot0 = nullptr;
	UPROPERTY(BlueprintReadOnly, Category = "Widgets", meta = (BindWidget))
	TObjectPtr<UInventorySlot> slot1 = nullptr;
	UPROPERTY(BlueprintReadOnly, Category = "Widgets", meta = (BindWidget))
	TObjectPtr<UInventorySlot> slot2 = nullptr;
	UPROPERTY(BlueprintReadOnly, Category = "Widgets", meta = (BindWidget))
	TObjectPtr<UInventorySlot> slot3 = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Widgets", meta = (BindWidget))
	TObjectPtr<UViewportSlot> viewportSlot = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Widgets", meta = (BindWidget))
	TObjectPtr<UButton> closeButton = nullptr;

	virtual void NativeConstruct() override;

private:
	UPROPERTY()
	TArray<TObjectPtr<UInventorySlot>> m_slots;
	
};
