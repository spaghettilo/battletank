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

}

void ATank::RotateBarrel(float axisValue) {
	if (ChildBarrel) {
		ChildBarrel->AddRelativeRotation(FRotator(axisValue, 0.f, 0.f));
	}
}

void ATank::RotateTurret(float axisValue) {
	if (ChildTurret) {
		ChildTurret->AddRelativeRotation(FRotator(0.f, axisValue, 0.f));
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
