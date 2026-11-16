#include "Main/Unknown/code_0212a910.h"
#include "registers.h"

#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_0212030c.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_020d1630.h"
#include "Main/Unknown/code_020d1640.h"
#include "Main/Unknown/code_02124094.h"
#include "code_02142eac.h"
#include "code_02016468.h"
#include "code_0214cfe4.h"
#include "code_0201ea30.h"
#include "Main/Unknown/code_0212abd0.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0212b09c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020b19a0.h"
#include "Main/Unknown/code_021205f4.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_02024000.h"
#include "code_0200eddc.h"
#include "g2d_CharCanvas.h"
#include "code_0214a390.h"
#include "code_0214b824.h"
#include "code_0214d018.h"
#include "Main/Unknown/unk_0216e000.h"
#include "Main/Unknown/code_0212b0b8.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02023000.h"
#include "gx.h"

#pragma thumb on
void err_init(void *heap) {
    MessageScreen *messageScreen;
    TextCanvas *textCanvas;
    messageScreen = heap_alloc(heap, 0x1a44);
    gMessageScreen = messageScreen;
    NNS_G2dCharCanvasInitForBG(messageScreen->mCharCanvas, messageScreen->mCharBuffer, 0x20, 5, 4);
    messageScreen = gMessageScreen;
    textCanvas = &messageScreen->mTextCanvas;
    messageScreen->mTextCanvas.mCharCanvas = messageScreen->mCharCanvas;
    textCanvas->mFont = NULL;
    textCanvas->mCharSpacing = 1;
    textCanvas->mLineSpacing = 2;
    ResetMessageScreen();
}

void ResetMessageScreen(void) {
    gMessageScreen->mOpen = FALSE;
    gMessageScreen->mResult = -1;
}

s32 err_212B0B8(void) {
    MessageScreen *messageScreen;
    if (gMessageScreen->mOpen == FALSE) {
        return -1;
    }
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, 0);
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, 0);
    if ((u16) (data_021755dc.mPressedBits & PAD_KEY_A) != 0) {
        messageScreen = gMessageScreen;
        if (messageScreen->mInputEnabled != 0) {
            if ((u32) (messageScreen->mKind - 4) <= 1) {
                gStruct217B488->field58 = TRUE;
                gMessageScreen->mResult = 1;
            } else if (messageScreen->mKind == 6) {
                gStruct217B488->field1C = 1;
                gMessageScreen->mResult = 1;
                func_02120610();
            } else {
                messageScreen->mResult = 0;
            }
        }
    }
    return gMessageScreen->mResult;
}
#pragma thumb off

#pragma thumb on
void err_clearCharData(void) {
    u32 address;
    u32 fillValue;
    u32 size;
    u32 value3;
    address = (u32) &gMessageScreen;
    address = *(const u32 *) ((address) + 0u);
    address = (address) + 68u;
    fillValue = 0u;
    size = 0x1400u;
    MI_CpuFill8((void *) address, fillValue, size);
}
#pragma thumb off

#pragma thumb on

void *err_getCharData(void) {
    return gMessageScreen->mCharBuffer;
}

#pragma thumb off

#pragma thumb on
void err_clearScreenData(void) {
    volatile u16 zero;
    zero = 0;
    MIi_CpuClear16(zero, gMessageScreen->mScreenMap, 0x600);
}

void *err_getErrorMessageString(void) {
    void *messages;
    s32 kind;
    messages = NULL;
    if (*(vu16 *) 0x27ffc40 != 2) {
        messages = arc_get2dArcFile(aCommon_bmg_19);
    }
    kind = gMessageScreen->mKind;
    if (kind == 4) {
        return jn_msg_getMessage(messages, 0x86);
    }
    if (kind == 5) {
        return jn_msg_getMessage(messages, 0x87);
    }
    if (kind == 6) {
        return jn_msg_getMessage(messages, 0x88);
    }
    if (kind == 1) {
        return jn_msg_getMessage(messages, 0x83);
    }
    if (kind == 2) {
        return jn_msg_getMessage(messages, 0x84);
    }
    if (kind == 3) {
        return jn_msg_getMessage(messages, 0x85);
    }
    if (kind == 0) {
        if (*(vu16 *) 0x27ffc40 == 2) {
            return jn_msg_getMessage(s2d_getData()->field20, 0);
        }
        return jn_msg_getMessage(messages, 0x82);
    }
    return NULL;
}

void err_renderErrorMessage(void) {
    s32 i;
    err_clearCharData();
    if (*(vu16 *) 0x27ffc40 == 2) {
        gMessageScreen->mTextCanvas.mFont = &s2d_getData()->field14;
    } else {
        gMessageScreen->mTextCanvas.mFont = m2d_getFont(0);
    }
    NNSi_G2dTextCanvasDrawText(&gMessageScreen->mTextCanvas, 0x80, 0x14, 0xe, 0x412, gMessageScreen->mText);
    err_clearScreenData();
    for (i = 0; i < 0x300; i++) {
        if (i >= 0x120 && i < 0x1c0) {
            gMessageScreen->mScreenMap[i] = (i - 0x120) | 0xf000;
        } else {
            gMessageScreen->mScreenMap[i] = 0xf09f;
        }
    }
    *(vu16 *) 0x50001fc = 0xffff;
    *(vu16 *) 0x5000000 = 0;
    reg_G2_BG1OFS = 0;
    reg_G2_BG1CNT = reg_G2_BG1CNT & ~3;
    reg_G2_BG1CNT = reg_G2_BG1CNT & ~0x40;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & 0x43) | 0x400;
    DC_FlushRange(gMessageScreen->mCharBuffer, 0x1400);
    DC_FlushRange(gMessageScreen->mScreenMap, 0x600);
    GX_LoadBG1Char(gMessageScreen->mCharBuffer, 0, 0x1400);
    GX_LoadBG1Scr(gMessageScreen->mScreenMap, 0, 0x600);
}

void func_0212ae2c(void) {
    u16 a[11];
    a[0] = 0;
    MIi_CpuClear16(a[0], &a[1], 0x14);
    FormatAsciiNumber(func_021205f4(), &a[1]);
    FormatMessageWithText(&a[1], gMessageScreen->mText, gMessageScreen->mScreenMap, 0x600);
    gMessageScreen->mText = gMessageScreen->mScreenMap;
}

void OpenMessageScreen(s32 messageKind, s32 inputEnabled) {
    u32 bits8To12;
    if (gMessageScreen->mOpen == FALSE && messageKind != -1) {
        gMessageScreen->mOpen = TRUE;
        gMessageScreen->mInputEnabled = inputEnabled;
        gMessageScreen->mKind = messageKind;
        gMessageScreen->mText = err_getErrorMessageString();
        if (gMessageScreen->mKind == 4) {
            func_0212ae2c();
        }
        err_renderErrorMessage();
        if (scproc_getCurrentScene() == 2) {
            if (GetRaceHudStepHasRun() == 0) {
                reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x200;
                reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffffe0ff;
                *(vu16 *) 0x5000400 = 0;
                reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
            } else {
                bits8To12 = (reg_GX_DISPCNT & 0x1f00) >> 8;
                bits8To12 |= 2;
                reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | (bits8To12 << 8);
            }
            G2x_SetBlendBrightnessExt_(&reg_G2_BLDCNT, 0x1d, 0, 8, 8, -11);
        } else {
            reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x200;
            reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffffe0ff;
            *(vu16 *) 0x5000400 = 0;
            reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
            reg_G2_BLDCNT = 0;
            reg_G2S_DB_BLDCNT = 0;
        }
    }
}

void InitLinkLevelIcons(void *heap, void *oamList) {
    s32 i;
    LinkLevelIcons *linkLevelIcons;
    Unk0217d3fc_00_00 *oam;
    gLinkLevelIcons = heap_alloc(heap, 0x11c);
    gLinkLevelIcons->mOamList = oamList;
    MI_CpuFill8(gLinkLevelIcons->field3C, 0, 0x20);
    gLinkLevelIcons->mCycleFrames = 0;
    for (i = 0; i < 5; i++) {
        gLinkLevelIcons->mIconEnabled[i] = 0;
    }
    switch (scproc_getCurrentScene()) {
        case 1:
            if ((u32) (gSystemData->field20 - 1) <= 1) {
                gLinkLevelIcons->mIconEnabled[0] = 1;
            }
            break;
        case 6:
        case 13:
            gLinkLevelIcons->mIconEnabled[0] = 1;
            break;
        case 12:
            gLinkLevelIcons->mIconEnabled[4] = 1;
            break;
        case 10:
            if (gSystemData->field20 == 3) {
                gLinkLevelIcons->mIconEnabled[1] = 1;
                gLinkLevelIcons->mIconEnabled[4] = 1;
            } else if ((u32) (gSystemData->field20 - 1) <= 1) {
                gLinkLevelIcons->mIconEnabled[0] = 1;
            }
            break;
        case 8:
            if (gSystemData->field20 == 3) {
                gLinkLevelIcons->mIconEnabled[1] = 1;
                gLinkLevelIcons->mIconEnabled[4] = 1;
            }
            break;
    }
    for (i = 0; i < 2; i++) {
        gLinkLevelIcons->mIconKind[i] = -1;
    }
    SetupLinkLevelIcons();
    for (i = 0; i < 2; i++) {
        linkLevelIcons = gLinkLevelIcons;
        oam = &linkLevelIcons->mOamRecords[i];
        oam->field0 = ((linkLevelIcons->field28[i].field0 & 0x1ff) << 16) |
                       ((linkLevelIcons->field28[i].field4 & 0xff) | 0x40000000);
        oam->field4 = (0x400 - (i + 1) * 4) | 0xd000;
    }
}
#pragma thumb off

#pragma thumb on
void ClearLinkLevelIconsPointer(void) {
    u32 address;
    u32 zero;
    zero = 0u;
    address = (u32) &gLinkLevelIcons;
    *(u32 *) ((address) + 0u) = zero;
}
#pragma thumb off

#pragma thumb on
void SetupLinkLevelIcons(void) {
    s32 i;
    Ncgr *chars;
    Unk02021dc8 *cells;
    Nclr *palette;
    void *a;
    Unk0201ea30 *cellLayout;
    Unk0217b4b0 *loadedFiles;
    CellLayoutEntry *cellEntry;
    s32 j;
    loadedFiles = s2d_getData();
    a = loadedFiles->field0;
    cellLayout = loadedFiles->field4;
    chars = loadedFiles->field8;
    cells = loadedFiles->fieldC;
    palette = loadedFiles->field10;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < data_0215d168[i]; j++) {
            gLinkLevelIcons->mIconChars[i][j] =
                (CharTile *) chars->mData + GetCellCharIndex(data_0215d170[i][j], cells, a);
        }
    }
    for (i = 0; i < 2; i++) {
        cellEntry = jn_ui_getBnclElement(cellLayout, data_0215d164[i]);
        gLinkLevelIcons->field28[i].field0 = jn_ui_calcOriginCoordX(cellEntry->field0_0, 0x10);
        gLinkLevelIcons->field28[i].field4 = jn_ui_calcOriginCoordY(cellEntry->field0_2, 0x10);
    }
    for (i = 0; i < 2; i++) {
        NNS_GfdRegisterNewVramTransferTask(0x13, (0x400 - (i + 1) * 4) << 5, gLinkLevelIcons->field3C, 0x80);
    }
    NNS_GfdRegisterNewVramTransferTask(0xe, 0x1a0, palette->mData + 0xd0, 0x20);
}

void UpdateLinkLevelIconTiles(void) {
    s32 slotCount;
    s32 i;
    s32 linkLevel;
    BOOL flag;
    slotCount = 0;
    for (i = 0; i < 2; i++) {
        gLinkLevelIcons->mIconKind[i] = -1;
        gLinkLevelIcons->mIconLevel[i] = 0;
    }
    if (gLinkLevelIcons->mIconEnabled[1] != 0) {
        gLinkLevelIcons->mIconKind[0] = 1;
        gLinkLevelIcons->mIconLevel[0] = func_021205e8();
        slotCount = 1;
    }
    if (gLinkLevelIcons->mIconEnabled[0] != 0) {
        gLinkLevelIcons->mIconKind[slotCount] = 0;
        linkLevel = 0;
        if (gStruct217AA00->field4 != 0) {
            linkLevel = WM_GetLinkLevel();
        }
        gLinkLevelIcons->mIconLevel[slotCount] = linkLevel;
    } else if (gLinkLevelIcons->mIconEnabled[4] != 0) {
        flag = FALSE;
        if (!gSaveData->mFirstBlock->mLocateFriendOff) {
            if (func_021213f4() != FALSE) {
                flag = TRUE;
            }
        }
        if (flag != FALSE) {
            gLinkLevelIcons->mIconKind[slotCount] = 4;
        }
    }
    for (i = 0; i < 2; i++) {
        if (gLinkLevelIcons->mIconKind[i] == -1) {
            NNS_GfdRegisterNewVramTransferTask(0x13, (0x400 - (i + 1) * 4) << 5, gLinkLevelIcons->field3C, 0x80);
        } else {
            NNS_GfdRegisterNewVramTransferTask(0x13, (0x400 - (i + 1) * 4) << 5,
                            gLinkLevelIcons->mIconChars[gLinkLevelIcons->mIconKind[i]][gLinkLevelIcons->mIconLevel[i]],
                            0x80);
        }
    }
}

void AdvanceLinkLevelIcons(void) {
    s32 i;
    u32 slotValue;
    gLinkLevelIcons->mCycleFrames++;
    if (gLinkLevelIcons->mCycleFrames > 0x78) {
        gLinkLevelIcons->mCycleFrames = 0;
    }
    UpdateLinkLevelIconTiles();
    for (i = 0; i < 2; i++) {
        slotValue = gLinkLevelIcons->mIconKind[i];
        if (gLinkLevelIcons->mCycleFrames < 0x69 || slotValue <= 1) {
            MIi_CpuCopy16(&gLinkLevelIcons->mOamRecords[i],
                          &((GXOamAttr *) gLinkLevelIcons->mOamList->field0)[gLinkLevelIcons->mOamList->mOamCount],
                          6);
            gLinkLevelIcons->mOamList->mOamCount++;
        }
    }
}
#pragma thumb off

#pragma thumb on
void SetLinkLevelIconEnabled(u32 index, u32 enabled) {
    u32 value0 = index;
    u32 storedValue = enabled;
    u32 address;
    address = (u32) &gLinkLevelIcons;
    address = *(const u32 *) ((address) + 0u);
    value0 = (value0 << 2);
    *(u32 *) ((address) + (value0)) = storedValue;
}
#pragma thumb off
