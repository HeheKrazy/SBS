// Copyright HeheKrazy


#include "Characters/SBS_BaseCharacter.h"

ASBS_BaseCharacter::ASBS_BaseCharacter()
{

	PrimaryActorTick.bCanEverTick = false;

	// Tick and refresh bone transforms whether rendered or not - for bone updates on a dedicated server
	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
}

UAbilitySystemComponent* ASBS_BaseCharacter::GetAbilitySystemComponent() const
{
	return nullptr;
}







