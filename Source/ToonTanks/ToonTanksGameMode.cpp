// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Turret.h"

void AToonTanksGameMode::ActorDied(AActor* DeatActor)
{
	if (DeatActor == Tank)
	{
		Tank->HandleDestruction();
		if (Tank->GetTankPlayerController())
		{
			Tank->DisableInput(Tank->GetTankPlayerController());
			Tank->GetTankPlayerController()->bShowMouseCursor= false;
		}
	}
	else if(ATurret* DestroyedTurret = Cast<ATurret>(DeatActor))
	{
		DestroyedTurret->HandleDestruction();
		if (DestroyedTurret->Controller)
		{
			
		}
	}
}

void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this,0));
}
