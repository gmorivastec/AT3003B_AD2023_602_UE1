// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Plataforma.generated.h"

UCLASS()
class UE5_1_API APlataforma : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlataforma();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// esta variable la voy a utilizar para saber en qué dirección va la plataforma
	int direccion = 1;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// vamos agregando propiedades que podamos modificar desde el editor

	UPROPERTY(EditAnywhere, Category="Valores para plataforma")
	float limiteIzquierdo = 0;

	UPROPERTY(EditAnywhere, Category="Valores para plataforma")
	float limiteDerecho = 0;

	UPROPERTY(EditAnywhere, Category="Valores para plataforma")
	float velocidad = 10;
};
