#include "Main/Unknown/code_0202bb80.h"

#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_0202cc78.h"
#include "Main/Unknown/code_0202cca0.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020adb04.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_02120294.h"
#include "Main/Unknown/code_02121e24.h"
#include "Main/Unknown/code_02122734.h"
#include "Main/Unknown/code_02122794.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "code_02148950.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "code_0213ecf8.h"
#include "code_02016468.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "code_0202056c.h"
#include "registers.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02025e28.h"
#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_02025f80.h"

#pragma thumb on

void SetEntrySlot(s32 entryIndex, s32 slot) {
    gPlayerEntryList->mEntries[entryIndex].mSlotMove.mMoveFrames = 10;
    gPlayerEntryList->mEntries[entryIndex].mSlotMove.mToSlot = slot;
    gPlayerEntryList->mEntries[entryIndex].mSlotMove.mTargetSlot =
        gPlayerEntryList->mEntries[entryIndex].mSlotMove.mToSlot;
    gPlayerEntryList->mEntries[entryIndex].mSlotMove.mFromSlot =
        gPlayerEntryList->mEntries[entryIndex].mSlotMove.mTargetSlot;
}

// Sets the target slot; asking for the slot it came from turns the running move around.
void SetEntryTargetSlot(s32 entryIndex, s32 slot) {
    EntrySlotMove *entry;
    entry = &gPlayerEntryList->mEntries[entryIndex].mSlotMove;
    entry->mTargetSlot = slot;
    if (entry->mTargetSlot == entry->mFromSlot) {
        entry->mFromSlot = entry->mToSlot;
        entry->mToSlot = entry->mTargetSlot;
        entry->mMoveFrames = 10 - entry->mMoveFrames;
    }
}

void ResetEntrySlots(void) {
    s32 i;
    i = 0;
    do {
        SetEntrySlot(i, 0);
        SetEntryTargetSlot(i, 1);
        i++;
    } while (i < 8);
}

#pragma thumb off

#pragma thumb on

// Moves each entry toward its target slot one slot at a time, each move taking 10 frames.
void AdvanceEntrySlots(void) {
    s32 i;
    EntrySlotMove *move;
    for (i = 0; i < 8; i++) {
        move = &gPlayerEntryList->mEntries[i].mSlotMove;
        if (move->mMoveFrames < 10) {
            move->mMoveFrames++;
        } else if (move->mTargetSlot != move->mToSlot) {
            move->mMoveFrames = 0;
            move->mFromSlot = move->mToSlot;
            if (move->mTargetSlot > move->mToSlot) {
                move->mToSlot++;
            } else {
                move->mToSlot--;
            }
        }
    }
}

void func_0202cb68(s32 entryIndex) {
    switch (gPlayerEntryList->mEntries[entryIndex].mSlotMove.mTargetSlot) {
        case 0:
            SetEntryTargetSlot(entryIndex, 1);
            break;
        case 3:
            SetEntryTargetSlot(entryIndex, 2);
            break;
    }
}

void func_0202cb2c(s32 entryIndex) {
    switch (gPlayerEntryList->mEntries[entryIndex].mSlotMove.mTargetSlot) {
        case 1:
            SetEntryTargetSlot(entryIndex, 0);
            break;
        case 2:
            SetEntryTargetSlot(entryIndex, 3);
            break;
    }
}

#pragma thumb off

static inline s32 func_0202bb80_inline(s32 index) {
    return gStruct217B488->mShuffledIndices[index];
}

#pragma thumb on

void AdvancePlayerEntryListOffsets(void) {
    PlayerEntryList *entryList = gPlayerEntryList;
    CellFileSet *fileSet = &entryList->mParts;
    s32 i;
    s32 cellCount = fileSet->mCellLayout->mUnk_06;
    s32 onesCell;
    s32 d;
    s16 offsetX;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        interp_update(&gPlayerEntryList->mInterpolations[0]);
        fileSet->mCellTable[25].mOffsetY = interp_interpolate(&gPlayerEntryList->mInterpolations[0]);
        interp_update(&gPlayerEntryList->mInterpolations[3]);
        fileSet->mCellTable[64].mOffsetY = interp_interpolate(&gPlayerEntryList->mInterpolations[3]);
        fileSet->mCellTable[63].mOffsetY = fileSet->mCellTable[64].mOffsetY;
        fileSet->mCellTable[62].mOffsetY = fileSet->mCellTable[63].mOffsetY;
        fileSet->mCellTable[61].mOffsetY = fileSet->mCellTable[62].mOffsetY;
        fileSet->mCellTable[60].mOffsetY = fileSet->mCellTable[61].mOffsetY;
        fileSet->mCellTable[59].mOffsetY = fileSet->mCellTable[60].mOffsetY;
    }
    interp_update(&gPlayerEntryList->mInterpolations[1]);
    offsetX = interp_interpolate(&gPlayerEntryList->mInterpolations[1]);
    onesCell = GetTimerOnesCellIndex();
    fileSet->mCellTable[onesCell].mOffsetX = offsetX;
    fileSet->mCellTable[GetTimerTensCellIndex()].mOffsetX = fileSet->mCellTable[onesCell].mOffsetX;
    interp_update(&gPlayerEntryList->mInterpolations[2]);
    AdvanceEntrySlots();
    for (i = 0; i < 8; i++) {
        offsetX = mutil_interpolate(1, gEntrySlotOffsetsX[gPlayerEntryList->mEntries[i].mSlotMove.mFromSlot],
                                 gEntrySlotOffsetsX[gPlayerEntryList->mEntries[i].mSlotMove.mToSlot],
                                 gPlayerEntryList->mEntries[i].mSlotMove.mMoveFrames, 10);
        fileSet->mCellTable[cellCount + gEntryLabelTextRows[i].mUnk_00].mOffsetX = offsetX;
        fileSet->mCellTable[gEntryCellIndices[i].mKartCellIndex].mOffsetX =
            fileSet->mCellTable[cellCount + gEntryLabelTextRows[i].mUnk_00].mOffsetX;
        fileSet->mCellTable[gEntryCellIndices[i].mCharacterCellIndex].mOffsetX =
            fileSet->mCellTable[gEntryCellIndices[i].mKartCellIndex].mOffsetX;
        fileSet->mCellTable[gEntryCellIndices[i].mUnk_00].mOffsetX =
            fileSet->mCellTable[gEntryCellIndices[i].mCharacterCellIndex].mOffsetX;
        if (i == gPlayerEntryList->mEntryIndex) {
            fileSet->mCellTable[func_0202cca0()].mOffsetX = offsetX;
        }
    }
}

static inline void func_0202c0d4_inline(const void *source, void *destination, s32 byteCount) {
    MIi_CpuCopy16(source, destination, byteCount);
}

void func_0202c8dc(void) {
    void *text = jn_msg_getMessage(m2d_get2dArcFile(aCommon_bmg_29), 0x72);
    u16 u[3];
    u16 *w = &u[1];
    s32 i;
    w[0] = 0;
    w[1] = 0;
    for (i = gPlayerEntryList->mPlayerCount; i < 8; i++) {
        u[0] = 0;
        MIi_CpuClear16(u[0], gPlayerEntryList->mEntries[i].mName, 0x16);
        MIi_CpuCopy16(text, gPlayerEntryList->mEntries[i].mName, 0x14);
        u[1] = i + 0x31 - gPlayerEntryList->mPlayerCount;
        wcsncat(gPlayerEntryList->mEntries[i].mName, w, 1);
    }
}

void PrintEntryName(s32 entryIndex, u16 *name) {
    PlayerEntryList *entryList = gPlayerEntryList;
    u16 text[12];
    text[0] = 0;
    MIi_CpuClear16(text[0], &text[1], 0x16);
    name[10] = 0;
    CopyTextWithinWidth(name, &text[1]);
    jn_ui_212426C(0, gEntryLabelTextRows[entryIndex].mUnk_00, entryList->mParts.mLabelLayout, &text[1],
                  entryList->mParts.mCellLayout, entryList->mParts.mCellTable);
}

void InitPlayerEntryList(void *parentHeap, void *mainOam) {
    void *heap = heap_createSubFrmHeap(parentHeap);
    s32 objSizeLeft;
    CellFileSet *fileSet;
    s32 i;
    gPlayerEntryList = heap_alloc(heap, 0x258);
    MemFillWordsByBlock_inline(gPlayerEntryList, 0x258);
    gPlayerEntryList->mHeap = heap;
    gPlayerEntryList->mMainOam = mainOam;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        gEntryCellIndices = gDownloadEntryCellIndices;
        gEntryLabelTextRows = gDownloadEntryLabelTextRows;
        gCharacterCellIndices = gDownloadCharacterCellIndices;
        gTimerDigitCellIndices = a_01234567;
    } else {
        gEntryCellIndices = gNormalEntryCellIndices;
        gEntryLabelTextRows = gNormalEntryLabelTextRows;
        gCharacterCellIndices = gNormalCharacterCellIndices;
        gTimerDigitCellIndices = a012345678;
    }
    objSizeLeft = GX_GetSizeOfOBJ();
    fileSet = &gPlayerEntryList->mParts;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        mutil2_loadLayout(fileSet, aMbSelect_menu_etc_download_m_nce_ncgr, aMbSelect_menu_etc_download_m_nce_ncer, aMbSelect_menu_etc_download_m_o_nclr,
                          aMbSelect_menu_etc_download_m_bncl, aMbSelect_menu_etc_download_m_bnll, NULL, arc_getSceneArcFile);
    } else {
        mutil2_loadLayout(fileSet, aSelect_menu_etc_m_nce_ncgr_0, aSelect_menu_etc_m_nce_ncer_0, aSelect_menu_etc_m_o_nclr_0, aSelect_menu_etc_m_bncl,
                          aSelect_menu_etc_m_bnll, NULL, arc_get2dArcFile);
    }
    jn_ui_initLayout(gPlayerEntryList->mHeap, fileSet->mCellLayout, fileSet->mLabelLayout, &fileSet->mCellTable);
    for (i = 0; i < 8; i++) {
        objSizeLeft -= mutil2_initLabel(0, gPlayerEntryList->mHeap, fileSet, &gEntryLabelTextRows[i], objSizeLeft);
    }
    for (i = 0; i < 8; i++) {
        fileSet->mCellTable[gEntryCellIndices[i].mKartCellIndex].mVisible = 0;
        fileSet->mCellTable[gEntryCellIndices[i].mCharacterCellIndex].mVisible =
            fileSet->mCellTable[gEntryCellIndices[i].mKartCellIndex].mVisible;
    }
    ResetEntrySlots();
    interp_init(&gPlayerEntryList->mInterpolations[0], 0, 10, -0x40, 0);
    interp_init(&gPlayerEntryList->mInterpolations[2], 3, 10, 0x60, 0);
    interp_init(&gPlayerEntryList->mInterpolations[3], 3, 10, 0x40, 0);
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        mutil2_loadLayout(&gPlayerEntryList->mTitleParts, aSelect_menu_etc_title_m_nce_ncgr_0, aSelect_menu_etc_title_m_nce_ncer_0, NULL,
                          aSelect_menu_etc_title_m_bncl, NULL, NULL, arc_get2dArcFile);
    }
    gPlayerEntryList->mSetupRequested = TRUE;
    heap_adjustSubFrmHeap(gPlayerEntryList->mHeap);
}

void SetupPlayerEntryList(s32 mode, s32 screenKind) {
    PlayerEntryList *entryList = gPlayerEntryList;
    CellFileSet *fileSet = &entryList->mParts;
    CellFileSet *titleFileSet = &entryList->mTitleParts;
    s32 n;
    s32 i;
    s32 j;
    BOOL t;
    s32 onesCell;
    vu16 clearValue;
    vu16 secondClearValue;
    u8 screenMapFileSet[0x24];
    entryList->mMode = mode;
    gPlayerEntryList->mScreenKind = screenKind;
    if (gPlayerEntryList->mSetupRequested != FALSE) {
        gPlayerEntryList->mTimer = 0x708;
        interp_init(&gPlayerEntryList->mInterpolations[1], 0, 10, 0x40, 0);
        switch (gPlayerEntryList->mMode) {
            case 0:
                gPlayerEntryList->mPlayerCount = 1;
                gPlayerEntryList->mEntryIndex = 0;
                gPlayerEntryList->mUnk_208 = 1;
                MIi_CpuCopy16(gSaveData->mFirstBlock->mPlayerName,
                              gPlayerEntryList->mEntries[gPlayerEntryList->mEntryIndex].mName, 0x14);
                func_0202c8dc();
                break;
            case 1:
                t = TRUE;
                if (gStruct217AA00->mUnk_0004 != 8 && gStruct217AA00->mUnk_0004 != 9) {
                    t = FALSE;
                }
                if (t != FALSE) {
                    i = MATH_CountPopulation(gStruct217AA00->mParticipantMask);
                } else {
                    i = 0;
                }
                gPlayerEntryList->mPlayerCount = (u8) i;
                if (gStruct217AA00->mUnk_0000 == 2) {
                    i = gStruct217AA00->mOwnIndex;
                } else {
                    i = 0;
                }
                gPlayerEntryList->mEntryIndex = gStruct217AA00->mUnk_1e52[(u16) i].mEntryIndex;
                for (j = 0; j < (n = gPlayerEntryList->mPlayerCount); j++) {
                    menu_getRaceConfig()->mEntries[j].mPlayerKind = PLAYER_KIND_HUMAN;
                    clearValue = 0;
                    MIi_CpuClear16(clearValue, gPlayerEntryList->mEntries[j].mName, 0x16);
                    func_0202c0d4_inline(gStruct217AA00->mUnk_1e8c[(u16) j] == 0xffff
                                             ? (void *) 0
                                             : &gStruct217AA00->mUnk_045c[gStruct217AA00->mUnk_1e8c[(u16) j]],
                                         gPlayerEntryList->mEntries[j].mName, 0x14);
                }
                for (; n < 8; n++) {
                    SetEntryTargetSlot(n, 0);
                }
                func_0202c8dc();
                for (i = 0; i < 8; i++) {
                    gPlayerEntryList->mUnk_1dc[i] = 0;
                    gPlayerEntryList->mUnk_1bc[i] = gPlayerEntryList->mUnk_1dc[i];
                }
                break;
            case 2:
                gPlayerEntryList->mPlayerCount = GetSessionKartCount();
                gPlayerEntryList->mEntryIndex = menu_getRaceConfigField10C();
                for (i = 0; i < (n = gPlayerEntryList->mPlayerCount); i++) {
                    secondClearValue = 0;
                    MIi_CpuClear16(secondClearValue, gPlayerEntryList->mEntries[i].mName, 0x16);
                    if (GetIndexOfPackedIndex(i) >= 0) {
                        func_0202c0d4_inline(GetPlayerRecordName((u8) GetIndexOfPackedIndex(i)),
                                             gPlayerEntryList->mEntries[i].mName, 0x14);
                    }
                }
                for (; n < 8; n++) {
                    SetEntryTargetSlot(n, 0);
                }
                for (i = 0; i < 4; i++) {
                    gPlayerEntryList->mUnk_1ac[i] = 0;
                }
                for (i = 0; i < 8; i++) {
                    gPlayerEntryList->mUnk_1dc[i] = 0;
                    gPlayerEntryList->mUnk_1bc[i] = gPlayerEntryList->mUnk_1dc[i];
                }
                break;
        }
    }
    if (gPlayerEntryList->mScreenKind == PLAYER_ENTRY_LIST_RACE_RULE) {
        for (i = 0; i < 8; i++) {
            fileSet->mCellTable[gEntryCellIndices[i].mKartCellIndex].mVisible = 0;
        }
        if (gPlayerEntryList->mMode == 1) {
            for (i = gPlayerEntryList->mPlayerCount; i < 8; i++) {
                j = menu_getRaceConfig()->mEntries[i].mCharacterIndex;
                func_02025c48(gEntryCellIndices[i].mCharacterCellIndex, gCharacterCellIndices[j], fileSet->mCellLayout);
                fileSet->mCellTable[gEntryCellIndices[i].mCharacterCellIndex].mVisible = 1;
            }
        }
        reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0xd08;
        reg_G2_BG1CNT = (reg_G2_BG1CNT & 0x43) | 0xc00;
        if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
            mutil2_initBgGraphics(0, screenMapFileSet, aMbSelect_menu_etc_download_m_b_ncgr, aMbSelect_menu_etc_download_m_b_nclr, aMbSelect_menu_etc_download_m_bg_00_ns, 0,
                          arc_getSceneArcFile);
            mutil2_initBgGraphics(0, screenMapFileSet, aMbSelect_menu_etc_download_m_b_ncgr_0, aMbSelect_menu_etc_download_m_b_nclr_0, aMbSelect_menu_etc_download_m_bg_01__0, 1,
                          arc_getSceneArcFile);
        } else {
            mutil2_initBgGraphics(0, screenMapFileSet, aSelect_menu_etc_m_b_ncgr_0, aSelect_menu_etc_m_b_nclr_0, aSelect_menu_etc_m_bg_00_nscr_0, 0,
                          arc_get2dArcFile);
            mutil2_initBgGraphics(0, screenMapFileSet, aSelect_menu_etc_m_b_ncgr_1, aSelect_menu_etc_m_b_nclr_1, aSelect_menu_etc_m_bg_01_nscr_0, 1,
                          arc_get2dArcFile);
        }
    } else if (gPlayerEntryList->mScreenKind == PLAYER_ENTRY_LIST_KART) {
        interp_setState(&gPlayerEntryList->mInterpolations[3], 0);
    }
    if (gPlayerEntryList->mUnk_20c != FALSE) {
        for (i = 0; i < 8; i++) {
            if (i < gPlayerEntryList->mPlayerCount || gPlayerEntryList->mUnk_208 != 0) {
                func_0202cb68(i);
            }
        }
        gPlayerEntryList->mUnk_20c = FALSE;
    }
    NNS_GfdRegisterNewVramTransferTask(0x13, 0, ((Unk02174e3c_00 *) gPlayerEntryList->mParts.mChars)->mUnk_14,
                    ((Unk02174e3c_00 *) gPlayerEntryList->mParts.mChars)->mUnk_10);
    NNS_GfdRegisterNewVramTransferTask(0xe, 0, ((Unk0212463c_d *) fileSet->mPalette)->mUnk_0c, 0x1a0);
    NNS_GfdRegisterNewVramTransferTask(0xe, 0x1c0, ((Unk0212463c_d *) fileSet->mPalette)->mUnk_0c + 0x1c0, 0x40);
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        jn_ui_fillPlaceholder(gTitleCellIndices[gPlayerEntryList->mScreenKind], titleFileSet->mCells, titleFileSet->mChars,
                       titleFileSet->mCellLayout, 0, 0x19, fileSet->mCells, fileSet->mCellLayout);
        interp_setState(&gPlayerEntryList->mInterpolations[0], 0);
    }
    func_02025c6c(func_0202cca0(), gEntryCellIndices[gPlayerEntryList->mEntryIndex].mUnk_00, fileSet->mCellLayout);
    for (i = 0; i < 8; i++) {
        PrintEntryName(i, gPlayerEntryList->mEntries[i].mName);
    }
    interp_init(&gPlayerEntryList->mInterpolations[2], 3, 10, 0x60, 0);
    gPlayerEntryList->mUseTeams = 0;
    n = 0;
    if (gPlayerEntryList->mScreenKind != PLAYER_ENTRY_LIST_RACE_RULE && gPlayerEntryList->mMode != 0) {
        n = 1;
    }
    gPlayerEntryList->mTimerEnabled = n;
    onesCell = GetTimerOnesCellIndex();
    fileSet->mCellTable[onesCell].mVisible = gPlayerEntryList->mTimerEnabled;
    fileSet->mCellTable[GetTimerTensCellIndex()].mVisible = fileSet->mCellTable[onesCell].mVisible;
    gPlayerEntryList->mSetupRequested = FALSE;
}

void AdvancePlayerEntryList(void) {
    CellFileSet *fileSet = &gPlayerEntryList->mParts;
    PlayerEntryList *entryList;
    s32 i;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    BOOL g;
    if (mbright_isFadedIn() == 0) {
        return;
    }
    if (gPlayerEntryList->mTimerEnabled != 0) {
        if (gPlayerEntryList->mTimer != 0) {
            gPlayerEntryList->mTimer--;
            a = gPlayerEntryList->mTimer;
            b = a + 0x3c;
            c = b / 0x3c;
            if (a == 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x51);
            } else if (b % 0x3c == 0 && c <= 4) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x50);
            }
        } else {
            c = 0;
        }
        d = GetTimerTensCellIndex();
        fileSet->mCellTable[d].mVisible = c >= 10 ? 1 : 0;
        d = GetTimerTensCellIndex();
        func_02025c48(d, gTimerDigitCellIndices[c / 10 % 10], fileSet->mCellLayout);
        d = GetTimerOnesCellIndex();
        func_02025c48(d, gTimerDigitCellIndices[c % 10], fileSet->mCellLayout);
    }
    entryList = gPlayerEntryList;
    if (entryList->mScreenKind != PLAYER_ENTRY_LIST_RACE_RULE) {
        switch (entryList->mMode) {
            case 0: {
                s32 a;
                s32 b;

                for (i = 0; i < 8; i++) {
                    a = menu_getRaceConfig()->mEntries[i].mCharacterIndex;
                    if (a == -1) {
                        d = 0;
                    } else {
                        d = 1;
                    }
                    b = menu_getRaceConfig()->mEntries[i].mUnk_14;
                    if (d != 0) {
                        func_02025c48(gEntryCellIndices[i].mCharacterCellIndex, gCharacterCellIndices[a],
                                      fileSet->mCellLayout);
                    }
                    fileSet->mCellTable[gEntryCellIndices[i].mCharacterCellIndex].mVisible = d;
                    fileSet->mCellTable[gEntryCellIndices[i].mKartCellIndex].mVisible = b;
                }
            } break;
            case 1: {
                s32 d;

                for (i = 0; i < gPlayerEntryList->mPlayerCount; i++) {
                    if (gStruct217AA00->mUnk_0004 == 8 &&
                        (gStruct217AA00->mParticipantMask & (1 << gStruct217AA00->mUnk_1e8c[(u16) i])) != 0) {
                        c = gStruct217AA00->mUnk_15c8[gStruct217AA00->mUnk_1e8c[(u16) i]].mUnk_00[5];
                    } else {
                        c = 0;
                    }
                    if (c == 0xff) {
                        fileSet->mCellTable[gEntryCellIndices[i].mKartCellIndex].mVisible = 0;
                        fileSet->mCellTable[gEntryCellIndices[i].mCharacterCellIndex].mVisible =
                            fileSet->mCellTable[gEntryCellIndices[i].mKartCellIndex].mVisible;
                        menu_getRaceConfig()->mEntries[i].mCharacterIndex = -1;
                        menu_getRaceConfig()->mEntries[i].mKartIndex = -1;
                        menu_getRaceConfig()->mEntries[i].mUnk_14 = 0;
                        gPlayerEntryList->mUnk_1dc[i] = 0;
                        gPlayerEntryList->mUnk_1bc[i] = gPlayerEntryList->mUnk_1dc[i];
                    } else if ((c & 0x40) != 0) {
                        d = c & 0x3f;
                        if (d == 0xc) {
                            func_02025c48(gEntryCellIndices[i].mCharacterCellIndex,
                                          gCharacterCellIndices[d] + func_0202bb80_inline(i), fileSet->mCellLayout);
                        } else {
                            func_02025c48(gEntryCellIndices[i].mCharacterCellIndex, gCharacterCellIndices[d],
                                          fileSet->mCellLayout);
                        }
                        fileSet->mCellTable[gEntryCellIndices[i].mCharacterCellIndex].mVisible = 1;
                        menu_getRaceConfig()->mEntries[i].mCharacterIndex = d;
                        if (gPlayerEntryList->mEntryIndex != i && gPlayerEntryList->mUnk_1bc[i] == 0) {
                            func_0202cca4(d, 0);
                            gPlayerEntryList->mUnk_1bc[i] = 1;
                        }
                        if ((c & 0x80) != 0) {
                            e = func_02025e60(d);
                            fileSet->mCellTable[gEntryCellIndices[i].mKartCellIndex].mVisible = 1;
                            menu_getRaceConfig()->mEntries[i].mKartIndex = e;
                            menu_getRaceConfig()->mEntries[i].mUnk_14 = 1;
                        }
                    } else if ((c & 0x80) != 0) {
                        fileSet->mCellTable[gEntryCellIndices[i].mKartCellIndex].mVisible = 1;
                        menu_getRaceConfig()->mEntries[i].mKartIndex = c & 0x3f;
                        menu_getRaceConfig()->mEntries[i].mUnk_14 = 1;
                        if (gPlayerEntryList->mEntryIndex != i && gPlayerEntryList->mUnk_1dc[i] == 0) {
                            func_0202cca4(menu_getRaceConfig()->mEntries[i].mCharacterIndex, 1);
                            gPlayerEntryList->mUnk_1dc[i] = 1;
                        }
                    }
                }
            } break;
            case 2: {
                s32 e;

                for (i = 0; i < gPlayerEntryList->mPlayerCount; i++) {
                    if (GetKartMaskBitOfPackedIndex(i) == 0) {
                        func_02025c48(gEntryCellIndices[i].mCharacterCellIndex, 0x2e, fileSet->mCellLayout);
                        fileSet->mCellTable[gEntryCellIndices[i].mCharacterCellIndex].mVisible = 1;
                        fileSet->mCellTable[gEntryCellIndices[i].mKartCellIndex].mVisible = 0;
                        if (gPlayerEntryList->mUnk_1ac[i] == 0) {
                            gPlayerEntryList->mUnk_1ac[i] = 1;
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x52);
                        }
                    } else {
                        e = GetWiFiSessionCharacterIndex((u8) GetIndexOfPackedIndex(i));
                        f = GetWiFiSessionKartIndex((u8) GetIndexOfPackedIndex(i));
                        if (e == -1) {
                            d = 0;
                        } else {
                            d = 1;
                        }
                        if (f == -1) {
                            g = FALSE;
                        } else {
                            g = TRUE;
                        }
                        if (d != 0) {
                            func_02025c48(gEntryCellIndices[i].mCharacterCellIndex, gCharacterCellIndices[e],
                                          fileSet->mCellLayout);
                        }
                        fileSet->mCellTable[gEntryCellIndices[i].mCharacterCellIndex].mVisible = d;
                        fileSet->mCellTable[gEntryCellIndices[i].mKartCellIndex].mVisible = g;
                        if (gPlayerEntryList->mEntryIndex != i) {
                            if (gPlayerEntryList->mUnk_1bc[i] == 0 && d != 0) {
                                func_0202cca4(e, 0);
                                if (g != FALSE) {
                                    gPlayerEntryList->mUnk_1dc[i] = 1;
                                }
                            } else if (gPlayerEntryList->mUnk_1dc[i] == 0 && g != FALSE) {
                                func_0202cca4(e, 1);
                            }
                            gPlayerEntryList->mUnk_1bc[i] = d;
                            gPlayerEntryList->mUnk_1dc[i] = g;
                        }
                    }
                }
            } break;
        }
    }
    AdvancePlayerEntryListOffsets();
    jn_ui_renderElements(fileSet->mCellLayout, fileSet->mCells, fileSet->mLabelLayout, gPlayerEntryList->mMainOam,
                    fileSet->mCellTable);
}

#pragma thumb off
