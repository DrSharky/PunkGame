// Copyright Dystopia Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Data/ItemData.h"
#include "BasePickup.generated.h"

UCLASS()
class PUNKGAME_API ABasePickup : public AActor
{
	GENERATED_BODY()
	
public:	
	ABasePickup();

	UPROPERTY(EditDefaultsOnly, Category = "Pickup")
	FItemData ItemData;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
	class USphereComponent* CollisionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
	class UStaticMeshComponent* MeshComp;

	UFUNCTION()
	virtual void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult
	);

	UFUNCTION(BlueprintNativeEvent, Category = "Pickup")
	void OnPickedUp(AActor* PickingActor);

	virtual void OnPickedUp_Implementation(AActor* PickingActor);

	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};