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

	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("DONKEY: %s: Tank Construct!"), *TankName);
}

void ATank::BeginPlay()
{
	Super::BeginPlay();	// Needed to get the Blueprint's BeginPlay to work!
	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("DONKEY: %s: Tank BeginPlay!"), *TankName);
}

void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

// Fire
void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }
	bool isReloaded = FPlatformTime::Seconds() - LastFireTime > ReloadTimeInSeconds;
		
	if (isReloaded) {
		// Spawn Projectile at the Socket Location of the Barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
		ProjectileBlueprint,
		Barrel->GetSocketLocation(FName("Projectile")),
		Barrel->GetSocketRotation(FName("Projectile"))
		);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}