#include "Main/System/wireless_vram_state.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "wireless_driver_startup.h"
#include "reset_interrupts_halt.h"
#include "vram_bank_display_setup.h"
#include "cpu_copy_fill.h"
#include "registers.h"
#include "Main/Scene/scene_run_forever.h"

UnreadHalfwordGroups gUnreadHalfwordGroups;

static inline u32 IsWvrStateBusy(void) {
    return gWvrState.mState == WIRELESS_VRAM_STATE_BUSY;
}

void InitWvrState(void) {
    gWvrState.mState = WIRELESS_VRAM_STATE_STOPPED;
    gWvrState.mCallback = NULL;
}

void ClearLcdcBanksByState(void) {
    switch (gWvrState.mState) {
        case WIRELESS_VRAM_STATE_STARTED:
            GX_SetBankForLCDC(0x1f7);
            MemFillWordsByBlock_inline((void *) 0x6800000, 0x60000);
            MemFillWordsByBlock_inline((void *) 0x6880000, 0x24000);
            break;
        case WIRELESS_VRAM_STATE_BUSY:
            break;
        case WIRELESS_VRAM_STATE_STOPPED:
        case WIRELESS_VRAM_STATE_UNUSED:
            GX_SetBankForLCDC(0x1ff);
            MemFillWordsByBlock_inline((void *) 0x6800000, 0xa4000);
            break;
    }
    GX_DisableBankForLCDC();
}

void SetBankForARM7ByState(u32 bank) {
    switch (gWvrState.mState) {
        case WIRELESS_VRAM_STATE_STARTED:
        case WIRELESS_VRAM_STATE_BUSY:
            break;
        case WIRELESS_VRAM_STATE_STOPPED:
        case WIRELESS_VRAM_STATE_UNUSED:
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
        case WIRELESS_VRAM_STATE_STARTED:
        case WIRELESS_VRAM_STATE_BUSY:
            break;
        case WIRELESS_VRAM_STATE_STOPPED:
        case WIRELESS_VRAM_STATE_UNUSED:
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
        case WIRELESS_VRAM_STATE_STARTED:
            gWvrState.mCallback(WIRELESS_VRAM_STATE_STARTED);
            break;
        case WIRELESS_VRAM_STATE_STOPPED:
            gWvrState.mCallback(WIRELESS_VRAM_STATE_STOPPED);
            break;
    }
}

void ClearLcdcBankAndStartWvrAndWait(void) {
    if (gWvrState.mState != WIRELESS_VRAM_STATE_STARTED && gWvrState.mState != WIRELESS_VRAM_STATE_UNUSED) {
        gWvrState.mState = WIRELESS_VRAM_STATE_BUSY;
        GX_SetBankForLCDC(8);
        MemFillWordsByBlock_inline((void *) 0x6860000, 0x20000);
        GX_DisableBankForLCDC();
        if (WVR_StartUpAsync(8, WvrCallback, WIRELESS_VRAM_STATE_STARTED) != 1) {
            OS_Terminate();
        }
    }
    while (IsWvrStateBusy() != 0) {
    }
}

void StopWvrAndWait(void) {
    if (gWvrState.mState != WIRELESS_VRAM_STATE_STOPPED && gWvrState.mState != WIRELESS_VRAM_STATE_UNUSED) {
        gWvrState.mState = WIRELESS_VRAM_STATE_BUSY;
        if (WVR_TerminateAsync(WvrCallback, WIRELESS_VRAM_STATE_STOPPED) != 1) {
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
    while (reg_CP_SQRTCNT & REG_CP_SQRTCNT_BUSY_MASK) {
    }
    sqrtResult = reg_CP_SQRT_RESULT;
    while (reg_CP_DIVCNT & REG_CP_DIVCNT_BUSY_MASK) {
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
