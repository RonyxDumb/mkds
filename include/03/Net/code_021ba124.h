#pragma once

#include "types.h"
#include "03/Net/essid_packet_steps.h"
#include "code_0200e77c.h"
#include "03/unk_021d8000.h"

extern MaskCodeEntry gMaskCodeTable[12];
extern u8 gEssidAossString[11];
extern s8 gMelcoString[6];
extern void *(*gEssidAllocFunction)(u32);
extern void (*gStateChangeCallback)(s32);
extern void *gEssidWorkBuffer;
extern void (*gEssidFreeFunction)(void *);
extern void *gMessageQueueSlots[4];
extern OSMessageQueue gMessageQueue;
extern MelcoBlock gMelcoBlock;
extern RawEntry gMelcoRecord;
