#include "Main/Unknown/code_02055730.h"

#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_02000000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_020497f0.h"
#include "Main/Unknown/code_0204db40.h"
#include "Main/Unknown/code_0204db48.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_02055710.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200eddc.h"
#include "code_02148950.h"
#include "code_0214a390.h"
#include "code_0214b824.h"
#include "code_0214d018.h"
#include "registers.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_02060004.h"
#include "Main/Unknown/unk_021759c0.h"

#pragma thumb on

// Returns 0 unless all 32 Grand Prix records are filled with a value of 5 or more; else the lowest value (5 to 7)
// minus 4.
u8 GetLowestGrandPrixRecordValue(void) {
    u8 cupIndex;
    s32 lowestValue;
    u8 engineClass;
    s32 recordValue;

    lowestValue = 7;
    for (cupIndex = 0; cupIndex < 8; cupIndex++) {
        for (engineClass = 0; engineClass < 4; engineClass++) {
            recordValue = GetGrandPrixRecordGrade(cupIndex, engineClass);
            if (recordValue == 9 || recordValue < lowestValue) {
                lowestValue = recordValue;
            }
            if (lowestValue == 9 || lowestValue < 5) {
                return 0;
            }
        }
    }
    switch (lowestValue) {
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 3;
        default:
            return 0;
    }
}

#pragma thumb off

void InitDispCap(void *heap) {
    gDispCap = HeapAlloc(heap, 0x10);
    if (gRaceSetup->mRaceKind == RACE_KIND_START_GP || gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        gDispCap->mOamBuffer = HeapAllocAligned(heap, 0x400, 0x20);
    } else {
        gDispCap->mOamBuffer = NULL;
    }
    gDispCap->mFlags = 0;
    gDispCap->mBlendMin = 0;
    gDispCap->mBlendFactor = 0x1000;
    gDispCap->mMode = 0;
    if (data_02175614.mState == BANK_SHARE_ACTIVE) {
        gDispCap->mMode = 0;
    }
}

void ClearDispCapPointer(void) {
    gDispCap = NULL;
}

static inline u32 func_02055808_inline(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

static inline s32 func_02055808_inline2(void) {
    BOOL r = FALSE;
    if (func_02055808_inline() != 0 && gConnectionWork->mState != 13) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02055808_inline3(void) {
    BOOL r = FALSE;
    if (func_02055808_inline2() && !(gConnectionWork->mFlags & CONNECTION_FLAG_ENDING)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02055808_inline4(void) {
    BOOL r = FALSE;
    if (func_02055808_inline3() && gConnectionWork->mErrorCode != 9) {
        r = TRUE;
    }
    return r;
}

void SetDispCapMode(s32 mode) {
    gDispCap->mMode = mode;
    if (data_02175614.mState == BANK_SHARE_ACTIVE) {
        gDispCap->mMode = 0;
    }
}

void SetupDispCapMode1(void) {
    DispCapOamEntry *oamBuffer;
    s32 affineMatrix[4];
    s32 clearIndex;
    s32 column;
    s32 row;
    s32 entryIndex;
    DispCapOamEntry *oamEntry;

    oamBuffer = gDispCap->mOamBuffer;
    if (oamBuffer == NULL) {
        return;
    }
    affineMatrix[0] = 0x1000;
    affineMatrix[3] = 0x1000;
    affineMatrix[1] = 0;
    affineMatrix[2] = 0;
    G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, affineMatrix, 0, 0, 0, 0);
    for (clearIndex = 0; clearIndex < 0x80; clearIndex++) {
        oamBuffer[clearIndex].mUnk_00 = 0;
        oamBuffer[clearIndex].mUnk_04 = 0;
    }
    entryIndex = 0;
    for (row = 0; row < 3; row++) {
        for (column = 0; column < 4; column++) {
            oamEntry = &oamBuffer[entryIndex++];
            oamEntry->mUnk_00 = (u8) (0x40 * row) | 0xc0000c00 | ((column * 0x40 & 0x1ff) << 16);
            oamEntry->mUnk_04_h = (0x100 * row + column * 8) | 0xf000;
        }
    }
    DC_FlushRange(oamBuffer, 0x400);
    GXS_LoadOAM(oamBuffer, 0, 0x400);
    VBlankIntrWait();
    gDispCap->mFlags &= ~1;
    reg_GX_POWCNT = reg_GX_POWCNT | 0x8000;
    ToggleDispCapBanks();
}

void SetupDispCap(void) {
    switch (gDispCap->mMode) {
        case 1:
            SetupDispCapMode1();
            break;
        case 2:
            GX_SetGraphicsMode(0xe, 0, 1);
            break;
    }
}

// Alternates the VRAM banks used for the display capture each time it runs.
void ToggleDispCapBanks(void) {
    u32 captureBits;
    u32 powerBit;

    GX_ResetBankForSubBG();
    GX_ResetBankForSubOBJ();
    if (gDispCap->mFlags & 1) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | 0x300;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1000;
        GX_SetBankForLCDC(4);
        GX_SetBankForSubOBJ(8);
        gDispCap->mFlags &= ~1;
        captureBits = 2;
        powerBit = 1;
    } else {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | 0x300;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x400;
        GX_SetBankForSubBG(4);
        GX_SetBankForLCDC(8);
        gDispCap->mFlags |= 1;
        captureBits = 3;
        powerBit = 0;
    }
    reg_GX_POWCNT = (reg_GX_POWCNT & ~0x8000) | (powerBit << 15);
    reg_GX_DISPCAPCNT = 0x80300010 | (captureBits << 16);
}

// Writes the capture blend weights; with a 0 it also moves the blend factor toward 0 (bit 2 of mFlags set) or 0x1000.
void AdvanceDispCapBlend(s32 a) {
    u8 weight;

    weight = gDispCap->mBlendMin + (((16 - gDispCap->mBlendMin) * gDispCap->mBlendFactor) >> 12);
    reg_GX_DISPCAPCNT = weight | (0xc0330000 | (u8) (16 - weight) << 8);
    if (a != 0) {
        return;
    }
    if (gDispCap->mFlags & 2) {
        if (gDispCap->mBlendFactor <= 0) {
            return;
        }
        gDispCap->mBlendFactor -= 0x802;
        if (gDispCap->mBlendFactor < 0) {
            gDispCap->mBlendFactor = 0;
        }
    } else {
        if (gDispCap->mBlendFactor >= 0x1000) {
            return;
        }
        gDispCap->mBlendFactor = gDispCap->mBlendFactor + 0x19a;
        if (gDispCap->mBlendFactor > 0x1000) {
            gDispCap->mBlendFactor = 0x1000;
        }
    }
}

void AdvanceDispCap(s32 a) {
    switch (gDispCap->mMode) {
        case 1:
            if (a == 0) {
                ToggleDispCapBanks();
            }
            break;
        case 2:
            AdvanceDispCapBlend(a);
            break;
    }
    if (!(gDispCap->mFlags & 4)) {
        return;
    }
    if (AreBrightnessFadesClear() == 0) {
        return;
    }
    gDispCap->mFlags &= ~4;
    gDispCap->mFlags &= ~8;
}

void StartDispCapBlend(u8 blendMin) {
    if (gDispCap->mMode != 2) {
        return;
    }
    gDispCap->mFlags |= 2;
    gDispCap->mBlendFactor = 0x1000;
    gDispCap->mBlendMin = blendMin;
}

static inline s32 func_02055b1c_inline(void) {
    BOOL r = FALSE;
    u32 t;
    if (gConnectionWork == NULL) {
        t = 0;
        r = FALSE;
    } else {
        t = gConnectionWork->mConnectionMode;
    }
    if (t != 0 && gConnectionWork->mState != 13) {
        r = TRUE;
    }
    return r;
}

void StopDispCapBlend(void) {
    if (gDispCap->mMode == 2) {
        gDispCap->mFlags &= ~2;
    }
}

void StartDispCapFadeToFaded(u32 frameCount) {
    if (GetSceneRunStep() != SCENE_RUN_STEP_RUNNING) {
        return;
    }
    gDispCap->mFlags |= 4;
    StartFadeToFadedNegativeOneScreen(frameCount, 1);
}

void StartDispCapFadeToClear(u32 frameCount) {
    if (GetSceneRunStep() != SCENE_RUN_STEP_RUNNING) {
        return;
    }
    gDispCap->mFlags |= 4;
    StartFadeToClearNegativeOneScreen(frameCount, 1);
}

BOOL IsSharedDispCapFadeFlagSet(void) {
    if (func_02055b1c_inline()) {
        if (IsDataSharingSyncDone() != 0) {
            return (gConnectionWork->mUnk_15bc_view.mUnk_0c->mUnk_06_0 & 4) != 0;
        }
        return FALSE;
    }
    return (gDispCap->mFlags & 8) != 0;
}

BOOL IsDispCapFadeFlagSet(void) {
    return (gDispCap->mFlags & 8) != 0;
}

// Sets bit 8; it stays set until the brightness fades are clear. A child console in a link leaves it alone.
void SetDispCapFadeFlag(void) {
    if (func_02055808_inline2() != 0 && func_02055808_inline() != 1) {
        return;
    }
    gDispCap->mFlags |= 8;
}

s32 RunRecordScene(SceneNumbers *sceneNumbers) {
    SceneCallbacks recordSceneCallbacks = gRecordSceneCallbacks;

    RunScene(sceneNumbers, &recordSceneCallbacks);
    return 0;
}

void StoreReceivedPlayerName(const void *entryName, s32 entryIndex, s32 keepMask) {
    u8 keptBits;

    keptBits = gConnectionWork->mReceivedNameMask & keepMask;
    MI_CpuCopy8(entryName, &gConnectionWork->mPlayerRecords[entryIndex], 0x14);
    gConnectionWork->mReceivedNameMask = keptBits | (1 << entryIndex);
}

s32 AdvanceNonMultiBootSetup(s32 isParent) {
    BOOL result;

    result = FALSE;
    if (gConnectionWork->mRequestPending != 0) {
        return result;
    }
    if (func_02055808_inline4()) {
        return 3;
    }
    switch (gConnectionWork->mStep) {
        case 0:
        case 21:
            gConnectionWork->mFlags &= ~CONNECTION_FLAG_MULTIBOOT_SETUP;
            gConnectionWork->mState = 1;
            Initialize();
            break;
        case 1:
            StartRomArchiveTransfer();
            break;
        case 2:
        case 36:
            if (isParent != 0) {
                SetLifeTime(0x14);
            } else {
                result = TRUE;
                gConnectionWork->mState = 3;
                StartScan(1, NULL, NULL);
            }
            break;
        case 3:
            MeasureChannel(0);
            break;
        case 4:
            SetParentChannelLowestSum();
            FillParentParameter(1);
            SetParentParameter();
            break;
        case 5:
            StartParent(NULL);
            break;
        case 6:
            StartMP();
            break;
        case 11:
            gConnectionWork->mState = 2;
            gConnectionWork->mChildren.mNameSendIndex = 0;
            result = TRUE;
            gConnectionWork->mStatusFlags &= ~CONNECTION_STATUS_CHILDREN_CHANGED;
            break;
        default:
            StopConnection();
            break;
    }
    return result;
}

s32 AdvanceSetupByMultiBoot(s32 isParent, s32 isMultiBoot) {
    if (isParent != 0) {
        if (isMultiBoot != 0) {
            return AdvanceMultiBootSetup(isParent);
        }
        return AdvanceNonMultiBootSetup(isParent);
    }
    if (gBootInfo->mUnk_00 == 2) {
        return AdvanceMultiBootSetup(isParent);
    }
    return AdvanceNonMultiBootSetup(isParent);
}

s32 AdvanceConnectByMultiBoot(u16 entryIndex) {
    if (gConnectionWork->mOperationFlags & CONNECTION_OPERATION_SCANNING) {
        gConnectionWork->mOperationFlags &= ~CONNECTION_OPERATION_SCANNING;
    }
    if (gBootInfo->mUnk_00 == 2 || IsScanSlotMultiBoot(entryIndex) != 0) {
        return AdvanceScanConnect(entryIndex);
    }
    return AdvanceNonMultiBootConnect(entryIndex);
}
