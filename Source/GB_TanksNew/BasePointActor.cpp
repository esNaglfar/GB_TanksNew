// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePointActor.h"

// Sets default values
ABasePointActor::ABasePointActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABasePointActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePointActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

