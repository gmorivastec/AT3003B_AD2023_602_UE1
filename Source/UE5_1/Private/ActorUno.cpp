// Fill out your copyright notice in the Description page of Project Settings.

// .cpp - contiene la implementación de la lógica
// el "cómo"

#include "ActorUno.h"

// Sets default values
AActorUno::AActorUno()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActorUno::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorUno::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

