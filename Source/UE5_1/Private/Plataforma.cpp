// Fill out your copyright notice in the Description page of Project Settings.


#include "Plataforma.h"

// Sets default values
APlataforma::APlataforma()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlataforma::BeginPlay()
{
	Super::BeginPlay();
	// imprimir algo a consola
	UE_LOG(LogTemp, Display, TEXT("HOLA DESDE C++!"));
}

// Called every frame
void APlataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// moverse!
	
	// obtener ubicación programáticamente
	FVector ubicacionActual = GetActorLocation();

	// verificar si salio de limite
	if(ubicacionActual.Y < limiteIzquierdo || ubicacionActual.Y > limiteDerecho)
	{
		// se salió de los límites, cambia la direccion
		direccion *= -1;
		// lo mismo que: direccion = direccion * -1;
	}

	// desplazar
	ubicacionActual.Y += DeltaTime * velocidad * direccion;
	SetActorLocation(ubicacionActual);
}

