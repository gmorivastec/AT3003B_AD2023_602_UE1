// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Cubito.generated.h"

UCLASS()
class UE5_1_API ACubito : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubito();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// OJO AQUÍ 
	// * ???????
	// apuntador

	UStaticMeshComponent* StaticMesh;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// métodos para escuchar las colisiones 
	// 1ero - similar a OnCollisionEnter
	UFUNCTION()
	void OnOverlapBegin(
		class UPrimitiveComponent* OverlappedComp, 
		class AActor* OtherActor, 
		class UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, 
		bool bFromSweep, 
		const FHitResult& SweepResult
	);

	// 2do - el similar a OnCollisionExit
	UFUNCTION()
	void OnOverlapEnd(
		class UPrimitiveComponent* OverlappedComp, 
		class AActor* OtherActor, 
		class UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex
	);

	// la fuerza con la que le vamos a dar el empujón
	UPROPERTY(EditAnywhere)
	FVector Fuerza = FVector(200, 0, 0);
};
