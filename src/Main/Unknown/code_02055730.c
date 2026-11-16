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
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_02060004.h"
#include "Main/Unknown/unk_021759c0.h"

#pragma thumb on

u8 func_02056208(void) {
    u8 cupIndex;
    s32 lowestValue;
    u8 engineClass;
    s32 recordValue;

    lowestValue = 7;
    for (cupIndex = 0; cupIndex < 8; cupIndex++) {
        for (engineClass = 0; engineClass < 4; engineClass++) {
            recordValue = savd_getCupRank(cupIndex, engineClass);
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

void dce_init(void *heap) {
    sDceState = heap_alloc(heap, 0x10);
    if (gRaceMultiConfig->mRaceKind == RACE_KIND_START_GP || gRaceMultiConfig->mRaceKind == RACE_KIND_AWARD) {
        sDceState->mOamBuffer = heap_allocEx(heap, 0x400, 0x20);
    } else {
        sDceState->mOamBuffer = NULL;
    }
    sDceState->mFlags = 0;
    sDceState->mBlendMin = 0;
    sDceState->mBlendFactor = 0x1000;
    sDceState->mMode = 0;
    if (gVramWvrStatus.field0 == 0) {
        sDceState->mMode = 0;
    }
}

u32 dce_uninit(void) {
    u32 pointerAddress;
    u32 nullValue;
    pointerAddress = (u32) &sDceState;
    nullValue = 0u;
    *(u32 *) ((pointerAddress) + (0)) = nullValue;
    return pointerAddress;
}

static inline u32 func_02055808_inline(void) {
    if (gStruct217AA00 == NULL) {
        return 0;
    }
    return gStruct217AA00->field0;
}

static inline s32 func_02055808_inline2(void) {
    BOOL r = FALSE;
    if (func_02055808_inline() != 0 && gStruct217AA00->field4 != 13) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02055808_inline3(void) {
    BOOL r = FALSE;
    if (func_02055808_inline2() && !(gStruct217AA00->field454 & 0x80)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02055808_inline4(void) {
    BOOL r = FALSE;
    if (func_02055808_inline3() && gStruct217AA00->field8 != 9) {
        r = TRUE;
    }
    return r;
}

void dce_setMode(s32 mode) {
    sDceState->mMode = mode;
    if (gVramWvrStatus.field0 == 0) {
        sDceState->mMode = 0;
    }
}

void dce_setupDouble3D(void) {
    DispCapOamEntry *oamBuffer;
    s32 affineMatrix[4];
    s32 clearIndex;
    s32 column;
    s32 row;
    s32 entryIndex;
    DispCapOamEntry *oamEntry;

    oamBuffer = sDceState->mOamBuffer;
    if (oamBuffer == NULL) {
        return;
    }
    affineMatrix[0] = 0x1000;
    affineMatrix[3] = 0x1000;
    affineMatrix[1] = 0;
    affineMatrix[2] = 0;
    G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, affineMatrix, 0, 0, 0, 0);
    for (clearIndex = 0; clearIndex < 0x80; clearIndex++) {
        oamBuffer[clearIndex].field0 = 0;
        oamBuffer[clearIndex].field4 = 0;
    }
    entryIndex = 0;
    for (row = 0; row < 3; row++) {
        for (column = 0; column < 4; column++) {
            oamEntry = &oamBuffer[entryIndex++];
            oamEntry->field0 = (u8) (0x40 * row) | 0xc0000c00 | ((column * 0x40 & 0x1ff) << 16);
            oamEntry->mUnk_04_h = (0x100 * row + column * 8) | 0xf000;
        }
    }
    DC_FlushRange(oamBuffer, 0x400);
    GXS_LoadOAM(oamBuffer, 0, 0x400);
    VBlankIntrWait();
    sDceState->mFlags &= ~1;
    reg_GX_POWCNT = reg_GX_POWCNT | 0x8000;
    dce_updateDouble3D();
}

void dce_setupGX(void) {
    switch (sDceState->mMode) {
        case 1:
            dce_setupDouble3D();
            break;
        case 2:
            GX_SetGraphicsMode(0xe, 0, 1);
            break;
    }
}

// Alternates the VRAM banks used for the display capture each time it runs.
void dce_updateDouble3D(void) {
    u32 captureBits;
    u32 powerBit;

    GX_ResetBankForSubBG();
    GX_ResetBankForSubOBJ();
    if (sDceState->mFlags & 1) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | 0x300;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1000;
        GX_SetBankForLCDC(4);
        GX_SetBankForSubOBJ(8);
        sDceState->mFlags &= ~1;
        captureBits = 2;
        powerBit = 1;
    } else {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | 0x300;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x400;
        GX_SetBankForSubBG(4);
        GX_SetBankForLCDC(8);
        sDceState->mFlags |= 1;
        captureBits = 3;
        powerBit = 0;
    }
    reg_GX_POWCNT = (reg_GX_POWCNT & ~0x8000) | (powerBit << 15);
    reg_GX_DISPCAPCNT = 0x80300010 | (captureBits << 16);
}

// Writes the capture blend weights; with a 0 it also moves the blend factor toward 0 (bit 2 of mFlags set) or 0x1000.
void dce_updateBlur(s32 a) {
    u8 weight;

    weight = sDceState->mBlendMin + (((16 - sDceState->mBlendMin) * sDceState->mBlendFactor) >> 12);
    reg_GX_DISPCAPCNT = weight | (0xc0330000 | (u8) (16 - weight) << 8);
    if (a != 0) {
        return;
    }
    if (sDceState->mFlags & 2) {
        if (sDceState->mBlendFactor <= 0) {
            return;
        }
        sDceState->mBlendFactor -= 0x802;
        if (sDceState->mBlendFactor < 0) {
            sDceState->mBlendFactor = 0;
        }
    } else {
        if (sDceState->mBlendFactor >= 0x1000) {
            return;
        }
        sDceState->mBlendFactor = sDceState->mBlendFactor + 0x19a;
        if (sDceState->mBlendFactor > 0x1000) {
            sDceState->mBlendFactor = 0x1000;
        }
    }
}

void dce_updateVBlank(s32 a) {
    switch (sDceState->mMode) {
        case 1:
            if (a == 0) {
                dce_updateDouble3D();
            }
            break;
        case 2:
            dce_updateBlur(a);
            break;
    }
    if (!(sDceState->mFlags & 4)) {
        return;
    }
    if (mbright_isFadedIn() == 0) {
        return;
    }
    sDceState->mFlags &= ~4;
    sDceState->mFlags &= ~8;
}

void dce_startBlur(u8 blendMin) {
    if (sDceState->mMode != 2) {
        return;
    }
    sDceState->mFlags |= 2;
    sDceState->mBlendFactor = 0x1000;
    sDceState->mBlendMin = blendMin;
}

static inline s32 func_02055b1c_inline(void) {
    BOOL r = FALSE;
    u32 t;
    if (gStruct217AA00 == NULL) {
        t = 0;
        r = FALSE;
    } else {
        t = gStruct217AA00->field0;
    }
    if (t != 0 && gStruct217AA00->field4 != 13) {
        r = TRUE;
    }
    return r;
}

void dce_stopBlur(void) {
    if (sDceState->mMode == 2) {
        sDceState->mFlags &= ~2;
    }
}

void dce_fadeInFromBlack(u32 frameCount) {
    if (scene_getState() != 2) {
        return;
    }
    sDceState->mFlags |= 4;
    mbright_fadeFromBlackSingle(frameCount, 1);
}

void dce_fadeOutToBlack(u32 frameCount) {
    if (scene_getState() != 2) {
        return;
    }
    sDceState->mFlags |= 4;
    mbright_fadeToBlackSingle(frameCount, 1);
}

BOOL dce_2055B1C(void) {
    if (func_02055b1c_inline()) {
        if (sub_204FFBC() != 0) {
            return (gStruct217AA00->mUnk_15bc_view.fieldC->field6_0 & 4) != 0;
        }
        return FALSE;
    }
    return (sDceState->mFlags & 8) != 0;
}

BOOL dce_2055AFC(void) {
    return (sDceState->mFlags & 8) != 0;
}

void dce_2055A94(void) {
    if (func_02055808_inline2() != 0 && func_02055808_inline() != 1) {
        return;
    }
    sDceState->mFlags |= 8;
}

s32 record_run(SceneNumbers *sceneNumbers) {
    SceneCallbacks recordSceneCallbacks = recordsMenu_vtable;

    scene_runScene(sceneNumbers, &recordSceneCallbacks);
    return 0;
}

void sub_20559EC(const void *entryName, s32 entryIndex, s32 keepMask) {
    u8 keptBits;

    keptBits = gStruct217AA00->field43D & keepMask;
    MI_CpuCopy8(entryName, &gStruct217AA00->field45C[entryIndex], 0x14);
    gStruct217AA00->field43D = keptBits | (1 << entryIndex);
}

s32 sub_2055808(s32 a) {
    BOOL result;

    result = FALSE;
    if (gStruct217AA00->mRequestPending != 0) {
        return result;
    }
    if (func_02055808_inline4()) {
        return 3;
    }
    switch (gStruct217AA00->fieldC) {
        case 0:
        case 21:
            gStruct217AA00->field454 &= ~0x40;
            gStruct217AA00->field4 = 1;
            Initialize();
            break;
        case 1:
            StartRomArchiveTransfer();
            break;
        case 2:
        case 36:
            if (a != 0) {
                SetLifeTime(0x14);
            } else {
                result = TRUE;
                gStruct217AA00->field4 = 3;
                StartScan(1, NULL, NULL);
            }
            break;
        case 3:
            MeasureChannel(0);
            break;
        case 4:
            sub_204F814();
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
            gStruct217AA00->field4 = 2;
            gStruct217AA00->field44.field3E = 0;
            result = TRUE;
            gStruct217AA00->field8B &= ~8;
            break;
        default:
            sub_20533A0();
            break;
    }
    return result;
}

s32 func_0205579c(s32 a, s32 b) {
    if (a != 0) {
        if (b != 0) {
            return func_0204e1a8(a);
        }
        return sub_2055808(a);
    }
    if (((Unk027ffc40 *) 0x027ffc40)->field0 == 2) {
        return func_0204e1a8(a);
    }
    return sub_2055808(a);
}

s32 func_02055730(u16 a) {
    if (gStruct217AA00->field436 & 1) {
        gStruct217AA00->field436 &= ~1;
    }
    if (((Unk027ffc40 *) 0x027ffc40)->field0 == 2 || func_0204fe90(a) != 0) {
        return func_0204dd24(a);
    }
    return func_02055564(a);
}
