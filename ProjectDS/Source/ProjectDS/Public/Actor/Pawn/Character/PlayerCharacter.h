// All rights reserved by Jellyfish-zero.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class UCameraComponent;
class UCombatSubsystem;
class UInputAction;
class UPlayerStatusComp;
class UNiagaraComponent;
class USpringArmComponent;

struct FInputActionValue;

UCLASS()
class PROJECTDS_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

#pragma region API

	UFUNCTION(BlueprintCallable)
	FORCEINLINE UCameraComponent* GetMainCamera() const;
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE UPlayerStatusComp* GetStatusComp() const;

#pragma endregion

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

#pragma region CameraEffect

	UFUNCTION(BlueprintImplementableEvent)
	void CameraBlackWhiteFadeInEvent();

	UFUNCTION(BlueprintImplementableEvent)
	void CameraBlackWhiteFadeOutEvent();

#pragma endregion

#pragma region SceneComponents

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UCameraComponent* MainCamera;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UNiagaraComponent* NS_PerciseDodge;

#pragma endregion

#pragma region ActorComponents

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UPlayerStatusComp* StatusComp;

#pragma endregion

#pragma region InputActions

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "InputAction")
	UInputAction* MoveAction;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "InputAction")
	UInputAction* RunAndDodgeAction;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "InputAction")
	UInputAction* JumpAction;

#pragma endregion

#pragma region EditableVariables

	/* 行走的速度Scale */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float WalkScale = 0.6f;

	/* 跑步的速度Scale */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float RunScale = 1.f;

	/* 迴避力道 */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float DodgeForce = 1000.f;

	/* 角色模型旋轉有關，先不做 */
	//UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	//float RotateAngle = 50.f;

	/* 迴避體力花費 */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	int32 DodgeStaminaCost = 100; // TODO: 應該用另一個ActorComponent管理起來

	/* 精準迴避距離 */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float PreciseDistance = 600.f; // TODO: 應該用另一個ActorComponent管理起來

	/* 精準迴避slow motion，TimeDilation值應該介於0~1之間，才會slow motion */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float PreciseTimeDilation = 0.2f;

	/* 精準迴避SlowMotion持續時間 */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float SlowMotionPersisTime = 2.f;

#pragma endregion

private:

#pragma region NormalGameInput

	void Move(const FInputActionValue& Value);
	
	void RunStart();
	
	void RunStop();

	void Dodge();

#pragma endregion

#pragma region PreciseTimeSlowMotionFunctions

	UFUNCTION()
	void StopTimeSlowMotion();

#pragma endregion

#pragma region Subsystems

	TWeakObjectPtr<UCombatSubsystem> CombatSys;

#pragma endregion

#pragma region PreciseTimeSlowParams

	FTimerHandle PreciseTimeSlowMotionHandler;

#pragma endregion

#pragma region PrivateVariable

	/* 當前移動速度 */
	float MoveSpeed; 

#pragma endregion

};

FORCEINLINE UCameraComponent* APlayerCharacter::GetMainCamera() const
{
	return MainCamera;
}

FORCEINLINE UPlayerStatusComp* APlayerCharacter::GetStatusComp() const
{
	return StatusComp;
}