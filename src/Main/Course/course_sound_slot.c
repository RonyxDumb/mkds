#include "Main/Course/course_sound_slot.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Sound/sound_handle_slots_and_other_kart_falloff.h"
#include "sound_player_control.h"
#include "sound_archive_load_result.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Menu/menu_screens_work.h"
#include "Main/Sound/sound_system.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"

CourseSoundSlot gCourseSoundSlots[2];
u32 gCourseSoundTableIndex = 0xffff;
CourseSoundTableRow gCourseSoundTable[5] = {
    {{0x01b1, 0x01b2, 0x01b3, 0x01b4, 0x01b5, 0xffff, 0xffff, 0xffff}},
    {{0x1000, 0x1001, 0x1002, 0x1003, 0x0198, 0x0197, 0xffff, 0xffff}},
    {{0x1000, 0x1001, 0x1002, 0x1003, 0x01ab, 0xffff, 0xffff, 0xffff}},
    {{PINBALL_COURSE_SEQ_ARC_INDEX, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff}},
    {{0x01c2, 0x01c3, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff}},
};

void SelectCourseSoundTable(u32 courseId) {
    u32 tableIndex;
    s32 slotIndex;
    s32 entryIndex;
    u32 volumeHandle;
    u32 groupValue;

    tableIndex = 0xffff;
    switch (courseId) {
        case COURSE_ID_RAINBOW:
            tableIndex = COURSE_SOUND_TABLE_RAINBOW;
            break;
        case COURSE_ID_TOWN:
            tableIndex = COURSE_SOUND_TABLE_TOWN;
            break;
        case COURSE_ID_KOOPA:
            tableIndex = COURSE_SOUND_TABLE_KOOPA;
            break;
        case COURSE_ID_PINBALL:
            tableIndex = COURSE_SOUND_TABLE_PINBALL;
            break;
        case COURSE_ID_STADIUM:
            tableIndex = COURSE_SOUND_TABLE_STADIUM;
            break;
    }
    gCourseSoundTableIndex = tableIndex;
    if (tableIndex != 0xffff) {
        slotIndex = 0;
        InitCourseSoundSlot(gCourseSoundSlots, 3, slotIndex);
        InitCourseSoundSlot(&gCourseSoundSlots[1], 3, slotIndex);
        for (; slotIndex < 2; slotIndex++) {
            groupValue = (slotIndex == 0 ? 0x1000 : 0x2000);
            for (entryIndex = 0; entryIndex < 8; entryIndex++) {
                if (gCourseSoundTable[tableIndex].mEntries[entryIndex] == groupValue) {
                    InitCourseSoundSlot(&gCourseSoundSlots[slotIndex], 0, entryIndex);
                    break;
                }
            }
        }
    }
    volumeHandle = 0;
    if (tableIndex == COURSE_SOUND_TABLE_TOWN && gRaceSetup->mMode != MODE_MISSION_RUN) {
        volumeHandle = 3;
    }
    gCourseSoundSlots[0].mPreviousVolumeHandle = volumeHandle;
    gCourseSoundSlots[0].mVolumeHandle = volumeHandle;
}

void ApplyCourseSoundTableEntry(s32 entryIndex) {
    u16 tableValue;
    u16 lowBits;
    u16 slotIndex;
    NNSSndSeqPlayer **handle;

    tableValue = gCourseSoundTable[gCourseSoundTableIndex].mEntries[entryIndex];
    lowBits = tableValue & 0xfff;
    switch (gCourseSoundTableIndex) {
        case COURSE_SOUND_TABLE_PINBALL:
            if (tableValue == PINBALL_COURSE_SEQ_ARC_INDEX) {
                handle = GetSndHandles();
                if (*handle != NULL) {
                    NNS_SndPlayerStopSeq(handle, 0);
                }
                handle = GetSndHandleSlot(7);
                if (*handle != NULL) {
                    NNS_SndPlayerStopSeq(handle, 0);
                }
            };
            break;
        case COURSE_SOUND_TABLE_STADIUM:
            StopSndHandleSlots7To11();
            break;
    }
    if (tableValue < 0xfff) {
        handle = GetSndHandleSlot(entryIndex < 5 ? entryIndex + 7 : entryIndex + 2);
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
        NNS_SndArcPlayerStartSeqArc(handle, 0, tableValue);
        return;
    }
    if (lowBits >= 4) {
        return;
    }
    slotIndex = ((tableValue & 0xf000) >> 12) - 1;
    entryIndex = entryIndex - gCourseSoundSlots[slotIndex].mFirstTableIndex;
    gCourseSoundSlots[slotIndex].mPreviousVolumeHandle = gCourseSoundSlots[slotIndex].mVolumeHandle;
    gCourseSoundSlots[slotIndex].mVolumeHandle = entryIndex;
}

BOOL StartCourseSoundAtVolume(s32 slotIndex, u32 soundId) {
    NNSSndSeqPlayer **handle;
    u32 volumeHandle;
    u8 trackVolume;
    u32 ok;

    if (slotIndex == 0) {
        handle = GetSndHandleSlot(0xa);
    } else {
        handle = GetSndHandleSlot(0xb);
    }
    volumeHandle = gCourseSoundSlots[slotIndex].mVolumeHandle;
    if (volumeHandle == 0) {
        trackVolume = 0;
        ok = 0;
    } else {
        trackVolume = gCourseSoundSlots[slotIndex].mVolumes[volumeHandle - 1];
        ok = 1;
    }
    if (ok != 0) {
        if ((gRaceSoundKind & 1) != 0) {
            if (gSoundModeHolder.mSeqStartEnabled != 0) {
                if (*handle != NULL) {
                    NNS_SndPlayerStopSeq(handle, 0);
                }
                if (*handle != NULL) {
                    NNS_SndPlayerStopSeq(handle, 0);
                }
                NNS_SndArcPlayerStartSeqArc(handle, 0, soundId);
            }
        }
        if (*handle != NULL) {
            SetSndHandleTrackVolume(handle, trackVolume);
        }
    }
    return ok;
}

BOOL UpdateCourseSound(u32 slotIndex, u32 soundId) {
    NNSSndSeqPlayer **handle;
    u32 volumeHandle;
    u8 trackVolume;
    u32 ok;

    if (slotIndex == 0) {
        handle = GetSndHandleSlot(0xa);
    } else {
        handle = GetSndHandleSlot(0xb);
    }
    volumeHandle = gCourseSoundSlots[slotIndex].mVolumeHandle;
    if (volumeHandle == 0) {
        trackVolume = 0;
        ok = 0;
    } else {
        trackVolume = gCourseSoundSlots[slotIndex].mVolumes[volumeHandle - 1];
        ok = 1;
    }
    if (ok != 0) {
        if (*handle == NULL) {
            if ((gRaceSoundKind & 1) != 0) {
                if (gSoundModeHolder.mSeqStartEnabled != 0) {
                    if (*handle != NULL) {
                        NNS_SndPlayerStopSeq(handle, 0);
                    }
                    if (*handle != NULL) {
                        NNS_SndPlayerStopSeq(handle, 0);
                    }
                    NNS_SndArcPlayerStartSeqArc(handle, 0, soundId);
                }
            }
            SetSndHandleTrackVolume(handle, trackVolume);
        } else if (*handle != NULL && gCourseSoundSlots[slotIndex].mPreviousVolumeHandle != volumeHandle) {
            SetSndHandleTrackVolume(handle, trackVolume);
        }
    } else {
        NNS_SndPlayerStopSeq(handle, 0xa);
    }
    return ok;
}

void InitCourseSoundSlot(CourseSoundSlot *slot, u32 volumeHandle, u32 firstTableIndex) {
    slot->mPreviousVolumeHandle = volumeHandle;
    slot->mVolumeHandle = volumeHandle;
    slot->mFirstTableIndex = firstTableIndex;
    slot->mLowVolume = COURSE_SOUND_LOW_VOLUME;
    slot->mMidVolume = COURSE_SOUND_MID_VOLUME;
    slot->mHighVolume = SOUND_VOLUME_MAX;
}
