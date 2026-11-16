#pragma once

#include "types.h"

typedef struct OSMutex OSMutex;

extern u32 g_SoundInnerInitialized;
extern OSMutex g_SoundMutex;

void Sound_UnlockMutex(void);
void Sound_LockMutex(void);
void Sound_InitializeImpl(void);
