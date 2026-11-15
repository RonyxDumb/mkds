#pragma once

#include "types.h"

// Object at 0x08 of GpiProfile: GpiWriteDelbuddyAndRemoveBuddy reads its 0x00 and passes its 0x08, its 0x0c and the
// object to DWCi_GsFree.
typedef struct GpiBuddyStatus {
    /* 00 */ s32 mIndex;
    /* 04 */ s32 mStatus;
    /* 08 */ void *mStatusString;
    /* 0c */ void *mLocationString;
    /* 10 */ u32 mIp;
    /* 14 */ s32 mPort;
} GpiBuddyStatus;

// Object behind the pointer whose address GpiWriteDelbuddyAndRemoveBuddy passes to GpiFindProfile; GpiIsProfileEmpty
// returns 1 when 0x08, 0x0c, 0x10 and 0x18 are 0.
typedef struct GpiProfile {
    /* 00 */ u32 mProfileId;
    /* 04 */ u32 mUserId;
    /* 08 */ GpiBuddyStatus *mBuddyStatus;
    /* 0c */ struct GPIInfoCache *mCache;
    /* 10 */ void *mAuthSig;
    /* 14 */ s32 mRequestCount;
    /* 18 */ void *mPeerSig;
} GpiProfile;

u32 GpiIsProfileEmpty(GpiProfile *profile);
