// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// Increment the timer
	SpawnTimer += DeltaTime;

	// Check if it's time to spawn
	if (SpawnTimer >= SpawnDelay)
	{
		Spawn();
		SpawnTimer = 0.0f; // Reset the timer
	}
}

void ASpawner::Spawn()
{
	if (!ActorToSpawn || !SpawnBox) return;
	
	// Get a random location within the spawn box
	FVector SpawnLocation = FMath::RandPointInBox(SpawnBox->GetComponentsBoundingBox());

	// Spawn the actor at the random location
	GetWorld()->SpawnActor<AActor>(ActorToSpawn, SpawnLocation, FRotator::ZeroRotator);
}

