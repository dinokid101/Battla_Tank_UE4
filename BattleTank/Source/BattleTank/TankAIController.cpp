// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
	if (!ensure(PlayerTank && ControlledTank)) return;

	auto TankAimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	//Move toward the player
	MoveToActor(PlayerTank, AcceptanceRadius); //TODO: check radius is in cm

	if (ensure(TankAimingComponent)) {
		//Aim towards the player
		TankAimingComponent->AimAt(PlayerTank->GetActorLocation());
		TankAimingComponent->Fire(); //TODO: limit firing rate
	}
}
