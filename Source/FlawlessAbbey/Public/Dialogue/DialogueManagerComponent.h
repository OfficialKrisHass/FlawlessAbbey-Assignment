#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DialogueManagerComponent.generated.h"

class UDialogueScript;

class UDialogueBox;

class UInputAction;
class UInputMappingContext;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FLAWLESSABBEY_API UDialogueManagerComponent : public UActorComponent {

	GENERATED_BODY()

public:
	UDialogueManagerComponent();

	UFUNCTION(BlueprintCallable)
	void StartDialogue(UDialogueScript* script);
	UFUNCTION(BlueprintCallable)
	void AdvanceDialogue();
	UFUNCTION(BlueprintCallable)
	void EndDialogue();

	virtual void TickComponent(float deltaTime, ELevelTick tickType, FActorComponentTickFunction* thisTickFunction) override;

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UDialogueBox> dialogueBoxClass;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> advanceAction = nullptr;
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> dialogueMappingContext = nullptr;

private:
	virtual void BeginPlay() override;

	UPROPERTY()
	TObjectPtr<UDialogueBox> m_dialogueBox = nullptr;

	UPROPERTY()
	TObjectPtr<UDialogueScript> m_script = nullptr;
	int32 m_lineIndex = -1;
	
};