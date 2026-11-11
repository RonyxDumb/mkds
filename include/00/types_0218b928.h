#pragma once

#include "types.h"

// Entry of the list at SbServerList.mUnk_008.
typedef struct KeyInfo {
    /* 0 */ char *mKeyName;
    /* 4 */ s32 mKeyType;
} KeyInfo;
