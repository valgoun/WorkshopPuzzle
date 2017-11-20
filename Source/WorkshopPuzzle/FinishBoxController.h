// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FinishBoxController.generated.h"

UCLASS()
class WORKSHOPPUZZLE_API AFinishBoxController : public AActor
{
	GENERATED_BODY()
	UPROPERTY()
	UPrimitiveComponent* Trigger;
	
public:	
	// Sets default values for this actor's properties
	AFinishBoxController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* Other) override;
	virtual void NotifyActorEndOverlap(AActor* Other) override;
	
};
