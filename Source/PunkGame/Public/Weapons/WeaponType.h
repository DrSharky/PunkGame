// Copyright Dystopia Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	Melee UMETA(DisplayName = "Melee"),
	Ranged UMETA(DisplayName = "Ranged"),
	Explosive UMETA(DisplayName = "Explosive")
};