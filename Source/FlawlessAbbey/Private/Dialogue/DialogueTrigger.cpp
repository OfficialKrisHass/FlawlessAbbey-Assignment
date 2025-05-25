#include "Dialogue/DialogueTrigger.h"
#include "Dialogue/DialogueManagerComponent.h"

#include "Player/FlawlessAbbeyCharacter.h"

#include <Components/BoxComponent.h>

ADialogueTrigger::ADialogueTrigger() {

	PrimaryActorTick.bCanEverTick = false;

}

void ADialogueTrigger::Interact(AFlawlessAbbeyCharacter* character) {

	if (script == nullptr) return;

	character->GetDialogueManagerComponent()->StartDialogue(script);

}