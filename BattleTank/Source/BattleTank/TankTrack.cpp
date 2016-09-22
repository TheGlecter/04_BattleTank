// Copyright Oscar Crego 2016

#include "BattleTank.h"
#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{
	// TODO Clamp Throttle values

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

