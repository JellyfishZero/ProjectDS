// All rights reserved by Jellyfish-zero.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainGamePC.generated.h"

class UInputMappingContext;
class UInputAction;
class UUserWidget;

/**
 * 
 */
UCLASS()
class PROJECTDS_API AMainGamePC : public APlayerController
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

#pragma region InputMappingContexts

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UInputMappingContext* DSGameInputContext;

#pragma endregion

#pragma region CameraLimitParams

	/*攝影機角度限制*/

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float MaxPitchAngle = 45.f;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float MinPitchAngle = -45.f;

#pragma endregion

#pragma region CommonInputAction

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "InputAction")
	UInputAction* LookAction;

#pragma endregion

#pragma region HUD

	// TODO: 是否需要用UI Manager管理起來？

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TSubclassOf<UUserWidget> MainGameHUDTemplate;

	UPROPERTY(BlueprintReadOnly, Category = "UI")
	UUserWidget* MainGameHUD;

#pragma endregion

private:

#pragma region CommonInputBindingFunctions

	/* 攝影機旋轉 */
	UFUNCTION()
	void Look(const FInputActionValue& Value);

#pragma endregion

};