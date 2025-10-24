// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "SBSAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class SBS_API USBSAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:

	virtual void OnGiveAbility(FGameplayAbilitySpec& AbilitySpec) override;
	virtual void OnRep_ActivateAbilities() override;
	

private:

	void HandleAutoActivatedAbility(const FGameplayAbilitySpec& AbilitySpec);
};
