// Copyright HeheKrazy


#include "GameplayTags/SBSTags.h"


namespace SBSTags
{
	namespace SBSAbilities
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(ActivateOnGiven, "SBSTags.SBSAbilities.ActivateOnGiven", "Tags for Abilities that should be activated immediately once given.");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Primary, "SBSTags.SBSAbilities.Primary", "Primary ability tag for SBS.");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Secondary, "SBSTags.SBSAbilities.Secondary", "Secondary ability tag for SBS.");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Tertiary, "SBSTags.SBSAbilities.Tertiary", "Tertiary ability tag for SBS.");

	}

	namespace Events
	{
		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(HitReact, "SBSTags.Events.Enemy.HitReact", "Tag for Enemy HitReact Event.");
		}
	}
}
