#pragma once

#include "types.h"

// Waits until mbright_isFadedIn returns non-zero, then requests state 1 (the first state after SPM_LoadCupSelectionMenu:
// mState is 0 from the allocation).
void AdvanceSelectCupGridState0(void);
