#include "Main/Course/course_sound_slot.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Sound/snd_handle_slots.h"
#include "player.h"
#include "code_0212df7c.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/MapObjects/data_0217c000.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Menu/data_0217d000.h"
#include "Main/Sound/sound_system.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
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
    {{0x01cc, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff}},
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
        case 0x1d:
            tableIndex = 0;
            break;
        case 0x1c:
            tableIndex = 1;
            break;
        case 0x20:
            tableIndex = 2;
            break;
        case 0x21:
            tableIndex = 3;
            break;
        case 0x22:
            tableIndex = 4;
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
    if (tableIndex == 1 && gRaceSetup->mMode != MODE_MISSION_RUN) {
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
        case 3:
            if (tableValue == 0x1cc) {
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
        case 4:
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

void InitCourseSoundSlot(CourseSoundSlot *p0, u32 p1, u32 p2) {
    p0->mPreviousVolumeHandle = p1;
    p0->mVolumeHandle = p1;
    p0->mFirstTableIndex = p2;
    p0->mLowVolume = 0x28;
    p0->mMidVolume = 0x50;
    p0->mHighVolume = 0x7f;
}
