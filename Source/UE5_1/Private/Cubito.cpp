// Fill out your copyright notice in the Description page of Project Settings.


#include "Cubito.h"

// Sets default values
ACubito::ACubito()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ACubito::BeginPlay()
{
	Super::BeginPlay();

	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("EL CUBITO VIVE!"));
	
	// objetivo: empujar al cubito al iniciar
	// paso 1 - obtener referencia a static mesh
	StaticMesh = Cast<UStaticMeshComponent>(GetComponentByClass(UStaticMeshComponent::StaticClass()));

	// dar empujón
	StaticMesh->AddImpulse(Fuerza);	

	// suscrbir métodos para escuchar el momento de colisión y de fin de colisión
	StaticMesh->OnComponentBeginOverlap.AddDynamic(this, &ACubito::OnOverlapBegin);
	StaticMesh->OnComponentEndOverlap.AddDynamic(this, &ACubito::OnOverlapEnd);
}

// Called every frame
void ACubito::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACubito::OnOverlapBegin(
	class UPrimitiveComponent* OverlappedComp, 
	class AActor* OtherActor, 
	class UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, 
	bool bFromSweep, 
	const FHitResult& SweepResult
){
	if(OtherActor == this)
		return;
		
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("OVERLAP BEGIN"));
	UE_LOG(LogTemp, Warning, TEXT("%s vs %s"), *GetName(), *OtherActor->GetName());

	// destruir al chocar
	Destroy();
}

void ACubito::OnOverlapEnd(
	class UPrimitiveComponent* OverlappedComp, 
	class AActor* OtherActor, 
	class UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex
){
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("OVERLAP END"));
}

