#include "Main/Ui/ChoisesS.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020adb04.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_020b2540.h"
#include "Main/Unknown/code_020b3260.h"
#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ad000.h"
#include "Main/Unknown/code_020b2000.h"
#include "Main/Unknown/code_020b3000.h"
#include "g2d_CharCanvas.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020b255c.h"
#include "Main/Unknown/code_020b2c68.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020b2b24.h"
#include "Main/Unknown/code_020b2b54.h"
#include "Main/Unknown/code_020b3278.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_02055000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Race/RaceStartSequence.h"
#include "Main/Unknown/code_020f36d8.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_020b19f8.h"
#include "Main/Unknown/code_020c3da0.h"
#include "Main/Unknown/code_020c5db0.h"
#include "Main/Unknown/code_020c5e30.h"
#include "Main/Unknown/code_020c7000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_020b41e8.h"
#include "Main/Unknown/code_020c3000.h"
#include "Main/Unknown/code_020c3db4.h"
#include "Main/Kart/KartTimes.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_0205f000.h"
#include "Main/Unknown/code_02133000.h"

// placeholder: the names of InitChoisesS's screens as file-scope arrays; this declaration order gives the original's
// order of them in .data.
static char sChoisesSNscrName6[] = "choises_s_6.NSCR";
static char sChoisesSNscrName1[] = "choises_s_1.NSCR";
static char sChoisesSNscrName5[] = "choises_s_5.NSCR";
static char sChoisesSNscrName4[] = "choises_s_4.NSCR";
static char sChoisesSNscrName2[] = "choises_s_2.NSCR";
static char sChoisesSNscrName3[] = "choises_s_3.NSCR";

#pragma optimize_for_size on

#pragma thumb on
void *GetChoisesSValueMessage(s32 listIndex, s32 value) {
    s32 entryNumbers[11] = {0x5d, 0x67, 0x62, 0x64, 0x65, 0x66, 0x69, 0x62, 0x61, 0x5f, 0x75};

    if (func_020b24e4() == 2) {
        entryNumbers[0] = 0x6a;
        entryNumbers[8] = 0x63;
    }
    if (listIndex != 0) {
        entryNumbers[2] = 0x60;
    }
    return GetBmgEntry(FindFileInLoadedArchivesWrapper("common.bmg"), entryNumbers[value]);
}

void ClearChoisesSListValueCounts(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gChoisesS->mLists[i].mValueCount = 0;
    }
}

void AppendChoisesSListValue(s32 listIndex, s32 value) {
    s32 valueCount;

    valueCount = gChoisesS->mLists[listIndex].mValueCount;
    gChoisesS->mLists[listIndex].mValueCount = valueCount + 1;
    gChoisesS->mLists[listIndex].mValues[valueCount] = value;
}

s32 MoveChoisesSSelectedValue(s32 step) {
    s32 selectedIndex = 0;
    s32 valueCount;
    s32 listIndex;
    ChoisesS *choisesS;

    if (func_020b2e98() != 0) {
        listIndex = GetChoisesSListIndex();
        valueCount = gChoisesS->mLists[listIndex].mValueCount;
        for (; selectedIndex < valueCount; selectedIndex++) {
            if (gChoisesS->mSelectedValue == gChoisesS->mLists[listIndex].mValues[selectedIndex]) {
                break;
            }
        }
        if (valueCount == 1) {
            step = 0;
        } else if (valueCount == 2) {
            if (step != 0 && selectedIndex + step >= 0 && selectedIndex + step < valueCount) {
                gChoisesS->mCycleFrames = 0;
                StartSoundOncePerFrame(0);
            } else {
                step = 0;
            }
        } else if (step != 0) {
            gChoisesS->mCycleFrames = 0;
            StartSoundOncePerFrame(0);
        }
        choisesS = gChoisesS;
        choisesS->mSelectedValue =
            choisesS->mLists[listIndex].mValues[(valueCount + (selectedIndex + step)) % valueCount];
    }
    return selectedIndex;
}

static inline ChoisesS *func_020b302c_inline(void) {
    return gChoisesS;
}

u32 func_020b302c(void) {
    u32 touched = 0;
    s32 valueCount;
    s32 listIndex;
    s32 valueIndex;
    PairRect valueRects[6];
    s32 firstRectRow;
    s32 top;

    if (func_020b2e98() != 0) {
        MoveChoisesSSelectedValue(0);
        listIndex = GetChoisesSListIndex();
        valueCount = gChoisesS->mLists[listIndex].mValueCount;
        for (valueIndex = 0, firstRectRow = 0xc - valueCount * 2; valueIndex < valueCount; valueIndex++) {
            top = (firstRectRow + valueIndex * 4) * 8 + 6;
            valueRects[valueIndex].mMinX = 8;
            valueRects[valueIndex].mMaxX = 0xf8;
            valueRects[valueIndex].mMinY = top;
            valueRects[valueIndex].mMaxY = top + 0x16;
        }
        for (valueIndex = 0; valueIndex < valueCount; valueIndex++) {
            if (IsNewPairInRect(func_020b2b54(), valueRects[valueIndex]) != 0) {
                if (gChoisesS->mSelectedValue != func_020b302c_inline()->mLists[listIndex].mValues[valueIndex]) {
                    gChoisesS->mSelectedValue = gChoisesS->mLists[listIndex].mValues[valueIndex];
                    MoveChoisesSSelectedValue(0);
                } else {
                    gChoisesS->mUnk_010 = TRUE;
                }
                touched = 1;
            }
        }
        if (touched != 0) {
            if (gChoisesS->mSelectedValue == 0) {
                func_02105c4c();
            } else {
                StartChoisesSSelectedValueSeq();
            }
        }
    }
    return touched;
}

void ResetChoisesSSelection(void) {
    ChoisesS *choisesS;

    gChoisesS->mPickedValue = 0;
    choisesS = gChoisesS;
    choisesS->mSelectedValue = choisesS->mLists[GetChoisesSListIndex()].mValues[0];
}

void func_020b2f88(s32 openFlag) {
    if (gChoisesS->mPickLocked != 0) {
        return;
    }
    if (openFlag != 0 && func_020b2e98() == 0) {
        if (func_020b29c4() != 0) {
            gChoisesS->mOpenDuringRace = openFlag;
        } else if (func_020b2b70() != 0) {
            gChoisesS->mUnk_008 = openFlag;
        } else {
            return;
        }
        ResetChoisesSSelection();
    } else if (openFlag == 0 && func_020b2e98() != 0) {
        if (func_020b29c4() != 0) {
            gChoisesS->mOpenDuringRace = openFlag;
        } else if (func_020b2b70() != 0) {
            gChoisesS->mUnk_008 = openFlag;
        } else {
            return;
        }
    }
    if (gChoisesS->mPickedValue != 0) {
        gChoisesS->mPickLocked = 1;
    }
}

u32 func_020b2f58(void) {
    if ((GetMissionRunTableRow() == 6 && GetMissionRunTableColumn() == 9) ||
        (GetMissionRunTableRow() == 7 && GetMissionRunTableColumn() == 9)) {
        return 1;
    }
    return 0;
}
#pragma thumb off

s8 GetMissionRunTableRow(void) {
    RaceSetup *raceSetup = gRaceSetup;

    if (raceSetup->mMode == MODE_MISSION_RUN) {
        return raceSetup->mMissionTableRow;
    }
    return -1;
}

s8 GetMissionRunTableColumn(void) {
    RaceSetup *raceSetup = gRaceSetup;

    if (raceSetup->mMode == MODE_MISSION_RUN) {
        return raceSetup->mMissionTableColumn;
    }
    return -1;
}

#pragma thumb on
u32 func_020b2ecc(void) {
    s32 recordValue;
    s32 isFilled;

    isFilled = GetMissionRecordValue(GetMissionRunTableRow(), GetMissionRunTableColumn(), &recordValue);
    if (GetEntryEndKind() == 0 && gChoisesS->mUnk_020 != FALSE && isFilled != 0 && (u32) (recordValue - 5) <= 2) {
        return 1;
    }
    return 0;
}
#pragma thumb off

#pragma thumb on

u32 GetChoisesSOpenDuringRace(void) {
    return (gChoisesS->mOpenDuringRace);
}

#pragma thumb off

#pragma thumb on
u32 func_020b2e98(void) {
    if (GetChoisesSOpenDuringRace() != 0 || gChoisesS->mUnk_008 != 0) {
        return 1;
    }
    return 0;
}
#pragma thumb off

#pragma thumb on

void func_020b2e64(u32 openFlag) {
    int wasOpen;
    int v2;
    wasOpen = GetChoisesSOpenDuringRace();
    v2 = func_020b29c4();
    if (v2 != 0) {
        func_020b2f88(openFlag);
    }
    v2 = GetChoisesSOpenDuringRace();
    if ((wasOpen == 0) && (v2 != 0)) {
        func_02105d70();
    }
}

u32 GetChoisesSPrevOpenDuringRace(void) {
    return (gChoisesS->mPrevOpenDuringRace);
}

int func_020b2e34(void) {
    int v1;
    int pickedValue;
    pickedValue = gChoisesS->mPickedValue;
    if ((pickedValue == 2) && (v1 = func_020c3db4(), v1 != 0)) {
        pickedValue = 7;
    }
    return pickedValue;
}

#pragma thumb off

#pragma thumb on
void func_020b2e00(u16 *screenMap, s32 column, s32 row) {
    SetScreenMapBlockLowBits(screenMap, column, row, 1, 1, 4);
    SetScreenMapBlockLowBits(screenMap, column, row + 1, 1, 1, 0x24);
}

void func_020b2da4(void) {
    s32 valueCount;
    s32 valueIndex;
    s32 firstRow;
    u16 *screenMap;

    valueCount = gChoisesS->mLists[GetChoisesSListIndex()].mValueCount;
    screenMap = GetChoisesSListScreenMapData();
    if (screenMap != NULL) {
        for (valueIndex = 0, firstRow = 0xd - valueCount * 2; valueIndex < valueCount; valueIndex++) {
            func_020b2e00(screenMap, 2, firstRow + valueIndex * 4);
        }
        SetScreenMapBlockTopBits(screenMap, 0, 0, 0x20, 0x18, 0xf);
    }
}
#pragma thumb off

#pragma thumb off
u32 GetEntryIndex(void) {
    return (gRaceSetup->mEntryIndex);
}

#pragma thumb off
s32 GetEntryEndKind(void) {
    if (IsKartEnded((u16) GetEntryIndex()) != 0) {
        return gRaceProgress->mEntryEndKind;
    }
    return 6;
}

#pragma thumb on
u32 GetChoisesSListIndex(void) {
    if (func_020b24e4() == 2 && GetRaceDone() == 0) {
        return 3;
    }
    if (GetRaceDone() != 0) {
        if (func_020b252c() == MODE_MISSION_RUN) {
            if (GetEntryEndKind() == 0) {
                return 2;
            }
            return 1;
        }
        if (func_020c3db4() != 0) {
            return 2;
        }
        return 1;
    }
    return 0;
}

// Defined without a prototype: func_020b2c68 calls it without an argument (it uses the value left in r0).
void func_020b2c80(selectedIndex) s32 selectedIndex;
{
    s32 valueCount;
    s32 row;
    u16 *screenMap;

    valueCount = gChoisesS->mLists[GetChoisesSListIndex()].mValueCount;
    screenMap = GetChoisesSListScreenMapData();
    if (screenMap != NULL) {
        if (gChoisesS->mUnk_010 == FALSE || gChoisesS->mPickFrames >= 5) {
            row = 0xd - valueCount * 2 + selectedIndex * 4;
            if (gChoisesS->mCycleFrames < 0x1e) {
                SetScreenMapBlockLowBits(screenMap, 2, row, 1, 1, 0x21);
                SetScreenMapBlockLowBits(screenMap, 2, row + 1, 1, 1, 0x41);
            }
            SetScreenMapBlockTopBits(screenMap, 0, row - 1, 0x20, 4, 0xe);
        }
    }
}
#pragma thumb off

#pragma thumb on

void func_020b2c68(void) {
    func_020b2da4();
    MoveChoisesSSelectedValue(0);
    func_020b2c80();
}

#pragma thumb off

u32 func_020b2c54(void) {
    return (gBackupAccess->mBackupEnabled);
}

#pragma thumb off
s32 func_020b2c24(void) {
    if (func_020b2c54() != 0) {
        return gBackupAccess->mCommandRunning;
    }
    return 0;
}

s32 func_020b2bf0(void) {
    if (data_0217aa08->mBusy != 0) {
        return 1;
    }
    return func_020b2c24();
}

#pragma thumb on
u32 func_020b2bc8(void) {
    if (GetRaceDone() != 0 || (func_020b24e4() == 2 && GetRaceStartSequenceFrames() > 0xf0)) {
        return 1;
    }
    return 0;
}

u32 func_020b2b70(void) {
    if (IsRaceStartSequenceDone() != 0 && func_020b2bc8() != 0 && func_020c5dc4() != 0 && func_020c3da0() == 0 &&
        func_020c70bc() == 0 && func_020c70a0() == 0 && GetShowLapTime() == 0 &&
        (GetChoisesSOpenDuringRace() != 0 || func_02055b1c() == FALSE)) {
        return 1;
    }
    return 0;
}
#pragma thumb off

#pragma thumb off
u32 func_020b2b5c(void) {
    return (data_0217b488->mUnk_10);
}

u32 func_020b2b54(void) {
    return 0x8u;
}

u16 func_020b2b40(InputSlot *slot, u32 mask) {
    return slot->mPressedBits & mask;
}

u16 func_020b2b24(s32 slotIndex, u32 mask) {
    return func_020b2b40(&data_02175628[slotIndex], mask);
}

u32 func_020b2b1c(const void *inputSlotPair) {
    return (*OFFSET_PTR(const u16, inputSlotPair, 4));
}

#pragma thumb off
u32 func_020b2aec(InputSlotPair *inputSlotPair) {
    if (func_020b2b1c(inputSlotPair) == 0 && inputSlotPair->mNoPairCount < 5) {
        return 1;
    }
    return 0;
}

u32 func_020b2ac8(InputSlotPair *inputSlotPair) {
    if (inputSlotPair->mPrevHasPair == 0 && inputSlotPair->mHasPair != 0) {
        return 1;
    }
    return 0;
}

u32 func_020b2a94(InputSlotPair *inputSlotPair) {
    if (func_020b2aec(inputSlotPair) == 0 && func_020b2ac8(inputSlotPair) != 0) {
        return 1;
    }
    return 0;
}

u32 func_020b2a74(s32 slotIndex) {
    return func_020b2a94((InputSlotPair *) &data_02175628[slotIndex].mPairX);
}

#pragma thumb off
void func_020b2a60(u32 p0) {
    data_0217b488->mUnk_14 = p0;
}

u32 GetRaceDone(void) {
    return (gRaceProgress->mRaceDone);
}

#pragma thumb on
u32 func_020b29c4(void) {
    u32 result = 0;
    u32 b = 0;
    u32 raceInProgress = 0;
    u32 noMissionWinner;

    if (IsRaceStartSequenceDone() != 0 && GetRaceStartSequenceFrames() > 0xf0 && GetRaceDone() == 0 &&
        (func_020b252c() != MODE_BATTLE || IsWinnerDecided() == FALSE)) {
        noMissionWinner = 1;
        if (func_020b252c() == MODE_MISSION_RUN) {
            if ((func_020b252c() == MODE_MISSION_RUN ? IsWinnerDecided() : 0) != FALSE) {
                noMissionWinner = 0;
            }
        }
        if (noMissionWinner != 0) {
            raceInProgress = 1;
        }
    }
    if (raceInProgress != 0) {
        if (func_020b252c() != 5) {
            b = 1;
        }
    }
    if (b != 0) {
        if (GetChoisesSOpenDuringRace() != 0 || func_02055b1c() == FALSE) {
            result = 1;
        }
    }
    return result;
}
#pragma thumb off

#pragma thumb off
u32 func_020b29b0(void) {
    return (data_021759d0->mUnk_20);
}

#pragma thumb on
void UpdateChoisesS(void) {
    s32 a;

    gChoisesS->mPrevOpenDuringRace = gChoisesS->mOpenDuringRace;
    gChoisesS->mCycleFrames = gChoisesS->mCycleFrames + 1;
    if (gChoisesS->mCycleFrames >= 0x32) {
        gChoisesS->mCycleFrames = 0;
    }
    if (func_020b2bf0() != 0) {
        return;
    }
    if ((func_020b252c() == MODE_GRAND_PRIX || func_020b252c() == MODE_TIME_ATTACK) && func_020b24e4() == 2 &&
        func_0203c0bc() != 0) {
        return;
    }
    if (gChoisesS->mPickFrames == 0 && gChoisesS->mCloseFrames == 0 && IsChoisesSPickLocked() == 0) {
        if (func_020b2bc8() != 0) {
            if (func_020b2b70() != 0) {
                if (func_020b252c() == MODE_MISSION_RUN && func_020b2b5c() != 0 && func_020b2f58() != 0) {
                    if (func_020b2b24(func_020b2b54(), PAD_KEY_A) != 0 || func_020b2a74(func_020b2b54()) != 0) {
                        gChoisesS->mPickedValue = 10;
                        gChoisesS->mSelectedValue = gChoisesS->mPickedValue;
                        gChoisesS->mPickLocked = 1;
                        StartChoisesSSelectedValueSeq();
                    }
                } else if (func_020b252c() == MODE_MISSION_RUN && func_020b2ecc() != 0) {
                    if (func_020b2b24(func_020b2b54(), PAD_KEY_A) != 0 || func_020b2a74(func_020b2b54()) != 0) {
                        gChoisesS->mPickedValue = 6;
                        gChoisesS->mSelectedValue = gChoisesS->mPickedValue;
                        gChoisesS->mPickLocked = 1;
                        StartChoisesSSelectedValueSeq();
                        func_020b2a60(1);
                    }
                } else if (func_020b252c() == MODE_MISSION_RUN && func_020b2b5c() != 0) {
                    if (func_020b2b24(func_020b2b54(), PAD_KEY_A) != 0 || func_020b2a74(func_020b2b54()) != 0) {
                        gChoisesS->mPickedValue = 6;
                        gChoisesS->mSelectedValue = gChoisesS->mPickedValue;
                        gChoisesS->mPickLocked = 1;
                        StartChoisesSSelectedValueSeq();
                    }
                } else if (func_020b2b24(func_020b2b54(), 8) != 0) {
                    if (func_020b2e98() != 0) {
                        func_02105c4c();
                        gChoisesS->mCloseFrames = 1;
                    } else {
                        func_02105d70();
                        func_020b2f88(1);
                    }
                } else if (func_020b302c() != 0) {
                    gChoisesS->mPickFrames = 1;
                } else if (func_020b2b24(func_020b2b54(), PAD_KEY_A) != 0) {
                    if (func_020b2e98() != 0) {
                        if (gChoisesS->mSelectedValue == 0) {
                            func_02105c4c();
                        } else {
                            StartChoisesSSelectedValueSeq();
                        }
                        gChoisesS->mPickFrames = 1;
                        gChoisesS->mUnk_010 = TRUE;
                    } else {
                        func_02105d70();
                        func_020b2f88(1);
                    }
                } else if (func_020b2b24(func_020b2b54(), PAD_KEY_B) != 0) {
                    if (func_020b2e98() != 0) {
                        func_02105c4c();
                        gChoisesS->mCloseFrames = 1;
                    }
                } else if (GetNewOrRepeatBits(func_020b2b54(), PAD_KEY_UP) != 0) {
                    MoveChoisesSSelectedValue(-1);
                } else if (GetNewOrRepeatBits(func_020b2b54(), PAD_KEY_DOWN) != 0) {
                    MoveChoisesSSelectedValue(1);
                }
            }
        } else if (func_020b29c4() != 0) {
            if (func_020b2b24(func_020b2b54(), 8) != 0) {
                if (func_020b2e98() != 0) {
                    func_02105c4c();
                    gChoisesS->mCloseFrames = 1;
                } else {
                    func_02105d70();
                    func_020b2f88(1);
                }
            } else if (func_020b302c() != 0) {
                gChoisesS->mPickFrames = 1;
            } else if (func_020b2b24(func_020b2b54(), PAD_KEY_A) != 0) {
                if (func_020b2e98() != 0) {
                    if (gChoisesS->mSelectedValue == 0) {
                        func_02105c4c();
                    } else {
                        StartChoisesSSelectedValueSeq();
                    }
                    gChoisesS->mPickFrames = 1;
                    gChoisesS->mUnk_010 = TRUE;
                }
            } else if (func_020b2b24(func_020b2b54(), PAD_KEY_B) != 0) {
                if (func_020b2e98() != 0) {
                    func_02105c4c();
                    gChoisesS->mCloseFrames = 1;
                }
            } else if (GetNewOrRepeatBits(func_020b2b54(), PAD_KEY_UP) != 0) {
                MoveChoisesSSelectedValue(-1);
            } else if (GetNewOrRepeatBits(func_020b2b54(), PAD_KEY_DOWN) != 0) {
                MoveChoisesSSelectedValue(1);
            }
        }
    }
    a = gChoisesS->mPickFrames;
    if (a != 0) {
        gChoisesS->mPickFrames = a + 1;
        if (gChoisesS->mPickFrames > 0xf) {
            if (func_020b2bc8() != 0) {
                if (func_020b2e98() != 0) {
                    gChoisesS->mPickedValue = gChoisesS->mSelectedValue;
                    func_020b2f88(0);
                } else {
                    func_020b2f88(1);
                }
            } else if (func_020b2e98() != 0) {
                gChoisesS->mPickedValue = gChoisesS->mSelectedValue;
                func_020b2f88(0);
            }
            gChoisesS->mPickFrames = 0;
            gChoisesS->mUnk_010 = FALSE;
        }
    }
    a = gChoisesS->mCloseFrames;
    if (a != 0) {
        gChoisesS->mCloseFrames = a + 1;
        if (gChoisesS->mCloseFrames > 4) {
            if (func_020b2bc8() != 0) {
                if (func_020b2e98() != 0) {
                    func_020b2f88(0);
                } else {
                    func_020b2f88(1);
                }
            } else if (func_020b2e98() != 0) {
                func_020b2f88(0);
            }
            gChoisesS->mCloseFrames = 0;
        }
    }
    if (func_020b29b0() != 0 && func_020b252c() == 5 && func_020b2bc8() != 0) {
        gChoisesS->mAutoPickFrames = gChoisesS->mAutoPickFrames + 1;
        if (gChoisesS->mAutoPickFrames > 0x384) {
            gChoisesS->mPickedValue = GetCourseNumber() != 4 ? 2 : 7;
        }
    }
    if (GetChoisesSOpenDuringRace() != 0) {
        a = gChoisesS->mUnk_030;
        gChoisesS->mUnk_030 = a + 1;
        if (a >= 1) {
            gChoisesS->mUnk_02c = 2;
            gChoisesS->mUnk_030 = 1;
        }
    } else {
        gChoisesS->mUnk_02c = 0;
        gChoisesS->mUnk_030 = 0;
    }
}
#pragma thumb off

#pragma thumb on

void func_020b255c(void) {
    int isOpen;
    isOpen = func_020b2e98();
    if (isOpen != 0) {
        func_020b2c68();
    }
}

#pragma thumb off

void *func_020b2540(void) {
    return GetHeap(GetCurrentHeapCall());
}

u32 func_020b252c(void) {
    return (gRaceSetup->mMode);
}

#pragma thumb on
BOOL func_020b250c(void) {
    return func_020b252c() == MODE_GRAND_PRIX && GetCourseNumber() == 4;
}
#pragma thumb off

#pragma thumb off
u32 GetCourseNumber(void) {
    return (gRaceSetup->mCourseNumber);
}

u32 func_020b24e4(void) {
    return gRaceSetup->mRaceKind;
}

#pragma thumb off
void func_020b24cc(TextCanvas *textCanvas, void *charCanvas, void *font, s32 charSpacing, s32 lineSpacing) {
    textCanvas->mCharCanvas = charCanvas;
    textCanvas->mFont = font;
    textCanvas->mCharSpacing = charSpacing;
    textCanvas->mLineSpacing = lineSpacing;
}

u32 func_020b24a4(TextCanvas *textCanvas, s32 textX, s32 textY, u32 color, u32 flags, void *text) {
    return NNSi_G2dTextCanvasDrawText(textCanvas, textX, textY, color, flags, text);
}

#pragma thumb on

void InitChoisesS(void) {
    ChoisesS *choisesS;
    u32 charCount;
    s32 i;

    gChoisesS = HeapAlloc(func_020b2540(), 0x1a4);
    gChoisesS->mOpenDuringRace = 0;
    gChoisesS->mPrevOpenDuringRace = 0;
    gChoisesS->mUnk_008 = 0;
    gChoisesS->mPickLocked = 0;
    gChoisesS->mPickFrames = 0;
    gChoisesS->mUnk_010 = FALSE;
    gChoisesS->mAutoPickFrames = 0;
    if (func_020b252c() == MODE_MISSION_RUN) {
        gChoisesS->mUnk_020 = func_020adb34();
    } else {
        gChoisesS->mUnk_020 = FALSE;
    }
    gChoisesS->mUnk_02c = 0;
    gChoisesS->mUnk_030 = 0;
    ResetChoisesSSelection();
    ClearChoisesSListValueCounts();
    switch (func_020b252c()) {
        case MODE_GRAND_PRIX:
            AppendChoisesSListValue(0, 0);
            AppendChoisesSListValue(0, 9);
            if (func_020b250c() != FALSE) {
                AppendChoisesSListValue(1, 7);
                AppendChoisesSListValue(1, 8);
            } else {
                AppendChoisesSListValue(1, 2);
                AppendChoisesSListValue(1, 8);
                AppendChoisesSListValue(1, 9);
            }
            if (func_020b250c() != FALSE) {
                AppendChoisesSListValue(3, 0);
                AppendChoisesSListValue(3, 7);
                AppendChoisesSListValue(3, 8);
            } else {
                AppendChoisesSListValue(3, 0);
                AppendChoisesSListValue(3, 2);
                AppendChoisesSListValue(3, 8);
                AppendChoisesSListValue(3, 9);
            }
            break;
        case MODE_TIME_ATTACK:
            AppendChoisesSListValue(0, 0);
            AppendChoisesSListValue(0, 3);
            AppendChoisesSListValue(0, 4);
            AppendChoisesSListValue(0, 5);
            AppendChoisesSListValue(0, 9);
            AppendChoisesSListValue(1, 1);
            AppendChoisesSListValue(1, 4);
            AppendChoisesSListValue(1, 5);
            AppendChoisesSListValue(1, 8);
            AppendChoisesSListValue(1, 9);
            AppendChoisesSListValue(3, 0);
            AppendChoisesSListValue(3, 1);
            AppendChoisesSListValue(3, 4);
            AppendChoisesSListValue(3, 5);
            AppendChoisesSListValue(3, 8);
            AppendChoisesSListValue(3, 9);
            break;
        case MODE_BATTLE:
            AppendChoisesSListValue(0, 0);
            AppendChoisesSListValue(0, 9);
            AppendChoisesSListValue(1, 2);
            AppendChoisesSListValue(1, 9);
            AppendChoisesSListValue(2, 7);
            break;
        case MODE_VS:
            AppendChoisesSListValue(0, 0);
            AppendChoisesSListValue(0, 9);
            AppendChoisesSListValue(1, 2);
            AppendChoisesSListValue(1, 9);
            AppendChoisesSListValue(2, 7);
            break;
        case MODE_MISSION_RUN:
            AppendChoisesSListValue(0, 0);
            AppendChoisesSListValue(0, 3);
            AppendChoisesSListValue(0, 6);
            AppendChoisesSListValue(0, 9);
            if (func_020b2f58() != 0) {
                if (IsMissionRunRecordFilled() != 0) {
                    AppendChoisesSListValue(1, 1);
                    AppendChoisesSListValue(1, 6);
                    AppendChoisesSListValue(1, 9);
                    AppendChoisesSListValue(2, 6);
                    AppendChoisesSListValue(2, 1);
                    AppendChoisesSListValue(2, 10);
                    AppendChoisesSListValue(2, 9);
                } else {
                    AppendChoisesSListValue(1, 1);
                    AppendChoisesSListValue(1, 6);
                    AppendChoisesSListValue(1, 9);
                    AppendChoisesSListValue(2, 6);
                    AppendChoisesSListValue(2, 1);
                    AppendChoisesSListValue(2, 9);
                }
            } else {
                AppendChoisesSListValue(1, 1);
                AppendChoisesSListValue(1, 6);
                AppendChoisesSListValue(1, 9);
                AppendChoisesSListValue(2, 6);
                AppendChoisesSListValue(2, 1);
                AppendChoisesSListValue(2, 9);
            }
            break;
        case 5:
            AppendChoisesSListValue(0, 0);
            if (GetCourseNumber() != 4) {
                AppendChoisesSListValue(1, 2);
            } else {
                AppendChoisesSListValue(1, 7);
            }
            break;
    }
    if (func_020b24e4() != RACE_KIND_START_GP && func_020b24e4() != RACE_KIND_STAFF_ROLL) {
        const char *nscrNames[6] = {
            sChoisesSNscrName1, sChoisesSNscrName2, sChoisesSNscrName3,
            sChoisesSNscrName4, sChoisesSNscrName5, sChoisesSNscrName6,
        };

        LoadNclrData(&gChoisesS->mChoisesSBNclr, FindSceneFileWrapper("choises_s_b.NCLR"));
        LoadNcgrData(&gChoisesS->mChoisesSBNcgr, FindSceneFileWrapper("choises_s_b.NCGR"));
        for (i = 0; i < 6; i++) {
            LoadNscrData(&gChoisesS->mChoisesSNscrs[i], FindSceneFileWrapper(nscrNames[i]));
        }
        gChoisesS->mList0Nscr = gChoisesS->mChoisesSNscrs[gChoisesS->mLists[0].mValueCount - 1];
        gChoisesS->mList1Nscr = gChoisesS->mChoisesSNscrs[gChoisesS->mLists[1].mValueCount - 1];
        gChoisesS->mList2Nscr = gChoisesS->mChoisesSNscrs[gChoisesS->mLists[2].mValueCount - 1];
        gChoisesS->mList3Nscr = gChoisesS->mChoisesSNscrs[gChoisesS->mLists[3].mValueCount - 1];
        gChoisesS->mList1Chars = HeapAlloc(func_020b2540(), GetChoisesSListCharsSize(gChoisesS->mLists[1].mValueCount));
        switch (func_020b252c()) {
            case MODE_BATTLE:
            case MODE_VS:
            case MODE_MISSION_RUN:
                gChoisesS->mList2Chars =
                    HeapAlloc(func_020b2540(), GetChoisesSListCharsSize(gChoisesS->mLists[2].mValueCount));
                break;
        }
        gChoisesS->mFont = GetFontByIndex(2);
        NNS_G2dCharCanvasInitForBG(gChoisesS->mCharCanvases[0], GetChoisesSBNcgrWithListChars()->mData, 0x20, 0xc, 4);
        choisesS = gChoisesS;
        func_020b24cc(&choisesS->mTextCanvases[0], choisesS->mCharCanvases[0], choisesS->mFont, IsLanguageJa(), 0);
        NNS_G2dCharCanvasInitForBG(gChoisesS->mCharCanvases[1], gChoisesS->mList1Chars, 0x20, 0xc, 4);
        choisesS = gChoisesS;
        func_020b24cc(&choisesS->mTextCanvases[1], choisesS->mCharCanvases[1], choisesS->mFont, IsLanguageJa(), 0);
        charCount = GetChoisesSListCharsSize(gChoisesS->mLists[1].mValueCount) >> 1;
        for (i = 0; i < charCount; i++) {
            gChoisesS->mList1Chars[i] = GetChoisesSBNcgrWithListChars()->mData[i];
        }
        if (gChoisesS->mList2Chars != NULL) {
            NNS_G2dCharCanvasInitForBG(gChoisesS->mCharCanvases[2], gChoisesS->mList2Chars, 0x20, 0xc, 4);
            choisesS = gChoisesS;
            func_020b24cc(&choisesS->mTextCanvases[2], choisesS->mCharCanvases[2], choisesS->mFont, IsLanguageJa(), 0);
            charCount = GetChoisesSListCharsSize(gChoisesS->mLists[2].mValueCount) >> 1;
            for (i = 0; i < charCount; i++) {
                gChoisesS->mList2Chars[i] = GetChoisesSBNcgrWithListChars()->mData[i];
            }
        }
        NNS_G2dCharCanvasInitForBG(gChoisesS->mCharCanvases[3], GetChoisesSBNcgrWithListChars()->mData, 0x20, 0xc, 4);
        choisesS = gChoisesS;
        func_020b24cc(&choisesS->mTextCanvases[3], choisesS->mCharCanvases[3], choisesS->mFont, IsLanguageJa(), 0);
        if (func_020b24e4() != 2) {
            for (i = 0; i < gChoisesS->mLists[0].mValueCount; i++) {
                func_020b24a4(&gChoisesS->mTextCanvases[0], 0x90, i * 16 + 9, 0xc, 0x412,
                              GetChoisesSValueMessage(0, gChoisesS->mLists[0].mValues[i]));
            }
        } else {
            for (i = 0; i < gChoisesS->mLists[3].mValueCount; i++) {
                func_020b24a4(&gChoisesS->mTextCanvases[3], 0x90, i * 16 + 9, 0xc, 0x412,
                              GetChoisesSValueMessage(3, gChoisesS->mLists[3].mValues[i]));
            }
        }
        for (i = 0; i < gChoisesS->mLists[1].mValueCount; i++) {
            func_020b24a4(&gChoisesS->mTextCanvases[1], 0x90, i * 16 + 9, 0xc, 0x412,
                          GetChoisesSValueMessage(1, gChoisesS->mLists[1].mValues[i]));
        }
        for (i = 0; i < gChoisesS->mLists[2].mValueCount; i++) {
            func_020b24a4(&gChoisesS->mTextCanvases[2], 0x90, i * 16 + 9, 0xc, 0x412,
                          GetChoisesSValueMessage(2, gChoisesS->mLists[2].mValues[i]));
        }
    } else {
        gChoisesS->mChoisesSBNclr = NULL;
        gChoisesS->mChoisesSBNcgr = NULL;
        gChoisesS->mList1Chars = NULL;
        gChoisesS->mList2Chars = NULL;
        gChoisesS->mList0Nscr = NULL;
        gChoisesS->mList1Nscr = NULL;
        gChoisesS->mList2Nscr = NULL;
        gChoisesS->mList3Nscr = NULL;
    }
}

void ClearChoisesSPointer(void) {
    gChoisesS = NULL;
}

#pragma thumb off
