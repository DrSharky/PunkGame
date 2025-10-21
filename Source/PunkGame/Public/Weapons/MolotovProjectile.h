// Copyright Dystopia Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/BaseProjectile.h"
#include "MolotovProjectile.generated.h"

/**
 * 
 */
UCLASS()
class PUNKGAME_API AMolotovProjectile : public ABaseProjectile
{
	GENERATED_BODY()

public:
    AMolotovProjectile();
	
protected:
    // Fire effect actor to spawn
    UPROPERTY(EditDefaultsOnly, Category = "Effects")
    TSubclassOf<AActor> FireEffectActor;

    // Damage or fire duration
    UPROPERTY(EditDefaultsOnly, Category = "Effects")
    float FireDuration;
};
