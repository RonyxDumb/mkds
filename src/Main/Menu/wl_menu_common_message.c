#include "Main/Menu/wl_menu_common_message.h"
#include "Main/Menu/wl_menu_message.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Sound/seq_zero_loop_wrapper.h"
#include "Main/Menu/wl_menu_mb_child_message.h"
#include "Main/Unknown/code_02036438.h"
#include "Main/System/heap.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Graphics/font_and_player_character.h"
#include "code_0200eddc.h"
#include "g2d_CharCanvas.h"
#include "gx_bgcnt.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214b824.h"

#pragma optimize_for_size on

#pragma thumb on

void SetupWLMenuCommonMessage(void *heap) {
    void *text;
    u32 charBase;
    s32 column;
    s32 row;
    u16 entry;

    InitWLMenuMessage(heap);
    gWLMenuMessage->mState = 9;
    gWLMenuMessage->mCommonMessages = FindFileInLoadedArchives(data_021646e0);
    gWLMenuMessage->mFont = GetFontByIndex(0);
    charBase = G2S_GetBG1CharPtr();
    text = GetBmgEntry(gWLMenuMessage->mCommonMessages, 0x79);
    NNS_G2dCharCanvasInitForBG(gWLMenuMessage->mCharCanvas, (u8 *) charBase + 0x400, 0x20, 4, 4);
    WLMenuInitTextCanvas(&gWLMenuMessage->mTextCanvas, gWLMenuMessage->mCharCanvas, gWLMenuMessage->mFont, 1, 4);
    WLMenuDrawTextOnCanvas(&gWLMenuMessage->mTextCanvas, 8, 0, 3, 0x209, text);
    for (row = 0x16; row < 0x18; row++) {
        for (column = 0; column < 0x20; column++) {
            entry = (((column + row + 1) & 1) << 12) | 1;
            gWLMenuMessage->mScreenMap[column + row * 0x20] = entry;
        }
    }
    DC_StoreRange(gWLMenuMessage->mScreenMap, 0x600);
    GXS_LoadBG3Scr(gWLMenuMessage->mScreenMap, 0, 0x600);
    WLMenuMessageMI_CpuClearFast(gWLMenuMessage->mScreenMap, 0x600);
    for (row = 0x14; row < 0x16; row++) {
        for (column = 0; column < 0x20; column++) {
            gWLMenuMessage->mScreenMap[column + row * 0x20] = column + (row - 0x14) * 0x20 + 0x20;
        }
    }
    DC_StoreRange(gWLMenuMessage->mScreenMap, 0x600);
    GXS_LoadBG1Scr(gWLMenuMessage->mScreenMap, 0, 0x600);
    if (HasGroupSendMask() != 0) {
        StartSeqZeroLoopWrapper();
    }
    FrmHeapShrinkInParent(gWLMenuMessage->mHeap);
}

#pragma thumb off

u32 WLMenuIsMultiBootSetupStarted(void) {
    return (gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0;
}
