// Copyright HeheKrazy


#include "UI/SBS_WidgetComponent.h"
#include "AbilitySystem/SBSAbilitySystemComponent.h"
#include "AbilitySystem/SBS_AttributeSet.h"
#include "Characters/SBS_BaseCharacter.h"

void USBS_WidgetComponent::BeginPlay()
{
	Super::BeginPlay();

	InitAbilitySystemData();

	if (!IsASCInitialized())
	{
		SBSCharacter->OnASCInitialized.AddDynamic(this, &ThisClass::OnASCInitialized);
	}
}

void USBS_WidgetComponent::InitAbilitySystemData()
{
	SBSCharacter = Cast<ASBS_BaseCharacter>(GetOwner());
	AttributeSet = Cast<USBS_AttributeSet>(SBSCharacter->GetAttributeSet());
	AbilitySystemComponent = Cast<USBSAbilitySystemComponent>(SBSCharacter->GetAbilitySystemComponent());
}

bool USBS_WidgetComponent::IsASCInitialized() const
{
	return AbilitySystemComponent.IsValid() && AttributeSet.IsValid();
}

void USBS_WidgetComponent::OnASCInitialized(UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	AbilitySystemComponent = Cast<USBSAbilitySystemComponent>(ASC);
	AttributeSet = Cast<USBS_AttributeSet>(AS);

	//TODO: Check if the attribute set has been initialized properly
	//if not, bind to some delegate
}
