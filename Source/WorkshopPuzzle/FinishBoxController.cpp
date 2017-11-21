// Fill out your copyright notice in the Description page of Project Settings.

#include "FinishBoxController.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Core/Public/Misc/Paths.h"
#include "WorkshopPuzzleCharacter.h"

// Sets default values
AFinishBoxController::AFinishBoxController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Trigger = CreateDefaultSubobject<USphereComponent>(TEXT("TriggerCollider"));

	// Both colliders need to have this set to true for events to fire
	Trigger->bGenerateOverlapEvents = true;

	// Set the collision mode for the collider
	// This mode will only enable the collider for raycasts, sweeps, and overlaps
	Trigger->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

// Called when the game starts or when spawned
void AFinishBoxController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFinishBoxController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFinishBoxController::NotifyActorBeginOverlap(AActor * Other)
{
	AWorkshopPuzzleCharacter* player = Cast<AWorkshopPuzzleCharacter>(Other);

	if (player) {
		UObject* world = Cast<UObject>(GetWorld());

		FString actualLevel = UGameplayStatics::GetCurrentLevelName(world);
		actualLevel.Replace(TEXT("Level"), TEXT(""));
		int newLevelIndex = FCString::Atoi(*actualLevel) + 1;

		if (FPaths::FileExists(TEXT("Level" + newLevelIndex))) {
			UGameplayStatics::OpenLevel(world, "Level" + newLevelIndex);
		}
	}
	
}