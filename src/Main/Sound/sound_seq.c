#include "Main/Sound/sound_seq.h"
#include "Main/Sound/sound_row.h"
#include "Main/Menu/data_02153000.h"
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Race/race_entries.h"
#include "Main/Scene/scene_connection.h"

#include "player.h"
#include "Main/Sound/sound_sources.h"
#include "Main/Sound/scene_players_release.h"
#include "Main/Sound/sound_system.h"
#include "Main/Sound/sound_mode.h"
#include "Main/Sound/sound_mode_restore.h"
#include "Main/Sound/snd_arc_setup.h"
#include "Main/Course/course_sound_slot.h"
#include "Main/Sound/seq_queue.h"
#include "Main/Sound/race_end_seq.h"
#include "Main/Sound/seq_row.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/data_0217c000.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Menu/data_0217d000.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Sound/sound_set_load.h"
#include "code_0212df7c.h"
#include "Main/Item/data_0215a000.h"
#include "Main/Menu/data_0217d068.h"
#include "Main/Sound/data_0210b000.h"
#include "Main/Sound/data_0210e000.h"
#include "code_0212ba34.h"
#include "code_02147cd8.h"
#include "Main/Scene/run_scenes.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Sound/sound_falloffs_init.h"
#include "Main/Sound/sound_return_argument.h"
#include "Main/Sound/kart_surface_sound.h"
#include "Main/Sound/map_object_sound_counter.h"
#include "Main/Sound/end_race_fade_steps.h"
#include "Main/Sound/sound_file_id_list.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "Main/Save/buddy_record_time.h"
#include "g2d_CellTransferManager.h"
#include "Main/Sound/kart_sound.h"
#include "Main/Menu/select_race_rule_state.h"

const Vec3 gVec3Ones = {0x1000, 0x1000, 0x1000};
const Vec3 data_0215a6cc = {0, 0, 0};

// Keeps seq 0 looping on the in-memory archive until StopSeqZeroLoop; UpdateSounds restarts it.
void StartSeqZeroLoop(void) {
    NNS_SndArcSetCurrent(&gOnMemorySndArc);
    NNS_SndPlayerStopSeq(&gSeqZeroLoopHandle, 1);
    NNS_SndPlayerStopSeq(&gMatchingEntrySeqHandle, 1);
    gSeqZeroLoopOn = 1;
    NNS_SndArcSetCurrent(&gFileSndArc);
}

void StopSeqZeroLoop(void) {
    NNS_SndArcSetCurrent(&gOnMemorySndArc);
    NNS_SndPlayerStopSeq(&gSeqZeroLoopHandle, 0xd);
    gSeqZeroLoopOn = 0;
    NNS_SndPlayerStopSeq(&gMatchingEntrySeqHandle, 1);
    NNS_SndArcSetCurrent(&gFileSndArc);
}

void BootInfoStartMessageScreenSeq(void) {
    NNS_SndPlayerStopSeq(&gSeqZeroLoopHandle, 1);
    gSeqZeroLoopOn = 0;
    NNS_SndPlayerStopSeq(&gMatchingEntrySeqHandle, 1);
    NNS_SndArcSetCurrent(&gOnMemorySndArc);
    NNS_SndArcSetCurrent(&gOnMemorySndArc);
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 1);
    NNS_SndArcSetCurrent(&gFileSndArc);
    NNS_SndArcSetCurrent(&gFileSndArc);
}

void StartMessageScreenSeq(void) {
    NNS_SndPlayerStopSeq(&gSeqZeroLoopHandle, 1);
    gSeqZeroLoopOn = 0;
    NNS_SndPlayerStopSeq(&gMatchingEntrySeqHandle, 1);
    NNS_SndArcSetCurrent(&gOnMemorySndArc);
    NNS_SndArcSetCurrent(&gOnMemorySndArc);
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 1);
    NNS_SndArcSetCurrent(&gFileSndArc);
    NNS_SndArcSetCurrent(&gFileSndArc);
}

void StartTimeAttackGhostSendSeq(void) {
    NNS_SndPlayerStopSeq(&gSeqZeroLoopHandle, 1);
    NNS_SndArcSetCurrent(&gOnMemorySndArc);
    if (gSeqZeroLoopHandle != NULL) {
        NNS_SndPlayerStopSeq(&gSeqZeroLoopHandle, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&gSeqZeroLoopHandle, 0, 8);
    NNS_SndArcSetCurrent(&gFileSndArc);
}

void StopTimeAttackGhostSendSeq(void) {
    NNS_SndPlayerStopSeq(&gSeqZeroLoopHandle, 1);
}

void StartWiFiSessionLoginSeq(void) {
    NNS_SndPlayerStopSeq(&gSeqZeroLoopHandle, 1);
    if (gSeqZeroLoopHandle != NULL) {
        NNS_SndPlayerStopSeq(&gSeqZeroLoopHandle, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&gSeqZeroLoopHandle, 0, 0x202);
}

void StartWiFiSessionLoginResult1Seq(void) {
    NNS_SndPlayerStopSeq(&gSeqZeroLoopHandle, 1);
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x203);
}

void StartWiFiSessionMatchingSeq(void) {
    NNS_SndPlayerStopSeq(&gSeqZeroLoopHandle, 1);
    if (gSeqZeroLoopHandle != NULL) {
        NNS_SndPlayerStopSeq(&gSeqZeroLoopHandle, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&gSeqZeroLoopHandle, 0, 0x204);
}

void StartWiFiMatchingEntryShowSeq(void) {
    NNS_SndPlayerStopSeq(&gMatchingEntrySeqHandle, 1);
    if (gMatchingEntrySeqHandle != NULL) {
        NNS_SndPlayerStopSeq(&gMatchingEntrySeqHandle, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&gMatchingEntrySeqHandle, 0, 0x205);
}

void StartWiFiMatchingEntryHideSeq(void) {
    NNS_SndPlayerStopSeq(&gMatchingEntrySeqHandle, 1);
    if (gMatchingEntrySeqHandle != NULL) {
        NNS_SndPlayerStopSeq(&gMatchingEntrySeqHandle, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&gMatchingEntrySeqHandle, 0, 0x206);
}

void StartPlayerEntryListSetupSeq(void) {
    NNS_SndPlayerStopSeq(&gSeqZeroLoopHandle, 1);
    NNS_SndPlayerStopSeq(&gMatchingEntrySeqHandle, 1);
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x207);
}

void StartWiFiLoginErrorSeq(void) {
    NNS_SndPlayerStopSeq(&gSeqZeroLoopHandle, 1);
    NNS_SndPlayerStopSeq(&gMatchingEntrySeqHandle, 1);
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, (0x0000020au));
}

void StartSelectReturnState1Seq(void) {
    NNS_SndPlayerStopSeq(&gSeqZeroLoopHandle, 1);
    NNS_SndPlayerStopSeq(&gMatchingEntrySeqHandle, 1);
    NNS_SndPlayerStopSeq(&gSeqZeroLoopHandle, 1);
    NNS_SndPlayerStopSeq(&gMatchingEntrySeqHandle, 1);
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x20a);
}

void StopBothSeqHandles(void) {
    NNS_SndPlayerStopSeq(&gSeqZeroLoopHandle, 1);
    NNS_SndPlayerStopSeq(&gMatchingEntrySeqHandle, 1);
}

LoadedSoundSet *GetLoadedSoundSet(void) {
    return &data_0217c7b4;
}

BOOL LoadSndBanksAndWaveArcs(s32 bankMask) {
    s32 bankIndex;
    NNSSndHeap *savedHeap;

    savedHeap = gCurrentSndHeap;
    gCurrentSndHeap = gSndHeap;
    if (data_0216c7d4 != 2) {
        NNS_SndArcLoadBank(1, gSndHeap);
    }
    for (bankIndex = 0; bankIndex < 0xd; bankIndex++) {
        if (((bankMask >> bankIndex) & 1) != 0) {
            if (NNS_SndArcLoadBankEx(data_0216c7f8[bankIndex], 2, gSndHeap) == 0) {
                gCurrentSndHeap = savedHeap;
                return FALSE;
            }
            if (NNS_SndArcLoadWaveArc(data_0216c82c[bankIndex], gSndHeap) == 0) {
                gCurrentSndHeap = savedHeap;
                return FALSE;
            }
        }
    }
    gCurrentSndHeap = savedHeap;
    return TRUE;
}

BOOL LoadSndBanksAndWaveArcsIfChanged(s32 bankMask) {
    if (bankMask == 0) {
        return TRUE;
    }
    if (gLoadedSoundBanks.mLoadMarker != 0xff00 && gLoadedSoundBanks.mBankMask == bankMask) {
        return TRUE;
    }
    NNS_SndHeapClear(gSndHeap);
    gLoadedSoundBanks.mLoadMarker = 0xff00;
    gLoadedSoundBanks.mBankMask = 0;
    gLoadedSoundBanks.mBankMask = bankMask;
    gLoadedSoundBanks.mLoadMarker = 0xfe00;
    if (LoadSndBanksAndWaveArcs(bankMask) == FALSE) {
        return FALSE;
    }
    return TRUE;
}

// Total size of the buffer CreateSndHeaps carves into its three parts.
int GetSndHeapsBufferSize(int heapSizeKind) {
    return (heapSizeKind == 0 ? 0xc8000 : 0xaf000) - (heapSizeKind == 2 ? 0xaf000 : 0xc400);
}

int GetSndInitBufferSize(int heapSizeKind) {
    return heapSizeKind == 2 ? 0xaf000 : 0xc400;
}

void ReleaseSndHeaps(void) {
    NNS_SndHeapDestroy(gCurrentSndHeap);
    gCurrentSndHeap = NULL;
    NNS_SndHeapDestroy(gSndHeap);
    gSndHeap = NULL;
    NNS_SndHeapDestroy(data_0217c790);
    data_0217c790 = NULL;
    ClearSndFileAddresses(GetSndDataFileIdList());
    ClearSndFileIdList(GetSndDataFileIdList());
    ((u32 *) &gLoadedSoundBanks)[0] = data_0215a6f4[0];
    ((u32 *) &gLoadedSoundBanks)[1] = data_0215a6f4[1];
    ResetLoadedSoundSet(&data_0217c7b4);
}

void CreateSndHeaps(u32 heapSizeKind, u32 buffer) {
    u32 soundHeapSize;
    u32 seqRowHeapSize;
    u32 soundHeapSizeCopy;
    u32 seqRowHeapSizeCopy;
    u32 currentHeapSize;
    u32 heapCursor;

    data_0216c7d4 = heapSizeKind;
    switch (heapSizeKind) {
        case 0:
            soundHeapSize = 0x36f3c;
            break;
        case 1:
            soundHeapSize = 0x26a08;
            break;
        case 2:
            soundHeapSize = 0x25a5c;
            break;
    }
    ((u32 *) &gLoadedSoundBanks)[0] = data_0215a6ec[0];
    ((u32 *) &gLoadedSoundBanks)[1] = data_0215a6ec[1];
    ResetLoadedSoundSet(&data_0217c7b4);
    gSndHeap = NNS_SndHeapCreate((void *) buffer, soundHeapSize);
    seqRowHeapSize = 0;
    gCurrentSndHeap = NULL;
    buffer = buffer + soundHeapSize;
    switch (heapSizeKind) {
        case 0:
            seqRowHeapSize = 0x6580;
            break;
        case 1:
            seqRowHeapSize = 0x35a0;
            break;
        case 2:
            seqRowHeapSize = 0x35a0;
            break;
    }
    CreateSeqRowHeap((void *) buffer, seqRowHeapSize);
    data_0217c790 = (NNSSndHeap *) buffer;
    heapCursor = buffer + seqRowHeapSize;
    currentHeapSize = (heapSizeKind == 0 ? 0xc8000 : 0xaf000) - (heapSizeKind == 2 ? 0xaf000 : 0xc400);
    switch (heapSizeKind) {
        case 0:
            soundHeapSizeCopy = 0x36f3c;
            break;
        case 1:
            soundHeapSizeCopy = 0x26a08;
            break;
        case 2:
            soundHeapSizeCopy = 0x25a5c;
            break;
    }
    seqRowHeapSizeCopy = 0;
    switch (heapSizeKind) {
        case 0:
            seqRowHeapSizeCopy = 0x6580;
            break;
        case 1:
            seqRowHeapSizeCopy = 0x35a0;
            break;
        case 2:
            seqRowHeapSizeCopy = 0x35a0;
            break;
    }
    currentHeapSize = currentHeapSize - soundHeapSizeCopy - seqRowHeapSizeCopy;
    gCurrentSndHeap = NNS_SndHeapCreate((void *) heapCursor, currentHeapSize);
    heapCursor = 0;
    if (heapSizeKind == 1) {
        heapCursor = 1;
    }
    LoadInitialSndGroup(heapCursor);
}

void InitSound(void *buffer, u32 bufferSize, u32 useFileArchive) {
    u32 soundHeapSize;
    u32 seqRowHeapSize;
    SndHeapSizeKind heapSizeKind;
    s32 slotIndex;

    gSeqZeroLoopOn = 0;
    if (useFileArchive == 0) {
        heapSizeKind = E2;
        switch (heapSizeKind) {
            case E0:
                soundHeapSize = 0x36f3c;
                break;
            case E1:
                soundHeapSize = 0x26a08;
                break;
            case E2:
                soundHeapSize = 0x25a5c;
                break;
        }
        seqRowHeapSize = 0;
        switch (heapSizeKind) {
            case E0:
                seqRowHeapSize = 0x6580;
                break;
            case E1:
                seqRowHeapSize = 0x35a0;
                break;
            case E2:
                seqRowHeapSize = 0x35a0;
                break;
        }
        bufferSize = bufferSize - soundHeapSize;
        data_0216c7d4 = 2;
        bufferSize = bufferSize - seqRowHeapSize;
    }
    InitSoundSystem(buffer, bufferSize, useFileArchive != 0 ? gSoundDataSdatPath : 0);
    InitSoundRequestQueues();
    NNS_SndArcInitOnMemory(&gOnMemorySndArc, gOnMemorySdat);
    NNS_SndArcSetCurrent(&gFileSndArc);
    if (useFileArchive != 0) {
        LoadInitialSndArcs();
    } else {
        ((u32 *) &gLoadedSoundBanks)[0] = data_0215a6e4[0];
        ((u32 *) &gLoadedSoundBanks)[1] = data_0215a6e4[1];
        gSndHeap = NNS_SndHeapCreate((buffer + bufferSize), 0x25a5c);
        CreateSeqRowHeap((buffer + bufferSize + 0x25a5c), 0x35a0);
    }
    gSceneSeqVolume = 0x69;
    StartSoundOutputEffect(1);
    InitKartSoundPitchFactors();
    ClearSndFileIdList(GetSndDataFileIdList());
    ClearSndFileIdList(GetSoundSetFileIdList());
    for (slotIndex = 0; slotIndex < 12; slotIndex++) {
        NNS_SndHandleInit(&gSndHandleSlots[slotIndex]);
    }
    InitSoundHandlePool(&gSoundHandlePool, data_0217c7d8, 3, 8);
    NNS_SndHandleInit(&gChoisesSSeqHandle);
    NNS_SndHandleInit(&gSeqZeroLoopHandle);
    NNS_SndHandleInit(&gMatchingEntrySeqHandle);
    NNS_SndSetMasterVolume(0x7f);
    NNS_SndSetMonoFlag(0);
    SetSoundFadeSteps(0x1e);
    gPlayerVolumeFade.mVolumePerFrameBeforeRaceStart = FX_Div(0x7f000, 0x46000);
    gPlayerVolumeFade.mVolumePerFrameAfterRaceStart = FX_Div(0x7f000, 0x3c000);
    gPlayerVolumeFade.mPlayerMaskBeforeRaceStart = 0xff;
    gPlayerVolumeFade.mPlayerMaskAfterRaceStart = 0x7f;
    gPlayerVolumeFade.mVolumePerFrame = gPlayerVolumeFade.mVolumePerFrameBeforeRaceStart;
    gPlayerVolumeFade.mVolume = 0;
    InitSoundFalloffsAndPlayingSounds();
    gRaceSoundKind = 0;
    InitSoundPitchSwing();
}

// Per-frame sound step; runs once per iteration of every scene frame loop.
void UpdateSounds(void) {
    s32 queueIndex;
    BOOL seqZeroPlaying;
    NNSSndSeqPlayer *seqPlayer;

    if (gScenePlayers.mProgress != 0) {
        UpdateSceneSoundState();
    }
    ResetThunderShrinkSoundCounter();
    ResetMapObjectSoundCounter();
    for (queueIndex = 0; queueIndex < 7; queueIndex++) {
        RunSoundRequests(OFFSET_PTR(SoundRequestQueue, gSoundRequestQueues, queueIndex * sizeof(SoundRequestQueue)));
    }
    IncrementSoundHandleAges(&gSoundHandlePool);
    UpdateSoundSources();
    if (gSeqZeroLoopOn == 1) {
        seqPlayer = gSeqZeroLoopHandle;
        seqZeroPlaying = seqPlayer != NULL && seqPlayer->mSeqArcIndex == 0 && seqPlayer->mSeqNo == 0;
        if (seqZeroPlaying == FALSE) {
            NNS_SndArcSetCurrent(&gOnMemorySndArc);
            if (gSeqZeroLoopHandle != NULL) {
                NNS_SndPlayerStopSeq(&gSeqZeroLoopHandle, 0);
            }
            NNS_SndArcPlayerStartSeqArc(&gSeqZeroLoopHandle, 0, 0);
            NNS_SndArcSetCurrent(&gFileSndArc);
        }
    }
    UpdateSndMain();
    gSoundStartedThisFrame = 0;
}

// Loads the sound data of the scene that is starting; the parameter is not used.
void InitSceneSounds(s32 unused) {
    s32 sceneSoundRowIndex;
    s32 currentSceneNumber;
    s32 value;
    BOOL isRaceScene;
    u32 raceKindMatches;
    NNSSndHeap *savedHeap;
    SoundRow buf;
    ScenePlayersSeqInfo scenePlayersSeqInfo;

    if (gBootInfo->mBootType == 2 && GetCurrentSceneNumber() == 6) {
        return;
    }
    ClearSurfaceSoundIds();
    currentSceneNumber = GetCurrentSceneNumber();
    value = 0x69;
    isRaceScene = FALSE;
    if (GetCurrentSceneNumber() == 2) {
        raceKindMatches = gRaceSetup->mRaceKind == RACE_KIND_NORMAL || gRaceSetup->mRaceKind == RACE_KIND_REPLAY;
        if (raceKindMatches != 0) {
            isRaceScene = TRUE;
        }
    }
    if (isRaceScene != FALSE) {
        switch (gRaceSetup->mCourseId) {
            case COURSE_ID_BEACH:
                value = value + 0x17;
                break;
            case COURSE_ID_OLD_MOMO_64:
                value = value + 5;
                break;
            case COURSE_ID_OLD_MARIO_SFC:
                value = value + 1;
                break;
            case COURSE_ID_OLD_PEACH_AGB:
            case COURSE_ID_OLD_LUIGI_AGB:
                value = value + 0xd;
                break;
            case COURSE_ID_OLD_DONUT_SFC:
                value = value + 5;
                break;
        }
    }
    if (value > 0x7f) {
        value = 0x7f;
    }
    gSceneSeqVolume = value;
    sceneSoundRowIndex = GetSceneSoundRowIndex(currentSceneNumber, &buf);
    if (gCurrentSoundSetPlayer == NULL) {
        ResetSeqVariableReadings();
        SetSeqVariableEnabled(0, 0);
        SetSeqVariableEnabled(1, 0);
    }
    ResetEmblemSoundCounters();
    ResetSeqQueue();
    InitKingTeresaSoundState(0);
    SetSoundFadeSteps(GetSceneFadeToFadedFrameCount());
    InitKartNearSoundFactors();
    InitVolumeFade();
    switch (currentSceneNumber) {
        case 2:
            value = gRaceSetup->mCourseId;
            switch (value) {
                case COURSE_ID_TOWN:
                    SetSeqVariableEnabled(0, 1);
                    SetSeqVariableEnabled(1, 1);
                    break;
                case COURSE_ID_MANSION:
                    CourseEntrySetSurfaceSoundIds(0x15, gCourseSurfaceSoundEntries[0].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[0]);
                    CourseEntrySetSurfaceSoundIds(0x8, gCourseSurfaceSoundEntries[0].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[0]);
                    CourseEntrySetSurfaceSoundIds(0x9, gCourseSurfaceSoundEntries[0].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[0]);
                    CourseEntrySetSurfaceSoundIds(0xd, gCourseSurfaceSoundEntries[0].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[0]);
                    CourseEntrySetSurfaceSoundIds(0xe, gCourseSurfaceSoundEntries[0].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[0]);
                    CourseEntrySetSurfaceSoundIds(0x10, gCourseSurfaceSoundEntries[0].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[0]);
                    break;
                case COURSE_ID_PINBALL:
                    CourseEntrySetSurfaceSoundIds(0x15, gCourseSurfaceSoundEntries[1].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[1]);
                    CourseEntrySetSurfaceSoundIds(0x8, gCourseSurfaceSoundEntries[1].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[1]);
                    CourseEntrySetSurfaceSoundIds(0x9, gCourseSurfaceSoundEntries[1].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[1]);
                    CourseEntrySetSurfaceSoundIds(0xd, gCourseSurfaceSoundEntries[1].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[1]);
                    CourseEntrySetSurfaceSoundIds(0xe, gCourseSurfaceSoundEntries[1].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[1]);
                    CourseEntrySetSurfaceSoundIds(0x10, gCourseSurfaceSoundEntries[1].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[1]);
                    break;
                case COURSE_ID_RIDGE:
                    CourseEntrySetSurfaceSoundIds(0x15, gCourseSurfaceSoundEntries[2].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[2]);
                    CourseEntrySetSurfaceSoundIds(0x8, gCourseSurfaceSoundEntries[2].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[2]);
                    CourseEntrySetSurfaceSoundIds(0x9, gCourseSurfaceSoundEntries[2].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[2]);
                    CourseEntrySetSurfaceSoundIds(0xd, gCourseSurfaceSoundEntries[2].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[2]);
                    CourseEntrySetSurfaceSoundIds(0xe, gCourseSurfaceSoundEntries[2].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[2]);
                    CourseEntrySetSurfaceSoundIds(0x10, gCourseSurfaceSoundEntries[2].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[2]);
                    break;
                case COURSE_ID_SNOW:
                    CourseEntrySetSurfaceSoundIds(0x15, gCourseSurfaceSoundEntries[3].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[3]);
                    CourseEntrySetSurfaceSoundIds(0x8, gCourseSurfaceSoundEntries[3].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[3]);
                    CourseEntrySetSurfaceSoundIds(0x9, gCourseSurfaceSoundEntries[3].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[3]);
                    CourseEntrySetSurfaceSoundIds(0xd, gCourseSurfaceSoundEntries[3].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[3]);
                    CourseEntrySetSurfaceSoundIds(0xe, gCourseSurfaceSoundEntries[3].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[3]);
                    CourseEntrySetSurfaceSoundIds(0x10, gCourseSurfaceSoundEntries[3].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[3]);
                    break;
                case COURSE_ID_CLOCK:
                    CourseEntrySetSurfaceSoundIds(0x15, gCourseSurfaceSoundEntries[4].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[4]);
                    CourseEntrySetSurfaceSoundIds(0x8, gCourseSurfaceSoundEntries[4].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[4]);
                    CourseEntrySetSurfaceSoundIds(0x9, gCourseSurfaceSoundEntries[4].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[4]);
                    CourseEntrySetSurfaceSoundIds(0xd, gCourseSurfaceSoundEntries[4].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[4]);
                    CourseEntrySetSurfaceSoundIds(0xe, gCourseSurfaceSoundEntries[4].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[4]);
                    CourseEntrySetSurfaceSoundIds(0x10, gCourseSurfaceSoundEntries[4].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[4]);
                    break;
                case COURSE_ID_AIRSHIP:
                    CourseEntrySetSurfaceSoundIds(0x15, gCourseSurfaceSoundEntries[5].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[5]);
                    CourseEntrySetSurfaceSoundIds(0x8, gCourseSurfaceSoundEntries[5].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[5]);
                    CourseEntrySetSurfaceSoundIds(0x9, gCourseSurfaceSoundEntries[5].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[5]);
                    CourseEntrySetSurfaceSoundIds(0xd, gCourseSurfaceSoundEntries[5].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[5]);
                    CourseEntrySetSurfaceSoundIds(0xe, gCourseSurfaceSoundEntries[5].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[5]);
                    CourseEntrySetSurfaceSoundIds(0x10, gCourseSurfaceSoundEntries[5].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[5]);
                    break;
                case COURSE_ID_STADIUM:
                    CourseEntrySetSurfaceSoundIds(0x15, gCourseSurfaceSoundEntries[6].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[6]);
                    CourseEntrySetSurfaceSoundIds(0x8, gCourseSurfaceSoundEntries[6].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[6]);
                    CourseEntrySetSurfaceSoundIds(0x9, gCourseSurfaceSoundEntries[6].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[6]);
                    CourseEntrySetSurfaceSoundIds(0xd, gCourseSurfaceSoundEntries[6].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[6]);
                    CourseEntrySetSurfaceSoundIds(0xe, gCourseSurfaceSoundEntries[6].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[6]);
                    CourseEntrySetSurfaceSoundIds(0x10, gCourseSurfaceSoundEntries[6].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[6]);
                    break;
                case COURSE_ID_GARDEN:
                    CourseEntrySetSurfaceSoundIds(0x15, gCourseSurfaceSoundEntries[7].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[7]);
                    CourseEntrySetSurfaceSoundIds(0x8, gCourseSurfaceSoundEntries[7].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[7]);
                    CourseEntrySetSurfaceSoundIds(0x9, gCourseSurfaceSoundEntries[7].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[7]);
                    CourseEntrySetSurfaceSoundIds(0xd, gCourseSurfaceSoundEntries[7].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[7]);
                    CourseEntrySetSurfaceSoundIds(0xe, gCourseSurfaceSoundEntries[7].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[7]);
                    CourseEntrySetSurfaceSoundIds(0x10, gCourseSurfaceSoundEntries[7].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[7]);
                    break;
                case COURSE_ID_KOOPA:
                    CourseEntrySetSurfaceSoundIds(0x15, gCourseSurfaceSoundEntries[8].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[8]);
                    CourseEntrySetSurfaceSoundIds(0x8, gCourseSurfaceSoundEntries[8].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[8]);
                    CourseEntrySetSurfaceSoundIds(0x9, gCourseSurfaceSoundEntries[8].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[8]);
                    CourseEntrySetSurfaceSoundIds(0xd, gCourseSurfaceSoundEntries[8].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[8]);
                    CourseEntrySetSurfaceSoundIds(0xe, gCourseSurfaceSoundEntries[8].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[8]);
                    CourseEntrySetSurfaceSoundIds(0x10, gCourseSurfaceSoundEntries[8].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[8]);
                    break;
                case COURSE_ID_OLD_BABY_GC:
                    CourseEntrySetSurfaceSoundIds(0x15, gCourseSurfaceSoundEntries[9].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[9]);
                    CourseEntrySetSurfaceSoundIds(0x8, gCourseSurfaceSoundEntries[9].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[9]);
                    CourseEntrySetSurfaceSoundIds(0x9, gCourseSurfaceSoundEntries[9].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[9]);
                    CourseEntrySetSurfaceSoundIds(0xd, gCourseSurfaceSoundEntries[9].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[9]);
                    CourseEntrySetSurfaceSoundIds(0xe, gCourseSurfaceSoundEntries[9].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[9]);
                    CourseEntrySetSurfaceSoundIds(0x10, gCourseSurfaceSoundEntries[9].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[9]);
                    break;
                case COURSE_ID_OLD_KINOKO_GC:
                    CourseEntrySetSurfaceSoundIds(0x15, gCourseSurfaceSoundEntries[10].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[10]);
                    CourseEntrySetSurfaceSoundIds(0x8, gCourseSurfaceSoundEntries[10].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[10]);
                    CourseEntrySetSurfaceSoundIds(0x9, gCourseSurfaceSoundEntries[10].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[10]);
                    CourseEntrySetSurfaceSoundIds(0xd, gCourseSurfaceSoundEntries[10].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[10]);
                    CourseEntrySetSurfaceSoundIds(0xe, gCourseSurfaceSoundEntries[10].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[10]);
                    CourseEntrySetSurfaceSoundIds(0x10, gCourseSurfaceSoundEntries[10].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[10]);
                    break;
                case COURSE_ID_OLD_HYUDORO_64:
                    CourseEntrySetSurfaceSoundIds(0x15, gCourseSurfaceSoundEntries[11].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[11]);
                    CourseEntrySetSurfaceSoundIds(0x8, gCourseSurfaceSoundEntries[11].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[11]);
                    CourseEntrySetSurfaceSoundIds(0x9, gCourseSurfaceSoundEntries[11].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[11]);
                    CourseEntrySetSurfaceSoundIds(0xd, gCourseSurfaceSoundEntries[11].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[11]);
                    CourseEntrySetSurfaceSoundIds(0xe, gCourseSurfaceSoundEntries[11].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[11]);
                    CourseEntrySetSurfaceSoundIds(0x10, gCourseSurfaceSoundEntries[11].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[11]);
                    break;
                case COURSE_ID_MINI_STAGE4:
                    CourseEntrySetSurfaceSoundIds(0x15, gCourseSurfaceSoundEntries[12].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[12]);
                    CourseEntrySetSurfaceSoundIds(0x8, gCourseSurfaceSoundEntries[12].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[12]);
                    CourseEntrySetSurfaceSoundIds(0x9, gCourseSurfaceSoundEntries[12].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[12]);
                    CourseEntrySetSurfaceSoundIds(0xd, gCourseSurfaceSoundEntries[12].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[12]);
                    CourseEntrySetSurfaceSoundIds(0xe, gCourseSurfaceSoundEntries[12].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[12]);
                    CourseEntrySetSurfaceSoundIds(0x10, gCourseSurfaceSoundEntries[12].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[12]);
                    break;
                case COURSE_ID_OLD_LUIGI_AGB:
                    SetSurfaceSoundIds(data_0216c7e0.mRowIndex, data_0216c7e0.mColumnIndex, &data_0216c7e0);
                    break;
                case COURSE_ID_MR_STAGE3:
                    CourseEntrySetSurfaceSoundIds(0x15, gCourseSurfaceSoundEntries[13].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[13]);
                    CourseEntrySetSurfaceSoundIds(0x8, gCourseSurfaceSoundEntries[13].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[13]);
                    CourseEntrySetSurfaceSoundIds(0x9, gCourseSurfaceSoundEntries[13].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[13]);
                    CourseEntrySetSurfaceSoundIds(0xd, gCourseSurfaceSoundEntries[13].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[13]);
                    CourseEntrySetSurfaceSoundIds(0xe, gCourseSurfaceSoundEntries[13].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[13]);
                    CourseEntrySetSurfaceSoundIds(0x10, gCourseSurfaceSoundEntries[13].mSurfaceVariant,
                                                  &gCourseSurfaceSoundEntries[13]);
                    if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
                        InitKingTeresaSoundState(1);
                    }
                    break;
            }
            SelectCourseSoundTable(value);
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                MissionSettings *setupView = &gRaceSetup->mUnk_28_view;
                switch (gRaceSetup->mMissionKind) {
                    case 1:
                        gMissionRunCountSeqNo[0] = 0x1d7;
                        gMissionRunLimitSeqNo[0] = 0x1d7;
                        break;
                    case 7:
                        gMissionRunCountSeqNo[0] = 0x1e0;
                        gMissionRunLimitSeqNo[0] = 0x1e1;
                        switch (setupView->mMissionTableValue) {
                            case 9:
                            case 0xa:
                                gMissionRunLimitSeqNo[0] = 0xff;
                                break;
                        }
                        break;
                    case 0:
                        gMissionRunCountSeqNo[0] = 0x1db;
                        gMissionRunLimitSeqNo[0] = 0x1dc;
                        break;
                    case 2:
                    case 6:
                        gMissionRunCountSeqNo[0] = 0xff;
                        gMissionRunLimitSeqNo[0] = 0xff;
                        break;
                    case 4:
                        gMissionRunCountSeqNo[0] = 0x1dd;
                        gMissionRunLimitSeqNo[0] = 0x1de;
                        break;
                    case 3:
                        gMissionRunCountSeqNo[0] = 0x1dd;
                        gMissionRunLimitSeqNo[0] = 0x1de;
                        break;
                    case 8:
                    case 9:
                    case 10:
                        break;
                }
            }
            { break; }
        case 1:
            if (gBootInfo->mBootType != 2) {
                savedHeap = gCurrentSndHeap;
                if (gLoadedSoundBanks.mLoadMarker == 0xff00 || gLoadedSoundBanks.mBankMask != 0xffff) {
                    NNS_SndHeapClear(gSndHeap);
                    gLoadedSoundBanks.mLoadMarker = 0xff00;
                    gLoadedSoundBanks.mBankMask = 0;
                    gCurrentSndHeap = gSndHeap;
                    if (NNS_SndArcLoadBank(0x2c, gSndHeap) != 0) {
                        if (NNS_SndArcLoadSeqArc(3, gCurrentSndHeap) != 0) {
                            gCurrentSndHeap = savedHeap;
                            gLoadedSoundBanks.mBankMask = 0xffff;
                            gLoadedSoundBanks.mLoadMarker = 0xfe00;
                        }
                    }
                }
            }
            { break; }
        case 0xc:
            savedHeap = gCurrentSndHeap;
            if (gLoadedSoundBanks.mLoadMarker == 0xff00 || gLoadedSoundBanks.mBankMask != 0xffff) {
                NNS_SndHeapClear(gSndHeap);
                gLoadedSoundBanks.mLoadMarker = 0xff00;
                gLoadedSoundBanks.mBankMask = 0;
                gCurrentSndHeap = gSndHeap;
                if (NNS_SndArcLoadBank(0x2c, gSndHeap) != 0) {
                    if (NNS_SndArcLoadSeqArc(3, gCurrentSndHeap) != 0) {
                        gCurrentSndHeap = savedHeap;
                        gLoadedSoundBanks.mBankMask = 0xffff;
                        gLoadedSoundBanks.mLoadMarker = 0xfe00;
                    }
                }
            }
            { break; }
        case 0:
            break;
    }
    scenePlayersSeqInfo.mUnk_00 = 0xff;
    scenePlayersSeqInfo.mSeqStartProgress = buf.mUnk_00[0];
    scenePlayersSeqInfo.mSeqId = buf.mUnk_00[1];
    InitVolumeFade();
    InitSceneSoundState(sceneSoundRowIndex & 0xff, scenePlayersSeqInfo, &gSceneSoundState);
    InitSoundFalloffsAndPlayingSounds();
    InitSceneSoundsNop();
    InitKartSoundQueue();
    ResetSoundRequestQueues();
    ResetSeqPlayerControl();
    if (gBootInfo->mBootType != 2) {
        LoadSceneSoundSet(buf, 0);
    }
    if (currentSceneNumber != 1) {
        return;
    }
    if (gBootInfo->mBootType != 2) {
        NNS_SndArcLoadBank(2, gCurrentSndHeap);
    }
    if (gBootInfo->mBootType == 2) {
        return;
    }
    data_0217c798[0] = NNS_SndHeapSaveState(gCurrentSndHeap);
    if (GetCurrentSceneNumber() != 1) {
        return;
    }
    if (gMenuShared->mMenuEntryKind == 3) {
        gScenePlayers.mSeqStartProgress = 0xff;
    }
}

void InitSceneSoundState(u32 sceneSoundRowIndex, ScenePlayersSeqInfo seqInfo, SceneSoundState *sceneSoundState) {
    sceneSoundState->mLapsDone = 0;
    NNS_SndHandleInit(&sceneSoundState->mKartStarSeq);
    sceneSoundState->mLastLapSeqState = 0;
    sceneSoundState->mOnLastLap = 0;
    sceneSoundState->mKartStarSeqOn = 0;
    sceneSoundState->mRaceFrames = 0;
    sceneSoundState->mSceneFrames = 0;
    sceneSoundState->mRaceState = 0;
    sceneSoundState->mRankIndex = 0xff;
    sceneSoundState->mRankIndexAtSeq = 0xff;
    sceneSoundState->mRankSeqFrames = -1;
    sceneSoundState->mVolumesLowered = 0;
    InitScenePlayers(&gScenePlayers, sceneSoundState, sceneSoundRowIndex, seqInfo);
    gSoundModeHolder.mKartStarSeqPlayer = &gSceneSoundState.mKartStarSeq;
    SetSoundMode(&gSoundModeHolder, SCENE_SOUND_MODE_STOPPED);
}

void StartSceneSounds(void) {
    s32 flag;
    u32 raceKindMatches;
    s32 value;
    s32 playerId;
    NNSSndArc *savedArc;
    NNSSndSeqPlayer **seqHandle;
    s32 playerId2;

    if (gBootInfo->mBootType == 2) {
        if (GetCurrentSceneNumber() == 6) {
            return;
        }
    }
    ResetRaceEndSeqState();
    gRaceSoundKind = 0;
    SoundReturnArgumentWrapper((u32) &gRaceSoundKind);
    flag = 0;
    gPlayerVolumeFade.mVolume = 0;
    gPlayerVolumeFade.mTargetVolumeBeforeRaceStart = 0x7f;
    gPlayerVolumeFade.mTargetVolumeAfterRaceStart = 0x7f;
    gPlayerVolumeFade.mRaceStarted = 0;
    if (GetCurrentSceneNumber() == 2) {
        raceKindMatches = gRaceSetup->mRaceKind == RACE_KIND_NORMAL || gRaceSetup->mRaceKind == RACE_KIND_REPLAY;
        if (raceKindMatches != 0) {
            flag = 1;
        }
    }
    if (flag != 0) {
        SetSoundMode(&gSoundModeHolder, SCENE_SOUND_MODE_PLAYING);
        gRaceSoundKind = 1;
        StartScenePlayersSeqNo(&gScenePlayers, GetSeqRowSceneSeq(), NULL);
        data_0217c7b0 = 0;
        value = 0xffff;
        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
            switch (gRaceSetup->mMissionTableValue) {
                case 9:
                    value = 0x20e;
                    break;
                case 0x11:
                    value = 0x235;
                    break;
                case 0x31:
                    value = 0x246;
                    break;
                case 0x33:
                    value = 0x228;
                    break;
            }
        }
        if (value == 0xffff) {
            switch (gRaceSetup->mCourseId) {
                case COURSE_ID_AIRSHIP:
                    value = 0x1d2;
                    break;
                case COURSE_ID_STADIUM:
                    value = 0x1bf;
                    break;
                case COURSE_ID_OLD_LUIGI_AGB:
                    value = 0x1d6;
                    break;
            }
        }
        if (value != 0xffff) {
            NNS_SndPlayerStopSeq(&gRaceSeqHandle, 0);
            seqHandle = &gRaceSeqHandle;
            if ((gRaceSoundKind & 1) != 0) {
                if (gSoundModeHolder.mSeqStartEnabled != 0) {
                    if (*seqHandle != NULL) {
                        NNS_SndPlayerStopSeq(seqHandle, 0);
                    }
                    if (*seqHandle != NULL) {
                        NNS_SndPlayerStopSeq(seqHandle, 0);
                    }
                    NNS_SndArcPlayerStartSeqArc(seqHandle, 0, value);
                }
            }
            data_0217c7b0 = 1;
        }
        if (gRaceSetup->mMode != MODE_BATTLE) {
            SetLapProgressSoundGaps(gCourseMap->mCheckpointSum);
            gSceneSoundState.mLapCount = GetLapCount();
        }
    } else {
        if (GetCurrentSceneNumber() == 2) {
            if (gRaceSetup->mRaceKind - 3 <= 1) {
                SetSoundMode(&gSoundModeHolder, SCENE_SOUND_MODE_PLAYING);
                gRaceSoundKind = 2;
            } else {
                if (IsFileSndArcOpen() != 0) {
                    savedArc = NNS_SndArcGetCurrent();
                    NNS_SndArcSetCurrent(&gFileSndArc);
                    value = 0xffff;
                    flag = 0x7f;
                    for (playerId = 1; playerId <= 7; playerId++) {
                        if (NNS_SndArcGetPlayerInfo(playerId) != NULL) {
                            if (((value >> playerId) & 1) != 0) {
                                NNS_SndPlayerSetPlayerVolume(playerId, flag);
                            }
                        }
                    }
                    NNS_SndArcSetCurrent(savedArc);
                }
                gPlayerVolumeFade.mVolume = 0x7f000;
                SetSoundMode(&gSoundModeHolder, SCENE_SOUND_MODE_MAIN_SEQUENCE_ONLY);
                gRaceSoundKind = 0;
            }
        } else {
            if (IsFileSndArcOpen() != 0) {
                savedArc = NNS_SndArcGetCurrent();
                NNS_SndArcSetCurrent(&gFileSndArc);
                value = 0xffff;
                flag = 0x7f;
                for (playerId2 = 1; playerId2 <= 7; playerId2++) {
                    if (NNS_SndArcGetPlayerInfo(playerId2) != NULL) {
                        if (((value >> playerId2) & 1) != 0) {
                            NNS_SndPlayerSetPlayerVolume(playerId2, flag);
                        }
                    }
                }
                NNS_SndArcSetCurrent(savedArc);
            }
            gPlayerVolumeFade.mVolume = 0x7f000;
            SetSoundMode(&gSoundModeHolder, SCENE_SOUND_MODE_PLAYING);
            gRaceSoundKind = 0;
        }
    }
    StartScenePlayersForScene(&gScenePlayers);
}

void StartRaceSounds(void) {
    s32 slotIndex;
    NNSSndSeqPlayer **handle;

    gSceneSoundState.mRaceState = 1;
    StartScenePlayersForRace(&gScenePlayers);
    gPlayerVolumeFade.mRaceStarted = 1;
    if (data_0217c7b0 != 0) {
        NNS_SndPlayerStopSeq(&gRaceSeqHandle, 0x14);
    }
    if (gRaceSetup->mCourseId != COURSE_ID_STADIUM) {
        return;
    }
    for (slotIndex = 7; slotIndex < 12; slotIndex++) {
        NNS_SndPlayerStopSeq(OFFSET_PTR(NNSSndSeqPlayer *, gSndHandleSlots, slotIndex * sizeof(NNSSndSeqPlayer *)), 0);
    }
    handle = &gRaceSeqHandle;
    if ((gRaceSoundKind & 1) == 0) {
        return;
    }
    if (gSoundModeHolder.mSeqStartEnabled == 0) {
        return;
    }
    if (*handle != NULL) {
        NNS_SndPlayerStopSeq(handle, 0);
    }
    if (*handle != NULL) {
        NNS_SndPlayerStopSeq(handle, 0);
    }
    NNS_SndArcPlayerStartSeqArc(handle, 0, 0x1c0);
}

void StartKartStarSeq(void) {
    if (gSceneSoundState.mRaceState != 1) {
        return;
    }
    gSceneSoundState.mKartStarSeqOn = 1;
    if ((gSceneSoundState.mLastLapSeqState & 1) != 0) {
        data_0217c7a8 = 1;
        return;
    }
    NNS_SndPlayerSetTrackMuteEx(&gScenePlayersSeqPlayer, 0xffff, 1);
    StartScenePlayersSeqNo(&gScenePlayers, 0x49, &gSceneSoundState.mKartStarSeq);
}

void StopKartStarSeq(void) {
    NNS_SndPlayerSetTrackMuteEx(&gScenePlayersSeqPlayer, 0xffff, 0);
    NNS_SndPlayerStopSeq(&gSceneSoundState.mKartStarSeq, 0);
    if (data_0217c78c != 0) {
        if (gSceneSoundState.mRaceState == 1) {
            StartScenePlayersSeq(&gScenePlayers);
            NNS_SndPlayerSetVolume(&gScenePlayersSeqPlayer, FROM_FIXED12(gVolumeFade.mVolume));
            NNS_SndPlayerSetTempoRatio(&gScenePlayersSeqPlayer, 0x12c);
            SetRestartedSeqPitchFlag();
        }
        data_0217c78c = 0;
    }
    gSceneSoundState.mKartStarSeqOn = 0;
}

void EndRaceSounds(void) {
    u32 fadeSteps;
    s32 slotIndex;
    s32 poolIndex;
    u8 *playerCursor;

    gSceneSoundState.mRaceState = 2;
    StopScenePlayersSeq(&gScenePlayers, GetEndRaceFadeSteps());
    NNS_SndPlayerSetTrackMuteEx(&gScenePlayersSeqPlayer, 0xffff, 0);
    NNS_SndPlayerStopSeq(&gSceneSoundState.mKartStarSeq, 0);
    if (data_0217c78c != 0) {
        if (gSceneSoundState.mRaceState == 1) {
            StartScenePlayersSeq(&gScenePlayers);
            NNS_SndPlayerSetVolume(&gScenePlayersSeqPlayer, FROM_FIXED12(gVolumeFade.mVolume));
            NNS_SndPlayerSetTempoRatio(&gScenePlayersSeqPlayer, 0x12c);
            SetRestartedSeqPitchFlag();
        }
        data_0217c78c = 0;
    }
    gSceneSoundState.mKartStarSeqOn = 0;
    if (gSoundModeHolder.mMode == 2) {
        SetSoundMode(&gSoundModeHolder, SCENE_SOUND_MODE_MAIN_SEQUENCE_ONLY);
    }
    for (slotIndex = 0; slotIndex < 12; slotIndex++) {
        NNS_SndPlayerStopSeq(gSndHandleSlots + slotIndex, GetEndRaceFadeSteps());
    }
    fadeSteps = GetEndRaceFadeSteps();
    for (poolIndex = 0, playerCursor = (&gSoundHandlePool)->mEntries; poolIndex < (&gSoundHandlePool)->mCount;
         poolIndex++) {
        NNS_SndPlayerStopSeq((NNSSndSeqPlayer **) playerCursor, fadeSteps);
        playerCursor += (&gSoundHandlePool)->mEntrySize;
    }
}

// Counts a lap done by the selected kart; one lap before the end it switches to seq 0x3e.
void AdvanceSceneSoundLap(void) {
    BOOL finishedAllLaps;
    s32 slotIndex;
    NNSSndSeqPlayer **seqHandle;

    finishedAllLaps = FALSE;
    if (GetCurrentSceneNumber() == 2) {
        if (gRaceSetup->mRaceKind == RACE_KIND_DEMO) {
            return;
        }
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        return;
    }
    gSceneSoundState.mLapsDone = gSceneSoundState.mLapsDone + 1;
    if (gSceneSoundState.mLapsDone == gSceneSoundState.mLapCount) {
        finishedAllLaps = TRUE;
    } else if (gSceneSoundState.mLapsDone == gSceneSoundState.mLapCount - 1) {
        gSceneSoundState.mLastLapSeqState = 1;
        gSceneSoundState.mOnLastLap = 1;
        StopScenePlayersSeq(&gScenePlayers, 0);
        if (gSceneSoundState.mKartStarSeq != NULL) {
            NNS_SndPlayerSetTrackMuteEx(&gSceneSoundState.mKartStarSeq, 0xffff, 1);
        }
        StartScenePlayersSeqNo(&gScenePlayers, 0x3e, NULL);
        gSceneSoundState.mLastLapSeqState = 1;
    }
    if (gRaceSetup->mCourseId != COURSE_ID_STADIUM) {
        return;
    }
    if (finishedAllLaps != FALSE) {
        return;
    }
    for (slotIndex = 7; slotIndex < 12; slotIndex++) {
        NNS_SndPlayerStopSeq(OFFSET_PTR(NNSSndSeqPlayer *, gSndHandleSlots, slotIndex * sizeof(NNSSndSeqPlayer *)), 0);
    }
    seqHandle = &gRaceSeqHandle;
    if ((gRaceSoundKind & 1) == 0) {
        return;
    }
    if (gSoundModeHolder.mSeqStartEnabled == 0) {
        return;
    }
    if (*seqHandle != NULL) {
        NNS_SndPlayerStopSeq(seqHandle, 0);
    }
    if (*seqHandle != NULL) {
        NNS_SndPlayerStopSeq(seqHandle, 0);
    }
    NNS_SndArcPlayerStartSeqArc(seqHandle, 0, 0x1c1);
}

// Stores the selected kart's new place; in some courses it starts a seq when the place improves.
void SetSceneSoundRank(u32 rankIndex) {
    BOOL flag;
    BOOL raceKindMatches;
    u32 slotSeqPlaying;
    u32 shouldStartSeq;
    u32 seqNo;
    s32 slotIndex;
    NNSSndSeqPlayer *seqPlayer;
    NNSSndSeqPlayer **seqHandle;

    flag = FALSE;
    if (GetCurrentSceneNumber() == 2) {
        raceKindMatches = gRaceSetup->mRaceKind == RACE_KIND_NORMAL || gRaceSetup->mRaceKind == RACE_KIND_REPLAY;
        if (raceKindMatches != FALSE) {
            flag = TRUE;
        }
    }
    if (flag == FALSE) {
        return;
    }
    if ((u32) gRaceSetup->mMode - 1 <= 1) {
        return;
    }
    seqNo = -1;
    flag = FALSE;
    if (gSceneSoundState.mRaceFrames <= 0xf0) {
        gSceneSoundState.mRankIndex = rankIndex;
        return;
    }
    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_STADIUM:
            if (gSceneSoundState.mOnLastLap != 0) {
                seqNo = 0x1c2;
                for (slotIndex = 7; slotIndex < 12; slotIndex++) {
                    NNS_SndPlayerStopSeq(
                        OFFSET_PTR(NNSSndSeqPlayer *, gSndHandleSlots, slotIndex * sizeof(NNSSndSeqPlayer *)), flag);
                }
                flag = TRUE;
            }
            { break; }
        case COURSE_ID_PINBALL:
            seqNo = rankIndex == 0 ? 0x1cb : 0x1ca;
            flag = TRUE;
            seqPlayer = gSndHandleSlots[7];
            slotSeqPlaying = seqPlayer != NULL && seqPlayer->mSeqArcIndex == 0x1cc && seqPlayer->mSeqNo == 0;
            if (slotSeqPlaying != 0) {
                flag = FALSE;
            }
            break;
    }
    if (flag != FALSE) {
        if (rankIndex < gSceneSoundState.mRankIndex) {
            shouldStartSeq = 0;
            if (gSceneSoundState.mRankSeqFrames != -1) {
                if (gSceneSoundState.mRankIndexAtSeq > rankIndex) {
                    shouldStartSeq = 1;
                }
            } else {
                shouldStartSeq = 1;
            }
            if (shouldStartSeq != 0) {
                NNS_SndPlayerStopSeq(&gRaceSeqHandle, 0);
                seqHandle = &gRaceSeqHandle;
                if (gRaceSoundKind & 1) {
                    if (gSoundModeHolder.mSeqStartEnabled != 0) {
                        if (*seqHandle != NULL) {
                            NNS_SndPlayerStopSeq(seqHandle, 0);
                        }
                        if (*seqHandle != NULL) {
                            NNS_SndPlayerStopSeq(seqHandle, 0);
                        }
                        NNS_SndArcPlayerStartSeqArc(seqHandle, 0, (u16) seqNo);
                    }
                }
                gSceneSoundState.mRankIndexAtSeq = rankIndex;
                gSceneSoundState.mRankSeqFrames = 0;
            }
        }
    }
    gSceneSoundState.mRankIndex = rankIndex;
}

void UpdateRaceSounds(void) {
    PlayerVolumeFade *volumeFade;
    NNSSndSeqPlayer **sceneSeqHandle;
    u32 steppedVolume;
    s32 tableRow;
    s32 playerMask;
    s32 playerNo;
    struct NNSSndArc *savedArc;

    switch (gSceneSoundState.mRaceState) {
        case 1:
            gSceneSoundState.mRaceFrames++;
            if (gSceneSoundState.mRaceFrames == 0x28) {
                StartScenePlayersSeq(&gScenePlayers);
                NNS_SndPlayerSetVolume(&gScenePlayersSeqPlayer, FROM_FIXED12(gVolumeFade.mVolume));
            }
            volumeFade = &gPlayerVolumeFade;
            tableRow = volumeFade->mRaceStarted;
            if (tableRow == 1) {
                volumeFade->mVolumePerFrame = gPlayerVolumeSteps[tableRow];
                steppedVolume = StepValueTowardTarget(volumeFade, gPlayerVolumeTargets[tableRow]);
                if (steppedVolume != -1) {
                    playerMask = gPlayerVolumeMasks[tableRow];
                    if (IsFileSndArcOpen() != 0) {
                        savedArc = NNS_SndArcGetCurrent();
                        NNS_SndArcSetCurrent(&gFileSndArc);
                        for (playerNo = 1; playerNo <= 7; playerNo++) {
                            if (NNS_SndArcGetPlayerInfo(playerNo) != NULL && ((playerMask >> playerNo) & 1) != 0) {
                                NNS_SndPlayerSetPlayerVolume(playerNo, steppedVolume);
                            }
                        }
                        NNS_SndArcSetCurrent(savedArc);
                    }
                }
            }
            UpdateSceneSeqPlayerControl();
            UpdateSoundPitchSwing();
            break;
        case 2:
            UpdateRaceEndSeq();
            break;
    }
    if (gRaceSetup->mMode != MODE_BATTLE) {
        sceneSeqHandle = &gScenePlayersSeqPlayer;
        if (IsAnySeqVariableEnabled() != 0) {
            UpdateSeqVariableReadings(sceneSeqHandle);
            if (gRaceSetup->mCourseId == COURSE_ID_TOWN) {
                if (IsSeqVariableChanged(0) != 0 || IsSeqVariableChanged(1) != 0) {
                    StartCourseSoundAtVolume(0, 0x1a9);
                }
            }
        }
        if (gRaceSetup->mCourseId == COURSE_ID_KOOPA) {
            UpdateCourseSound(0, 0x16b);
        }
        if (gSceneSoundState.mRankSeqFrames != -1) {
            if (++gSceneSoundState.mRankSeqFrames >= 0x3c) {
                gSceneSoundState.mRankSeqFrames = -1;
            }
        }
        if (gSceneSoundState.mLastLapSeqState == 1 && sceneSeqHandle[0] == NULL) {
            gSceneSoundState.mLastLapSeqState = 0;
            if (data_0217c7a8 != 0 && gSceneSoundState.mKartStarSeqOn == 1) {
                if (gSceneSoundState.mRaceState == 1) {
                    gSceneSoundState.mKartStarSeqOn = 1;
                    if ((gSceneSoundState.mLastLapSeqState & 1) == 0) {
                        NNS_SndPlayerSetTrackMuteEx(&gScenePlayersSeqPlayer, 0xffff, 1);
                        StartScenePlayersSeqNo(&gScenePlayers, 0x49, &gSceneSoundState.mKartStarSeq);
                    }
                }
                data_0217c7a8 = 0;
                data_0217c78c = 1;
            } else if (gSceneSoundState.mKartStarSeq != NULL) {
                NNS_SndPlayerSetTrackMuteEx(&gSceneSoundState.mKartStarSeq, 0xffff, 0);
                data_0217c78c = 1;
            } else if (gSceneSoundState.mRaceState == 1) {
                StartScenePlayersSeq(&gScenePlayers);
                NNS_SndPlayerSetVolume(&gScenePlayersSeqPlayer, FROM_FIXED12(gVolumeFade.mVolume));
                NNS_SndPlayerSetTempoRatio(&gScenePlayersSeqPlayer, 0x12c);
                SetRestartedSeqPitchFlag();
            }
        }
    } else {
        UpdateKartSoundQueue();
    }
    gKingTeresaStateLastFrame = gKingTeresaState;
}

void UpdateCourseSeqAtSceneFrames(void) {
    u32 seqNo;
    NNSSndSeqPlayer **seqHandle;

    seqNo = 0xffff;
    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_STADIUM:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                seqNo = 0x1bc;
            }
            break;
        case COURSE_ID_RIDGE:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                seqNo = 0x1a6;
            }
            break;
        case COURSE_ID_GARDEN:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                seqNo = 0x1a5;
            }
            break;
        case COURSE_ID_MANSION:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                seqNo = 0x126;
            }
            break;
        case COURSE_ID_AIRSHIP:
            switch (gSceneSoundState.mSceneFrames) {
                case 0xa:
                    seqNo = 0x1d2;
                    break;
                case 0xa0:
                    NNS_SndPlayerStopSeq(&gRaceSeqHandle, 0x3c);
                    break;
                case 0x122:
                    seqNo = 0x1d2;
                    break;
            }
            { break; }
        case COURSE_ID_KOOPA:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                seqNo = 0x1aa;
            }
            break;
        case COURSE_ID_CLOCK:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                seqNo = 0x192;
            }
            break;
        case COURSE_ID_MARIO:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                seqNo = 0x19b;
            }
            break;
        case COURSE_ID_OLD_NOKO_SFC:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                seqNo = 0x112;
            }
            break;
        case COURSE_ID_BEACH:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                seqNo = 0x112;
            }
            break;
        case COURSE_ID_OLD_MOMO_64:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                seqNo = 0x12b;
            }
            break;
        case COURSE_ID_OLD_HYUDORO_64:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                seqNo = 0x19a;
            }
            break;
        case COURSE_ID_OLD_LUIGI_AGB:
            if (gSceneSoundState.mSceneFrames == 0xa) {
                seqNo = 0x1d5;
            }
            break;
        case COURSE_ID_RAINBOW:
            if (gSceneSoundState.mSceneFrames == 0x28) {
                seqNo = 0x1ba;
            }
            break;
        case COURSE_ID_TOWN:
            if (gSceneSoundState.mSceneFrames == 0x28) {
                seqNo = 0x199;
            }
            break;
    }
    if (seqNo == 0xffff) {
        return;
    }
    NNS_SndPlayerStopSeq(&gRaceSeqHandle, 0);
    seqHandle = &gRaceSeqHandle;
    if ((gRaceSoundKind & 2) == 0) {
        return;
    }
    if (gSoundModeHolder.mSeqStartEnabled == 0) {
        return;
    }
    if (*seqHandle != NULL) {
        NNS_SndPlayerStopSeq(seqHandle, 0);
    }
    if (*seqHandle != NULL) {
        NNS_SndPlayerStopSeq(seqHandle, 0);
    }
    NNS_SndArcPlayerStartSeqArc(seqHandle, 0, seqNo);
}

void UpdateSceneSoundState(void) {
    PlayerVolumeFade *volumeFade;
    s32 tableRow;
    s32 steppedVolume;
    s32 playerMask;
    s32 playerNo;
    struct NNSSndArc *savedArc;

    volumeFade = &gPlayerVolumeFade;
    tableRow = volumeFade->mRaceStarted;
    if (tableRow == 0) {
        volumeFade->mVolumePerFrame = gPlayerVolumeSteps[tableRow];
        steppedVolume = StepValueTowardTarget(volumeFade, gPlayerVolumeTargets[tableRow]);
        if (steppedVolume != -1) {
            playerMask = gPlayerVolumeMasks[tableRow];
            if (IsFileSndArcOpen() != 0) {
                savedArc = NNS_SndArcGetCurrent();
                NNS_SndArcSetCurrent(&gFileSndArc);
                for (playerNo = 1; playerNo <= 7; playerNo++) {
                    if (NNS_SndArcGetPlayerInfo(playerNo) != NULL && ((playerMask >> playerNo) & 1) != 0) {
                        NNS_SndPlayerSetPlayerVolume(playerNo, steppedVolume);
                    }
                }
                NNS_SndArcSetCurrent(savedArc);
            }
        }
    }
    if (GetCurrentSceneNumber() == 2) {
        switch (gRaceSetup->mRaceKind) {
            case RACE_KIND_NORMAL:
            case RACE_KIND_REPLAY:
                UpdateRaceSounds();
                break;
            case RACE_KIND_START_GP:
            case RACE_KIND_START_BATTLE:
                UpdateCourseSeqAtSceneFrames();
                break;
        }
    } else if (GetCurrentSceneNumber() == 9) {
        if (gSceneSoundState.mSceneFrames == 0x5d) {
            NNS_SndPlayerStopSeq(&gScenePlayersSeqPlayer, 0x1b);
        }
    } else if (GetCurrentSceneNumber() == 1 || GetCurrentSceneNumber() == 0xc) {
        if (gBootInfo->mBootType != 2) {
            UpdateSeqQueue();
        }
    } else if (GetCurrentSceneNumber() == 3) {
        UpdateEmblemSound();
    }
    if (gCurrentSoundSetPlayer != NULL && gCurrentSoundSetPlayer->mSoundSet.mSeqId == 0 &&
        gCurrentSoundSetPlayer->mSeqPlayer != NULL) {
        UpdateSeqVariableReadings(&gCurrentSoundSetPlayer->mSeqPlayer);
    }
    gSceneSoundState.mSceneFrames++;
}

void StopSceneSounds(void) {
    u32 fadeSteps;
    s32 slotIndex;
    s32 poolIndex;
    u8 *playerCursor;

    if (gBootInfo->mBootType == 2 && GetCurrentSceneNumber() == 6) {
        return;
    }
    gPlayerVolumeFade.mTargetVolumeBeforeRaceStart = 0;
    gPlayerVolumeFade.mRaceStarted = 0;
    ScenePlayersReturnArgument(&gScenePlayers);
    SetSoundMode(&gSoundModeHolder, SCENE_SOUND_MODE_FADED_OUT);
    for (slotIndex = 0; slotIndex < 12; slotIndex++) {
        NNS_SndPlayerStopSeq(gSndHandleSlots + slotIndex, GetSoundFadeSteps());
    }
    fadeSteps = GetSoundFadeSteps();
    for (poolIndex = 0, playerCursor = (&gSoundHandlePool)->mEntries; poolIndex < (&gSoundHandlePool)->mCount;
         poolIndex++) {
        NNS_SndPlayerStopSeq((NNSSndSeqPlayer **) playerCursor, fadeSteps);
        playerCursor += (&gSoundHandlePool)->mEntrySize;
    }
    NNS_SndPlayerStopSeq(&gSeqZeroLoopHandle, 13);
    NNS_SndPlayerStopSeq(&gMatchingEntrySeqHandle, 13);
    gSeqZeroLoopOn = 0;
}

void StopSceneSoundsAtOnce(void) {
    s32 slotIndex;
    s32 poolIndex;
    u8 *playerCursor;
    SoundHandlePool *playerTable;

    if (gBootInfo->mBootType == 2 && GetCurrentSceneNumber() == 6) {
        return;
    }
    gPlayerVolumeFade.mTargetVolumeBeforeRaceStart = 0;
    gPlayerVolumeFade.mRaceStarted = 0;
    ReleaseScenePlayers(&gScenePlayers, 1);
    SetSoundMode(&gSoundModeHolder, SCENE_SOUND_MODE_STOPPED);
    for (slotIndex = 0; slotIndex < 12; slotIndex++) {
        NNS_SndPlayerStopSeq(gSndHandleSlots + slotIndex, 0);
    }
    playerTable = &gSoundHandlePool;
    for (poolIndex = 0, playerCursor = playerTable->mEntries; poolIndex < playerTable->mCount; poolIndex++) {
        NNS_SndPlayerStopSeq((NNSSndSeqPlayer **) playerCursor, 0);
        playerCursor += playerTable->mEntrySize;
    }
    gSeqZeroLoopOn = 0;
    NNS_SndPlayerStopSeq(&gSeqZeroLoopHandle, 0);
    NNS_SndPlayerStopSeq(&gMatchingEntrySeqHandle, 0);
}

void StopSceneSeqWithFadeSteps(void) {
    u32 fadeSteps;
    fadeSteps = GetSoundFadeSteps();
    NNS_SndPlayerStopSeq(&gScenePlayersSeqPlayer, fadeSteps);
}

// Starts a seq and fades the sound handles out while the choises-S screen is open.
void LowerSndHandleVolumes(void) {
    u32 savedFadeSteps;
    s32 fadeSteps;
    s32 poolIndex;
    u8 *playerCursor;
    s32 slotIndex;
    NNSSndSeqPlayer **handleCursor;
    SoundHandlePool *playerTable;

    savedFadeSteps = GetSoundFadeSteps();
    gSceneSoundState.mVolumesLowered = 1;
    SetSoundFadeSteps(0xa);
    if (gChoisesSSeqHandle != NULL) {
        NNS_SndPlayerStopSeq(&gChoisesSSeqHandle, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&gChoisesSSeqHandle, 0, 0x11);
    if (gSceneSoundState.mRaceState == 2) {
        return;
    }
    SetSoundMode(&gSoundModeHolder, SCENE_SOUND_MODE_PAUSED);
    if (gSceneSoundState.mLastLapSeqState == 1) {
        gSceneSoundState.mLastLapSeqState = 3;
    }
    handleCursor = gSndHandleSlots;
    for (slotIndex = 0; slotIndex < 0xc; slotIndex++) {
        NNS_SndPlayerMoveVolume(handleCursor, 0, GetSoundFadeSteps());
        handleCursor++;
    }
    fadeSteps = GetSoundFadeSteps();
    playerTable = &gSoundHandlePool;
    for (poolIndex = 0, playerCursor = playerTable->mEntries; poolIndex < playerTable->mCount; poolIndex++) {
        NNS_SndPlayerMoveVolume((NNSSndSeqPlayer **) playerCursor, 0, fadeSteps);
        playerCursor += playerTable->mEntrySize;
    }
    SetSoundFadeSteps(savedFadeSteps);
}

// Starts a seq and fades the sound handles back in when the choises-S screen closes.
void RaiseSndHandleVolumes(void) {
    u32 savedFadeSteps;
    s32 fadeSteps;
    s32 poolIndex;
    u8 *playerCursor;
    s32 slotIndex;
    NNSSndSeqPlayer **handleCursor;
    SoundHandlePool *playerTable;

    savedFadeSteps = GetSoundFadeSteps();
    gSceneSoundState.mVolumesLowered = 0;
    SetSoundFadeSteps(0xa);
    if (gChoisesSSeqHandle != NULL) {
        NNS_SndPlayerStopSeq(&gChoisesSSeqHandle, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&gChoisesSSeqHandle, 0, 0x12);
    if (gSceneSoundState.mRaceState == 2) {
        return;
    }
    RestoreSavedSoundMode(&gSoundModeHolder);
    if (gSceneSoundState.mLastLapSeqState == 3) {
        gSceneSoundState.mLastLapSeqState = 1;
    }
    handleCursor = gSndHandleSlots;
    for (slotIndex = 0; slotIndex < 0xc; slotIndex++) {
        NNS_SndPlayerMoveVolume(handleCursor, 0x7f, GetSoundFadeSteps());
        handleCursor++;
    }
    fadeSteps = GetSoundFadeSteps();
    playerTable = &gSoundHandlePool;
    for (poolIndex = 0, playerCursor = playerTable->mEntries; poolIndex < playerTable->mCount; poolIndex++) {
        NNS_SndPlayerMoveVolume((NNSSndSeqPlayer **) playerCursor, 0x7f, fadeSteps);
        playerCursor += playerTable->mEntrySize;
    }
    SetSoundFadeSteps(savedFadeSteps);
}

void StartChoisesSValueSeq(s32 valueIndex) {
    u32 fadeSteps;
    s32 poolIndex;
    u8 *playerCursor;
    s32 slotIndex;
    NNSSndSeqPlayer **handleCursor;
    SoundHandlePool *playerTable;
    u32 seqNo;

    seqNo = data_0215a6d8[valueIndex];
    if (gChoisesSSeqHandle != NULL) {
        NNS_SndPlayerStopSeq(&gChoisesSSeqHandle, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&gChoisesSSeqHandle, 0, seqNo);
    if (valueIndex == 4) {
        return;
    }
    handleCursor = gSndHandleSlots;
    for (slotIndex = 0; slotIndex < 0xc; slotIndex++) {
        NNS_SndPlayerStopSeq(handleCursor, GetSoundFadeSteps());
        handleCursor++;
    }
    fadeSteps = GetSoundFadeSteps();
    playerTable = &gSoundHandlePool;
    for (poolIndex = 0, playerCursor = playerTable->mEntries; poolIndex < playerTable->mCount; poolIndex++) {
        NNS_SndPlayerStopSeq((NNSSndSeqPlayer **) playerCursor, fadeSteps);
        playerCursor += playerTable->mEntrySize;
    }
    SetSoundMode(&gSoundModeHolder, SCENE_SOUND_MODE_FADED_OUT);
}

void StopAllSeqPlayers(void) {
    NNS_SndPlayerStopSeqAll(GetSoundFadeSteps());
}

void SetSndHandleTrackVolume(NNSSndSeqPlayer **handle, u32 volume) {
    NNS_SndPlayerSetTrackVolume(handle, gSeqTrackMask, (u8) volume);
}

void SetSndHandleTrackPitch(NNSSndSeqPlayer **handle, u32 pitch) {
    NNS_SndPlayerSetTrackPitch(handle, gSeqTrackMask, pitch);
}

// Starts sound a on the shared handle unless one was already started this frame.
void StartSoundOncePerFrame(s32 seqNo) {
    if (gSoundStartedThisFrame != 0) {
        return;
    }
    gSoundStartedThisFrame = 1;
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, seqNo);
}

void StartMissionRunLVselSeq(u32 mode) {
    s32 seqNo;

    data_0217c784 = mode;
    if (mode - 1 > 1) {
        return;
    }
    seqNo = (mode == 1) ? 0x47 : 0x48;
    NNS_SndHeapLoadState(gCurrentSndHeap, data_0217c798[0]);
    NNS_SndHeapGetCurrentLevel(gCurrentSndHeap);
    NNS_SndArcLoadSeq(seqNo, gCurrentSndHeap);
    NNS_SndPlayerStopSeq(&gScenePlayersSeqPlayer, 2);
    StartSeqAtVolume(seqNo, 0x7f, &data_0217c83c);
}

void StartSceneSeqIfIdle(void) {
    if (gScenePlayers.mSeqPlayer != NULL) {
        return;
    }
    if (gSndHandleSlots[1] != NULL) {
        return;
    }
    StartScenePlayersSeq(&gScenePlayers);
}

void StopMissionRunLVselSeqsWithSteps(int mode, u32 fadeSteps) {
    if (data_0217c784 - 1 <= 1) {
        NNS_SndPlayerStopSeq(&data_0217c83c, fadeSteps);
    }
    if (mode == 3) {
        NNS_SndPlayerStopSeq(&gScenePlayersSeqPlayer, fadeSteps);
        return;
    }
}

void StartSceneSeqAfterMissionRunLVsel(u32 mode) {
    if (mode != 4) {
        return;
    }
    if (gScenePlayers.mSeqPlayer != NULL) {
        return;
    }
    StartScenePlayersSeq(&gScenePlayers);
}

void LoadMissionRunMSselSoundData(u32 mode, u32 missionRow) {
    u32 bankNo = 0xff;
    data_0217c784 = mode;
    data_0217c79c = 0;
    data_0217c7a0 = 0;
    gMissionRunMSselSeqIndex = 0xff;
    if (mode != 3) {
        return;
    }
    switch (missionRow) {
        case 1:
            gMissionRunMSselSeqIndex = 1;
            bankNo = 0x25;
            break;
        case 2:
            gMissionRunMSselSeqIndex = 2;
            bankNo = 0x26;
            break;
        case 3:
            gMissionRunMSselSeqIndex = 3;
            bankNo = 0x27;
            break;
        case 4:
            gMissionRunMSselSeqIndex = 4;
            bankNo = 0x28;
            break;
        case 5:
            gMissionRunMSselSeqIndex = 5;
            bankNo = 0x29;
            break;
        case 6:
            gMissionRunMSselSeqIndex = 6;
            bankNo = 0x25;
            break;
        case 7:
            gMissionRunMSselSeqIndex = 7;
            bankNo = 0x17;
            break;
    }
    NNS_SndHeapLoadState(gCurrentSndHeap, data_0217c798[0]);
    NNS_SndHeapGetCurrentLevel(gCurrentSndHeap);
    NNS_SndArcLoadBank(bankNo, gCurrentSndHeap);
    NNS_SndArcLoadBank(0x2a, gCurrentSndHeap);
    NNS_SndArcLoadSeqArc(4, gCurrentSndHeap);
}

void UpdateMissionRunMSselSounds(s32 stepId) {
    s32 trackVolume;
    u32 startsBankSeq;
    s32 stepCount;
    if (data_0217c784 == 0) {
        if (gScenePlayers.mSeqPlayer != NULL) {
            return;
        }
        StartScenePlayersSeq(&gScenePlayers);
        return;
    }
    if (stepId != 0 && stepId != 0x32) {
        return;
    }
    startsBankSeq = 0;
    trackVolume = 0x78;
    stepCount = (stepId == 0x32) ? data_0217c79c : data_0217c7a0;
    if (stepCount < 5) {
        switch (stepCount) {
            case 0:
                trackVolume = 0xf;
                break;
            case 1:
                trackVolume = 0x1e;
                startsBankSeq = 1;
                break;
            case 2:
                trackVolume = 0x2d;
                break;
            case 3:
                trackVolume = 0x46;
                break;
            case 4:
                trackVolume = 0x2d;
                break;
        }
    } else {
        switch ((stepCount - 5) % 6) {
            case 0:
                trackVolume = 0x1e;
                break;
            case 1:
                trackVolume = 0x2d;
                break;
            case 2:
                trackVolume = 0x46;
                break;
            case 3:
                trackVolume = 0x5f;
                startsBankSeq = 1;
                break;
            case 4:
                trackVolume = 0x46;
                break;
            case 5:
                trackVolume = 0x2d;
                break;
        }
    }
    if (stepId == 0x32) {
        NNSSndSeqPlayer **seqHandle = &data_0217c83c;
        if (*seqHandle != NULL) {
            NNS_SndPlayerStopSeq(seqHandle, 0);
        }
        NNS_SndArcPlayerStartSeqArc(seqHandle, 4, 0);
        if (*seqHandle != NULL) {
            NNS_SndPlayerSetTrackVolume(seqHandle, gSeqTrackMask, trackVolume & 0xff);
        }
        data_0217c79c++;
        return;
    }
    if (stepId != 0) {
        return;
    }
    if (startsBankSeq != 0) {
        u16 seqIndex = gMissionRunMSselSeqIndex;
        if (seqIndex != 0xff) {
            NNSSndSeqPlayer **bankSeqHandle = &data_0217c840;
            if (*bankSeqHandle != NULL) {
                NNS_SndPlayerStopSeq(bankSeqHandle, 0);
            }
            NNS_SndArcPlayerStartSeqArc(bankSeqHandle, 4, seqIndex);
        }
    }
    data_0217c7a0++;
}

void StopMissionRunMSselSeqsWithSteps(u32 unused, u32 fadeSteps) {
    NNS_SndPlayerStopSeq(&data_0217c83c, fadeSteps);
    NNS_SndPlayerStopSeq(&data_0217c840, fadeSteps);
}

void StopMissionRunMSselSeqsAtOnce(void) {
    NNS_SndPlayerStopSeq(&data_0217c83c, 0);
    NNS_SndPlayerStopSeq(&data_0217c840, 0);
}
