#pragma once

#include "types.h"

typedef struct MicBuffer MicBuffer;

void mic_stopAutoSampling(MicBuffer *micBuffer);
void mic_startAutoSampling(MicBuffer *micBuffer);
void mic_finalize(MicBuffer *micBuffer);
