#include "Main/Unknown/code_02030a20.h"

#include "Main/Unknown/code_02036000.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02125ee8.h"
#include "Main/Unknown/code_0212b000.h"
#include "Main/Unknown/code_0212b1a8.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_0202f14c.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02108c1c.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
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
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "00/code_02181f98.h"
#include "code_0201ea58.h"
#include "code_0212d214.h"
#include "code_0212df7c.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204aa04.h"
#include "Main/Unknown/code_0204db48.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02058b38.h"
#include "Main/Unknown/code_0205e2cc.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_02126248.h"
#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/code_021262f0.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_0212b928.h"
#include "code_02148950.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/unk_02163000.h"
#include "Main/Unknown/unk_02175000.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_02025f80.h"
#include "registers.h"

#pragma thumb on

void func_02032028(void) {
    void *bannerMessage;
    void *commonMessage;

    bannerMessage = jn_msg_getMessage(gMultiSelectMember->mBannerMessages, 0xb);
    commonMessage = jn_msg_getMessage(gMultiSelectMember->mCommonMessages, 4);
    gMultiSelectMember->mUnk_70 = 8;
    gMultiSelectMember->mState = 5;
    SetupTxtSystemSubTextButton(bannerMessage, commonMessage);
    RequestSelectReturnState4();
}

s32 CountMultiSelectChildren(void) {
    s32 i;
    s32 childCount;

    childCount = 0;
    for (i = 1; i < 8; i++) {
        if (func_0204fcec(i, NULL) != 0) {
            childCount++;
        }
    }
    return childCount;
}

void PrintMultiSelectMemberNames(void) {
    Unk02174e58_24 *subFileSet;
    LabelMessageRow *labelMessageRow;
    u16 nameBuffer[12];
    s32 i;

    subFileSet = &gMultiSelectMember->mCellFileSets[1];
    for (i = 1, labelMessageRow = data_02153d88; i < 8; labelMessageRow++, i++) {
        nameBuffer[0] = 0;
        MIi_CpuClear16(nameBuffer[0], &nameBuffer[1], 0x16);
        if (func_0204fcec(i, &nameBuffer[1]) != 0) {
            nameBuffer[11] = 0;
            jn_ui_212426C(1, labelMessageRow->mLabelIndex, subFileSet->mUnk_14, &nameBuffer[1], subFileSet->mUnk_0c,
                          subFileSet->mUnk_18);
            if (gMultiSelectMember->mRows[i].mState != 2) {
                gMultiSelectMember->mRows[i].mState = 1;
            }
        } else {
            jn_ui_21241C0(1, labelMessageRow->mLabelIndex, subFileSet->mUnk_14, subFileSet->mUnk_0c,
                                         subFileSet->mUnk_18);
            gMultiSelectMember->mRows[i].mState = 0;
        }
    }
}

void func_02031e80(void) {
    Unk02174e58_24 *subFileSet;
    LabelMessageRow *labelMessageRow;
    u16 nameBuffer[12];
    s32 childCount;
    s32 i;

    childCount = 0;
    subFileSet = &gMultiSelectMember->mCellFileSets[1];
    for (i = 1, labelMessageRow = data_02153d88; i < 8; labelMessageRow++, i++) {
        nameBuffer[0] = 0;
        MIi_CpuClear16(nameBuffer[0], &nameBuffer[1], 0x16);
        if (&gStruct217AA00->mUnk_045c[(u16) i] != NULL) {
            MIi_CpuCopy16(&gStruct217AA00->mUnk_045c[(u16) i], &nameBuffer[1], 0x14);
            if (nameBuffer[1] != 0) {
                jn_ui_212426C(1, labelMessageRow->mLabelIndex, subFileSet->mUnk_14, &nameBuffer[1], subFileSet->mUnk_0c,
                              subFileSet->mUnk_18);
                gMultiSelectMember->mRows[i].mState = 2;
                childCount++;
            } else {
                jn_ui_21241C0(1, labelMessageRow->mLabelIndex, subFileSet->mUnk_14, subFileSet->mUnk_0c,
                                             subFileSet->mUnk_18);
                gMultiSelectMember->mRows[i].mState = 0;
            }
        }
    }
    gMultiSelectMember->mChildCount = childCount;
    gMultiSelectMember->mUnk_8c = TRUE;
}

void func_02031ba4(void) {
    Unk02174e58_24 *mainFileSet;
    Unk02174e58_24 *subFileSet;
    s32 mainLabelCount;
    s32 mainCellCount;
    s32 subLabelCount;
    s32 n3;
    s32 i;
    s16 interpolatedValue;
    BOOL visible;
    s32 d;
    MultiSelectMemberRow *row;

    mainFileSet = &gMultiSelectMember->mCellFileSets[0];
    subFileSet = &gMultiSelectMember->mCellFileSets[1];
    mainLabelCount = mainFileSet->mUnk_14->mUnk_06;
    mainCellCount = mainFileSet->mUnk_0c->mUnk_06;
    subLabelCount = subFileSet->mUnk_14->mUnk_06;
    n3 = subFileSet->mUnk_0c->mUnk_06;
    interp_update(&gMultiSelectMember->mInterpolations[0]);
    mainFileSet->mUnk_18[2].mOffsetY = interp_interpolate(&gMultiSelectMember->mInterpolations[0]);
    mainFileSet->mUnk_18[1].mOffsetY = mainFileSet->mUnk_18[2].mOffsetY;
    mainFileSet->mUnk_18[0].mOffsetY = mainFileSet->mUnk_18[1].mOffsetY;
    gMultiSelectMember->mCycleFrames = gMultiSelectMember->mCycleFrames + 1;
    if (gMultiSelectMember->mCycleFrames > data_02153d46[gMultiSelectMember->mCycleIndex][0]) {
        gMultiSelectMember->mCycleIndex = gMultiSelectMember->mCycleIndex + 1;
        if (gMultiSelectMember->mCycleIndex == 4) {
            gMultiSelectMember->mCycleIndex = 0;
        }
        gMultiSelectMember->mCycleFrames = 0;
    }
    if (data_02153d44[gMultiSelectMember->mCycleIndex][0] == 0) {
        d = 1;
    } else {
        d = 0;
    }
    mainFileSet->mUnk_18[0].mVisible = d;
    if (data_02153d44[gMultiSelectMember->mCycleIndex][0] == 1) {
        d = 1;
    } else {
        d = 0;
    }
    mainFileSet->mUnk_18[1].mVisible = d;
    if (data_02153d44[gMultiSelectMember->mCycleIndex][0] == 2) {
        d = 1;
    } else {
        d = 0;
    }
    mainFileSet->mUnk_18[2].mVisible = d;
    interp_update(&gMultiSelectMember->mInterpolations[1]);
    interpolatedValue = interp_interpolate(&gMultiSelectMember->mInterpolations[1]);
    mainFileSet->mUnk_18[0xb].mOffsetY = interpolatedValue;
    mainFileSet->mUnk_18[0xa].mOffsetY = mainFileSet->mUnk_18[0xb].mOffsetY;
    mainFileSet->mUnk_18[9].mOffsetY = mainFileSet->mUnk_18[0xa].mOffsetY;
    mainFileSet->mUnk_18[8].mOffsetY = mainFileSet->mUnk_18[9].mOffsetY;
    mainFileSet->mUnk_18[7].mOffsetY = mainFileSet->mUnk_18[8].mOffsetY;
    mainFileSet->mUnk_18[6].mOffsetY = mainFileSet->mUnk_18[7].mOffsetY;
    mainFileSet->mUnk_18[5].mOffsetY = mainFileSet->mUnk_18[6].mOffsetY;
    mainFileSet->mUnk_18[4].mOffsetY = mainFileSet->mUnk_18[5].mOffsetY;
    mainFileSet->mUnk_18[3].mOffsetY = mainFileSet->mUnk_18[4].mOffsetY;
    for (i = 0; i < mainLabelCount; i++) {
        mainFileSet->mUnk_18[i + mainCellCount].mOffsetY = interpolatedValue;
    }
    interp_update(&gMultiSelectMember->mInterpolations[2]);
    interpolatedValue = interp_interpolate(&gMultiSelectMember->mInterpolations[2]);
    i = 0;
    d = n3 + subLabelCount;
    for (; i < d; i++) {
        subFileSet->mUnk_18[i].mOffsetY = interpolatedValue;
    }
    if (gMultiSelectMember->mChildCount > 0) {
        interp_setState(&gMultiSelectMember->mInterpolations[3], 0);
    } else {
        interp_setState(&gMultiSelectMember->mInterpolations[3], 2);
    }
    interp_update(&gMultiSelectMember->mInterpolations[3]);
    interpolatedValue = interp_interpolate(&gMultiSelectMember->mInterpolations[3]);
    n3 = n3 + 8;
    subFileSet->mUnk_18[n3].mOffsetY = interpolatedValue;
    subFileSet->mUnk_18[0x11].mOffsetY = subFileSet->mUnk_18[n3].mOffsetY;
    subFileSet->mUnk_18[0x10].mOffsetY = subFileSet->mUnk_18[0x11].mOffsetY;
    if (gMultiSelectMember->mUnk_84 == 0) {
        for (i = 0; i < 8; i++) {
            row = &gMultiSelectMember->mRows[i];
            switch (row->mState) {
                case 0:
                    subFileSet->mUnk_18[row->mSecondCellIndex].mVisible = 0;
                    subFileSet->mUnk_18[row->mFirstCellIndex].mVisible =
                        subFileSet->mUnk_18[row->mSecondCellIndex].mVisible;
                    row->mStateFrames = 0;
                    break;
                case 1:
                    row->mStateFrames = row->mStateFrames + 1;
                    if (row->mStateFrames > 0x14) {
                        row->mState = 2;
                    } else {
                        if (row->mStateFrames / 4 % 2 == 0) {
                            visible = TRUE;
                        } else {
                            visible = FALSE;
                        }
                        subFileSet->mUnk_18[row->mFirstCellIndex].mVisible = visible;
                        if (visible == FALSE) {
                            visible = TRUE;
                        } else {
                            visible = FALSE;
                        }
                        subFileSet->mUnk_18[row->mSecondCellIndex].mVisible = visible;
                    }
                    break;
                case 2:
                    subFileSet->mUnk_18[row->mSecondCellIndex].mVisible = 1;
                    subFileSet->mUnk_18[row->mFirstCellIndex].mVisible =
                        subFileSet->mUnk_18[row->mSecondCellIndex].mVisible;
                    row->mStateFrames = 0;
                    break;
            }
        }
    }
}

void SetMultiSelectChildCountCellsVisible(void) {
    s32 i;
    Unk02174e58_24 *mainFileSet;
    BOOL visible;

    mainFileSet = &gMultiSelectMember->mCellFileSets[0];
    for (i = 0; i < 8; i++) {
        if (i == gMultiSelectMember->mChildCount) {
            visible = TRUE;
        } else {
            visible = FALSE;
        }
        mainFileSet->mUnk_18[gMultiSelectMemberCountCellIndices[i]].mVisible = visible;
    }
}

void func_02031b30(s32 visible) {
    Unk02174e58_24 *subFileSet;
    s32 labelValue;

    subFileSet = &gMultiSelectMember->mCellFileSets[1];
    if (visible != 0) {
        labelValue = 1;
    } else {
        labelValue = 0;
    }
    subFileSet->mUnk_18[0x11].mVisible = visible;
    jn_ui_setLabelColorParam(8, labelValue, subFileSet->mUnk_14, subFileSet->mUnk_18, subFileSet->mUnk_0c);
}

void func_02031960(void) {
    s32 v;

    switch (gMultiSelectMember->mUnk_70) {
        case 0:
            if (func_0205579c(1, gSystemData->mUnk_1c_2) == 1) {
                gMultiSelectMember->mUnk_70 = 1;
            }
            break;
        case 1:
            if (gMultiSelectMember->mUnk_78 != FALSE) {
                gMultiSelectMember->mUnk_78 = FALSE;
                gMultiSelectMember->mUnk_70 = 3;
                gMultiSelectMember->mTimer = 0x78;
                SetupTxtSystemSubTextEx(jn_msg_getMessage(gMultiSelectMember->mCommonMessages, 0x79), 0, 1, 1, 0, 1);
                interp_setState(&gMultiSelectMember->mInterpolations[0], 2);
            } else if (gMultiSelectMember->mUnk_7c != FALSE) {
                gMultiSelectMember->mUnk_7c = FALSE;
                gMultiSelectMember->mUnk_70 = 7;
            } else {
                func_020554e4();
            }
            break;
        case 3:
            switch (func_0204db6c()) {
                case 1:
                    gMultiSelectMember->mUnk_70 = 4;
                    break;
                case 2:
                    func_02032028();
                    break;
            }
            break;
        case 4:
            switch (func_02058cac()) {
                case 1:
                    if (gMultiSelectMember->mTimer == 0) {
                        if ((u8) ((gStruct217AA00->mParticipantMask & ~gStruct217AA00->mUnk_0457) & 0xfe) != 0) {
                            SetupTxtSystemSubText(jn_msg_getMessage(gMultiSelectMember->mCommonMessages, 0x81));
                            gMultiSelectMember->mTimer = 0x78;
                        } else {
                            RequestTxtSystemClose();
                        }
                        func_02108d80();
                        StartCopyOtherEmblems(1);
                        gMultiSelectMember->mUnk_148 = FALSE;
                        gMultiSelectMember->mUnk_70 = 6;
                    }
                    break;
                case 2:
                    func_02032028();
                    break;
            }
            break;
        case 7:
        case 8:
            if (func_02054f58() == 1) {
                gMultiSelectMember->mUnk_70 = 11;
            }
            break;
        case 6:
            if (gSaveData->mBusy == 0) {
                if (gSaveCore->mBackupEnabled != 0) {
                    v = gSaveCore->mCommandRunning;
                } else {
                    v = 0;
                }
            } else {
                v = 1;
            }
            if (v == 0 && gMultiSelectMember->mTimer == 0) {
                gMultiSelectMember->mUnk_70 = 11;
            }
            break;
    }
}

void func_020317a0(void) {
    s32 v;

    switch (gMultiSelectMember->mUnk_70) {
        case 2:
            if (gMultiSelectMember->mUnk_7c != FALSE) {
                gMultiSelectMember->mUnk_7c = FALSE;
                gMultiSelectMember->mUnk_70 = 7;
                return;
            }
            switch (func_02055730(func_0202f14c()->mUnk_00)) {
                case 1:
                    if (gSystemData->mUnk_20 == 2) {
                        sysdat_setIsMBChild((gStruct217AA00->mUnk_0454 & 0x40) != 0 ? 1 : 0);
                    }
                    gMultiSelectMember->mUnk_70 = 4;
                    if (gMultiSelectMember->mUnk_84 == 0) {
                        gMultiSelectMember->mChildCount = CountMultiSelectChildren();
                        PrintMultiSelectMemberNames();
                        gMultiSelectMember->mUnk_88 = TRUE;
                    }
                    break;
                case 2:
                    func_02032028();
                    break;
            }
            break;
        case 4:
            if (gMultiSelectMember->mUnk_7c != FALSE) {
                gMultiSelectMember->mUnk_7c = FALSE;
                gMultiSelectMember->mUnk_70 = 7;
                return;
            }
            switch (func_02058cac()) {
                case 1:
                    if (gMultiSelectMember->mUnk_84 == 0 && gMultiSelectMember->mUnk_8c == FALSE) {
                        func_02031e80();
                        SetMultiSelectChildCountCellsVisible();
                    }
                    if (gMultiSelectMember->mTimer == 0) {
                        SetupTxtSystemSubText(jn_msg_getMessage(gMultiSelectMember->mCommonMessages, 0x81));
                        func_02108d80();
                        StartCopyOtherEmblems(1);
                        gMultiSelectMember->mUnk_148 = FALSE;
                        gMultiSelectMember->mTimer = 0x78;
                        gMultiSelectMember->mUnk_70 = 6;
                    }
                    break;
                case 2:
                    func_02032028();
                    break;
            }
            break;
        case 7:
        case 8:
            if (func_02054f58() == 1) {
                gMultiSelectMember->mUnk_70 = 11;
            }
            break;
        case 6:
            if (gSaveData->mBusy == 0) {
                if (gSaveCore->mBackupEnabled != 0) {
                    v = gSaveCore->mCommandRunning;
                } else {
                    v = 0;
                }
            } else {
                v = 1;
            }
            if (v == 0 && gMultiSelectMember->mTimer == 0) {
                gMultiSelectMember->mUnk_70 = 11;
            }
            break;
    }
}

void InitMultiSelectMember(void *parentHeap, void *mainOam, void *subOam) {
    Unk02174e58_24 *mainFileSet;
    Unk02174e58_24 *subFileSet;
    u32 mainObjSizeLeft;
    s32 i;
    u32 subObjSizeLeft;
    void *heap;
    volatile u32 clearValue;
    LabelMessageRow *canvasRow;
    LabelMessageRow *printRow;

    heap = heap_createSubFrmHeap(parentHeap);
    gMultiSelectMember = heap_alloc(heap, 0x154);
    clearValue = 0;
    MIi_CpuClearFast(clearValue, gMultiSelectMember, 0x154);
    gMultiSelectMember->mHeap = heap;
    gMultiSelectMember->mMainOam = mainOam;
    gMultiSelectMember->mSubOam = subOam;
    gMultiSelectMember->mBannerMessages = arc_getSceneArcFile(aBanner_bmg_0);
    gMultiSelectMember->mCommonMessages = arc_get2dArcFile(aCommon_bmg_35);
    gMultiSelectMember->mUnk_6c = -1;
    mainObjSizeLeft = GX_GetSizeOfOBJ();
    mainFileSet = &gMultiSelectMember->mCellFileSets[0];
    mutil2_loadLayout(mainFileSet, aMulti_select_member_m_nce_ncgr, aMulti_select_member_m_nce_ncer,
                      aMulti_select_member_m_o_nclr, aMulti_select_member_m_bncl, aMulti_select_member_m_bnll, NULL,
                      arc_getSceneArcFile);
    mutil2_initLayout(0, gMultiSelectMember->mHeap, mainFileSet);
    i = 0;
    canvasRow = data_02153d64;
    printRow = canvasRow;
    for (; i < 2; i++) {
        mainObjSizeLeft -= mutil2_initLabel(0, gMultiSelectMember->mHeap, mainFileSet, canvasRow, mainObjSizeLeft);
        jn_ui_212426C(0, printRow->mLabelIndex, mainFileSet->mUnk_14,
                      jn_msg_getMessage(gMultiSelectMember->mBannerMessages, printRow->mMessageIndex), mainFileSet->mUnk_0c,
                      mainFileSet->mUnk_18);
        canvasRow++;
        printRow++;
    }
    SetMultiSelectChildCountCellsVisible();
    mutil2_initBgGraphics(1, gMultiSelectMember, aMulti_select_member_s_b_ncgr, aMulti_select_member_s_b_nclr,
                  aMulti_select_member_s_register_nscr, 3, arc_getSceneArcFile);
    subObjSizeLeft = GX_GetSizeOfSubOBJ();
    subFileSet = &gMultiSelectMember->mCellFileSets[1];
    mutil2_loadLayout(subFileSet, aMulti_select_member_register_s_nce_ncgr, aMulti_select_member_register_s_nce_ncer,
                      aMulti_select_member_register_s_o_nclr, aMulti_select_member_s_register_bncl,
                      aMulti_select_member_s_register_bnll, aMulti_select_member_s_register_bnbl, arc_getSceneArcFile);
    mutil2_initLayout(1, gMultiSelectMember->mHeap, subFileSet);
    for (i = 0; i < 9; i++) {
        subObjSizeLeft -=
            mutil2_initLabel(1, gMultiSelectMember->mHeap, subFileSet, &data_02153d7c[i], subObjSizeLeft);
    }
    interp_init(&gMultiSelectMember->mInterpolations[3], 3, 10, 0x40, 0);
    InitPaletteBlend(gMultiSelectMember->mHeap, subFileSet->mUnk_04, 3);
    func_02031b30(1);
    interp_init(&gMultiSelectMember->mInterpolations[0], 0, 10, -0x40, 0);
    interp_init(&gMultiSelectMember->mInterpolations[1], 0, 10, 0x40, 0);
    interp_init(&gMultiSelectMember->mInterpolations[2], 0, 10, -0xc0, 0);
    gMultiSelectMember->mRows[0].mState = 2;
    for (i = 0; i < 8; i++) {
        gMultiSelectMember->mRows[i].mFirstCellIndex = i * 2;
        gMultiSelectMember->mRows[i].mSecondCellIndex = i * 2 + 1;
    }
    SetTxtSystemBgOffsetRequested(0x20, 0);
}

void func_0203147c(void *parentHeap, void *mainOam, void *subOam) {
    Unk02174e58_24 *subFileSet;
    u16 nameBuffer[11];

    InitMultiSelectMember(parentHeap, mainOam, subOam);
    subFileSet = &gMultiSelectMember->mCellFileSets[1];
    MIi_CpuCopy16(gSaveData->mFirstBlock->mPlayerName, nameBuffer, 0x14);
    nameBuffer[10] = 0;
    jn_ui_212426C(1, data_02153d7c[0].mLabelIndex, subFileSet->mUnk_14, nameBuffer, subFileSet->mUnk_0c,
                  subFileSet->mUnk_18);
    jn_ui_212426C(1, data_02153dbc[16], subFileSet->mUnk_14,
                  jn_msg_getMessage(gMultiSelectMember->mBannerMessages, data_02153d7c[8].mMessageIndex),
                  subFileSet->mUnk_0c, subFileSet->mUnk_18);
    gSystemData->mUnk_20 = 1;
    CreateMainMessageBoxBig(jn_msg_getMessage(gMultiSelectMember->mBannerMessages, 9), 0, 0, 1, 0, 0, 0);
    subFileSet->mUnk_18[0x11].mVisible = 0;
    subFileSet->mUnk_18[0x10].mVisible = subFileSet->mUnk_18[0x11].mVisible;
    gmenu_setSeqArcIndex(-1);
    heap_adjustSubFrmHeap(gMultiSelectMember->mHeap);
}

void func_02031280(void *parentHeap, void *mainOam, void *subOam) {
    Unk02174e58_24 *mainFileSet;
    Unk02174e58_24 *subFileSet;
    u16 nameBuffer[12];
    s32 n0;
    s32 mainCellCount;
    s32 subLabelCount;
    s32 subCellCount;
    s32 i;
    void *bannerMessage;

    InitMultiSelectMember(parentHeap, mainOam, subOam);
    mainFileSet = &gMultiSelectMember->mCellFileSets[0];
    subFileSet = &gMultiSelectMember->mCellFileSets[1];
    gMultiSelectMember->mUnk_70 = 2;
    gMultiSelectMember->mUnk_84 = func_0204fe90(func_0202f14c()->mUnk_00);
    nameBuffer[0] = 0;
    MIi_CpuClear16(nameBuffer[0], &nameBuffer[1], 0x16);
    if (gMultiSelectMember->mUnk_84 == 0 && func_0204ff14(func_0202f14c()->mUnk_00, &nameBuffer[1]) != 0) {
        nameBuffer[11] = 0;
        jn_ui_212426C(1, data_02153d7c[0].mLabelIndex, subFileSet->mUnk_14, &nameBuffer[1], subFileSet->mUnk_0c,
                      subFileSet->mUnk_18);
        gMultiSelectMember->mUnk_80 = TRUE;
    }
    subFileSet->mUnk_18[0x11].mVisible = 0;
    subFileSet->mUnk_18[0x10].mVisible = subFileSet->mUnk_18[0x11].mVisible;
    bannerMessage = jn_msg_getMessage(gMultiSelectMember->mBannerMessages, 10);
    if (gMultiSelectMember->mUnk_84 != 0) {
        SetupTxtSystemSubTextEx(bannerMessage, 0, 0, 1, 0, 1);
    } else {
        CreateMainMessageBoxBig(bannerMessage, 0, 0, 1, 0, 0, 0);
    }
    if (gMultiSelectMember->mUnk_84 != 0) {
        n0 = mainFileSet->mUnk_14->mUnk_06;
        mainCellCount = mainFileSet->mUnk_0c->mUnk_06;
        subLabelCount = subFileSet->mUnk_14->mUnk_06;
        subCellCount = subFileSet->mUnk_0c->mUnk_06;
        i = 0;
        mainFileSet->mUnk_18[0xb].mVisible = 0;
        mainFileSet->mUnk_18[0xa].mVisible = mainFileSet->mUnk_18[0xb].mVisible;
        mainFileSet->mUnk_18[9].mVisible = mainFileSet->mUnk_18[0xa].mVisible;
        mainFileSet->mUnk_18[8].mVisible = mainFileSet->mUnk_18[9].mVisible;
        mainFileSet->mUnk_18[7].mVisible = mainFileSet->mUnk_18[8].mVisible;
        mainFileSet->mUnk_18[6].mVisible = mainFileSet->mUnk_18[7].mVisible;
        mainFileSet->mUnk_18[5].mVisible = mainFileSet->mUnk_18[6].mVisible;
        mainFileSet->mUnk_18[4].mVisible = mainFileSet->mUnk_18[5].mVisible;
        mainFileSet->mUnk_18[3].mVisible = mainFileSet->mUnk_18[4].mVisible;
        for (i = 0; i < 8; i++) {
            subFileSet->mUnk_18[gMultiSelectMember->mRows[i].mSecondCellIndex].mVisible = 0;
            subFileSet->mUnk_18[gMultiSelectMember->mRows[i].mFirstCellIndex].mVisible =
                subFileSet->mUnk_18[gMultiSelectMember->mRows[i].mSecondCellIndex].mVisible;
        }
        for (i = 0; i < n0; i++) {
            mainFileSet->mUnk_18[i + mainCellCount].mVisible = 0;
        }
        i = 0;
        n0 = subCellCount + subLabelCount;
        for (; i < n0; i++) {
            subFileSet->mUnk_18[i].mVisible = 0;
        }
    }
    gmenu_setSeqArcIndex(-1);
    heap_adjustSubFrmHeap(gMultiSelectMember->mHeap);
}

#pragma thumb off

#pragma thumb on

u32 func_02031268(void) {
    if (gMultiSelectMember->mInterpolations[2].mState == 1) {
        return 1;
    }
    return 0;
}

u32 func_02031250(void) {
    if (gMultiSelectMember->mInterpolations[2].mState == 3) {
        return 1;
    }
    return 0;
}

void DrawMultiSelectMember(void) {
    int screenIndex;
    Unk02174e58_24 *cellFileSet;
    if (gMultiSelectMember->mState != 6) {
        screenIndex = 0;
        do {
            cellFileSet = &gMultiSelectMember->mCellFileSets[screenIndex];
            jn_ui_renderElements(cellFileSet->mUnk_0c, cellFileSet->mUnk_08, cellFileSet->mUnk_14,
                            (&gMultiSelectMember->mMainOam)[screenIndex], cellFileSet->mUnk_18);
            screenIndex++;
        } while (screenIndex < 2);
    }
}

#pragma thumb off

#pragma thumb on

s32 func_02030ea4(Unk02030b18 *sceneNumbers) {
    Unk02174e58_24 *subFileSet;
    s32 result;
    s32 previousChildCount;
    u16 slotIndex;
    s32 rectIndex;
    s32 touchInReturnRect;
    u32 pairIsNew;
    u32 pairRecentlyGone;
    u32 hasPair;
    s32 x;
    s32 pairY;

    result = -1;
    slotIndex = input_getDirectInputUnitId();
    subFileSet = &gMultiSelectMember->mCellFileSets[1];
    previousChildCount = gMultiSelectMember->mChildCount;
    if (gMultiSelectMember->mTimer > 0) {
        gMultiSelectMember->mTimer = gMultiSelectMember->mTimer - 1;
    }
    func_02031960();
    if (gMultiSelectMember->mState != 0 && gMultiSelectMember->mState != 3 && gMultiSelectMember->mState != 4 &&
        gMultiSelectMember->mState != 5 && gMultiSelectMember->mState != 6) {
        if (gStruct217AA00 == NULL) {
            x = 0;
        } else {
            x = gStruct217AA00->mUnk_0000;
        }
        if (x == 1) {
            if ((gStruct217AA00->mUnk_0454 & 0x40) != 0) {
                x = gStruct217AA00->mUnk_1699;
            } else {
                x = gStruct217AA00->mUnk_0044.mChildCount;
            }
        } else {
            x = 0;
        }
        gMultiSelectMember->mChildCount = x;
        if (gMultiSelectMember->mChildCount != previousChildCount) {
            PrintMultiSelectMemberNames();
            if (gMultiSelectMember->mChildCount > previousChildCount) {
                NNS_SndArcSetCurrent(&SDATFile);
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 2);
                NNS_SndArcSetCurrent(&gSdatFileSndArc);
            } else {
                NNS_SndArcSetCurrent(&SDATFile);
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 3);
                NNS_SndArcSetCurrent(&gSdatFileSndArc);
            }
        }
    }
    SetMultiSelectChildCountCellsVisible();
    func_02031ba4();
    AdvancePaletteBlend();
    if (gMultiSelectMember->mUnk_148 != FALSE) {
        gMultiSelectMember->mUnk_14c = gMultiSelectMember->mUnk_14c + 1;
        if (gMultiSelectMember->mUnk_14c > 0x96) {
            func_02108ddc();
            gMultiSelectMember->mUnk_148 = FALSE;
        }
    }
    switch (gMultiSelectMember->mState) {
        case 0:
            if (func_02031268() != 0) {
                gMultiSelectMember->mState = 1;
                subFileSet->mUnk_18[0x10].mVisible = 1;
                func_02031b30(1);
            }
            break;
        case 1:
            touchInReturnRect = 0;
            rectIndex = -1;
            pairIsNew = 0;
            pairRecentlyGone = 0;
            hasPair = data_02175674[slotIndex].mPressedBits;
            if (hasPair == 0 && data_02175680[slotIndex].mPressedBits < 5) {
                pairRecentlyGone = 1;
            }
            if (pairRecentlyGone == 0 && data_0217567c[slotIndex].mPressedBits == 0 && hasPair != 0) {
                pairIsNew = 1;
            }
            if (pairIsNew != 0) {
                x = data_02175670[slotIndex].mPressedBits;
                pairY = data_02175672[slotIndex].mPressedBits;
                touchInReturnRect = gmenu_checkSelectReturnTouch(x, pairY);
                rectIndex = jn_ui_checkTouch(subFileSet->mUnk_10, x, pairY);
            }
            if ((u16) (gInputUnits[slotIndex].mPressedBits & PAD_KEY_A) != 0 || rectIndex == 0) {
                if (gMultiSelectMember->mChildCount > 0 && gMultiSelectMember->mInterpolations[3].mState == 1) {
                    func_02031b30(0);
                    RequestSelectReturnState4();
                    StopPaletteBlend();
                    NNS_SndArcSetCurrent(&SDATFile);
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 6);
                    NNS_SndArcSetCurrent(&gSdatFileSndArc);
                    gMultiSelectMember->mUnk_78 = TRUE;
                    gMultiSelectMember->mUnk_148 = TRUE;
                    gMultiSelectMember->mState = 2;
                    break;
                }
            }
            if ((u16) (gInputUnits[slotIndex].mPressedBits & PAD_KEY_B) != 0 || touchInReturnRect != 0) {
                gMultiSelectMember->mUnk_6c = 1;
                gMultiSelectMember->mState = 3;
                gMultiSelectMember->mUnk_7c = TRUE;
                RequestTxtSystemClose();
                RequestSelectReturnState3WithSound(0);
                NNS_SndArcSetCurrent(&SDATFile);
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
                NNS_SndArcSetCurrent(&gSdatFileSndArc);
            }
            break;
        case 2:
            gMultiSelectMember->mState2Frames = gMultiSelectMember->mState2Frames + 1;
            if (gMultiSelectMember->mState2Frames >= 5) {
                func_02031b30(1);
                if (gMultiSelectMember->mUnk_70 == 11) {
                    gStruct217B488->mUnk_04 = 1;
                    gStruct217B488->mUnk_08 = 4;
                    if (sceneNumbers != NULL) {
                        sceneNumbers->mUnk_04 = 1;
                    }
                    gMultiSelectMember->mState2Frames = 0;
                    gMultiSelectMember->mState = 7;
                }
            }
            break;
        case 5:
            if (IsTxtSystemState2AfterState1() != 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x15);
            }
            if (GetTxtSystemDone() != 0) {
                RequestTxtSystemClose();
                gMultiSelectMember->mUnk_6c = 0;
                gMultiSelectMember->mState = 3;
            }
            break;
        case 3:
            if (gMultiSelectMember->mUnk_70 == 11) {
                interp_setState(&gMultiSelectMember->mInterpolations[0], 2);
                interp_setState(&gMultiSelectMember->mInterpolations[1], 2);
                interp_setState(&gMultiSelectMember->mInterpolations[2], 2);
                gMultiSelectMember->mState = 4;
            }
            break;
        case 4:
            if (func_02031250() != 0) {
                gMultiSelectMember->mState = 6;
            }
            break;
        case 6:
            result = gMultiSelectMember->mUnk_6c;
            break;
    }
    DrawMultiSelectMember();
    return result;
}

s32 func_02030b18(Unk02030b18 *sceneNumbers) {
    Unk02174e58_24 *subFileSet;
    s32 result;
    s32 touchInReturnRect;
    s32 previousChildCount;
    u16 slotIndex;
    u16 nameBuffer[12];
    BOOL x;
    u32 pairIsNew;
    u32 pairRecentlyGone;
    u32 hasPair;
    s32 y;

    result = -1;
    slotIndex = input_getDirectInputUnitId();
    touchInReturnRect = 0;
    subFileSet = &gMultiSelectMember->mCellFileSets[1];
    if (gMultiSelectMember->mTimer > 0) {
        gMultiSelectMember->mTimer = gMultiSelectMember->mTimer - 1;
    }
    func_020317a0();
    previousChildCount = gMultiSelectMember->mChildCount;
    if (gMultiSelectMember->mUnk_84 == 0 && gMultiSelectMember->mUnk_8c == FALSE) {
        gMultiSelectMember->mChildCount = CountMultiSelectChildren();
        if (gMultiSelectMember->mChildCount != previousChildCount) {
            PrintMultiSelectMemberNames();
            if (gMultiSelectMember->mUnk_88 == FALSE) {
                if (gMultiSelectMember->mChildCount > previousChildCount) {
                    NNS_SndArcSetCurrent(&SDATFile);
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 2);
                    NNS_SndArcSetCurrent(&gSdatFileSndArc);
                } else if (gMultiSelectMember->mChildCount < previousChildCount) {
                    NNS_SndArcSetCurrent(&SDATFile);
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 3);
                    NNS_SndArcSetCurrent(&gSdatFileSndArc);
                }
                gMultiSelectMember->mUnk_88 = FALSE;
            }
        }
        SetMultiSelectChildCountCellsVisible();
    }
    if (gMultiSelectMember->mUnk_84 == 0 && gMultiSelectMember->mUnk_80 == FALSE) {
        nameBuffer[0] = 0;
        MIi_CpuClear16(nameBuffer[0], &nameBuffer[1], 0x16);
        if (func_0204ff14(func_0202f14c()->mUnk_00, &nameBuffer[1]) != 0) {
            nameBuffer[11] = 0;
            jn_ui_212426C(1, data_02153d7c[0].mLabelIndex, subFileSet->mUnk_14, &nameBuffer[1], subFileSet->mUnk_0c,
                          subFileSet->mUnk_18);
            gMultiSelectMember->mUnk_80 = TRUE;
        }
    }
    func_02031ba4();
    if (gMultiSelectMember->mUnk_148 != FALSE) {
        gMultiSelectMember->mUnk_14c = gMultiSelectMember->mUnk_14c + 1;
        if (gMultiSelectMember->mUnk_14c > 0x96) {
            func_02108ddc();
            gMultiSelectMember->mUnk_148 = FALSE;
        }
    }
    switch (gMultiSelectMember->mState) {
        case 0:
            if (func_02031268() != 0) {
                gMultiSelectMember->mState = 1;
            }
            break;
        case 1:
            pairIsNew = 0;
            pairRecentlyGone = 0;
            hasPair = data_02175674[slotIndex].mPressedBits;
            if (hasPair == 0 && data_02175680[slotIndex].mPressedBits < 5) {
                pairRecentlyGone = 1;
            }
            if (pairRecentlyGone == 0 && data_0217567c[slotIndex].mPressedBits == 0 && hasPair != 0) {
                pairIsNew = 1;
            }
            if (pairIsNew != 0) {
                touchInReturnRect = gmenu_checkSelectReturnTouch(
                    data_02175670[slotIndex].mPressedBits, data_02175672[slotIndex].mPressedBits);
            }
            y = gMultiSelectMember->mUnk_90;
            if (y == 0) {
                switch (gStruct217AA00->mUnk_0004) {
                    case 7:
                    case 8:
                    case 9:
                    case 10:
                    case 11:
                        x = TRUE;
                        break;
                    default:
                        x = FALSE;
                        break;
                }
                if (x != FALSE) {
                    RequestSelectReturnState4();
                    interp_setState(&gMultiSelectMember->mInterpolations[0], 2);
                    NNS_SndArcSetCurrent(&SDATFile);
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 6);
                    NNS_SndArcSetCurrent(&gSdatFileSndArc);
                    gMultiSelectMember->mUnk_148 = TRUE;
                    gMultiSelectMember->mUnk_90 = 1;
                    break;
                }
            }
            if (gMultiSelectMember->mUnk_70 == 11) {
                gStruct217B488->mUnk_04 = 1;
                gStruct217B488->mUnk_08 = 4;
                if (sceneNumbers != NULL) {
                    sceneNumbers->mUnk_04 = 1;
                }
                gMultiSelectMember->mState = 7;
            } else if (y == 0) {
                if ((u16) (gInputUnits[slotIndex].mPressedBits & PAD_KEY_B) != 0 || touchInReturnRect != 0) {
                    gMultiSelectMember->mUnk_6c = 0;
                    gMultiSelectMember->mState = 3;
                    gMultiSelectMember->mUnk_7c = TRUE;
                    RequestTxtSystemClose();
                    RequestSelectReturnState3WithSound(0);
                    NNS_SndArcSetCurrent(&SDATFile);
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 3);
                    NNS_SndArcSetCurrent(&gSdatFileSndArc);
                }
            }
            break;
        case 5:
            if (IsTxtSystemState2AfterState1() != 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x15);
            }
            if (GetTxtSystemDone() != 0) {
                gMultiSelectMember->mUnk_6c = 0;
                gMultiSelectMember->mState = 3;
                RequestTxtSystemClose();
            }
            break;
        case 3:
            if (gMultiSelectMember->mUnk_70 == 11) {
                interp_setState(&gMultiSelectMember->mInterpolations[0], 2);
                interp_setState(&gMultiSelectMember->mInterpolations[1], 2);
                interp_setState(&gMultiSelectMember->mInterpolations[2], 2);
                gMultiSelectMember->mState = 4;
            }
            break;
        case 4:
            if (func_02031250() != 0) {
                gMultiSelectMember->mState = 6;
            }
            break;
        case 6:
            result = gMultiSelectMember->mUnk_6c;
            break;
    }
    DrawMultiSelectMember();
    return result;
}

#pragma thumb off

#pragma thumb on

void ReleaseMultiSelectMember(void) {
    SetTxtSystemBgOffsetRequested(0, 0);
    ClearPaletteBlendPointer();
    heap_destroySubHeap(gMultiSelectMember->mHeap);
    *&gMultiSelectMember = NULL;
}

#pragma thumb off

#pragma thumb on

void WriteMultiSelectMemberRegisters(void) {
    s32 displayBits;
    s32 interpolatedValue;

    displayBits = 0x17;
    interpolatedValue = interp_interpolate(&gMultiSelectMember->mInterpolations[2]);
    if (gMultiSelectMember->mUnk_84 == 0 && gMultiSelectMember->mState != 6) {
        displayBits |= 8;
    }
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | (displayBits << 8);
    reg_G2S_DB_BG3OFS = (-interpolatedValue << 16) & 0x1ff0000;
    if (interpolatedValue != 0) {
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffff1fff) | 0x2000;
        reg_G2S_DB_WININ = (u32) ((reg_G2S_DB_WININ & ~0x3f) | 0x1f) | 0x20;
        reg_G2S_DB_WINOUT = (u32) ((reg_G2S_DB_WINOUT & ~0x3f) | 7) | 0x20;
        reg_G2S_DB_WIN0H = 0xff;
        reg_G2S_DB_WIN0V = (interpolatedValue + 0xc0) & 0xff;
    } else {
        reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
    }
}

#pragma thumb off
