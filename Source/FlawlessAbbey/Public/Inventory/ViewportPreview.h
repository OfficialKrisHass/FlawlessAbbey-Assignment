#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ViewportPreview.generated.h"

class UStaticMeshComponent;
class USceneCaptureComponent2D;

UCLASS()
class FLAWLESSABBEY_API AViewportPreview : public AActor {

	GENERATED_BODY()
	
public:
	AViewportPreview();

protected:
	UPROPERTY(EditAnywhere, Category = "Components")
	TObjectPtr<UStaticMeshComponent> mesh = nullptr;

	UPROPERTY(EditAnywhere, Category = "Components")
	TObjectPtr<USceneCaptureComponent2D> sceneCapture = nullptr;

private:
	virtual void BeginPlay() override;
	
};