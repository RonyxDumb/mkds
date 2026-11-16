#include "Main/Unknown/code_02119e14.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02060004.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020d0efc.h"
#include "registers.h"
#include "Main/Scene/SelectCupM.h"
#include "Main/Unknown/code_0211b23c.h"
#include "Main/Unknown/code_0211ac88.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/code_0212b1a8.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02016468.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020d0000.h"
#include "Main/Unknown/code_02116d24.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_0211ac70.h"
#include "Main/Unknown/code_0211b224.h"
#include "Main/Unknown/code_0211de00.h"
#include "Main/Unknown/code_0211e0c4.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02124bc8.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/code_02128244.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_0212b000.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0202bb80.h"

#pragma thumb on

void AdvanceSelectRaceRuleState6(void) {
    if (GetSelectChoisesDone() != 0) {
        RequestSelectRaceRuleState7();
        switch (GetSelectChoisesIndex()) {
            case 0:
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 7);
                break;
            case -1:
            case 1:
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x10);
                break;
        }
    }
}

void AdvanceSelectRaceRuleState7(void) {
    if (IsSelectChoisesState0NoState1Request() != 0) {
        switch (GetSelectChoisesIndex()) {
            case 0:
                RequestSelectRaceRuleState8();
                gSelectRaceRule->mResult = 1;
                func_0202b7c0(3);
                RequestSelectReturnState4();
                break;
            case -1:
            case 1:
                RequestSelectRaceRuleState3();
                break;
        }
    }
}

void AdvanceSelectRaceRuleState8(void) {
    SelectRaceRule *selectRaceRule;
    s32 i;
    s16 returnOffsetY;
    s16 rowsOffsetY;
    s32 j;
    s32 c;
    gSelectRaceRule->mStateFrames++;
    selectRaceRule = gSelectRaceRule;
    c = mutil_interpolate(1, 0, -192, selectRaceRule->mStateFrames, 10);
    rowsOffsetY = selectRaceRule->mOffsetY + c;
    returnOffsetY = -LookupSelectReturnState4Bg2Offset(selectRaceRule->mStateFrames);
    gSelectRaceRule->mBg3Offset = rowsOffsetY;
    c = gSelectRaceRule->mBncl->field6;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mTable[data_0215cd88[i][j]].mOffsetY = rowsOffsetY;
            gSelectRaceRule->mTable[data_0215cdb0[i][j]].mOffsetY = rowsOffsetY;
            gSelectRaceRule->mTable[data_0215cdc4[i][j]].mOffsetY = rowsOffsetY;
        }
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mTable[c + gSelectRaceRuleRowEntries[i].mEntryIndices[j]].mOffsetY = rowsOffsetY;
        }
    }
    gSelectRaceRule->mTable[c + 10].mOffsetY = rowsOffsetY;
    gSelectRaceRule->mTable[c + 12].mOffsetY = rowsOffsetY;
    gSelectRaceRule->mTable[34].mOffsetY = rowsOffsetY;
    gSelectRaceRule->mTable[37].mOffsetY = rowsOffsetY;
    gSelectRaceRule->mTable[35].mOffsetY = rowsOffsetY;
    gSelectRaceRule->mTable[38].mOffsetY = rowsOffsetY;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mTable[data_0215ccac[i][j]].mOffsetY = rowsOffsetY;
        }
    }
    if (gSystemData->field20 != 2) {
        gSelectRaceRule->mTable[40].mOffsetY = returnOffsetY;
        gSelectRaceRule->mTable[41].mOffsetY = returnOffsetY;
        gSelectRaceRule->mTable[c + 13].mOffsetY = returnOffsetY;
        c += 8;
        gSelectRaceRule->mTable[c].mOffsetY = rowsOffsetY;
        gSelectRaceRule->mTable[30].mOffsetY = rowsOffsetY;
        gSelectRaceRule->mTable[31].mOffsetY = rowsOffsetY;
    } else {
        gSelectRaceRule->mTable[42].mOffsetY = returnOffsetY;
        c += 14;
        gSelectRaceRule->mTable[c].mOffsetY = returnOffsetY;
    }
}

void func_0211a964(s32 labelIndex) {
    s32 tableIndex;
    tableIndex = gSelectRaceRule->mBncl->field6 + labelIndex;
    gSelectRaceRule->mTable[tableIndex].mOffsetY++;
    jn_ui_setLabelColorParam(labelIndex, 1, gSelectRaceRule->mBnll, gSelectRaceRule->mTable, gSelectRaceRule->mBncl);
    jn_ui_renderElement(tableIndex, gSelectRaceRule->mBncl, gSelectRaceRule->mNcer, gSelectRaceRule->mBnll,
                         gSelectRaceRule->mOamList, gSelectRaceRule->mTable);
    gSelectRaceRule->mTable[tableIndex].mOffsetY--;
    jn_ui_setLabelColorParam(labelIndex, 0, gSelectRaceRule->mBnll, gSelectRaceRule->mTable, gSelectRaceRule->mBncl);
}

void func_0211a908(s32 row) {
    if (row == 3) {
        if (gSystemData->field20 != 2) {
            func_0211a964(data_0215cd4e[row * 2]);
        }
        func_0211a964(10);
    } else if (row == 4) {
        func_0211a964(data_0215cd4e[row * 2]);
        func_0211a964(12);
    } else {
        func_0211a964(data_0215cd4e[row * 2]);
    }
}

s32 AdvanceSelectRaceRule(void) {
    SelectRaceRule *selectRaceRule;
    s32 i;
    gSelectRaceRule->mState = gSelectRaceRule->mNextState;
    gSelectRaceRule->mPrevRow = gSelectRaceRule->mRow;
    gSelectRaceRule->mPrevOnButton = gSelectRaceRule->mOnButton;
    switch (gSelectRaceRule->mState) {
        case 0:
            AdvanceSelectRaceRuleState0();
            break;
        case 1:
            AdvanceSelectRaceRuleState1();
            break;
        case 2:
            AdvanceSelectRaceRuleState2();
            break;
        case 3:
            AdvanceSelectRaceRuleState3();
            break;
        case 4:
            AdvanceSelectRaceRuleState4();
            break;
        case 5:
            AdvanceSelectRaceRuleState5();
            break;
        case 6:
            AdvanceSelectRaceRuleState6();
            break;
        case 7:
            AdvanceSelectRaceRuleState7();
            break;
        case 8:
            AdvanceSelectRaceRuleState8();
            break;
    }
    if (gSystemData->field20 == 2) {
        wait_update();
    }
    switch (gSelectRaceRule->mRowValues[4]) {
        case 0:
            SetPlayerEntryListUseTeams(0);
            break;
        case 1:
        case 2:
            SetPlayerEntryListUseTeams(1);
            break;
    }
    AdvancePlayerEntryList();
    if (((Unk027ffc40 *) 0x027ffc40)->field0 != 2) {
        AdvancePaletteBlend();
    }
    AdvanceSelectRaceRuleHighlight();
    AdvanceSelectRaceRuleValueObjects();
    func_0211c0cc();
    selectRaceRule = gSelectRaceRule;
    jn_ui_renderElements(selectRaceRule->mBncl, selectRaceRule->mNcer, selectRaceRule->mBnll, selectRaceRule->mOamList,
                    selectRaceRule->mTable);
    for (i = 0; i < 5; i++) {
        func_0211a908(i);
    }
    selectRaceRule = gSelectRaceRule;
    if (selectRaceRule->mState == 8) {
        if (selectRaceRule->mResult == 1 && (selectRaceRule->mMode == 3 || selectRaceRule->mRowValues[2] == 1)) {
            if (selectRaceRule->mStateFrames >= 10 && IsSelectReturnState0NoState1Request() != 0) {
                return gSelectRaceRule->mResult;
            }
        } else if (selectRaceRule->mStateFrames >= 10) {
            return selectRaceRule->mResult;
        }
    }
    return 0;
}

void WriteSelectRaceRuleRegisters(void) {
    reg_G2S_DB_BG3OFS = (-gSelectRaceRule->mBg3Offset << 16) & 0x1ff0000;
    WritePlayerEntryListRegisters();
}

void LoadSelectCupCourseData(void) {
    Ncgr *cellChars = NULL;
    Unk02021dc8 *cells = NULL;
    Nclr *cellPalette = NULL;
    Ncgr *bgChars = NULL;
    Nscr *screenMap = NULL;
    Nclr *bgPalette = NULL;
    if (((Unk027ffc40 *) 0x027ffc40)->field0 != 2) {
        g2du_unpackCharacterDataBG(&bgChars, arc_getSceneArcFile(data_0216d894));
        g2du_unpackPaletteData(&bgPalette, arc_getSceneArcFile(data_0216d88c));
        g2du_unpackScreenData(&screenMap, arc_getSceneArcFile(data_0216d8a4));
        g2du_unpackCharacterDataBG(&bgChars, arc_getSceneArcFile(data_0216d87c));
        g2du_unpackPaletteData(&bgPalette, arc_getSceneArcFile(data_0216d86c));
        g2du_unpackScreenData(&screenMap, arc_getSceneArcFile(data_0216d884));
        g2du_unpackCharacterData(&cellChars, arc_getSceneArcFile(data_0216d8a0));
        g2du_unpackCellBankData(&cells, arc_getSceneArcFile(data_0216d890));
        g2du_unpackPaletteData(&cellPalette, arc_getSceneArcFile(data_0216d878));
    }
}

void LocateAndQueueSelectCupCourse(void) {
    Ncgr *courseCellChars = NULL;
    Nclr *courseCellPalette = NULL;
    Ncgr *cupCellChars = NULL;
    Nclr *cupCellPalette = NULL;
    Ncgr *modeChars = NULL;
    Nscr *modeScreenMap = NULL;
    Nclr *modePalette = NULL;
    Ncgr *fixedChars = NULL;
    Nscr *fixedScreenMap = NULL;
    Nclr *fixedPalette = NULL;
    u16 *courseCellPaletteData;
    if (((Unk027ffc40 *) 0x027ffc40)->field0 == 2) {
        gSelectCupCourse->mSelectCupMBnbl = arc_getSceneArcFile(data_0216d864);
        return;
    }
    if (gSelectCupCourse->mMode == 0) {
        g2du_getCharacterDataBG(&modeChars, arc_getSceneArcFile(data_0216d894));
        g2du_getPaletteData(&modePalette, arc_getSceneArcFile(data_0216d88c));
        g2du_getScreenData(&modeScreenMap, arc_getSceneArcFile(data_0216d8a4));
    } else {
        g2du_getCharacterDataBG(&modeChars, arc_getSceneArcFile(data_0216d87c));
        g2du_getPaletteData(&modePalette, arc_getSceneArcFile(data_0216d86c));
        g2du_getScreenData(&modeScreenMap, arc_getSceneArcFile(data_0216d884));
    }
    g2du_getCharacterDataBG(&fixedChars, arc_getSceneArcFile(data_0216d874));
    g2du_getPaletteData(&fixedPalette, arc_getSceneArcFile(data_0216d854));
    g2du_getScreenData(&fixedScreenMap, arc_getSceneArcFile(data_0216d858));
    gSelectCupCourse->field24 = heap_alloc(gSelectCupCourse->mHeap, 0x800);
    if (gSelectCupCourse->mMode == 0) {
        gSelectCupCourse->mSelectCupCourseTaOrVsMBncl = arc_getSceneArcFile(data_0216d880);
        gSelectCupCourse->mSelectCupCourseTaOrVsMBnll = arc_getSceneArcFile(data_0216d89c);
    } else {
        gSelectCupCourse->mSelectCupCourseTaOrVsMBncl = arc_getSceneArcFile(data_0216d868);
        gSelectCupCourse->mSelectCupCourseTaOrVsMBnll = arc_getSceneArcFile(data_0216d870);
    }
    g2du_getCharacterData(&courseCellChars, arc_getSceneArcFile(data_0216d8a0));
    g2du_getCellBankData(&gSelectCupCourse->mSelectCupCourseMNcer, arc_getSceneArcFile(data_0216d890));
    g2du_getPaletteData(&courseCellPalette, arc_getSceneArcFile(data_0216d878));
    gSelectCupCourse->mSelectCupMBncl = arc_getSceneArcFile(data_0216d888);
    gSelectCupCourse->mSelectCupMBnbl = arc_getSceneArcFile(data_0216d864);
    gSelectCupCourse->mSelectCupMBnll = arc_getSceneArcFile(data_0216d860);
    g2du_getCharacterData(&cupCellChars, arc_getSceneArcFile(data_0216d898));
    g2du_getCellBankData(&gSelectCupCourse->mSelectCupMNcer, arc_getSceneArcFile(data_0216d8a8));
    g2du_getPaletteData(&cupCellPalette, arc_getSceneArcFile(data_0216d85c));
    courseCellPaletteData = courseCellPalette->mData;
    NNS_GfdRegisterNewVramTransferTask(4, 0, modeChars->mData, modeChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xf, 0, modePalette->mData, 0x140);
    NNS_GfdRegisterNewVramTransferTask(8, 0, modeScreenMap->mData, modeScreenMap->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(8, 0x800, gSelectCupCourse->field24, 0x800);
    if (menu_getPrevState() != 0x18 && menu_getPrevState() != 0xc) {
        NNS_GfdRegisterNewVramTransferTask(0x17, 0, fixedChars->mData, fixedChars->mDataSize);
        NNS_GfdRegisterNewVramTransferTask(0x1f, 0, fixedPalette->mData, 0x140);
        NNS_GfdRegisterNewVramTransferTask(0x1b, 0, fixedScreenMap->mData, fixedScreenMap->mDataSize);
        NNS_GfdRegisterNewVramTransferTask(0x1b, 0x800, gSelectCupCourse->field24, 0x800);
    }
    NNS_GfdRegisterNewVramTransferTask(0x13, 0, courseCellChars->mData, courseCellChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xe, 0, courseCellPalette->mData, 0x1a0);
    NNS_GfdRegisterNewVramTransferTask(0xe, 0x1c0, courseCellPaletteData + 0xe0, 0x40);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, cupCellChars->mData, cupCellChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, cupCellPalette->mData, cupCellPalette->mDataSize);
}

void SetupSelectCupCourseObjects(void) {
    s32 i;
    u32 courseEntryCount;
    u32 cupEntryCount;
    SelectCupCourse *selectCupCourse;
    if (((Unk027ffc40 *) 0x027ffc40)->field0 != 2) {
        courseEntryCount = gSelectCupCourse->mSelectCupCourseTaOrVsMBncl->field6;
        cupEntryCount = gSelectCupCourse->mSelectCupMBncl->field6;
        for (i = 0; i < 8; i++) {
            gSelectCupCourse->mSelectCupMTable[data_0215cacc[i]].mVisible = 0;
        }
        for (i = 0; i < 4; i++) {
            gSelectCupCourse->mSelectCupMTable[data_0215ca9c[i]].mVisible = 0;
        }
        for (i = 0; i < 4; i++) {
            gSelectCupCourse->mSelectCupMTable[data_0215caa4[i]].mVisible = 0;
            gSelectCupCourse->mSelectCupMTable[cupEntryCount + data_0215cab4[i]].mVisible = 1;
        }
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[0].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[2].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[1].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[4].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[3].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[5].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 1].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 2].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 3].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 4].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 5].mVisible = 1;
        gSelectCupCourse->mSelectCupMTable[0x14].mVisible = 0;
        gSelectCupCourse->mSelectCupMTable[0x13].mVisible = 1;
        selectCupCourse = gSelectCupCourse;
        QueueSelectCupNameM(data_0215cadc[SPM_GetSelectedCup()], selectCupCourse->mSelectCupCourseMNcer,
                            selectCupCourse->mSelectCupCourseTaOrVsMBncl, 0, 0);
        selectCupCourse = gSelectCupCourse;
        QueueSelectCupNameM(data_0215cadc[SPM_GetSelectedCup()], selectCupCourse->mSelectCupMNcer,
                            selectCupCourse->mSelectCupMBncl, 0x13, 1);
        selectCupCourse = gSelectCupCourse;
        i = SPM_GetSelectedCup();
        QueueCupMark(data_0215cadc[i], selectCupCourse->mSelectCupCourseMNcer,
                     selectCupCourse->mSelectCupCourseTaOrVsMBncl, 5,
                     GetCellPaletteIndex(5, selectCupCourse->mSelectCupCourseMNcer,
                                         selectCupCourse->mSelectCupCourseTaOrVsMBncl),
                     0);
        for (i = 0; i < 4; i++) {
            selectCupCourse = gSelectCupCourse;
            jn_ui_212426C(
                1, data_0215cab4[i], gSelectCupCourse->mSelectCupMBnll,
                jn_msg_getMessage(gSelectCupCourse->mCommonMessages, a_0123456789Abcdefghijkl3456789Abcdefghi[data_0215cadc[SPM_GetSelectedCup()]][i]),
                selectCupCourse->mSelectCupMBncl, selectCupCourse->mSelectCupMTable);
        }
        selectCupCourse = gSelectCupCourse;
        jn_ui_212426C(0, 2, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
                      jn_msg_getMessage(selectCupCourse->mCommonMessages, 0x73), selectCupCourse->mSelectCupCourseTaOrVsMBncl,
                      selectCupCourse->mSelectCupCourseTaOrVsMTable);
        selectCupCourse = gSelectCupCourse;
        jn_ui_212426C(0, 4, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
                      jn_msg_getMessage(selectCupCourse->mCommonMessages, 0x74), selectCupCourse->mSelectCupCourseTaOrVsMBncl,
                      selectCupCourse->mSelectCupCourseTaOrVsMTable);
        jn_ui_setLabelIsTranslucent(0, 0, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
                      gSelectCupCourse->mSelectCupCourseTaOrVsMTable, gSelectCupCourse->mSelectCupCourseTaOrVsMBncl);
        jn_ui_setLabelIsTranslucent(1, 0, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
                      gSelectCupCourse->mSelectCupCourseTaOrVsMTable, gSelectCupCourse->mSelectCupCourseTaOrVsMBncl);
        jn_ui_setLabelIsTranslucent(2, 0, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
                      gSelectCupCourse->mSelectCupCourseTaOrVsMTable, gSelectCupCourse->mSelectCupCourseTaOrVsMBncl);
        jn_ui_setLabelIsTranslucent(4, 0, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
                      gSelectCupCourse->mSelectCupCourseTaOrVsMTable, gSelectCupCourse->mSelectCupCourseTaOrVsMBncl);
        selectCupCourse = gSelectCupCourse;
        switch (selectCupCourse->mMode) {
            case 1:
            case 2:
            case 3:
                selectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 2].mVisible = 0;
                gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 3].mVisible = 0;
                gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 4].mVisible = 0;
                gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 5].mVisible = 0;
                break;
        }
    }
}

void AdvanceSelectCupCourseHighlight(void) {
    s32 i;
    if (((Unk027ffc40 *) 0x027ffc40)->field0 != 2) {
        for (i = 0; i < 4; i++) {
            if (gSelectCupCourse->mIndex == i && gSelectCupCourse->field54 != FALSE) {
                gSelectCupCourse->mSelectCupMTable[data_0215caa4[i]].mVisible = 1;
                jn_ui_setLabelColorParam(data_0215cab4[i], 0xe, gSelectCupCourse->mSelectCupMBnll,
                                     gSelectCupCourse->mSelectCupMTable, gSelectCupCourse->mSelectCupMBncl);
            } else {
                gSelectCupCourse->mSelectCupMTable[data_0215caa4[i]].mVisible = 0;
                jn_ui_setLabelColorParam(data_0215cab4[i], 0xf, gSelectCupCourse->mSelectCupMBnll,
                                     gSelectCupCourse->mSelectCupMTable, gSelectCupCourse->mSelectCupMBncl);
            }
        }
    }
}

void RefreshSelectCupCourseForIndex(void) {
    SelectCupCourse *selectCupCourse;
    u32 recordTime;
    u8 timeText[0x24];
    if (((Unk027ffc40 *) 0x027ffc40)->field0 != 2) {
        selectCupCourse = gSelectCupCourse;
        jn_ui_212426C(0, 0, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
                      jn_msg_getMessage(gSelectCupCourse->mCommonMessages,
                                  a_0123456789Abcdefghijkl3456789Abcdefghi[data_0215cadc[SPM_GetSelectedCup()]][selectCupCourse->mIndex]),
                      selectCupCourse->mSelectCupCourseTaOrVsMBncl, selectCupCourse->mSelectCupCourseTaOrVsMTable);
        selectCupCourse = gSelectCupCourse;
        jn_ui_212426C(0, 1, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
                      jn_msg_getMessage(gSelectCupCourse->mCommonMessages,
                                  a_0123456789Abcdefghijkl3456789Abcdefghi[data_0215cadc[SPM_GetSelectedCup()]][selectCupCourse->mIndex]),
                      selectCupCourse->mSelectCupCourseTaOrVsMBncl, selectCupCourse->mSelectCupCourseTaOrVsMTable);
        if (IsTimeRecordFilled(TTCourseOrder[data_0215cadc[SPM_GetSelectedCup()]][gSelectCupCourse->mIndex], 0)) {
            GetTimeRecordTime(TTCourseOrder[data_0215cadc[SPM_GetSelectedCup()]][gSelectCupCourse->mIndex], 0, &recordTime);
            func_02116b80(&recordTime, timeText);
            selectCupCourse = gSelectCupCourse;
            jn_ui_2124224(0, 3, selectCupCourse->mSelectCupCourseTaOrVsMBnll, timeText,
                          selectCupCourse->mSelectCupCourseTaOrVsMBncl, selectCupCourse->mSelectCupCourseTaOrVsMTable,
                          9);
        } else {
            selectCupCourse = gSelectCupCourse;
            jn_ui_2124224(0, 3, selectCupCourse->mSelectCupCourseTaOrVsMBnll, data_0216dbac,
                          selectCupCourse->mSelectCupCourseTaOrVsMBncl, selectCupCourse->mSelectCupCourseTaOrVsMTable,
                          9);
        }
        if (IsTimeRecordFilled(TTCourseOrder[data_0215cadc[SPM_GetSelectedCup()]][gSelectCupCourse->mIndex], 5)) {
            GetTimeRecordTime(TTCourseOrder[data_0215cadc[SPM_GetSelectedCup()]][gSelectCupCourse->mIndex], 5, &recordTime);
            func_02116b80(&recordTime, timeText);
            selectCupCourse = gSelectCupCourse;
            jn_ui_2124224(0, 5, selectCupCourse->mSelectCupCourseTaOrVsMBnll, timeText,
                          selectCupCourse->mSelectCupCourseTaOrVsMBncl, selectCupCourse->mSelectCupCourseTaOrVsMTable,
                          9);
        } else {
            selectCupCourse = gSelectCupCourse;
            jn_ui_2124224(0, 5, selectCupCourse->mSelectCupCourseTaOrVsMBnll, data_0216dbc0,
                          selectCupCourse->mSelectCupCourseTaOrVsMBncl, selectCupCourse->mSelectCupCourseTaOrVsMTable,
                          9);
        }
        cpic_loadForCourse(TTCourseOrder[data_0215cadc[SPM_GetSelectedCup()]][gSelectCupCourse->mIndex]);
        gSelectCupCourse->mCupPicturePending = TRUE;
    }
}

void SetCourseIdFromSelectCupCourse(void) {
    SPM_SetCourse(TTCourseOrder[data_0215cadc[SPM_GetSelectedCup()]][gSelectCupCourse->mIndex]);
}

void func_02119e14(void) {
    SetupGhostRecordSetForCourse(TTCourseOrder[data_0215cadc[SPM_GetSelectedCup()]][gSelectCupCourse->mIndex]);
    SPM_SetTTGhost(0);
}

#pragma thumb off
