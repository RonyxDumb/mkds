#pragma once

#include "types.h"

typedef struct RepeatCounter RepeatCounter;

void KBD_InitAutoRepeatValue(RepeatCounter *repeatCounter, unsigned int firstFireFrame, unsigned int repeatGap);
void KBD_InitAutoRepeat(RepeatCounter *repeatCounter);
