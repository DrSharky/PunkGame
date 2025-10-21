// Copyright Dystopia Games, Inc. All Rights Reserved.


#include "Weapons/MolotovProjectile.h"

AMolotovProjectile::AMolotovProjectile()
{
	PrimaryActorTick.bCanEverTick = false;
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	CollisionComp->InitSphereRadius(8.f);
}