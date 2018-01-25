// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"


// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("TurretRotation", this, &ATank::RotateTurret);
	PlayerInputComponent->BindAxis("BarrelRotation", this, &ATank::RotateBarrel);
	PlayerInputComponent->BindAxis("MoveTank", this, &ATank::MoveTank);
	PlayerInputComponent->BindAxis("RotateTank", this, &ATank::RotateTank);


}

void ATank::RotateBarrel(float axisValue) {
	if (ChildBarrel) {
		ChildBarrel->AddRelativeRotation(FRotator(axisValue *GetWorld()->DeltaTimeSeconds* RotationSpeed, 0.f, 0.f));
	}
}

void ATank::RotateTurret(float axisValue) {
	if (ChildTurret) {
		ChildTurret->AddRelativeRotation(FRotator(0.f, axisValue*GetWorld()->DeltaTimeSeconds* RotationSpeed, 0.f));
	}
}

void ATank::SetTurrentChildActor(UChildActorComponent* TurretFromBP)
{
	ChildTurret = TurretFromBP;
}

void ATank::SetBarrelChildActor(UChildActorComponent * BarrelFromBP)
{
	ChildBarrel = BarrelFromBP;
}

void ATank::SetTankChildActor(UChildActorComponent * TankFromBP)
{
	ChildTank = TankFromBP;
}

void ATank::MoveTank(float Speed)
{
	if (ChildTank) {
		float Distance = GetWorld()->DeltaTimeSeconds * Speed * MovementSpeed;
		ChildTank->AddRelativeLocation(-(ChildTank->GetForwardVector() * Distance));
	} 
}

void ATank::RotateTank(float Speed)
{
	if (ChildTank) {
		ChildTank->AddRelativeRotation(FRotator(0.f, Speed * GetWorld()->DeltaTimeSeconds * RotationSpeed, 0.f));
	}
}
