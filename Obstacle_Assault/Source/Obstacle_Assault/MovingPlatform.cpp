// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	FString name = GetName();
	UE_LOG(LogTemp, Display, TEXT("Begin Play: %s"), *name);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);

	
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	// Move Platform forewards
		// Get current location
	FVector CurrentLocation = GetActorLocation();
		// Add vector to that location 
	CurrentLocation += PlatformVelocity * DeltaTime;
		// Set that location
	SetActorLocation(CurrentLocation);
	// Send Platform Back
		// Check how far we have moved
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);
		// Reverse direction of motion if gone to far
	if(DistanceMoved > MoveDistance)
	{
		float OverShoot = DistanceMoved - MoveDistance;
		FString name = GetName();
		UE_LOG(LogTemp, Display, TEXT("%s Overshot by: %f"),*name, OverShoot);
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation += MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	UE_LOG(LogTemp, Display, TEXT("Rotate Platform"));
}