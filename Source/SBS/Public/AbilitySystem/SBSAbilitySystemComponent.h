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
	USBSAbilitySystemComponent();
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:

	virtual void BeginPlay() override;
	
};
