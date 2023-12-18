// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

//Constructer Function
ATurret::ATurret()
{
}

//Every Frame Tick Event 
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Tank)
	{
	    float Distance= FVector::Dist(GetActorLocation(),Tank->GetActorLocation());

		if (Distance<=FireRange)
        	{
        		RotateTurret(Tank->GetActorLocation());
        	}
	}

	
	
}

void ATurret::BeginPlay()
{
	Super::BeginPlay();

	Tank= Cast<ATank>(UGameplayStatics::GetPlayerPawn(this,0));
	UE_LOG(LogTemp,Display,TEXT("distance içinde %s"),*Tank->GetName());
}

