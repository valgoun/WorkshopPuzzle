// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "WorkshopPuzzleGameMode.h"
#include "WorkshopPuzzleHUD.h"
#include "WorkshopPuzzleCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWorkshopPuzzleGameMode::AWorkshopPuzzleGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AWorkshopPuzzleHUD::StaticClass();
}
