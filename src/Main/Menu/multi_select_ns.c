#include "Main/Menu/multi_select_ns.h"
#include "Main/Menu/multi_select_ns_registers.h"
#include "Main/Menu/multi_select_member_group.h"
#include "Main/Menu/multi_select_ns_layout_count.h"
#include "Main/Menu/multi_select_ns_input.h"
#include "Main/System/heap.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Net/led_pattern.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Menu/select_return.h"
#include "vram_bank_display_setup.h"
#include "Main/Menu/menu_label_cell_rows.h"
#include "font_glyph_layout.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Menu/label_palette_indices.h"
#include "Main/Menu/select_kart_ghost_work.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "Main/Graphics/font_and_player_character.h"
#include "touch_panel_sampling.h"
#include "Main/Save/buddy_record_time.h"
#include "cell_transfer_state.h"
#include "vram_transfer_queue.h"
#include "cpu_copy_fill.h"

const u16 gMultiSelectNSRowCellIndices[2][3] = {{4, 2, 0}, {5, 3, 1}};
const MultiSelectNSLabelMessageRow gMultiSelectNSLabelMessageRows[2] = {{0, 0xdc, 0x25, 4, 3}, {1, 0xdc, 0x25, 5, 4}};
u32 gMultiSelectNSLabelValues[2] = {1, 0};
struct WLMenuCallbacks gMultiSelectNSCallbacks = {InitMultiSelectNS, AdvanceMultiSelectNS, ReleaseMultiSelectNS,
                                                  WriteMultiSelectNSRegisters};
struct MultiSelectNS *gMultiSelectNS;

#pragma optimize_for_size on

#pragma thumb on

void SetMultiSelectNSCellTableOffsetY(void) {
    MultiSelectNS *multiSelectNS;
    s32 cellIndex;
    s32 entryCount;

    multiSelectNS = gMultiSelectNS;
    entryCount =
        MultiSelectNSGetCellLayoutCount(multiSelectNS->mBncl) + MultiSelectNSGetLabelLayoutCount(multiSelectNS->mBnll);
    for (cellIndex = 0; cellIndex < entryCount; cellIndex++) {
        multiSelectNS->mCellTable[cellIndex].mOffsetY = gMultiSelectNS->mOffset;
    }
}

void RefreshMultiSelectNS(s32 showSelected) {
    u32 valueTable[2];
    s32 rowIndex;
    MultiSelectNS *multiSelectNS;
    s32 rowSelected;
    s32 rowNotSelected;
    BOOL rowSelectedDefault;
    BOOL rowNotSelectedDefault;
    const u16 *rowCellIndices;
    u32 firstValue;
    u32 secondValue;

    multiSelectNS = gMultiSelectNS;
    firstValue = *(volatile u32 *) &gMultiSelectNSLabelValues[0];
    secondValue = *(volatile u32 *) &gMultiSelectNSLabelValues[1];
    valueTable[0] = firstValue;
    valueTable[1] = secondValue;
    rowSelectedDefault = FALSE;
    rowNotSelectedDefault = FALSE;
    for (rowIndex = 0; rowIndex < 2; rowIndex++) {
        if (gMultiSelectNS->mIndex == rowIndex && showSelected != 0) {
            rowSelected = 1;
        } else {
            rowSelected = rowSelectedDefault;
        }
        rowCellIndices = gMultiSelectNSRowCellIndices[rowIndex];
        multiSelectNS->mCellTable[rowCellIndices[0]].mVisible = rowSelected;
        if (rowSelected == 0) {
            rowNotSelected = 1;
        } else {
            rowNotSelected = rowNotSelectedDefault;
        }
        multiSelectNS->mCellTable[rowCellIndices[1]].mVisible = rowNotSelected;
        SetLabelPaletteIndex(rowCellIndices[2], valueTable[rowSelected], multiSelectNS->mBnll,
                             multiSelectNS->mCellTable, multiSelectNS->mBncl);
    }
}

#pragma thumb off

void MultiSelectNSMI_CpuFillFast(void *destination, u32 value, u32 size) {
    volatile u32 valueCopy = value;
    MIi_CpuClearFast(valueCopy, destination, size);
}

void MultiSelectNSMI_CpuClearFast(void *destination, u32 size) {
    MultiSelectNSMI_CpuFillFast(destination, 0, size);
}

#pragma thumb on

void InitMultiSelectNS(void *parentHeap, void *scene, void *oamList) {
    void *heap;
    MultiSelectNS *multiSelectNS;
    const MultiSelectNSLabelMessageRow *labelMessageRow;
    s32 labelRowIndex;
    u32 subObjSizeLeft;
    s32 labelIndex;

    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gMultiSelectNS = HeapAlloc(heap, sizeof(*gMultiSelectNS));
    MultiSelectNSMI_CpuClearFast(gMultiSelectNS, 0x40);
    gMultiSelectNS->mHeap = heap;
    gMultiSelectNS->mScene = scene;
    gMultiSelectNS->mOamList = oamList;
    gMultiSelectNS->mBannerMessages = FindSceneFile("banner.bmg");
    gMultiSelectNS->mOffset = -0xc0;
    subObjSizeLeft = GX_GetSizeOfSubOBJ();
    multiSelectNS = gMultiSelectNS;
    LocateNcgr2(&multiSelectNS->mNcgr, FindSceneFile("multi_select_NS_s.nce.ncgr"));
    LocateNcer(&multiSelectNS->mNcer, FindSceneFile("multi_select_NS_s.nce.ncer"));
    LocateNclr(&multiSelectNS->mNclr, FindSceneFile("multi_select_NS_s_o.NCLR"));
    multiSelectNS->mBncl = FindSceneFile("multi_select_NS_s.bncl");
    multiSelectNS->mBnbl = FindSceneFile("multi_select_NS_s.bnbl");
    multiSelectNS->mBnll = FindSceneFile("multi_select_NS_s.bnll");
    InitLayoutTable(gMultiSelectNS->mHeap, multiSelectNS->mBncl, multiSelectNS->mBnll, &multiSelectNS->mCellTable);
    for (labelRowIndex = 0; labelRowIndex < 2; labelRowIndex++) {
        labelMessageRow = &gMultiSelectNSLabelMessageRows[labelRowIndex];
        labelIndex = labelMessageRow->mLabelIndex;
        subObjSizeLeft -=
            InitLabelCanvas(gMultiSelectNS->mHeap, labelIndex, multiSelectNS->mBnll, labelMessageRow->mWidth,
                            labelMessageRow->mHeight, labelMessageRow->mEntryIndex, multiSelectNS->mNcer,
                            multiSelectNS->mBncl, multiSelectNS->mCellTable, subObjSizeLeft);
        PrintLabelLayoutTextNoFixedAdvance(1, labelIndex, multiSelectNS->mBnll,
                                           GetBmgEntry(gMultiSelectNS->mBannerMessages, labelMessageRow->mMessageIndex),
                                           multiSelectNS->mBncl, multiSelectNS->mCellTable);
    }
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_SPRITE_TILES, 0, multiSelectNS->mNcgr->mData,
                                       multiSelectNS->mNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_SPRITE_PALETTE, 0, multiSelectNS->mNclr->mData,
                                       multiSelectNS->mNclr->mDataSize);
    RefreshMultiSelectNS(1);
    SetSelectReturnSoundId(0xe);
    SendLedPatternWireless();
    FrmHeapShrinkInParent(gMultiSelectNS->mHeap);
}

#pragma thumb off
