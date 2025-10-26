// Copyright HeheKrazy


#include "UI/SBS_WidgetComponent.h"
#include "AbilitySystem/SBSAbilitySystemComponent.h"
#include "AbilitySystem/SBS_AttributeSet.h"
#include "Characters/SBS_BaseCharacter.h"
#include "UI/SBS_AttributeWidget.h"
#include "Blueprint/WidgetTree.h"

void USBS_WidgetComponent::BeginPlay()
{
	Super::BeginPlay();

	InitAbilitySystemData();

	if (!IsASCInitialized())
	{
		SBSCharacter->OnASCInitialized.AddDynamic(this, &ThisClass::OnASCInitialized);
		return;
	}

	InitializeAttributeDelegate();
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

	if(!IsASCInitialized()) {return;}
	InitializeAttributeDelegate();
}

void USBS_WidgetComponent::InitializeAttributeDelegate()
{
	if (!AttributeSet->bAttributesInitialized)
	{
		AttributeSet->OnAttributesInitialized.AddDynamic(this, &ThisClass::BindToAttributeChange);
	}
	else
	{
		BindToAttributeChange();
	}
}

void USBS_WidgetComponent::BindToAttributeChange()
{
	for (const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair : AttributeMap)
	{
		BindWidgetToAttributeChanges(GetUserWidgetObject(), Pair); // Check the owned widget object

		GetUserWidgetObject()->WidgetTree->ForEachWidget([this, &Pair](UWidget* ChildWidget) 
			{
				BindWidgetToAttributeChanges(ChildWidget, Pair);
			});

	}
}

void USBS_WidgetComponent::BindWidgetToAttributeChanges(UWidget* WidgetObject, const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const
{
	USBS_AttributeWidget* AttributeWidget = Cast<USBS_AttributeWidget>(WidgetObject);
	if (!IsValid(AttributeWidget)) return; // We only care about SBS_AttributeWidget
	if (!AttributeWidget->MatchesAttributes(Pair)) return;	// Only bind if the attributes match

	AttributeWidget->OnAttributeChanged(Pair, AttributeSet.Get()); // Initial update
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Key).AddLambda([this, AttributeWidget, &Pair](const FOnAttributeChangeData& AttributeChangeData)
		{
			AttributeWidget->OnAttributeChanged(Pair, AttributeSet.Get()); // For changes during gameplay
		});
}
