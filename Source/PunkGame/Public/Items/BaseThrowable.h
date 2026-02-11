// Copyright Dystopia Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseThrowable.generated.h"

UCLASS()
class PUNKGAME_API ABaseThrowable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseThrowable();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item")
	class USphereComponent* CollisionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item")
	class UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item")
	float Weight;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
