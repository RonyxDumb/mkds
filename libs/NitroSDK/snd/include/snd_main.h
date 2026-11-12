#pragma once

#include "types.h"

typedef struct OSMutex OSMutex;

extern u32 sSndInitialized;
extern OSMutex sSndMutex;

void SNDi_UnlockMutex(void);
void SNDi_LockMutex(void);
void SND_Init(void);
