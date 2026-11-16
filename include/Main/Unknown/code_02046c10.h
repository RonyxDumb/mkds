#pragma once

#include "types.h"

typedef struct InputSlotPair InputSlotPair;

u16 spi_getTouchPos(void);
void spi_finalize(void);
void spi_updateTpMic(InputSlotPair *pair, s32 b, s32 c);
void spi_update(void);
void spi_handlePostSleep(void);
void spi_handlePreSleep(void);
void spi_stopMicAutoSampling(void);
void spi_stopTouchAutoSampling(void);
void spi_startMicAutoSampling(void *heap);
void spi_startTouchAutoSampling(void);
