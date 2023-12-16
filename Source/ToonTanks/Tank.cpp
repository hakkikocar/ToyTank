// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"

#include "Kismet/KismetSystemLibrary.h"

ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArm= CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm Component"));
	SpringArm->SetupAttachment(RootComponent);
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	Camera->SetupAttachment(SpringArm);
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"),this, &ATank::Move);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATank::Turn);
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
}

void ATank::Move(float Value)
{
	FVector DeltaLocation= FVector::ZeroVector;
	DeltaLocation.X=Value;
	AddActorLocalOffset(DeltaLocation);
}

void ATank::Turn(float Value)
{
	FVector DeltaLocation;
	DeltaLocation.Y=Value;
	AddActorLocalOffset(DeltaLocation);
}


void ATank::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}




