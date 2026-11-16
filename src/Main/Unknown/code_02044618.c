#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Save/GhostTimes.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02120294.h"
#include "Main/Unknown/code_02120240.h"
#include "Main/Unknown/code_021201e4.h"
#include "Main/Unknown/code_021202f0.h"
#include "Main/Unknown/code_0211d4a8.h"
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
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

static inline void func_020446e0_inline(s32 f, u32 teamIndex, s32 playerKind, u32 kartIndex, u32 characterIndex,
                                        s32 entryIndex) {
    rconf_setDriverConfigNext(entryIndex, characterIndex, kartIndex, playerKind, teamIndex, f);
}

static inline Unk0217aa00_45c *func_02045084_inline(ConnectionWork *q, s32 entryIndex) {
    u16 participantIndex;

    participantIndex = q->mUnk_1e8c[entryIndex];
    return participantIndex == 0xffff ? 0 : &q->mUnk_045c[participantIndex];
}

static inline BOOL func_02045084_inline2(void) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        return TRUE;
    }
    return FALSE;
}

void rconf_reset(void) {
    u16 i;
    MinuteSecondMillisecondTime *time;

    gRaceMultiConfig->mNextHeader.mCourseId = COURSE_ID_CROSS;
    gRaceMultiConfig->mNextHeader.mCupIndex = 0;
    gRaceMultiConfig->mNextHeader.mMode = MODE_GRAND_PRIX;
    gRaceMultiConfig->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
    gRaceMultiConfig->mNextHeader.mEngineIndex = 0;
    gRaceMultiConfig->mNextHeader.mCpuDifficulty = 0;
    gRaceMultiConfig->mNextHeader.mBattleKind = 0;
    gRaceMultiConfig->mNextHeader.mRuleKind = 0;
    gRaceMultiConfig->mNextHeader.mCourseListMode = 0;
    gRaceMultiConfig->mNextHeader.mGhostRecordIndex = 0;
    MI_CpuFill8(&gRaceMultiConfig->mNextHeader.mMissionFileRow, 0, 0x2c);
    gRaceMultiConfig->mNextHeader.mMissionTableRow = -1;
    gRaceMultiConfig->mNextHeader.mMissionTableColumn = -1;
    gRaceMultiConfig->mNextHeader.mUnk_56[0] = 0;
    gRaceMultiConfig->mNextHeader.mMirrorMode = 0;
    gRaceMultiConfig->mNextHeader.mUseTeams = 0;
    gRaceMultiConfig->mNextHeader.mUnk_5c = 0;
    gRaceMultiConfig->mNextHeader.mCourseNumber = 1;
    gRaceMultiConfig->mNextHeader.mEntryIndex = -1;
    gRaceMultiConfig->mNextHeader.mFollowedKartIndex = 0;
    gRaceMultiConfig->mNextHeader.mLapCount = -1;
    for (i = 0; i < 8; i++) {
        gRaceMultiConfig->mNextEntries[i].mCharacterIndex = i;
        gRaceMultiConfig->mNextEntries[i].mKartIndex = i * 3;
        gRaceMultiConfig->mNextEntries[i].mPlayer.mKind = i == 0 ? PLAYER_KIND_HUMAN : PLAYER_KIND_CPU;
        gRaceMultiConfig->mNextEntries[i].mPlayer.mTeamIndex = -1;
        gRaceMultiConfig->mNextEntries[i].mPlayer.mUnk_08 = 3;
        gRaceMultiConfig->mNextEntries[i].mPlayer.mIndex = i;
        gRaceMultiConfig->mNextEntries[i].mPlayer.mGhostRecordIndex = 3;
        gRaceMultiConfig->mNextEntries[i].mPlayer.mUnk_14 = 0;
        gRaceMultiConfig->mNextEntries[i].mPlayer.mName = NULL;
        gRaceMultiConfig->mNextEntries[i].mPlayer.mUnk_24 = 0;
        gRaceMultiConfig->mNextEntries[i].mPlayer.mUnk_25 = gSystemData->mUnk_00;
        gRaceMultiConfig->mNextEntries[i].mPlayer.mEmblemData = NULL;
        gRaceMultiConfig->mNextEntries[i].mPlayer.mUnk_20 = 0;
    }
    gRaceMultiConfig->mNextEntries[7].mPlayer.mUnk_08 = 0;
    gRaceMultiConfig->mNextEntries[6].mPlayer.mUnk_08 = 1;
    gRaceMultiConfig->mKartCount = 0;
    gRaceMultiConfig->mHumanAndPeerKartCount = 0;
    for (i = 0; i < 2; i++) {
        gRaceMultiConfig->mTeamKartCounts[i] = 0;
    }
    gRaceMultiConfig->mUnk_3d4 = 0;
    for (i = 0; i < 2; i++) {
        gRaceMultiConfig->mUnk_3d5[i] = -1;
    }
    gRaceMultiConfig->mCourseCount = 0;
    for (i = 0; i < 0x21; i++) {
        gRaceMultiConfig->mCourseList[i] = 0;
    }
    gRaceMultiConfig->mCourseListIndex = 0;
    time = &gRaceMultiConfig->mGhostTime;
    time->mMinute = 0;
    time->mSecond = 0;
    time->mMillisecond = 0;
    for (i = 0; i < 5; i++) {
        time = &gRaceMultiConfig->mGhostLapTimes[i];
        time->mMinute = 0;
        time->mSecond = 0;
        time->mMillisecond = 0;
    }
    rres_reset();
    ResetParticipantKartMap();
    rconf_setupNext();
}

void SetCurrentEntryPlayer(s32 entryIndex) {
    Unk0217aa08 *p;
    ConnectionWork *q;
    void **nameSlot;
    void **emblemDataSlot;
    u8 *b2;
    u8 *b3;
    u8 *b4;
    s32 *b5;
    BOOL f;
    BOOL g;
    BOOL t;
    s8 x;
    u8 v;

    p = gSaveData;
    nameSlot = &gRaceMultiConfig->mCurrentEntries[entryIndex].mPlayer.mName;
    emblemDataSlot = &gRaceMultiConfig->mCurrentEntries[entryIndex].mPlayer.mEmblemData;
    b2 = &gRaceMultiConfig->mCurrentEntries[entryIndex].mPlayer.mUnk_24;
    b3 = &gRaceMultiConfig->mCurrentEntries[entryIndex].mPlayer.mUnk_25;
    b4 = &gRaceMultiConfig->mCurrentEntries[entryIndex].mPlayer.mUnk_26;
    b5 = &gRaceMultiConfig->mCurrentEntries[entryIndex].mPlayer.mUnk_20;
    f = FALSE;
    if (p->mEmblemRecord->mFilled != 0) {
        f = p->mFirstBlock->mUnk_31_3 == 0;
    }
    if (f != FALSE) {
        g = TRUE;
    } else {
        g = FALSE;
    }
    *nameSlot = NULL;
    *emblemDataSlot = NULL;
    *b2 = 0;
    *b5 = 0;
    *b3 = gSystemData->mUnk_00;
    *b4 = 0;
    if (entryIndex == gRaceMultiConfig->mEntryIndex) {
        *nameSlot = &gSaveData->mFirstBlock->mPlayerName;
        *emblemDataSlot = &gSaveData->mEmblemRecord->mEmblemData;
        *b2 = g != FALSE ? 1 : 0;
        *b3 = gSystemData->mUnk_00;
        *b4 = func_02056208();
        return;
    }
    switch (gRaceMultiConfig->mCurrentEntries[entryIndex].mPlayer.mKind) {
        case PLAYER_KIND_HUMAN:
            q = gStruct217AA00;
            t = FALSE;
            if ((q == NULL ? 0 : q->mUnk_0000) != 0 && q->mUnk_0004 != 13) {
                t = TRUE;
            }
            if (t == FALSE) {
                return;
            }
            if (func_02045084_inline(q, entryIndex) == NULL) {
                return;
            }
            *nameSlot = func_02045084_inline(q, entryIndex);
            *emblemDataSlot = &func_02045084_inline(gStruct217AA00, entryIndex)->mUnk_014;
            *b2 = func_02045084_inline(gStruct217AA00, entryIndex)->mUnk_214;
            *b3 = func_02045084_inline(gStruct217AA00, entryIndex)->mUnk_228_0;
            *b5 =
                func_02045084_inline2() || (gStruct217AA00->mUnk_0457 & (1 << gStruct217AA00->mUnk_1e8c[entryIndex])) != 0
                    ? 0
                    : (s32) &func_02045084_inline(gStruct217AA00, entryIndex)->mUnk_218;
            *b4 = func_02045084_inline(gStruct217AA00, entryIndex)->mUnk_229;
            break;
        case PLAYER_KIND_GHOST:
            switch (gRaceMultiConfig->mCurrentEntries[entryIndex].mPlayer.mGhostRecordIndex) {
                case 0:
                    *nameSlot = &gSaveData->mGhostRecords[0]->mName;
                    *emblemDataSlot = &gSaveData->mEmblemRecord->mEmblemData;
                    *b2 = g != FALSE ? 1 : 0;
                    *b3 = gSaveData->mGhostRecords[0]->mUnk_08_2;
                    *b4 = 0;
                    break;
                case 1:
                    *nameSlot = &gSaveData->mGhostRecords[1]->mName;
                    *emblemDataSlot = &gSaveData->mGhostRecords[1]->mUnk_30;
                    *b2 = gSaveData->mGhostRecords[1]->mUnk_08_1;
                    *b3 = gSaveData->mGhostRecords[1]->mUnk_08_2;
                    *b4 = gSaveData->mGhostRecords[1]->mUnk_2f_0;
                    break;
                case 2:
                    *nameSlot = &gSaveData->mGhostRecords[2]->mName;
                    *emblemDataSlot = &gSaveData->mGhostRecords[2]->mUnk_30;
                    *b2 = 1;
                    *b3 = gSaveData->mGhostRecords[2]->mUnk_08_2;
                    *b4 = 1;
                    break;
            }
            break;
        case PLAYER_KIND_PEER:
            x = gStruct217AA18->mParticipantOfKart[(u8) entryIndex];
            if (x < 0) {
                return;
            }
            v = x;
            *nameSlot = GetPlayerRecordName(v);
            *emblemDataSlot = GetPlayerRecordEmblem(v);
            *b2 = func_02120278(v);
            *b3 = GetPlayerRecordRegion(v);
            *b5 = func_021202f0(v);
            *b4 = func_021201e4(v);
            break;
    }
}

void func_02044fc0(void) {
    u8 n;
    s8 j;

    n = 0;
    for (j = 0; j < 2; j++) {
        gRaceMultiConfig->mUnk_3d5[j] = -1;
    }
    for (j = 0; j < gRaceMultiConfig->mKartCount; j++) {
        if ((gRaceMultiConfig->mCurrentEntries[(u16) j].mPlayer.mUnk_14 & 1) != 0) {
            gRaceMultiConfig->mUnk_3d5[(u8) gRaceMultiConfig->mCurrentEntries[j].mPlayer.mUnk_08] = j;
            n++;
        }
    }
    gRaceMultiConfig->mUnk_3d4 = n;
}

BOOL rconf_loadPersonalGhost(s32 courseId, s32 entryIndex) {
    u8 i;
    BOOL result;
    GhostRecord *ghostRecord;

    result = FALSE;
    if (gRaceMultiConfig->mNextHeader.mRaceKind == 2) {
        return TRUE;
    }
    ghostRecord = gSaveData->mGhostRecords[0];
    if (ghostRecord->mFilled == 1) {
        rconf_setDriverConfigNext(entryIndex, ghostRecord->mCharacterIndex, ghostRecord->mKartIndex, PLAYER_KIND_GHOST, -1, 3);
        gRaceMultiConfig->mNextEntries[entryIndex].mPlayer.mGhostRecordIndex = result;
        MI_CpuCopy8(ghostRecord->mUnk_30, data_02175650[entryIndex].mBuffer, 0xdcc);
        result = TRUE;
        savd_getGhostTime(0, &gRaceMultiConfig->mGhostTime);
        for (i = 1; i <= 5; i++) {
            savd_getGhostLapTime(0, i, &gRaceMultiConfig->mGhostLapTimes[i - 1]);
        }
    }
    return result;
}

s32 rconf_loadDownloadGhost(s32 courseId, s32 entryIndex) {
    GhostRecord *ghostRecord;
    s32 filled;
    u8 i;

    if (gRaceMultiConfig->mNextHeader.mRaceKind == 2) {
        return 1;
    }
    ghostRecord = gSaveData->mGhostRecords[1];
    filled = ghostRecord->mFilled == 1 ? 1 : 0;
    if (filled != 0) {
        rconf_setDriverConfigNext(entryIndex, ghostRecord->mCharacterIndex, ghostRecord->mKartIndex, PLAYER_KIND_GHOST, -1, 3);
        gRaceMultiConfig->mNextEntries[entryIndex].mPlayer.mGhostRecordIndex = 1;
        MI_CpuCopy8(&ghostRecord->mUnk_30[0x200], data_02175650[entryIndex].mBuffer, 0xdcc);
        savd_getGhostTime(1, &gRaceMultiConfig->mGhostTime);
        for (i = 1; i <= 5; i++) {
            savd_getGhostLapTime(1, i, &gRaceMultiConfig->mGhostLapTimes[i - 1]);
        }
    } else {
        rconf_setDriverConfigNext(entryIndex, 0, 0, PLAYER_KIND_NONE, -1, 3);
    }
    return filled;
}

BOOL rconf_loadStaffGhost(s32 courseId, s32 entryIndex) {
    GhostRecord *ghostRecord;
    u8 i;

    if (gRaceMultiConfig->mNextHeader.mRaceKind == 2) {
        return TRUE;
    }
    ghostRecord = gSaveData->mGhostRecords[2];
    if (ghostRecord != NULL && ghostRecord->mFilled == 1) {
        rconf_setDriverConfigNext(entryIndex, ghostRecord->mCharacterIndex, ghostRecord->mKartIndex, PLAYER_KIND_GHOST, -1, 3);
        gRaceMultiConfig->mNextEntries[entryIndex].mPlayer.mGhostRecordIndex = 2;
        MI_CpuCopy8(&ghostRecord->mUnk_30[0x200], data_02175650[entryIndex].mBuffer, 0xdcc);
        savd_getGhostTimeDirect(ghostRecord, &gRaceMultiConfig->mGhostTime);
        for (i = 1; i <= 5; i++) {
            savd_getGhostLapTimeDirect(ghostRecord, i, &gRaceMultiConfig->mGhostLapTimes[i - 1]);
        }
        return TRUE;
    }
    rconf_setDriverConfigNext(entryIndex, 0, 0, PLAYER_KIND_NONE, -1, 3);
    return FALSE;
}

void rconf_setupNext(void) {
    s16 entryIndex;
    GhostRecord *ghostRecord;
    ConnectionWork *q;
    u16 n;
    u16 entryCount;
    u8 i;
    BOOL f;

    entryCount = 0;
    switch (gRaceMultiConfig->mNextHeader.mMode) {
        case MODE_GRAND_PRIX:
        case MODE_BATTLE:
        case MODE_VS:
            entryCount = 8;
            break;
        case 5:
            entryCount = 4;
            break;
        case MODE_TIME_ATTACK:
            n = 1;
            ghostRecord = gSaveData->mGhostRecords[0];
            if (ghostRecord->mFilled == 1) {
                gRaceMultiConfig->mFirstGhostRecordFilled = 1;
                gRaceMultiConfig->mFirstGhostRecordMinute = ghostRecord->mMinute;
                gRaceMultiConfig->mFirstGhostRecordSecond = ghostRecord->mSecond;
                gRaceMultiConfig->mFirstGhostRecordMillisecond = ghostRecord->mMillisecond;
            } else {
                gRaceMultiConfig->mFirstGhostRecordFilled = 0;
                gRaceMultiConfig->mFirstGhostRecordMinute = 0;
                gRaceMultiConfig->mFirstGhostRecordSecond = 0;
                gRaceMultiConfig->mFirstGhostRecordMillisecond = 0;
            }
            switch (gRaceMultiConfig->mNextHeader.mGhostRecordIndex) {
                case 0:
                    if (rconf_loadPersonalGhost(gRaceMultiConfig->mNextHeader.mCourseId, 1) != 0) {
                        n++;
                    }
                    break;
                case 1:
                    if (rconf_loadDownloadGhost(gRaceMultiConfig->mNextHeader.mCourseId, 1) != 0) {
                        n++;
                    }
                    break;
                case 2:
                    if (rconf_loadStaffGhost(gRaceMultiConfig->mNextHeader.mCourseId, 1) != FALSE) {
                        n++;
                    }
                    break;
                case 3:
                    break;
            }
            entryCount = n;
            break;
        case MODE_MISSION_RUN:
            entryCount = 2;
            break;
    }
    switch (gRaceMultiConfig->mNextHeader.mRaceKind) {
        case RACE_KIND_DEMO:
        case RACE_KIND_AWARD:
            gRaceMultiConfig->mNextHeader.mEntryIndex = gRaceMultiConfig->mNextHeader.mFollowedKartIndex;
            break;
        case RACE_KIND_STAFF_ROLL:
            gRaceMultiConfig->mNextHeader.mEntryIndex = gRaceMultiConfig->mNextHeader.mFollowedKartIndex;
            entryCount = 8;
            break;
        case RACE_KIND_NORMAL:
        case 2:
        case RACE_KIND_START_GP:
        case 4:
            entryIndex = 0;
            for (i = 0; i < 8; i++) {
                if (gRaceMultiConfig->mNextEntries[i].mPlayer.mKind == PLAYER_KIND_HUMAN) {
                    entryIndex = i;
                    break;
                }
            }
            q = gStruct217AA00;
            f = FALSE;
            if ((q == NULL ? 0 : q->mUnk_0000) != 0 && q->mUnk_0004 != 13) {
                f = TRUE;
            }
            if (f != FALSE) {
                entryIndex = q->mUnk_1e52[(u16) (q->mUnk_0000 == 2 ? q->mOwnIndex : 0)].mEntryIndex;
            }
            gRaceMultiConfig->mNextHeader.mEntryIndex = entryIndex;
            gRaceMultiConfig->mNextHeader.mFollowedKartIndex = entryIndex;
            break;
    }
    *(RaceSetupBlock *) gRaceMultiConfig = *(RaceSetupBlock *) &gRaceMultiConfig->mNextHeader;
    RefreshRaceSetupKartCounts(entryCount);
    func_02044fc0();
    for (n = 0; n < 8; n++) {
        SetCurrentEntryPlayer(n);
    }
}

void func_020446e0(void) {
    u8 i;
    u32 tableIndex;
    u8 cupIndex;
    u8 courseIndexInCup;
    RaceSetupHeader *a;
    s32 cupCourseId;
    u8 rankIndex;
    s32 kartIndex;

    switch (gRaceMultiConfig->mNextHeader.mMode) {
        case MODE_GRAND_PRIX:
            if (gRaceMultiConfig->mNextHeader.mCourseId == COURSE_ID_AWARD) {
                gRaceMultiConfig->mNextHeader.mCourseId = COURSE_ID_AWARD;
                gRaceMultiConfig->mNextHeader.mRaceKind = RACE_KIND_AWARD;
                for (i = 3; i < 8; i++) {
                    rconf_setDriverConfigNext(i, i, i * 3, PLAYER_KIND_NONE, -1, 3);
                }
                gRaceMultiConfig->mNextHeader.mFollowedKartIndex = 0;
            } else if ((u32) (gRaceMultiConfig->mNextHeader.mCourseId - 0x35) <= 1) {
                gRaceMultiConfig->mNextHeader.mRaceKind = RACE_KIND_STAFF_ROLL;
                gRaceMultiConfig->mNextHeader.mEngineIndex = 1;
                for (rankIndex = 0; rankIndex < 8; rankIndex++) {
                    s8 j;
                    for (j = 0; j < gRaceMultiConfig->mKartCount; j++) {
                        if (rankIndex + 1 == rres_getGlobalRank((u16) j)) {
                            break;
                        }
                    }
                    kartIndex = rankIndex * 3;
                    if (gRaceMultiConfig->mNextHeader.mCourseId != COURSE_ID_STAFFROLLTRUE) {
                        func_020446e0_inline(3, -1, 1, kartIndex, rankIndex, rankIndex);
                    }
                }
                gRaceMultiConfig->mNextHeader.mFollowedKartIndex = 0;
            } else {
                for (tableIndex = 0; tableIndex < 32; tableIndex++) {
                    cupIndex = (s32) tableIndex / 4;
                    courseIndexInCup = (s32) tableIndex % 4;
                    cupCourseId = sCupDefs[cupIndex][courseIndexInCup];
                    if (gRaceMultiConfig->mNextHeader.mCourseId == cupCourseId) {
                        break;
                    }
                    if (tableIndex == 31) {
                        cupIndex = 0;
                        courseIndexInCup = 3;
                    }
                }
                gRaceMultiConfig->mNextHeader.mCourseNumber = (u8) (courseIndexInCup + 1);
                a = &gRaceMultiConfig->mNextHeader;
                gRaceMultiConfig->mNextHeader.mRaceKind = RACE_KIND_START_GP;
                gRaceMultiConfig->mNextHeader.mCupIndex = cupIndex;
            }
            break;
        case MODE_BATTLE:
            if (gSystemData->mUnk_1c_2 != 0) {
                gRaceMultiConfig->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
            } else {
                gRaceMultiConfig->mNextHeader.mRaceKind = 4;
            }
            break;
        case MODE_MISSION_RUN:
            break;
        default:
            gRaceMultiConfig->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
            break;
    }
}

void ResetTimeAttackNextEntries(void) {
    u16 i;

    if (gRaceMultiConfig->mNextHeader.mMode != MODE_TIME_ATTACK) {
        return;
    }
    gRaceMultiConfig->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
    for (i = 1; i < 8; i++) {
        gRaceMultiConfig->mNextEntries[i].mCharacterIndex = i;
        gRaceMultiConfig->mNextEntries[i].mKartIndex = i;
        gRaceMultiConfig->mNextEntries[i].mPlayer.mKind = PLAYER_KIND_NONE;
        gRaceMultiConfig->mNextEntries[i].mPlayer.mIndex = i;
    }
}

// In battle there is one lap.
u16 rconf_getLapCount(void) {
    RaceSetup *raceSetup;
    u16 lapCount;

    lapCount = 1;
    raceSetup = gRaceMultiConfig;
    if (raceSetup->mMode != MODE_BATTLE) {
        if (raceSetup->mLapCount <= 0) {
            lapCount = gMapData->mSettings->mLapCountOrBattleSeconds;
        } else {
            lapCount = raceSetup->mLapCount;
        }
    }
    return lapCount;
}
