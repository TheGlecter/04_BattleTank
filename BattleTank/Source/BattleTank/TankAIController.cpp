// Copyright Oscar Crego 2016

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Error, TEXT("AIController is not possesing a Tank!"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI-Controlled Tank: %s"), *(ControlledTank->GetName()));
	}

	FoundTank = GetPlayerTank();
	if (!FoundTank) {
		UE_LOG(LogTemp, Error, TEXT("AI can't find any player-controlled Tank!"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI found player-controlled Tank: %s"), *(FoundTank->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

