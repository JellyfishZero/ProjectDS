// All rights reserved by Jellyfish-zero.


#include "Actor/Pawn/Character/PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	MainCamera->SetupAttachment(GetCapsuleComponent());
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
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Look);
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
	MoveSpeed = WalkSpeed;
}

void APlayerCharacter::Move(const FInputActionValue& Value)
{
	// 正常走路
	FVector2D MovementVector = Value.Get<FVector2D>();
	MovementVector.Normalize();

	FRotator CameraRotation = GetMainCamera()->GetComponentRotation();
	FRotator YawRotation(0, CameraRotation.Yaw, 0);

	FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(ForwardDirection * UGameplayStatics::GetWorldDeltaSeconds(GetWorld()) * MoveSpeed, MovementVector.X);
	AddMovementInput(RightDirection * UGameplayStatics::GetWorldDeltaSeconds(GetWorld()) * MoveSpeed, MovementVector.Y);
}

void APlayerCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookVector = Value.Get<FVector2D>();

	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (ensure(IsValid(PlayerController)))
	{
		PlayerController->AddYawInput(LookVector.X);
		PlayerController->AddPitchInput(LookVector.Y);

		/* 角色模型延遲旋轉有關，先不做 */
		//FRotator Delta = GetControlRotation() - GetActorRotation();
		//if (Delta.Yaw > RotateAngle)
		//{
		//	GetCharacterMovement()->bUseControllerDesiredRotation = true;
		//	GetCharacterMovement()->bOrientRotationToMovement = false;
		//}
		//else if (Delta.Yaw < -RotateAngle)
		//{
		//	GetCharacterMovement()->bUseControllerDesiredRotation = true;
		//	GetCharacterMovement()->bOrientRotationToMovement = false;
		//}
		//else
		//{
		//	GetCharacterMovement()->bUseControllerDesiredRotation = false;
		//	GetCharacterMovement()->bOrientRotationToMovement = false;
		//}
	}
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
	FVector LastMovementInputDirection = GetLastMovementInputVector().GetSafeNormal();
	bool bIsOnGround = GetCharacterMovement()->IsMovingOnGround();

	// TODO:暫時消除摩擦力，看ChatGpt給的參考

	FVector DodgeForce = FVector(
		bIsOnGround ? LastMovementInputDirection.X * DodgeDistance : LastMovementInputDirection.X * DodgeDistance * AirDodgeDistanceRatio,
		bIsOnGround ? LastMovementInputDirection.Y * DodgeDistance : LastMovementInputDirection.Y * DodgeDistance * AirDodgeDistanceRatio,
		bIsOnGround ? 0.f : DodgetJumpingForce);
	LaunchCharacter(DodgeForce, true, true);
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, .2f, FColor::Cyan, FString::Printf(TEXT("Dodge, %s"), bIsOnGround ? TEXT("Gorund") : TEXT("Air")));

	// TODO:冷卻
}

