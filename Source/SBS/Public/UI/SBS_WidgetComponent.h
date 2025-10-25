// Copyright HeheKrazy

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "SBS_WidgetComponent.generated.h"

/**
 * 
 */
class ASBS_BaseCharacter;
class USBSAbilitySystemComponent;
class USBS_AttributeSet;
class UAbilitySystemComponent;
class UAttributeSet;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SBS_API USBS_WidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;	

private:
	TWeakObjectPtr<ASBS_BaseCharacter> SBSCharacter;
	TWeakObjectPtr<USBSAbilitySystemComponent> AbilitySystemComponent;
	TWeakObjectPtr<USBS_AttributeSet> AttributeSet;

	void InitAbilitySystemData();
	bool IsASCInitialized() const;

	UFUNCTION()
	void OnASCInitialized(UAbilitySystemComponent* ASC, UAttributeSet* AS);
	
	void InitializeAttributeDelegate();

	UFUNCTION()
	void BindToAttributeChange();

};
