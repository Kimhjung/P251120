// Fill out your copyright notice in the Description page of Project Settings.


#include "CChar.h"
#include "GameframeWork/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ACChar::ACChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetCapsuleComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	GetMesh()->SetRelativeLocation(FVector(0, 0, -GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight()));

	GetMesh()->SetRelativeRotation(FRotator(0, -90.0f, 0));
}

// Called when the game starts or when spawned
void ACChar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACChar::Move(float Forward, float Side)
{
	const FRotator CameraRotation = GetController()->GetControlRotation();
	const FRotator YawRotation = FRotator(0, CameraRotation.Yaw, 0);
	const FRotator YawRollRotation = FRotator(0, CameraRotation.Yaw, CameraRotation.Roll);

	const FVector ForwardVector = UKismetMathLibrary::GetForwardVector(YawRotation);
	AddMovementInput(ForwardVector, Forward);

	const FVector SideVector = UKismetMathLibrary::GetRightVector(YawRollRotation);
	AddMovementInput(SideVector, Side);
}

void ACChar::Look(float pitch, float yaw)
{
	AddControllerPitchInput(-pitch);

	AddControllerYawInput(yaw);
}