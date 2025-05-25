#include "UI/Dialogue/DialogueBox.h"

#include "Dialogue/DialogueScript.h"

#include <Components/TextBlock.h>

void UDialogueBox::SetLine(UDialogueScript* script, int32 lineIndex) {

	const FDialogueLine line = script->lines[lineIndex];
	const TObjectPtr<UDialogueCharacter> character = script->characters[line.characterIndex];

	text->SetText(line.text);
	text->SetColorAndOpacity(character->textColor);

	characterName->SetText(character->name);
	characterName->SetColorAndOpacity(character->textColor);

	if (character->rightJustified) {

		text->SetJustification(ETextJustify::Right);
		characterName->SetJustification(ETextJustify::Right);

	} else {

		text->SetJustification(ETextJustify::Left);
		characterName->SetJustification(ETextJustify::Left);

	}

}