#include "Weapons/BaseWeapon.h"

// Sets default values
ABaseWeapon::ABaseWeapon()
{
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	RootComponent = Mesh;
}

void ABaseWeapon::UseWeapon() {}