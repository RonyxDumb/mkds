#include "Main/Menu/wl_menu_mb_child_message.h"
#include "Main/Unknown/code_02036438.h"
#include "Main/Menu/wl_menu_message.h"
#include "Main/Graphics/sub_bg1_cnt.h"
#include "Main/System/heap.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Net/multiboot_child_files.h"
#include "Main/Net/search_icon_mb_child_and.h"
#include "Main/Unknown/unk_02174000.h"
#include "code_0214b824.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Sound/seq_zero_loop_wrapper.h"
#include "Main/System/key_recording_buffer.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0200eddc.h"
#include "g2d_CharCanvas.h"
#include "gx_bgcnt.h"
#include "code_0214d018.h"

#pragma thumb on

void InitWLMenuMessage(void *heap) {
    void *frameHeap;
    int object;
    Ncgr *chars;
    Nclr *palette;
    frameHeap = CreateFrmHeapFromMaxFree(heap);
    object = ((u32) HeapAlloc(frameHeap, (0x00000654u)));
    *(s32 *) &gWLMenuMessage = object;
    WLMenuMessageMI_CpuClearFast((void *) object, (0x00000654u));
    gWLMenuMessage->mHeap = frameHeap;
    SetSubBg1Cnt(0, 0, 0x10, 0, 0);
    chars = GetDownloadScreenFiles()->mMultiDownloadChars;
    palette = GetDownloadScreenFiles()->mMultiDownloadPalette;
    GXS_LoadBG1Char(chars->mData, 0, chars->mDataSize);
    GXS_LoadBG3Char(chars->mData, 0, chars->mDataSize);
    GXS_LoadBGPltt(palette->mData, 0, palette->mDataSize);
}

#pragma thumb off

#pragma optimize_for_size on

#pragma thumb on

void SetupWLMenuMBChildMessage(void *heap) {
    void *text;
    u32 charBase;
    s32 column;
    s32 row;
    u16 entry;

    InitWLMenuMessage(heap);
    gWLMenuMessage->mState = 0;
    SetMultiSimple(1);
    gWLMenuMessage->mMBChildMessages = GetDownloadScreenFiles()->mUnk_20;
    gWLMenuMessage->mFont = (u8 *) GetDownloadScreenFiles() + 0x14;
    charBase = G2S_GetBG1CharPtr();
    text = GetBmgEntry(gWLMenuMessage->mMBChildMessages, 1);
    NNS_G2dCharCanvasInitForBG(gWLMenuMessage->mCharCanvas, (u8 *) charBase + 0x400, 0x20, 4, 4);
    WLMenuInitTextCanvas(&gWLMenuMessage->mTextCanvas, gWLMenuMessage->mCharCanvas, gWLMenuMessage->mFont, 1, 4);
    WLMenuDrawTextOnCanvas(&gWLMenuMessage->mTextCanvas, 0x80, 0, 3, 0x211, text);
    for (row = 7; row < 9; row++) {
        for (column = 0; column < 0x20; column++) {
            entry = (((column + row + 1) & 1) << 12) | 1;
            gWLMenuMessage->mScreenMap[column + row * 0x20] = entry;
            gWLMenuMessage->mScreenMap[column + (row + 7) * 0x20] = entry;
        }
    }
    DC_StoreRange(gWLMenuMessage->mScreenMap, 0x600);
    GXS_LoadBG3Scr(gWLMenuMessage->mScreenMap, 0, 0x600);
    WLMenuMessageMI_CpuClearFast(gWLMenuMessage->mScreenMap, 0x600);
    for (row = 10; row < 14; row++) {
        for (column = 0; column < 0x20; column++) {
            gWLMenuMessage->mScreenMap[column + row * 0x20] = column + (row - 10) * 0x20 + 0x20;
        }
    }
    DC_StoreRange(gWLMenuMessage->mScreenMap, 0x600);
    GXS_LoadBG1Scr(gWLMenuMessage->mScreenMap, 0, 0x600);
    StartSeqZeroLoopWrapper();
    FrmHeapShrinkInParent(gWLMenuMessage->mHeap);
}

#pragma thumb off

void WLMenuInitTextCanvas(TextCanvas *textCanvas, void *charCanvas, void *font, s32 charSpacing, s32 lineSpacing) {
    textCanvas->mCharCanvas = charCanvas;
    textCanvas->mFont = font;
    textCanvas->mCharSpacing = charSpacing;
    textCanvas->mLineSpacing = lineSpacing;
}

u32 WLMenuDrawTextOnCanvas(TextCanvas *textCanvas, s32 textX, s32 textY, u32 color, u32 flags, void *text) {
    return NNSi_G2dTextCanvasDrawText(textCanvas, textX, textY, color, flags, text);
}

void WLMenuMessageMI_CpuFillFast(void *dest, u32 fillValue, u32 size) {
    volatile u32 fillData = fillValue;
    MIi_CpuClearFast(fillData, dest, size);
}

void WLMenuMessageMI_CpuClearFast(void *dest, u32 size) {
    WLMenuMessageMI_CpuFillFast(dest, 0, size);
}
