#pragma once

#include "CoreMinimal.h"
#include "UI/UserWidgetBase.h"
#include "InventorySlot.generated.h"

class UItemData;

class UItemIcon;
class UButton;

UCLASS(Abstract)
class FLAWLESSABBEY_API UInventorySlot : public UUserWidgetBase {

	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	inline void SetIndex(int32 value) { m_index = value; }

	UFUNCTION(BlueprintCallable)
	inline int32 GetIndex() const { return m_index; }

	UFUNCTION(BlueprintCallable)
	virtual void SetItem(UItemData* item);

	UFUNCTION(BlueprintCallable)
	inline UItemData* GetItem() const { return m_item; }

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Widgets", meta = (BindWidget))
	TObjectPtr<UButton> button = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Widgets", meta = (BindWidget))
	TObjectPtr<UItemIcon> icon = nullptr;

	virtual void NativeConstruct() override;

	virtual bool NativeOnDrop(const FGeometry& geometry, const FDragDropEvent& event, UDragDropOperation* operation) override;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UItemData> m_item = nullptr;

	UPROPERTY(VisibleAnywhere)
	int32 m_index = -1;
	
};