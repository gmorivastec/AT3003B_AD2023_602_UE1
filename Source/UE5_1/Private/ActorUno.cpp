// Fill out your copyright notice in the Description page of Project Settings.

// .cpp - contiene la implementación de la lógica
// el "cómo"

#include "ActorUno.h"

// Sets default values
AActorUno::AActorUno()
{
	// aquí pueden lidiar con setup de datos 
	// el actor todavía no está creado! si tratan de acceder a elementos del actor
	// va a compilar y correr pero no va a hacer lo que quieren

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActorUno::BeginPlay()
{
	// aquí va lógica que tenga que encargarse de actores / componentes
	Super::BeginPlay();
	
	// SUPER IMPORTANTE - tu lógica DEBE ir abajo de la llamada a 
	// BeginPlay en la superclase
}

// Called every frame 
// este es el equivalente a update
void AActorUno::Tick(float DeltaTime)
{
	// igual que en BeginPlay asegúrate que esta línea sea la primera
	Super::Tick(DeltaTime);

	// DeltaTime - equivalente en Unity a Time.deltaTime
}

