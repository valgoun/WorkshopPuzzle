// Fill out your copyright notice in the Description page of Project Settings.

#include "CheckpointBoxController.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"


// Sets default values
ACheckpointBoxController::ACheckpointBoxController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Trigger = CreateDefaultSubobject<USphereComponent>(TEXT("TriggerCollider"));

}

// Called when the game starts or when spawned
void ACheckpointBoxController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACheckpointBoxController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACheckpointBoxController::NotifyActorBeginOverlap(AActor * Other) { }