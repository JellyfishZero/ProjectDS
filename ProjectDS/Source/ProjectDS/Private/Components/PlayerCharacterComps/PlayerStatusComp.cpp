// All rights reserved by Jellyfish-zero.


#include "Components/PlayerCharacterComps/PlayerStatusComp.h"
#include "SubSystem/MainCharacterSubsystem/MainCharacterSubsystem.h"

// Sets default values for this component's properties
UPlayerStatusComp::UPlayerStatusComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

// Called every frame
void UPlayerStatusComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

// Called when the game starts
void UPlayerStatusComp::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}
