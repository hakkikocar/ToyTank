// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	void HandleDestruction();
	
protected:
	void RotateTurret(FVector LookAtTarget);
	
	void Fire();

private:
	/**
	 * Constructer actor components
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components" ,meta=(AllowPrivateAccess=true)) 
	class UCapsuleComponent* CapsuleComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components" ,meta=(AllowPrivateAccess=true))
	UStaticMeshComponent* BaseMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components" ,meta=(AllowPrivateAccess=true))
	UStaticMeshComponent* TurretMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components" ,meta=(AllowPrivateAccess=true))
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditAnywhere, Category="Combat")
	TSubclassOf<class AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, Category="Combat")
	class UParticleSystem* DeathParticles;

	UPROPERTY(EditAnywhere,Category="Combat")
	class USoundBase* DeathSound;

	UPROPERTY(EditAnywhere,Category="Combat")
	TSubclassOf<class UCameraShakeBase> DeathCameraShakeClass;
};
