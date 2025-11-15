// Copyright Dystopia Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/BaseWeapon.h"
#include "Weapons/Throwable.h"
#include "ExplosiveWeapon.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, Category="Weapon")
class PUNKGAME_API AExplosiveWeapon : public ABaseWeapon, public IThrowable
{
	GENERATED_BODY()
	
public:
	AExplosiveWeapon();
	virtual void UseWeapon() override;

	virtual void Throw() override;
};
