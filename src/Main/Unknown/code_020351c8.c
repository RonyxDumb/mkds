#include "Main/Unknown/code_020351c8.h"

#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02125ed0.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02126000.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Save/GhostList.h"
#include "Main/Unknown/code_0202dd9c.h"
#include "Main/Unknown/code_0202e4b0.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_0202db04.h"
#include "Main/Ui/ScrollList.h"
#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_0203434c.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/code_020566a8.h"
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
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_02125ee8.h"
#include "Main/Unknown/code_02125f2c.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_0212775c.h"
#include "code_02148950.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "00/code_02181f98.h"
#include "code_0212d214.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_02025d5c.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_02025f80.h"
#include "Main/Unknown/code_02025cd0.h"
#include "registers.h"

#pragma thumb on

void func_02035c50(s32 a, s32 b, s32 listIndex, s32 d) {
    CellFileSet *subCellFileSet;
    s32 i;
    s32 v;
    s32 e;
    u8 time[4];
    s16 timeText[12];

    subCellFileSet = &data_02174e68->mCellFileSets[1];
    if (a == 1) {
        listIndex += ghost_getMyGhostCount();
        jn_ui_212426C(1, b, subCellFileSet->mLabelLayout,
                      jn_msg_getMessage(data_02174e68->mGhostMessages, mutil2_getCourseNameGhostMsgId(GetListedGhostCourseId(listIndex))),
                      subCellFileSet->mCellLayout, subCellFileSet->mCellTable);
        GetListedGhostTime(listIndex, time);
        mutil2_timeToString(timeText, time[2], time[3], *(u16 *) time);
        jn_ui_2124224(1, b + 7, subCellFileSet->mLabelLayout, timeText, subCellFileSet->mCellLayout,
                      subCellFileSet->mCellTable, 7);
    } else if (a == 0) {
        for (i = 0; i < 7; i++) {
            e = i + 7;
            if (i == d) {
                v = 14;
            } else {
                v = 15;
            }
            jn_ui_setLabelColorParam(i, v, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                                 subCellFileSet->mCellLayout);
            jn_ui_setLabelColorParam(e, v, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                                 subCellFileSet->mCellLayout);
        }
    }
}

#pragma thumb off

#pragma thumb on

void func_02035c14(void) {
    void *message;
    message = jn_msg_getMessage(data_02174e68->mGhostMessages, 3);
    SetTxtSystemBgOffsetRequested(0xfffffff4, 0);
    CreateMainMessageBoxBig(message, 0, 0, 0, 0, 0, 0);
}

#pragma thumb off

#pragma thumb on

static inline s32 func_0203551c_inline(void) {
    BackupAccess *p = gSaveCore;
    if (p->mBackupEnabled != 0) {
        return p->mCommandRunning;
    }
    return 0;
}

static inline s32 func_0203551c_inline_2(void) {
    if (gSaveData->mBusy == 0) {
        return func_0203551c_inline();
    }
    return 1;
}

void SetupGhostNameSubTextTwoButtons(void) {
    void *formatText;
    void *firstButtonText;
    void *secondButtonText;
    u8 ghostName[0x14];
    u16 nameText[11];
    u16 formattedText[0x100];

    formatText = jn_msg_getMessage(data_02174e68->mGhostMessages, 0x12);
    firstButtonText = jn_msg_getMessage(data_02174e68->mCommonMessages, 0);
    secondButtonText = jn_msg_getMessage(data_02174e68->mCommonMessages, 1);
    GetListedGhostName(data_02174e68->mSelectedIndex + ghost_getMyGhostCount(), ghostName);
    MIi_CpuCopy16(ghostName, nameText, 0x14);
    nameText[10] = 0;
    FormatMessageWithText(nameText, formatText, formattedText, 0x100);
    SetTxtSystemSoundId(0, -1);
    CreateSubMessageBoxSubYesNo(formattedText, firstButtonText, secondButtonText, 1, 0, 1, 1, 0);
}

void func_02035b0c(void) {
    CellFileSet *mainCellFileSet;
    CellFileSet *subCellFileSet;
    s32 mainEntryCount;
    s32 subEntryCount;
    s32 i;
    s16 offset;

    mainCellFileSet = &data_02174e68->mCellFileSets[0];
    subCellFileSet = &data_02174e68->mCellFileSets[1];
    mainEntryCount = mainCellFileSet->mCellLayout->mUnk_06 + mainCellFileSet->mLabelLayout->mUnk_06;
    subEntryCount = subCellFileSet->mCellLayout->mUnk_06 + subCellFileSet->mLabelLayout->mUnk_06;
    offset = interp_interpolate(&data_02174e68->mUnk_90);
    for (i = 0; i < mainEntryCount; i++) {
        mainCellFileSet->mCellTable[i].mOffsetY = -offset;
    }
    for (i = 0; i < subEntryCount; i++) {
        subCellFileSet->mCellTable[i].mOffsetY = offset;
    }
}

void PrintSelectedGhostRecord(void) {
    s32 listIndex;
    u32 characterIndex;
    u32 kartIndex;
    u32 courseId;
    u32 time;
    u8 ghostName[0x14];
    u16 nameText[11];

    listIndex = ghost_getMyGhostCount() + data_02174e68->mSelectedIndex;
    GetListedGhostTime(listIndex, &time);
    GetListedGhostName(listIndex, ghostName);
    MIi_CpuCopy16(ghostName, nameText, 0x14);
    nameText[10] = 0;
    characterIndex = GetListedGhostCharacterIndex(listIndex);
    kartIndex = GetListedGhostKartIndex(listIndex);
    courseId = GetListedGhostCourseId(listIndex);
    PrintGhostRecordInfo((SelectCharacter *) &data_02174e68->mCellFileSets[0], data_0215404c, nameText, characterIndex,
                         kartIndex, courseId, (MinuteSecondMillisecondTime *) &time);
}

void func_020357dc(void *parentHeap, void *b, void *c) {
    void *heap;
    CellFileSet *cellFileSet;
    s32 i;
    u32 remainingObjSize;
    s32 j;
    s32 assignedCount;
    s32 cellCount;
    s32 cellIndex;
    s32 labelIndex;
    s32 secondLabelIndex;
    s16 *row;
    void *cellTable;
    u16 w[3];

    heap = heap_createSubFrmHeap(parentHeap);
    data_02174e68 = heap_alloc(heap, 0xa8);
    MemFillWordsByBlock_inline(data_02174e68, 0xa8);
    data_02174e68->mHeap = heap;
    data_02174e68->mUnk_24[0] = b;
    data_02174e68->mUnk_24[1] = c;
    data_02174e68->mCommonMessages = arc_get2dArcFile(aCommon_bmg_27);
    data_02174e68->mGhostMessages = arc_getSceneArcFile(aGhost_bmg_1);
    cellFileSet = &data_02174e68->mCellFileSets[0];
    remainingObjSize = GX_GetSizeOfOBJ();
    mutil2_loadLayout(cellFileSet, aTimeattack_ghost_get_m_nce_ncgr, aTimeattack_ghost_get_m_nce_ncer, aTimeattack_ghost_get_m_o_nclr, aTimeattack_ghost_get_m_bncl, aTimeattack_ghost_get_m_bnll, NULL,
                      arc_getSceneArcFile);
    mutil2_initLayout(0, data_02174e68->mHeap, cellFileSet);
    for (i = 0; i < cellFileSet->mLabelLayout->mUnk_06; i++) {
        remainingObjSize -= mutil2_initLabel(0, data_02174e68->mHeap, cellFileSet, data_0215404c[i], remainingObjSize);
    }
    mutil2_initBgGraphics(1, data_02174e68, aTimeattack_ghost_get_s_b_ncgr, aTimeattack_ghost_get_s_b_nclr, aTimeattack_ghost_get_s_nscr, 3, arc_getSceneArcFile);
    cellFileSet = &data_02174e68->mCellFileSets[1];
    remainingObjSize = GX_GetSizeOfSubOBJ();
    assignedCount = 0;
    mutil2_loadLayout(cellFileSet, aTimeattack_ghost_get_s_nce_ncgr, aTimeattack_ghost_get_s_nce_ncer, aTimeattack_ghost_get_s_o_nclr, aTimeattack_ghost_get_s_bncl,
                      aTimeattack_ghost_get_s_bnll, aTimeattack_ghost_get_s_bnbl, arc_getSceneArcFile);
    mutil2_initLayout(1, data_02174e68->mHeap, cellFileSet);
    cellCount = cellFileSet->mCellLayout->mUnk_06;
    j = 0;
    if (j < cellFileSet->mLabelLayout->mUnk_06) {
        row = data_02164470[0];
        do {
            if (row[3] < 0) {
                row[3] = cellCount + assignedCount++;
            }
            remainingObjSize -= mutil2_initLabel(1, data_02174e68->mHeap, cellFileSet, data_02164470[j], remainingObjSize);
            row += 4;
            j++;
        } while (j < cellFileSet->mLabelLayout->mUnk_06);
    }
    for (i = 0; i < 8; i++) {
        jn_ui_setCellPriority(i, 3, cellFileSet->mCells, cellFileSet->mCellLayout);
    }
    for (j = 0, row = data_02164470[0]; j < 7; j++) {
        cellIndex = row[3];
        labelIndex = row[0];
        secondLabelIndex = data_02164470[j + 7][0];
        cellTable = cellFileSet->mCellTable;
        mutil2_setElementPositionFromBncl(cellIndex, (u8 *) cellTable + (cellIndex << 6), cellFileSet->mCellLayout);
        mutil2_setElementPositionFromBnll(labelIndex, (u8 *) cellTable + (labelIndex << 6) + (cellCount << 6), cellFileSet->mLabelLayout);
        mutil2_setElementPositionFromBnll(secondLabelIndex, (u8 *) cellTable + (secondLabelIndex << 6) + (cellCount << 6),
                      cellFileSet->mLabelLayout);
        row += 4;
    }
    mutil2_setElementPositionFromBncl(7, (u8 *) cellFileSet->mCellTable + 0x1c0, cellFileSet->mCellLayout);
    w[0] = 0;
    w[1] = cellCount;
    w[2] = cellCount + 7;
    InitScrollList(data_02174e68->mHeap, 3, w, 7, 8, 0x7c, cellFileSet->mCellTable, cellFileSet->mRects,
                   data_02174e68->mUnk_20 + 0xc, 0, 1, 2, 10, func_02035c50);
    mutil2_loadPortraits(0, &data_02174e68->mUnk_64);
    PrintSelectedGhostRecord();
    interp_init(&data_02174e68->mUnk_90, 0, 10, -0xc0, 0);
    RequestSelectReturnState1();
    gmenu_setSeqArcIndex(0xf);
    func_02035c14();
    heap_adjustSubFrmHeap(data_02174e68->mHeap);
}

s32 func_0203551c(u16 *sceneNumbers) {
    Unk02174e68 *object;
    enum { K0 = -1 } result;
    s32 touchInReturnRect;
    BOOL pairIsNew;
    BOOL pairRecentlyGone;
    s32 i;
    u16 slotIndex;
    u16 hasPair;
    void *message;
    CellFileSet *cellFileSets;
    void *buttonText;

    result = K0;
    slotIndex = input_getDirectInputUnitId();
    touchInReturnRect = 0;
    interp_update(&data_02174e68->mUnk_90);
    pairIsNew = FALSE;
    pairRecentlyGone = FALSE;
    hasPair = data_02175674[slotIndex].mPressedBits;
    if (hasPair == 0 && data_02175680[slotIndex].mPressedBits < 5) {
        pairRecentlyGone = TRUE;
    }
    if (pairRecentlyGone == FALSE && data_0217567c[slotIndex].mPressedBits == 0 && hasPair != 0) {
        pairIsNew = TRUE;
    }
    if (pairIsNew != FALSE) {
        touchInReturnRect = gmenu_checkSelectReturnTouch(data_02175670[slotIndex].mPressedBits,
                                                                            data_02175672[slotIndex].mPressedBits);
    }
    object = data_02174e68;
    switch (object->mState) {
        case 0:
            if (object->mUnk_90.mState == 1) {
                object->mState = 1;
            } else {
                func_02035b0c();
            }
            break;
        case 1:
            if (IsTxtSystemState0NoOpenRequest() != 0) {
                func_02035c14();
            }
            AdvanceScrollList();
            i = GetScrollListSelectedRow();
            if (data_02174e68->mSelectedIndex != i) {
                data_02174e68->mSelectedIndex = i;
                PrintSelectedGhostRecord();
            }
            if (IsScrollListPickStarted() != 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
            }
            if (IsScrollListPickFinished() != 0) {
                SetupGhostNameSubTextTwoButtons();
                RequestSelectReturnState4();
                data_02174e68->mState = 2;
            } else if ((u16) (gInputUnits[slotIndex].mPressedBits & PAD_KEY_B) != 0 || touchInReturnRect != 0) {
                message = jn_msg_getMessage(data_02174e68->mGhostMessages, 0x54);
                buttonText = jn_msg_getMessage(data_02174e68->mCommonMessages, 4);
                SetTxtSystemSoundId(0, 5);
                SetupTxtSystemSubTextButton(message, buttonText);
                RequestSelectReturnState3WithSound(1);
                data_02174e68->mUnk_a0 = FALSE;
                data_02174e68->mState = 4;
            }
            break;
        case 2:
            if (GetTxtSystemInputAccepted() != 0 && GetTxtSystemSelectedIndex() == 0) {
                NNS_SndArcSetCurrent(&SDATFile);
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 10);
                NNS_SndArcSetCurrent(&gSdatFileSndArc);
            }
            if (GetTxtSystemDone() != 0) {
                if (GetTxtSystemSelectedIndex() == 0) {
                    ((Unk0202ddd8 *) GetSlotGhostBuffer())->mUnk_08_0 = 1;
                    savd_storeDownloadGhost((u8) data_02174e68->mSelectedIndex, GetSlotGhostBuffer());
                    data_02174e68->mState = 3;
                } else {
                    RequestSelectReturnState1();
                    data_02174e68->mState = 1;
                }
                RequestTxtSystemClose();
            }
            break;
        case 3:
            if (func_0203551c_inline_2() != 0) {
                message = jn_msg_getMessage(object->mGhostMessages, 0x10);
                buttonText = jn_msg_getMessage(data_02174e68->mCommonMessages, 4);
                SetTxtSystemSoundId(0, 5);
                SetupTxtSystemSubTextButton(message, buttonText);
                data_02174e68->mUnk_a0 = FALSE;
                data_02174e68->mState = 4;
            }
            break;
        case 4:
            if (GetTxtSystemDone() != 0) {
                gStruct217B488->mUnk_08 = 5;
                if (sceneNumbers != NULL) {
                    sceneNumbers[2] = 1;
                }
                data_02174e68->mState = 5;
            }
            break;
    }
    for (i = 0; i < 2; i++) {
        cellFileSets = data_02174e68->mCellFileSets;
        jn_ui_renderElements(cellFileSets[i].mCellLayout, cellFileSets[i].mCells, cellFileSets[i].mLabelLayout,
                        data_02174e68->mUnk_24[i], cellFileSets[i].mCellTable);
    }
    return result;
}

#pragma thumb off

#pragma thumb on

void func_020354fc(void) {
    heap_destroySubHeap(data_02174e68->mHeap);
    *(int *) &data_02174e68 = 0;
}

#pragma thumb off

#pragma thumb on

void func_020353f8(void) {
    s32 offset;
    s32 negatedOffset;

    offset = interp_interpolate(&data_02174e68->mUnk_90);
    reg_G2_BG0OFS = (offset << 16) & 0x1ff0000;
    negatedOffset = -offset;
    reg_G2S_DB_BG3OFS = (negatedOffset << 16) & 0x1ff0000;
    if (offset != 0) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffff1fff) | 0x2000;
        reg_G2_WININ = (u32) ((reg_G2_WININ & ~0x3f) | 0x1f) | 0x20;
        reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~0x3f) | 0xe) | 0x20;
        reg_G2_WIN0H = 0xff;
        reg_G2_WIN0V = ((negatedOffset << 8) & 0xff00) | 0xc0;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffff1fff) | 0x2000;
        reg_G2S_DB_WININ = (u32) ((reg_G2S_DB_WININ & ~0x3f) | 0x1f) | 0x20;
        reg_G2S_DB_WINOUT = (u32) ((reg_G2S_DB_WINOUT & ~0x3f) | 7) | 0x20;
        reg_G2S_DB_WIN0H = 0xff;
        reg_G2S_DB_WIN0V = (offset + 0xc0) & 0xff;
    } else {
        reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
        reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
    }
}

void func_020353a4(void) {
    void *message;
    void *buttonText;

    message = jn_msg_getMessage(sGhostReceiveState->mGhostMessages, 0x11);
    buttonText = jn_msg_getMessage(sGhostReceiveState->mCommonMessages, 4);
    SetTxtSystemSoundId(0, 5);
    SetupTxtSystemSubTextButton(message, buttonText);
    sGhostReceiveState->mStateFrames = 0;
    sGhostReceiveState->mState = 15;
}

#pragma thumb off

#pragma thumb on

void func_02035378(void) {
    void *message;
    message = jn_msg_getMessage(sGhostReceiveState->mGhostMessages, 1);
    CreateMainMessageBoxSmall(message, 0, 0, 0, 0, 0, 0);
}

#pragma thumb off

#pragma thumb on

// Selects the previous filled entry whose counter has run up to its end; a nonzero argument wraps from the first entry
// to the last.
void MoveSelectedGhostUp(s32 wrap) {
    BOOL found;
    s32 startIndex;
    s32 index;
    Unk02174e64 *object;

    found = FALSE;
    object = sGhostReceiveState;
    startIndex = object->mSelectedIndex;
    index = startIndex - 1;
    if (index < 0) {
        if (wrap == 0) {
            return;
        }
        index = 3;
    }
    if (index != startIndex) {
        do {
            if (object->mGhostInfoEntries[index].mFilled == TRUE &&
                object->mGhostInfoEntries[index].mInterpolation.mState == 1) {
                found = TRUE;
                object->mSelectedIndex = index;
                break;
            }
            index--;
            if (index < 0) {
                if (wrap == 0) {
                    return;
                }
                index = 3;
            }
        } while (index != object->mSelectedIndex);
    }
    if (found != FALSE) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
    }
}

// Selects the next filled entry whose counter has run up to its end; a nonzero argument wraps from the last entry to
// the first.
void MoveSelectedGhostDown(s32 wrap) {
    BOOL found;
    s32 startIndex;
    s32 index;
    Unk02174e64 *object;

    found = FALSE;
    object = sGhostReceiveState;
    startIndex = object->mSelectedIndex;
    index = startIndex + 1;
    if (index >= 4) {
        if (wrap == 0) {
            return;
        }
        index = 0;
    }
    if (index != startIndex) {
        do {
            if (object->mGhostInfoEntries[index].mFilled == TRUE &&
                object->mGhostInfoEntries[index].mInterpolation.mState == 1) {
                found = TRUE;
                object->mSelectedIndex = index;
                break;
            }
            index++;
            if (index >= 4) {
                if (wrap == 0) {
                    return;
                }
                index = 0;
            }
        } while (index != object->mSelectedIndex);
    }
    if (found != FALSE) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
    }
}

void func_02035228(s32 a) {
    CellFileSet *subCellFileSet;
    s32 selectedIndex;
    s32 w;
    s32 v;

    subCellFileSet = &sGhostReceiveState->mCellFileSets[1];
    selectedIndex = sGhostReceiveState->mSelectedIndex;
    w = selectedIndex + 4;
    if (a != 0) {
        v = 0xe;
    } else {
        v = 0xf;
    }
    subCellFileSet->mCellTable[4].mVisible = a;
    jn_ui_setLabelColorParam(w, v, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable, subCellFileSet->mCellLayout);
    jn_ui_setLabelColorParam(selectedIndex, v, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                         subCellFileSet->mCellLayout);
}

#pragma thumb off

#pragma thumb on

void SetupGhostSubTextTwoButtons(void) {
    void *message;
    void *firstButtonText;
    void *secondButtonText;
    message = jn_msg_getMessage(sGhostReceiveState->mGhostMessages, 8);
    firstButtonText = jn_msg_getMessage(sGhostReceiveState->mCommonMessages, 0);
    secondButtonText = jn_msg_getMessage(sGhostReceiveState->mCommonMessages, 1);
    SetTxtSystemSoundId(0, 5);
    CreateSubMessageBoxSubYesNo(message, firstButtonText, secondButtonText, 0, 0, 1, 1, 0);
}

#pragma thumb off
