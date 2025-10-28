// Copyright Dystopia Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/BasePickup.h"
#include "Data/ItemData.h"
#include "MolotovPickup.generated.h"

UCLASS()
class PUNKGAME_API AMolotovPickup : public ABasePickup
{
    GENERATED_BODY()

protected:
    virtual void OnPickedUp_Implementation(AActor* PickingActor) override;
};
