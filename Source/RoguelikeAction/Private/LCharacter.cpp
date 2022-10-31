// Fill out your copyright notice in the Description page of Project Settings.


#include "LCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ALCharacter::ALCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->SetupAttachment(RootComponent); // RootComponent没有兄弟组件
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent); // 第三人称

	GetCharacterMovement()->bOrientRotationToMovement = true; // 保证人物的始终与镜头朝向保持一致
	
	bUseControllerRotationYaw = false;
}

// Called when the game starts or when spawned
void ALCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALCharacter::MoveForward(float value)
{
	// 或许当前相机的方向和角度
	FRotator ControlRotation = GetControlRotation();
	// 我们必须保证人物的移动是在XY水平面上，而不是向上或向下走
	ControlRotation.Roll = 0.0f;
	ControlRotation.Pitch = 0.0f;
	// 通过指定相机的视角方向，以及前进速度（-1到1之间），移动Character
	AddMovementInput(ControlRotation.Vector(), value);
}

void ALCharacter::MoveRight(float value)
{
	// 获取当前相机的方向和角度
	FRotator ControlRotation = GetControlRotation();
	// 我们必须保证人物的移动是在XY水平面上，而不是向上或向下走
	ControlRotation.Roll = 0.0f;
	ControlRotation.Pitch = 0.0f;
	// 通过当前相机的方向，判断出正确的左和右（Y轴对应左右）
	const FVector RightVector = FRotationMatrix(ControlRotation).GetScaledAxis(EAxis::Y);
	AddMovementInput(RightVector, value);
}

void ALCharacter::PrimaryAttack()
{
	
}

// Called every frame
void ALCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ALCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 上下左右移动
	PlayerInputComponent->BindAxis("MoveForward", this, &ALCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ALCharacter::MoveRight);

	// 视角旋转
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput); // Yaw绕Z轴转动
	PlayerInputComponent->BindAxis("Lookup", this, &APawn::AddControllerPitchInput); // Pitch绕Y轴转动
    
    // 射击
    PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &ALCharacter::PrimaryAttack);
}

