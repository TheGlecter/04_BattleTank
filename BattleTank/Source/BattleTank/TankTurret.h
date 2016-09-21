// Copyright Oscar Crego 2016

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Mobile"))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 25.f;
	
	
};
