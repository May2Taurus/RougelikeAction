// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LMagicProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UParticleSystemComponent;

UCLASS()
class ROGUELIKEACTION_API ALMagicProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALMagicProjectile();

protected:

	UPROPERTY(VisibleAnywhere)
	USphereComponent * SphereComponent;
	
	UPROPERTY(VisibleAnywhere)
	UProjectileMovementComponent * ProjectileMovementComponent;

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent * EffectComponent;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
