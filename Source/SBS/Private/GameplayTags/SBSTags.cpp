// Copyright HeheKrazy


#include "GameplayTags/SBSTags.h"


namespace SBSTags
{
	namespace SetByCaller
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Projectile, "SBSTags.SetByCaller.Projectile", "Tags for Set by Caller Magnitude for projectile.");
	}

	namespace SBSAbilities
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(ActivateOnGiven, "SBSTags.SBSAbilities.ActivateOnGiven", "Tags for Abilities that should be activated immediately once given.");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Primary, "SBSTags.SBSAbilities.Primary", "Primary ability tag for SBS.");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Secondary, "SBSTags.SBSAbilities.Secondary", "Secondary ability tag for SBS.");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Tertiary, "SBSTags.SBSAbilities.Tertiary", "Tertiary ability tag for SBS.");


		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attack, "SBSTags.SBSAbilities.Enemy.Attack", "Attack ability tag for Enemy.");
		}
	}

	namespace Events
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(KillScored, "SBSTags.Events.KillScored", "Tag for KillScored Event.");

		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(HitReact, "SBSTags.Events.Enemy.HitReact", "Tag for Enemy HitReact Event.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(EndAttack, "SBSTags.Events.Enemy.EndAttack", "Tag for Enemy Ending an Attack Event.");
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(MeleeTraceHit, "SBSTags.Events.Enemy.MeleeTraceHit", "Tag for Enemy Melee Trace Hit Event.");
		}
	}
}
