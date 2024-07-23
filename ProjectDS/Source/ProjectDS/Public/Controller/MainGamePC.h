// All rights reserved by Jellyfish-zero.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainGamePC.generated.h"

class UInputMappingContext;
class UInputAction;

/**
 * 
 */
UCLASS()
class PROJECTDS_API AMainGamePC : public APlayerController
{
	GENERATED_BODY()

protected:

	void BeginPlay() override;

	void SetupInputComponent() override;

#pragma region InputMappingContexts

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UInputMappingContext* DSGameInputContext;

#pragma endregion

#pragma region CameraLimitParams

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float MaxPitchAngle = 45.f;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float MinPitchAngle = -45.f;

#pragma endregion

#pragma region CommonInputAction

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "InputAction")
	UInputAction* LookAction;

#pragma endregion

private:

#pragma region CommonInputBindingFunctions

	/*Common Input*/
	UFUNCTION()
	void Look(const FInputActionValue& Value);

#pragma endregion

};