// Fill out your copyright notice in the Description page of Project Settings.


#include "Personaje.h"

// Sets default values
APersonaje::APersonaje()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APersonaje::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APersonaje::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APersonaje::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Horizontal", this, &APersonaje::MovimientoHorizontal);
	PlayerInputComponent->BindAction("Disparo", IE_Pressed, this, &APersonaje::Disparo);

}

void APersonaje::MovimientoHorizontal(float valor)
{
	// UE_LOG(LogTemp, Display, TEXT("moviendose: %f"), valor);
	// Get the actor's forward vector
    FVector ForwardVector = GetActorForwardVector();

    FVector ubicacionActual = GetActorLocation();

	ubicacionActual.Y +=  valor * 10;

    // Add the scaled forward vector to the actor's location
    SetActorLocation(ubicacionActual);
}

void APersonaje::Disparo()
{
	UE_LOG(LogTemp, Warning, TEXT("DISPARO"));

	if (Original && GetWorld())
	{
		// Get a reference to the world
		UWorld* World = GetWorld();

		// Define the spawn parameters
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		// Get the location and rotation where you want to spawn the actor
		FVector SpawnLocation = GetActorLocation(); // Set your desired location
		FRotator SpawnRotation = GetActorRotation(); // Set your desired rotation

		SpawnLocation.Y += 100;

		// Spawn the actor using SpawnActor function
		ACubito* SpawnedActor = World->SpawnActor<ACubito>(Original, SpawnLocation, SpawnRotation, SpawnParams);

		// Check if the spawned actor is valid
		if (SpawnedActor)
		{
			// The actor was successfully spawned, you can further modify or interact with it here
		}
		else
		{
			// Handle failure to spawn the actor
		}
	}
}