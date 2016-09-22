// Copyright Oscar Crego 2016

#include "BattleTank.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	/// Delegate Components
	/// No need to protect pointers as added at construction.
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}


// Fire
void ATank::Fire()
{
	bool isReloaded = FPlatformTime::Seconds() - LastFireTime > ReloadTimeInSeconds;
		
	if (Barrel && isReloaded)
	{
		// Spawn Projectile at the Socket Location of the Barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
	else { return; }
}

/// Delegate Component Functions
void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}
