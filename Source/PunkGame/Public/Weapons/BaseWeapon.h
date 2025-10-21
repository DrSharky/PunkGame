#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

UCLASS()
class PUNKGAME_API ABaseWeapon : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseWeapon();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	virtual void UseWeapon();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	UStaticMeshComponent* Mesh;
};
