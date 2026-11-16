#include "Main/Unknown/code_020435c4.h"

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
#include "Main/System/Heap.h"
#include "Main/Unknown/code_0203a3a4.h"
#include "Main/Unknown/code_02039708.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204a9e4.h"
#include "Main/Unknown/code_0204aa04.h"
#include "Main/Unknown/code_02056284.h"
#include "Main/Save/GhostTimes.h"
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

static inline void func_02043a34_inline(void) {
    if ((*(vu16 *) 0x027fffa8 & 0x8000) >> 15) {
        input_sPadData->mPadKeys = 0;
    } else {
        input_sPadData->mPadKeys = ((*(vu16 *) 0x4000130 | *(vu16 *) 0x027fffa8) ^ 0x2fff) & 0x2fff;
    }
    spi_update();
}

static inline void func_02043c14_inline(void) {
    s32 i;
    s32 k;
    InputSlot *inputSlot;
    InputSlot *slot;

    for (i = 0; i < 10; i++) {
        inputSlot = &gInputUnits[(u32) i];
        pad_init(inputSlot);
        pad_initAutoRepeat(inputSlot, 0xff3, 0x1e, 0xa);
        inputSlot->mSourceKind = 0;
        inputSlot->mRequestedBits = 0;
        inputSlot->field44 = 0;
        inputSlot->mBitMask = 0x2fff;
        irec_init((KeyRecording *) &inputSlot->field28);
        spi_initTpMic((InputSlotPair *) &inputSlot->mPairX);
    }
    gInputUnits[8].mSourceKind = 5;
    gInputUnits[9].mSourceKind = 6;
    input_sPadData->field8 = 0;
    input_sPadData->fieldC = FALSE;
    slot = gInputUnits;
    for (k = 0; k < 10; k++) {
        pad_init(slot);
        slot->mRequestedBits = 0;
        pad_initAutoRepeat(slot, 0xff3, 0x1e, 0xa);
        slot++;
    }
}

static inline RaceSetup *func_02043f28_inline(void) {
    return gRaceMultiConfig;
}

void sub_204451C(u32 entryIndex) {
    s32 f;
    RaceSetup *raceSetup;

    f = 3;
    if (gRaceMultiConfig->field3D5[0] == -1) {
        f = 0;
    } else if (gRaceMultiConfig->field3D5[1] == -1) {
        f = 1;
    }
    rconf_setDriverConfigNext(entryIndex, gRaceMultiConfig->mCurrentEntries[entryIndex].mCharacterIndex,
                     gRaceMultiConfig->mCurrentEntries[entryIndex].mKartIndex, PLAYER_KIND_CPU,
                     gRaceMultiConfig->mCurrentEntries[entryIndex].mPlayer.mTeamIndex, f);
    raceSetup = gRaceMultiConfig;
    raceSetup->mCurrentEntries[entryIndex] = raceSetup->mNextEntries[entryIndex];
    if (f < 2) {
        raceSetup->field3D5[f] = entryIndex;
    }
    gRaceMultiConfig->mNextEntries[entryIndex].mPlayer.mNumber = gRaceMultiConfig->mNextCpuNumber;
    gRaceMultiConfig->mNextCpuNumber = gRaceMultiConfig->mNextCpuNumber + 1;
}

void rconf_setupMissionRace(MissionFileRow *missionFileRow, u32 tableRow, u32 tableColumn) {
    u8 i;

    gRaceMultiConfig->mNextHeader.mMissionFileRow = *missionFileRow;
    gRaceMultiConfig->mNextHeader.mMissionTableRow = tableRow;
    gRaceMultiConfig->mNextHeader.mMissionTableColumn = tableColumn;
    gRaceMultiConfig->mNextHeader.mMode = MODE_MISSION_RUN;
    gRaceMultiConfig->mNextHeader.mCourseId = missionFileRow->mCourseId;
    gRaceMultiConfig->mNextHeader.mMirrorMode = (missionFileRow->field1C & 0x10) != 0 ? 1 : 0;
    gRaceMultiConfig->mNextHeader.mUseTeams = 0;
    gRaceMultiConfig->mNextHeader.mRuleKind = 0;
    gRaceMultiConfig->mNextHeader.mCourseListMode = 0;
    gRaceMultiConfig->mNextHeader.mBattleKind = 0;
    gRaceMultiConfig->mCourseCount = 0;
    gRaceMultiConfig->mNextHeader.mEngineIndex = missionFileRow->mEngineIndex;
    rconf_setDriverConfigNext(0, missionFileRow->mCharacterIndex0, missionFileRow->mKartIndex0, PLAYER_KIND_HUMAN, -1, 3);
    if (missionFileRow->mCharacterIndex1 != 0xff && missionFileRow->mKartIndex1 != 0xff) {
        rconf_setDriverConfigNext(1, missionFileRow->mCharacterIndex1, missionFileRow->mKartIndex1, PLAYER_KIND_CPU, -1, 3);
        gRaceMultiConfig->mNextHeader.mCpuDifficulty = 2;
    } else {
        rconf_setDriverConfigNext(1, -1, -1, PLAYER_KIND_NONE, -1, 3);
        gRaceMultiConfig->mNextHeader.mCpuDifficulty = 0;
    }
    for (i = 2; i < 8; i++) {
        rconf_setDriverConfigNext(i, -1, -1, PLAYER_KIND_NONE, -1, 3);
    }
}

void func_020442d0(u32 courseId) {
    gSaveData->mGhostRecords[1]->mFilled = 0;
    gSaveData->mGhostRecords[2]->mFilled = 0;
    gSaveData->mGhostRecords[0]->mFilled = 0;
    savd_loadPersonalGhost(courseId);
    bgwkr_waitForCompletion();
    if (gSaveCore->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gSaveCore->mErrorCode != 0) {
        gSaveData->mGhostRecords[0]->mFilled = 0;
    }
}

void func_0204419c(u32 courseId, u32 b) {
    gSaveData->mGhostRecords[1]->mFilled = 0;
    gSaveData->mGhostRecords[2]->mFilled = 0;
    gSaveData->mGhostRecords[0]->mFilled = 0;
    gSaveData->mGhostRecords[1]->mFilled = 0;
    gSaveData->mGhostRecords[2]->mFilled = 0;
    gSaveData->mGhostRecords[0]->mFilled = 0;
    savd_loadPersonalGhost(courseId);
    bgwkr_waitForCompletion();
    if (gSaveCore->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gSaveCore->mErrorCode != 0) {
        gSaveData->mGhostRecords[0]->mFilled = 0;
    }
    savd_loadDownloadGhost(b);
    bgwkr_waitForCompletion();
    if (gSaveCore->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gSaveCore->mErrorCode != 0) {
        gSaveData->mGhostRecords[1]->mFilled = 0;
    }
}

void LoadStaffGhost(u32 courseId) {
    GhostRecord *ghostRecord;
    char path[0x80];

    ghostRecord = NULL;
    gSaveData->mGhostRecords[1]->mFilled = 0;
    gSaveData->mGhostRecords[2]->mFilled = 0;
    gSaveData->mGhostRecords[0]->mFilled = 0;
    gSaveData->mGhostRecords[1]->mFilled = 0;
    gSaveData->mGhostRecords[2]->mFilled = 0;
    gSaveData->mGhostRecords[0]->mFilled = 0;
    savd_loadPersonalGhost(courseId);
    bgwkr_waitForCompletion();
    if (gSaveCore->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gSaveCore->mErrorCode != 0) {
        gSaveData->mGhostRecords[0]->mFilled = 0;
    }
    if (race_getGhostFileNameForCourse(courseId, path, 0x80) != FALSE) {
        ghostRecord = savd_loadStaffGhost(path);
    }
    if (ghostRecord != NULL) {
        return;
    }
    MI_CpuFill8(ghostRecord, 0, 0x1000);
    ghostRecord->mFilled = 0;
}

void sub_2043FB0(u32 courseId) {
    gSaveData->mGhostRecords[1]->mFilled = 0;
    gSaveData->mGhostRecords[2]->mFilled = 0;
    gSaveData->mGhostRecords[0]->mFilled = 0;
    savd_loadPersonalGhost(courseId);
    bgwkr_waitForCompletion();
    if (gSaveCore->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gSaveCore->mErrorCode != 0) {
        gSaveData->mGhostRecords[0]->mFilled = 0;
    }
}

void rconf_loadCharacterSounds(u32 a) {
    u16 i;
    RaceSetup *raceSetup;
    u32 r;

    r = 0;
    i = 0;
    for (; i < (u32) (raceSetup = func_02043f28_inline())->mKartCount; i++) {
        if (a != 0) {
            r |= g_CharacterMaskTable[raceSetup->mCurrentEntries[i].mCharacterIndex];
        } else {
            r |= g_CharacterMaskTable[raceSetup->mNextEntries[i].mCharacterIndex];
        }
    }
    sound_loadCharacterSounds(r);
}

void input_init(void *heap) {
    s32 i;

    spi_initTouch();
    spi_init(heap);
    for (i = 0; i <= 1; i++) {
        irec_allocBuffer((u32) &gInputUnits[i].field28, (u32) heap);
    }
    for (; i < 10; i++) {
        irec_setBufferToNull((KeyRecording *) &gInputUnits[i].field28);
    }
    input_sPadData = heap_alloc(heap, 0x10);
    func_02043c14_inline();
    func_02043a34_inline();
    func_02043a34_inline();
}

void input_initUnits(void) {
    func_02043c14_inline();
}

void input_2043B48(void) {
    s32 i;
    s32 j;
    InputSlot *inputSlot;
    InputSlot *slot;

    inputSlot = gInputUnits;
    for (i = 0; i < 10; i++) {
        pad_init(inputSlot);
        inputSlot->mRequestedBits = 0;
        pad_initAutoRepeat(inputSlot, 0xff3, 0x1e, 0xa);
        inputSlot++;
    }
    spi_startTouchAutoSampling();
    input_update();
    slot = gInputUnits;
    for (j = 0; j < 10; j++) {
        slot->mHoldLong = 0;
        slot->field14 = 0;
        pad_initAutoRepeat(slot, 0xff3, 0x1e, 0xa);
        slot++;
    }
    input_sPadData->mPadKeys = 0;
    input_sPadData->mFlags = 0;
}

void input_stopTouchAutoSampling(void) {
    spi_stopTouchAutoSampling();
}

void input_clearPads(void) {
    s32 i;
    InputSlot *inputSlot;

    inputSlot = gInputUnits;
    for (i = 0; i < 10; i++) {
        pad_clear(inputSlot);
        inputSlot++;
    }
}

void input_2043AE0(void) {
    input_sPadData->mFlags |= 8;
    input_update();
}

void input_finalize(void) {
    spi_finalize();
}

void input_setMirrorMode(u32 mirrorMode) {
    if (mirrorMode != 0) {
        input_sPadData->mFlags |= 4;
    } else {
        input_sPadData->mFlags &= ~4;
    }
}

void input_sample(void) {
    func_02043a34_inline();
}

u32 input_getPressedKeys(void) {
    return (input_sPadData->mPadKeys);
}

static inline s32 func_02043648_inline(ConnectionWork *p) {
    BOOL r = FALSE;
    if ((p == NULL ? 0 : p->field0) != 0 && p->field4 != 13) {
        r = TRUE;
    }
    return r;
}

void input_update(void) {
    u8 slotIndex;
    u16 y;
    u16 a;
    u16 b;
    u16 padKeys;
    s32 k;
    u16 slotKeys;
    u16 t;
    s32 n;
    InputSlot *inputSlot;
    s32 o;
    BOOL skipUpdate;
    s32 c;
    s32 f;
    s32 sourceKind;
    u16 flags;

    padKeys = input_sPadData->mPadKeys;
    y = spi_getTouchPos();
    a = padKeys;
    b = y;
    k = gSpiData->mMicOverThreshold;
    if (func_02043648_inline(gStruct217AA00) != 0) {
        a = sub_204FFE8(GetParticipantIndex(input_sPadData->field8));
        b = *(u16 *) &gStruct217AA00->mUnk_15bc_view.fieldC[GetParticipantIndex(input_sPadData->field8)].field0[2];
        GetParticipantIndex(input_sPadData->field8);
    }
    for (slotIndex = 0; slotIndex < 10; slotIndex++) {
        slotKeys = 0;
        n = 0xffff;
        o = slotKeys;
        f = (input_sPadData->mFlags & INPUT_STATE_OPEN_DURING_RACE) ? 1 : 0;
        skipUpdate = FALSE;
        c = (scproc_getCurrentScene() != 2 || (input_sPadData->mFlags & INPUT_STATE_READ_RACE_KEYS)) ? 1 : 0;
        inputSlot = &gInputUnits[slotIndex];
        flags = input_sPadData->mFlags;
        if (!(flags & 8)) {
            sourceKind = inputSlot->mSourceKind;
            if (f == 0) {
                f = inputSlot->field44;
            }
            switch (sourceKind) {
                case 1:
                    if (f == 0) {
                        if (c != 0) {
                            slotKeys = irec_playKeys((KeyRecording *) &inputSlot->field28);
                        }
                    } else {
                        skipUpdate = TRUE;
                    }
                    n = 0xffff;
                    o = 0;
                    break;
                case 2:
                    if (f == 0) {
                        if (c != 0) {
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
                            irec_recordKeys((KeyRecording *) &inputSlot->field28, slotKeys);
                        }
                    } else {
                        skipUpdate = TRUE;
                    }
                    n = y;
                    o = k;
                    break;
                case 3:
                case 7:
                    if (f != 0) {
                        skipUpdate = TRUE;
                    } else {
                        o = 0;
                        slotKeys = inputSlot->mRequestedBits;
                        n = 0xffff;
                        inputSlot->mRequestedBits = o;
                    }
                    break;
                case 5:
                    slotKeys = a;
                    n = b;
                    o = 0;
                    break;
                case 4:
                    if (f == 0) {
                        if (c != 0) {
                            slotKeys = sub_204FFE8(GetParticipantIndex(slotIndex));
                            if (input_sPadData->mFlags & 4) {
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
                    n = *(u16 *) &gStruct217AA00->mUnk_15bc_view.fieldC[GetParticipantIndex(slotIndex)].field0[2];
                    o = gStruct217AA00->mUnk_15bc_view.fieldC[GetParticipantIndex(slotIndex)].field6_7;
                    break;
                case 6:
                    slotKeys = padKeys;
                    n = y;
                    o = k;
                    break;
                case 0:
                    slotKeys = 0;
                    n = 0xffff;
                    o = slotKeys;
                    break;
            }
        }
        t = slotKeys & inputSlot->mBitMask;
        if (skipUpdate == FALSE) {
            pad_update(t, inputSlot);
        }
        spi_updateTpMic((InputSlotPair *) &inputSlot->mPairX, n, o);
    }
}

// Takes effect only for slots whose source kind is 3 or 7.
void input_pressVirtualPadKeys(s32 slotIndex, u32 bits) {
    if (gInputUnits[slotIndex].mSourceKind == 3 || gInputUnits[slotIndex].mSourceKind == 7) {
        gInputUnits[slotIndex].mRequestedBits |= bits;
    }
}

void input_setFlagsBit0(u32 openDuringRace) {
    if (openDuringRace != 0) {
        input_sPadData->mFlags |= INPUT_STATE_OPEN_DURING_RACE;
        return;
    }
    input_sPadData->mFlags &= ~INPUT_STATE_OPEN_DURING_RACE;
}

u32 input_getIsResetInvoked(void) {
    u32 value0;
    value0 = (u32) &data_02175928;
    value0 = *(const u16 *) ((value0) + (78));
    return value0;
}
