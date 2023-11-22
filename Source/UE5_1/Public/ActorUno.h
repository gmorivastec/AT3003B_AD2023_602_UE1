// Fill out your copyright notice in the Description page of Project Settings.

// archivo .h - header / encabezado
// contiene la definición del contrato de la clase

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorUno.generated.h"

// macros propias del unreal engine
// NO MOVER!
// el "qué"
UCLASS()
class UE5_1_API AActorUno : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorUno();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
