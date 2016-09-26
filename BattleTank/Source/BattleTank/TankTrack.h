// Copyright Oscar Crego 2016

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/*
TankTrack is used to apply forces to the Tank and set the maximum driving forces.
*/
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// Sets a throttle between -1 and +1.
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);
	
	// Max force per track, in Newtons
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 400000; // Assume 40t tank and 1g acceleration

private:
	UTankTrack();

	virtual void BeginPlay() override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
	
	void ApplySidewaysForce();
	void DriveTrack();

	float CurrentThrottle = 0;
};
