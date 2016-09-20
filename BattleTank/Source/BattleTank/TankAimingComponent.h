// Copyright Oscar Crego 2016

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Forward Declaration!
class UTankBarrel;

// Hold Barrel's properties and Elevate Method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);
	// TODO Add Set Turret Reference

	void AimAt(FVector HitLocation, float LaunchSpeed);
	
private:
	UTankBarrel* Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
};
