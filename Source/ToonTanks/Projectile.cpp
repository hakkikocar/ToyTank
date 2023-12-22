// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "GameFramework/DamageType.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ProjectileMesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Prjectile Mesh"));
	RootComponent=ProjectileMesh;

	UprojectileMovementComponent= CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));

	UprojectileMovementComponent->InitialSpeed = InitialSpeed;
	UprojectileMovementComponent->MaxSpeed = MaxSpeed;

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,FVector NormalImpulse, const FHitResult& Hit)
{
	auto MyOwner = GetOwner();
	if (MyOwner==nullptr) return;

	auto MyOwnerInstigator=	MyOwner->GetInstigatorController();
	auto DamageTypeCalass = UDamageType::StaticClass();

	if (OtherActor && OtherActor!= this && OtherActor != MyOwner)
	{
		UGameplayStatics::ApplyDamage(OtherActor,Damage,MyOwnerInstigator,MyOwner,DamageTypeCalass);
		Destroy();
	}
}



