#pragma once

#include "types.h"

// Runs AdvanceSelectCupGridShownCourse and waits until IsSelectChoisesState1NoState0Request returns non-zero (after the
// request of state 8, RequestSelectCupGridState8, opened a message with gmenu_startSelectChoices), then requests state 9.
void AdvanceSelectCupGridState8(void);
