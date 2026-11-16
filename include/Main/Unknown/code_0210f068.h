#pragma once

#include "types.h"

typedef struct MicBuffer MicBuffer;

void mic_handlePostSleep(MicBuffer *micBuffer);
void mic_handlePreSleep(MicBuffer *micBuffer);
