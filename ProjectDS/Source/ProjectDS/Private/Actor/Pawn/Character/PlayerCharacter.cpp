// All rights reserved by Jellyfish-zero.


#include "Actor/Pawn/Character/PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/PlayerCharacterComps/PlayerStatusComp.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "Kismet/GameplayStatics.h"
#include "SubSystem/CombatSubsystem/CombatSubsystem.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	MainCamera->SetupAttachment(GetCapsuleComponent());

	StatusComp = CreateDefaultSubobject<UPlayerStatusComp>(TEXT("StatusComp"));
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (ensure(IsValid(EnhancedInputComponent)))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);
		EnhancedInputComponent->BindAction(RunAndDodgeAction, ETriggerEvent::Triggered, this, &APlayerCharacter::RunStart);
		EnhancedInputComponent->BindAction(RunAndDodgeAction, ETriggerEvent::Completed, this, &APlayerCharacter::RunStop);
		EnhancedInputComponent->BindAction(RunAndDodgeAction, ETriggerEvent::Canceled, this, &APlayerCharacter::Dodge);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
	}
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	CombatSys = GetWorld()->GetGameInstance()->GetSubsystem<UCombatSubsystem>();

	MoveSpeed = WalkSpeed;
}

void APlayerCharacter::Move(const FInputActionValue& Value)
{
	// 正常走路
	FVector2D MovementVector = Value.Get<FVector2D>();
	MovementVector.Normalize();

	//FRotator CameraRotation = GetMainCamera()->GetComponentRotation();
	//FRotator YawRotation(0, CameraRotation.Yaw, 0);

	//FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	//FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(GetActorForwardVector(), MovementVector.X * MoveSpeed);
	AddMovementInput(GetActorRightVector(), MovementVector.Y * MoveSpeed);
}

void APlayerCharacter::RunStart()
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, .2f, FColor::Cyan, FString(TEXT("RunStart")));
	MoveSpeed = RunSpeed;
}

void APlayerCharacter::RunStop()
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, .2f, FColor::Cyan, FString(TEXT("RunStop")));
	MoveSpeed = WalkSpeed;
}

void APlayerCharacter::Dodge()
{
	FVector DodgeDirection = GetLastMovementInputVector().GetSafeNormal();
	if (DodgeDirection.Size() < .1f) // DeadZone取0.1f 表示，事實上沒有任何按鍵輸入
	{
		// 如果什麼方向鍵都沒按，讓角色後撤步
		DodgeDirection = -GetActorForwardVector().GetSafeNormal();
	}
	if (StatusComp->GetCurrentStamina() >= DodgeStaminaCost)
	{
		if (CombatSys.IsValid() && CombatSys->CheckIsPlayerPreciseDodge(PreciseDistance))
		{
			/* TODO: 理論上Slow Motion部分應該要有獨立的子系統處理 */
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.f, FColor::Blue, TEXT("PreciseDodge"));
			UGameplayStatics::SetGlobalTimeDilation(this, PreciseTimeDilation);
			CustomTimeDilation = 1.f / PreciseTimeDilation;
			GetWorld()->GetTimerManager().SetTimer(PreciseTimeSlowMotionHandler, this, &APlayerCharacter::StopTimeSlowMotion, SlowMotionPersisTime * PreciseTimeDilation, false);
			CameraBlackWhiteFadeInEvent();
			//GetMainCamera()->PostProcessSettings.bOverride_ColorSaturation = true;
			//GetMainCamera()->PostProcessSettings.ColorSaturation = FVector4(0.f, 0.f, 0.f, 1.f); // 黑白效果
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.f, FColor::Red, TEXT("NormalDodge"));
		}

		FVector DodgeVelocity = FVector(DodgeDirection.X, DodgeDirection.Y, 0.f) * DodgeForce;
		LaunchCharacter(DodgeVelocity, true, true);
		StatusComp->DecreaseCurrentStamina(DodgeStaminaCost);
	}

	// TOOD:冷卻？需要嗎？看體力恢復速度而定，如果超過100點的體力，就表示可以連續迴避
}

void APlayerCharacter::StopTimeSlowMotion()
{
	UGameplayStatics::SetGlobalTimeDilation(this, 1.f);
	CustomTimeDilation = 1.f;
	GetWorld()->GetTimerManager().ClearTimer(PreciseTimeSlowMotionHandler);
	CameraBlackWhiteFadeOutEvent();
	//GetMainCamera()->PostProcessSettings.bOverride_ColorSaturation = false;
	//GetMainCamera()->PostProcessSettings.ColorSaturation = FVector4(1.f, 1.f, 1.f, 1.f); // 黑白效果 恢復
}

