#pragma once

#include "types.h"

unsigned int GetB488SomeMode(void);

// Values of MenuShared.mWLMenuKind: what the wireless menu opens for. The scene starts the message screen named after
// the next step (InitWLMenuScene); the title leaves 0, the race scene and the results set the others.
#define WL_MENU_KIND_JOIN_GROUP 0
#define WL_MENU_KIND_TO_RACE 1
#define WL_MENU_KIND_TO_RESULT 2
#define WL_MENU_KIND_TO_MENU 3
