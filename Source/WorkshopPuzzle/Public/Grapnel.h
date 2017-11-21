// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "Editor/EditorEngine.h"
#include "Kismet/KismetMathLibrary.h"
//#include "GameFramework/InputComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h" 

#include "Grapnel.generated.h"

class UStaticMeshComponent;

UCLASS(Blueprintable)
class WORKSHOPPUZZLE_API AGrapnel : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	float maxDistanceGrapnel;

	UPROPERTY(EditAnywhere)
	float grapnelSpeed;

	UPROPERTY(EditAnywhere)
	float launchPlayerSpeed;

	UPROPERTY(BlueprintReadOnly)
	bool isLaunching;

private:
	float actualDistance;
	UStaticMeshComponent* grapnelComponent;
	AActor* playerActor;
	APlayerController* playerController;
	ACharacter* playerCharacter;

public:	
	// Sets default values for this actor's properties
	AGrapnel();

private:
	UFUNCTION(BlueprintCallable, Category="Grapnel")
	void LaunchGrapnel();

	UFUNCTION(BlueprintCallable, Category = "Grapnel")
	void ResetGrapnel();

	UFUNCTION(BlueprintCallable, Category = "Grapnel")
	void SetGrapnelComponent(UStaticMeshComponent* grapnelComponent);

	UFUNCTION(BlueprintCallable, Category = "Grapnel")
	void SetPlayerActor(AActor* playerActor);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* inputComponent);

public:	
	// Called every frame
	virtual void Tick(float deltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Grapnel")
	void PullPlayer(FVector location);
	
};
