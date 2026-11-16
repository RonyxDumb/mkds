#include "Main/Unknown/code_0202ccc0.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_02025ebc.h"
#include "Main/Unknown/code_0202e4b0.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02036000.h"
#include "code_0212d214.h"
#include "code_0212df7c.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "00/code_02181f98.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Save/GhostList.h"
#include "Main/Unknown/code_0202dd9c.h"
#include "Main/Ui/ScrollList.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204f5e4.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_02108c04.h"
#include "Main/Unknown/code_02108c1c.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_021262f0.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "code_02148950.h"
#include "Main/Unknown/code_020b3f7c.h"
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
#include "Main/Unknown/code_0202db04.h"
#include "Main/Unknown/unk_02153bec.h"
#include "Main/Unknown/unk_02162c74.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_0204ee64.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_02126000.h"
#include "Main/Unknown/code_02025cd0.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_02025f80.h"
#include "Main/Unknown/code_0204ea94.h"
#include "Main/Unknown/code_0204f240.h"
#include "registers.h"

#pragma thumb on

void RefreshGhostListRows(s32 action, s32 slot, s32 row, s32 selectedSlot) {
    MinuteSecondMillisecondTime recordTime;
    s16 text[10];
    CellFileSet *fileSet;
    s32 i;
    s32 j;
    s32 k;
    fileSet = &sGhostSendState->field50[1];
    if (action == 1) {
        jn_ui_212426C(1, slot, fileSet->mLabelLayout,
                      jn_msg_getMessage(sGhostSendState->mGhostMessages, mutil2_getCourseNameGhostMsgId(GetListedGhostCourseId(row))),
                      fileSet->mCellLayout, fileSet->mCellTable);
        GetListedGhostTime(row, &recordTime);
        mutil2_timeToString(text, recordTime.mMinute, recordTime.mSecond, recordTime.mMillisecond);
        jn_ui_2124224(1, slot + 7, fileSet->mLabelLayout, text, fileSet->mCellLayout, fileSet->mCellTable, 7);
        j = IsSlotGhostIndex(row) == 0;
        fileSet->mCellTable[slot].mVisible = j;
        k = j == 0;
        fileSet->mCellTable[slot + 7].mVisible = k;
    } else if (action == 0) {
        for (i = 0; i < 7; i++) {
            j = i + 7;
            if (i == selectedSlot) {
                k = 0xe;
            } else {
                k = 0xf;
            }
            jn_ui_setLabelColorParam(i, k, fileSet->mLabelLayout, fileSet->mCellTable, fileSet->mCellLayout);
            jn_ui_setLabelColorParam(j, k, fileSet->mLabelLayout, fileSet->mCellTable, fileSet->mCellLayout);
        }
    } else if (action == 2) {
        if (row >= 0 && row < (s32) ghost_getTotalGhostCount()) {
            j = IsSlotGhostIndex(row) == 0;
            fileSet->mCellTable[slot].mVisible = j;
            k = j == 0;
            fileSet->mCellTable[slot + 7].mVisible = k;
        }
    }
}

#pragma thumb off

#pragma thumb on

void func_0202d82c(void) {
    void *text;
    void *buttonText;
    text = jn_msg_getMessage(sGhostSendState->mGhostMessages, 0xd);
    buttonText = jn_msg_getMessage(sGhostSendState->mCommonMessages, 4);
    sGhostSendState->mState = 8;
    SetupTxtSystemSubTextButton(text, buttonText);
}

#pragma thumb off

#pragma thumb on

void gsend_initCounterLabels(void) {
    u16 text[6];
    CellFileSet *fileSet;
    s32 count;
    fileSet = &sGhostSendState->field50[1];
    jn_ui_212426C(1, 0xe, fileSet->mLabelLayout, jn_msg_getMessage(sGhostSendState->mGhostMessages, 0x56),
                  fileSet->mCellLayout, fileSet->mCellTable);
    jn_ui_212426C(1, 0xf, fileSet->mLabelLayout, jn_msg_getMessage(sGhostSendState->mGhostMessages, 0x57),
                  fileSet->mCellLayout, fileSet->mCellTable);
    count = ghost_getMyGhostCount();
    if (count < 10) {
        text[0] = ' ';
    } else {
        text[0] = count / 10 % 10 + '0';
    }
    text[1] = count % 10 + '0';
    text[2] = '/';
    text[3] = '3';
    text[4] = '2';
    text[5] = 0;
    jn_ui_2124224(1, 0x10, fileSet->mLabelLayout, text, fileSet->mCellLayout, fileSet->mCellTable, 6);
    count = ghost_getDlGhostCount();
    if (count < 10) {
        text[0] = ' ';
    } else {
        text[0] = count / 10 % 10 + '0';
    }
    text[1] = count % 10 + '0';
    text[2] = '/';
    text[3] = '1';
    text[4] = '0';
    text[5] = 0;
    jn_ui_2124224(1, 0x11, fileSet->mLabelLayout, text, fileSet->mCellLayout, fileSet->mCellTable, 6);
}

void PrintSelectedGhostSendRecord(void) {
    MinuteSecondMillisecondTime recordTime;
    u16 name[10];
    u16 terminatedName[11];
    s32 characterIndex;
    s32 kartIndex;
    GetListedGhostTime(sGhostSendState->mSelectedIndex, &recordTime);
    GetListedGhostName(sGhostSendState->mSelectedIndex, name);
    MIi_CpuCopy16(name, terminatedName, 0x14);
    terminatedName[10] = 0;
    characterIndex = GetListedGhostCharacterIndex(sGhostSendState->mSelectedIndex);
    kartIndex = GetListedGhostKartIndex(sGhostSendState->mSelectedIndex);
    PrintGhostRecordInfo((SelectCharacter *) sGhostSendState->field50, sGhostSendLabelsA,
                         terminatedName, characterIndex, kartIndex,
                         GetListedGhostCourseId(sGhostSendState->mSelectedIndex), &recordTime);
}

#pragma thumb off

#pragma thumb on

void func_0202d674(void) {
    void *text;
    text = jn_msg_getMessage(sGhostSendState->mGhostMessages, 0);
    CreateMainMessageBoxSmall(text, 0, 0, 0, 0, 0, 0);
}

#pragma thumb off

#pragma thumb on

void func_0202d5f8(s32 messageIndex, s32 withButton) {
    u16 name[11];
    u16 text[0x100];
    void *message;
    message = jn_msg_getMessage(sGhostSendState->mGhostMessages, messageIndex);
    MIi_CpuCopy16(sGhostSendState->fieldB8, name, 0x14);
    name[10] = 0;
    FormatMessageWithText(name, message, text, 0x100);
    if (withButton != 0) {
        SetupTxtSystemSubTextButton(text, jn_msg_getMessage(sGhostSendState->mCommonMessages, 4));
    } else {
        SetupTxtSystemSubText(text);
    }
}

void func_0202d5c0(void) {
    StartReadListedGhost(sGhostSendState->mSelectedIndex);
    SetupTxtSystemSubText(jn_msg_getMessage(sGhostSendState->mGhostMessages, 9));
    gmenu_setSeqArcIndex(0xe);
    RequestSelectReturnState4();
}

void SetGhostSendCellsOffsetY(void) {
    CellFileSet *mainFileSet;
    CellFileSet *subFileSet;
    s32 mainEntryCount;
    s32 subEntryCount;
    s32 i;
    s16 subOffsetY;
    mainFileSet = &sGhostSendState->field50[0];
    subFileSet = &sGhostSendState->field50[1];
    mainEntryCount = mainFileSet->mCellLayout->field6 + mainFileSet->mLabelLayout->field6;
    subEntryCount = subFileSet->mCellLayout->field6 + subFileSet->mLabelLayout->field6;
    subOffsetY = interp_interpolate(&sGhostSendState->mInterpolation);
    for (i = 0; i < mainEntryCount; i++) {
        mainFileSet->mCellTable[i].mOffsetY = -subOffsetY;
    }
    for (i = 0; i < subEntryCount; i++) {
        subFileSet->mCellTable[i].mOffsetY = subOffsetY;
    }
}

void gsend_create(void *parentHeap, void *mainOam, void *subOam) {
    s16 r[4];
    s32 cellIndex;
    s32 labelIndex;
    LayoutTableEntry *cellTable;
    CellFileSet *mainFileSet;
    CellFileSet *subFileSet;
    void *heap;
    s32 i;
    s32 objSizeLeft;
    s32 subCellCount;
    s32 assignedCount;
    heap = heap_createSubFrmHeap(parentHeap);
    sGhostSendState = heap_alloc(heap, 0xe0);
    MemFillWordsByBlock_inline(sGhostSendState, 0xe0);
    sGhostSendState->mHeap = heap;
    sGhostSendState->mOamLists[0] = mainOam;
    sGhostSendState->mOamLists[1] = subOam;
    sGhostSendState->mCommonMessages = arc_get2dArcFile(aCommon_bmg_32);
    sGhostSendState->mGhostMessages = arc_getSceneArcFile(aGhost_bmg_0);
    InitBlockEntries(sGhostSendState->mHeap, 2);
    mutil2_initBgGraphics(0, sGhostSendState, aTimeattack_ghost_send_m_b_ncgr, aTimeattack_ghost_send_m_b_nclr,
                  aTimeattack_ghost_send_m_nscr, 0, arc_getSceneArcFile);
    mainFileSet = &sGhostSendState->field50[0];
    objSizeLeft = GX_GetSizeOfOBJ();
    mutil2_loadLayout(mainFileSet, aTimeattack_ghost_send_m_nce_ncgr, aTimeattack_ghost_send_m_nce_ncer,
                      aTimeattack_ghost_send_m_o_nclr, aTimeattack_ghost_send_m_bncl, aTimeattack_ghost_send_m_bnll,
                      NULL, arc_getSceneArcFile);
    mutil2_initLayout(0, sGhostSendState->mHeap, mainFileSet);
    for (i = 0; i < mainFileSet->mLabelLayout->field6; i++) {
        objSizeLeft -= mutil2_initLabel(0, sGhostSendState->mHeap, mainFileSet, sGhostSendLabelsA[i],
                                     objSizeLeft);
    }
    mutil2_initBgGraphics(1, &sGhostSendState->field24, aTimeattack_ghost_send_s_b_ncgr, aTimeattack_ghost_send_s_b_nclr,
                  aTimeattack_ghost_send_s_nscr, 3, arc_getSceneArcFile);
    subFileSet = &sGhostSendState->field50[1];
    objSizeLeft = GX_GetSizeOfSubOBJ();
    assignedCount = 0;
    mutil2_loadLayout(subFileSet, aTimeattack_ghost_send_s_nce_ncgr, aTimeattack_ghost_send_s_nce_ncer,
                      aTimeattack_ghost_send_s_o_nclr, aTimeattack_ghost_send_s_bncl, aTimeattack_ghost_send_s_bnll,
                      aTimeattack_ghost_send_s_bnbl, arc_getSceneArcFile);
    mutil2_initLayout(1, sGhostSendState->mHeap, subFileSet);
    subCellCount = subFileSet->mCellLayout->field6;
    for (i = 0; i < subFileSet->mLabelLayout->field6; i++) {
        if (sGhostSendLabelsB[i][3] < 0) {
            sGhostSendLabelsB[i][3] = subCellCount + assignedCount++;
        }
        objSizeLeft -= mutil2_initLabel(1, sGhostSendState->mHeap, subFileSet,
                                     (s16(*)[4]) sGhostSendLabelsB + i, objSizeLeft);
    }
    gsend_initCounterLabels();
    for (i = 0; i < 0xf; i++) {
        jn_ui_setCellPriority(i, 3, subFileSet->mCells, subFileSet->mCellLayout);
    }
    for (i = 0; i < 0xe; i++) {
        jn_ui_setLabelPriority(i, 2, subFileSet->mLabelLayout, subFileSet->mCellTable, subFileSet->mCellLayout);
    }
    for (i = 0; i < 0xe; i++) {
        cellIndex = sGhostSendLabelsB[i][3];
        labelIndex = sGhostSendLabelsB[i][0];
        cellTable = subFileSet->mCellTable;
        mutil2_setElementPositionFromBncl(cellIndex, &cellTable[cellIndex], subFileSet->mCellLayout);
        mutil2_setElementPositionFromBnll(labelIndex, cellTable + subCellCount + labelIndex, subFileSet->mLabelLayout);
    }
    mutil2_setElementPositionFromBncl(0xe, (u8 *) subFileSet->mCellTable + 0x380, subFileSet->mCellLayout);
    if (ghost_getTotalGhostCount() != 0) {
        Unk02174e40_24 *screenMapFileSet = &sGhostSendState->field24;
        r[0] = 0;
        r[1] = 7;
        r[2] = subCellCount;
        r[3] = subCellCount + 7;
        InitScrollList(sGhostSendState->mHeap, 4, r, 0xe, 0xf, 0x7c, subFileSet->mCellTable, subFileSet->mRects,
                       screenMapFileSet->field20 + 0xc, 0, 1, 2, ghost_getTotalGhostCount(), RefreshGhostListRows);
    } else {
        for (i = 0; i < subCellCount; i++) {
            subFileSet->mCellTable[i].mVisible = 0;
        }
        for (i = 0; i < 0xe; i++) {
            subFileSet->mCellTable[subCellCount + i].mVisible = 0;
        }
    }
    mutil2_loadPortraits(0, &sGhostSendState->field50[2]);
    interp_init(&sGhostSendState->mInterpolation, 3, 10, -0xc0, 0);
    gmenu_setSeqArcIndex(0xf);
    LEDBlink_Wireless();
    sGhostSendState->mState = 1;
    heap_adjustSubFrmHeap(sGhostSendState->mHeap);
}

s32 gsend_render(Unk0202cdf4 *advanceArg) {
    u16 slotIndex;
    s32 b;
    s32 a;
    s32 returnTouched;
    s32 hasPair;
    u16 keyB;
    BackupAccess *d;
    CellFileSet *fileSets;
    s32 i;
    slotIndex = input_getDirectInputUnitId();
    returnTouched = 0;
    interp_update(&sGhostSendState->mInterpolation);
    b = returnTouched;
    a = b;
    hasPair = gInputUnits[slotIndex].mHasPair;
    if (hasPair == 0 && gInputUnits[slotIndex].mNoPairCount < 5) {
        a = 1;
    }
    if (a == 0 && gInputUnits[slotIndex].mPrevHasPair == 0 && hasPair != 0) {
        b = 1;
    }
    if (b != 0) {
        returnTouched = gmenu_checkSelectReturnTouch(gInputUnits[slotIndex].mPairX,
                                                                        gInputUnits[slotIndex].mPairY);
    }
    switch (sGhostSendState->mState) {
        case 0:
            if (GetTxtSystemDone() != 0) {
                gStruct217B488->field8 = 5;
                if (advanceArg != NULL) {
                    advanceArg->field4 = 1;
                }
                sGhostSendState->mState = 0xe;
            }
            break;
        case 1:
            if (mbright_isFadedIn() == 0) {
                if (ghost_getTotalGhostCount() == 0) {
                    SetupTxtSystemSubTextButton(jn_msg_getMessage(sGhostSendState->mGhostMessages, 0x53),
                                                jn_msg_getMessage(sGhostSendState->mCommonMessages, 4));
                    sGhostSendState->mState = 0;
                } else {
                    PrintSelectedGhostSendRecord();
                    func_0202d674();
                    RequestSelectReturnState1();
                    interp_setState(&sGhostSendState->mInterpolation, 0);
                    sGhostSendState->mState = 2;
                }
            }
            break;
        case 2:
            if (sGhostSendState->mInterpolation.mState == 1) {
                sGhostSendState->fieldB4 = 0;
                sGhostSendState->mState = 3;
            } else {
                SetGhostSendCellsOffsetY();
            }
            break;
        case 3:
            if (IsTxtSystemState2NoCloseRequest() != 0) {
                AdvanceScrollList();
                i = GetScrollListSelectedRow();
                if (sGhostSendState->mSelectedIndex != i) {
                    sGhostSendState->mSelectedIndex = i;
                    PrintSelectedGhostSendRecord();
                }
                if (IsScrollListPickStarted() != 0) {
                    NNS_SndArcSetCurrent(&SDATFile);
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 7);
                    NNS_SndArcSetCurrent(&gSdatFileSndArc);
                }
                if (IsScrollListPickFinished() != 0) {
                    func_0202d5c0();
                    func_02108c1c();
                    sGhostSendState->mState = 4;
                } else {
                    keyB = gInputUnits[slotIndex].mPressedBits & PAD_KEY_B;
                    if (keyB != 0 || returnTouched != 0) {
                        gStruct217B488->field8 = 5;
                        if (advanceArg != NULL) {
                            advanceArg->field4 = 1;
                        }
                        sGhostSendState->mState = 0xe;
                        RequestSelectReturnState3WithSound(0);
                    }
                }
            }
            break;
        case 4:
            d = gSaveCore;
            if (d->mBackupEnabled != 0) {
                i = d->mCommandRunning;
            } else {
                i = 0;
            }
            if (i == 0 && d->mErrorCode == 0) {
                if (IsSlotGhostIndex(sGhostSendState->mSelectedIndex) == 0) {
                    func_0203bf04(GetCourseGhostBuffer(), (void *) GetSlotGhostBuffer());
                }
                sGhostSendState->mState = 5;
            }
            break;
        case 5:
            i = AdvanceConnectionSetup(1, (void *) GetSlotGhostBuffer());
            switch (i) {
                case 1:
                    ResetPendingFiles();
                    func_0204eeac((void *) GetSlotGhostBuffer(), 0x1000);
                    RequestSelectReturnState1();
                    sGhostSendState->mState = 6;
                    break;
                case 2:
                    break;
            }
            break;
        case 6:
            keyB = gInputUnits[slotIndex].mPressedBits & PAD_KEY_B;
            if (keyB != 0 || returnTouched != 0) {
                RequestSelectReturnState3WithSound(0);
                gmenu_setSeqArcIndex(0xf);
                func_02108c04();
                sGhostSendState->mState = 0xb;
            } else if (func_0204eb08(sGhostSendState->fieldB8) != 0) {
                RequestSelectReturnState4();
                func_02108c04();
                NNS_SndArcSetCurrent(&SDATFile);
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 9);
                NNS_SndArcSetCurrent(&gSdatFileSndArc);
                func_0202d5f8(0xb, 0);
                sGhostSendState->mState = 7;
            }
            break;
        case 7:
            i = func_0205465c();
            switch (i) {
                case 1:
                    NNS_SndArcSetCurrent(&SDATFile);
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0xa);
                    NNS_SndArcSetCurrent(&gSdatFileSndArc);
                    sGhostSendState->mState = 0xa;
                    break;
                case 2:
                    func_0202d82c();
                    break;
            }
            break;
        case 8:
            if (IsTxtSystemState2AfterState1() != 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x15);
            }
            if (GetTxtSystemDone() != 0) {
                sGhostSendState->mState = 9;
            }
            break;
        case 9:
            if (func_02054f58() == 1) {
                LEDBlink_Wireless();
                gStruct217B488->field8 = 5;
                if (advanceArg != NULL) {
                    advanceArg->field4 = 1;
                }
                sGhostSendState->mState = 0xe;
            }
            break;
        case 10:
            if (func_02054f58() == 1) {
                LEDBlink_Wireless();
                func_0202d5f8(0xc, 1);
                sGhostSendState->mState = 0xd;
            }
            break;
        case 11:
            if (func_02054f58() == 1) {
                LEDBlink_Wireless();
                func_0202d674();
                sGhostSendState->mState = 3;
            }
            break;
        case 13:
            if (GetTxtSystemDone() != 0) {
                gStruct217B488->field8 = 5;
                if (advanceArg != NULL) {
                    advanceArg->field4 = 1;
                }
                sGhostSendState->mState = 0xe;
            }
            break;
    }
    func_02054aa0();
    for (i = 0; i < 2; i++) {
        fileSets = sGhostSendState->field50;
        jn_ui_renderElements(fileSets[i].mCellLayout, fileSets[i].mCells, fileSets[i].mLabelLayout,
                        sGhostSendState->mOamLists[i], fileSets[i].mCellTable);
    }
    return -1;
}

#pragma thumb off

#pragma thumb on

void gsend_finish(void) {
    heap_destroySubHeap(sGhostSendState->mHeap);
    *(int *) &sGhostSendState = 0;
}

#pragma thumb off

#pragma thumb on

void gsend_vblank(void) {
    s16 interpolatedValue = interp_interpolate(&sGhostSendState->mInterpolation);
    int negatedValue;
    reg_G2_BG0OFS = ((interpolatedValue << 16) & 0x1ff0000);
    negatedValue = -interpolatedValue;
    reg_G2S_DB_BG3OFS = ((negatedValue << 16) & 0x1ff0000);
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 1;
    if (interpolatedValue != 0) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffff1fff) | 0x2000;
        reg_G2_WININ = (u32) ((reg_G2_WININ & ~0x3f) | 0x1f) | 0x20;
        reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~0x3f) | 0xe) | 0x20;
        reg_G2_WIN0H = 0xff;
        reg_G2_WIN0V = ((negatedValue << 8) & 0xff00) | 0xc0;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffff1fff) | 0x2000;
        reg_G2S_DB_WININ = (u32) ((reg_G2S_DB_WININ & ~0x3f) | 0x1f) | 0x20;
        reg_G2S_DB_WINOUT = (u32) ((reg_G2S_DB_WINOUT & ~0x3f) | 7) | 0x20;
        reg_G2S_DB_WIN0H = 0xff;
        reg_G2S_DB_WIN0V = (interpolatedValue + 0xc0) & 0xff;
    } else {
        reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
        reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
    }
}

#pragma thumb off
