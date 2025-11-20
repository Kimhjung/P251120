// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotifyState_StatrAndStop.h"

void UAnimNotifyState_StatrAndStop::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);
	UE_LOG(LogTemp, Warning, TEXT("NotifyBegin"));
}

void UAnimNotifyState_StatrAndStop::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime, EventReference);
	UE_LOG(LogTemp, Warning, TEXT("NotifyTick"));
}

void UAnimNotifyState_StatrAndStop::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	UE_LOG(LogTemp, Warning, TEXT("NotifyEnd"));

	Super::NotifyEnd(MeshComp, Animation, EventReference);
}

