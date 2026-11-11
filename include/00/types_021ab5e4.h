#pragma once

#include "types.h"

// Entry of the four-entry table at gHttpsEntries.
typedef struct HttpsEntry {
    /* 00 */ u8 mSessionId[0x20];
    /* 20 */ u8 mMasterSecret[0x30];
    /* 50 */ u32 mLastUseTime;
    /* 54 */ u32 mRemoteIp;
    /* 58 */ u16 mRemotePort;
    /* 5a */ u8 mInUse;
    /* 5b */ u8 mUnk_5b;
} HttpsEntry;
