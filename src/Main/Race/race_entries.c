#include "Main/Race/race_entries.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Race/cup_records.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Save/ghost_record.h"
#include "Main/Graphics/disp_cap.h"
#include "Main/Unknown/code_02120294.h"
#include "Main/Unknown/code_02120240.h"
#include "Main/Unknown/code_021201e4.h"
#include "Main/Unknown/code_021202f0.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

static inline void SetNextRaceEntryWrapper(s32 listedCpuSlot, u32 teamIndex, s32 playerKind, u32 kartIndex,
                                           u32 characterIndex, s32 entryIndex) {
    SetNextRaceEntry(entryIndex, characterIndex, kartIndex, playerKind, teamIndex, listedCpuSlot);
}

static inline PlayerRecord *GetPlayerRecordByEntryIndex(ConnectionWork *connectionWork, s32 entryIndex) {
    u16 participantIndex;

    participantIndex = connectionWork->mParticipantIndexByPos[entryIndex];
    return participantIndex == 0xffff ? 0 : &connectionWork->mPlayerRecords[participantIndex];
}

static inline BOOL IsBootInfoFirstWordTwo(void) {
    if (gBootInfo->mBootType == 2) {
        return TRUE;
    }
    return FALSE;
}

void ResetRaceSetup(void) {
    u16 index;
    MinuteSecondMillisecondTime *time;

    gRaceSetup->mNextHeader.mCourseId = COURSE_ID_CROSS;
    gRaceSetup->mNextHeader.mCupIndex = 0;
    gRaceSetup->mNextHeader.mMode = MODE_GRAND_PRIX;
    gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
    gRaceSetup->mNextHeader.mEngineIndex = 0;
    gRaceSetup->mNextHeader.mCpuDifficulty = 0;
    gRaceSetup->mNextHeader.mBattleKind = 0;
    gRaceSetup->mNextHeader.mRuleKind = 0;
    gRaceSetup->mNextHeader.mCourseListMode = 0;
    gRaceSetup->mNextHeader.mGhostRecordIndex = 0;
    MI_CpuFill8(&gRaceSetup->mNextHeader.mMissionFileRow, 0, 0x2c);
    gRaceSetup->mNextHeader.mMissionTableRow = -1;
    gRaceSetup->mNextHeader.mMissionTableColumn = -1;
    gRaceSetup->mNextHeader.mUnk_56[0] = 0;
    gRaceSetup->mNextHeader.mMirrorMode = 0;
    gRaceSetup->mNextHeader.mUseTeams = 0;
    gRaceSetup->mNextHeader.mSeed = 0;
    gRaceSetup->mNextHeader.mCourseNumber = 1;
    gRaceSetup->mNextHeader.mEntryIndex = -1;
    gRaceSetup->mNextHeader.mFollowedKartIndex = 0;
    gRaceSetup->mNextHeader.mLapCount = -1;
    for (index = 0; index < 8; index++) {
        gRaceSetup->mNextEntries[index].mCharacterIndex = index;
        gRaceSetup->mNextEntries[index].mKartIndex = index * 3;
        gRaceSetup->mNextEntries[index].mPlayer.mKind = index == 0 ? PLAYER_KIND_HUMAN : PLAYER_KIND_CPU;
        gRaceSetup->mNextEntries[index].mPlayer.mTeamIndex = -1;
        gRaceSetup->mNextEntries[index].mPlayer.mListedCpuSlot = 3;
        gRaceSetup->mNextEntries[index].mPlayer.mIndex = index;
        gRaceSetup->mNextEntries[index].mPlayer.mGhostRecordIndex = 3;
        gRaceSetup->mNextEntries[index].mPlayer.mListedCpuFlags = 0;
        gRaceSetup->mNextEntries[index].mPlayer.mName = NULL;
        gRaceSetup->mNextEntries[index].mPlayer.mHasEmblem = 0;
        gRaceSetup->mNextEntries[index].mPlayer.mRegion = gStartupWork->mRegion;
        gRaceSetup->mNextEntries[index].mPlayer.mEmblemData = NULL;
        gRaceSetup->mNextEntries[index].mPlayer.mFriendData = 0;
    }
    gRaceSetup->mNextEntries[7].mPlayer.mListedCpuSlot = 0;
    gRaceSetup->mNextEntries[6].mPlayer.mListedCpuSlot = 1;
    gRaceSetup->mKartCount = 0;
    gRaceSetup->mHumanAndPeerKartCount = 0;
    for (index = 0; index < 2; index++) {
        gRaceSetup->mTeamKartCounts[index] = 0;
    }
    gRaceSetup->mListedCpuCount = 0;
    for (index = 0; index < 2; index++) {
        gRaceSetup->mListedCpuEntryIndices[index] = -1;
    }
    gRaceSetup->mCourseCount = 0;
    for (index = 0; index < 0x21; index++) {
        gRaceSetup->mCourseList[index] = 0;
    }
    gRaceSetup->mCourseListIndex = 0;
    time = &gRaceSetup->mGhostTime;
    time->mMinute = 0;
    time->mSecond = 0;
    time->mMillisecond = 0;
    for (index = 0; index < 5; index++) {
        time = &gRaceSetup->mGhostLapTimes[index];
        time->mMinute = 0;
        time->mSecond = 0;
        time->mMillisecond = 0;
    }
    ResetCupRecords();
    ResetParticipantKartMap();
    SetCurrentRaceFromNext();
}

void SetCurrentEntryPlayer(s32 entryIndex) {
    BackupBuffers *backupBuffers;
    ConnectionWork *connectionWork;
    void **nameSlot;
    void **emblemDataSlot;
    u8 *hasEmblemSlot;
    u8 *regionSlot;
    u8 *lowestRecordValueSlot;
    DWCAccFriendData **friendDataSlot;
    BOOL emblemFlag;
    BOOL hasEmblem;
    BOOL connectionActive;
    s8 participantOfKart;
    u8 participantIndex;

    backupBuffers = gBackupBuffers;
    nameSlot = &gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mName;
    emblemDataSlot = &gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mEmblemData;
    hasEmblemSlot = &gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mHasEmblem;
    regionSlot = &gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mRegion;
    lowestRecordValueSlot = &gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mLowestGrandPrixRecordValue;
    friendDataSlot = &gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mFriendData;
    emblemFlag = FALSE;
    if (backupBuffers->mEmblemRecord->mFilled != 0) {
        emblemFlag = backupBuffers->mFirstBlock->mEmblemOff == 0;
    }
    if (emblemFlag != FALSE) {
        hasEmblem = TRUE;
    } else {
        hasEmblem = FALSE;
    }
    *nameSlot = NULL;
    *emblemDataSlot = NULL;
    *hasEmblemSlot = 0;
    *friendDataSlot = 0;
    *regionSlot = gStartupWork->mRegion;
    *lowestRecordValueSlot = 0;
    if (entryIndex == gRaceSetup->mEntryIndex) {
        *nameSlot = &gBackupBuffers->mFirstBlock->mPlayerName;
        *emblemDataSlot = &gBackupBuffers->mEmblemRecord->mEmblemData;
        *hasEmblemSlot = hasEmblem != FALSE ? 1 : 0;
        *regionSlot = gStartupWork->mRegion;
        *lowestRecordValueSlot = GetLowestGrandPrixRecordValue();
        return;
    }
    switch (gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mKind) {
        case PLAYER_KIND_HUMAN:
            connectionWork = gConnectionWork;
            connectionActive = FALSE;
            if ((connectionWork == NULL ? 0 : connectionWork->mConnectionMode) != 0 && connectionWork->mState != 13) {
                connectionActive = TRUE;
            }
            if (connectionActive == FALSE) {
                return;
            }
            if (GetPlayerRecordByEntryIndex(connectionWork, entryIndex) == NULL) {
                return;
            }
            *nameSlot = GetPlayerRecordByEntryIndex(connectionWork, entryIndex);
            *emblemDataSlot = &GetPlayerRecordByEntryIndex(gConnectionWork, entryIndex)->mEmblem[0];
            *hasEmblemSlot = GetPlayerRecordByEntryIndex(gConnectionWork, entryIndex)->mHasEmblem;
            *regionSlot = GetPlayerRecordByEntryIndex(gConnectionWork, entryIndex)->mRegion;
            *friendDataSlot =
                IsBootInfoFirstWordTwo() || (gConnectionWork->mGroupSendMask &
                                             (1 << gConnectionWork->mParticipantIndexByPos[entryIndex])) != 0
                    ? 0
                    : &GetPlayerRecordByEntryIndex(gConnectionWork, entryIndex)->mFriendData;
            *lowestRecordValueSlot =
                GetPlayerRecordByEntryIndex(gConnectionWork, entryIndex)->mLowestGrandPrixRecordValue;
            break;
        case PLAYER_KIND_GHOST:
            switch (gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mGhostRecordIndex) {
                case 0:
                    *nameSlot = &gBackupBuffers->mCourseGhostRecord->mHead.mName;
                    *emblemDataSlot = &gBackupBuffers->mEmblemRecord->mEmblemData;
                    *hasEmblemSlot = hasEmblem != FALSE ? 1 : 0;
                    *regionSlot = gBackupBuffers->mCourseGhostRecord->mHead.mRegion;
                    *lowestRecordValueSlot = 0;
                    break;
                case 1:
                    *nameSlot = &gBackupBuffers->mSlotGhostRecords[0]->mHead.mName;
                    *emblemDataSlot = &gBackupBuffers->mSlotGhostRecords[0]->mEmblem;
                    *hasEmblemSlot = gBackupBuffers->mSlotGhostRecords[0]->mHead.mHasEmblem;
                    *regionSlot = gBackupBuffers->mSlotGhostRecords[0]->mHead.mRegion;
                    *lowestRecordValueSlot = gBackupBuffers->mSlotGhostRecords[0]->mHead.mLowestGrandPrixRecordValue;
                    break;
                case 2:
                    *nameSlot = &gBackupBuffers->mSlotGhostRecords[1]->mHead.mName;
                    *emblemDataSlot = &gBackupBuffers->mSlotGhostRecords[1]->mEmblem;
                    *hasEmblemSlot = 1;
                    *regionSlot = gBackupBuffers->mSlotGhostRecords[1]->mHead.mRegion;
                    *lowestRecordValueSlot = 1;
                    break;
            }
            break;
        case PLAYER_KIND_PEER:
            participantOfKart = GetParticipantOfKart(entryIndex);
            if (participantOfKart < 0) {
                return;
            }
            participantIndex = participantOfKart;
            *nameSlot = GetPlayerRecordName(participantIndex);
            *emblemDataSlot = GetPlayerRecordEmblem(participantIndex);
            *hasEmblemSlot = HasPlayerRecordEmblem(participantIndex);
            *regionSlot = GetPlayerRecordRegion(participantIndex);
            *friendDataSlot = GetPlayerRecordFriendData(participantIndex);
            *lowestRecordValueSlot = GetPlayerRecordLowestGrandPrixValue(participantIndex);
            break;
    }
}

void RefreshListedCpuEntryIndices(void) {
    u8 listedCount;
    s8 entryIndex;

    listedCount = 0;
    for (entryIndex = 0; entryIndex < 2; entryIndex++) {
        gRaceSetup->mListedCpuEntryIndices[entryIndex] = -1;
    }
    for (entryIndex = 0; entryIndex < gRaceSetup->mKartCount; entryIndex++) {
        if ((GetCurrentEntry(entryIndex)->mPlayer.mListedCpuFlags & KART_ENTRY_LISTED_CPU_FLAG) != 0) {
            SetListedCpuEntryIndex(gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mListedCpuSlot, entryIndex);
            listedCount++;
        }
    }
    gRaceSetup->mListedCpuCount = listedCount;
}

BOOL SetNextEntryFromCourseGhost(s32 courseId, s32 entryIndex) {
    u8 lapIndex;
    BOOL result;
    GhostRecord *ghostRecord;

    result = FALSE;
    if (gRaceSetup->mNextHeader.mRaceKind == RACE_KIND_REPLAY) {
        return TRUE;
    }
    ghostRecord = gBackupBuffers->mCourseGhostRecord;
    if (ghostRecord->mHead.mFilled == 1) {
        SetNextRaceEntry(entryIndex, ghostRecord->mHead.mCharacterIndex, ghostRecord->mHead.mKartIndex,
                         PLAYER_KIND_GHOST, -1, 3);
        gRaceSetup->mNextEntries[entryIndex].mPlayer.mGhostRecordIndex = result;
        MI_CpuCopy8(ghostRecord->mKeyRecordingBuffer, gInputSlots[entryIndex].mUnk_28.mBuffer, 0xdcc);
        result = TRUE;
        GetGhostFinishTimeByIndex(0, &gRaceSetup->mGhostTime);
        for (lapIndex = 1; lapIndex <= 5; lapIndex++) {
            GetGhostLapTimeByIndex(0, lapIndex, &gRaceSetup->mGhostLapTimes[lapIndex - 1]);
        }
    }
    return result;
}

BOOL SetNextEntryFromFirstSlotGhost(s32 courseId, s32 entryIndex) {
    SlotGhostRecord *ghostRecord;
    s32 filled;
    u8 lapIndex;

    if (gRaceSetup->mNextHeader.mRaceKind == RACE_KIND_REPLAY) {
        return 1;
    }
    ghostRecord = gBackupBuffers->mSlotGhostRecords[0];
    filled = ghostRecord->mHead.mFilled == 1 ? 1 : 0;
    if (filled != 0) {
        SetNextRaceEntry(entryIndex, ghostRecord->mHead.mCharacterIndex, ghostRecord->mHead.mKartIndex,
                         PLAYER_KIND_GHOST, -1, 3);
        gRaceSetup->mNextEntries[entryIndex].mPlayer.mGhostRecordIndex = 1;
        MI_CpuCopy8(ghostRecord->mKeyRecordingBuffer, gInputSlots[entryIndex].mUnk_28.mBuffer, 0xdcc);
        GetGhostFinishTimeByIndex(1, &gRaceSetup->mGhostTime);
        for (lapIndex = 1; lapIndex <= 5; lapIndex++) {
            GetGhostLapTimeByIndex(1, lapIndex, &gRaceSetup->mGhostLapTimes[lapIndex - 1]);
        }
    } else {
        SetNextRaceEntry(entryIndex, 0, 0, PLAYER_KIND_NONE, -1, 3);
    }
    return filled;
}

BOOL SetNextEntryFromSecondSlotGhost(s32 courseId, s32 entryIndex) {
    SlotGhostRecord *ghostRecord;
    u8 lapIndex;

    if (gRaceSetup->mNextHeader.mRaceKind == RACE_KIND_REPLAY) {
        return TRUE;
    }
    ghostRecord = gBackupBuffers->mSlotGhostRecords[1];
    if (ghostRecord != NULL && ghostRecord->mHead.mFilled == 1) {
        SetNextRaceEntry(entryIndex, ghostRecord->mHead.mCharacterIndex, ghostRecord->mHead.mKartIndex,
                         PLAYER_KIND_GHOST, -1, 3);
        gRaceSetup->mNextEntries[entryIndex].mPlayer.mGhostRecordIndex = 2;
        MI_CpuCopy8(ghostRecord->mKeyRecordingBuffer, gInputSlots[entryIndex].mUnk_28.mBuffer, 0xdcc);
        GetGhostFinishTime(&ghostRecord->mHead, &gRaceSetup->mGhostTime);
        for (lapIndex = 1; lapIndex <= 5; lapIndex++) {
            GetGhostLapTime(&ghostRecord->mHead, lapIndex, &gRaceSetup->mGhostLapTimes[lapIndex - 1]);
        }
        return TRUE;
    }
    SetNextRaceEntry(entryIndex, 0, 0, PLAYER_KIND_NONE, -1, 3);
    return FALSE;
}

void SetCurrentRaceFromNext(void) {
    s16 entryIndex;
    GhostRecord *ghostRecord;
    ConnectionWork *connectionWork;
    u16 value;
    u16 entryCount;
    u8 searchIndex;
    BOOL connectionActive;

    entryCount = 0;
    switch (gRaceSetup->mNextHeader.mMode) {
        case MODE_GRAND_PRIX:
        case MODE_BATTLE:
        case MODE_VS:
            entryCount = 8;
            break;
        case MODE_WIFI:
            entryCount = 4;
            break;
        case MODE_TIME_ATTACK:
            value = 1;
            ghostRecord = gBackupBuffers->mCourseGhostRecord;
            if (ghostRecord->mHead.mFilled == 1) {
                gRaceSetup->mFirstGhostRecordFilled = 1;
                gRaceSetup->mFirstGhostRecordMinute = ghostRecord->mHead.mMinute;
                gRaceSetup->mFirstGhostRecordSecond = ghostRecord->mHead.mSecond;
                gRaceSetup->mFirstGhostRecordMillisecond = ghostRecord->mHead.mMillisecond;
            } else {
                gRaceSetup->mFirstGhostRecordFilled = 0;
                gRaceSetup->mFirstGhostRecordMinute = 0;
                gRaceSetup->mFirstGhostRecordSecond = 0;
                gRaceSetup->mFirstGhostRecordMillisecond = 0;
            }
            switch (gRaceSetup->mNextHeader.mGhostRecordIndex) {
                case 0:
                    if (SetNextEntryFromCourseGhost(gRaceSetup->mNextHeader.mCourseId, 1) != 0) {
                        value++;
                    }
                    break;
                case 1:
                    if (SetNextEntryFromFirstSlotGhost(gRaceSetup->mNextHeader.mCourseId, 1) != 0) {
                        value++;
                    }
                    break;
                case 2:
                    if (SetNextEntryFromSecondSlotGhost(gRaceSetup->mNextHeader.mCourseId, 1) != FALSE) {
                        value++;
                    }
                    break;
                case 3:
                    break;
            }
            entryCount = value;
            break;
        case MODE_MISSION_RUN:
            entryCount = 2;
            break;
    }
    switch (gRaceSetup->mNextHeader.mRaceKind) {
        case RACE_KIND_DEMO:
        case RACE_KIND_AWARD:
            gRaceSetup->mNextHeader.mEntryIndex = gRaceSetup->mNextHeader.mFollowedKartIndex;
            break;
        case RACE_KIND_STAFF_ROLL:
            gRaceSetup->mNextHeader.mEntryIndex = gRaceSetup->mNextHeader.mFollowedKartIndex;
            entryCount = 8;
            break;
        case RACE_KIND_NORMAL:
        case RACE_KIND_REPLAY:
        case RACE_KIND_START_GP:
        case 4:
            entryIndex = 0;
            for (searchIndex = 0; searchIndex < 8; searchIndex++) {
                if (gRaceSetup->mNextEntries[searchIndex].mPlayer.mKind == PLAYER_KIND_HUMAN) {
                    entryIndex = searchIndex;
                    break;
                }
            }
            connectionWork = gConnectionWork;
            connectionActive = FALSE;
            if ((connectionWork == NULL ? 0 : connectionWork->mConnectionMode) != 0 && connectionWork->mState != 13) {
                connectionActive = TRUE;
            }
            if (connectionActive != FALSE) {
                entryIndex = connectionWork
                                 ->mParticipantPosByIndex[(
                                     u16) (connectionWork->mConnectionMode == 2 ? connectionWork->mOwnIndex : 0)]
                                 .mEntryIndex;
            }
            gRaceSetup->mNextHeader.mEntryIndex = entryIndex;
            gRaceSetup->mNextHeader.mFollowedKartIndex = entryIndex;
            break;
    }
    *(RaceSetupBlock *) gRaceSetup = *(RaceSetupBlock *) &gRaceSetup->mNextHeader;
    RefreshRaceSetupKartCounts(entryCount);
    RefreshListedCpuEntryIndices();
    for (value = 0; value < 8; value++) {
        SetCurrentEntryPlayer(value);
    }
}

void SetNextRaceByMode(void) {
    u8 entryIndex;
    u32 tableIndex;
    u8 cupIndex;
    u8 courseIndexInCup;
    RaceSetupHeader *nextHeader;
    s32 cupCourseId;
    u8 rankIndex;
    s32 kartIndex;

    switch (gRaceSetup->mNextHeader.mMode) {
        case MODE_GRAND_PRIX:
            if (gRaceSetup->mNextHeader.mCourseId == COURSE_ID_AWARD) {
                gRaceSetup->mNextHeader.mCourseId = COURSE_ID_AWARD;
                gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_AWARD;
                for (entryIndex = 3; entryIndex < 8; entryIndex++) {
                    SetNextRaceEntry(entryIndex, entryIndex, entryIndex * 3, PLAYER_KIND_NONE, -1, 3);
                }
                gRaceSetup->mNextHeader.mFollowedKartIndex = 0;
            } else if ((u32) (gRaceSetup->mNextHeader.mCourseId - 0x35) <= 1) {
                gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_STAFF_ROLL;
                gRaceSetup->mNextHeader.mEngineIndex = 1;
                for (rankIndex = 0; rankIndex < 8; rankIndex++) {
                    s8 rankKartIndex;
                    for (rankKartIndex = 0; rankKartIndex < gRaceSetup->mKartCount; rankKartIndex++) {
                        if (rankIndex + 1 == GetKartCupRank((u16) rankKartIndex)) {
                            break;
                        }
                    }
                    kartIndex = rankIndex * 3;
                    if (gRaceSetup->mNextHeader.mCourseId != COURSE_ID_STAFFROLLTRUE) {
                        SetNextRaceEntryWrapper(3, -1, 1, kartIndex, rankIndex, rankIndex);
                    }
                }
                gRaceSetup->mNextHeader.mFollowedKartIndex = 0;
            } else {
                for (tableIndex = 0; tableIndex < 32; tableIndex++) {
                    cupIndex = (s32) tableIndex / 4;
                    courseIndexInCup = (s32) tableIndex % 4;
                    cupCourseId = gCupCourseIdTable[cupIndex][courseIndexInCup];
                    if (gRaceSetup->mNextHeader.mCourseId == cupCourseId) {
                        break;
                    }
                    if (tableIndex == 31) {
                        cupIndex = 0;
                        courseIndexInCup = 3;
                    }
                }
                gRaceSetup->mNextHeader.mCourseNumber = (u8) (courseIndexInCup + 1);
                nextHeader = &gRaceSetup->mNextHeader;
                gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_START_GP;
                gRaceSetup->mNextHeader.mCupIndex = cupIndex;
            }
            break;
        case MODE_BATTLE:
            if (gStartupWork->mMultiSimple != 0) {
                gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
            } else {
                gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_START_BATTLE;
            }
            break;
        case MODE_MISSION_RUN:
            break;
        default:
            gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
            break;
    }
}

void ResetTimeAttackNextEntries(void) {
    u16 entryIndex;

    if (gRaceSetup->mNextHeader.mMode != MODE_TIME_ATTACK) {
        return;
    }
    gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
    for (entryIndex = 1; entryIndex < 8; entryIndex++) {
        gRaceSetup->mNextEntries[entryIndex].mCharacterIndex = entryIndex;
        gRaceSetup->mNextEntries[entryIndex].mKartIndex = entryIndex;
        gRaceSetup->mNextEntries[entryIndex].mPlayer.mKind = PLAYER_KIND_NONE;
        gRaceSetup->mNextEntries[entryIndex].mPlayer.mIndex = entryIndex;
    }
}

// In battle there is one lap.
u16 GetLapCount(void) {
    RaceSetup *raceSetup;
    u16 lapCount;

    lapCount = 1;
    raceSetup = gRaceSetup;
    if (raceSetup->mMode != MODE_BATTLE) {
        if (raceSetup->mLapCount <= 0) {
            lapCount = gCourseMap->mSettings->mLapCountOrBattleSeconds;
        } else {
            lapCount = raceSetup->mLapCount;
        }
    }
    return lapCount;
}
