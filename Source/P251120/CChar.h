// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CChar.generated.h"

//ABP에서 쓸거니까 블프에서 슬 ENUM이라고 알려줘야 함
UENUM(BlueprintType)
enum class EAnimState : uint8
{
	//숫자 안써주면 적힌 순서대로 자동 부여됨(위에서부터 0,1,2,3...)
	//중간에 정보 끼워넣어야 할 수 있으니까 각 번호를 넓게 잡기
	Unarmed = 0 UMETA(DisplayName = "Unarmed"),
	Pistol = 10 UMETA(DisplayName = "Pistol"),
	Rifle = 20 UMETA(DisplayName = "Rifle")
};

UCLASS()
class P251120_API ACChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACChar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	//어디서 찾는건지 모름
	UPROPERTY(Category = "SpringArm", VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class USpringArmComponent> SpringArm;

	UPROPERTY(Category = "Camera", VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UCameraComponent> Camera;
	//TSoftObjectPtr: 경로만 저장(에셋)

public:
	FORCEINLINE class USpringArmComponent* GetSpringArm() const
	{
		return SpringArm;
	}

	FORCEINLINE class UCameraComponent* GetCameraComponent() const
	{
		return Camera;
	}

	UFUNCTION(BlueprintCallable)
	void Move(float Forward, float Side);

	UFUNCTION(BlueprintCallable)
	void Look(float pitch, float yaw);

	//unit8 : 엔진꺼
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Character)
	uint8 bSprint : 1;

	//직접 추가
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	uint8 bUnarmed : 1;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	uint8 bPistor : 1;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	uint8 bRifle : 1;
};
