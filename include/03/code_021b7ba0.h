#pragma once

#include "types.h"

typedef struct PollEntry {
    /* 00 */ s32 mDescriptor;
    /* 04 */ u16 mAskedBits;
    /* 06 */ u16 mFoundBits;
} PollEntry;

void SetPollEntryForRead(s32 value, PollEntry *object);
