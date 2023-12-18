// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"
#include "Systems/MovieSceneQuaternionInterpolationRotationSystem.h"

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

//Tick
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerControllerRef)
	{
		FHitResult HitResult;
		PlayerControllerRef->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility,
			false,
			HitResult);
		FVector MouseLocation=HitResult.ImpactPoint;
		DrawDebugSphere(GetWorld(),MouseLocation,10,10,FColor::Blue,false,-1.f);
		RotateTurret(MouseLocation);
	}
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






