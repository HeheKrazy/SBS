// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "Characters/SBS_BaseCharacter.h"
#include "SBS_PlayerCharacter.generated.h"

/**
 * 
 */

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class SBS_API ASBS_PlayerCharacter : public ASBS_BaseCharacter
{
	GENERATED_BODY()


public:
	ASBS_PlayerCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	TObjectPtr<class USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	TObjectPtr<class UCameraComponent> FollowCamera;
};
