// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "SBS_GameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class SBS_API USBS_GameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SBS|Debug")
	bool bDrawDebugs = false;
	
};
