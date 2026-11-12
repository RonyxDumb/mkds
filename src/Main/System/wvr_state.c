#include "Main/System/wvr_state.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "wvr.h"
#include "code_0200fc8c.h"
#include "code_02148950.h"
#include "code_0214d018.h"
#include "registers.h"

UnreadHalfwordGroups gUnreadHalfwordGroups;

static inline u32 IsWvrStateBusy(void) {
    return gWvrState.mState == BANK_SHARE_CHANGING;
}

void InitWvrState(void) {
    gWvrState.mState = BANK_SHARE_INACTIVE;
    gWvrState.mCallback = NULL;
}

void ClearLcdcBanksByState(void) {
    switch (gWvrState.mState) {
        case BANK_SHARE_ACTIVE:
            GX_SetBankForLCDC(0x1f7);
            MemFillWordsByBlock_inline((void *) 0x6800000, 0x60000);
            MemFillWordsByBlock_inline((void *) 0x6880000, 0x24000);
            break;
        case BANK_SHARE_CHANGING:
            break;
        case BANK_SHARE_INACTIVE:
        case 3:
            GX_SetBankForLCDC(0x1ff);
            MemFillWordsByBlock_inline((void *) 0x6800000, 0xa4000);
            break;
    }
    GX_DisableBankForLCDC();
}

void SetBankForARM7ByState(u32 bank) {
    switch (gWvrState.mState) {
        case BANK_SHARE_ACTIVE:
        case BANK_SHARE_CHANGING:
            break;
        case BANK_SHARE_INACTIVE:
        case 3:
            GX_SetBankForARM7(bank);
            break;
    }
}

void DisableAllBanks(void) {
    GX_DisableBankForBG();
    GX_DisableBankForOBJ();
    GX_DisableBankForBGExtPltt();
    GX_DisableBankForOBJExtPltt();
    GX_DisableBankForTex();
    GX_DisableBankForTexPltt();
    GX_DisableBankForClearImage();
    GX_DisableBankForSubBG();
    GX_DisableBankForSubOBJ();
    GX_DisableBankForSubBGExtPltt();
    GX_DisableBankForSubOBJExtPltt();
    GX_DisableBankForLCDC();
    switch (gWvrState.mState) {
        case BANK_SHARE_ACTIVE:
        case BANK_SHARE_CHANGING:
            break;
        case BANK_SHARE_INACTIVE:
        case 3:
            GX_DisableBankForARM7();
            break;
    }
}

// Stores the state; for states 0 and 1 calls the stored callback with 0 or 1.
void WvrCallback(u32 state, s32 errorCode) {
    if (errorCode != 0) {
        OS_Terminate();
    }
    gWvrState.mState = state;
    if (gWvrState.mCallback == NULL) {
        return;
    }
    switch (state) {
        case BANK_SHARE_ACTIVE:
            gWvrState.mCallback(0);
            break;
        case BANK_SHARE_INACTIVE:
            gWvrState.mCallback(1);
            break;
    }
}

void ClearLcdcBankAndStartWvrAndWait(void) {
    if (gWvrState.mState != BANK_SHARE_ACTIVE && gWvrState.mState != 3) {
        gWvrState.mState = BANK_SHARE_CHANGING;
        GX_SetBankForLCDC(8);
        MemFillWordsByBlock_inline((void *) 0x6860000, 0x20000);
        GX_DisableBankForLCDC();
        if (WVR_StartUpAsync(8, WvrCallback, 0) != 1) {
            OS_Terminate();
        }
    }
    while (IsWvrStateBusy() != 0) {
    }
}

void StopWvrAndWait(void) {
    if (gWvrState.mState != BANK_SHARE_INACTIVE && gWvrState.mState != 3) {
        gWvrState.mState = BANK_SHARE_CHANGING;
        if (WVR_TerminateAsync(WvrCallback, 1) != 1) {
            OS_Terminate();
        }
    }
    while (IsWvrStateBusy() != 0) {
    }
}

s32 Vec3NormalizeAndGetLengthUnchecked(const Vec3 *vec, Vec3 *dst) {
    s64 lengthSquared;
    s32 sqrtResult;
    s64 divResult;
    s64 scale;
    lengthSquared = (s64) vec->x * vec->x;
    lengthSquared += (s64) vec->y * vec->y;
    lengthSquared += (s64) vec->z * vec->z;
    reg_CP_DIVCNT = 2;
    reg_CP_DIV_NUMER = 0x1000000000000LL << 8;
    reg_CP_DIV_DENOM = lengthSquared;
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = lengthSquared << 2;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    sqrtResult = reg_CP_SQRT_RESULT;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    divResult = reg_CP_DIV_RESULT;
    scale = divResult * sqrtResult;
    dst->x = (scale * vec->x + 0x100000000000LL) >> 45;
    dst->y = (scale * vec->y + 0x100000000000LL) >> 45;
    dst->z = (scale * vec->z + 0x100000000000LL) >> 45;
    return (sqrtResult + 1) >> 1;
}

s32 Vec3DotUnrounded(const Vec3 *lhs, const Vec3 *rhs) {
    return DOT3_FIXED12(lhs->x, rhs->x, lhs->y, rhs->y, lhs->z, rhs->z);
}

void Vec3CrossUnrounded(const Vec3 *lhs, const Vec3 *rhs, Vec3 *axb) {
    s64 crossX;
    s64 crossY;
    s64 crossZ;
    crossX = (s64) lhs->y * rhs->z - (s64) lhs->z * rhs->y;
    crossY = (s64) lhs->z * rhs->x - (s64) lhs->x * rhs->z;
    crossZ = (s64) lhs->x * rhs->y - (s64) lhs->y * rhs->x;
    axb->x = FROM_FIXED12(crossX);
    axb->y = FROM_FIXED12(crossY);
    axb->z = FROM_FIXED12(crossZ);
}

void InitUnreadHalfwordGroups(void) {
    gUnreadHalfwordGroups.mUnk_08 = 0;
    gUnreadHalfwordGroups.mUnk_0a = 0;
    gUnreadHalfwordGroups.mUnk_0c = 0;
    gUnreadHalfwordGroups.mUnk_0e = 3;
    gUnreadHalfwordGroups.mUnk_00 = 0;
    gUnreadHalfwordGroups.mUnk_02 = 0;
    gUnreadHalfwordGroups.mUnk_04 = 0;
    gUnreadHalfwordGroups.mUnk_06 = 3;
}
