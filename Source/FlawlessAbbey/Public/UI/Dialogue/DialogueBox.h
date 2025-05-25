#pragma once

#include "CoreMinimal.h"
#include "UI/UserWidgetBase.h"
#include "DialogueBox.generated.h"

class UDialogueScript;

class UTextBlock;

UCLASS(Abstract)
class FLAWLESSABBEY_API UDialogueBox : public UUserWidgetBase {

	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetLine(UDialogueScript* script, int32 lineIndex);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Widgets", meta = (BindWidget))
	TObjectPtr<UTextBlock> characterName = nullptr;
	UPROPERTY(BlueprintReadOnly, Category = "Widgets", meta = (BindWidget))
	TObjectPtr<UTextBlock> text = nullptr;
	
};
