#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DialogueScript.generated.h"

class UDialogueCharacter;

USTRUCT(BlueprintType)
struct FLAWLESSABBEY_API FDialogueLine {

	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 characterIndex = -1;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText text;

};

UCLASS(BlueprintType)
class FLAWLESSABBEY_API UDialogueScript : public UPrimaryDataAsset {

	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FDialogueLine> lines;
	UPROPERTY(EditAnywhere, Instanced, BlueprintReadOnly)
	TArray<TObjectPtr<UDialogueCharacter>> characters;
	
};

// Normally this would be a data asset so that we could create a character once and reference it in other dialogue scripts, but for
// simplicity sake and because I am too lazy, I am doing it this way. That is why it's a class and is Instanced.
UCLASS(BlueprintType, EditInlineNew)
class FLAWLESSABBEY_API UDialogueCharacter : public UObject {

	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FColor textColor = FColor::White;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool rightJustified = false;

};