#pragma once

#include "types.h"

typedef struct MicBuffer MicBuffer;

void PostSleepMicBuffer(MicBuffer *micBuffer);
void PreSleepMicBuffer(MicBuffer *micBuffer);
