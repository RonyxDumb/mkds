#include "00/code_021a2950.h"
#include "00/code_0218aea4.h"
#include "00/code_0218b000.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_02134398.h"
#include "00/code_0218d818.h"
#include "00/unk_021b5000.h"
#include "00/code_0219b580.h"
#include "00/code_0219c384.h"
#include "00/code_0219eac8.h"
#include "00/code_021a1000.h"
#include "00/code_021a3264.h"
#include "03/code_021b94b8.h"
#include "00/code_021a369c.h"
#include "00/code_021a4b84.h"
#include "code_02139f70.h"
#include "00/code_021a01dc.h"
#include "00/code_0219dd4c.h"

u32 DWC_IsValidCancelMatching(void) {
    if (DWCi_IsError() != 0) {
        return 0;
    }
    if (gWiFiMatching == NULL || GetWiFiConnectionState() != 5 || gWiFiMatching->mStopPending != 0) {
        return 0;
    }
    return 1;
}

u32 DWC_AddMatchKeyInt(u32 keyId, char *keyString, void *valueSrc) {
    u32 index;
    if (keyString == NULL || valueSrc == NULL) {
        return 0;
    }
    if (keyId >= 100) {
        index = keyId - 100;
        if (gMatchingKeys[index][0] != 0) {
            return keyId;
        }
    }
    keyId = FindFreeMatchingKeyId();
    if (keyId == 0) {
        return 0;
    }
    index = keyId - 100;
    gMatchingKeys[index][0] = keyId;
    gMatchingKeyIsString[index * 12] = 0;
    *(u16 *) &gMatchingKeyPad[index * 12] = 0;
    if (*(void **) &gMatchingKeyString[index * 12] != NULL) {
        DWC_Free(4, *(u32 *) &gMatchingKeyString[index * 12], 0);
    }
    *(void **) &gMatchingKeyString[index * 12] = DWC_Alloc(4, strlen(keyString) + 1);
    if (*(void **) &gMatchingKeyString[index * 12] == NULL) {
        ReportMatchingError(0xb, 0xfffec77f);
        return 0;
    }
    strcpy(*(char **) &gMatchingKeyString[index * 12], keyString);
    *(void **) &gMatchingKeyValue[index * 12] = valueSrc;
    func_ov000_021a4b84(keyId, keyString);
    return keyId;
}

u32 DWC_AddMatchKeyString(u32 keyId, char *keyString, void *valueSrc) {
    u32 index;
    if (keyString == NULL || valueSrc == NULL) {
        return 0;
    }
    if (keyId >= 100) {
        index = keyId - 100;
        if (gMatchingKeys[index][0] != 0) {
            return keyId;
        }
    }
    keyId = FindFreeMatchingKeyId();
    if (keyId == 0) {
        return 0;
    }
    index = keyId - 100;
    gMatchingKeys[index][0] = keyId;
    gMatchingKeyIsString[index * 12] = 1;
    *(u16 *) &gMatchingKeyPad[index * 12] = 0;
    if (*(void **) &gMatchingKeyString[index * 12] != NULL) {
        DWC_Free(4, *(u32 *) &gMatchingKeyString[index * 12], 0);
    }
    *(void **) &gMatchingKeyString[index * 12] = DWC_Alloc(4, strlen(keyString) + 1);
    if (*(void **) &gMatchingKeyString[index * 12] == NULL) {
        ReportMatchingError(0xb, 0xfffec77f);
        return 0;
    }
    strcpy(*(char **) &gMatchingKeyString[index * 12], keyString);
    *(void **) &gMatchingKeyValue[index * 12] = valueSrc;
    func_ov000_021a4b84(keyId, keyString);
    return keyId;
}

s32 DWC_GetMatchIntValue(u32 index, void *keyString, s32 idefault) {
    u32 serverEntry;
    if (gWiFiMatching == NULL || DWCi_IsError() != 0) {
        return idefault;
    }
    serverEntry = ServerBrowserGetServer(gWiFiMatching->mServerList, index);
    if (serverEntry != 0) {
        idefault = SbServerGetInt((SbServer *) serverEntry, keyString, idefault);
    }
    return idefault;
}

u32 DWC_SetMatchingOption(u32 opttype, void *optval, u32 optlen) {
    WiFiMatching *wiFiMatching = gWiFiMatching;
    DWCMatchOptMinCompleteIn *optMinComp;
    if (wiFiMatching == NULL) {
        return 1;
    }
    if (optval == NULL) {
        return 3;
    }
    switch (opttype) {
        case 0:
            if (wiFiMatching->mState == 0x13) {
                return 1;
            }
            if (*(u8 *) optval != 0 && ((u8 *) optval)[1] <= 1) {
                return 3;
            }
            optMinComp = gOptMinComp;
            if (optMinComp == NULL) {
                optMinComp = DWC_Alloc(4, 0x20);
                gOptMinComp = optMinComp;
                if (optMinComp == NULL) {
                    return 4;
                }
            }
            optMinComp->mValid = *(u8 *) optval;
            gOptMinComp->mMinEntry = ((u8 *) optval)[1];
            gOptMinComp->mRetry = 0;
            gOptMinComp->mPad = 0;
            gOptMinComp->mTimeout = *OFFSET_PTR(u32, optval, 4);
            gOptMinComp->mRecvBit = 0;
            gOptMinComp->mTimeoutBit = 0;
            gOptMinComp->mStartTime = MatchingGetTickMilliseconds();
            gOptMinComp->mLastPollTime = MatchingGetTickMilliseconds();
            return 0;
        case 1:
            if (*(u32 *) optval != 0) {
                gOptSCBlock.mValid = 1;
            } else {
                gOptSCBlock.mValid = 0;
            }
            gOptSCBlock.mLock = 0;
            return 0;
        default:
            return 2;
    }
}

s32 DWC_GetMOMinCompState(u64 *time) {
    DWCMatchOptMinCompleteIn *optMinComp = gOptMinComp;
    u64 elapsed;
    if (optMinComp == NULL || optMinComp->mValid == 0) {
        return -1;
    }
    elapsed = MatchingGetTickMilliseconds() - optMinComp->mStartTime;
    if (time != NULL) {
        *time = elapsed;
    }
    return elapsed >= optMinComp->mTimeout;
}
