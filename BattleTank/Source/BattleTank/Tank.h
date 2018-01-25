// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetTurrentChildActor(UChildActorComponent* TurretFromBP);
	void RotateTurret(float axisValue);

	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetBarrelChildActor(UChildActorComponent* BarrelFromBP);
	void RotateBarrel(float axisValue);

	//Moving
	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetTankChildActor(UChildActorComponent* TankFromBP);
	void MoveTank(float Speed);
	void RotateTank(float Speed);

	UPROPERTY(EditAnywhere, Category = "Tank")
	float RotationSpeed = 1.f;

	UPROPERTY(EditAnywhere, Category = "Tank")
	float MovementSpeed = 1.f;
	
private:
	UChildActorComponent * ChildTank = nullptr;
	UChildActorComponent* ChildTurret = nullptr;
	UChildActorComponent* ChildBarrel = nullptr;
};
