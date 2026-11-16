#pragma once

#include "types.h"

typedef struct OSMutex OSMutex;

extern u32 g_SoundInnerInitialized;
extern OSMutex g_SoundMutex;

void SNDi_UnlockMutex(void);
void SNDi_LockMutex(void);
void SND_Init(void);
