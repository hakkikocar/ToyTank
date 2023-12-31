// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Camera/CameraShakeBase.h"
#include "Projectile.generated.h"


class USoundBase;

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly, Category="Combat")
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(EditAnywhere, Category="Movement")
	class UProjectileMovementComponent* UprojectileMovementComponent;

	UPROPERTY(EditAnywhere, Category="Movement")
	float InitialSpeed=2500;

	UPROPERTY(EditAnywhere, Category="Movement")
	float MaxSpeed=3000;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere)
	float Damage=50;

	UPROPERTY(EditAnywhere, Category="Combat")
	class UParticleSystem* HitParticles;

	UPROPERTY(EditAnywhere,Category="Combat")
	class UParticleSystemComponent* TrailParticle;

	UPROPERTY(EditAnywhere,Category="Combat")
	USoundBase* LaunchSound;
	
	UPROPERTY(EditAnywhere,Category="Combat")
	USoundBase* HitSound;
	
	UPROPERTY(EditAnywhere,Category="Combat")
	TSubclassOf<class UCameraShakeBase> HitCameraShakeClass;	
};
