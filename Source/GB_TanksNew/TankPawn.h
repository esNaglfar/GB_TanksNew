// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Destroyable.h"
#include "HealthComponent.h"
#include "TankTower.h"
#include "Camera/CameraComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "TankPawn.generated.h"

UCLASS()
class GB_TANKSNEW_API ATankPawn : public APawn, public IDestroyable
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATankPawn();
	
	UPROPERTY()
	AController* TankController;
	
#pragma region Components

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Components")
	UBoxComponent* BoxCollision;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* ChasisMesh;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Components")
	UArrowComponent* TankTowerMantlingPoint;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArm;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Components")
	UCameraComponent* Camera;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Components")
	UHealthComponent* HealthComponent;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Components|Settings")
	TSubclassOf<ATankTower> TankTowerType;

#pragma endregion Components
		
#pragma region Properties
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Movement|Rotation")
	float RotationSpeed = 60.f;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Movement|Rotation")
	float TowerRotationTimeDelta = 0.015f;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Movement|Speed")
	float MaxSpeed = 350.f;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Movement|Speed")
	float MinSpeed = -250.f;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Movement|Speed")
	float Acceleration = 200.f;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Movement|Speed")
	float StoppingPower = 4.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Misc")
	ATankTower* TankTower;
	
#pragma endregion Properties

#pragma region Functions
	void MoveForward(float Value);
	void Rotate(float Value);
	void Fire();

	UFUNCTION()
	void OnDamageTaken(float Amount);
	UFUNCTION()
	void OnDeath();
	UFUNCTION()
	void RotateTower();
	
	virtual void TakeDamage(FDamageInfo Info) override;
#pragma endregion Functions
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	void Move(float DeltaTime);
	void RotateTank(float DeltaTime);
	void Stop();
	
	FTimerHandle RotationHandle;
	float RotationScale = 0.f;
	float ForwardScale = 0.f;
	float CurrentSpeed = 0.f;

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
