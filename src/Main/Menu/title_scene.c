#include "Main/Menu/title_scene.h"

#include "Main/System/heap.h"
#include "Main/Scene/display_settings.h"
#include "Main/Race/random_pick.h"
#include "Main/Scene/run_scene_connection.h"
#include "Main/Graphics/disp_cap.h"
#include "Main/Kart/kart_appear.h"
#include "Main/Menu/title_states.h"
#include "Main/Graphics/font_glyph_text.h"
#include "Main/Race/race_scene_callbacks.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "archive_memory_load.h"
#include "Main/System/input_slots.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/System/backup_net_camera_work.h"
#include "cpu_copy_fill.h"
#include "clock_chip_access.h"
#include "Main/Race/race_progress_kart.h"
#include "Main/Menu/title_bg.h"
#include "Main/Menu/title_registers.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Course/course_map_shapes.h"
#include "Main/Race/race_setup_input.h"
#include "Main/System/wvr_state.h"
#include "Main/System/key_recording.h"
#include "Main/System/heap_call.h"
#include "Main/Race/race.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "01/Race/mission_run_state.h"
#include "Main/Race/race_end_condition.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

SceneCallbacks gTitleSceneCallbacks = {
    InitTitleScene, UpdateTitleScene, ReleaseTitleScene, WriteTitleSceneRegistersCallback, NULL, NULL, 0xa, 0xa, 0};

void FinishKartInCourseMapMissionEndShape(Vec3 *position, u32 kartIndex) {
    s32 shapeFlag;
    if (IsPosInCourseMapMissionEndShape(position, &shapeFlag) == 0) {
        return;
    }
    if (shapeFlag != 0) {
        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
            AddMissionRunCountForShapeEntry();
        }
        if (gRaceSetup->mMode != MODE_MISSION_RUN) {
            return;
        }
        FinishRaceProgressKartWithEndKind(kartIndex, RACE_END_KIND_GOAL);
    } else {
        FinishRaceProgressKartWithEndKind(kartIndex, RACE_END_KIND_NOT_ENDED);
    }
}

BOOL IsFramesSinceFinishPastWait(void) {
    return gRaceProgress->mFramesSinceFinish > gRaceSetup->mFinishWaitFrameCount;
}

u32 ShouldEndReplayRace(void) {
    u32 framesSinceEntryEnd;
    s32 entryIndex = gRaceSetup->mEntryIndex;
    if (entryIndex == -1) {
        return 0;
    }
    if (gRaceProgress->mHeader.mClockMinute >= REPLAY_END_CLOCK_MINUTE) {
        return 1;
    }
    if (IsKeyRecordingPlaybackNearBufferEnd(&gInputSlots[entryIndex].mKeyRecording) != FALSE) {
        return 1;
    }
    if (TryGetRaceUpdateFramesSinceEntryEnd(&framesSinceEntryEnd) != 0) {
        if (framesSinceEntryEnd > 0x384) {
            return 1;
        }
    }
    return 0;
}

void InitTitleScene(void) {
    GetHeap(GetCurrentHeapCall());
    ClearLcdcBankAndStartWvrAndWait();
    CreateTitleScene();
    ResetInputSlots();
}

void ReleaseTitleScene(void) {
    u32 unused;
    ReleaseTitleSceneObject();
}

void WriteTitleSceneRegistersCallback(void) {
    u32 unused;
    WriteTitleSceneRegisters();
}

void UpdateTitleScene(s32 flag) {
    PrepareDisplayFrame();
    AdvanceTitleStates(flag);
}

u32 RunTitleScene(SceneNumbers *sceneNumbers) {
    SceneCallbacks callbacks = gTitleSceneCallbacks;
    RunScene(sceneNumbers, &callbacks);
    return 0;
}

void GetClockDateOrDefault(s32 *date) {
    if (RTC_GetDate((RTCDate *) date) != 0) {
        date[0] = 5;
        date[1] = 1;
        date[2] = 1;
    }
}

void GetClockTimeOrZero(RTCTime *time) {
    if (RTC_GetTime(time) != 0) {
        time->mHour = 0;
        time->mMinute = 0;
        time->mSecond = 0;
    }
}

void CopyCourseGhostToSlotGhost(GhostRecord *courseGhost, SlotGhostRecord *slotGhost) {
    MI_CpuCopy8(courseGhost, slotGhost, sizeof(GhostRecordHead));
    MI_CpuCopy8(courseGhost->mKeyRecordingBuffer, slotGhost->mKeyRecordingBuffer,
                sizeof(slotGhost->mKeyRecordingBuffer));
    if (gBackupBuffers->mEmblemRecord->mFilled != 0 && gBackupBuffers->mFirstBlock->mEmblemOff == 0) {
        MI_CpuCopy8(gBackupBuffers->mEmblemRecord->mEmblemData, slotGhost->mEmblem, sizeof(slotGhost->mEmblem));
        slotGhost->mHead.mHasEmblem = 1;
    } else {
        MI_CpuFill8(slotGhost->mEmblem, 0, sizeof(slotGhost->mEmblem));
        slotGhost->mHead.mHasEmblem = 0;
    }
    slotGhost->mHead.mLowestGrandPrixRecordValue = GetLowestGrandPrixRecordValue();
}

#pragma thumb on

CharacterKartPicks *CreateCharacterKartPicks(void *heap) {
    CharacterKartPicks *picks;
    void *kartAppear;
    picks = HeapAlloc(heap, sizeof(CharacterKartPicks));
    kartAppear = CreateKartAppear(heap);
    picks->mKartAppear = kartAppear;
    InitCharacterKartPicks(picks);
    return picks;
}

void InitCharacterKartPicks(CharacterKartPicks *picks) {
    u8 entryIndex;
    picks->mKartGivenBits = 0;
    picks->mCharacterGivenBits = 0;
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        picks->mCharacterIndices[entryIndex] = -1;
        picks->mKartIndices[entryIndex] = -1;
    }
}

void SetGivenCharacter(CharacterKartPicks *picks, u32 entryIndex, u32 characterIndex) {
    BIT_SET(picks->mCharacterGivenBits, entryIndex);
    picks->mCharacterIndices[entryIndex] = characterIndex;
}

void SetGivenKart(CharacterKartPicks *picks, u32 entryIndex, u32 kartIndex) {
    BIT_SET(picks->mKartGivenBits, entryIndex);
    picks->mKartIndices[entryIndex] = kartIndex;
}
