#include "Main/Unknown/code_020307b8.h"
#include "Main/Unknown/code_020302a0.h"
#include "Main/Unknown/code_0202f688.h"
#include "Main/Unknown/code_02030a10.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_0212775c.h"
#include "code_02148950.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02163000.h"
#include "Main/Unknown/unk_02174000.h"
#include "code_02016468.h"
#include "code_0214d018.h"

#pragma optimize_for_size on

#pragma thumb on

void SetMultiSelectNSCellTableOffsetY(void) {
    MultiSelectNS *multiSelectNS;
    s32 i;
    s32 entryCount;

    multiSelectNS = gMultiSelectNS;
    entryCount = func_02030a18(multiSelectNS->mBncl) + func_02030a10(multiSelectNS->mBnll);
    for (i = 0; i < entryCount; i++) {
        multiSelectNS->mCellTable[i].mOffsetY = gMultiSelectNS->mOffset;
    }
}

void RefreshMultiSelectNS(s32 showSelected) {
    u32 valueTable[2];
    s32 i;
    MultiSelectNS *multiSelectNS;
    s32 rowSelected;
    s32 rowNotSelected;
    BOOL z1;
    BOOL z2;
    u16 *rowCellIndices;
    u32 firstValue;
    u32 secondValue;

    multiSelectNS = gMultiSelectNS;
    firstValue = *(volatile u32 *) &gMultiSelectNSLabelValues[0];
    secondValue = *(volatile u32 *) &gMultiSelectNSLabelValues[1];
    valueTable[0] = firstValue;
    valueTable[1] = secondValue;
    z1 = FALSE;
    z2 = FALSE;
    for (i = 0; i < 2; i++) {
        if (gMultiSelectNS->mIndex == i && showSelected != 0) {
            rowSelected = 1;
        } else {
            rowSelected = z1;
        }
        rowCellIndices = gMultiSelectNSRowCellIndices[i];
        multiSelectNS->mCellTable[rowCellIndices[0]].mVisible = rowSelected;
        if (rowSelected == 0) {
            rowNotSelected = 1;
        } else {
            rowNotSelected = z2;
        }
        multiSelectNS->mCellTable[rowCellIndices[1]].mVisible = rowNotSelected;
        jn_ui_setLabelColorParam(rowCellIndices[2], valueTable[rowSelected], multiSelectNS->mBnll,
                             multiSelectNS->mCellTable, multiSelectNS->mBncl);
    }
}

#pragma thumb off

void func_02030930(void *destination, u32 value, u32 size) {
    volatile u32 valueCopy = value;
    MIi_CpuClearFast(valueCopy, destination, size);
}

void func_0203091c(void *destination, u32 size) {
    func_02030930(destination, 0, size);
}

#pragma thumb on

void InitMultiSelectNS(void *parentHeap, void *scene, void *oamList) {
    void *heap;
    MultiSelectNS *multiSelectNS;
    Unk02153d2c *labelMessageRow;
    s32 i;
    u32 subObjSizeLeft;
    s32 labelIndex;

    heap = heap_createSubFrmHeap(parentHeap);
    gMultiSelectNS = heap_alloc(heap, 0x40);
    func_0203091c(gMultiSelectNS, 0x40);
    gMultiSelectNS->mHeap = heap;
    gMultiSelectNS->field1C = scene;
    gMultiSelectNS->mOamList = oamList;
    gMultiSelectNS->mBannerMessages = arc_getSceneArcFile(aBanner_bmg_1);
    gMultiSelectNS->mOffset = -0xc0;
    subObjSizeLeft = GX_GetSizeOfSubOBJ();
    multiSelectNS = gMultiSelectNS;
    g2du_getCharacterData(&multiSelectNS->mNcgr, arc_getSceneArcFile(aMulti_select_ns_s_nce_ncgr));
    g2du_getCellBankData(&multiSelectNS->mNcer, arc_getSceneArcFile(aMulti_select_ns_s_nce_ncer));
    g2du_getPaletteData(&multiSelectNS->mNclr, arc_getSceneArcFile(aMulti_select_ns_s_o_nclr));
    multiSelectNS->mBncl = arc_getSceneArcFile(aMulti_select_ns_s_bncl);
    multiSelectNS->mBnbl = arc_getSceneArcFile(aMulti_select_ns_s_bnbl);
    multiSelectNS->mBnll = arc_getSceneArcFile(aMulti_select_ns_s_bnll);
    jn_ui_initLayout(gMultiSelectNS->mHeap, multiSelectNS->mBncl, multiSelectNS->mBnll, &multiSelectNS->mCellTable);
    for (i = 0; i < 2; i++) {
        labelMessageRow = &gMultiSelectNSLabelMessageRows[i];
        labelIndex = labelMessageRow->field0;
        subObjSizeLeft -=
            jn_ui_initLabel(gMultiSelectNS->mHeap, labelIndex, multiSelectNS->mBnll, labelMessageRow->field2,
                            labelMessageRow->field4, labelMessageRow->field6, multiSelectNS->mNcer,
                            multiSelectNS->mBncl, multiSelectNS->mCellTable, subObjSizeLeft);
        jn_ui_212426C(1, labelIndex, multiSelectNS->mBnll,
                      jn_msg_getMessage(gMultiSelectNS->mBannerMessages, labelMessageRow->field8), multiSelectNS->mBncl,
                      multiSelectNS->mCellTable);
    }
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, multiSelectNS->mNcgr->mData, multiSelectNS->mNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, multiSelectNS->mNclr->mData, multiSelectNS->mNclr->mDataSize);
    RefreshMultiSelectNS(1);
    gmenu_setSeqArcIndex(0xe);
    LEDBlink_Wireless();
    heap_adjustSubFrmHeap(gMultiSelectNS->mHeap);
}

#pragma thumb off
