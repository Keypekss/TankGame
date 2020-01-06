// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay() {
    Super::BeginPlay();

    auto ControlledAITank = GetControlledTank();
    if(!ControlledAITank){
        UE_LOG(LogTemp, Warning, TEXT("AIController not possessing a tank"))

    } else {
        UE_LOG(LogTemp, Warning, TEXT("AIController possessing %s: "), *ControlledAITank->GetName())
    }
}

ATank* ATankAIController::GetControlledTank() const{
    return Cast<ATank>(GetPawn());
}
