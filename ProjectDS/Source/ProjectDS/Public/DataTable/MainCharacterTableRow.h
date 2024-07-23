// All rights reserved by Jellyfish-zero.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MainCharacterTableRow.generated.h"

USTRUCT(BlueprintType)
struct PROJECTDS_API FMainCharacterTableRow : public FTableRowBase
{
    GENERATED_BODY()

public:

    FMainCharacterTableRow() {}

    /* 等級 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Level;

    /* 生命力 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Health;

    /* 魔力 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite) 
    int32 Mana;

    /* 體力 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Stamina;

};