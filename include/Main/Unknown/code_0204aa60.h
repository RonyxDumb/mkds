#pragma once

#include "types.h"
#include "Main/Unknown/code_020d22c0.h" // RandomState64

RandomState64 *sysdat_getRandom(void);
BOOL sysdat_configureBackLight(s32 firstRequest, s32 secondRequest);
void sysdat_204AB64(u32 fadeSteps);
void sysdat_unloadSeq(void);
void sysdat_stopSeq(void);
void sysdat_startSeq(void);
void sysdat_loadSeq(s32 seqId);
