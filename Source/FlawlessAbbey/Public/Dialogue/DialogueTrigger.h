#pragma once

#include "CoreMinimal.h"
#include "Player/Interactible.h"
#include "DialogueTrigger.generated.h"

class UDialogueScript;

UCLASS(Abstract)
class FLAWLESSABBEY_API ADialogueTrigger : public AInteractible {

	GENERATED_BODY()
	
public:
	ADialogueTrigger();

protected:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UDialogueScript> script = nullptr;

	void Interact(AFlawlessAbbeyCharacter* character) override;

};