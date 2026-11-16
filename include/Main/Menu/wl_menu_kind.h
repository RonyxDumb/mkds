#pragma once

#include "types.h"

unsigned int GetWLMenuKind(void);

// Values of MenuShared.mWLMenuKind: what the wireless menu opens for. 0 starts the member group screen; the others
// start the message screen named after the next step (InitWLMenuScene).
#define WL_MENU_KIND_JOIN_GROUP 0
#define WL_MENU_KIND_TO_RACE 1
#define WL_MENU_KIND_TO_RESULT 2
#define WL_MENU_KIND_TO_MENU 3
