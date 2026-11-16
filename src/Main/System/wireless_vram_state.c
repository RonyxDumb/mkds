#include "Main/System/wireless_vram_state.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "wireless_driver_startup.h"
#include "reset_interrupts_halt.h"
#include "vram_bank_display_setup.h"
#include "cpu_copy_fill.h"
#include "registers.h"
#include "Main/Scene/scene_run_forever.h"

UnreadHalfwordGroups g_GlobalHN;

static inline u32 IsWvrStateBusy(void) {
    return g_SomeVramConfigMode.mState == BANK_SHARE_CHANGING;
}

void SomeVramInit(void) {
    g_SomeVramConfigMode.mState = BANK_SHARE_INACTIVE;
    g_SomeVramConfigMode.mCallback = NULL;
}

void MaybePrepareVram(void) {
    switch (g_SomeVramConfigMode.mState) {
        case BANK_SHARE_ACTIVE:
            GX_SetBankForLCDC(0x1f7);
            MemFillWordsByBlock_inline((void *) 0x6800000, 0x60000);
            MemFillWordsByBlock_inline((void *) 0x6880000, 0x24000);
            break;
        case BANK_SHARE_CHANGING:
            break;
        case BANK_SHARE_INACTIVE:
        case BANK_SHARE_INACTIVE_UNUSED:
            GX_SetBankForLCDC(0x1ff);
            MemFillWordsByBlock_inline((void *) 0x6800000, 0xa4000);
            break;
    }
    GX_DisableBankForLCDC();
}

void SetBankForARM7ByState(u32 bank) {
    switch (g_SomeVramConfigMode.mState) {
        case BANK_SHARE_ACTIVE:
        case BANK_SHARE_CHANGING:
            break;
        case BANK_SHARE_INACTIVE:
        case BANK_SHARE_INACTIVE_UNUSED:
            GX_SetBankForARM7(bank);
            break;
    }
}

void ResetSomeVram(void) {
    GX_DisableBankForBG();
    GX_DisableBankForOBJ();
    GX_DisableBankForBGExtPltt();
    GX_DisableBankForOBJExtPltt();
    GX_DisableBankForTex();
    GX_DisableBankForTexPltt();
    GX_DisableBankForClearImage();
    GX_DisableBankForSubBG();
    GX_DisableBankForSubOBJ();
    GX_DisableBankForBGExtPltt();
    GX_DisableBankForOBJExtPltt();
    GX_DisableBankForLCDC();
    switch (g_SomeVramConfigMode.mState) {
        case BANK_SHARE_ACTIVE:
        case BANK_SHARE_CHANGING:
            break;
        case BANK_SHARE_INACTIVE:
        case BANK_SHARE_INACTIVE_UNUSED:
            GX_DisableBankForARM7();
            break;
    }
}

// Stores the state; for states 0 and 1 calls the stored callback with 0 or 1.
void WvrCallback(u32 state, s32 errorCode) {
    if (errorCode != 0) {
        Os_Terminate();
    }
    g_SomeVramConfigMode.mState = state;
    if (g_SomeVramConfigMode.mCallback == NULL) {
        return;
    }
    switch (state) {
        case BANK_SHARE_ACTIVE:
            g_SomeVramConfigMode.mCallback(0);
            break;
        case BANK_SHARE_INACTIVE:
            g_SomeVramConfigMode.mCallback(1);
            break;
    }
}

void SomeVramConfig(void) {
    if (g_SomeVramConfigMode.mState != BANK_SHARE_ACTIVE && g_SomeVramConfigMode.mState != BANK_SHARE_INACTIVE_UNUSED) {
        g_SomeVramConfigMode.mState = BANK_SHARE_CHANGING;
        GX_SetBankForLCDC(8);
        MemFillWordsByBlock_inline((void *) 0x6860000, 0x20000);
        GX_DisableBankForLCDC();
        if (WVR_StartUpAsync(8, WvrCallback, 0) != 1) {
            Os_Terminate();
        }
    }
    while (IsWvrStateBusy() != 0) {
    }
}

void MaybeInitializeSomeWirelessShit(void) {
    if (g_SomeVramConfigMode.mState != BANK_SHARE_INACTIVE && g_SomeVramConfigMode.mState != BANK_SHARE_INACTIVE_UNUSED) {
        g_SomeVramConfigMode.mState = BANK_SHARE_CHANGING;
        if (SetWvrFifoShit(WvrCallback, 1) != 1) {
            Os_Terminate();
        }
    }
    while (IsWvrStateBusy() != 0) {
    }
}

s32 Vector3_MaybeNormalize(const Vec3 *vec, Vec3 *dst) {
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

s32 VecFx32_CrossProduct_0(const Vec3 *lhs, const Vec3 *rhs) {
    return DOT3_FIXED12(lhs->x, rhs->x, lhs->y, rhs->y, lhs->z, rhs->z);
}

void Vector3_Cross(const Vec3 *lhs, const Vec3 *rhs, Vec3 *axb) {
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

void InitializeGlobalHN(void) {
    g_GlobalHN.mUnk_08 = 0;
    g_GlobalHN.mUnk_0a = 0;
    g_GlobalHN.mUnk_0c = 0;
    g_GlobalHN.mUnk_0e = 3;
    g_GlobalHN.mUnk_00 = 0;
    g_GlobalHN.mUnk_02 = 0;
    g_GlobalHN.mUnk_04 = 0;
    g_GlobalHN.mUnk_06 = 3;
}
