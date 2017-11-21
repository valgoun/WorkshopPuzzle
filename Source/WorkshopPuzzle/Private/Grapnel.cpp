// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/Grapnel.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AGrapnel::AGrapnel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGrapnel::BeginPlay()
{
	Super::BeginPlay();
	playerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	playerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	SetupPlayerInputComponent(playerController->InputComponent);
	isLaunching = false;
}

void AGrapnel::SetupPlayerInputComponent(UInputComponent* inputComponent) {
	//inputComponent->BindAction("Grapnel", IE_Pressed, this, &AGrapnel::LaunchGrapnel);
}

// Called every frame
void AGrapnel::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
	if (isLaunching) {
		if (actualDistance < maxDistanceGrapnel) {
			
			FVector location = grapnelComponent->GetComponentLocation();
			FVector forward = GetActorForwardVector();
			const FVector newLocation = FVector(location + (forward * grapnelSpeed * deltaTime));
			actualDistance += grapnelSpeed * deltaTime;
			FHitResult overlapResult;
			grapnelComponent->SetWorldLocation(newLocation, true, &overlapResult, ETeleportType::None);
			if (overlapResult.GetActor() != nullptr) {
				ResetGrapnel();
				PullPlayer(overlapResult.Location);
			}
		}
		else {
			ResetGrapnel();
		}
		
	}

}

void AGrapnel::LaunchGrapnel() {
	if (!isLaunching) {
		UE_LOG(LogTemp, Warning, TEXT("Grap"));
		isLaunching = true;
		actualDistance = 0;
	}		
}

void AGrapnel::ResetGrapnel() {
	const FVector newLocation = FVector(0, 0, 0);
	grapnelComponent->SetRelativeLocation(newLocation, false, nullptr, ETeleportType::TeleportPhysics);
	isLaunching = false;
}

void AGrapnel::PullPlayer(FVector location) {
	//FActorOrComponent playerActor = FActorOrComponent(playerController);
	FVector playerPosition = playerController->GetPawn()->GetActorLocation();
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *playerActor.GetWorldLocation().ToString());
	FVector direction = UKismetMathLibrary::GetDirectionUnitVector(playerPosition, location) * launchPlayerSpeed;
	UE_LOG(LogTemp, Warning, TEXT("%s"), *direction.ToString());
	playerCharacter->LaunchCharacter(direction, true, true);
}

void AGrapnel::SetGrapnelComponent(UStaticMeshComponent* grapnelComponent) {
	this->grapnelComponent = grapnelComponent;
}

void AGrapnel::SetPlayerActor(AActor* playerActor) {
	this->playerActor = playerActor;

}