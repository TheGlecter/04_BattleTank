// Copyright Oscar Crego 2016

#include "BattleTank.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float DegreesPerSecond)
{
	UE_LOG(LogTemp, Warning, TEXT("Barrel->Elevate() Called at speed %f"), DegreesPerSecond);
}
