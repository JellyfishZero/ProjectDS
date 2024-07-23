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

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

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
	if (StatusComp->GetCurrentStamina() >= DodgeStaminaCost)
	{
		FVector LastMovementInputDirection = GetLastMovementInputVector().GetSafeNormal();

		FVector DodgeVelocity = FVector(LastMovementInputDirection.X, LastMovementInputDirection.Y, 0.f) * DodgeForce;
		LaunchCharacter(DodgeVelocity, true, true);
		StatusComp->DecreaseCurrentStamina(DodgeStaminaCost);
	}

	// TOOD:冷卻？需要嗎？看體力恢復速度而定，如果超過100點的體力，就表示可以連續迴避
}

