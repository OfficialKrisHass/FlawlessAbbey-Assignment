#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainHUD.generated.h"

class UMainLayout;

UCLASS(Abstract)
class FLAWLESSABBEY_API AMainHUD : public AHUD {

	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UMainLayout> layoutClass;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	TObjectPtr<UMainLayout> layout = nullptr;
	
};
