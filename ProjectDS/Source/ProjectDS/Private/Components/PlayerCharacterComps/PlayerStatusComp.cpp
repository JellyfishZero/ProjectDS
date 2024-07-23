// All rights reserved by Jellyfish-zero.


#include "Components/PlayerCharacterComps/PlayerStatusComp.h"
#include "SubSystem/MainCharacterSubsystem/MainCharacterSubsystem.h"

DEFINE_LOG_CATEGORY(PlayerStatusCompLog);

// Sets default values for this component's properties
UPlayerStatusComp::UPlayerStatusComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UPlayerStatusComp::InitPlayerStatus()
{
	/*
	* 生命、魔力、體力初始化
	*/
	UMainCharacterSubsystem* MainCharacterSubsys = GetWorld()->GetGameInstance()->GetSubsystem<UMainCharacterSubsystem>();
	if (ensure(IsValid(MainCharacterSubsys)))
	{
		MaxHealth = MainCharacterSubsys->GetCurrentCharacterMaxHealth();
		CurrentHealth = MaxHealth;
		OnHealthChanged.Broadcast(CurrentHealth, MaxHealth);

		MaxMana = MainCharacterSubsys->GetCurrentCharacterMaxMana();
		CurrentMana = MaxMana;
		OnManaChanged.Broadcast(CurrentMana, MaxMana);

		MaxStamina = MainCharacterSubsys->GetCurrentCharacterMaxStamina();
		CurrentStamina = MaxStamina;
		OnStaminaChanged.Broadcast(CurrentStamina, MaxStamina);
		return;
	}
#if WITH_EDITOR
		UE_LOG(PlayerStatusCompLog, Error, TEXT("MainCharacterSubsys is not exist!"));
#endif
}

void UPlayerStatusComp::IncreaseCurrentHealth(int32 IncreaseValue)
{
	if (IncreaseValue > 0)
	{
		CurrentHealth = FMath::Min(CurrentHealth + IncreaseValue, MaxHealth);
		OnHealthChanged.Broadcast(CurrentHealth, MaxHealth);
		return;
	}
#if WITH_EDITOR
	UE_LOG(PlayerStatusCompLog, Error, TEXT("IncreaseValue < 0!"));
#endif
}

void UPlayerStatusComp::DecreaseCurrentHealth(int32 DecreaseValue)
{
	if (DecreaseValue > 0)
	{
		CurrentHealth = FMath::Max(CurrentHealth - DecreaseValue, 0);
		OnHealthChanged.Broadcast(CurrentHealth, MaxHealth);
		return;
	}
#if WITH_EDITOR
	UE_LOG(PlayerStatusCompLog, Error, TEXT("DecreaseValue < 0!"));
#endif
}

void UPlayerStatusComp::IncreaseCurrentMana(int32 IncreaseValue)
{
	if (IncreaseValue > 0)
	{
		CurrentMana = FMath::Min(CurrentMana + IncreaseValue, MaxMana);
		OnManaChanged.Broadcast(CurrentMana, MaxMana);
		return;
	}
#if WITH_EDITOR
	UE_LOG(PlayerStatusCompLog, Error, TEXT("IncreaseValue < 0!"));
#endif
}

void UPlayerStatusComp::DecreaseCurrentMana(int32 DecreaseValue)
{
	if (DecreaseValue > 0)
	{
		CurrentMana = FMath::Max(CurrentMana - DecreaseValue, 0);
		OnManaChanged.Broadcast(CurrentMana, MaxMana);
		return;
	}
#if WITH_EDITOR
	UE_LOG(PlayerStatusCompLog, Error, TEXT("DecreaseValue < 0!"));
#endif
}

void UPlayerStatusComp::IncreaseCurrentStamina(int32 IncreaseValue)
{
	if (IncreaseValue > 0)
	{
		CurrentStamina = FMath::Min(CurrentStamina + IncreaseValue, MaxStamina);
		OnStaminaChanged.Broadcast(CurrentStamina, MaxStamina);
		return;
	}
#if WITH_EDITOR
	UE_LOG(PlayerStatusCompLog, Error, TEXT("IncreaseValue < 0!"));
#endif
}

void UPlayerStatusComp::DecreaseCurrentStamina(int32 DecreaseValue)
{
	if (DecreaseValue > 0)
	{
		CurrentStamina = FMath::Max(CurrentStamina - DecreaseValue, 0);
		OnStaminaChanged.Broadcast(CurrentStamina, MaxStamina);
		return;
	}
#if WITH_EDITOR
	UE_LOG(PlayerStatusCompLog, Error, TEXT("DecreaseValue < 0!"));
#endif
}

// Called when the game starts
void UPlayerStatusComp::BeginPlay()
{
	Super::BeginPlay();

	BindCallBackFunctions(); // binding各種callback

	InitPlayerStatus(); // 初始化狀態

}

void UPlayerStatusComp::BindCallBackFunctions()
{
	OnStaminaChanged.AddDynamic(this, &UPlayerStatusComp::HandleStaminaChanged);
}

void UPlayerStatusComp::HandleStaminaChanged(int32 InCurrentStamina, int32 InMaxStamina)
{
	/* 觸發條件是當前體力比體力最大值少 且 要避免Timer重複被註冊 */
	if (InCurrentStamina < InMaxStamina && !GetWorld()->GetTimerManager().TimerExists(StaminaRecoerTimerHandler))
	{
		GetWorld()->GetTimerManager().SetTimer(StaminaRecoerTimerHandler, this, &UPlayerStatusComp::AutoRecoverStamina, StaminaAutoRecoverInterval, true);
	}
}

void UPlayerStatusComp::AutoRecoverStamina()
{
	IncreaseCurrentStamina(StaminaAutoRecoverValue);
	if (CurrentStamina >= MaxStamina)
	{
		/* 恢復完成後解除Timer */
		GetWorld()->GetTimerManager().ClearTimer(StaminaRecoerTimerHandler);
	}
}
