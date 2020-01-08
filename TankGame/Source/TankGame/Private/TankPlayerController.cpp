// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
    Super::BeginPlay();
    auto ControlledTank = GetControlledTank();
    if(!ControlledTank){
        UE_LOG(LogTemp, Warning, TEXT("PlayController not possessing a tank"))

    } else {
        UE_LOG(LogTemp, Warning, TEXT("PlayController possessing %s: "), *ControlledTank->GetName())
    }

}

ATank* ATankPlayerController::GetControlledTank() const{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::Tick(float DeltaTime){
    Super::Tick(DeltaTime);
    AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair(){
    if(!GetControlledTank()) { return; }

    FVector OutHitLocation;
    if(GetSightRayHitLocation(OutHitLocation)){
        //UE_LOG(LogTemp, Warning, TEXT("Hit Location %s: "), *OutHitLocation.ToString())
    }
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const {

    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

    FVector LookDirection;
    if(GetLookDirection(ScreenLocation, LookDirection)) {
        UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *LookDirection.ToString());
    }

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const {

    FVector CameraWorldLocation;
    return  DeprojectScreenPositionToWorld(
            ScreenLocation.X, 
            ScreenLocation.Y, 
            CameraWorldLocation, 
            LookDirection
            );


}



