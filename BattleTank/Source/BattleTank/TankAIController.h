// Copyright Oscar Crego 2016

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"


UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	// How close to the Player can the AI tank get.
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 8000;

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// Called by the engine when a Pawn is possesed
	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnPossesedTankDeath();
};
