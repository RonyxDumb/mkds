#include "Main/Unknown/code_0202f688.h"
#include "Main/Unknown/code_020019b0.h" // SceneNumbersView
#include "Main/Unknown/code_020302a0.h"

#include "Main/Unknown/unk_02174000.h"
#include "registers.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_0202f14c.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02030000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_02054000.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_02055000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "code_02148950.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02163000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212d214.h"
#include "code_0212df7c.h"
#include "code_0213ecf8.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0203033c.h"

#pragma thumb on

s32 IsRectInMemberRow(s32 rectIndex, s32 memberRow) {
    s32 i;
    BOOL found;

    found = FALSE;
    for (i = 0; i < 3; i++) {
        if (rectIndex == gMemberRowRectIndices[memberRow][i]) {
            found = TRUE;
            break;
        }
    }
    return found;
}

s32 func_0203023c(void) {
    BOOL result;
    s32 selectedIndex;
    BOOL memberChecksPass;

    result = TRUE;
    selectedIndex = gMultiSelectMemberGroup->mSelectedIndex;
    if (selectedIndex != 4) {
        memberChecksPass = FALSE;
        if (gMultiSelectMemberGroup->field58[selectedIndex].field0 != 0 &&
            gMultiSelectMemberGroup->field58[selectedIndex].field8 < 7) {
            memberChecksPass = TRUE;
        }
        if (memberChecksPass == FALSE) {
            result = FALSE;
        }
    }
    return result;
}

void SetMemberGroupCellTableOffsetY(void) {
    s32 i;
    s32 entryCount;
    Unk02174e50_24 *cellFileSet;

    cellFileSet = &gMultiSelectMemberGroup->mGroupSParts;
    entryCount = *OFFSET_PTR(u16, cellFileSet->fieldC, 6) + *OFFSET_PTR(u16, cellFileSet->field14, 6);
    for (i = 0; i < entryCount; i++) {
        cellFileSet->field18[i].mOffsetY = gMultiSelectMemberGroup->mBg3Offset;
    }
}

void RefreshMultiSelectMemberGroup(s32 showSelected) {
    Unk02174e50_24 *cellFileSet;
    Unk021634a8 valueTable;
    s32 i;
    s32 j;
    s32 entryOffset;
    s32 rowSelected;
    s32 rowNotSelected;
    s32 x;
    BOOL y;
    BOOL z;
    MemberRowCellIndices *rowCellIndices;

    cellFileSet = &gMultiSelectMemberGroup->mGroupSParts;
    valueTable = data_021634a8;
    i = 0;
    entryOffset = 0;
    rowCellIndices = gMemberRowCellIndices;
    do {
        rowSelected = 0;
        if (gMultiSelectMemberGroup->mSelectedIndex == i && showSelected != 0) {
            rowSelected = 1;
        }
        x = *(s32 *) ((u8 *) gMultiSelectMemberGroup + entryOffset + 0x58);
        cellFileSet->field18[rowCellIndices->mCellIndices[0]].mVisible = rowSelected;
        if (rowSelected == 0) {
            rowNotSelected = 1;
        } else {
            rowNotSelected = 0;
        }
        cellFileSet->field18[rowCellIndices->mCellIndices[0x18 / 2]].mVisible = rowNotSelected;
        for (j = 1; j < 12; j++) {
            cellFileSet->field18[rowCellIndices->mCellIndices[j]].mVisible = rowSelected & x;
            cellFileSet->field18[(rowCellIndices->mCellIndices + 12)[j]].mVisible = rowNotSelected & x;
        }
        cellFileSet->field18[rowCellIndices->mCellIndices[1]].mVisible &=
            *(s32 *) ((u8 *) gMultiSelectMemberGroup + entryOffset + 0x5c);
        cellFileSet->field18[rowCellIndices->mCellIndices[13]].mVisible &=
            *(s32 *) ((u8 *) gMultiSelectMemberGroup + entryOffset + 0x5c);
        if (*(s32 *) ((u8 *) gMultiSelectMemberGroup + entryOffset + 0x5c) == 0) {
            y = TRUE;
        } else {
            y = FALSE;
        }
        cellFileSet->field18[rowCellIndices->mCellIndices[2]].mVisible &= y;
        if (*(s32 *) ((u8 *) gMultiSelectMemberGroup + entryOffset + 0x5c) == 0) {
            y = TRUE;
        } else {
            y = FALSE;
        }
        cellFileSet->field18[rowCellIndices->mCellIndices[14]].mVisible &= y;
        for (j = 0; j < 8; j++) {
            if (j == *(s32 *) (entryOffset + (s32) gMultiSelectMemberGroup + 0x60)) {
                z = TRUE;
            } else {
                z = FALSE;
            }
            cellFileSet->field18[(rowCellIndices->mCellIndices + 4)[j]].mVisible &= z;
            cellFileSet->field18[(rowCellIndices->mCellIndices + 16)[j]].mVisible &= z;
        }
        jn_ui_setLabelColorParam(rowCellIndices->mLabelIndex, valueTable.field0[rowSelected], cellFileSet->field14,
                             cellFileSet->field18, cellFileSet->fieldC);
        entryOffset += 0xc;
        rowCellIndices = OFFSET_PTR(MemberRowCellIndices, rowCellIndices, 0x32);
        i++;
    } while (i < 4);
    if (gMultiSelectMemberGroup->mSelectedIndex == i && showSelected != 0) {
        rowSelected = 1;
    } else {
        rowSelected = 0;
    }
    cellFileSet->field18[89].mVisible = rowSelected;
    if (rowSelected == 0) {
        rowNotSelected = 1;
    } else {
        rowNotSelected = 0;
    }
    cellFileSet->field18[88].mVisible = rowNotSelected;
    jn_ui_setLabelColorParam(4, valueTable.field0[rowSelected], cellFileSet->field14, cellFileSet->field18,
                         cellFileSet->fieldC);
}

#pragma thumb off

#pragma thumb on

// Fills with 0 through a halfword stack offset of its own.
static inline void func_0202f764_inline(void *p, s32 v1) {
    volatile u16 zero = 0;
    MIi_CpuClear16(zero, p, v1);
}

void func_0202fd2c(void) {
    s32 changed;
    Unk02174e50_24 *cellFileSet;
    s32 oldWord0;
    s32 oldWord8;
    s32 oldWord4;
    BOOL isNewEntry;
    s32 i;
    s32 j;
    Unk02174e4c_818_04 entry;

    cellFileSet = &gMultiSelectMemberGroup->mGroupSParts;
    changed = 0;
    switch (gMultiSelectMemberGroup->field50) {
        case 0:
            if (func_0205579c(0, 0) == 1) {
                gMultiSelectMemberGroup->field50 = 1;
            }
            return;
        case 1:
            if (gMultiSelectMemberGroup->field88 != FALSE) {
                if (gMultiSelectMemberGroup->mSelectedIndex < 4) {
                    for (i = 0; i < 4; i++) {
                        if (func_0204ff14(i, &func_0202f14c()->field4[i]) != 0) {
                            func_0202f14c()->field4[i].field14 = 0;
                        } else {
                            func_0202f764_inline(&func_0202f14c()->field4[i], 0x16);
                        }
                    }
                    if (func_0204ff14(gMultiSelectMemberGroup->mSelectedIndex, NULL) != 0) {
                        func_0202f14c()->field0 = gMultiSelectMemberGroup->mSelectedIndex;
                        gMultiSelectMemberGroup->mNextCallbacksIndex = 3;
                        gMultiSelectMemberGroup->field50 = 0xb;
                        return;
                    }
                    gMultiSelectMemberGroup->field58[gMultiSelectMemberGroup->mSelectedIndex].field0 = 0;
                    return;
                }
                gMultiSelectMemberGroup->mNextCallbacksIndex = 1;
                gMultiSelectMemberGroup->field50 = 5;
                return;
            }
            if (gMultiSelectMemberGroup->mState != 1) {
                return;
            }
            for (i = 0; i < 4; i++) {
                oldWord0 = gMultiSelectMemberGroup->field58[i].field0;
                oldWord8 = gMultiSelectMemberGroup->field58[i].field8;
                oldWord4 = gMultiSelectMemberGroup->field58[i].field4;
                func_0202f764_inline(&entry, 0x16);
                gMultiSelectMemberGroup->field58[i].field0 = func_0204ff14(i, &entry);
                if (gMultiSelectMemberGroup->field58[i].field0 != 0) {
                    entry.field14 = 0;
                    jn_ui_212426C(1, gMemberRowCellIndices[i].mLabelIndex, cellFileSet->field14, &entry,
                                  cellFileSet->fieldC, cellFileSet->field18);
                    gMultiSelectMemberGroup->field58[i].field8 = func_0204fe1c(i);
                    gMultiSelectMemberGroup->field58[i].field4 = func_0204fe90(i);
                } else {
                    jn_ui_212426C(1, gMemberRowCellIndices[i].mLabelIndex, cellFileSet->field14,
                                  jn_msg_getMessage(gMultiSelectMemberGroup->mBannerMessages, 8), cellFileSet->fieldC,
                                  cellFileSet->field18);
                    gMultiSelectMemberGroup->field58[i].field8 = 0;
                    gMultiSelectMemberGroup->field58[i].field4 = 0;
                }
                if (oldWord0 == 0 && gMultiSelectMemberGroup->field58[i].field0 != 0) {
                    isNewEntry = TRUE;
                    for (j = 0; j < 4; j++) {
                        if (wcsncmp(entry.field0, func_0202f14c()->field4[j].field0, 0xb) == 0) {
                            isNewEntry = FALSE;
                        }
                    }
                    if (isNewEntry != FALSE) {
                        NNS_SndArcSetCurrent(&SDATFile);
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 4);
                        NNS_SndArcSetCurrent(&gSdatFileSndArc);
                    }
                } else if (oldWord0 != 0 && gMultiSelectMemberGroup->field58[i].field0 == 0) {
                    NNS_SndArcSetCurrent(&SDATFile);
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
                    NNS_SndArcSetCurrent(&gSdatFileSndArc);
                }
                changed |= oldWord0 != gMultiSelectMemberGroup->field58[i].field0 ? 1 : 0;
                changed |= oldWord8 != gMultiSelectMemberGroup->field58[i].field8 ? 1 : 0;
                changed |= oldWord4 != gMultiSelectMemberGroup->field58[i].field4 ? 1 : 0;
            }
            if (changed != 0) {
                RefreshMultiSelectMemberGroup(1);
            }
            return;
        case 5:
        case 8:
            if (func_02054f58() == 1) {
                gMultiSelectMemberGroup->field50 = 0xb;
            }
            return;
    }
}

void InitMultiSelectMemberGroup(void *parentHeap, void *scene, void *oamList) {
    void *heap;
    u32 subObjSizeLeft;
    Unk02174e50_24 *cellFileSet;
    s32 i;
    LabelMessageRow *labelMessageRow;
    void *text;

    heap = heap_createSubFrmHeap(parentHeap);
    gMultiSelectMemberGroup = heap_alloc(heap, 0xa8);
    MemFillWordsByBlock_inline(gMultiSelectMemberGroup, 0xa8);
    gMultiSelectMemberGroup->mHeap = heap;
    gMultiSelectMemberGroup->field40 = scene;
    gMultiSelectMemberGroup->mOamList = oamList;
    gMultiSelectMemberGroup->mBannerMessages = arc_getSceneArcFile(aBanner_bmg_2);
    gMultiSelectMemberGroup->mState = 0;
    gMultiSelectMemberGroup->mBg3Offset = -0xc0;
    mutil2_initBgGraphics(1, gMultiSelectMemberGroup, aMulti_select_member_s_b_ncgr_0, aMulti_select_member_s_b_nclr_0,
                  aMulti_select_member_s_group_nscr, 3, arc_getSceneArcFile);
    subObjSizeLeft = GX_GetSizeOfSubOBJ();
    cellFileSet = &gMultiSelectMemberGroup->mGroupSParts;
    mutil2_loadLayout(cellFileSet, aMulti_select_member_group_s_nce_ncgr, aMulti_select_member_group_s_nce_ncer,
                      aMulti_select_member_group_s_o_nclr, aMulti_select_member_s_group_bncl,
                      aMulti_select_member_s_group_bnll, aMulti_select_member_s_group_bnbl, arc_getSceneArcFile);
    mutil2_initLayout(1, gMultiSelectMemberGroup->mHeap, cellFileSet);
    for (i = 0, labelMessageRow = gMemberGroupLabelMessageRows; i < 5; labelMessageRow++, i++) {
        subObjSizeLeft -=
            mutil2_initLabel(1, gMultiSelectMemberGroup->mHeap, cellFileSet, labelMessageRow, subObjSizeLeft);
        if (gMemberGroupLabelMessageRows[i].mMessageIndex < 0) {
            text = data_02163610;
        } else {
            text = jn_msg_getMessage(gMultiSelectMemberGroup->mBannerMessages, gMemberGroupLabelMessageRows[i].mMessageIndex);
        }
        jn_ui_212426C(1, gMemberGroupLabelMessageRows[i].mLabelIndex, cellFileSet->field14, text, cellFileSet->fieldC,
                      cellFileSet->field18);
    }
    RefreshMultiSelectMemberGroup(1);
    gmenu_setSeqArcIndex(0xf);
    gSystemData->field20 = 2;
    heap_adjustSubFrmHeap(gMultiSelectMemberGroup->mHeap);
}

s32 AdvanceMultiSelectMemberGroup(SceneNumbersView *sceneNumbers) {
    Unk02174e50_24 *cellFileSet;
    s32 result;
    u16 slotIndex;
    s32 i;
    s32 touchInReturnRect;
    s32 rectIndex;
    BOOL pairIsNew;
    BOOL pairRecentlyGone;
    u16 v;
    s32 pairX;
    s32 pairY;
    s32 selectionChanged;

    result = -1;
    slotIndex = input_getDirectInputUnitId();
    cellFileSet = &gMultiSelectMemberGroup->mGroupSParts;
    if (gMultiSelectMemberGroup->mEntriesCleared == FALSE) {
        gMultiSelectMemberGroup->mEntriesClearFrames++;
        if (gMultiSelectMemberGroup->mEntriesClearFrames > 0x78) {
            for (i = 0; i < 4; i++) {
                func_0202f764_inline(&func_0202f14c()->field4[i], 0x16);
            }
            gMultiSelectMemberGroup->mEntriesCleared = TRUE;
        }
    }
    if (gMultiSelectMemberGroup->mState != -1) {
        func_0202fd2c();
    }
    switch (gMultiSelectMemberGroup->mState) {
        case 0:
            if (mbright_isFadedIn() == 0) {
                break;
            }
            if (gMultiSelectMemberGroup->mBg3OffsetFrames == 0) {
                RequestSelectReturnState1();
                CreateMainMessageBoxBig(jn_msg_getMessage(gMultiSelectMemberGroup->mBannerMessages, 7), 0, 0, 1, 0, 0, 0);
            }
            gMultiSelectMemberGroup->mBg3OffsetFrames++;
            if (gMultiSelectMemberGroup->mBg3OffsetFrames < 10) {
                gMultiSelectMemberGroup->mBg3Offset =
                    mutil_interpolate(1, -0xc0, 0, gMultiSelectMemberGroup->mBg3OffsetFrames, 10);
            } else {
                gMultiSelectMemberGroup->mBg3OffsetFrames = 0;
                gMultiSelectMemberGroup->mBg3Offset = 0;
                gMultiSelectMemberGroup->mState = 1;
            }
            SetMemberGroupCellTableOffsetY();
            break;
        case 1:
            touchInReturnRect = 0;
            rectIndex = -1;
            pairIsNew = FALSE;
            pairRecentlyGone = FALSE;
            v = gInputUnits[slotIndex].mHasPair;
            if (v == 0 && gInputUnits[slotIndex].mNoPairCount < 5) {
                pairRecentlyGone = TRUE;
            }
            if (pairRecentlyGone == FALSE && gInputUnits[slotIndex].mPrevHasPair == 0 && v != 0) {
                pairIsNew = TRUE;
            }
            if (pairIsNew != FALSE) {
                pairX = gInputUnits[slotIndex].mPairX;
                pairY = gInputUnits[slotIndex].mPairY;
                touchInReturnRect = gmenu_checkSelectReturnTouch(pairX, pairY);
                rectIndex = jn_ui_checkTouch(cellFileSet->field10, pairX, pairY);
            }
            v = gInputUnits[slotIndex].mPressedBits;
            if ((u16) (v & PAD_KEY_A) != 0) {
                if (func_0203023c() != 0) {
                    gMultiSelectMemberGroup->field88 = TRUE;
                    gMultiSelectMemberGroup->mState = 2;
                    gMultiSelectMemberGroup->mState2Frames = 0;
                    RefreshMultiSelectMemberGroup(0);
                    if (gMultiSelectMemberGroup->mSelectedIndex == 4) {
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x4e);
                    } else {
                        if ((gStruct217AA00 == NULL ? 0 : gStruct217AA00->field0) == 2) {
                            gStruct217AA00->field436 |= 1;
                        }
                        NNS_SndArcSetCurrent(&SDATFile);
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 2);
                        NNS_SndArcSetCurrent(&gSdatFileSndArc);
                    }
                } else {
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x4f);
                }
            } else if ((u16) (v & PAD_KEY_B) != 0 || touchInReturnRect != 0) {
                if (sceneNumbers != NULL) {
                    sceneNumbers->mNextScene = 0;
                }
                gMultiSelectMemberGroup->mState = 3;
                RequestSelectReturnState3WithSound(1);
            } else if (mutil_checkKeys(slotIndex, PAD_KEY_UP) != 0) {
                gMultiSelectMemberGroup->mSelectedIndex--;
                if (gMultiSelectMemberGroup->mSelectedIndex < 0) {
                    gMultiSelectMemberGroup->mSelectedIndex = 4;
                }
                RefreshMultiSelectMemberGroup(1);
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
            } else if (mutil_checkKeys(slotIndex, PAD_KEY_DOWN) != 0) {
                gMultiSelectMemberGroup->mSelectedIndex++;
                if (gMultiSelectMemberGroup->mSelectedIndex > 4) {
                    gMultiSelectMemberGroup->mSelectedIndex = 0;
                }
                RefreshMultiSelectMemberGroup(1);
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
            } else if (rectIndex == 0xc) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x4e);
                RefreshMultiSelectMemberGroup(gMultiSelectMemberGroup->mSelectedIndex != 4 ? 1 : 0);
                gMultiSelectMemberGroup->mState2Frames = 0;
                gMultiSelectMemberGroup->mState = 2;
                gMultiSelectMemberGroup->mSelectedIndex = 4;
                gMultiSelectMemberGroup->field88 = TRUE;
            } else {
                for (i = 0; i < 4; i++) {
                    if (IsRectInMemberRow(rectIndex, i) != 0) {
                        selectionChanged = gMultiSelectMemberGroup->mSelectedIndex != i ? 1 : 0;
                        if (gMultiSelectMemberGroup->field58[i].field0 != 0 &&
                            gMultiSelectMemberGroup->field58[i].field8 < 7) {
                            NNS_SndArcSetCurrent(&SDATFile);
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 2);
                            NNS_SndArcSetCurrent(&gSdatFileSndArc);
                            gMultiSelectMemberGroup->mSelectedIndex = i;
                            RefreshMultiSelectMemberGroup(selectionChanged);
                            gMultiSelectMemberGroup->mState2Frames = 0;
                            gMultiSelectMemberGroup->mState = 2;
                            gMultiSelectMemberGroup->field88 = TRUE;
                        } else {
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x4f);
                        }
                    }
                }
            }
            break;
        case 2:
            gMultiSelectMemberGroup->mState2Frames++;
            if (gMultiSelectMemberGroup->mState2Frames >= 5) {
                gMultiSelectMemberGroup->mState2Frames = 0;
                RefreshMultiSelectMemberGroup(1);
                if (gMultiSelectMemberGroup->mSelectedIndex < 4 &&
                    gMultiSelectMemberGroup->field58[gMultiSelectMemberGroup->mSelectedIndex].field0 == 0) {
                    gMultiSelectMemberGroup->mState = 1;
                } else {
                    gMultiSelectMemberGroup->mState = 3;
                    RequestTxtSystemClose();
                }
            }
            break;
        case 3:
            gMultiSelectMemberGroup->mBg3OffsetFrames++;
            if (gMultiSelectMemberGroup->mBg3OffsetFrames < 10) {
                gMultiSelectMemberGroup->mBg3Offset =
                    mutil_interpolate(1, 0, -0xc0, gMultiSelectMemberGroup->mBg3OffsetFrames, 10);
            } else {
                gMultiSelectMemberGroup->mBg3OffsetFrames = 0;
                gMultiSelectMemberGroup->mBg3Offset = 0;
                gMultiSelectMemberGroup->mState = 4;
            }
            SetMemberGroupCellTableOffsetY();
            break;
        case 4:
            if (gMultiSelectMemberGroup->field50 == 0xb) {
                result = gMultiSelectMemberGroup->mNextCallbacksIndex;
            }
            break;
    }
    if (gMultiSelectMemberGroup->mState != 4) {
        jn_ui_renderElements(cellFileSet->fieldC, cellFileSet->field8, cellFileSet->field14,
                        gMultiSelectMemberGroup->mOamList, cellFileSet->field18);
    }
    return result;
}

#pragma thumb off

#pragma thumb on

void ReleaseMultiSelectMemberGroup(void) {
    heap_destroySubHeap(gMultiSelectMemberGroup->mHeap);
    *&gMultiSelectMemberGroup = NULL;
}

#pragma thumb off

#pragma thumb on

void WriteMultiSelectMemberGroupRegisters(void) {
    u32 displayBits = 0x16;
    s32 windowEndY;

    if (gMultiSelectMemberGroup->mState != 4) {
        displayBits |= 8;
    }
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | (displayBits << 8);
    reg_G2S_DB_BG3OFS = (-gMultiSelectMemberGroup->mBg3Offset << 16) & 0x1ff0000;
    if (gMultiSelectMemberGroup->mBg3Offset != 0) {
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffff1fff) | 0x2000;
        reg_G2S_DB_WININ = (u32) ((reg_G2S_DB_WININ & ~0x3f) | 0x1f) | 0x20;
        reg_G2S_DB_WINOUT = (u32) ((reg_G2S_DB_WINOUT & ~0x3f) | 7) | 0x20;
        windowEndY = gMultiSelectMemberGroup->mBg3Offset + 0xc0;
        reg_G2S_DB_WIN0H = 0xff;
        reg_G2S_DB_WIN0V = windowEndY & 0xff;
    } else {
        reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
    }
}

#pragma thumb off
