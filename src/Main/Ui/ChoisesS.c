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

// placeholder: the names of rchoi_init's screens as file-scope arrays; this declaration order gives the original's
// order of them in .data.
static char aChoises_s_6_ns[] = "choises_s_6.NSCR";
static char aChoises_s_1_ns[] = "choises_s_1.NSCR";
static char aChoises_s_5_ns[] = "choises_s_5.NSCR";
static char aChoises_s_4_ns[] = "choises_s_4.NSCR";
static char aChoises_s_2_ns[] = "choises_s_2.NSCR";
static char aChoises_s_3__0[] = "choises_s_3.NSCR";

#pragma optimize_for_size on

#pragma thumb on
void *rchoi_getOptionString(s32 listIndex, s32 value) {
    s32 entryNumbers[11] = {0x5d, 0x67, 0x62, 0x64, 0x65, 0x66, 0x69, 0x62, 0x61, 0x5f, 0x75};

    if (rchoi_race_getCurrentDisplayMode() == 2) {
        entryNumbers[0] = 0x6a;
        entryNumbers[8] = 0x63;
    }
    if (listIndex != 0) {
        entryNumbers[2] = 0x60;
    }
    return jn_msg_getMessage(m2d_get2dArcFile("common.bmg"), entryNumbers[value]);
}

void rchoi_resetChoicesSets(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        rchoi_sState->mLists[i].mValueCount = 0;
    }
}

void rchoi_registerOption(s32 listIndex, s32 value) {
    s32 valueCount;

    valueCount = rchoi_sState->mLists[listIndex].mValueCount;
    rchoi_sState->mLists[listIndex].mValueCount = valueCount + 1;
    rchoi_sState->mLists[listIndex].mValues[valueCount] = value;
}

s32 rchoi_moveCursor(s32 step) {
    s32 selectedIndex = 0;
    s32 valueCount;
    s32 listIndex;
    ChoisesS *choisesS;

    if (rchoi_isMenuVisible() != 0) {
        listIndex = rchoi_getCurChoicesSetId();
        valueCount = rchoi_sState->mLists[listIndex].mValueCount;
        for (; selectedIndex < valueCount; selectedIndex++) {
            if (rchoi_sState->mSelectedValue == rchoi_sState->mLists[listIndex].mValues[selectedIndex]) {
                break;
            }
        }
        if (valueCount == 1) {
            step = 0;
        } else if (valueCount == 2) {
            if (step != 0 && selectedIndex + step >= 0 && selectedIndex + step < valueCount) {
                rchoi_sState->mCycleFrames = 0;
                sfx_2105AC0(0);
            } else {
                step = 0;
            }
        } else if (step != 0) {
            rchoi_sState->mCycleFrames = 0;
            sfx_2105AC0(0);
        }
        choisesS = rchoi_sState;
        choisesS->mSelectedValue =
            choisesS->mLists[listIndex].mValues[(valueCount + (selectedIndex + step)) % valueCount];
    }
    return selectedIndex;
}

static inline ChoisesS *func_020b302c_inline(void) {
    return rchoi_sState;
}

u32 rchoi_handleTouch(void) {
    u32 touched = 0;
    s32 valueCount;
    s32 listIndex;
    s32 valueIndex;
    PairRect valueRects[6];
    s32 firstRectRow;
    s32 top;

    if (rchoi_isMenuVisible() != 0) {
        rchoi_moveCursor(0);
        listIndex = rchoi_getCurChoicesSetId();
        valueCount = rchoi_sState->mLists[listIndex].mValueCount;
        for (valueIndex = 0, firstRectRow = 0xc - valueCount * 2; valueIndex < valueCount; valueIndex++) {
            top = (firstRectRow + valueIndex * 4) * 8 + 6;
            valueRects[valueIndex].mMinX = 8;
            valueRects[valueIndex].mMaxX = 0xf8;
            valueRects[valueIndex].mMinY = top;
            valueRects[valueIndex].mMaxY = top + 0x16;
        }
        for (valueIndex = 0; valueIndex < valueCount; valueIndex++) {
            if (IsNewPairInRect(rchoi_input_getDefaultInputId(), valueRects[valueIndex]) != 0) {
                if (rchoi_sState->mSelectedValue != func_020b302c_inline()->mLists[listIndex].mValues[valueIndex]) {
                    rchoi_sState->mSelectedValue = rchoi_sState->mLists[listIndex].mValues[valueIndex];
                    rchoi_moveCursor(0);
                } else {
                    rchoi_sState->mUnk_010 = TRUE;
                }
                touched = 1;
            }
        }
        if (touched != 0) {
            if (rchoi_sState->mSelectedValue == 0) {
                sfx_handleRaceContinue();
            } else {
                rchoi_emitOptionActivationSound();
            }
        }
    }
    return touched;
}

void rchoi_resetSelectedOption(void) {
    ChoisesS *choisesS;

    rchoi_sState->mPickedValue = 0;
    choisesS = rchoi_sState;
    choisesS->mSelectedValue = choisesS->mLists[rchoi_getCurChoicesSetId()].mValues[0];
}

void rchoi_setMenuVisible(s32 openFlag) {
    if (rchoi_sState->mPickLocked != 0) {
        return;
    }
    if (openFlag != 0 && rchoi_isMenuVisible() == 0) {
        if (rchoi_shouldPauseRaceDuringMenu() != 0) {
            rchoi_sState->mOpenDuringRace = openFlag;
        } else if (rchoi_isMenuAllowed() != 0) {
            rchoi_sState->mUnk_008 = openFlag;
        } else {
            return;
        }
        rchoi_resetSelectedOption();
    } else if (openFlag == 0 && rchoi_isMenuVisible() != 0) {
        if (rchoi_shouldPauseRaceDuringMenu() != 0) {
            rchoi_sState->mOpenDuringRace = openFlag;
        } else if (rchoi_isMenuAllowed() != 0) {
            rchoi_sState->mUnk_008 = openFlag;
        } else {
            return;
        }
    }
    if (rchoi_sState->mPickedValue != 0) {
        rchoi_sState->mPickLocked = 1;
    }
}

u32 func_020b2f58(void) {
    if ((rchoi_race_getCurrentMissionLevel() == 6 && rchoi_race_getCurrentMissionIdx() == 9) ||
        (rchoi_race_getCurrentMissionLevel() == 7 && rchoi_race_getCurrentMissionIdx() == 9)) {
        return 1;
    }
    return 0;
}
#pragma thumb off

s8 rchoi_race_getCurrentMissionLevel(void) {
    RaceSetup *raceSetup = gRaceMultiConfig;

    if (raceSetup->mMode == MODE_MISSION_RUN) {
        return raceSetup->mMissionTableRow;
    }
    return -1;
}

s8 rchoi_race_getCurrentMissionIdx(void) {
    RaceSetup *raceSetup = gRaceMultiConfig;

    if (raceSetup->mMode == MODE_MISSION_RUN) {
        return raceSetup->mMissionTableColumn;
    }
    return -1;
}

#pragma thumb on
u32 rchoi_20B2ECC(void) {
    s32 recordValue;
    s32 isFilled;

    isFilled = GetMissionRecordValue(rchoi_race_getCurrentMissionLevel(), rchoi_race_getCurrentMissionIdx(), &recordValue);
    if (rchoi_rstat_getMissionResult() == 0 && rchoi_sState->mUnk_020 != FALSE && isFilled != 0 && (u32) (recordValue - 5) <= 2) {
        return 1;
    }
    return 0;
}
#pragma thumb off

#pragma thumb on

u32 rchoi_getIsRacePaused(void) {
    return (rchoi_sState->mOpenDuringRace);
}

#pragma thumb off

#pragma thumb on
u32 rchoi_isMenuVisible(void) {
    if (rchoi_getIsRacePaused() != 0 || rchoi_sState->mUnk_008 != 0) {
        return 1;
    }
    return 0;
}
#pragma thumb off

#pragma thumb on

void rchoi_handleSleep(u32 openFlag) {
    int wasOpen;
    int v2;
    wasOpen = rchoi_getIsRacePaused();
    v2 = rchoi_shouldPauseRaceDuringMenu();
    if (v2 != 0) {
        rchoi_setMenuVisible(openFlag);
    }
    v2 = rchoi_getIsRacePaused();
    if ((wasOpen == 0) && (v2 != 0)) {
        sfx_handleRacePause();
    }
}

u32 rchoi_getPrevIsRacePaused(void) {
    return (rchoi_sState->mPrevOpenDuringRace);
}

int rchoi_getActivatedOption(void) {
    int v1;
    int pickedValue;
    pickedValue = rchoi_sState->mPickedValue;
    if ((pickedValue == 2) && (v1 = func_020c3db4(), v1 != 0)) {
        pickedValue = 7;
    }
    return pickedValue;
}

#pragma thumb off

#pragma thumb on
void rchoi_renderOptionBar(u16 *screenMap, s32 column, s32 row) {
    m2d_setCharMapCharName2d(screenMap, column, row, 1, 1, 4);
    m2d_setCharMapCharName2d(screenMap, column, row + 1, 1, 1, 0x24);
}

void rchoi_renderChoicesUnselected(void) {
    s32 valueCount;
    s32 valueIndex;
    s32 firstRow;
    u16 *screenMap;

    valueCount = rchoi_sState->mLists[rchoi_getCurChoicesSetId()].mValueCount;
    screenMap = rchoi_getMapData();
    if (screenMap != NULL) {
        for (valueIndex = 0, firstRow = 0xd - valueCount * 2; valueIndex < valueCount; valueIndex++) {
            rchoi_renderOptionBar(screenMap, 2, firstRow + valueIndex * 4);
        }
        m2d_setCharMapPalette2d(screenMap, 0, 0, 0x20, 0x18, 0xf);
    }
}
#pragma thumb off

#pragma thumb off
u32 rchoi_race_getCurrentPlayerDriverId(void) {
    return (gRaceMultiConfig->mEntryIndex);
}

#pragma thumb off
s32 rchoi_rstat_getMissionResult(void) {
    if (rstat_hasDriverFinished((u16) rchoi_race_getCurrentPlayerDriverId()) != 0) {
        return gRaceStatus->mEntryEndKind;
    }
    return 6;
}

#pragma thumb on
u32 rchoi_getCurChoicesSetId(void) {
    if (rchoi_race_getCurrentDisplayMode() == 2 && GetRaceDone() == 0) {
        return 3;
    }
    if (GetRaceDone() != 0) {
        if (rchoi_race_getCurrentRaceMode() == MODE_MISSION_RUN) {
            if (rchoi_rstat_getMissionResult() == 0) {
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

// Defined without a prototype: rchoi_renderMenu calls it without an argument (it uses the value left in r0).
void rchoi_renderSelection(selectedIndex) s32 selectedIndex;
{
    s32 valueCount;
    s32 row;
    u16 *screenMap;

    valueCount = rchoi_sState->mLists[rchoi_getCurChoicesSetId()].mValueCount;
    screenMap = rchoi_getMapData();
    if (screenMap != NULL) {
        if (rchoi_sState->mUnk_010 == FALSE || rchoi_sState->mPickFrames >= 5) {
            row = 0xd - valueCount * 2 + selectedIndex * 4;
            if (rchoi_sState->mCycleFrames < 0x1e) {
                m2d_setCharMapCharName2d(screenMap, 2, row, 1, 1, 0x21);
                m2d_setCharMapCharName2d(screenMap, 2, row + 1, 1, 1, 0x41);
            }
            m2d_setCharMapPalette2d(screenMap, 0, row - 1, 0x20, 4, 0xe);
        }
    }
}
#pragma thumb off

#pragma thumb on

void rchoi_renderMenu(void) {
    rchoi_renderChoicesUnselected();
    rchoi_moveCursor(0);
    rchoi_renderSelection();
}

#pragma thumb off

u32 rchoi_savc_isEnabled(void) {
    return (gSaveCore->mBackupEnabled);
}

#pragma thumb off
s32 rchoi_savc_isBusy(void) {
    if (rchoi_savc_isEnabled() != 0) {
        return gSaveCore->mCommandRunning;
    }
    return 0;
}

s32 rchoi_savd_isBusy(void) {
    if (gSaveData->mBusy != 0) {
        return 1;
    }
    return rchoi_savc_isBusy();
}

#pragma thumb on
u32 func_020b2bc8(void) {
    if (GetRaceDone() != 0 || (rchoi_race_getCurrentDisplayMode() == 2 && GetRaceStartSequenceFrames() > 0xf0)) {
        return 1;
    }
    return 0;
}

u32 rchoi_isMenuAllowed(void) {
    if (IsRaceStartSequenceDone() != 0 && func_020b2bc8() != 0 && func_020c5dc4() != 0 && func_020c3da0() == 0 &&
        r2dtar_isSaving() == 0 && func_020c70a0() == 0 && GetShowLapTime() == 0 &&
        (rchoi_getIsRacePaused() != 0 || dce_2055B1C() == FALSE)) {
        return 1;
    }
    return 0;
}
#pragma thumb off

#pragma thumb off
u32 func_020b2b5c(void) {
    return (gStruct217B488->mUnk_10);
}

u32 rchoi_input_getDefaultInputId(void) {
    return 0x8u;
}

u16 rchoi_pad_isSetPadTrig(InputSlot *slot, u32 mask) {
    return slot->mPressedBits & mask;
}

u16 rchoi_input_isSetPadTrigById(s32 slotIndex, u32 mask) {
    return rchoi_pad_isSetPadTrig(&gInputUnits[slotIndex], mask);
}

u32 rchoi_spi_getTpValid(const void *inputSlotPair) {
    return (*OFFSET_PTR(const u16, inputSlotPair, 4));
}

#pragma thumb off
u32 rchoi_spi_isPenReleaseTimeout(InputSlotPair *inputSlotPair) {
    if (rchoi_spi_getTpValid(inputSlotPair) == 0 && inputSlotPair->mNoPairCount < 5) {
        return 1;
    }
    return 0;
}

u32 rchoi_spi_isPenDownEvent(InputSlotPair *inputSlotPair) {
    if (inputSlotPair->mPrevHasPair == 0 && inputSlotPair->mHasPair != 0) {
        return 1;
    }
    return 0;
}

u32 func_020b2a94(InputSlotPair *inputSlotPair) {
    if (rchoi_spi_isPenReleaseTimeout(inputSlotPair) == 0 && rchoi_spi_isPenDownEvent(inputSlotPair) != 0) {
        return 1;
    }
    return 0;
}

u32 rchoi_sub_20ACE14(s32 slotIndex) {
    return func_020b2a94((InputSlotPair *) &gInputUnits[slotIndex].mPairX);
}

#pragma thumb off
void func_020b2a60(u32 p0) {
    gStruct217B488->mUnk_14 = p0;
}

u32 GetRaceDone(void) {
    return (gRaceStatus->mRaceDone);
}

#pragma thumb on
u32 rchoi_shouldPauseRaceDuringMenu(void) {
    u32 result = 0;
    u32 b = 0;
    u32 raceInProgress = 0;
    u32 noMissionWinner;

    if (IsRaceStartSequenceDone() != 0 && GetRaceStartSequenceFrames() > 0xf0 && GetRaceDone() == 0 &&
        (rchoi_race_getCurrentRaceMode() != MODE_BATTLE || mgcnt_hasWinnerBeenDecided() == FALSE)) {
        noMissionWinner = 1;
        if (rchoi_race_getCurrentRaceMode() == MODE_MISSION_RUN) {
            if ((rchoi_race_getCurrentRaceMode() == MODE_MISSION_RUN ? mgcnt_hasWinnerBeenDecided() : 0) != FALSE) {
                noMissionWinner = 0;
            }
        }
        if (noMissionWinner != 0) {
            raceInProgress = 1;
        }
    }
    if (raceInProgress != 0) {
        if (rchoi_race_getCurrentRaceMode() != 5) {
            b = 1;
        }
    }
    if (b != 0) {
        if (rchoi_getIsRacePaused() != 0 || dce_2055B1C() == FALSE) {
            result = 1;
        }
    }
    return result;
}
#pragma thumb off

#pragma thumb off
u32 rchoi_sysdat_getOverlayRelatedNum(void) {
    return (gSystemData->mUnk_20);
}

#pragma thumb on
void rchoi_update(void) {
    s32 a;

    rchoi_sState->mPrevOpenDuringRace = rchoi_sState->mOpenDuringRace;
    rchoi_sState->mCycleFrames = rchoi_sState->mCycleFrames + 1;
    if (rchoi_sState->mCycleFrames >= 0x32) {
        rchoi_sState->mCycleFrames = 0;
    }
    if (rchoi_savd_isBusy() != 0) {
        return;
    }
    if ((rchoi_race_getCurrentRaceMode() == MODE_GRAND_PRIX || rchoi_race_getCurrentRaceMode() == MODE_TIME_ATTACK) && rchoi_race_getCurrentDisplayMode() == 2 &&
        rstat_203C0BC() != 0) {
        return;
    }
    if (rchoi_sState->mPickFrames == 0 && rchoi_sState->mCloseFrames == 0 && rchoi_getIsExittingRace() == 0) {
        if (func_020b2bc8() != 0) {
            if (rchoi_isMenuAllowed() != 0) {
                if (rchoi_race_getCurrentRaceMode() == MODE_MISSION_RUN && func_020b2b5c() != 0 && func_020b2f58() != 0) {
                    if (rchoi_input_isSetPadTrigById(rchoi_input_getDefaultInputId(), PAD_KEY_A) != 0 || rchoi_sub_20ACE14(rchoi_input_getDefaultInputId()) != 0) {
                        rchoi_sState->mPickedValue = 10;
                        rchoi_sState->mSelectedValue = rchoi_sState->mPickedValue;
                        rchoi_sState->mPickLocked = 1;
                        rchoi_emitOptionActivationSound();
                    }
                } else if (rchoi_race_getCurrentRaceMode() == MODE_MISSION_RUN && rchoi_20B2ECC() != 0) {
                    if (rchoi_input_isSetPadTrigById(rchoi_input_getDefaultInputId(), PAD_KEY_A) != 0 || rchoi_sub_20ACE14(rchoi_input_getDefaultInputId()) != 0) {
                        rchoi_sState->mPickedValue = 6;
                        rchoi_sState->mSelectedValue = rchoi_sState->mPickedValue;
                        rchoi_sState->mPickLocked = 1;
                        rchoi_emitOptionActivationSound();
                        func_020b2a60(1);
                    }
                } else if (rchoi_race_getCurrentRaceMode() == MODE_MISSION_RUN && func_020b2b5c() != 0) {
                    if (rchoi_input_isSetPadTrigById(rchoi_input_getDefaultInputId(), PAD_KEY_A) != 0 || rchoi_sub_20ACE14(rchoi_input_getDefaultInputId()) != 0) {
                        rchoi_sState->mPickedValue = 6;
                        rchoi_sState->mSelectedValue = rchoi_sState->mPickedValue;
                        rchoi_sState->mPickLocked = 1;
                        rchoi_emitOptionActivationSound();
                    }
                } else if (rchoi_input_isSetPadTrigById(rchoi_input_getDefaultInputId(), 8) != 0) {
                    if (rchoi_isMenuVisible() != 0) {
                        sfx_handleRaceContinue();
                        rchoi_sState->mCloseFrames = 1;
                    } else {
                        sfx_handleRacePause();
                        rchoi_setMenuVisible(1);
                    }
                } else if (rchoi_handleTouch() != 0) {
                    rchoi_sState->mPickFrames = 1;
                } else if (rchoi_input_isSetPadTrigById(rchoi_input_getDefaultInputId(), PAD_KEY_A) != 0) {
                    if (rchoi_isMenuVisible() != 0) {
                        if (rchoi_sState->mSelectedValue == 0) {
                            sfx_handleRaceContinue();
                        } else {
                            rchoi_emitOptionActivationSound();
                        }
                        rchoi_sState->mPickFrames = 1;
                        rchoi_sState->mUnk_010 = TRUE;
                    } else {
                        sfx_handleRacePause();
                        rchoi_setMenuVisible(1);
                    }
                } else if (rchoi_input_isSetPadTrigById(rchoi_input_getDefaultInputId(), PAD_KEY_B) != 0) {
                    if (rchoi_isMenuVisible() != 0) {
                        sfx_handleRaceContinue();
                        rchoi_sState->mCloseFrames = 1;
                    }
                } else if (mutil_checkKeys(rchoi_input_getDefaultInputId(), PAD_KEY_UP) != 0) {
                    rchoi_moveCursor(-1);
                } else if (mutil_checkKeys(rchoi_input_getDefaultInputId(), PAD_KEY_DOWN) != 0) {
                    rchoi_moveCursor(1);
                }
            }
        } else if (rchoi_shouldPauseRaceDuringMenu() != 0) {
            if (rchoi_input_isSetPadTrigById(rchoi_input_getDefaultInputId(), 8) != 0) {
                if (rchoi_isMenuVisible() != 0) {
                    sfx_handleRaceContinue();
                    rchoi_sState->mCloseFrames = 1;
                } else {
                    sfx_handleRacePause();
                    rchoi_setMenuVisible(1);
                }
            } else if (rchoi_handleTouch() != 0) {
                rchoi_sState->mPickFrames = 1;
            } else if (rchoi_input_isSetPadTrigById(rchoi_input_getDefaultInputId(), PAD_KEY_A) != 0) {
                if (rchoi_isMenuVisible() != 0) {
                    if (rchoi_sState->mSelectedValue == 0) {
                        sfx_handleRaceContinue();
                    } else {
                        rchoi_emitOptionActivationSound();
                    }
                    rchoi_sState->mPickFrames = 1;
                    rchoi_sState->mUnk_010 = TRUE;
                }
            } else if (rchoi_input_isSetPadTrigById(rchoi_input_getDefaultInputId(), PAD_KEY_B) != 0) {
                if (rchoi_isMenuVisible() != 0) {
                    sfx_handleRaceContinue();
                    rchoi_sState->mCloseFrames = 1;
                }
            } else if (mutil_checkKeys(rchoi_input_getDefaultInputId(), PAD_KEY_UP) != 0) {
                rchoi_moveCursor(-1);
            } else if (mutil_checkKeys(rchoi_input_getDefaultInputId(), PAD_KEY_DOWN) != 0) {
                rchoi_moveCursor(1);
            }
        }
    }
    a = rchoi_sState->mPickFrames;
    if (a != 0) {
        rchoi_sState->mPickFrames = a + 1;
        if (rchoi_sState->mPickFrames > 0xf) {
            if (func_020b2bc8() != 0) {
                if (rchoi_isMenuVisible() != 0) {
                    rchoi_sState->mPickedValue = rchoi_sState->mSelectedValue;
                    rchoi_setMenuVisible(0);
                } else {
                    rchoi_setMenuVisible(1);
                }
            } else if (rchoi_isMenuVisible() != 0) {
                rchoi_sState->mPickedValue = rchoi_sState->mSelectedValue;
                rchoi_setMenuVisible(0);
            }
            rchoi_sState->mPickFrames = 0;
            rchoi_sState->mUnk_010 = FALSE;
        }
    }
    a = rchoi_sState->mCloseFrames;
    if (a != 0) {
        rchoi_sState->mCloseFrames = a + 1;
        if (rchoi_sState->mCloseFrames > 4) {
            if (func_020b2bc8() != 0) {
                if (rchoi_isMenuVisible() != 0) {
                    rchoi_setMenuVisible(0);
                } else {
                    rchoi_setMenuVisible(1);
                }
            } else if (rchoi_isMenuVisible() != 0) {
                rchoi_setMenuVisible(0);
            }
            rchoi_sState->mCloseFrames = 0;
        }
    }
    if (rchoi_sysdat_getOverlayRelatedNum() != 0 && rchoi_race_getCurrentRaceMode() == 5 && func_020b2bc8() != 0) {
        rchoi_sState->mAutoPickFrames = rchoi_sState->mAutoPickFrames + 1;
        if (rchoi_sState->mAutoPickFrames > 0x384) {
            rchoi_sState->mPickedValue = rchoi_race_getCurrentRaceNr() != 4 ? 2 : 7;
        }
    }
    if (rchoi_getIsRacePaused() != 0) {
        a = rchoi_sState->mUnk_030;
        rchoi_sState->mUnk_030 = a + 1;
        if (a >= 1) {
            rchoi_sState->mUnk_02c = 2;
            rchoi_sState->mUnk_030 = 1;
        }
    } else {
        rchoi_sState->mUnk_02c = 0;
        rchoi_sState->mUnk_030 = 0;
    }
}
#pragma thumb off

#pragma thumb on

void rchoi_render(void) {
    int isOpen;
    isOpen = rchoi_isMenuVisible();
    if (isOpen != 0) {
        rchoi_renderMenu();
    }
}

#pragma thumb off

void *rchoi_proc_getCurrentHeap(void) {
    return proc_getHeap(proc_getCurrent());
}

u32 rchoi_race_getCurrentRaceMode(void) {
    return (gRaceMultiConfig->mMode);
}

#pragma thumb on
BOOL func_020b250c(void) {
    return rchoi_race_getCurrentRaceMode() == MODE_GRAND_PRIX && rchoi_race_getCurrentRaceNr() == 4;
}
#pragma thumb off

#pragma thumb off
u32 rchoi_race_getCurrentRaceNr(void) {
    return (gRaceMultiConfig->mCourseNumber);
}

u32 rchoi_race_getCurrentDisplayMode(void) {
    return gRaceMultiConfig->mRaceKind;
}

#pragma thumb off
void rchoi_NNS_G2dTextCanvasInit(TextCanvas *textCanvas, void *charCanvas, void *font, s32 charSpacing, s32 lineSpacing) {
    textCanvas->mCharCanvas = charCanvas;
    textCanvas->mFont = font;
    textCanvas->mCharSpacing = charSpacing;
    textCanvas->mLineSpacing = lineSpacing;
}

u32 rchoi_NNS_G2dTextCanvasDrawText(TextCanvas *textCanvas, s32 textX, s32 textY, u32 color, u32 flags, void *text) {
    return NNSi_G2dTextCanvasDrawText(textCanvas, textX, textY, color, flags, text);
}

#pragma thumb on

void rchoi_init(void) {
    ChoisesS *choisesS;
    u32 charCount;
    s32 i;

    rchoi_sState = heap_alloc(rchoi_proc_getCurrentHeap(), 0x1a4);
    rchoi_sState->mOpenDuringRace = 0;
    rchoi_sState->mPrevOpenDuringRace = 0;
    rchoi_sState->mUnk_008 = 0;
    rchoi_sState->mPickLocked = 0;
    rchoi_sState->mPickFrames = 0;
    rchoi_sState->mUnk_010 = FALSE;
    rchoi_sState->mAutoPickFrames = 0;
    if (rchoi_race_getCurrentRaceMode() == MODE_MISSION_RUN) {
        rchoi_sState->mUnk_020 = func_020adb34();
    } else {
        rchoi_sState->mUnk_020 = FALSE;
    }
    rchoi_sState->mUnk_02c = 0;
    rchoi_sState->mUnk_030 = 0;
    rchoi_resetSelectedOption();
    rchoi_resetChoicesSets();
    switch (rchoi_race_getCurrentRaceMode()) {
        case MODE_GRAND_PRIX:
            rchoi_registerOption(0, 0);
            rchoi_registerOption(0, 9);
            if (func_020b250c() != FALSE) {
                rchoi_registerOption(1, 7);
                rchoi_registerOption(1, 8);
            } else {
                rchoi_registerOption(1, 2);
                rchoi_registerOption(1, 8);
                rchoi_registerOption(1, 9);
            }
            if (func_020b250c() != FALSE) {
                rchoi_registerOption(3, 0);
                rchoi_registerOption(3, 7);
                rchoi_registerOption(3, 8);
            } else {
                rchoi_registerOption(3, 0);
                rchoi_registerOption(3, 2);
                rchoi_registerOption(3, 8);
                rchoi_registerOption(3, 9);
            }
            break;
        case MODE_TIME_ATTACK:
            rchoi_registerOption(0, 0);
            rchoi_registerOption(0, 3);
            rchoi_registerOption(0, 4);
            rchoi_registerOption(0, 5);
            rchoi_registerOption(0, 9);
            rchoi_registerOption(1, 1);
            rchoi_registerOption(1, 4);
            rchoi_registerOption(1, 5);
            rchoi_registerOption(1, 8);
            rchoi_registerOption(1, 9);
            rchoi_registerOption(3, 0);
            rchoi_registerOption(3, 1);
            rchoi_registerOption(3, 4);
            rchoi_registerOption(3, 5);
            rchoi_registerOption(3, 8);
            rchoi_registerOption(3, 9);
            break;
        case MODE_BATTLE:
            rchoi_registerOption(0, 0);
            rchoi_registerOption(0, 9);
            rchoi_registerOption(1, 2);
            rchoi_registerOption(1, 9);
            rchoi_registerOption(2, 7);
            break;
        case MODE_VS:
            rchoi_registerOption(0, 0);
            rchoi_registerOption(0, 9);
            rchoi_registerOption(1, 2);
            rchoi_registerOption(1, 9);
            rchoi_registerOption(2, 7);
            break;
        case MODE_MISSION_RUN:
            rchoi_registerOption(0, 0);
            rchoi_registerOption(0, 3);
            rchoi_registerOption(0, 6);
            rchoi_registerOption(0, 9);
            if (func_020b2f58() != 0) {
                if (IsMissionRunRecordFilled() != 0) {
                    rchoi_registerOption(1, 1);
                    rchoi_registerOption(1, 6);
                    rchoi_registerOption(1, 9);
                    rchoi_registerOption(2, 6);
                    rchoi_registerOption(2, 1);
                    rchoi_registerOption(2, 10);
                    rchoi_registerOption(2, 9);
                } else {
                    rchoi_registerOption(1, 1);
                    rchoi_registerOption(1, 6);
                    rchoi_registerOption(1, 9);
                    rchoi_registerOption(2, 6);
                    rchoi_registerOption(2, 1);
                    rchoi_registerOption(2, 9);
                }
            } else {
                rchoi_registerOption(1, 1);
                rchoi_registerOption(1, 6);
                rchoi_registerOption(1, 9);
                rchoi_registerOption(2, 6);
                rchoi_registerOption(2, 1);
                rchoi_registerOption(2, 9);
            }
            break;
        case 5:
            rchoi_registerOption(0, 0);
            if (rchoi_race_getCurrentRaceNr() != 4) {
                rchoi_registerOption(1, 2);
            } else {
                rchoi_registerOption(1, 7);
            }
            break;
    }
    if (rchoi_race_getCurrentDisplayMode() != RACE_KIND_START_GP && rchoi_race_getCurrentDisplayMode() != RACE_KIND_STAFF_ROLL) {
        const char *nscrNames[6] = {
            aChoises_s_1_ns, aChoises_s_2_ns, aChoises_s_3__0,
            aChoises_s_4_ns, aChoises_s_5_ns, aChoises_s_6_ns,
        };

        g2du_unpackPaletteData(&rchoi_sState->mChoisesSBNclr, m2d_getSceneArcFile("choises_s_b.NCLR"));
        g2du_unpackCharacterDataBG(&rchoi_sState->mChoisesSBNcgr, m2d_getSceneArcFile("choises_s_b.NCGR"));
        for (i = 0; i < 6; i++) {
            g2du_unpackScreenData(&rchoi_sState->mChoisesSNscrs[i], m2d_getSceneArcFile(nscrNames[i]));
        }
        rchoi_sState->mList0Nscr = rchoi_sState->mChoisesSNscrs[rchoi_sState->mLists[0].mValueCount - 1];
        rchoi_sState->mList1Nscr = rchoi_sState->mChoisesSNscrs[rchoi_sState->mLists[1].mValueCount - 1];
        rchoi_sState->mList2Nscr = rchoi_sState->mChoisesSNscrs[rchoi_sState->mLists[2].mValueCount - 1];
        rchoi_sState->mList3Nscr = rchoi_sState->mChoisesSNscrs[rchoi_sState->mLists[3].mValueCount - 1];
        rchoi_sState->mList1Chars = heap_alloc(rchoi_proc_getCurrentHeap(), GetChoisesSListCharsSize(rchoi_sState->mLists[1].mValueCount));
        switch (rchoi_race_getCurrentRaceMode()) {
            case MODE_BATTLE:
            case MODE_VS:
            case MODE_MISSION_RUN:
                rchoi_sState->mList2Chars =
                    heap_alloc(rchoi_proc_getCurrentHeap(), GetChoisesSListCharsSize(rchoi_sState->mLists[2].mValueCount));
                break;
        }
        rchoi_sState->mFont = m2d_getFont(2);
        NNS_G2dCharCanvasInitForBG(rchoi_sState->mCharCanvases[0], rchoi_getCharData()->mData, 0x20, 0xc, 4);
        choisesS = rchoi_sState;
        rchoi_NNS_G2dTextCanvasInit(&choisesS->mTextCanvases[0], choisesS->mCharCanvases[0], choisesS->mFont, g2du_getTextHSpace(), 0);
        NNS_G2dCharCanvasInitForBG(rchoi_sState->mCharCanvases[1], rchoi_sState->mList1Chars, 0x20, 0xc, 4);
        choisesS = rchoi_sState;
        rchoi_NNS_G2dTextCanvasInit(&choisesS->mTextCanvases[1], choisesS->mCharCanvases[1], choisesS->mFont, g2du_getTextHSpace(), 0);
        charCount = GetChoisesSListCharsSize(rchoi_sState->mLists[1].mValueCount) >> 1;
        for (i = 0; i < charCount; i++) {
            rchoi_sState->mList1Chars[i] = rchoi_getCharData()->mData[i];
        }
        if (rchoi_sState->mList2Chars != NULL) {
            NNS_G2dCharCanvasInitForBG(rchoi_sState->mCharCanvases[2], rchoi_sState->mList2Chars, 0x20, 0xc, 4);
            choisesS = rchoi_sState;
            rchoi_NNS_G2dTextCanvasInit(&choisesS->mTextCanvases[2], choisesS->mCharCanvases[2], choisesS->mFont, g2du_getTextHSpace(), 0);
            charCount = GetChoisesSListCharsSize(rchoi_sState->mLists[2].mValueCount) >> 1;
            for (i = 0; i < charCount; i++) {
                rchoi_sState->mList2Chars[i] = rchoi_getCharData()->mData[i];
            }
        }
        NNS_G2dCharCanvasInitForBG(rchoi_sState->mCharCanvases[3], rchoi_getCharData()->mData, 0x20, 0xc, 4);
        choisesS = rchoi_sState;
        rchoi_NNS_G2dTextCanvasInit(&choisesS->mTextCanvases[3], choisesS->mCharCanvases[3], choisesS->mFont, g2du_getTextHSpace(), 0);
        if (rchoi_race_getCurrentDisplayMode() != 2) {
            for (i = 0; i < rchoi_sState->mLists[0].mValueCount; i++) {
                rchoi_NNS_G2dTextCanvasDrawText(&rchoi_sState->mTextCanvases[0], 0x90, i * 16 + 9, 0xc, 0x412,
                              rchoi_getOptionString(0, rchoi_sState->mLists[0].mValues[i]));
            }
        } else {
            for (i = 0; i < rchoi_sState->mLists[3].mValueCount; i++) {
                rchoi_NNS_G2dTextCanvasDrawText(&rchoi_sState->mTextCanvases[3], 0x90, i * 16 + 9, 0xc, 0x412,
                              rchoi_getOptionString(3, rchoi_sState->mLists[3].mValues[i]));
            }
        }
        for (i = 0; i < rchoi_sState->mLists[1].mValueCount; i++) {
            rchoi_NNS_G2dTextCanvasDrawText(&rchoi_sState->mTextCanvases[1], 0x90, i * 16 + 9, 0xc, 0x412,
                          rchoi_getOptionString(1, rchoi_sState->mLists[1].mValues[i]));
        }
        for (i = 0; i < rchoi_sState->mLists[2].mValueCount; i++) {
            rchoi_NNS_G2dTextCanvasDrawText(&rchoi_sState->mTextCanvases[2], 0x90, i * 16 + 9, 0xc, 0x412,
                          rchoi_getOptionString(2, rchoi_sState->mLists[2].mValues[i]));
        }
    } else {
        rchoi_sState->mChoisesSBNclr = NULL;
        rchoi_sState->mChoisesSBNcgr = NULL;
        rchoi_sState->mList1Chars = NULL;
        rchoi_sState->mList2Chars = NULL;
        rchoi_sState->mList0Nscr = NULL;
        rchoi_sState->mList1Nscr = NULL;
        rchoi_sState->mList2Nscr = NULL;
        rchoi_sState->mList3Nscr = NULL;
    }
}

void rchoi_finalize(void) {
    rchoi_sState = NULL;
}

#pragma thumb off
