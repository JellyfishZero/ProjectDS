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

    /* ���� */
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Level;

    /* �ͩR�O */
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Health;

    /* �]�O */
    UPROPERTY(EditAnywhere, BlueprintReadWrite) 
    int32 Mana;

    /* ��O */
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Stamina;

};