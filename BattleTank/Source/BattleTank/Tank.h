// Copyright Oscar Crego 2016

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward Declarations
class AProjectile;
class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

	void AimAt(FVector HitLocation);

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 5000.f;	// TODO Find Sensible default value

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	// Local Barrel reference for spawning projectiles
	UTankBarrel* Barrel = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeInSeconds = 3;
	double LastFireTime = 0;
};
