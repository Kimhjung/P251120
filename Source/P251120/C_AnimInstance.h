// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
//#include "Kismet/KismetAnimationLibrary.h"
#include "C_AnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class P251120_API UC_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	float GroundSpeed = 0.0f;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	uint8 bSprint : 1;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	float Direction = 0.0f;

	UFUNCTION()
	void AnimNotify_SkeletonNotify();


	//직접 추가
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	uint8 bUnarmed : 1;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	uint8 bPistor : 1;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	uint8 bRifle : 1;

	


};
