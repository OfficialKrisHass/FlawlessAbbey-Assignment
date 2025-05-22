#include "Pickup/ItemPickup.h"

#include "Player/FlawlessAbbeyCharacter.h"

#include "Inventory/InventoryComponent.h"

#include <Components/StaticMeshComponent.h>
#include <Components/BoxComponent.h>

AItemPickup::AItemPickup() {

	PrimaryActorTick.bCanEverTick = false;

	m_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(m_mesh);

	// Simulate physics, but no collisions with the player character

	m_mesh->SetSimulatePhysics(true);
	m_mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	m_mesh->SetCollisionResponseToAllChannels(ECR_Block);
	m_mesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);


	m_trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	m_trigger->SetupAttachment(m_mesh);

	m_trigger->OnComponentBeginOverlap.AddDynamic(this, &AItemPickup::BeginOverlap);

	// No physics, only overlap with the player

	m_trigger->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	m_trigger->SetCollisionObjectType(ECC_WorldDynamic);
	m_trigger->SetCollisionResponseToAllChannels(ECR_Ignore);
	m_trigger->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

}

void AItemPickup::BeginPlay() {

	Super::BeginPlay();

}

void AItemPickup::BeginOverlap(UPrimitiveComponent* overlapedComponent, AActor* actor, UPrimitiveComponent* otherComponent, int32 otherIndex, bool fromSweep, const FHitResult& sweepResult) {

	if (m_item == nullptr) return;

	TObjectPtr<AFlawlessAbbeyCharacter> player = Cast<AFlawlessAbbeyCharacter>(actor);
	if (player == nullptr) return;

	player->GetInventoryComponent()->AddItem(m_item);
	player->GetInventoryComponent()->UpdateInventoryUI();

	Destroy();

}