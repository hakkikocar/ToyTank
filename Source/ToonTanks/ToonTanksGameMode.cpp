// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "ToonTankPlayerController.h"
#include "Turret.h"

void AToonTanksGameMode::ActorDied(AActor* DeatActor)
{
	if (DeatActor == Tank)
	{
		Tank->HandleDestruction();
		if (Tank->GetTankPlayerController())
		{
			ToonTankPlayerController->SetEnablePlayerState(false);
		}
		GameOver(false);
	}
	else if(ATurret* DestroyedTurret = Cast<ATurret>(DeatActor))
	{
		DestroyedTurret->HandleDestruction();
		--TargetTowers;
		if (TargetTowers==0)
		{
			GameOver(true);
		}
	}
}

void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay();

	HandleGameStart();
}

void AToonTanksGameMode::HandleGameStart()
{
	TargetTowers= GetTargetTowerCount();
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

int32 AToonTanksGameMode::GetTargetTowerCount()
{
	TArray<AActor*> Turret;
	UGameplayStatics::GetAllActorsOfClass(this,ATurret::StaticClass(),Turret);
	return Turret.Num();
}









