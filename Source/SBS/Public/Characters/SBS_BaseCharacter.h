// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "SBS_BaseCharacter.generated.h"

UCLASS(Abstract)
class SBS_API ASBS_BaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ASBS_BaseCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

};
