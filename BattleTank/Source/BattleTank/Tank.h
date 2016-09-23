// Copyright Oscar Crego 2016

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward Declarations
class AProjectile;
class UTankBarrel;
class UTankTurret;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

private:
	virtual void BeginPlay() override;

	// Sets default values for this pawn's properties
	ATank();

	//TODO Remove once Fire() is moved to Aim component
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 5000.f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	// Local Barrel reference for spawning projectiles
	UTankBarrel* Barrel = nullptr;	// TODO Remove this Reference

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;
	double LastFireTime = 0;
};
