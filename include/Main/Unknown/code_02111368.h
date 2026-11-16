#pragma once

#include "types.h"

void recordsMenu_afterDraw(void);
// Slot mRelease: calls the state's undo functions and clears the globals; frees nothing itself (the
// scene heap goes with the scene).
void recordsMenu_onDelete(void);
