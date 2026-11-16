#include "Main/Unknown/code_021173e4.h"

#include "Main/System/Heap.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020d0e3c.h"
#include "Main/Unknown/code_02117418.h"
#include "Main/Unknown/code_0211f000.h"
#include "Main/Unknown/code_0211f2ac.h"
#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_0211f4b0.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_0211f378.h"
#include "Main/Unknown/code_020d0000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02117814.h"
#include "Main/Unknown/code_021177a4.h"
#include "Main/Unknown/code_02117be0.h"
#include "Main/Unknown/code_02117d98.h"
#include "Main/Unknown/code_02117bf8.h"
#include "Main/Unknown/code_021177c0.h"
#include "Main/Unknown/code_0211784c.h"
#include "Main/Unknown/code_02118148.h"
#include "Main/Unknown/code_02117db0.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/unk_0215c000.h"
#include "00/code_02181f98.h"
#include "code_02016468.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02118000.h"
#include "Main/Unknown/code_02117000.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_02118088.h"
#include "Main/Unknown/unk_02175628.h"
#include "code_0201ea58.h"
#include "Main/Unknown/code_021185d4.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_0211de34.h"
#include "Main/Unknown/code_0211de00.h"
#include "Main/Unknown/code_0211df44.h"
#include "Main/Unknown/code_0211f2b8.h"
#include "Main/Unknown/code_0211f380.h"
#include "Main/Unknown/code_0211f498.h"
#include "Main/Unknown/code_021189f4.h"
#include "Main/Unknown/code_021281fc.h"
#include "Main/Unknown/unk_02175000.h"
#include "registers.h"
#include "Main/Unknown/code_02118054.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02118114.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02060004.h"
#include "Main/Unknown/code_020d0efc.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_0211f240.h"

#pragma thumb on

void RefreshSelectCupGridCupsEnabled(void) {
    int cupIndex;
    u32 enabled;
    cupIndex = 0;
    do {
        enabled = GetSelectCupGridCupEnabled(cupIndex);
        CupSelectionMenuInfoPointer->mCupsEnabled[cupIndex] = enabled;
        cupIndex = cupIndex + 1;
    } while (cupIndex < 8);
}

#pragma thumb off

#pragma thumb on
void LoadCupSelectionMenuOAM(void) {
    s32 cupCellIndex;
    s32 i;
    u16 mainCellCount;
    u16 *cellIndices;
    SelectCupGrid *grid;

    if (*(vu16 *) 0x027ffc40 != 2) {
        mainCellCount = CupSelectionMenuInfoPointer->mSelectCupMBncl->field6;
        for (i = 0; i < 4; i++) {
            CupSelectionMenuInfoPointer->mSelectCupMTable[data_0215c7d0[i]].mVisible = 0;
            CupSelectionMenuInfoPointer->mSelectCupMTable[mainCellCount + data_0215c7d8[i]].mVisible = 1;
        }
        for (i = 0; i < 8; i++) {
            for (cupCellIndex = 0, cellIndices = gSelectCupGridCupCellIndices[i]; cupCellIndex < 6; cupCellIndex++) {
                CupSelectionMenuInfoPointer->mSelectCupSTable[cellIndices[cupCellIndex]].mVisible = 0;
            }
        }
        CupSelectionMenuInfoPointer->mSelectCupMTable[0x14].mVisible = 1;
        CupSelectionMenuInfoPointer->mSelectCupMTable[0x13].mVisible = 1;
        CupSelectionMenuInfoPointer->mSelectCupSTable[2].mVisible = 1;
        CupSelectionMenuInfoPointer->mSelectCupSTable[3].mVisible = 1;
        for (i = 0; i < 8; i++) {
            CupSelectionMenuInfoPointer->mSelectCupSTable[gSelectCupGridCupCellIndices[i][0]].mVisible = 1;
        }
        for (i = 0; i < 8; i++) {
            grid = CupSelectionMenuInfoPointer;
            QueueCupMark(
                i, grid->mSelectCupSNcer, grid->mSelectCupSBncl, gSelectCupGridCupCellIndices[i][4],
                GetCellPaletteIndex(gSelectCupGridCupCellIndices[i][4], grid->mSelectCupSNcer, grid->mSelectCupSBncl),
                1);
        }
    }
}

void UpdateSelectCupGridCupCells(void) {
    s32 i;
    BOOL visible;

    if (*(vu16 *) 0x027ffc40 != 2) {
        visible = FALSE;
        for (i = 0; i < 8; i++) {
            u16 *cellIndices = gSelectCupGridCupCellIndices[i];
            CupSelectionMenuInfoPointer->mSelectCupSTable[cellIndices[1]].mVisible = 0;
            CupSelectionMenuInfoPointer->mSelectCupSTable[cellIndices[2]].mVisible = 0;
            CupSelectionMenuInfoPointer->mSelectCupSTable[cellIndices[3]].mVisible = 0;
            CupSelectionMenuInfoPointer->mSelectCupSTable[cellIndices[4]].mVisible = 0;
            CupSelectionMenuInfoPointer->mSelectCupSTable[cellIndices[5]].mVisible = 0;
            if (CupSelectionMenuInfoPointer->mCupsEnabled[i] == 0) {
                CupSelectionMenuInfoPointer->mSelectCupSTable[cellIndices[3]].mVisible = 1;
                CupSelectionMenuInfoPointer->mSelectCupSTable[cellIndices[5]].mVisible = 1;
            } else {
                if (CupSelectionMenuInfoPointer->mIndex == i && CupSelectionMenuInfoPointer->field68 != FALSE) {
                    CupSelectionMenuInfoPointer->mSelectCupSTable[cellIndices[2]].mVisible = 1;
                } else {
                    CupSelectionMenuInfoPointer->mSelectCupSTable[cellIndices[1]].mVisible = 1;
                }
                CupSelectionMenuInfoPointer->mSelectCupSTable[cellIndices[4]].mVisible = 1;
            }
            if (CupSelectionMenuInfoPointer->mMode == 3) {
                CupSelectionMenuInfoPointer->mSelectCupSTable[cellIndices[5]].mVisible = visible;
            }
        }
    }
}

void UpdateCoursePicture(void) {
    if (*(vu16 *) 0x027ffc40 != 2) {
        cpic_loadForCourse(
            TTCoursePicOrder[CupSelectionMenuInfoPointer->mIndex][CupSelectionMenuInfoPointer->mShownCourseIndex]);
        CupSelectionMenuInfoPointer->mCupPicturePending = TRUE;
    }
}

void UpdateCourseNames(void) {
    u32 a;
    s32 recordSlot;
    s32 c;
    s32 i;
    u16 *cellIndexCursor;
    s32 j;
    SelectCupGrid *grid;
    u32 engineOrMirrorSlot;

    a = 0;
    if (*(vu16 *) 0x027ffc40 == 2) {
        return;
    }
    QueueSelectCupNameM(CupSelectionMenuInfoPointer->mIndex, CupSelectionMenuInfoPointer->mSelectCupMNcer, CupSelectionMenuInfoPointer->mSelectCupMBncl, 0x13,
                        a);
    j = 0;
    for (i = 0; i < 4; i++) {
        grid = CupSelectionMenuInfoPointer;
        jn_ui_212426C(j, data_0215c7d8[i], CupSelectionMenuInfoPointer->mSelectCupMBnll,
                      jn_msg_getMessage(grid->mCommonMessages, a_0123456789Abcdefghijkl[grid->mIndex][i]),
                      grid->mSelectCupMBncl, grid->mSelectCupMTable);
    }
    for (j = 0, cellIndexCursor = data_0215c83c; j < 8; cellIndexCursor++, j++) {
        CupSelectionMenuInfoPointer->mSelectCupMTable[*cellIndexCursor].mVisible = 0;
    }
    for (i = 0; i < 4; i++) {
        CupSelectionMenuInfoPointer->mSelectCupMTable[data_0215c7c8[i]].mVisible = 0;
    }
    if (CupSelectionMenuInfoPointer->mMode == 0) {
        if (GetMirrorMode() != 0) {
            engineOrMirrorSlot = 3;
        } else {
            engineOrMirrorSlot = data_0215c7f0[GetEngineIndex()];
        }
        recordSlot = data_0215c81c[engineOrMirrorSlot];
        if (savd_getIsCupPlayed(CupTable[CupSelectionMenuInfoPointer->mIndex], recordSlot) != 0) {
            c = savd_getCupRank(CupTable[CupSelectionMenuInfoPointer->mIndex], recordSlot);
            CupSelectionMenuInfoPointer->mSelectCupMTable[data_0215c83c[data_0215c87c[c]]].mVisible = 1;
            switch (c) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                    a = data_0215c7c8[0];
                    break;
                case 5:
                    a = data_0215c7c8[1];
                    break;
                case 6:
                    a = data_0215c7c8[2];
                    break;
                case 7:
                    a = data_0215c7c8[3];
                    break;
            }
            CupSelectionMenuInfoPointer->mSelectCupMTable[a].mVisible = 1;
            c = savd_getCupTrophy(CupTable[CupSelectionMenuInfoPointer->mIndex], recordSlot);
            grid = CupSelectionMenuInfoPointer;
            QueueTrophyIcon(CupTable[grid->mIndex], c, grid->mSelectCupMNcer, grid->mSelectCupMBncl, a, 4, 0);
        }
    }
    UpdateCoursePicture();
}

void func_021185ec(void) {
    SPM_SetCup(CupTable[CupSelectionMenuInfoPointer->mIndex]);
    SPM_SetCourse(gSelectCupGridFirstCourseIds[CupSelectionMenuInfoPointer->mIndex]);
}
#pragma thumb off

#pragma thumb on

u32 IsSelectCupGridIndexChangeRunning(void) {
    if (CupSelectionMenuInfoPointer->mIndexChangeTimer != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridIndexChange(void) {
    u16 mainCellCount;
    s16 offsetY;
    int i;

    if (IsSelectCupGridIndexChangeRunning() != 0) {
        if (CupSelectionMenuInfoPointer->mIndexChangeTimer == 7) {
            CupSelectionMenuInfoPointer->mShownIndex = CupSelectionMenuInfoPointer->mIndex;
            UpdateCourseNames();
        } else if (*(vu16 *) 0x027ffc40 != 2) {
            mainCellCount = CupSelectionMenuInfoPointer->mSelectCupMBncl->field6;
            offsetY = LookupIndexChangeOffset(7 - CupSelectionMenuInfoPointer->mIndexChangeTimer, 1);
            CupSelectionMenuInfoPointer->mBg0Offset = offsetY;
            CupSelectionMenuInfoPointer->mSelectCupMTable[19].mOffsetY = offsetY;
            CupSelectionMenuInfoPointer->mSelectCupMTable[2].mOffsetY = offsetY;
            CupSelectionMenuInfoPointer->mSelectCupMTable[1].mOffsetY = offsetY;
            CupSelectionMenuInfoPointer->mSelectCupMTable[0].mOffsetY = offsetY;
            for (i = 0; i < 8; i++) {
                CupSelectionMenuInfoPointer->mSelectCupMTable[data_0215c83c[i]].mOffsetY = offsetY;
            }
            for (i = 0; i < 4; i++) {
                CupSelectionMenuInfoPointer->mSelectCupMTable[data_0215c7c8[i]].mOffsetY = offsetY;
            }
            for (i = 0; i < 4; i++) {
                CupSelectionMenuInfoPointer->mSelectCupMTable[data_0215c7d0[i]].mOffsetY = offsetY;
                CupSelectionMenuInfoPointer->mSelectCupMTable[mainCellCount + data_0215c7d8[i]].mOffsetY = offsetY;
            }
        }
        CupSelectionMenuInfoPointer->mIndexChangeTimer = CupSelectionMenuInfoPointer->mIndexChangeTimer - 1;
    } else if (CupSelectionMenuInfoPointer->mIndex != CupSelectionMenuInfoPointer->mShownIndex) {
        CupSelectionMenuInfoPointer->mIndexChangeTimer = 7;
    }
}

void UpdateSelectCupGridCourseCells(void) {
    int i;

    if (*(vu16 *) 0x027ffc40 != 2) {
        for (i = 0; i < 4; i++) {
            if (CupSelectionMenuInfoPointer->mShownCourseIndex == i) {
                CupSelectionMenuInfoPointer->mSelectCupMTable[data_0215c7d0[i]].mVisible = 1;
                jn_ui_setLabelColorParam(data_0215c7d8[i], 0xe, CupSelectionMenuInfoPointer->mSelectCupMBnll,
                                     CupSelectionMenuInfoPointer->mSelectCupMTable, CupSelectionMenuInfoPointer->mSelectCupMBncl);
            } else {
                CupSelectionMenuInfoPointer->mSelectCupMTable[data_0215c7d0[i]].mVisible = 0;
                jn_ui_setLabelColorParam(data_0215c7d8[i], 0xf, CupSelectionMenuInfoPointer->mSelectCupMBnll,
                                     CupSelectionMenuInfoPointer->mSelectCupMTable, CupSelectionMenuInfoPointer->mSelectCupMBncl);
            }
        }
    }
}

void AdvanceSelectCupGridShownCourse(void) {
    CupSelectionMenuInfoPointer->mShownCourseFrames = CupSelectionMenuInfoPointer->mShownCourseFrames + 1;
    if (CupSelectionMenuInfoPointer->mShownCourseFrames >= 0x4b) {
        CupSelectionMenuInfoPointer->mShownCourseIndex = CupSelectionMenuInfoPointer->mShownCourseIndex + 1;
        if (CupSelectionMenuInfoPointer->mShownCourseIndex >= 4) {
            CupSelectionMenuInfoPointer->mShownCourseIndex = 0;
        }
        CupSelectionMenuInfoPointer->mShownCourseFrames = 0;
        UpdateCoursePicture();
    }
}

void ResetSelectCupGridShownCourse(void) {
    CupSelectionMenuInfoPointer->mShownCourseIndex = 0;
    CupSelectionMenuInfoPointer->mShownCourseFrames = 0;
}

void RequestSelectCupGridState0(void) {
    u16 mainCellCount;
    s32 offsetY;
    s32 offsetX;
    int i;
    int j;

    CupSelectionMenuInfoPointer->mNextState = 0;
    CupSelectionMenuInfoPointer->mStateFrames = 0;
    if (*(vu16 *) 0x027ffc40 != 2) {
        mainCellCount = CupSelectionMenuInfoPointer->mSelectCupMBncl->field6;
        if (menu_getPrevState() == 0x18 || menu_getPrevState() == 0xc) {
            offsetY = 0;
            CupSelectionMenuInfoPointer->mBg0Offset = offsetY;
            CupSelectionMenuInfoPointer->mSelectCupMTable[20].mOffsetY = offsetY;
            CupSelectionMenuInfoPointer->mSelectCupMTable[19].mOffsetY = offsetY;
            CupSelectionMenuInfoPointer->mSelectCupMTable[2].mOffsetY = offsetY;
            CupSelectionMenuInfoPointer->mSelectCupMTable[1].mOffsetY = offsetY;
            CupSelectionMenuInfoPointer->mSelectCupMTable[0].mOffsetY = offsetY;
            for (i = 0; i < 8; i++) {
                CupSelectionMenuInfoPointer->mSelectCupMTable[data_0215c83c[i]].mOffsetY = offsetY;
            }
            for (i = 0; i < 4; i++) {
                CupSelectionMenuInfoPointer->mSelectCupMTable[data_0215c7c8[i]].mOffsetY = offsetY;
            }
            for (i = 0; i < 4; i++) {
                CupSelectionMenuInfoPointer->mSelectCupMTable[data_0215c7d0[i]].mOffsetY = offsetY;
                CupSelectionMenuInfoPointer->mSelectCupMTable[mainCellCount + data_0215c7d8[i]].mOffsetY = offsetY;
            }
        } else {
            offsetY = -192;
            CupSelectionMenuInfoPointer->mBg0Offset = offsetY;
            CupSelectionMenuInfoPointer->mSelectCupMTable[20].mOffsetY = offsetY;
            CupSelectionMenuInfoPointer->mSelectCupMTable[19].mOffsetY = offsetY;
            CupSelectionMenuInfoPointer->mSelectCupMTable[2].mOffsetY = offsetY;
            CupSelectionMenuInfoPointer->mSelectCupMTable[1].mOffsetY = offsetY;
            CupSelectionMenuInfoPointer->mSelectCupMTable[0].mOffsetY = offsetY;
            for (i = 0; i < 8; i++) {
                CupSelectionMenuInfoPointer->mSelectCupMTable[data_0215c83c[i]].mOffsetY = offsetY;
            }
            for (i = 0; i < 4; i++) {
                CupSelectionMenuInfoPointer->mSelectCupMTable[data_0215c7c8[i]].mOffsetY = offsetY;
            }
            for (i = 0; i < 4; i++) {
                CupSelectionMenuInfoPointer->mSelectCupMTable[data_0215c7d0[i]].mOffsetY = offsetY;
                CupSelectionMenuInfoPointer->mSelectCupMTable[mainCellCount + data_0215c7d8[i]].mOffsetY = offsetY;
            }
        }
        offsetY = -192;
        CupSelectionMenuInfoPointer->mSelectCupMTable[20].mOffsetY = offsetY;
        offsetX = -224;
        CupSelectionMenuInfoPointer->mSelectCupSTable[0].mOffsetX = offsetX;
        CupSelectionMenuInfoPointer->mSelectCupSTable[1].mOffsetX = 0xe0;
        CupSelectionMenuInfoPointer->mSelectCupSTable[2].mOffsetX = offsetX;
        CupSelectionMenuInfoPointer->mSelectCupSTable[3].mOffsetX = 0xe0;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 6; j++) {
                CupSelectionMenuInfoPointer->mSelectCupSTable[gSelectCupGridCupCellIndices[i][j]].mOffsetX = offsetX;
            }
        }
        for (i = 4; i < 8; i++) {
            for (j = 0; j < 6; j++) {
                CupSelectionMenuInfoPointer->mSelectCupSTable[gSelectCupGridCupCellIndices[i][j]].mOffsetX = 0xe0;
            }
        }
    }
}

void RequestSelectCupGridState1(void) {
    CupSelectionMenuInfoPointer->mNextState = 1;
    CupSelectionMenuInfoPointer->mStateFrames = 0;
}

void RequestSelectCupGridState2(void) {
    CupSelectionMenuInfoPointer->mNextState = 2;
    CupSelectionMenuInfoPointer->mStateFrames = 0;
    RequestSelectReturnState1();
}

void RequestSelectCupGridState3(void) {
    CupSelectionMenuInfoPointer->mNextState = 3;
    CupSelectionMenuInfoPointer->mStateFrames = 0;
}

void RequestSelectCupGridState4(void) {
    CupSelectionMenuInfoPointer->mNextState = 4;
    CupSelectionMenuInfoPointer->mStateFrames = 0;
    if (*(vu16 *) 0x027ffc40 != 2) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
    }
}

void RequestSelectCupGridState5(void) {
    void *firstChoiceText;

    CupSelectionMenuInfoPointer->mNextState = 5;
    CupSelectionMenuInfoPointer->mStateFrames = 0;
    firstChoiceText = jn_msg_getMessage(CupSelectionMenuInfoPointer->mCommonMessages, 4);
    gmenu_startSelectChoices(firstChoiceText, jn_msg_getMessage(CupSelectionMenuInfoPointer->mCommonMessages, 2), 0);
}

#pragma thumb off

#pragma thumb on

void RequestSelectCupGridState6(void) {
    CupSelectionMenuInfoPointer->mNextState = 6;
    CupSelectionMenuInfoPointer->mStateFrames = 0;
    SetSelectChoisesSoundId(0, 7);
    SetSelectChoisesSoundId(1, 0x10);
    SetSelectChoisesSoundId(0xffffffff, 0x10);
}

#pragma thumb off

#pragma thumb on

void RequestSelectCupGridState7(void) {
    CupSelectionMenuInfoPointer->mNextState = 7;
    CupSelectionMenuInfoPointer->mStateFrames = 0;
    RequestSelectChoisesState0();
}

void RequestSelectCupGridState8(void) {
    void *firstChoiceText;

    CupSelectionMenuInfoPointer->mNextState = 8;
    CupSelectionMenuInfoPointer->mStateFrames = 0;
    if (*(vu16 *) 0x027ffc40 == 2) {
        firstChoiceText = jn_msg_getMessage(CupSelectionMenuInfoPointer->mCommonMessages, 0x5d);
        gmenu_startSelectChoices(firstChoiceText, jn_msg_getMessage(CupSelectionMenuInfoPointer->mCommonMessages, 0x5f), 0);
    } else {
        firstChoiceText = jn_msg_getMessage(CupSelectionMenuInfoPointer->mMenuMessages, 0x14);
        gmenu_startSelectChoices(firstChoiceText, jn_msg_getMessage(CupSelectionMenuInfoPointer->mMenuMessages, 0x15), 0);
    }
}

#pragma thumb off

#pragma thumb on

void RequestSelectCupGridState9(void) {
    CupSelectionMenuInfoPointer->mNextState = 9;
    CupSelectionMenuInfoPointer->mStateFrames = 0;
    SetSelectChoisesSoundId(0, 5);
    SetSelectChoisesSoundId(1, 0xf);
    SetSelectChoisesSoundId(0xffffffff, 0x10);
}

#pragma thumb off

#pragma thumb on

void RequestSelectCupGridState10(void) {
    CupSelectionMenuInfoPointer->mNextState = 0xa;
    CupSelectionMenuInfoPointer->mStateFrames = 0;
    RequestSelectChoisesState0();
}

void RequestSelectCupGridState11(void) {
    CupSelectionMenuInfoPointer->mNextState = 0xb;
    CupSelectionMenuInfoPointer->mStateFrames = 0;
}

void SPM_LoadCupSelectionMenu(void *heap, void *mainOam, void *subOam, s32 mode) {
    s32 remainingSize;
    int i;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x9004;
    if (menu_getPrevState() != 0x18 && menu_getPrevState() != 0xc) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1800;
    }
    heap = heap_createSubFrmHeap(heap);
    CupSelectionMenuInfoPointer = heap_alloc(heap, 0x8c);
    CupSelectionMenuInfoPointer->mHeap = heap;
    CupSelectionMenuInfoPointer->mState = 0;
    CupSelectionMenuInfoPointer->mIndex = data_0215c8fc[SPM_GetSelectedCup()];
    CupSelectionMenuInfoPointer->field68 = TRUE;
    CupSelectionMenuInfoPointer->mIndexChangeTimer = 0;
    CupSelectionMenuInfoPointer->mMode = mode;
    CupSelectionMenuInfoPointer->mShownIndex = CupSelectionMenuInfoPointer->mIndex;
    CupSelectionMenuInfoPointer->mCupPicturePending = FALSE;
    CupSelectionMenuInfoPointer->mMainOam = mainOam;
    CupSelectionMenuInfoPointer->mSubOam = subOam;
    CupSelectionMenuInfoPointer->mResult = 0;
    ResetSelectCupGridShownCourse();
    RefreshSelectCupGridCupsEnabled();
    func_02118b48();
    if (menu_getPrevState() != 0x18 && menu_getPrevState() != 0xc) {
        oam_clearResetBuffers(CupSelectionMenuInfoPointer->mMainOam, CupSelectionMenuInfoPointer->mSubOam);
    }
    CupSelectionMenuInfoPointer->mCommonMessages = arc_get2dArcFile("common.bmg");
    if (*(vu16 *) 0x027ffc40 != 2) {
        CupSelectionMenuInfoPointer->mMenuMessages = arc_getSceneArcFile("menu.bmg");
        jn_ui_initLayout(CupSelectionMenuInfoPointer->mHeap, CupSelectionMenuInfoPointer->mSelectCupMBncl, CupSelectionMenuInfoPointer->mSelectCupMBnll,
                        &CupSelectionMenuInfoPointer->mSelectCupMTable);
        jn_ui_initLayout(CupSelectionMenuInfoPointer->mHeap, CupSelectionMenuInfoPointer->mSelectCupSBncl, NULL,
                        &CupSelectionMenuInfoPointer->mSelectCupSTable);
        remainingSize = 0x8000;
        for (i = 0; i < 4; i++) {
            remainingSize -=
                jn_ui_initLabel(CupSelectionMenuInfoPointer->mHeap, data_0215c7d8[i], CupSelectionMenuInfoPointer->mSelectCupMBnll,
                                data_0215c7e0[i], data_0215c7e8[i], data_0215c7d0[i], CupSelectionMenuInfoPointer->mSelectCupMNcer,
                                CupSelectionMenuInfoPointer->mSelectCupMBncl, CupSelectionMenuInfoPointer->mSelectCupMTable, remainingSize);
        }
        CreateSelectCupNameM(CupSelectionMenuInfoPointer->mHeap);
        CreateCommonCupMark(CupSelectionMenuInfoPointer->mHeap);
        CreateTrophyIcon(CupSelectionMenuInfoPointer->mHeap);
    } else {
        InitSelectRaceRuleWait(CupSelectionMenuInfoPointer->mHeap, CupSelectionMenuInfoPointer->mSubOam);
        if (menu_getPrevState() != 0xc) {
            func_0211f394();
        } else {
            func_0211f380();
        }
    }
    LoadCupSelectionMenuOAM();
    UpdateCourseNames();
    RequestSelectCupGridState0();
    heap_adjustSubFrmHeap(CupSelectionMenuInfoPointer->mHeap);
    if (gSystemData->field20 == 2) {
        ClearSelectReturnDisplayBitOn();
    }
}

void ReleaseSelectCupGrid(void) {
    if ((CupSelectionMenuInfoPointer->mMode == 0 && CupSelectionMenuInfoPointer->mResult == 1) || CupSelectionMenuInfoPointer->mResult == 2) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1800;
    }
    if (*(vu16 *) 0x027ffc40 != 2) {
        ClearSelectCupNameMPointer();
        ClearCupMarkPointer();
        ClearTrophyIconPointer();
    } else {
        func_0211f498();
    }
    heap_destroySubHeap(CupSelectionMenuInfoPointer->mHeap);
    CupSelectionMenuInfoPointer = NULL;
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState0(void) {
    int fadesClear;
    fadesClear = mbright_isFadedIn();
    if (fadesClear != 0) {
        RequestSelectCupGridState1();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState1(void) {
    u16 mainCellCount;
    s16 offsetX;
    s16 offsetY;
    s16 negatedOffsetX;
    int i;
    int j;

    CupSelectionMenuInfoPointer->mStateFrames = CupSelectionMenuInfoPointer->mStateFrames + 1;
    if (*(vu16 *) 0x027ffc40 != 2) {
        mainCellCount = CupSelectionMenuInfoPointer->mSelectCupMBncl->field6;
        offsetX = mutil_interpolate(1, 0xe0, 0, CupSelectionMenuInfoPointer->mStateFrames, 0xa);
        offsetY = mutil_interpolate(1, -192, 0, CupSelectionMenuInfoPointer->mStateFrames, 0xa);
        if (menu_getPrevState() != 0x18 && menu_getPrevState() != 0xc) {
            CupSelectionMenuInfoPointer->mBg0Offset = offsetY;
            CupSelectionMenuInfoPointer->mSelectCupMTable[19].mOffsetY = offsetY;
            CupSelectionMenuInfoPointer->mSelectCupMTable[2].mOffsetY = offsetY;
            CupSelectionMenuInfoPointer->mSelectCupMTable[1].mOffsetY = offsetY;
            CupSelectionMenuInfoPointer->mSelectCupMTable[0].mOffsetY = offsetY;
            for (i = 0; i < 8; i++) {
                CupSelectionMenuInfoPointer->mSelectCupMTable[data_0215c83c[i]].mOffsetY = offsetY;
            }
            for (i = 0; i < 4; i++) {
                CupSelectionMenuInfoPointer->mSelectCupMTable[data_0215c7c8[i]].mOffsetY = offsetY;
            }
            for (i = 0; i < 4; i++) {
                CupSelectionMenuInfoPointer->mSelectCupMTable[data_0215c7d0[i]].mOffsetY = offsetY;
                CupSelectionMenuInfoPointer->mSelectCupMTable[mainCellCount + data_0215c7d8[i]].mOffsetY = offsetY;
            }
        }
        CupSelectionMenuInfoPointer->mSelectCupMTable[20].mOffsetY = offsetY;
        negatedOffsetX = -offsetX;
        CupSelectionMenuInfoPointer->mSelectCupSTable[0].mOffsetX = negatedOffsetX;
        CupSelectionMenuInfoPointer->mSelectCupSTable[1].mOffsetX = offsetX;
        CupSelectionMenuInfoPointer->mSelectCupSTable[2].mOffsetX = negatedOffsetX;
        CupSelectionMenuInfoPointer->mSelectCupSTable[3].mOffsetX = offsetX;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 6; j++) {
                CupSelectionMenuInfoPointer->mSelectCupSTable[gSelectCupGridCupCellIndices[i][j]].mOffsetX = -offsetX;
            }
        }
        for (i = 4; i < 8; i++) {
            for (j = 0; j < 6; j++) {
                CupSelectionMenuInfoPointer->mSelectCupSTable[gSelectCupGridCupCellIndices[i][j]].mOffsetX = offsetX;
            }
        }
    }
    if (CupSelectionMenuInfoPointer->mStateFrames >= 0xa) {
        RequestSelectCupGridState2();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState2(void) {
    int isReturnState2NoState3Or4Request;
    isReturnState2NoState3Or4Request = IsSelectReturnState2NoState3Or4Request();
    if (isReturnState2NoState3Or4Request != 0) {
        RequestSelectCupGridState3();
    }
}

#pragma thumb off

#pragma thumb on

void CupSelectionMenuSoundHandler(void) {
    InputSlotIndex inputIndex;
    s32 touchedRectIndex;
    s32 neighborIndex;
    s32 touchedCupIndex;
    int b;
    int a;
    u16 x;
    InputSlot *p;
    InputSlot *q;

    touchedRectIndex = -1;
    inputIndex = UNK_02175628_INDEX_8;
    AdvanceSelectCupGridIndexChange();
    AdvanceSelectCupGridShownCourse();
    b = 0;
    a = 0;
    p = &data_02175674[inputIndex];
    x = data_02175674[inputIndex].mPressedBits;
    if (x == 0 && data_02175680[inputIndex].mPressedBits < 5) {
        a = 1;
    }
    if (a == 0 && data_0217567c[inputIndex].mPressedBits == 0 && x != 0) {
        b = 1;
    }
    if (b != 0) {
        touchedRectIndex =
            jn_ui_checkTouch(CupSelectionMenuInfoPointer->mSelectCupSBnbl, data_02175670[inputIndex].mPressedBits,
                                    data_02175672[inputIndex].mPressedBits);
    }
    q = &gInputUnits[inputIndex];
    if ((u16) (gInputUnits[inputIndex].mPressedBits & PAD_KEY_B) != 0) {
        goto L1;
    }
    b = 0;
    a = 0;
    x = p->mPressedBits;
    if (x == 0 && data_02175680[inputIndex].mPressedBits < 5) {
        a = 1;
    }
    if (a == 0 && data_0217567c[inputIndex].mPressedBits == 0 && x != 0) {
        b = 1;
    }
    if (b == 0) {
        goto L2;
    }
    if (gmenu_checkSelectReturnTouch(data_02175670[inputIndex].mPressedBits,
                                                        data_02175672[inputIndex].mPressedBits) == FALSE) {
        goto L2;
    }
L1:
    if (IsSelectCupGridIndexChangeRunning() != 0) {
        return;
    }
    gmenu_setSeqArcIndex(0xe);
    switch (CupSelectionMenuInfoPointer->mMode) {
        case 0:
        case 1:
            RequestSelectCupGridState11();
            CupSelectionMenuInfoPointer->mResult = 2;
            RequestSelectReturnState3WithSound(0);
            return;
        case 2:
        case 3:
        case 4:
            if (gStruct217B488->field8 == 2 || gStruct217B488->field8 == 3) {
                RequestSelectCupGridState8();
                if (*(vu16 *) 0x027ffc40 == 2) {
                    gmenu_setSeqArcIndex(-1);
                }
                RequestSelectReturnState3WithSound(0);
                return;
            }
            RequestSelectCupGridState11();
            CupSelectionMenuInfoPointer->mResult = 2;
            if (CupSelectionMenuInfoPointer->mMode != 2) {
                RequestSelectReturnState3WithSound(1);
                if (*(vu16 *) 0x027ffc40 == 2) {
                    func_0211f378();
                }
            } else {
                RequestSelectReturnState3WithSound(0);
            }
            return;
    }
    return;
L2:
    if ((u32) touchedRectIndex <= 7) {
        touchedCupIndex = data_0215c8dc[touchedRectIndex];
        if (CupSelectionMenuInfoPointer->mCupsEnabled[touchedCupIndex] == 0) {
            if (*(vu16 *) 0x027ffc40 != 2) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x16);
            }
            return;
        }
        if (CupSelectionMenuInfoPointer->mIndex == touchedCupIndex) {
            CupSelectionMenuInfoPointer->field68 = FALSE;
        }
        CupSelectionMenuInfoPointer->mIndex = touchedCupIndex;
        RequestSelectCupGridState4();
        return;
    }
    if ((u16) (q->mPressedBits & PAD_KEY_A) != 0) {
        RequestSelectCupGridState4();
        CupSelectionMenuInfoPointer->field68 = FALSE;
        return;
    }
    if (mutil_checkKeys(8, PAD_KEY_UP) != 0) {
        a = CupSelectionMenuInfoPointer->mIndex;
        b = gSelectCupGridUpOffsets[a];
        if (b != 0) {
            neighborIndex = a + b;
            if (CupSelectionMenuInfoPointer->mCupsEnabled[neighborIndex] != 0) {
                CupSelectionMenuInfoPointer->mIndex = neighborIndex;
                ResetSelectCupGridShownCourse();
                if (*(vu16 *) 0x027ffc40 != 2) {
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
                }
            }
        }
    } else if (mutil_checkKeys(8, PAD_KEY_DOWN) != 0) {
        a = CupSelectionMenuInfoPointer->mIndex;
        b = gSelectCupGridDownOffsets[a];
        if (b != 0) {
            neighborIndex = a + b;
            if (CupSelectionMenuInfoPointer->mCupsEnabled[neighborIndex] != 0) {
                CupSelectionMenuInfoPointer->mIndex = neighborIndex;
                ResetSelectCupGridShownCourse();
                if (*(vu16 *) 0x027ffc40 != 2) {
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
                }
            }
        }
    } else if (mutil_checkKeys(8, PAD_KEY_LEFT) != 0) {
        a = CupSelectionMenuInfoPointer->mIndex;
        b = gSelectCupGridLeftOffsets[a];
        if (b != 0) {
            neighborIndex = a + b;
            if (CupSelectionMenuInfoPointer->mCupsEnabled[neighborIndex] != 0) {
                CupSelectionMenuInfoPointer->mIndex = neighborIndex;
                ResetSelectCupGridShownCourse();
                if (*(vu16 *) 0x027ffc40 != 2) {
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
                }
            }
        }
    } else if (mutil_checkKeys(8, PAD_KEY_RIGHT) != 0) {
        a = CupSelectionMenuInfoPointer->mIndex;
        b = gSelectCupGridRightOffsets[a];
        if (b != 0) {
            neighborIndex = a + b;
            if (CupSelectionMenuInfoPointer->mCupsEnabled[neighborIndex] != 0) {
                CupSelectionMenuInfoPointer->mIndex = neighborIndex;
                ResetSelectCupGridShownCourse();
                if (*(vu16 *) 0x027ffc40 != 2) {
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
                }
            }
        }
    }
}

void AdvanceSelectCupGridState4(void) {
    AdvanceSelectCupGridIndexChange();
    AdvanceSelectCupGridShownCourse();
    if (CupSelectionMenuInfoPointer->mStateFrames == 5) {
        CupSelectionMenuInfoPointer->field68 = TRUE;
    }
    CupSelectionMenuInfoPointer->mStateFrames = CupSelectionMenuInfoPointer->mStateFrames + 1;
    if (CupSelectionMenuInfoPointer->mStateFrames >= 10 && IsSelectCupGridIndexChangeRunning() == 0) {
        if (CupSelectionMenuInfoPointer->mMode == 0) {
            RequestSelectCupGridState5();
            return;
        }
        func_021185ec();
        CupSelectionMenuInfoPointer->mResult = 1;
        RequestSelectCupGridState11();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState5(void) {
    int isChoisesState1NoState0Request;
    AdvanceSelectCupGridShownCourse();
    isChoisesState1NoState0Request = IsSelectChoisesState1NoState0Request();
    if (isChoisesState1NoState0Request != 0) {
        RequestSelectCupGridState6();
    }
}

void AdvanceSelectCupGridState6(void) {
    int isDone;
    AdvanceSelectCupGridShownCourse();
    isDone = GetSelectChoisesDone();
    if (isDone != 0) {
        RequestSelectCupGridState7();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState7(void) {
    s32 choiceIndex;

    AdvanceSelectCupGridShownCourse();
    if (IsSelectChoisesState0NoState1Request() != 0) {
        choiceIndex = GetSelectChoisesIndex();
        switch (choiceIndex) {
            case 0:
                func_021185ec();
                CupSelectionMenuInfoPointer->mResult = 1;
                RequestSelectCupGridState11();
                RequestSelectReturnState4();
                break;
            case -1:
            case 1:
                RequestSelectCupGridState3();
                break;
        }
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState8(void) {
    int isChoisesState1NoState0Request;
    AdvanceSelectCupGridShownCourse();
    isChoisesState1NoState0Request = IsSelectChoisesState1NoState0Request();
    if (isChoisesState1NoState0Request != 0) {
        RequestSelectCupGridState9();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState9(void) {
    s32 choiceIndex;

    AdvanceSelectCupGridShownCourse();
    if (GetSelectChoisesDone() != 0) {
        RequestSelectCupGridState10();
        if (*(vu16 *) 0x027ffc40 == 2) {
            choiceIndex = GetSelectChoisesIndex();
            switch (choiceIndex) {
                case -1:
                case 0:
                    break;
                case 1:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0xf);
                    break;
            }
        }
    }
}

void AdvanceSelectCupGridState10(void) {
    s32 choiceIndex;

    AdvanceSelectCupGridShownCourse();
    if (IsSelectChoisesState0NoState1Request() != 0) {
        choiceIndex = GetSelectChoisesIndex();
        switch (choiceIndex) {
            case -1:
            case 0:
                RequestSelectCupGridState3();
                break;
            case 1:
                CupSelectionMenuInfoPointer->mResult = 3;
                RequestSelectCupGridState11();
                if (*(vu16 *) 0x027ffc40 == 2) {
                    func_0211f378();
                }
                break;
        }
    }
}

void AdvanceSelectCupGridState11(void) {
    s16 offsetX;
    s16 offsetY;
    s16 negatedOffsetX;
    u16 mainCellCount;
    int i;
    int j;
    int k;

    CupSelectionMenuInfoPointer->mStateFrames = CupSelectionMenuInfoPointer->mStateFrames + 1;
    if (*(vu16 *) 0x027ffc40 != 2) {
        mainCellCount = CupSelectionMenuInfoPointer->mSelectCupMBncl->field6;
        offsetX = mutil_interpolate(1, 0, 0xe0, CupSelectionMenuInfoPointer->mStateFrames, 0xa);
        offsetY = mutil_interpolate(1, 0, -192, CupSelectionMenuInfoPointer->mStateFrames, 0xa);
        if (CupSelectionMenuInfoPointer->mResult == 2 || CupSelectionMenuInfoPointer->mResult == 3 || CupSelectionMenuInfoPointer->mMode == 0) {
            CupSelectionMenuInfoPointer->mBg0Offset = offsetY;
            CupSelectionMenuInfoPointer->mSelectCupMTable[19].mOffsetY = offsetY;
            CupSelectionMenuInfoPointer->mSelectCupMTable[2].mOffsetY = offsetY;
            CupSelectionMenuInfoPointer->mSelectCupMTable[1].mOffsetY = offsetY;
            CupSelectionMenuInfoPointer->mSelectCupMTable[0].mOffsetY = offsetY;
            for (i = 0; i < 8; i++) {
                CupSelectionMenuInfoPointer->mSelectCupMTable[data_0215c83c[i]].mOffsetY = offsetY;
            }
            for (i = 0; i < 4; i++) {
                CupSelectionMenuInfoPointer->mSelectCupMTable[data_0215c7c8[i]].mOffsetY = offsetY;
            }
            for (i = 0; i < 4; i++) {
                CupSelectionMenuInfoPointer->mSelectCupMTable[data_0215c7d0[i]].mOffsetY = offsetY;
                CupSelectionMenuInfoPointer->mSelectCupMTable[mainCellCount + data_0215c7d8[i]].mOffsetY = offsetY;
            }
        }
        CupSelectionMenuInfoPointer->mSelectCupMTable[20].mOffsetY = offsetY;
        negatedOffsetX = -offsetX;
        CupSelectionMenuInfoPointer->mSelectCupSTable[0].mOffsetX = negatedOffsetX;
        CupSelectionMenuInfoPointer->mSelectCupSTable[1].mOffsetX = offsetX;
        CupSelectionMenuInfoPointer->mSelectCupSTable[2].mOffsetX = negatedOffsetX;
        CupSelectionMenuInfoPointer->mSelectCupSTable[3].mOffsetX = offsetX;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 6; j++) {
                CupSelectionMenuInfoPointer->mSelectCupSTable[gSelectCupGridCupCellIndices[i][j]].mOffsetX = -offsetX;
            }
        }
        for (i = 4; i < 8; i++) {
            for (j = 0; j < 6; j++) {
                CupSelectionMenuInfoPointer->mSelectCupSTable[gSelectCupGridCupCellIndices[i][j]].mOffsetX = offsetX;
            }
        }
    }
}

s32 AdvanceSelectCupGrid(void) {
    int i;
    int screenMapIndex;
    u16 *screenMap;

    CupSelectionMenuInfoPointer->mState = CupSelectionMenuInfoPointer->mNextState;
    switch (CupSelectionMenuInfoPointer->mState) {
        case 0:
            AdvanceSelectCupGridState0();
            break;
        case 1:
            AdvanceSelectCupGridState1();
            break;
        case 2:
            AdvanceSelectCupGridState2();
            break;
        case 3:
            CupSelectionMenuSoundHandler();
            break;
        case 4:
            AdvanceSelectCupGridState4();
            break;
        case 5:
            AdvanceSelectCupGridState5();
            break;
        case 6:
            AdvanceSelectCupGridState6();
            break;
        case 7:
            AdvanceSelectCupGridState7();
            break;
        case 8:
            AdvanceSelectCupGridState8();
            break;
        case 9:
            AdvanceSelectCupGridState9();
            break;
        case 10:
            AdvanceSelectCupGridState10();
            break;
        case 11:
            AdvanceSelectCupGridState11();
            break;
    }
    UpdateSelectCupGridCupCells();
    UpdateSelectCupGridCourseCells();
    if (*(vu16 *) 0x027ffc40 != 2) {
        if (CupSelectionMenuInfoPointer->mCupPicturePending != FALSE && func_020d0ec4() != FALSE) {
            screenMap = GetCupPictureNscrData();
            NNS_GfdRegisterNewVramTransferTask(0xf, 0, GetCupPictureNclrData(), 0xe0);
            NNS_GfdRegisterNewVramTransferTask(4, 0x20, GetCupPictureNcgrData(), 0xdc0);
            for (i = 0; i < 11; i++) {
                screenMapIndex = (i + 8) * 0x20 + 0x16;
                NNS_GfdRegisterNewVramTransferTask(8, screenMapIndex * 2, screenMap + screenMapIndex, 0x14);
            }
            CupSelectionMenuInfoPointer->mCupPicturePending = FALSE;
        }
        jn_ui_renderElements(CupSelectionMenuInfoPointer->mSelectCupMBncl, CupSelectionMenuInfoPointer->mSelectCupMNcer,
                        CupSelectionMenuInfoPointer->mSelectCupMBnll, CupSelectionMenuInfoPointer->mMainOam, CupSelectionMenuInfoPointer->mSelectCupMTable);
        jn_ui_renderElements(CupSelectionMenuInfoPointer->mSelectCupSBncl, CupSelectionMenuInfoPointer->mSelectCupSNcer, NULL, CupSelectionMenuInfoPointer->mSubOam,
                        CupSelectionMenuInfoPointer->mSelectCupSTable);
    } else {
        AdvanceSelectRaceRuleWait();
    }
    if (CupSelectionMenuInfoPointer->mState == 0xb && CupSelectionMenuInfoPointer->mStateFrames >= 0xa) {
        return CupSelectionMenuInfoPointer->mResult;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on
void WriteSelectCupGridRegisters(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value0 = CupSelectionMenuInfoPointer->mBg0Offset;
    value0 = 0u - (value0);
    value1 = (value0 << 16);
    value0 = 0x1ff0000u;
    value1 = (value1) & (value0);
    value0 = 0x4000010u;
    *(u32 *) ((value0) + 0u) = value1;
    value1 = 0x4000000u;
    value2 = *(const u32 *) ((value1) + 0u);
    value0 = 0xffff1fffu;
    value2 = (value2) & (value0);
    *(u32 *) ((value1) + 0u) = value2;
}
#pragma thumb off
