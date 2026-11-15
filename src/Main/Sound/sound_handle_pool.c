#include "Main/Sound/sound_handle_pool.h"

#include "Main/Sound/sound_set_load.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Sound/sound_system.h"
#include "Main/Sound/sound_request_queue.h"
#include "Main/Race/race_setup_block.h"
#include "tp.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "player.h"
#include "code_021479b4.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Menu/menu_screens_work.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Sound/sound_seq.h"
#include "code_0212df7c.h"

void StartMissionRunCountSeq(s32 count, s32 countLimit) {
    u32 value;
    PlayingSound *playingSound;

    if (count == countLimit) {
        if (gMissionRunLimitSeqNo[0] != 0xff) {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, gMissionRunLimitSeqNo[0]);
        }
        if (gMissionRunLimitSeqNo[0] == 0x1d7) {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1de);
            return;
        }
        value = gRaceSetup->mMissionCountMapObjectKinds[0];
        if (value == 0x65 || value == 0xc9) {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0xd4);
        }
    } else {
        value = gMissionRunCountSeqNo[0];
        if (value == 0xff) {
            return;
        }
        if (!(gRaceSoundKind & 1)) {
            return;
        }
        playingSound = TakeSoundHandleEntry(&gSoundHandlePool);
        if (gSoundModeHolder.mSeqStartEnabled == 0) {
            return;
        }
        if (playingSound->mSeqPlayer != NULL) {
            NNS_SndPlayerStopSeq(&playingSound->mSeqPlayer, 0);
        }
        if (playingSound->mSeqPlayer != NULL) {
            NNS_SndPlayerStopSeq(&playingSound->mSeqPlayer, 0);
        }
        NNS_SndArcPlayerStartSeqArc(&playingSound->mSeqPlayer, 0, value);
    }
}

void RunScenesSoundNop(void) {}

NNSSndArc *SetCurrentSndArc(void) {
    return NNS_SndArcSetCurrent(&gFileSndArc);
}

void SetPlayerVolumeTarget(u32 index, u32 value) {
    gPlayerVolumeFade.mTargetVolumes[index] = value;
}

SoundHandlePool *GetSoundHandlePool(u32 index) {
    return &(&gSoundHandlePool)[index];
}

void SetSoundOutputEffect(s32 type) {
    ChangeSoundOutputEffect(type);
}

NNSSndSeqPlayer **GetSndHandles(void) {
    return gSndHandleSlots;
}

NNSSndSeqPlayer **GetSecondSndHandleSlot(void) {
    return &gSndHandleSlots[1];
}

NNSSndSeqPlayer **GetSndHandleSlot(u32 index) {
    return gSndHandleSlots + index;
}
