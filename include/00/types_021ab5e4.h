#pragma once

#include "types.h"

// Entry of the four-entry table at data_ov000_021b61f4.
typedef struct HttpsEntry {
    /* 00 */ u8 field0[0x20];
    /* 20 */ u8 field20[0x30];
    /* 50 */ u32 mLastUseTime;
    /* 54 */ u32 field54;
    /* 58 */ u16 field58;
    /* 5a */ u8 mInUse;
    /* 5b */ u8 field5B;
} HttpsEntry;
