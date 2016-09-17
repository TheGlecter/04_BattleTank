// Copyright Oscar Crego 2016

#pragma once

#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"


UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;
	
	ATank* GetControlledTank() const;
	ATank* ControlledTank = nullptr;
	
	ATank* GetPlayerTank() const;
	ATank* FoundTank = nullptr;
};
