#pragma once

#include "types.h"

// Object at 0x08 of GpiProfile: GpiWriteDelbuddyAndRemoveBuddy reads its 0x00 and passes its 0x08, its 0x0c and the
// object to func_ov000_021a3668.
typedef struct GpiBuddyStatus {
    /* 00 */ s32 mIndex;
    /* 04 */ s32 field4;
    /* 08 */ void *field8;
    /* 0c */ void *fieldC;
    /* 10 */ u32 field10;
    /* 14 */ s32 field14;
} GpiBuddyStatus;

// Object behind the pointer whose address GpiWriteDelbuddyAndRemoveBuddy passes to GpiFindProfile; GpiIsProfileEmpty
// returns 1 when 0x08, 0x0c, 0x10 and 0x18 are 0.
typedef struct GpiProfile {
    /* 00 */ u32 mProfileId;
    /* 04 */ u32 mUserId;
    /* 08 */ GpiBuddyStatus *mBuddyStatus;
    /* 0c */ struct Unk02192e04 *fieldC;
    /* 10 */ void *field10;
    /* 14 */ s32 field14;
    /* 18 */ void *field18;
} GpiProfile;

u32 GpiIsProfileEmpty(GpiProfile *a);
