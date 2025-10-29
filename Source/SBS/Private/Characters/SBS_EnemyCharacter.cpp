// Copyright HeheKrazy


#include "Characters/SBS_EnemyCharacter.h"
#include "AbilitySystem/SBSAbilitySystemComponent.h"
#include "AbilitySystem/SBS_AttributeSet.h"	
#include "AIController.h"

ASBS_EnemyCharacter::ASBS_EnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	AbilitySystemComponent = CreateDefaultSubobject<USBSAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<USBS_AttributeSet>("AttributeSet");
}

UAbilitySystemComponent* ASBS_EnemyCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* ASBS_EnemyCharacter::GetAttributeSet() const
{
	return AttributeSet;
}

void ASBS_EnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (!IsValid(GetAbilitySystemComponent())) return;

	GetAbilitySystemComponent()->InitAbilityActorInfo(this, this);
	OnASCInitialized.Broadcast(GetAbilitySystemComponent(), GetAttributeSet());
	
	if (!HasAuthority()) return;	

	GiveStartupAbilities();
	InitializeAttributes();


	USBS_AttributeSet* SBSAttributeSet = Cast<USBS_AttributeSet>(GetAttributeSet());
	if (!IsValid(SBSAttributeSet)) return;

	GetAbilitySystemComponent()->GetGameplayAttributeValueChangeDelegate(SBSAttributeSet->GetHealthAttribute()).AddUObject(this, &ThisClass::OnHealthChanged);
}

void ASBS_EnemyCharacter::HandleDeath()
{
	Super::HandleDeath();
	// Additional death logic for enemy characters can be added here
	AAIController* AIController = GetController<AAIController>();
	if (!IsValid(AIController)) return;
	AIController->StopMovement();
}
