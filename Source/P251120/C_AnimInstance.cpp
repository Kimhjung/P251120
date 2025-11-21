// Fill out your copyright notice in the Description page of Project Settings.


#include "C_AnimInstance.h"
#include "CChar.h"
#include "Gameframework/CharacterMovementComponent.h"
#include "KismetAnimationLibrary.h"

void UC_AnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	ACChar* Character = Cast<ACChar>(TryGetPawnOwner());

	if (Character)
	{
		GroundSpeed = Character->GetCharacterMovement()->Velocity.Size2D();
		bSprint = Character->bSprint;
		Direction = UKismetAnimationLibrary::CalculateDirection(Character->GetCharacterMovement()->Velocity, Character->GetActorRotation());

		/*
		//직접 추가
		bUnarmed = Character->bUnarmed;
		bPistor = Character->bPistor;
		bRifle = Character->bRifle;
		*/
	}
}

void UC_AnimInstance::AnimNotify_SkeletonNotify()
{

}