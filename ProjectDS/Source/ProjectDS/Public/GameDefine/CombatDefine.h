#pragma once

#include "CoreMinimal.h"
#include "CombatDefine.generated.h"

/* 陣營列舉 */
UENUM(BlueprintType)
enum class ECampType : uint8
{
	None			UMETA(DisplayName = "無"),
	Confederation	UMETA(DisplayName = "邦聯(主角方)"),
	Kingdom			UMETA(DisplayName = "王國(敵方)"),
};
