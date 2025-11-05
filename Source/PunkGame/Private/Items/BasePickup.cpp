// Copyright Dystopia Games, Inc. All Rights Reserved.


#include "Items/BasePickup.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"
#include "Inventory/InventoryComponent.h"
#include "Components/StaticMeshComponent.h"
#include <PunkGame/PunkGameCharacter.h>

// Sets default values
ABasePickup::ABasePickup()
{
	PrimaryActorTick.bCanEverTick = false;

	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComp"));
	CollisionComp->InitSphereRadius(50.f);
	CollisionComp->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	RootComponent = CollisionComp;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &ABasePickup::OnOverlapBegin);
}

void ABasePickup::OnOverlapBegin(
	UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult
)
{
	if (OtherActor == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("OnOverlapBegin: OtherActor is null."));
		return;
	}
	if (OtherActor && (OtherActor != this))
	{
		OnPickedUp(OtherActor);
	}
}

void ABasePickup::OnPickedUp_Implementation(AActor* PickingActor)
{
	if (PickingActor == nullptr)
	{
		return;
	}

	if (!IsValid(PickingActor))
	{
		return;
	}

	if (APunkGameCharacter* Character = Cast<APunkGameCharacter>(PickingActor))
	{
		if (Character == nullptr)
		{
			return;
		}
		/*UE_LOG(LogTemp, Log, TEXT("%s picked up a %s"), *Character->GetName(), *this->GetName());*/

		if (UInventoryComponent* InventoryComp = Character->FindComponentByClass<UInventoryComponent>())
		{

			if (InventoryComp == nullptr)
			{
				return;
			}

			InventoryComp->AddItem(ItemData);
			UE_LOG(LogTemp, Log, TEXT("%s added to inventory."), *this->GetName());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No InventoryComponent found on %s."), *Character->GetName());
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Cast of character failed."));
	}
	Destroy();
}