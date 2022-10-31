// Fill out your copyright notice in the Description page of Project Settings.


#include "LMagicProjectile.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ALMagicProjectile::ALMagicProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 子弹发射的球形组件
	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	RootComponent = SphereComponent;
	
	// 投掷体运动系统
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
	ProjectileMovementComponent->InitialSpeed = 1000.0f; // 初始速度
	ProjectileMovementComponent->bRotationFollowsVelocity = true; // 球体每帧都会旋转以适应当前运动的方向
	ProjectileMovementComponent->bInitialVelocityInLocalSpace = true; // 使用局部坐标系定义初始速度

	// 粒子系统
	EffectComponent = CreateDefaultSubobject<UParticleSystemComponent>("EffectComponent");
	EffectComponent->SetupAttachment(SphereComponent);

}

// Called when the game starts or when spawned
void ALMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

