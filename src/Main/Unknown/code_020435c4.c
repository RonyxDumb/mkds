#include "Main/Unknown/code_020435c4.h"
#include "code_0200fc8c.h"

#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_02039530.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_02039520.h"
#include "Main/Unknown/code_02046c10.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_02050034.h"
#include "Main/Unknown/code_02039774.h"
#include "Main/Unknown/code_0204a550.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0203a3a4.h"
#include "Main/Unknown/code_02039708.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204a9e4.h"
#include "Main/Unknown/code_0204aa04.h"
#include "Main/Unknown/code_02056284.h"
#include "Main/Unknown/code_02056464.h"
#include "Main/Unknown/code_02056700.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020470c4.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02154000.h"
#include "01/code_021956dc.h"
#include "code_021458c4.h"
#include "code_0214d018.h"
#include "registers.h"
#include "code_0200fe74.h"

static inline void func_02043a34_inline(void) {
    if ((SYSTEM_WORK->mButtonXY & 0x8000) >> 15) {
        data_02175624->mPadKeys = 0;
    } else {
        data_02175624->mPadKeys = ((reg_PAD_KEYINPUT | SYSTEM_WORK->mButtonXY) ^ 0x2fff) & 0x2fff;
    }
    UpdateTouchMicInput();
}

static inline void func_02043c14_inline(void) {
    s32 i;
    s32 k;
    InputSlot *inputSlot;
    InputSlot *slot;

    for (i = 0; i < 10; i++) {
        inputSlot = &gInputSlots[(u32) i];
        ResetInputSlot(inputSlot);
        SetInputSlotRepeat(inputSlot, 0xff3, 0x1e, 0xa);
        inputSlot->mSourceKind = 0;
        inputSlot->mRequestedBits = 0;
        inputSlot->mUnk_44 = 0;
        inputSlot->mBitMask = 0x2fff;
        ResetKeyRecording(&inputSlot->mUnk_28);
        ResetInputSlotPair(&inputSlot->mPair);
    }
    gInputSlots[8].mSourceKind = 5;
    gInputSlots[9].mSourceKind = 6;
    data_02175624->mUnk_08 = 0;
    data_02175624->mUnk_0c = FALSE;
    slot = gInputSlots;
    for (k = 0; k < 10; k++) {
        ResetInputSlot(slot);
        slot->mRequestedBits = 0;
        SetInputSlotRepeat(slot, 0xff3, 0x1e, 0xa);
        slot++;
    }
}

static inline RaceSetup *func_02043f28_inline(void) {
    return gRaceSetup;
}

void ReplaceEntryWithCpu(u32 entryIndex) {
    s32 listedCpuSlot;
    RaceSetup *raceSetup;

    listedCpuSlot = 3;
    if (gRaceSetup->mListedCpuEntryIndices[0] == -1) {
        listedCpuSlot = 0;
    } else if (gRaceSetup->mListedCpuEntryIndices[1] == -1) {
        listedCpuSlot = 1;
    }
    SetNextRaceEntry(entryIndex, gRaceSetup->mCurrentEntries[entryIndex].mCharacterIndex,
                     gRaceSetup->mCurrentEntries[entryIndex].mKartIndex, PLAYER_KIND_CPU,
                     gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mTeamIndex, listedCpuSlot);
    raceSetup = gRaceSetup;
    raceSetup->mCurrentEntries[entryIndex] = raceSetup->mNextEntries[entryIndex];
    if (listedCpuSlot < 2) {
        raceSetup->mListedCpuEntryIndices[listedCpuSlot] = entryIndex;
    }
    gRaceSetup->mNextEntries[entryIndex].mPlayer.mNumber = gRaceSetup->mNextCpuNumber;
    gRaceSetup->mNextCpuNumber = gRaceSetup->mNextCpuNumber + 1;
}

void SetNextRaceFromMissionRow(MissionFileRow *missionFileRow, u32 tableRow, u32 tableColumn) {
    u8 i;

    gRaceSetup->mNextHeader.mMissionFileRow = *missionFileRow;
    gRaceSetup->mNextHeader.mMissionTableRow = tableRow;
    gRaceSetup->mNextHeader.mMissionTableColumn = tableColumn;
    gRaceSetup->mNextHeader.mMode = MODE_MISSION_RUN;
    gRaceSetup->mNextHeader.mCourseId = missionFileRow->mCourseId;
    gRaceSetup->mNextHeader.mMirrorMode = (missionFileRow->mUnk_1c & 0x10) != 0 ? 1 : 0;
    gRaceSetup->mNextHeader.mUseTeams = 0;
    gRaceSetup->mNextHeader.mRuleKind = 0;
    gRaceSetup->mNextHeader.mCourseListMode = 0;
    gRaceSetup->mNextHeader.mBattleKind = 0;
    gRaceSetup->mCourseCount = 0;
    gRaceSetup->mNextHeader.mEngineIndex = missionFileRow->mEngineIndex;
    SetNextRaceEntry(0, missionFileRow->mCharacterIndex0, missionFileRow->mKartIndex0, PLAYER_KIND_HUMAN, -1, 3);
    if (missionFileRow->mCharacterIndex1 != 0xff && missionFileRow->mKartIndex1 != 0xff) {
        SetNextRaceEntry(1, missionFileRow->mCharacterIndex1, missionFileRow->mKartIndex1, PLAYER_KIND_CPU, -1, 3);
        gRaceSetup->mNextHeader.mCpuDifficulty = 2;
    } else {
        SetNextRaceEntry(1, -1, -1, PLAYER_KIND_NONE, -1, 3);
        gRaceSetup->mNextHeader.mCpuDifficulty = 0;
    }
    for (i = 2; i < 8; i++) {
        SetNextRaceEntry(i, -1, -1, PLAYER_KIND_NONE, -1, 3);
    }
}

void ReadCourseGhostRecordAndWait(u32 courseId) {
    data_0217aa08->mSlotGhostRecords[0]->mHead.mFilled = 0;
    data_0217aa08->mSlotGhostRecords[1]->mHead.mFilled = 0;
    data_0217aa08->mCourseGhostRecord->mHead.mFilled = 0;
    ReadCourseGhostRecord(courseId);
    WaitThreadFunctionsDone();
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != 0) {
        data_0217aa08->mCourseGhostRecord->mHead.mFilled = 0;
    }
}

void ReadCourseAndSlotGhostRecords(u32 courseId, u32 slotIndex) {
    data_0217aa08->mSlotGhostRecords[0]->mHead.mFilled = 0;
    data_0217aa08->mSlotGhostRecords[1]->mHead.mFilled = 0;
    data_0217aa08->mCourseGhostRecord->mHead.mFilled = 0;
    data_0217aa08->mSlotGhostRecords[0]->mHead.mFilled = 0;
    data_0217aa08->mSlotGhostRecords[1]->mHead.mFilled = 0;
    data_0217aa08->mCourseGhostRecord->mHead.mFilled = 0;
    ReadCourseGhostRecord(courseId);
    WaitThreadFunctionsDone();
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != 0) {
        data_0217aa08->mCourseGhostRecord->mHead.mFilled = 0;
    }
    ReadSlotGhostRecord(slotIndex);
    WaitThreadFunctionsDone();
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != 0) {
        data_0217aa08->mSlotGhostRecords[0]->mHead.mFilled = 0;
    }
}

// Reads the course ghost record, then loads its ghost file; a failed load leaves a NULL record that is then
// zero-filled.
void ReadCourseGhostRecordAndLoadFile(u32 courseId) {
    SlotGhostRecord *ghostRecord;
    char path[0x80];

    ghostRecord = NULL;
    data_0217aa08->mSlotGhostRecords[0]->mHead.mFilled = 0;
    data_0217aa08->mSlotGhostRecords[1]->mHead.mFilled = 0;
    data_0217aa08->mCourseGhostRecord->mHead.mFilled = 0;
    data_0217aa08->mSlotGhostRecords[0]->mHead.mFilled = 0;
    data_0217aa08->mSlotGhostRecords[1]->mHead.mFilled = 0;
    data_0217aa08->mCourseGhostRecord->mHead.mFilled = 0;
    ReadCourseGhostRecord(courseId);
    WaitThreadFunctionsDone();
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != 0) {
        data_0217aa08->mCourseGhostRecord->mHead.mFilled = 0;
    }
    if (TryFormatGhostPath(courseId, path, 0x80) != FALSE) {
        ghostRecord = LoadGhostRecordFile(path);
    }
    if (ghostRecord != NULL) {
        return;
    }
    MI_CpuFill8(ghostRecord, 0, 0x1000);
    ghostRecord->mHead.mFilled = 0;
}

void func_02043fb0(u32 courseId) {
    data_0217aa08->mSlotGhostRecords[0]->mHead.mFilled = 0;
    data_0217aa08->mSlotGhostRecords[1]->mHead.mFilled = 0;
    data_0217aa08->mCourseGhostRecord->mHead.mFilled = 0;
    ReadCourseGhostRecord(courseId);
    WaitThreadFunctionsDone();
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != 0) {
        data_0217aa08->mCourseGhostRecord->mHead.mFilled = 0;
    }
}

void LoadSndBanksForCharacters(u32 useCurrentEntries) {
    u16 i;
    RaceSetup *raceSetup;
    u32 bankMask;

    bankMask = 0;
    i = 0;
    for (; i < (u32) (raceSetup = func_02043f28_inline())->mKartCount; i++) {
        if (useCurrentEntries != 0) {
            bankMask |= data_021540ec[raceSetup->mCurrentEntries[i].mCharacterIndex];
        } else {
            bankMask |= data_021540ec[raceSetup->mNextEntries[i].mCharacterIndex];
        }
    }
    LoadSndBanksAndWaveArcsIfChanged(bankMask);
}

void InitInputSlotsAndTouchMic(void *heap) {
    s32 i;

    InitTouchPanelAndSetCalibration();
    InitTouchMicInput(heap);
    for (i = 0; i <= 1; i++) {
        InitKeyRecordingBuffer(&gInputSlots[i].mUnk_28, heap);
    }
    for (; i < 10; i++) {
        ClearKeyRecordingBufferPointer(&gInputSlots[i].mUnk_28);
    }
    data_02175624 = HeapAlloc(heap, 0x10);
    func_02043c14_inline();
    func_02043a34_inline();
    func_02043a34_inline();
}

void ResetInputSlots(void) {
    func_02043c14_inline();
}

void StartInputSlots(void) {
    s32 i;
    s32 j;
    InputSlot *inputSlot;
    InputSlot *slot;

    inputSlot = gInputSlots;
    for (i = 0; i < 10; i++) {
        ResetInputSlot(inputSlot);
        inputSlot->mRequestedBits = 0;
        SetInputSlotRepeat(inputSlot, 0xff3, 0x1e, 0xa);
        inputSlot++;
    }
    StartTouchAutoSampling();
    UpdateInputSlots();
    slot = gInputSlots;
    for (j = 0; j < 10; j++) {
        slot->mHoldLong = 0;
        slot->mUnk_14 = 0;
        SetInputSlotRepeat(slot, 0xff3, 0x1e, 0xa);
        slot++;
    }
    data_02175624->mPadKeys = 0;
    data_02175624->mFlags = 0;
}

void StopTouchAutoSamplingWrapper(void) {
    StopTouchAutoSampling();
}

void ClearInputSlots(void) {
    s32 i;
    InputSlot *inputSlot;

    inputSlot = gInputSlots;
    for (i = 0; i < 10; i++) {
        ClearInputSlotBitsAndRepeat(inputSlot);
        inputSlot++;
    }
}

void SetNoKeysAndUpdateInputSlots(void) {
    data_02175624->mFlags |= INPUT_STATE_NO_KEYS;
    UpdateInputSlots();
}

void ReleaseTouchMicInputWrapper(void) {
    ReleaseTouchMicInput();
}

void SetLeftRightKeysSwapped(u32 mirrorMode) {
    if (mirrorMode != 0) {
        data_02175624->mFlags |= 4;
    } else {
        data_02175624->mFlags &= ~4;
    }
}

void UpdatePadKeysAndTouchMic(void) {
    func_02043a34_inline();
}

u32 GetPadKeys(void) {
    return (data_02175624->mPadKeys);
}

static inline s32 func_02043648_inline(ConnectionWork *p) {
    BOOL r = FALSE;
    if ((p == NULL ? 0 : p->mUnk_0000) != 0 && p->mState != 13) {
        r = TRUE;
    }
    return r;
}

void UpdateInputSlots(void) {
    u8 slotIndex;
    u16 packedTouchPoint;
    u16 padOrParticipantKeys;
    u16 padOrParticipantTouchPoint;
    u16 padKeys;
    s32 micOverThreshold;
    u16 slotKeys;
    u16 t;
    s32 touchPoint;
    InputSlot *inputSlot;
    s32 micValue;
    BOOL skipUpdate;
    s32 canReadKeys;
    s32 f;
    s32 sourceKind;
    u16 flags;

    padKeys = data_02175624->mPadKeys;
    packedTouchPoint = GetPackedTouchPoint();
    padOrParticipantKeys = padKeys;
    padOrParticipantTouchPoint = packedTouchPoint;
    micOverThreshold = gTouchMicInput->mMicOverThreshold;
    if (func_02043648_inline(gConnectionWork) != 0) {
        padOrParticipantKeys = func_0204ffe8(GetParticipantIndex(data_02175624->mUnk_08));
        padOrParticipantTouchPoint =
            gConnectionWork->mUnk_15bc_view.mUnk_0c[GetParticipantIndex(data_02175624->mUnk_08)].mUnk_00_2;
        GetParticipantIndex(data_02175624->mUnk_08);
    }
    for (slotIndex = 0; slotIndex < 10; slotIndex++) {
        slotKeys = 0;
        touchPoint = 0xffff;
        micValue = slotKeys;
        f = (data_02175624->mFlags & INPUT_STATE_OPEN_DURING_RACE) ? 1 : 0;
        skipUpdate = FALSE;
        canReadKeys = (GetCurrentSceneNumber() != 2 || (data_02175624->mFlags & INPUT_STATE_READ_RACE_KEYS)) ? 1 : 0;
        inputSlot = &gInputSlots[slotIndex];
        flags = data_02175624->mFlags;
        if (!(flags & INPUT_STATE_NO_KEYS)) {
            sourceKind = inputSlot->mSourceKind;
            if (f == 0) {
                f = inputSlot->mUnk_44;
            }
            switch (sourceKind) {
                case 1:
                    if (f == 0) {
                        if (canReadKeys != 0) {
                            slotKeys = ReadKeysFromKeyRecording(&inputSlot->mUnk_28);
                        }
                    } else {
                        skipUpdate = TRUE;
                    }
                    touchPoint = 0xffff;
                    micValue = 0;
                    break;
                case 2:
                    if (f == 0) {
                        if (canReadKeys != 0) {
                            slotKeys = padKeys;
                            if (flags & 4) {
                                slotKeys = padKeys & 0xffcf;
                                if (padKeys & PAD_KEY_LEFT) {
                                    slotKeys |= PAD_KEY_RIGHT;
                                }
                                if (padKeys & PAD_KEY_RIGHT) {
                                    slotKeys |= PAD_KEY_LEFT;
                                }
                            }
                            AppendKeysToKeyRecording(&inputSlot->mUnk_28, slotKeys);
                        }
                    } else {
                        skipUpdate = TRUE;
                    }
                    touchPoint = packedTouchPoint;
                    micValue = micOverThreshold;
                    break;
                case 3:
                case 7:
                    if (f != 0) {
                        skipUpdate = TRUE;
                    } else {
                        micValue = 0;
                        slotKeys = inputSlot->mRequestedBits;
                        touchPoint = 0xffff;
                        inputSlot->mRequestedBits = micValue;
                    }
                    break;
                case 5:
                    slotKeys = padOrParticipantKeys;
                    touchPoint = padOrParticipantTouchPoint;
                    micValue = 0;
                    break;
                case 4:
                    if (f == 0) {
                        if (canReadKeys != 0) {
                            slotKeys = func_0204ffe8(GetParticipantIndex(slotIndex));
                            if (data_02175624->mFlags & 4) {
                                t = slotKeys & 0xffcf;
                                if (slotKeys & PAD_KEY_LEFT) {
                                    t |= PAD_KEY_RIGHT;
                                }
                                if (slotKeys & PAD_KEY_RIGHT) {
                                    t |= PAD_KEY_LEFT;
                                }
                                slotKeys = t;
                            }
                        }
                    } else {
                        skipUpdate = TRUE;
                    }
                    touchPoint = gConnectionWork->mUnk_15bc_view.mUnk_0c[GetParticipantIndex(slotIndex)].mUnk_00_2;
                    micValue = gConnectionWork->mUnk_15bc_view.mUnk_0c[GetParticipantIndex(slotIndex)].mUnk_06_7;
                    break;
                case 6:
                    slotKeys = padKeys;
                    touchPoint = packedTouchPoint;
                    micValue = micOverThreshold;
                    break;
                case 0:
                    slotKeys = 0;
                    touchPoint = 0xffff;
                    micValue = slotKeys;
                    break;
            }
        }
        t = slotKeys & inputSlot->mBitMask;
        if (skipUpdate == FALSE) {
            UpdateInputSlot(t, inputSlot);
        }
        UpdateInputSlotPair(&inputSlot->mPair, touchPoint, micValue);
    }
}

// Takes effect only for slots whose source kind is 3 or 7.
void RequestBits(s32 slotIndex, u32 bits) {
    if (gInputSlots[slotIndex].mSourceKind == 3 || gInputSlots[slotIndex].mSourceKind == 7) {
        gInputSlots[slotIndex].mRequestedBits |= bits;
    }
}

void SetInputOpenDuringRace(u32 openDuringRace) {
    if (openDuringRace != 0) {
        data_02175624->mFlags |= INPUT_STATE_OPEN_DURING_RACE;
        return;
    }
    data_02175624->mFlags &= ~INPUT_STATE_OPEN_DURING_RACE;
}

u32 func_020435c4(void) {
    return data_02175928[0x27];
}
