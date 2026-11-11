#pragma once

#include "types.h"
#include "00/code_021947e4.h"

typedef struct GpiProfileSearch {
    /* 00 */ u32 mKey;
    /* 04 */ GpiProfile *mEntry;
} GpiProfileSearch;

BOOL gpiCheckForBuddy(void *unused, GpiProfile *entry, GpiProfileSearch *search);
