// All rights reserved by Jellyfish-zero.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerStatusComp.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(PlayerStatusCompLog, Log, All);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTDS_API UPlayerStatusComp : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerStatusComp();

	/* 狀態初始化 */
	UFUNCTION(BlueprintCallable, Category = "InitFunction")
	void InitPlayerStatus();

#pragma region IncreaseOrDecreaseFunctions

	/* 增加當前生命
	* @param IncreaseValue 數量，請輸入正值， > 0
	*/
	UFUNCTION(BlueprintCallable, Category = "IncreaseOrDecreaseFunctions")
	void IncreaseCurrentHealth(int32 IncreaseValue);

	/* 減少當前生命
	* @param DecreaseValue 數量，請輸入正值， > 0
	*/
	UFUNCTION(BlueprintCallable, Category = "IncreaseOrDecreaseFunctions")
	void DecreaseCurrentHealth(int32 DecreaseValue);

	/* 增加當前魔力 
	* @param IncreaseValue 數量，請輸入正值， > 0
	*/
	UFUNCTION(BlueprintCallable, Category = "IncreaseOrDecreaseFunctions")
	void IncreaseCurrentMana(int32 IncreaseValue);
	
	/* 減少當前魔力
	* @param DecreaseValue 數量，請輸入正值， > 0
	*/
	UFUNCTION(BlueprintCallable, Category = "IncreaseOrDecreaseFunctions")
	void DecreaseCurrentMana(int32 DecreaseValue);

	/* 增加當前體力
	* @param IncreaseValue 數量，請輸入正值， > 0
	*/
	UFUNCTION(BlueprintCallable, Category = "IncreaseOrDecreaseFunctions")
	void IncreaseCurrentStamina(int32 IncreaseValue);

	/* 減少當前體力
	* @param DecreaseValue 數量，請輸入正值， > 0
	*/
	UFUNCTION(BlueprintCallable, Category = "IncreaseOrDecreaseFunctions")
	void DecreaseCurrentStamina(int32 DecreaseValue);

#pragma endregion

#pragma region GetFunctions

	UFUNCTION(BlueprintCallable, Category = "GetBasicSatusFunctions")
	FORCEINLINE int32 GetMaxHealth() const;

	UFUNCTION(BlueprintCallable, Category = "GetBasicSatusFunctions")
	FORCEINLINE int32 GetCurrentHealth() const;

	UFUNCTION(BlueprintCallable, Category = "GetBasicSatusFunctions")
	FORCEINLINE int32 GetMaxMana() const;

	UFUNCTION(BlueprintCallable, Category = "GetBasicSatusFunctions")
	FORCEINLINE int32 GetCurrentMana() const;

	UFUNCTION(BlueprintCallable, Category = "GetBasicSatusFunctions")
	FORCEINLINE int32 GetMaxStamina() const;

	UFUNCTION(BlueprintCallable, Category = "GetBasicSatusFunctions")
	FORCEINLINE int32 GetCurrentStamina() const;

#pragma endregion

/* 處理基本數值變動，如生命、魔力、體力 */
#pragma region Delegate_BasicParamsChanged


	/* 
	* @param InCurrentValue 傳入當前數值
	* @param InMaxValue 傳入最大值
	*/
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBasicParamsValueChangedEvent, int32, InCurrentValue, int32, InMaxValue);

	/* 當生命數值異動時觸發 */
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FBasicParamsValueChangedEvent OnHealthChanged;

	/* 當魔力數值異動時觸發 */
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FBasicParamsValueChangedEvent OnManaChanged;

	/* 當體力數值異動時觸發 */
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FBasicParamsValueChangedEvent OnStaminaChanged;

#pragma endregion

protected:
	// Called when the game starts
	virtual void BeginPlay() override;		

private:

	void BindCallBackFunctions();

/* 處理自動恢復機制的方法 */
#pragma region RecoverMechanismCallBack

	UFUNCTION()
	void HandleStaminaChanged(int32 InCurrentStamina, int32 InMaxStamina);

	UFUNCTION()
	void AutoRecoverStamina();

#pragma endregion

#pragma region CharacterBasicParams

	UPROPERTY()
	int32 MaxHealth = 100;

	UPROPERTY()
	int32 CurrentHealth;

	UPROPERTY()
	int32 MaxMana = 100;

	UPROPERTY()
	int32 CurrentMana;

	UPROPERTY()
	int32 MaxStamina = 100;

	UPROPERTY()
	int32 CurrentStamina;

#pragma endregion

#pragma region RecoverMechanismParams

	FTimerHandle StaminaRecoerTimerHandler;

	/* 體力恢復間隔 */
	UPROPERTY(EditAnywhere)
	float StaminaAutoRecoverInterval = 0.1f; // 暫代尚無被系統管理

	/* 體力恢復量 */
	UPROPERTY(EditAnywhere)
	int32 StaminaAutoRecoverValue = 2; // 暫代尚無被系統管理

#pragma endregion

};

FORCEINLINE int32 UPlayerStatusComp::GetMaxHealth() const
{
	return MaxHealth;
}

FORCEINLINE int32 UPlayerStatusComp::GetCurrentHealth() const
{
	return CurrentHealth;
}

FORCEINLINE int32 UPlayerStatusComp::GetMaxMana() const
{
	return MaxMana;
}

FORCEINLINE int32 UPlayerStatusComp::GetCurrentMana() const
{
	return CurrentMana;
}

FORCEINLINE int32 UPlayerStatusComp::GetMaxStamina() const
{
	return MaxStamina;
}

FORCEINLINE int32 UPlayerStatusComp::GetCurrentStamina() const
{
	return CurrentStamina;
}