// All rights reserved by Jellyfish-zero.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class UCameraComponent;
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

	void Move(const FInputActionValue& Value);

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

};

FORCEINLINE UCameraComponent* APlayerCharacter::GetMainCamera() const
{
	return MainCamera;
}