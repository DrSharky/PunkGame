// Copyright Dystopia Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Data/ItemData.h"
#include "InventoryItem.h"
#include "InventoryComponent.generated.h"

class ABaseWeapon;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PUNKGAME_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryComponent();

	void AddItem(UItemDataAsset* ItemData, int32 Quantity = 1);

	bool HasItem(FName ItemID) const;

	/*void AddWeapon(TSubclassOf<ABaseWeapon> WeaponClass);*/

	void EquipNextWeapon();

	ABaseWeapon* GetCurrentWeapon() const { return CurrentWeapon; }

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory")
	TArray<FInventoryItem> Items;

	virtual void BeginPlay() override;

private:
	UPROPERTY()
	TArray<ABaseWeapon*> Weapons;

	UPROPERTY()
	ABaseWeapon* CurrentWeapon;

	int32 CurrentIndex;

	void EquipWeapon(int32 Index);


};
