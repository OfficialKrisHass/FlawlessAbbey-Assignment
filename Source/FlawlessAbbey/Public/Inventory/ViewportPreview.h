#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ViewportPreview.generated.h"

class UStaticMeshComponent;
class USpringArmComponent;
class USceneCaptureComponent2D;

UCLASS()
class FLAWLESSABBEY_API AViewportPreview : public AActor {

	GENERATED_BODY()
	
public:
	AViewportPreview();

	UFUNCTION(BlueprintCallable)
	void SetMesh(UStaticMesh* itemMesh);

	UFUNCTION(BlueprintCallable)
	inline UMaterialInterface* GetOutputMaterial() const { return outMaterial; }

	UFUNCTION(BlueprintCallable)
	void Rotate(FVector2D delta);
	UFUNCTION(BlueprintCallable)
	void Zoom(float delta);

protected:
	UPROPERTY(EditAnywhere, Category = "Components")
	TObjectPtr<UStaticMeshComponent> mesh = nullptr;

	UPROPERTY(EditAnywhere, Category = "Components")
	TObjectPtr<USpringArmComponent> springArm = nullptr;
	UPROPERTY(EditAnywhere, Category = "Components")
	TObjectPtr<USceneCaptureComponent2D> sceneCapture = nullptr;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UMaterialInterface> outMaterial = nullptr;

	UPROPERTY(EditAnywhere)
	float rotationSpeed = 1.0f;
	UPROPERTY(EditAnywhere)
	float zoomSpeed = 1.0f;

	UPROPERTY(EditAnywhere)
	float minSpringLen = 10.0f;
	UPROPERTY(EditAnywhere)
	float maxSpringLen = 10.0f;

private:
	virtual void BeginPlay() override;
	
};