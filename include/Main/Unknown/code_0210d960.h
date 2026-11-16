#pragma once

#include "types.h"

unsigned int sound_getFadeFrameCount(void);
void sound_setFadeFrameCount(unsigned int fadeSteps);
unsigned int sound_getIsSdatLoaded(void);
void sound_setIsSdatLoaded(unsigned int flag);
