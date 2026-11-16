#pragma once

#include "types.h"

// A buddy status: its index, status, status and location strings, and the IP and port it is at.
typedef struct GPIBuddyStatus {
    /* 00 */ s32 mIndex;
    /* 04 */ s32 mStatus;
    /* 08 */ void *mStatusString;
    /* 0c */ void *mLocationString;
    /* 10 */ u32 mIp;
    /* 14 */ s32 mPort;
} GPIBuddyStatus;

// A known profile: its ids, buddy status, info cache, signatures and request count.
typedef struct GPIProfile {
    /* 00 */ u32 mProfileId;
    /* 04 */ u32 mUserId;
    /* 08 */ GPIBuddyStatus *mBuddyStatus;
    /* 0c */ struct GPIInfoCache *mCache;
    /* 10 */ void *mAuthSig;
    /* 14 */ s32 mRequestCount;
    /* 18 */ void *mPeerSig;
} GPIProfile;

u32 gpiCanFreeProfile(GPIProfile *profile);
