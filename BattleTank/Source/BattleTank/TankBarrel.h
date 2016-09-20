// Copyright Oscar Crego 2016

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max low speed. +1 is max top speed. Clamps higher values.
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 5.f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 40.f;
	
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 0.f;
	
	
};
