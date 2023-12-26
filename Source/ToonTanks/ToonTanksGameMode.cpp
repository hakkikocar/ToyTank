// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "ToonTankPlayerController.h"
#include "Turret.h"
#include "Blueprint/UserWidget.h"

void AToonTanksGameMode::ActorDied(AActor* DeatActor)
{
	if (DeatActor == Tank)
	{
		Tank->HandleDestruction();
		if (Tank->GetTankPlayerController())
		{
			ToonTankPlayerController->SetEnablePlayerState(false);
		}
	}
	else if(ATurret* DestroyedTurret = Cast<ATurret>(DeatActor))
	{
		DestroyedTurret->HandleDestruction();
	}
}

void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay();

	HandleGameStart();
}

void AToonTanksGameMode::HandleGameStart()
{
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this,0));
	ToonTankPlayerController= Cast<AToonTankPlayerController>(UGameplayStatics::GetPlayerController(this,0));

	StartGame();
	
	if (ToonTankPlayerController)
	{
		ToonTankPlayerController->SetEnablePlayerState(false);

		FTimerHandle PlayerEnableTimerHandle;
		FTimerDelegate PlayerEnableTimerDelegate=FTimerDelegate::CreateUObject(
			ToonTankPlayerController,
			&AToonTankPlayerController::SetEnablePlayerState,
			true);
		GetWorldTimerManager().SetTimer(PlayerEnableTimerHandle,PlayerEnableTimerDelegate,StartDelay,false);
	}
}









