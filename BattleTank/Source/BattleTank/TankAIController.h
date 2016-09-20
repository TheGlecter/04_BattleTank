// Copyright Oscar Crego 2016

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

// Forward Declarations
class ATank;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	ATank* GetControlledTank() const;
	ATank* ControlledTank = nullptr;
	
	ATank* GetPlayerTank() const;
	ATank* FoundTank = nullptr;
};
