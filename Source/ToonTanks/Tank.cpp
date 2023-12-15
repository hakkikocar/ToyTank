// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"

ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArm= CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm Component"));
	SpringArm->SetupAttachment(RootComponent);
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	Camera->SetupAttachment(SpringArm);
	
}




void ATank::BeginPlay()
{
	Super::BeginPlay();
}



void ATank::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}


