#pragma once

#include "types.h"

void WriteRecordSceneRegistersCallback(void);
// Slot mRelease: calls the state's undo functions and clears the globals; frees nothing itself (the
// scene heap goes with the scene).
void ReleaseRecordScene(void);
