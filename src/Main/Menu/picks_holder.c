#include "Main/Menu/picks_holder.h"
#include "Main/Kart/karts.h"

#include "Main/Race/random_pick.h"
#include "Main/Menu/title_scene.h"
#include "Main/Menu/kart_icon_row.h"
#include "Main/Race/race_setup.h"
#include "Main/Race/entry_character_kart.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_control.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "sound_archive_load.h"
#include "bit_count.h"
#include "Main/System/heap.h"

const u32 gCharacterKartIndices[13] = {0, 3, 6, 9, 0xc, 0xf, 0x12, 0x15, 0x18, 0x1b, 0x1e, 0x21, KART_INDEX_HEYHO};
PicksHolder *gPicksHolder;

#pragma thumb on

void CreatePicksHolder(void *heap) {
    gPicksHolder = HeapAlloc(heap, 4);
    gPicksHolder->mPicks = CreateCharacterKartPicks(heap);
}

#pragma thumb off

#pragma thumb on

void ClearPicksHolderPointer(void) {
    gPicksHolder = NULL;
}

// Resets the picks and clears the character index of every entry from the participant count up.
void ClearNonParticipantCharacterIndices(void) {
    int participantCount;
    BOOL isEightOrNine;
    u32 zeroValue, noIndex;

    InitCharacterKartPicks(gPicksHolder->mPicks);
    if (gStartupWork->mConnectionKind == CONNECTION_KIND_NONE) {
        participantCount = 1;
    } else {
        isEightOrNine = TRUE;
        if (gConnectionWork->mState != CONNECTION_STATE_SYNCED &&
            gConnectionWork->mState != CONNECTION_STATE_SYNCED_RACE) {
            isEightOrNine = FALSE;
        }
        participantCount = (u8) (isEightOrNine != FALSE ? CountSetBits(gConnectionWork->mParticipantMask) : 0);
    }
    zeroValue = 0;
    noIndex = ~0;
    for (; participantCount < 8; participantCount++) {
        SetCharacterIndex(participantCount, noIndex);
        SetKartStored(participantCount, zeroValue);
    }
}

// Resets the picks, copies the characters in and clears the kart index of entries from the participant count up.
void ClearNonParticipantKartIndices(void) {
    int entryIndex;
    int participantCount;
    BOOL isEightOrNine;
    u32 zeroValue, noIndex;

    InitCharacterKartPicks(gPicksHolder->mPicks);
    if (gStartupWork->mConnectionKind == CONNECTION_KIND_NONE) {
        participantCount = 1;
    } else {
        isEightOrNine = TRUE;
        if (gConnectionWork->mState != CONNECTION_STATE_SYNCED &&
            gConnectionWork->mState != CONNECTION_STATE_SYNCED_RACE) {
            isEightOrNine = FALSE;
        }
        participantCount = (u8) (isEightOrNine != FALSE ? CountSetBits(gConnectionWork->mParticipantMask) : 0);
    }
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        SetGivenCharacter(gPicksHolder->mPicks, (u8) entryIndex, GetCharacterIndex(entryIndex));
    }
    zeroValue = 0;
    noIndex = ~0;
    for (; participantCount < 8; participantCount++) {
        SetKartIndex(participantCount, noIndex);
        SetKartStored(participantCount, zeroValue);
    }
}

void FillRandomCharacterIndices(void) {
    int participantIndex;
    int participantCount;
    BOOL isEightOrNine;
    u32 pickedIndex;

    pickedIndex = ~0;
    if (gStartupWork->mConnectionKind == CONNECTION_KIND_NONE) {
        participantCount = 1;
    } else {
        isEightOrNine = TRUE;
        if (gConnectionWork->mState != CONNECTION_STATE_SYNCED &&
            gConnectionWork->mState != CONNECTION_STATE_SYNCED_RACE) {
            isEightOrNine = FALSE;
        }
        participantCount = (u8) (isEightOrNine != FALSE ? CountSetBits(gConnectionWork->mParticipantMask) : 0);
    }
    for (participantIndex = 0; participantIndex < participantCount; participantIndex++) {
        SetGivenCharacter(gPicksHolder->mPicks, (u8) participantIndex, GetCharacterIndex(participantIndex));
    }
    PickRandomCharacters(gPicksHolder->mPicks);
    for (; participantCount < 8; participantCount++) {
        GetEntryCharacterAndKart(gPicksHolder->mPicks, participantCount, &pickedIndex, NULL);
        SetCharacterIndex(participantCount, pickedIndex);
    }
}

void FillRandomKartIndices(void) {
    int participantIndex;
    int participantCount;
    BOOL isEightOrNine;
    u32 pickedIndex;

    pickedIndex = ~0;
    if (gStartupWork->mConnectionKind == CONNECTION_KIND_NONE) {
        participantCount = 1;
    } else {
        isEightOrNine = TRUE;
        if (gConnectionWork->mState != CONNECTION_STATE_SYNCED &&
            gConnectionWork->mState != CONNECTION_STATE_SYNCED_RACE) {
            isEightOrNine = FALSE;
        }
        participantCount = (u8) (isEightOrNine != FALSE ? CountSetBits(gConnectionWork->mParticipantMask) : 0);
    }
    for (participantIndex = 0; participantIndex < participantCount; participantIndex++) {
        SetGivenKart(gPicksHolder->mPicks, (u8) participantIndex, GetKartIndex(participantIndex));
    }
    PickRandomKarts(gPicksHolder->mPicks);
    for (; participantCount < 8; participantCount++) {
        GetEntryCharacterAndKart(gPicksHolder->mPicks, participantCount, NULL, &pickedIndex);
        SetKartIndex(participantCount, pickedIndex);
        SetKartStored(participantCount, 1);
    }
}

void SetKartIndicesFromCharacters(void) {
    int entryIndex;

    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        SetKartIndex(entryIndex, gCharacterKartIndices[GetCharacterIndex(entryIndex)]);
        SetKartStored(entryIndex, 1);
    }
}

#pragma thumb off
