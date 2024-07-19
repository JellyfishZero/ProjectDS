// All rights reserved by Jellyfish-zero.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class UCameraComponent;
class UInputAction;
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

	FORCEINLINE UCameraComponent* GetMainCamera() const;

#pragma endregion

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

#pragma region Components

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UCameraComponent* MainCamera;

#pragma endregion

#pragma region InputActions

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "InputAction")
	UInputAction* MoveAction;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "InputAction")
	UInputAction* LookAction;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "InputAction")
	UInputAction* RunAndDodgeAction;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "InputAction")
	UInputAction* JumpAction;

#pragma endregion

#pragma region EditableVariables

	/* 走路定速 */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float WalkSpeed = 100.f;

	/* 跑步定速 */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float RunSpeed = 200.f;

	/* 迴避距離 */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float DodgeDistance = 1000.f;

	/* 迴避起跳力道 */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float DodgetJumpingForce = .1f;

	/* 空中迴避距離效果比例 */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float AirDodgeDistanceRatio = .8f;

	/* 角色模型旋轉有關，先不做 */
	//UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	//float RotateAngle = 50.f;

#pragma endregion

private:

#pragma region NormalGameInput

	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);
	
	void RunStart();
	
	void RunStop();

	void Dodge();

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