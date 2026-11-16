#include "Main/Unknown/code_0202a820.h"

#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02025ebc.h"
#include "Main/System/Heap.h"
#include "code_02148950.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_0202e4b0.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_0202bb80.h"
#include "Main/Unknown/code_0202db04.h"
#include "Main/Ui/ScrollList.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02121e24.h"
#include "Main/Unknown/code_02121e84.h"
#include "Main/Unknown/code_02122734.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/unk_0217d068.h"
#include "00/code_02181f98.h"
#include "code_0200f5ac.h"
#include "code_0201ea30.h"
#include "code_0201ea58.h"
#include "code_0212df7c.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02025f80.h"
#include "registers.h"

#pragma thumb on

// Sets the digit cells for the place of the kart among the karts that appear for the character and for how many appear.
void WriteKartPositionAndCount(s32 position, s32 kartCount) {
    CellFileSet *fileSet;
    s32 tens;
    s32 ones;

    tens = kartCount / 10 % 10;
    ones = kartCount % 10;
    fileSet = &gPlayerEntryList->mParts;
    fileSet->mCellTable[0x3c].mVisible = position >= 10 ? 1 : 0;
    func_02025c48(0x3c, position / 10 % 10 + 0x41, fileSet->mCellLayout);
    func_02025c48(0x3d, position % 10 + 0x41, fileSet->mCellLayout);
    if (kartCount >= 10) {
        tens += 0x4b;
        func_02025c48(0x3f, tens, fileSet->mCellLayout);
        func_02025c48(0x40, ones + 0x4b, fileSet->mCellLayout);
    } else {
        fileSet->mCellTable[0x40].mVisible = 0;
        func_02025c48(0x3f, ones + 0x4b, fileSet->mCellLayout);
    }
}

// List callback: action 1 prints the label of a row, action 0 sets the highlight value of the seven slots.
void RefreshCourseListRows(s32 action, s32 slot, s32 row, s32 selectedSlot) {
    CellFileSet *fileSet;
    void *text;
    s32 i;
    s32 k;

    fileSet = &gWiFiVSCourseSelect->mWiFiVSCourseSelectSParts;
    if (action == 1) {
        if (row == 0) {
            text = jn_msg_getMessage(gWiFiVSCourseSelect->mWiFiMessages, 0x1a);
        } else {
            text = jn_msg_getMessage(gWiFiVSCourseSelect->mWiFiMessages, mutil2_getCourseNameWifiMsgId(WifiCourseOrder[row - 1]));
        }
        jn_ui_212426C(1, slot, fileSet->mLabelLayout, text, fileSet->mCellLayout, fileSet->mCellTable);
    } else if (action == 0) {
        for (i = 0; i < 7; i++) {
            if (i == selectedSlot) {
                k = 0xe;
            } else {
                k = 0xf;
            }
            jn_ui_setLabelColorParam(i, k, fileSet->mLabelLayout, fileSet->mCellTable, fileSet->mCellLayout);
        }
    }
}

void func_0202b3f4(void) {
    CellFileSet *fileSet;
    s32 cellCount;
    s32 i;

    fileSet = &gWiFiVSCourseSelect->mWiFiVSCourseSelectMParts;
    cellCount = fileSet->mCellLayout->mUnk_06;
    for (i = 0; i < gWiFiVSCourseSelect->mPlayerCount; i++) {
        fileSet->mCellTable[gWiFiVSCourseSelectMLabelTextRows[i].mCellIndex].mOffsetY = mutil_interpolate(
            1, 0,
            0x60 - (((s16 *) jn_ui_getBnclElement(fileSet->mCellLayout, gWiFiVSCourseSelectMLabelTextRows[i].mCellIndex))[1]
                        << 20 >>
                    20),
            (*(struct WiFiVSCourseSelect **) &gWiFiVSCourseSelect)->mStateFrames, 0x3c);
        fileSet->mCellTable[cellCount + gWiFiVSCourseSelectMLabelTextRows[i].mLabelIndex].mOffsetY = mutil_interpolate(
            1, 0,
            0x60 - (((s16 *) jn_ui_getBnllElement(fileSet->mLabelLayout, gWiFiVSCourseSelectMLabelTextRows[i].mLabelIndex))[1]
                        << 20 >>
                    20),
            (*(struct WiFiVSCourseSelect **) &gWiFiVSCourseSelect)->mStateFrames, 0x3c);
    }
}

void ShowWiFiSessionCourse(void) {
    CellFileSet *fileSet;
    u16 cellCount;
    s32 i;
    s32 courseId;
    u16 *text;

    fileSet = &gWiFiVSCourseSelect->mWiFiVSCourseSelectMParts;
    cellCount = fileSet->mCellLayout->mUnk_06;
    courseId = GetWiFiSessionCourseId();
    text = jn_msg_getMessage(gWiFiVSCourseSelect->mCommonMessages, mutil2_getCourseNameCommonMsgId(courseId));
    for (i = 0; i < 4; i++) {
        fileSet->mCellTable[gWiFiVSCourseSelectMLabelTextRows[i].mCellIndex].mVisible = 0;
        fileSet->mCellTable[cellCount + gWiFiVSCourseSelectMLabelTextRows[i].mLabelIndex].mVisible =
            fileSet->mCellTable[gWiFiVSCourseSelectMLabelTextRows[i].mCellIndex].mVisible;
        fileSet->mCellTable[gWiFiVSCourseSelectMLabelTextRows[i].mCellIndex].mOffsetX = 0;
        fileSet->mCellTable[cellCount + gWiFiVSCourseSelectMLabelTextRows[i].mLabelIndex].mOffsetX =
            fileSet->mCellTable[gWiFiVSCourseSelectMLabelTextRows[i].mCellIndex].mOffsetX;
        interp_setState(&gWiFiVSCourseSelect->mRowInterpolations[i], 1);
    }
    fileSet->mCellTable[4].mVisible = 1;
    fileSet->mCellTable[gWiFiVSCourseSelectMLabelTextRows[0].mLabelIndex + cellCount].mVisible =
        fileSet->mCellTable[4].mVisible;
    fileSet->mCellTable[gWiFiVSCourseSelectMLabelTextRows[0].mLabelIndex + cellCount].mOffsetY += 2;
    jn_ui_212426C(0, gWiFiVSCourseSelectMLabelTextRows[0].mLabelIndex, fileSet->mLabelLayout, text,
                  fileSet->mCellLayout, fileSet->mCellTable);
    gWiFiVSCourseSelect->mCourseId = courseId;
    gWiFiVSCourseSelect->mCourseMessageIndex = mutil2_getCourseNameCommonMsgId(courseId);
    gWiFiVSCourseSelect->mUnk_14c[0] = text[0];
    gWiFiVSCourseSelect->mUnk_14c[1] = text[1];
    gWiFiVSCourseSelect->mUnk_14c[2] = text[2];
    gWiFiVSCourseSelect->mUnk_14c[3] = text[3];
}

void AdvanceSubCellsOffsetY(void) {
    CellFileSet *fileSet;
    s32 entryCount;
    s32 i;

    fileSet = &gWiFiVSCourseSelect->mWiFiVSCourseSelectSParts;
    entryCount = fileSet->mCellLayout->mUnk_06 + fileSet->mLabelLayout->mUnk_06;
    interp_update(&gWiFiVSCourseSelect->mInterpolations[0]);
    gWiFiVSCourseSelect->mSubOffsetY = interp_interpolate(&gWiFiVSCourseSelect->mInterpolations[0]);
    for (i = 0; i < entryCount; i++) {
        fileSet->mCellTable[i].mOffsetY = gWiFiVSCourseSelect->mSubOffsetY;
    }
}

void AdvancePickedCourseRows(void) {
    s32 i;
    CellFileSet *fileSet;
    s32 cellCount;
    s32 pickedCourseId;
    void *text;

    fileSet = &gWiFiVSCourseSelect->mWiFiVSCourseSelectMParts;
    cellCount = fileSet->mCellLayout->mUnk_06;
    for (i = 0; i < gWiFiVSCourseSelect->mPlayerCount; i++) {
        interp_update(&gWiFiVSCourseSelect->mRowInterpolations[i]);
        if (GetIndexOfPackedIndex(i) >= 0) {
            pickedCourseId = GetWiFiSessionPickedCourseId((u8) GetIndexOfPackedIndex(i));
        } else {
            pickedCourseId = 0;
        }
        switch (gWiFiVSCourseSelect->mState) {
            case 0:
            case 1:
            case 2:
                if (pickedCourseId != 0 && pickedCourseId != gWiFiVSCourseSelect->mShownCourseIds[i]) {
                    text = jn_msg_getMessage(gWiFiVSCourseSelect->mCommonMessages, mutil2_getCourseNameCommonMsgId(pickedCourseId));
                    jn_ui_212426C(0, gWiFiVSCourseSelectMLabelTextRows[i].mLabelIndex, fileSet->mLabelLayout, text,
                                  fileSet->mCellLayout, fileSet->mCellTable);
                    gWiFiVSCourseSelect->mShownCourseIds[i] = pickedCourseId;
                    interp_setState(&gWiFiVSCourseSelect->mRowInterpolations[i], 0);
                    if (gWiFiVSCourseSelect->mEntryIndex != i) {
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x208);
                    }
                }
                break;
        }
        fileSet->mCellTable[cellCount + gWiFiVSCourseSelectMLabelTextRows[i].mLabelIndex].mOffsetX =
            interp_interpolate(&gWiFiVSCourseSelect->mRowInterpolations[i]);
        fileSet->mCellTable[gCourseRowCellIndices[i]].mOffsetX =
            fileSet->mCellTable[cellCount + gWiFiVSCourseSelectMLabelTextRows[i].mLabelIndex].mOffsetX;
    }
}

void AdvanceWiFiVSCourseSelectTimer(void) {
    s32 seconds;
    CellFileSet *fileSet;
    Unk0201ea30 *cellLayout;
    void *cells;

    seconds = 0;
    fileSet = &gWiFiVSCourseSelect->mWiFiVSCourseSelectMParts;
    interp_update(&gWiFiVSCourseSelect->mInterpolations[2]);
    fileSet->mCellTable[16].mOffsetX = interp_interpolate(&gWiFiVSCourseSelect->mInterpolations[2]);
    fileSet->mCellTable[15].mOffsetX = fileSet->mCellTable[16].mOffsetX;
    switch (gWiFiVSCourseSelect->mState) {
        case 0:
        case 1:
        case 2:
            if (gWiFiVSCourseSelect->mTimer != 0) {
                gWiFiVSCourseSelect->mTimer--;
                seconds = (gWiFiVSCourseSelect->mTimer + 0x3c) / 0x3c;
                fileSet->mCellTable[15].mVisible = seconds >= 10 ? 1 : 0;
                if (gWiFiVSCourseSelect->mTimer == 0) {
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x51);
                } else if ((gWiFiVSCourseSelect->mTimer + 0x3c) % 0x3c == 0 && seconds <= 4) {
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x50);
                }
            }
            cellLayout = fileSet->mCellLayout;
            cells = fileSet->mCells;
            jn_ui_fillPlaceholder(gCourseTimerDigitCellIndices[seconds / 10 % 10], cells, fileSet->mChars, cellLayout, 0, 0xf,
                           cells, cellLayout);
            cellLayout = fileSet->mCellLayout;
            cells = fileSet->mCells;
            jn_ui_fillPlaceholder(gCourseTimerDigitCellIndices[seconds % 10], cells, fileSet->mChars, cellLayout, 0, 0x10,
                           cells, cellLayout);
            break;
    }
}

// Picks a course index at random that none of the stored course ids of the earlier races has.
s32 PickRandomCourseIndexNotRaced(void) {
    WiFiVSCourseSelect *courseSelect;
    RandomState64 *random;
    Unk0217b488 *d;
    s32 i;
    s32 courseIndex;
    BOOL notRaced;
    u32 courseId;
    u32 *cursor;

    courseSelect = gWiFiVSCourseSelect;
    random = &courseSelect->mRandom;
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    courseIndex = (u16) (random->mValue >> 32 >> 20) % 20;
    d = gStruct217B488;
    do {
        notRaced = TRUE;
        courseIndex = (courseIndex + 1) % 20;
        i = 0;
        cursor = (u32 *) d;
        courseId = WifiCourseOrder[courseIndex];
        for (; i < 4; i++) {
            if (cursor[0x17] == courseId) {
                notRaced = FALSE;
                break;
            }
            cursor++;
        }
    } while (notRaced == FALSE);
    return courseIndex;
}

void InitWiFiVSCourseSelect(void *parentHeap, void *mainOam, void *subOam) {
    void *heap;
    CellFileSet *mainFileSet;
    CellFileSet *subFileSet;
    RandomState64 *random;
    u32 tick;
    u32 seed;
    u32 objSizeLeft;
    s32 i;
    s32 n;
    s32 subCellCount;
    s32 j;
    s32 labelIndex;
    LayoutTableEntry *cellTable;
    u16 w[2];

    heap = heap_createSubFrmHeap(parentHeap);
    gWiFiVSCourseSelect = heap_alloc(heap, 0x158);
    MemFillWordsByBlock_inline(gWiFiVSCourseSelect, 0x158);
    gWiFiVSCourseSelect->mHeap = heap;
    gWiFiVSCourseSelect->mOamLists[0] = mainOam;
    gWiFiVSCourseSelect->mOamLists[1] = subOam;
    gWiFiVSCourseSelect->mCommonMessages = arc_get2dArcFile(aCommon_bmg_15);
    gWiFiVSCourseSelect->mWiFiMessages = arc_getSceneArcFile(aWifi_bmg);
    tick = OS_GetTick();
    seed = (tick << 16) + (u32) OS_GetTick();
    random = &gWiFiVSCourseSelect->mRandom;
    random->mValue = seed;
    random->mMultiplier = 0x5d588b656c078965;
    random->mIncrement = 0x269ec3;
    gWiFiVSCourseSelect->mPlayerCount = GetSessionKartCount();
    gWiFiVSCourseSelect->mEntryIndex = menu_getRaceConfigField10C();
    gWiFiVSCourseSelect->mTimer = 0x4b0;
    gWiFiVSCourseSelect->mSubOffsetY = -0xc0;
    for (i = 0; i < 4; i++) {
        gWiFiVSCourseSelect->mShownCourseIds[i] = 0;
        interp_init(&gWiFiVSCourseSelect->mRowInterpolations[i], 3, 10, 0xfc, 0);
    }
    interp_init(&gWiFiVSCourseSelect->mInterpolations[1], 0, 10, -0x40, 0);
    interp_init(&gWiFiVSCourseSelect->mInterpolations[0], 0, 10, -0xc0, 0);
    interp_init(&gWiFiVSCourseSelect->mInterpolations[2], 0, 10, 0x40, 0);
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0xc00;
    mutil2_initBgGraphics(0, gWiFiVSCourseSelect, aWifi_vs_cou_11, aWifi_vs_cou_12,
                  aWifi_vs_cou_13, 0, arc_getSceneArcFile);
    mainFileSet = &gWiFiVSCourseSelect->mWiFiVSCourseSelectMParts;
    objSizeLeft = GX_GetSizeOfOBJ();
    mutil2_loadLayout(mainFileSet, aWifi_vs_cou_15, aWifi_vs_cou_14,
                      aWifi_vs_cou_16, aWifi_vs_cou_17, aWifi_vs_cou_18, NULL,
                      arc_getSceneArcFile);
    mutil2_initLayout(0, gWiFiVSCourseSelect->mHeap, mainFileSet);
    n = mainFileSet->mCellLayout->mUnk_06;
    for (i = 0; i < n; i++) {
        jn_ui_setCellPriority(i, 1, mainFileSet->mCells, mainFileSet->mCellLayout);
    }
    for (i = 0; i < mainFileSet->mLabelLayout->mUnk_06; i++) {
        objSizeLeft -= mutil2_initLabel(0, gWiFiVSCourseSelect->mHeap, mainFileSet, &gWiFiVSCourseSelectMLabelTextRows[i],
                                     objSizeLeft);
    }
    for (i = gWiFiVSCourseSelect->mPlayerCount; i < 4; i++) {
        mainFileSet->mCellTable[gCourseRowCellIndices[i]].mVisible = 0;
        mainFileSet->mCellTable[n + gWiFiVSCourseSelectMLabelTextRows[i].mLabelIndex].mVisible = 0;
    }
    for (i = 0; i < n; i++) {
        jn_ui_setCellPriority(i, 2, mainFileSet->mCells, mainFileSet->mCellLayout);
    }
    mainFileSet->mCellTable[4].mOffsetY = 0x60 - (((s16 *) jn_ui_getBnclElement(mainFileSet->mCellLayout, 4))[1] << 20 >> 20);
    mainFileSet->mCellTable[4].mVisible = 0;
    mutil2_initBgGraphics(1, &gWiFiVSCourseSelect->mWiFiVSCourseSelectMBAndSBParts[1], aWifi_vs_cou_19,
                  aWifi_vs_cou_20, aWifi_vs_cou_21, 3, arc_getSceneArcFile);
    subFileSet = &gWiFiVSCourseSelect->mWiFiVSCourseSelectSParts;
    objSizeLeft = GX_GetSizeOfSubOBJ();
    mutil2_loadLayout(subFileSet, aWifi_vs_cou_22, aWifi_vs_cou_23,
                      aWifi_vs_cou_24, aWifi_vs_cou_25, aWifi_vs_cou_26,
                      aWifi_vs_cou_27, arc_getSceneArcFile);
    mutil2_initLayout(1, gWiFiVSCourseSelect->mHeap, subFileSet);
    subCellCount = subFileSet->mCellLayout->mUnk_06;
    for (j = 0; j < subCellCount; j++) {
        jn_ui_setCellPriority(j, 1, subFileSet->mCells, subFileSet->mCellLayout);
    }
    for (j = 0; j < subFileSet->mLabelLayout->mUnk_06; j++) {
        objSizeLeft -= mutil2_initLabel(1, gWiFiVSCourseSelect->mHeap, subFileSet, &gWiFiVSCourseSelectSLabelTextRows[j],
                                     objSizeLeft);
    }
    for (j = 0; j < subCellCount; j++) {
        jn_ui_setCellPriority(j, 2, subFileSet->mCells, subFileSet->mCellLayout);
    }
    for (i = 0; i < 7; i++) {
        n = gWiFiVSCourseSelectSLabelTextRows[i].mCellIndex;
        labelIndex = gWiFiVSCourseSelectSLabelTextRows[i].mLabelIndex;
        cellTable = subFileSet->mCellTable;
        mutil2_setElementPositionFromBncl(n, cellTable + n, subFileSet->mCellLayout);
        mutil2_setElementPositionFromBnll(labelIndex, cellTable + labelIndex + subCellCount, subFileSet->mLabelLayout);
    }
    mutil2_setElementPositionFromBncl(7, subFileSet->mCellTable + 7, subFileSet->mCellLayout);
    w[0] = 0;
    w[1] = subCellCount;
    InitScrollList(gWiFiVSCourseSelect->mHeap, 2, w, 7, 8, 0x7c, subFileSet->mCellTable, subFileSet->mRects,
                   (u8 *) gWiFiVSCourseSelect->mWiFiVSCourseSelectMBAndSBParts[1].mScreenMaps[3] + 0xc, 5, 6, 0, 0x15,
                   RefreshCourseListRows);
    heap_adjustSubFrmHeap(gWiFiVSCourseSelect->mHeap);
}

s32 AdvanceWiFiVSCourseSelect(void) {
    WiFiVSCourseSelect *courseSelect;
    CellFileSet *fileSets;
    s32 result = 0;
    s32 i;
    s32 v;

    AdvanceScrollList();
    AdvancePickedCourseRows();
    switch (gWiFiVSCourseSelect->mState) {
        case 0:
            if (mbright_isFadedIn() == 0) {
                break;
            }
            if (gWiFiVSCourseSelect->mInterpolations[0].mState == 1) {
                gWiFiVSCourseSelect->mState = 1;
            }
            AdvanceSubCellsOffsetY();
            break;
        case 1:
            if (IsScrollListPickStarted() != 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x208);
            }
            if (IsScrollListPickFinished() == 0 && gWiFiVSCourseSelect->mTimer != 0) {
                break;
            }
            v = GetScrollListSelectedRow();
            if (v == 0) {
                v = PickRandomCourseIndexNotRaced();
            } else {
                v--;
            }
            SetWiFiSessionOwnPickedCourseId(WifiCourseOrder[v]);
            gWiFiVSCourseSelect->mState = 2;
            gWiFiVSCourseSelect->mUnk_0b0 = 1;
            SetScrollListEnabled(0);
            break;
        case 2:
            if (func_02121cd0() != 0) {
                gWiFiVSCourseSelect->mState = 3;
                interp_setState(&gWiFiVSCourseSelect->mInterpolations[2], 2);
            }
            break;
        case 3:
            gWiFiVSCourseSelect->mStateFrames++;
            if (gWiFiVSCourseSelect->mStateFrames > 0x3c) {
                StartFadeToFadedPositiveOneScreen(0x3c, 1);
                gWiFiVSCourseSelect->mState = 4;
                gWiFiVSCourseSelect->mStateFrames = 0;
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x209);
            }
            break;
        case 4:
            gWiFiVSCourseSelect->mStateFrames++;
            if (gWiFiVSCourseSelect->mStateFrames <= 0x3c) {
                func_0202b3f4();
            } else {
                StartFadeToClearOneScreen(10, 1);
                gWiFiVSCourseSelect->mState = 5;
                gWiFiVSCourseSelect->mStateFrames = 0;
                ShowWiFiSessionCourse();
            }
            break;
        case 5:
            gWiFiVSCourseSelect->mStateFrames++;
            if (gWiFiVSCourseSelect->mStateFrames > 0x3c) {
                mbright_fadeToBlack(10);
                gWiFiVSCourseSelect->mState = 6;
                gWiFiVSCourseSelect->mStateFrames = 0;
            }
            break;
        case 6:
            gWiFiVSCourseSelect->mStateFrames++;
            if (gWiFiVSCourseSelect->mStateFrames > 10) {
                gWiFiVSCourseSelect->mState = 7;
                gWiFiVSCourseSelect->mStateFrames = 0;
            }
            break;
        case 7:
            result = gWiFiVSCourseSelect->mUnk_0b0;
            break;
    }
    AdvanceWiFiVSCourseSelectTimer();
    interp_update(&gWiFiVSCourseSelect->mInterpolations[1]);
    for (i = 0; i < 2; i++) {
        courseSelect = gWiFiVSCourseSelect;
        fileSets = &courseSelect->mWiFiVSCourseSelectMParts;
        jn_ui_renderElements(fileSets[i].mCellLayout, fileSets[i].mCells, fileSets[i].mLabelLayout,
                        courseSelect->mOamLists[i], fileSets[i].mCellTable);
    }
    return result;
}

#pragma thumb off

#pragma thumb on

void ReleaseWiFiVSCourseSelect(void) {
    heap_destroySubHeap(gWiFiVSCourseSelect->mHeap);
    *&gWiFiVSCourseSelect = NULL;
}

#pragma thumb off

#pragma thumb on

void WriteWiFiVSCourseSelectRegisters(void) {
    s32 window0V;

    GX_SetGraphicsMode(1, 0, 0);
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | 0x1a00;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 2;
    reg_G2_BG0OFS = (-interp_interpolate(&gWiFiVSCourseSelect->mInterpolations[1]) << 16) & 0x1ff0000;
    reg_G2S_DB_BG3OFS = (-gWiFiVSCourseSelect->mSubOffsetY << 16) & 0x1ff0000;
    if (gWiFiVSCourseSelect->mSubOffsetY != 0) {
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffff1fff) | 0x2000;
        reg_G2S_DB_WININ = (u32) ((reg_G2S_DB_WININ & ~0x3f) | 0x1f) | 0x20;
        reg_G2S_DB_WINOUT = (u32) ((reg_G2S_DB_WINOUT & ~0x3f) | 7) | 0x20;
        window0V = gWiFiVSCourseSelect->mSubOffsetY + 0xc0;
        reg_G2S_DB_WIN0H = 0xff;
        reg_G2S_DB_WIN0V = window0V & 0xff;
    } else {
        reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
    }
}

#pragma thumb off
