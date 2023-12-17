// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

//Generate constructer function
ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArm= CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm Component"));
	SpringArm->SetupAttachment(RootComponent);
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	Camera->SetupAttachment(SpringArm);
}

//Binding input axis
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"),this, &ATank::Move);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATank::Turn);
}

//begin play
void ATank::BeginPlay()
{
	Super::BeginPlay();
	PlayerControllerRef=Cast<APlayerController>(GetController());
	
}

//Tank Move Forward
void ATank::Move(float Value)
{
	FVector DeltaLocation= FVector::ZeroVector;
	DeltaLocation.X=Value*Speed*UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalOffset(DeltaLocation,true);
}

//Tank Turn Rate
void ATank::Turn(float Value)
{
	FRotator DeltaRotation= FRotator::ZeroRotator;
	DeltaRotation.Yaw=Value* TurnRate*UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalRotation(DeltaRotation,true);
}






