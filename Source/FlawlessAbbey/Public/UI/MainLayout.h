#pragma once

#include "CoreMinimal.h"
#include "UI/UserWidgetBase.h"
#include "MainLayout.generated.h"

class UInventory;

UCLASS(Abstract)
class FLAWLESSABBEY_API UMainLayout : public UUserWidgetBase {

	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Widgets", meta = (BindWidget))
	TObjectPtr<UInventory> inventory = nullptr;
	
};
