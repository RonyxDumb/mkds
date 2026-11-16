#include "Main/Unknown/code_020467d0.h"

#include "Main/System/Heap.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0205d0bc.h"
#include "Main/Unknown/code_0205dc54.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_020364e0.h"

void sm_gotoState(void *rawStateMachine, u16 state) {
    StateMachine *stateMachine;

    stateMachine = rawStateMachine;
    stateMachine->mStateFrames = 0;
    stateMachine->mNextStateRequested = 1;
    stateMachine->mState = state;
    stateMachine->mNextState = state;
}

void sm_execute(void *rawStateMachine) {
    StateMachine *stateMachine;
    StateCallbacks *callbacks;

    stateMachine = rawStateMachine;
    if (stateMachine->mNextStateRequested != 0) {
        stateMachine->mStateFrames = 0;
        stateMachine->mNextStateRequested = 0;
        stateMachine->mState = stateMachine->mNextState;
        stateMachine->mNextState = 0;
        callbacks = &stateMachine->mStateTable[stateMachine->mState];
        if (callbacks->mEnter != NULL) {
            callbacks->mEnter(stateMachine->mObject);
        }
    } else {
        callbacks = &stateMachine->mStateTable[stateMachine->mState];
    }
    if (callbacks->mUpdate != NULL) {
        callbacks->mUpdate(stateMachine->mObject);
    }
    stateMachine->mStateFrames++;
}

void menu2_create(void) {
    u8 *displaySettings;

    displaySettings = dc_createDisplayConfig(proc_getHeap(proc_getCurrent()), DebugMenuDisplayConfig);
    dc_setBg1Config(displaySettings + 0x28, 0, 0, 0, 0, 4, 0, 0);
    dc_setDisplayConfig(displaySettings);
}

void menu2_finish(void) {
    func_020446e0();
}

u32 menu2_vblank(u32 value) {
    return value;
}

u32 menu2_draw(u32 value) {
    return value;
}

s32 menu2_run(void *a) {
    SceneCallbacks callbacks = menu2_vtable;

    scene_runScene(a, &callbacks);
    return 0;
}

void rconf_init(void *heap) {
    gRaceMultiConfig = heap_alloc(heap, 0x400);
    gRaceMultiConfig->mCourseList = heap_alloc(heap, 0x21);
    CreateParticipantKartMap(heap);
    rres_init(heap);
}

void RefreshRaceSetupKartCounts(s32 entryCount) {
    u8 teamCounts[2] = {0};
    s32 i;
    u8 humanAndPeerCount;
    u8 kartCount;

    humanAndPeerCount = 0;
    kartCount = 0;
    for (i = 0; i < entryCount; i++) {
        if (gRaceMultiConfig->mCurrentEntries[i].mPlayer.mKind != PLAYER_KIND_NONE) {
            if (gRaceMultiConfig->mCurrentEntries[i].mPlayer.mKind == PLAYER_KIND_HUMAN ||
                gRaceMultiConfig->mCurrentEntries[i].mPlayer.mKind == PLAYER_KIND_PEER) {
                humanAndPeerCount++;
            }
            kartCount++;
            if (gRaceMultiConfig->mUseTeams != 0) {
                teamCounts[gRaceMultiConfig->mCurrentEntries[i].mPlayer.mTeamIndex]++;
            }
        }
    }
    gRaceMultiConfig->mKartCount = kartCount;
    gRaceMultiConfig->mHumanAndPeerKartCount = humanAndPeerCount;
    for (i = 0; i < 2; i++) {
        gRaceMultiConfig->mTeamKartCounts[i] = teamCounts[i];
    }
}

void rconf_setDriverConfigNext(int entryIndex, u32 characterIndex, u32 kartIndex, int playerKind, u32 teamIndex, int f) {
    gRaceMultiConfig->mNextEntries[entryIndex].mCharacterIndex = characterIndex;
    gRaceMultiConfig->mNextEntries[entryIndex].mPlayer.mKind = playerKind;
    gRaceMultiConfig->mNextEntries[entryIndex].mPlayer.mIndex = entryIndex;
    gRaceMultiConfig->mNextEntries[entryIndex].mKartIndex = kartIndex;
    gRaceMultiConfig->mNextEntries[entryIndex].mPlayer.mTeamIndex = teamIndex;
    gRaceMultiConfig->mNextEntries[entryIndex].mPlayer.field8 = f;
    gRaceMultiConfig->mNextEntries[entryIndex].mPlayer.mGhostRecordIndex = playerKind == PLAYER_KIND_GHOST ? 0 : 3;
    gRaceMultiConfig->mNextEntries[entryIndex].mPlayer.field14 = 0;
    if (f != 3) {
        gRaceMultiConfig->mNextEntries[entryIndex].mPlayer.field14 |= 1;
    }
}

s32 rconf_getCourseNumber(s32 courseId) {
    s32 i;
    s32 j;
    s8 courseIndex;

    courseIndex = -1;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            if (courseId == sCupDefs[i][j]) {
                courseIndex = j + i * 4;
                break;
            }
        }
    }
    return courseIndex;
}

u32 GetCupCourseIdAtIndex(s32 courseIndex) {
    return sCupDefs[(u32) courseIndex / 4][courseIndex % 4];
}

s32 FindCupIndexOfCourse(s32 courseId) {
    s32 cupIndex;
    s32 i;
    s32 j;

    cupIndex = 9;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            if (courseId == sCupDefs[i][j]) {
                cupIndex = i;
            }
        }
    }
    return cupIndex;
}
