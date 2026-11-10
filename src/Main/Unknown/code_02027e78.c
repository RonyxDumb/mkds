#include "Main/Unknown/code_02027e78.h"

#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/unk_02174000.h"
#include "registers.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_021281fc.h"
#include "Main/Unknown/code_0212b1a8.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_02028000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_0211f498.h"
#include "Main/Unknown/code_02128000.h"
#include "Main/Unknown/code_0212b000.h"
#include "code_0214a390.h"
#include "Main/Unknown/code_0202b604.h"
#include "Main/Unknown/code_0211d4a8.h"

u32 SelectKartGetConnectionKind(void) {
    return (data_021759d0->mConnectionKind);
}

u16 *SelectKartMB_GetMultiBootParam(void) {
    return &gBootInfo->mUnk_00;
}

u32 SelectKartMB_IsMultiBootChild(void) {
    if (*SelectKartMB_GetMultiBootParam() == 2) {
        return 1;
    }
    return 0;
}

u32 SelectKartMB_IsMultiBootChildWrapper(void) {
    return SelectKartMB_IsMultiBootChild();
}

#pragma thumb on

void ReleaseSelectKart(void) {
    int result;
    if ((gSelectKart->mResult == 1) && (result = SelectKartGetConnectionKind(), result == 2)) {
        ClearSelectReturnDisplayBitOn();
    }
    result = SelectKartMB_IsMultiBootChildWrapper();
    if (result == 0) {
        ClearPaletteBlendPointer();
    } else {
        ClearSelectRaceRuleWaitPointer();
    }
    HeapDestroy(gSelectKart->mHeap);
    *&gSelectKart = NULL;
}

#pragma thumb off

u32 SelectKartGX_SetVisiblePlane(u32 bits) {
    u32 value = (reg_GX_DISPCNT & ~0x1f00) | (bits << 8);
    reg_GX_DISPCNT = value;
    return value;
}

u32 SelectKartGXS_SetVisiblePlane(u32 bits) {
    u32 value = (reg_GXS_DB_DISPCNT & ~0x1f00) | (bits << 8);
    reg_GXS_DB_DISPCNT = value;
    return value;
}

void SelectKartG2S_SetBG3Offset(u32 offsetX, u32 offsetY) {
    reg_G2S_DB_BG3OFS = (offsetX & 0x1ff) | ((offsetY << 16) & 0x1ff0000);
}

void WriteSubBg3CntBits(u32 bits) {
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | bits;
}

void WriteSubBlendAlpha(u32 firstPlane, u32 secondPlane, u32 firstCoefficient, u32 secondCoefficient) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, firstPlane, secondPlane, firstCoefficient, secondCoefficient);
}

u32 WriteSubWinEnableBits(u32 bits) {
    u32 value = (reg_GXS_DB_DISPCNT & ~0xe000) | (bits << 13);
    reg_GXS_DB_DISPCNT = value;
    return value;
}

void SelectKartG2S_SetWnd0InsidePlane(u32 lowBits, u32 extraBitFlag) {
    u32 value = (reg_G2S_DB_WININ & ~0x3f) | lowBits;
    if (extraBitFlag != 0) {
        value |= 0x20;
    }
    reg_G2S_DB_WININ = value;
}

void SelectKartG2S_SetWndOutsidePlane(u32 lowBits, u32 extraBitFlag) {
    u32 value = (reg_G2S_DB_WINOUT & ~0x3f) | lowBits;
    if (extraBitFlag != 0) {
        value |= 0x20;
    }
    reg_G2S_DB_WINOUT = value;
}

void SelectKartG2S_SetWnd0Position(u32 startX, u32 startY, u32 endX, u32 endY) {
    reg_G2S_DB_WIN0H = ((startX << 8) & 0xff00) | (endX & 0xff);
    reg_G2S_DB_WIN0V = ((startY << 8) & 0xff00) | (endY & 0xff);
}

#pragma thumb on

void WriteSelectKartRegisters(void) {
    u32 displayBits = 0x16;
    s32 interpolatedValue = GetInterpolatedValue(&gSelectKart->mInterpolations[4]);
    if (gSelectKart->mState != 8) {
        displayBits |= 8;
    }
    SelectKartGX_SetVisiblePlane(0x19);
    SelectKartGXS_SetVisiblePlane(displayBits);
    SelectKartG2S_SetBG3Offset(0, -interpolatedValue);
    WriteSubBg3CntBits(2);
    WriteSubBlendAlpha(0, 0x3f, 6, 10);
    if (interpolatedValue != 0 && gSelectKart->mState != 8) {
        WriteSubWinEnableBits(1);
        SelectKartG2S_SetWnd0InsidePlane(0x1f, 1);
        SelectKartG2S_SetWndOutsidePlane(7, 1);
        SelectKartG2S_SetWnd0Position(0, 0, 0xff, interpolatedValue + 0xc0);
    } else {
        WriteSubWinEnableBits(0);
    }
    if (gSelectKart->mEntryListUsed != FALSE) {
        WritePlayerEntryListRegisters();
    }
}
