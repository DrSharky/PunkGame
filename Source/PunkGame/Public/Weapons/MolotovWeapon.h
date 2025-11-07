// Copyright Dystopia Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/BaseWeapon.h"
#include "MolotovWeapon.generated.h"

/**
 * 
 */
UCLASS()
class PUNKGAME_API AMolotovWeapon : public ABaseWeapon
{
	GENERATED_BODY()
	

public:
	AMolotovWeapon();

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<class AMolotovProjectile> MolotovProjectileClass;

	virtual void UseWeapon() override;
};
