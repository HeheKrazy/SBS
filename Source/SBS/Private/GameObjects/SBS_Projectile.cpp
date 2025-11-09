// Copyright HeheKrazy


#include "GameObjects/SBS_Projectile.h"
#include "Player/SBS_PlayerCharacter.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include <AbilitySystemBlueprintLibrary.h>
#include "GameplayTags/SBSTags.h"
#include <Utils/SBS_BlueprintLibrary.h>

ASBS_Projectile::ASBS_Projectile()
{
	PrimaryActorTick.bCanEverTick = false;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
	bReplicates = true;
}

void ASBS_Projectile::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	ASBS_PlayerCharacter* PlayerCharacter = Cast<ASBS_PlayerCharacter>(OtherActor);
	if (!IsValid(PlayerCharacter)) return;
	if (!PlayerCharacter->IsAlive()) return;
	UAbilitySystemComponent* AbilitySystemComponent = PlayerCharacter->GetAbilitySystemComponent();
	if (!IsValid(AbilitySystemComponent) || !HasAuthority()) return;

	FGameplayEventData Payload;
	Payload.Instigator = GetOwner();
	Payload.Target = PlayerCharacter;

	USBS_BlueprintLibrary::SendDamageEventToPlayer(PlayerCharacter, DamageEffect, Payload, SBSTags::SetByCaller::Projectile, Damage);

	SpawnImpactEffects();
	Destroy();
}

