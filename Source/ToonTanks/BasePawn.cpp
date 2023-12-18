// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CapsuleComponent=CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsul Component"));
	RootComponent=CapsuleComponent;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(CapsuleComponent);
	
	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);
	
	ProjectileSpawnPoint=CreateDefaultSubobject<USceneComponent>(TEXT("projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);
}

void ABasePawn::RotateTurret(FVector LookAtTarget)
{
	FVector ToTarget=LookAtTarget- TurretMesh->GetComponentLocation();
	FRotator LookAtRotation=ToTarget.Rotation()=FRotator(0.f,ToTarget.Rotation().Yaw,0.f);
	TurretMesh->SetWorldRotation(FMath::RInterpTo(TurretMesh->GetComponentRotation(),LookAtRotation,UGameplayStatics::GetWorldDeltaSeconds(this),3.f));
}

void ABasePawn::Fire()
{
	FVector ProjectileSpawnPointLocation=ProjectileSpawnPoint->GetComponentLocation();
	DrawDebugSphere(GetWorld(),ProjectileSpawnPointLocation,20,10,FColor::Red,false,2);
	
}



