#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Sound/sound_row.h"
#include "Main/Menu/menu_entry_kind.h"
#include "Main/System/result_archive_path.h"
#include "Main/Menu/menu_label_cell_rows.h"
#include "font_glyph_layout.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Race/race_setup_input.h"
#include "Main/Scene/scene_connection.h"

#include "sound_player_control.h"
#include "Main/Sound/sound_sources.h"
#include "Main/Sound/scene_players_start_stop_and_release.h"
#include "Main/Sound/sound_system.h"
#include "Main/Sound/sound_mode.h"
#include "Main/Sound/sound_mode_setup_and_restore.h"
#include "Main/Sound/sound_archive_setup_and_file_id_clear.h"
#include "Main/Course/course_sound_slot.h"
#include "Main/Sound/seq_queue_seq_volume_control_and_seq_variables.h"
#include "Main/Sound/race_end_seq_menu_seqs_and_emblem_sound.h"
#include "Main/Sound/seq_row.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids_on_memory_sdat_and_list_links.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Sound/sound_set_load.h"
#include "sound_archive_load_result.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "sound_system_main.h"
#include "fixed_vector_math.h"
#include "Main/Scene/run_scenes.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Sound/sound_falloffs_and_playing_sounds_init.h"
#include "Main/Sound/sound_nop_wrapper.h"
#include "Main/Sound/kart_sound_starts_and_track_params.h"
#include "Main/Sound/map_object_sound_starts_and_queues.h"
#include "Main/Sound/end_race_fade_steps.h"
#include "Main/Sound/sound_file_id_list.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "Main/Save/buddy_record_time.h"
#include "cell_transfer_state.h"
#include "Main/Sound/kart_sound.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/System/init_after_startup.h"

const Vec3 gVec3Ones = {0x1000, 0x1000, 0x1000};
const Vec3 gPooledMapObjectVec3Zero = {0, 0, 0};
const u16 gChoisesSValueSeqNos[6] = {0xc, 0xc, 0xc, 0x13, 7, 7};
s32 gSndHeapSizeKind = 4;
LoadedSoundBanks gLoadedSoundBanks = {0, {0, 0}, LOADED_SOUND_BANKS_NONE};
SurfaceSoundSetup gOldLuigiAgbSurfaceSoundSetup = {{0x7a, 0x66, 0x67, 0x9d}, 0, 0};
s32 gSndBankIdsByBit[13] = {3, 4, 5, 6, 7, 8, 9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf};
s32 gSndWaveArcIdsByBit[13] = {5, 6, 7, 8, 9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0x10, 0x11};
CourseSurfaceSoundEntry gCourseSurfaceSoundEntries[14] = {
    {0x8d, 2}, {0x8e, 2}, {0x8d, 7},   {0x8d, 7}, {0x8e, 2}, {0x8e, 2}, {0x8d, 7},
    {0x8d, 2}, {0x8e, 2}, {0x8e, 2}, {0x8d, 2}, {0x8d, 2}, {0x158, 1}, {0x8e, 2}};
u16 gMissionRunMSselSeqIndex;
u16 gMissionRunCountSeqNo[1];
u16 gMissionRunLimitSeqNo[1];
NNSSndSeqPlayer *gSeqZeroAndSessionSeqHandle;
u32 gSceneSeqRestartAfterStar;
s32 gMissionRunMSselStep0Count;
s32 gMissionRunMSselStep32Count;
u32 gSndHeapSavedState[1];
NNSSndSeqPlayer *gChoisesSSeqHandle;
NNSSndSeqPlayer *gMatchingEntrySeqHandle;
u32 gBeforeStartSeqStarted;
s32 gSeqZeroLoopOn;
u32 gSoundStartedThisFrame;
u32 gRaceSoundKind;
u32 gMissionRunSelMode;
NNSSndHeap *gSndHeap;
NNSSndHeap *gSeqRowSndHeap;
u32 gKartStarSeqStartPending;
LoadedSoundSet gLoadedSoundSet;
SoundHandlePool gSoundHandlePool;
u8 gSoundHandlePoolEntries[21];
SceneSoundState gSceneSoundState;
NNSSndSeqPlayer *gSndHandleSlots[12];
NNSSndArc gOnMemorySndArc;
PlayerVolumeFade gPlayerVolumeFade;

// Keeps seq 0 looping on the in-memory archive until StopSeqZeroLoop; UpdateSounds restarts it.
void StartSeqZeroLoop(void) {
    NNS_SndArcSetCurrent(&gOnMemorySndArc);
    NNS_SndPlayerStopSeq(&gSeqZeroAndSessionSeqHandle, 1);
    NNS_SndPlayerStopSeq(&gMatchingEntrySeqHandle, 1);
    gSeqZeroLoopOn = 1;
    NNS_SndArcSetCurrent(&gFileSndArc);
}

void StopSeqZeroLoop(void) {
    NNS_SndArcSetCurrent(&gOnMemorySndArc);
    NNS_SndPlayerStopSeq(&gSeqZeroAndSessionSeqHandle, 0xd);
    gSeqZeroLoopOn = 0;
    NNS_SndPlayerStopSeq(&gMatchingEntrySeqHandle, 1);
    NNS_SndArcSetCurrent(&gFileSndArc);
}

void BootInfoStartMessageScreenSeq(void) {
    NNS_SndPlayerStopSeq(&gSeqZeroAndSessionSeqHandle, 1);
    gSeqZeroLoopOn = 0;
    NNS_SndPlayerStopSeq(&gMatchingEntrySeqHandle, 1);
    NNS_SndArcSetCurrent(&gOnMemorySndArc);
    NNS_SndArcSetCurrent(&gOnMemorySndArc);
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 1);
    NNS_SndArcSetCurrent(&gFileSndArc);
    NNS_SndArcSetCurrent(&gFileSndArc);
}

void StartMessageScreenSeq(void) {
    NNS_SndPlayerStopSeq(&gSeqZeroAndSessionSeqHandle, 1);
    gSeqZeroLoopOn = 0;
    NNS_SndPlayerStopSeq(&gMatchingEntrySeqHandle, 1);
    NNS_SndArcSetCurrent(&gOnMemorySndArc);
    NNS_SndArcSetCurrent(&gOnMemorySndArc);
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 1);
    NNS_SndArcSetCurrent(&gFileSndArc);
    NNS_SndArcSetCurrent(&gFileSndArc);
}

void StartTimeAttackGhostSendSeq(void) {
    NNS_SndPlayerStopSeq(&gSeqZeroAndSessionSeqHandle, 1);
    NNS_SndArcSetCurrent(&gOnMemorySndArc);
    if (gSeqZeroAndSessionSeqHandle != NULL) {
        NNS_SndPlayerStopSeq(&gSeqZeroAndSessionSeqHandle, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&gSeqZeroAndSessionSeqHandle, 0, 8);
    NNS_SndArcSetCurrent(&gFileSndArc);
}

void StopTimeAttackGhostSendSeq(void) {
    NNS_SndPlayerStopSeq(&gSeqZeroAndSessionSeqHandle, 1);
}

void StartWiFiSessionLoginSeq(void) {
    NNS_SndPlayerStopSeq(&gSeqZeroAndSessionSeqHandle, 1);
    if (gSeqZeroAndSessionSeqHandle != NULL) {
        NNS_SndPlayerStopSeq(&gSeqZeroAndSessionSeqHandle, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&gSeqZeroAndSessionSeqHandle, 0, 0x202);
}

void StartWiFiSessionLoginResult1Seq(void) {
    NNS_SndPlayerStopSeq(&gSeqZeroAndSessionSeqHandle, 1);
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x203);
}

void StartWiFiSessionMatchingSeq(void) {
    NNS_SndPlayerStopSeq(&gSeqZeroAndSessionSeqHandle, 1);
    if (gSeqZeroAndSessionSeqHandle != NULL) {
        NNS_SndPlayerStopSeq(&gSeqZeroAndSessionSeqHandle, 0);
    }
    NNS_SndArcPlayerStartSeqArc(&gSeqZeroAndSessionSeqHandle, 0, 0x204);
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
    NNS_SndPlayerStopSeq(&gSeqZeroAndSessionSeqHandle, 1);
    NNS_SndPlayerStopSeq(&gMatchingEntrySeqHandle, 1);
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x207);
}

void StartWiFiLoginErrorSeq(void) {
    NNS_SndPlayerStopSeq(&gSeqZeroAndSessionSeqHandle, 1);
    NNS_SndPlayerStopSeq(&gMatchingEntrySeqHandle, 1);
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, (0x0000020au));
}

void StartWiFiNoOpponentsSeq(void) {
    NNS_SndPlayerStopSeq(&gSeqZeroAndSessionSeqHandle, 1);
    NNS_SndPlayerStopSeq(&gMatchingEntrySeqHandle, 1);
    NNS_SndPlayerStopSeq(&gSeqZeroAndSessionSeqHandle, 1);
    NNS_SndPlayerStopSeq(&gMatchingEntrySeqHandle, 1);
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x20a);
}

void StopBothSeqHandles(void) {
    NNS_SndPlayerStopSeq(&gSeqZeroAndSessionSeqHandle, 1);
    NNS_SndPlayerStopSeq(&gMatchingEntrySeqHandle, 1);
}

LoadedSoundSet *GetLoadedSoundSet(void) {
    return &gLoadedSoundSet;
}

BOOL LoadSndBanksAndWaveArcs(s32 bankMask) {
    s32 bankIndex;
    NNSSndHeap *savedHeap;

    savedHeap = gCurrentSndHeap;
    gCurrentSndHeap = gSndHeap;
    if (gSndHeapSizeKind != SND_HEAP_SIZE_SMALL) {
        NNS_SndArcLoadBank(1, gSndHeap);
    }
    for (bankIndex = 0; bankIndex < 0xd; bankIndex++) {
        if (((bankMask >> bankIndex) & 1) != 0) {
            if (NNS_SndArcLoadBankEx(gSndBankIdsByBit[bankIndex], 2, gSndHeap) == 0) {
                gCurrentSndHeap = savedHeap;
                return FALSE;
            }
            if (NNS_SndArcLoadWaveArc(gSndWaveArcIdsByBit[bankIndex], gSndHeap) == 0) {
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
    if (gLoadedSoundBanks.mLoadMarker != LOADED_SOUND_BANKS_NONE && gLoadedSoundBanks.mBankMask == bankMask) {
        return TRUE;
    }
    NNS_SndHeapClear(gSndHeap);
    gLoadedSoundBanks.mLoadMarker = LOADED_SOUND_BANKS_NONE;
    gLoadedSoundBanks.mBankMask = 0;
    gLoadedSoundBanks.mBankMask = bankMask;
    gLoadedSoundBanks.mLoadMarker = LOADED_SOUND_BANKS_LOADED;
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
    NNS_SndHeapDestroy(gSeqRowSndHeap);
    gSeqRowSndHeap = NULL;
    ClearSndFileAddresses(GetSndDataFileIdList());
    ClearSndFileIdList(GetSndDataFileIdList());
    gLoadedSoundBanks = gLoadedSoundBanksAfterRelease;
    ResetLoadedSoundSet(&gLoadedSoundSet);
}

void CreateSndHeaps(u32 heapSizeKind, u32 buffer) {
    u32 soundHeapSize;
    u32 seqRowHeapSize;
    u32 soundHeapSizeCopy;
    u32 seqRowHeapSizeCopy;
    u32 currentHeapSize;
    u32 value;

    gSndHeapSizeKind = heapSizeKind;
    switch (heapSizeKind) {
        case SND_HEAP_SIZE_LARGE:
            soundHeapSize = 0x36f3c;
            break;
        case SND_HEAP_SIZE_MEDIUM:
            soundHeapSize = 0x26a08;
            break;
        case SND_HEAP_SIZE_SMALL:
            soundHeapSize = 0x25a5c;
            break;
    }
    gLoadedSoundBanks = gLoadedSoundBanksAfterHeapCreate;
    ResetLoadedSoundSet(&gLoadedSoundSet);
    gSndHeap = NNS_SndHeapCreate((void *) buffer, soundHeapSize);
    seqRowHeapSize = 0;
    gCurrentSndHeap = NULL;
    buffer = buffer + soundHeapSize;
    switch (heapSizeKind) {
        case SND_HEAP_SIZE_LARGE:
            seqRowHeapSize = 0x6580;
            break;
        case SND_HEAP_SIZE_MEDIUM:
            seqRowHeapSize = 0x35a0;
            break;
        case SND_HEAP_SIZE_SMALL:
            seqRowHeapSize = 0x35a0;
            break;
    }
    CreateSeqRowHeap((void *) buffer, seqRowHeapSize);
    gSeqRowSndHeap = (NNSSndHeap *) buffer;
    value = buffer + seqRowHeapSize;
    currentHeapSize = (heapSizeKind == SND_HEAP_SIZE_LARGE ? 0xc8000 : 0xaf000) -
                      (heapSizeKind == SND_HEAP_SIZE_SMALL ? 0xaf000 : 0xc400);
    switch (heapSizeKind) {
        case SND_HEAP_SIZE_LARGE:
            soundHeapSizeCopy = 0x36f3c;
            break;
        case SND_HEAP_SIZE_MEDIUM:
            soundHeapSizeCopy = 0x26a08;
            break;
        case SND_HEAP_SIZE_SMALL:
            soundHeapSizeCopy = 0x25a5c;
            break;
    }
    seqRowHeapSizeCopy = 0;
    switch (heapSizeKind) {
        case SND_HEAP_SIZE_LARGE:
            seqRowHeapSizeCopy = 0x6580;
            break;
        case SND_HEAP_SIZE_MEDIUM:
            seqRowHeapSizeCopy = 0x35a0;
            break;
        case SND_HEAP_SIZE_SMALL:
            seqRowHeapSizeCopy = 0x35a0;
            break;
    }
    currentHeapSize = currentHeapSize - soundHeapSizeCopy - seqRowHeapSizeCopy;
    gCurrentSndHeap = NNS_SndHeapCreate((void *) value, currentHeapSize);
    value = 0;
    if (heapSizeKind == 1) {
        value = 1;
    }
    LoadInitialSndGroup(value);
}

void InitSound(void *buffer, u32 bufferSize, u32 useFileArchive) {
    u32 soundHeapSize;
    u32 seqRowHeapSize;
    SndHeapSizeKind heapSizeKind;
    s32 slotIndex;

    gSeqZeroLoopOn = 0;
    if (useFileArchive == 0) {
        heapSizeKind = SND_HEAP_SIZE_SMALL;
        switch (heapSizeKind) {
            case SND_HEAP_SIZE_LARGE:
                soundHeapSize = 0x36f3c;
                break;
            case SND_HEAP_SIZE_MEDIUM:
                soundHeapSize = 0x26a08;
                break;
            case SND_HEAP_SIZE_SMALL:
                soundHeapSize = 0x25a5c;
                break;
        }
        seqRowHeapSize = 0;
        switch (heapSizeKind) {
            case SND_HEAP_SIZE_LARGE:
                seqRowHeapSize = 0x6580;
                break;
            case SND_HEAP_SIZE_MEDIUM:
                seqRowHeapSize = 0x35a0;
                break;
            case SND_HEAP_SIZE_SMALL:
                seqRowHeapSize = 0x35a0;
                break;
        }
        bufferSize = bufferSize - soundHeapSize;
        gSndHeapSizeKind = SND_HEAP_SIZE_SMALL;
        bufferSize = bufferSize - seqRowHeapSize;
    }
    InitSoundSystem(buffer, bufferSize, useFileArchive != 0 ? gSoundDataSdatPath : 0);
    InitSoundRequestQueues();
    NNS_SndArcInitOnMemory(&gOnMemorySndArc, gOnMemorySdat);
    NNS_SndArcSetCurrent(&gFileSndArc);
    if (useFileArchive != 0) {
        LoadInitialSndArcs();
    } else {
        gLoadedSoundBanks = gLoadedSoundBanksAfterOnMemoryInit;
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
    InitSoundHandlePool(&gSoundHandlePool, gSoundHandlePoolEntries, 3, 8);
    NNS_SndHandleInit(&gChoisesSSeqHandle);
    NNS_SndHandleInit(&gSeqZeroAndSessionSeqHandle);
    NNS_SndHandleInit(&gMatchingEntrySeqHandle);
    NNS_SndSetMasterVolume(0x7f);
    NNS_SndSetMonoFlag(0);
    SetSoundFadeSteps(0x1e);
    gPlayerVolumeFade.mVolumePerFrameBeforeRaceStart = FX_Div(0x7f000, 0x46000);
    gPlayerVolumeFade.mVolumePerFrameAfterRaceStart = FX_Div(0x7f000, 0x3c000);
    gPlayerVolumeFade.mPlayerMaskBeforeRaceStart = SOUND_PLAYER_MASK_ALL;
    gPlayerVolumeFade.mPlayerMaskAfterRaceStart = SOUND_PLAYER_MASK_ALL_BUT_HIGHEST;
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

    if (gScenePlayers.mProgress != SCENE_PLAYERS_PROGRESS_RELEASED) {
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
        seqPlayer = gSeqZeroAndSessionSeqHandle;
        seqZeroPlaying = seqPlayer != NULL && seqPlayer->mSeqArcIndex == 0 && seqPlayer->mSeqNo == 0;
        if (seqZeroPlaying == FALSE) {
            NNS_SndArcSetCurrent(&gOnMemorySndArc);
            if (gSeqZeroAndSessionSeqHandle != NULL) {
                NNS_SndPlayerStopSeq(&gSeqZeroAndSessionSeqHandle, 0);
            }
            NNS_SndArcPlayerStartSeqArc(&gSeqZeroAndSessionSeqHandle, 0, 0);
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
    BOOL isRaceSceneNormalOrReplay;
    u32 raceKindMatches;
    NNSSndHeap *savedHeap;
    SoundRow soundRow;
    ScenePlayersSeqInfo scenePlayersSeqInfo;

    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT && GetCurrentSceneNumber() == 6) {
        return;
    }
    ClearSurfaceSoundIds();
    currentSceneNumber = GetCurrentSceneNumber();
    value = 0x69;
    isRaceSceneNormalOrReplay = FALSE;
    if (GetCurrentSceneNumber() == SCENE_RACE) {
        raceKindMatches = gRaceSetup->mRaceKind == RACE_KIND_NORMAL || gRaceSetup->mRaceKind == RACE_KIND_REPLAY;
        if (raceKindMatches != 0) {
            isRaceSceneNormalOrReplay = TRUE;
        }
    }
    if (isRaceSceneNormalOrReplay != FALSE) {
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
    sceneSoundRowIndex = GetSceneSoundRowIndex(currentSceneNumber, &soundRow);
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
        case SCENE_RACE:
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
                    SetSurfaceSoundIds(gOldLuigiAgbSurfaceSoundSetup.mRowIndex,
                                       gOldLuigiAgbSurfaceSoundSetup.mColumnIndex, &gOldLuigiAgbSurfaceSoundSetup);
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
                MissionSettings *mission = &gRaceSetup->mMissionSettings;
                switch (gRaceSetup->mMissionKind) {
                    case MISSION_KIND_COUNT_PENDING_WITH_SEQ:
                        gMissionRunCountSeqNo[0] = 0x1d7;
                        gMissionRunLimitSeqNo[0] = 0x1d7;
                        break;
                    case MISSION_KIND_COUNT_HITS:
                        gMissionRunCountSeqNo[0] = 0x1e0;
                        gMissionRunLimitSeqNo[0] = 0x1e1;
                        switch (mission->mMissionTableValue) {
                            case MISSION_NUMBER_DONKETU:
                            case MISSION_NUMBER_KING_ICE_DONKETU:
                                gMissionRunLimitSeqNo[0] = 0xff;
                                break;
                        }
                        break;
                    case MISSION_KIND_COUNT_SHAPE_ENTRIES:
                        gMissionRunCountSeqNo[0] = 0x1db;
                        gMissionRunLimitSeqNo[0] = 0x1dc;
                        break;
                    case MISSION_KIND_LAPS:
                    case MISSION_KIND_LAPS_FIRST_PLACE:
                        gMissionRunCountSeqNo[0] = 0xff;
                        gMissionRunLimitSeqNo[0] = 0xff;
                        break;
                    case MISSION_KIND_LAPS_MINI_TURBO_COUNT:
                        gMissionRunCountSeqNo[0] = 0x1dd;
                        gMissionRunLimitSeqNo[0] = 0x1de;
                        break;
                    case MISSION_KIND_COUNT_MAP_OBJECTS:
                        gMissionRunCountSeqNo[0] = 0x1dd;
                        gMissionRunLimitSeqNo[0] = 0x1de;
                        break;
                    case MISSION_KIND_LAPS_NO_LAP_PROGRESS:
                        break;
                }
            }
            { break; }
        case SCENE_MENU_1:
            if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                savedHeap = gCurrentSndHeap;
                if (gLoadedSoundBanks.mLoadMarker == LOADED_SOUND_BANKS_NONE ||
                    gLoadedSoundBanks.mBankMask != LOADED_SOUND_BANKS_MENU_SET) {
                    NNS_SndHeapClear(gSndHeap);
                    gLoadedSoundBanks.mLoadMarker = LOADED_SOUND_BANKS_NONE;
                    gLoadedSoundBanks.mBankMask = 0;
                    gCurrentSndHeap = gSndHeap;
                    if (NNS_SndArcLoadBank(0x2c, gSndHeap) != 0) {
                        if (NNS_SndArcLoadSeqArc(3, gCurrentSndHeap) != 0) {
                            gCurrentSndHeap = savedHeap;
                            gLoadedSoundBanks.mBankMask = LOADED_SOUND_BANKS_MENU_SET;
                            gLoadedSoundBanks.mLoadMarker = LOADED_SOUND_BANKS_LOADED;
                        }
                    }
                }
            }
            { break; }
        case SCENE_WIFI_MENU:
            savedHeap = gCurrentSndHeap;
            if (gLoadedSoundBanks.mLoadMarker == LOADED_SOUND_BANKS_NONE ||
                gLoadedSoundBanks.mBankMask != LOADED_SOUND_BANKS_MENU_SET) {
                NNS_SndHeapClear(gSndHeap);
                gLoadedSoundBanks.mLoadMarker = LOADED_SOUND_BANKS_NONE;
                gLoadedSoundBanks.mBankMask = 0;
                gCurrentSndHeap = gSndHeap;
                if (NNS_SndArcLoadBank(0x2c, gSndHeap) != 0) {
                    if (NNS_SndArcLoadSeqArc(3, gCurrentSndHeap) != 0) {
                        gCurrentSndHeap = savedHeap;
                        gLoadedSoundBanks.mBankMask = LOADED_SOUND_BANKS_MENU_SET;
                        gLoadedSoundBanks.mLoadMarker = LOADED_SOUND_BANKS_LOADED;
                    }
                }
            }
            { break; }
        case SCENE_TITLE:
            break;
    }
    scenePlayersSeqInfo.mUnk_00 = 0xff;
    scenePlayersSeqInfo.mSeqStartProgress = soundRow.mSeqStartProgress;
    scenePlayersSeqInfo.mSeqId = soundRow.mSeqId;
    InitVolumeFade();
    InitSceneSoundState(sceneSoundRowIndex & 0xff, scenePlayersSeqInfo, &gSceneSoundState);
    InitSoundFalloffsAndPlayingSounds();
    InitSceneSoundsNop();
    InitKartSoundQueue();
    ResetSoundRequestQueues();
    ResetSeqPlayerControl();
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        LoadSceneSoundSet(soundRow, 0);
    }
    if (currentSceneNumber != SCENE_MENU_1) {
        return;
    }
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        NNS_SndArcLoadBank(2, gCurrentSndHeap);
    }
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        return;
    }
    gSndHeapSavedState[0] = NNS_SndHeapSaveState(gCurrentSndHeap);
    if (GetCurrentSceneNumber() != SCENE_MENU_1) {
        return;
    }
    if (gMenuShared->mMenuEntryKind == MENU_ENTRY_MISSION_SELECT) {
        gScenePlayers.mSeqInfo.mSeqStartProgress = SCENE_PLAYERS_SEQ_START_UNMATCHED;
    }
}

void InitSceneSoundState(u32 sceneSoundRowIndex, ScenePlayersSeqInfo seqInfo, SceneSoundState *sceneSoundState) {
    sceneSoundState->mLapsDone = 0;
    NNS_SndHandleInit(&sceneSoundState->mKartStarSeq);
    sceneSoundState->mLastLapSeqState = SCENE_LAST_LAP_SEQ_NONE;
    sceneSoundState->mOnLastLap = 0;
    sceneSoundState->mKartStarSeqOn = 0;
    sceneSoundState->mRaceFrames = 0;
    sceneSoundState->mSceneFrames = 0;
    sceneSoundState->mRaceState = SCENE_RACE_STATE_BEFORE_START;
    sceneSoundState->mRankIndex = SCENE_RANK_INDEX_NONE;
    sceneSoundState->mRankIndexAtSeq = SCENE_RANK_INDEX_NONE;
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

    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        if (GetCurrentSceneNumber() == 6) {
            return;
        }
    }
    ResetRaceEndSeqState();
    gRaceSoundKind = 0;
    SoundNopWrapper(&gRaceSoundKind);
    flag = 0;
    gPlayerVolumeFade.mVolume = 0;
    gPlayerVolumeFade.mTargetVolumeBeforeRaceStart = SOUND_VOLUME_MAX;
    gPlayerVolumeFade.mTargetVolumeAfterRaceStart = SOUND_VOLUME_MAX;
    gPlayerVolumeFade.mRaceStarted = 0;
    if (GetCurrentSceneNumber() == SCENE_RACE) {
        raceKindMatches = gRaceSetup->mRaceKind == RACE_KIND_NORMAL || gRaceSetup->mRaceKind == RACE_KIND_REPLAY;
        if (raceKindMatches != 0) {
            flag = 1;
        }
    }
    if (flag != 0) {
        SetSoundMode(&gSoundModeHolder, SCENE_SOUND_MODE_PLAYING);
        gRaceSoundKind = 1;
        StartScenePlayersSeqNo(&gScenePlayers, GetSeqRowSceneSeq(), NULL);
        gBeforeStartSeqStarted = 0;
        value = 0xffff;
        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
            switch (gRaceSetup->mMissionTableValue) {
                case MISSION_NUMBER_DONKETU:
                    value = 0x20e;
                    break;
                case MISSION_NUMBER_BOMB_KING:
                    value = 0x235;
                    break;
                case MISSION_NUMBER_HANACHAN:
                    value = 0x246;
                    break;
                case MISSION_NUMBER_KING_TERESA:
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
            NNS_SndPlayerStopSeq(&gSndHandleSlots[7], 0);
            seqHandle = &gSndHandleSlots[7];
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
            gBeforeStartSeqStarted = 1;
        }
        if (gRaceSetup->mMode != MODE_BATTLE) {
            SetLapProgressSoundGaps(gCourseMap->mCheckpointSum);
            gSceneSoundState.mLapCount = GetLapCount();
        }
    } else {
        if (GetCurrentSceneNumber() == SCENE_RACE) {
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
                gPlayerVolumeFade.mVolume = TO_FIXED12(SOUND_VOLUME_MAX);
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
            gPlayerVolumeFade.mVolume = TO_FIXED12(SOUND_VOLUME_MAX);
            SetSoundMode(&gSoundModeHolder, SCENE_SOUND_MODE_PLAYING);
            gRaceSoundKind = 0;
        }
    }
    StartScenePlayersForScene(&gScenePlayers);
}

void StartRaceSounds(void) {
    s32 slotIndex;
    NNSSndSeqPlayer **handle;

    gSceneSoundState.mRaceState = SCENE_RACE_STATE_RUNNING;
    StartScenePlayersForRace(&gScenePlayers);
    gPlayerVolumeFade.mRaceStarted = 1;
    if (gBeforeStartSeqStarted != 0) {
        NNS_SndPlayerStopSeq(&gSndHandleSlots[7], 0x14);
    }
    if (gRaceSetup->mCourseId != COURSE_ID_STADIUM) {
        return;
    }
    for (slotIndex = 7; slotIndex < 12; slotIndex++) {
        NNS_SndPlayerStopSeq(OFFSET_PTR(NNSSndSeqPlayer *, gSndHandleSlots, slotIndex * sizeof(NNSSndSeqPlayer *)), 0);
    }
    handle = &gSndHandleSlots[7];
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
    if (gSceneSoundState.mRaceState != SCENE_RACE_STATE_RUNNING) {
        return;
    }
    gSceneSoundState.mKartStarSeqOn = 1;
    if ((gSceneSoundState.mLastLapSeqState & 1) != 0) {
        gKartStarSeqStartPending = 1;
        return;
    }
    NNS_SndPlayerSetTrackMuteEx(&gScenePlayers.mSeqPlayer, 0xffff, 1);
    StartScenePlayersSeqNo(&gScenePlayers, 0x49, &gSceneSoundState.mKartStarSeq);
}

void StopKartStarSeq(void) {
    NNS_SndPlayerSetTrackMuteEx(&gScenePlayers.mSeqPlayer, 0xffff, 0);
    NNS_SndPlayerStopSeq(&gSceneSoundState.mKartStarSeq, 0);
    if (gSceneSeqRestartAfterStar != 0) {
        if (gSceneSoundState.mRaceState == SCENE_RACE_STATE_RUNNING) {
            StartScenePlayersSeq(&gScenePlayers);
            NNS_SndPlayerSetVolume(&gScenePlayers.mSeqPlayer, FROM_FIXED12(gVolumeFade.mVolume));
            NNS_SndPlayerSetTempoRatio(&gScenePlayers.mSeqPlayer, 0x12c);
            SetRestartedSeqPitchFlag();
        }
        gSceneSeqRestartAfterStar = 0;
    }
    gSceneSoundState.mKartStarSeqOn = 0;
}

void EndRaceSounds(void) {
    u32 fadeSteps;
    s32 slotIndex;
    s32 poolIndex;
    u8 *playerCursor;

    gSceneSoundState.mRaceState = SCENE_RACE_STATE_ENDED;
    StopScenePlayersSeq(&gScenePlayers, GetEndRaceFadeSteps());
    NNS_SndPlayerSetTrackMuteEx(&gScenePlayers.mSeqPlayer, 0xffff, 0);
    NNS_SndPlayerStopSeq(&gSceneSoundState.mKartStarSeq, 0);
    if (gSceneSeqRestartAfterStar != 0) {
        if (gSceneSoundState.mRaceState == SCENE_RACE_STATE_RUNNING) {
            StartScenePlayersSeq(&gScenePlayers);
            NNS_SndPlayerSetVolume(&gScenePlayers.mSeqPlayer, FROM_FIXED12(gVolumeFade.mVolume));
            NNS_SndPlayerSetTempoRatio(&gScenePlayers.mSeqPlayer, 0x12c);
            SetRestartedSeqPitchFlag();
        }
        gSceneSeqRestartAfterStar = 0;
    }
    gSceneSoundState.mKartStarSeqOn = 0;
    if (gSoundModeHolder.mMode == SCENE_SOUND_MODE_PLAYING) {
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
    if (GetCurrentSceneNumber() == SCENE_RACE) {
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
        gSceneSoundState.mLastLapSeqState = SCENE_LAST_LAP_SEQ_PLAYING;
        gSceneSoundState.mOnLastLap = 1;
        StopScenePlayersSeq(&gScenePlayers, 0);
        if (gSceneSoundState.mKartStarSeq != NULL) {
            NNS_SndPlayerSetTrackMuteEx(&gSceneSoundState.mKartStarSeq, 0xffff, 1);
        }
        StartScenePlayersSeqNo(&gScenePlayers, 0x3e, NULL);
        gSceneSoundState.mLastLapSeqState = SCENE_LAST_LAP_SEQ_PLAYING;
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
    seqHandle = &gSndHandleSlots[7];
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
void SetSceneSoundRank(u8 rankIndex) {
    BOOL flag;
    BOOL raceKindMatches;
    u32 slotSeqPlaying;
    u32 shouldStartSeq;
    u32 seqNo;
    s32 slotIndex;
    NNSSndSeqPlayer *seqPlayer;
    NNSSndSeqPlayer **seqHandle;

    flag = FALSE;
    if (GetCurrentSceneNumber() == SCENE_RACE) {
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
    if (gSceneSoundState.mRaceFrames <= SCENE_RANK_START_DELAY_FRAMES) {
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
            slotSeqPlaying =
                seqPlayer != NULL && seqPlayer->mSeqArcIndex == PINBALL_COURSE_SEQ_ARC_INDEX && seqPlayer->mSeqNo == 0;
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
                NNS_SndPlayerStopSeq(&gSndHandleSlots[7], 0);
                seqHandle = &gSndHandleSlots[7];
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
        case SCENE_RACE_STATE_RUNNING:
            gSceneSoundState.mRaceFrames++;
            if (gSceneSoundState.mRaceFrames == SCENE_RACE_SEQ_START_FRAMES) {
                StartScenePlayersSeq(&gScenePlayers);
                NNS_SndPlayerSetVolume(&gScenePlayers.mSeqPlayer, FROM_FIXED12(gVolumeFade.mVolume));
            }
            volumeFade = &gPlayerVolumeFade;
            tableRow = volumeFade->mRaceStarted;
            if (tableRow == 1) {
                volumeFade->mVolumePerFrame = gPlayerVolumeFade.mVolumePerFrames[tableRow];
                steppedVolume = StepValueTowardTarget(volumeFade, gPlayerVolumeFade.mTargetVolumes[tableRow]);
                if (steppedVolume != -1) {
                    playerMask = gPlayerVolumeFade.mPlayerMasks[tableRow];
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
        case SCENE_RACE_STATE_ENDED:
            UpdateRaceEndSeq();
            break;
    }
    if (gRaceSetup->mMode != MODE_BATTLE) {
        sceneSeqHandle = &gScenePlayers.mSeqPlayer;
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
            if (++gSceneSoundState.mRankSeqFrames >= SCENE_RANK_SEQ_FRAMES) {
                gSceneSoundState.mRankSeqFrames = -1;
            }
        }
        if (gSceneSoundState.mLastLapSeqState == SCENE_LAST_LAP_SEQ_PLAYING && sceneSeqHandle[0] == NULL) {
            gSceneSoundState.mLastLapSeqState = SCENE_LAST_LAP_SEQ_NONE;
            if (gKartStarSeqStartPending != 0 && gSceneSoundState.mKartStarSeqOn == 1) {
                if (gSceneSoundState.mRaceState == SCENE_RACE_STATE_RUNNING) {
                    gSceneSoundState.mKartStarSeqOn = 1;
                    if ((gSceneSoundState.mLastLapSeqState & 1) == 0) {
                        NNS_SndPlayerSetTrackMuteEx(&gScenePlayers.mSeqPlayer, 0xffff, 1);
                        StartScenePlayersSeqNo(&gScenePlayers, 0x49, &gSceneSoundState.mKartStarSeq);
                    }
                }
                gKartStarSeqStartPending = 0;
                gSceneSeqRestartAfterStar = 1;
            } else if (gSceneSoundState.mKartStarSeq != NULL) {
                NNS_SndPlayerSetTrackMuteEx(&gSceneSoundState.mKartStarSeq, 0xffff, 0);
                gSceneSeqRestartAfterStar = 1;
            } else if (gSceneSoundState.mRaceState == SCENE_RACE_STATE_RUNNING) {
                StartScenePlayersSeq(&gScenePlayers);
                NNS_SndPlayerSetVolume(&gScenePlayers.mSeqPlayer, FROM_FIXED12(gVolumeFade.mVolume));
                NNS_SndPlayerSetTempoRatio(&gScenePlayers.mSeqPlayer, 0x12c);
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
            if (gSceneSoundState.mSceneFrames == SCENE_COURSE_SEQ_START_FRAMES) {
                seqNo = 0x1bc;
            }
            break;
        case COURSE_ID_RIDGE:
            if (gSceneSoundState.mSceneFrames == SCENE_COURSE_SEQ_START_FRAMES) {
                seqNo = 0x1a6;
            }
            break;
        case COURSE_ID_GARDEN:
            if (gSceneSoundState.mSceneFrames == SCENE_COURSE_SEQ_START_FRAMES) {
                seqNo = 0x1a5;
            }
            break;
        case COURSE_ID_MANSION:
            if (gSceneSoundState.mSceneFrames == SCENE_COURSE_SEQ_START_FRAMES) {
                seqNo = 0x126;
            }
            break;
        case COURSE_ID_AIRSHIP:
            switch (gSceneSoundState.mSceneFrames) {
                case SCENE_COURSE_SEQ_START_FRAMES:
                    seqNo = 0x1d2;
                    break;
                case SCENE_AIRSHIP_SEQ_STOP_FRAMES:
                    NNS_SndPlayerStopSeq(&gSndHandleSlots[7], 0x3c);
                    break;
                case SCENE_AIRSHIP_SEQ_RESTART_FRAMES:
                    seqNo = 0x1d2;
                    break;
            }
            { break; }
        case COURSE_ID_KOOPA:
            if (gSceneSoundState.mSceneFrames == SCENE_COURSE_SEQ_START_FRAMES) {
                seqNo = 0x1aa;
            }
            break;
        case COURSE_ID_CLOCK:
            if (gSceneSoundState.mSceneFrames == SCENE_COURSE_SEQ_START_FRAMES) {
                seqNo = 0x192;
            }
            break;
        case COURSE_ID_MARIO:
            if (gSceneSoundState.mSceneFrames == SCENE_COURSE_SEQ_START_FRAMES) {
                seqNo = 0x19b;
            }
            break;
        case COURSE_ID_OLD_NOKO_SFC:
            if (gSceneSoundState.mSceneFrames == SCENE_COURSE_SEQ_START_FRAMES) {
                seqNo = 0x112;
            }
            break;
        case COURSE_ID_BEACH:
            if (gSceneSoundState.mSceneFrames == SCENE_COURSE_SEQ_START_FRAMES) {
                seqNo = 0x112;
            }
            break;
        case COURSE_ID_OLD_MOMO_64:
            if (gSceneSoundState.mSceneFrames == SCENE_COURSE_SEQ_START_FRAMES) {
                seqNo = 0x12b;
            }
            break;
        case COURSE_ID_OLD_HYUDORO_64:
            if (gSceneSoundState.mSceneFrames == SCENE_COURSE_SEQ_START_FRAMES) {
                seqNo = 0x19a;
            }
            break;
        case COURSE_ID_OLD_LUIGI_AGB:
            if (gSceneSoundState.mSceneFrames == SCENE_COURSE_SEQ_START_FRAMES) {
                seqNo = 0x1d5;
            }
            break;
        case COURSE_ID_RAINBOW:
            if (gSceneSoundState.mSceneFrames == SCENE_COURSE_SEQ_START_LATE_FRAMES) {
                seqNo = 0x1ba;
            }
            break;
        case COURSE_ID_TOWN:
            if (gSceneSoundState.mSceneFrames == SCENE_COURSE_SEQ_START_LATE_FRAMES) {
                seqNo = 0x199;
            }
            break;
    }
    if (seqNo == 0xffff) {
        return;
    }
    NNS_SndPlayerStopSeq(&gSndHandleSlots[7], 0);
    seqHandle = &gSndHandleSlots[7];
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
        volumeFade->mVolumePerFrame = gPlayerVolumeFade.mVolumePerFrames[tableRow];
        steppedVolume = StepValueTowardTarget(volumeFade, gPlayerVolumeFade.mTargetVolumes[tableRow]);
        if (steppedVolume != -1) {
            playerMask = gPlayerVolumeFade.mPlayerMasks[tableRow];
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
    if (GetCurrentSceneNumber() == SCENE_RACE) {
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
    } else if (GetCurrentSceneNumber() == SCENE_LOGO) {
        if (gSceneSoundState.mSceneFrames == SCENE_LOGO_SEQ_STOP_FRAMES) {
            NNS_SndPlayerStopSeq(&gScenePlayers.mSeqPlayer, 0x1b);
        }
    } else if (GetCurrentSceneNumber() == SCENE_MENU_1 || GetCurrentSceneNumber() == SCENE_WIFI_MENU) {
        if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
            UpdateSeqQueue();
        }
    } else if (GetCurrentSceneNumber() == SCENE_EMBLEM) {
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

    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT && GetCurrentSceneNumber() == 6) {
        return;
    }
    gPlayerVolumeFade.mTargetVolumeBeforeRaceStart = 0;
    gPlayerVolumeFade.mRaceStarted = 0;
    ScenePlayersNop(&gScenePlayers);
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
    NNS_SndPlayerStopSeq(&gSeqZeroAndSessionSeqHandle, 13);
    NNS_SndPlayerStopSeq(&gMatchingEntrySeqHandle, 13);
    gSeqZeroLoopOn = 0;
}

void StopSceneSoundsAtOnce(void) {
    s32 slotIndex;
    s32 poolIndex;
    u8 *playerCursor;
    SoundHandlePool *playerTable;

    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT && GetCurrentSceneNumber() == 6) {
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
    NNS_SndPlayerStopSeq(&gSeqZeroAndSessionSeqHandle, 0);
    NNS_SndPlayerStopSeq(&gMatchingEntrySeqHandle, 0);
}

void StopSceneSeqWithFadeSteps(void) {
    u32 fadeSteps;
    fadeSteps = GetSoundFadeSteps();
    NNS_SndPlayerStopSeq(&gScenePlayers.mSeqPlayer, fadeSteps);
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
    if (gSceneSoundState.mRaceState == SCENE_RACE_STATE_ENDED) {
        return;
    }
    SetSoundMode(&gSoundModeHolder, SCENE_SOUND_MODE_PAUSED);
    if (gSceneSoundState.mLastLapSeqState == SCENE_LAST_LAP_SEQ_PLAYING) {
        gSceneSoundState.mLastLapSeqState = SCENE_LAST_LAP_SEQ_PAUSED;
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
    if (gSceneSoundState.mRaceState == SCENE_RACE_STATE_ENDED) {
        return;
    }
    RestoreSavedSoundMode(&gSoundModeHolder);
    if (gSceneSoundState.mLastLapSeqState == SCENE_LAST_LAP_SEQ_PAUSED) {
        gSceneSoundState.mLastLapSeqState = SCENE_LAST_LAP_SEQ_PLAYING;
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

    seqNo = gChoisesSValueSeqNos[valueIndex];
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

    gMissionRunSelMode = mode;
    if (mode - 1 > 1) {
        return;
    }
    seqNo = (mode == 1) ? 0x47 : 0x48;
    NNS_SndHeapLoadState(gCurrentSndHeap, gSndHeapSavedState[0]);
    NNS_SndHeapGetCurrentLevel(gCurrentSndHeap);
    NNS_SndArcLoadSeq(seqNo, gCurrentSndHeap);
    NNS_SndPlayerStopSeq(&gScenePlayers.mSeqPlayer, 2);
    StartSeqAtVolume(seqNo, 0x7f, &gSndHandleSlots[1]);
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
    if (gMissionRunSelMode - 1 <= 1) {
        NNS_SndPlayerStopSeq(&gSndHandleSlots[1], fadeSteps);
    }
    if (mode == 3) {
        NNS_SndPlayerStopSeq(&gScenePlayers.mSeqPlayer, fadeSteps);
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
    gMissionRunSelMode = mode;
    gMissionRunMSselStep32Count = 0;
    gMissionRunMSselStep0Count = 0;
    gMissionRunMSselSeqIndex = 0xff;
    if (mode != 3) {
        return;
    }
    switch (missionRow) {
        case MISSION_TABLE_ROW_DONKETU:
            gMissionRunMSselSeqIndex = 1;
            bankNo = SOUND_BANK_MISSION_DONKETU;
            break;
        case MISSION_TABLE_ROW_IWANTE:
            gMissionRunMSselSeqIndex = 2;
            bankNo = SOUND_BANK_MISSION_IWANTE;
            break;
        case MISSION_TABLE_ROW_KURIKING:
            gMissionRunMSselSeqIndex = 3;
            bankNo = SOUND_BANK_MISSION_KURIKING;
            break;
        case MISSION_TABLE_ROW_KING_TERESA:
            gMissionRunMSselSeqIndex = 4;
            bankNo = SOUND_BANK_MISSION_KING_TERESA;
            break;
        case MISSION_TABLE_ROW_BOMB_KING:
            gMissionRunMSselSeqIndex = 5;
            bankNo = SOUND_BANK_MISSION_BOMB_KING;
            break;
        case MISSION_TABLE_ROW_KING_ICE_DONKETU:
            gMissionRunMSselSeqIndex = 6;
            bankNo = SOUND_BANK_MISSION_DONKETU;
            break;
        case MISSION_TABLE_ROW_HANACHAN:
            gMissionRunMSselSeqIndex = 7;
            bankNo = 0x17;
            break;
    }
    NNS_SndHeapLoadState(gCurrentSndHeap, gSndHeapSavedState[0]);
    NNS_SndHeapGetCurrentLevel(gCurrentSndHeap);
    NNS_SndArcLoadBank(bankNo, gCurrentSndHeap);
    NNS_SndArcLoadBank(0x2a, gCurrentSndHeap);
    NNS_SndArcLoadSeqArc(4, gCurrentSndHeap);
}

void UpdateMissionRunMSselSounds(s32 blendFrame) {
    s32 trackVolume;
    u32 startsBankSeq;
    s32 stepCount;
    if (gMissionRunSelMode == 0) {
        if (gScenePlayers.mSeqPlayer != NULL) {
            return;
        }
        StartScenePlayersSeq(&gScenePlayers);
        return;
    }
    if (blendFrame != 0 && blendFrame != 0x32) {
        return;
    }
    startsBankSeq = 0;
    trackVolume = 0x78;
    stepCount = (blendFrame == 0x32) ? gMissionRunMSselStep32Count : gMissionRunMSselStep0Count;
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
    if (blendFrame == 0x32) {
        NNSSndSeqPlayer **seqHandle = &gSndHandleSlots[1];
        if (*seqHandle != NULL) {
            NNS_SndPlayerStopSeq(seqHandle, 0);
        }
        NNS_SndArcPlayerStartSeqArc(seqHandle, 4, 0);
        if (*seqHandle != NULL) {
            NNS_SndPlayerSetTrackVolume(seqHandle, gSeqTrackMask, trackVolume & 0xff);
        }
        gMissionRunMSselStep32Count++;
        return;
    }
    if (blendFrame != 0) {
        return;
    }
    if (startsBankSeq != 0) {
        u16 seqIndex = gMissionRunMSselSeqIndex;
        if (seqIndex != 0xff) {
            NNSSndSeqPlayer **bankSeqHandle = &gSndHandleSlots[2];
            if (*bankSeqHandle != NULL) {
                NNS_SndPlayerStopSeq(bankSeqHandle, 0);
            }
            NNS_SndArcPlayerStartSeqArc(bankSeqHandle, 4, seqIndex);
        }
    }
    gMissionRunMSselStep0Count++;
}

void StopMissionRunMSselSeqsWithSteps(u32 unused, u32 fadeSteps) {
    NNS_SndPlayerStopSeq(&gSndHandleSlots[1], fadeSteps);
    NNS_SndPlayerStopSeq(&gSndHandleSlots[2], fadeSteps);
}

void StopMissionRunMSselSeqsAtOnce(void) {
    NNS_SndPlayerStopSeq(&gSndHandleSlots[1], 0);
    NNS_SndPlayerStopSeq(&gSndHandleSlots[2], 0);
}
