// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatComponent.h"

// Sets default values for this component's properties
UFloatComponent::UFloatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFloatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UFloatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

		FVector NewLocation = GetOwner()->GetActorLocation();

	FRotator NewRotation = GetOwner()->GetActorRotation();

	float RunningTime = GetOwner()->GetGameTimeSinceCreation();

	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));

	NewLocation.Z += DeltaHeight * 20.0f; //Scale our height by a factor of 20


	float DeltaRotation = DeltaTime * 20.0f; // Rotate by 20 degrees per second

	if (!Counterclockwise)
	{
		NewRotation.Yaw += DeltaRotation;
	}

	if (Counterclockwise)
	{
		NewRotation.Yaw -= DeltaRotation;
	}

	GetOwner()->SetActorLocationAndRotation(NewLocation, NewRotation);

	// ...
}

