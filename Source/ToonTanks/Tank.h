// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();


protected:
	virtual void BeginPlay() override;


private:
	UPROPERTY(EditAnywhere, Category="Components")
	class UCameraComponent* Camera;
	
	UPROPERTY(EditAnywhere, Category="Components")
	class USpringArmComponent* SpringArm;


public:
	virtual void Tick(float DeltaSeconds) override;
	
};
