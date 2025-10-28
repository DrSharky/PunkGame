// Copyright Dystopia Games, Inc.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Data/ItemData.h"
#include "InventoryComponent.generated.h"

class ABaseWeapon;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PUNKGAME_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryComponent();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	TArray<FItemData> Items;

	void AddItem(const FItemData& ItemData);

	void AddWeapon(TSubclassOf<ABaseWeapon> WeaponClass);

	void EquipNextWeapon();

	ABaseWeapon* GetCurrentWeapon() const { return CurrentWeapon; }

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	TArray<ABaseWeapon*> Weapons;

	UPROPERTY()
	ABaseWeapon* CurrentWeapon;

	int32 CurrentIndex;

	void EquipWeapon(int32 Index);


};
