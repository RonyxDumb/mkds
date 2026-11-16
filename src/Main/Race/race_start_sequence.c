#include "Main/Race/race_start_sequence.h"
#include "Main/System/heap.h"
#include "Main/Net/connection_sharing.h"
#include "Main/Race/race.h"
#include "Main/Graphics/stem_sets.h"

#include "Main/System/backup_net_camera_work.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Sound/sound_request_queue.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Menu/choises_s.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "sound_player_control.h"
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
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "sound_archive_load_result.h"
#include "Main/System/heap_call.h"
#include "Main/Race/race_clock.h"
#include "Main/Race/race_start_sequence_work.h"
#include "Main/Save/ghost_record_file.h"

RaceStartSequence *g_GlobalB358;

void InitializeGlobalB358(void) {
    g_GlobalB358 = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), 0xc);
    g_GlobalB358->mCounting = FALSE;
    g_GlobalB358->mDone = 0;
    g_GlobalB358->mSequenceFrames = 0;
}

void ResetGlobalB358(void) {
    g_GlobalB358 = NULL;
}

void MaybeClearGlobalB358(void) {
    g_GlobalB358->mCounting = FALSE;
    g_GlobalB358->mSequenceFrames = -0x78;
}

// Per-frame step from SomeUpdateFn: no sounds (they are in the draw, UpdateRaceStartSequenceSounds).
void IncreaseB358Countdown(void) {
    RaceStartSequence *sequence = g_GlobalB358;
    s32 frames;
    s32 *framesAddress;

    if (sequence->mCounting != FALSE) {
        frames = sequence->mSequenceFrames;
        if (frames < 200) {
            sequence->mSequenceFrames = frames + 1;
            if (frames == -1) {
                StartRaceInput();
                return;
            }
            if (frames != 180) {
                return;
            }
            StartRaceSounds();
            StartRace();
            g_GlobalB358->mDone = 1;
            return;
        }
        framesAddress = &sequence->mSequenceFrames;
        if (frames < 0x7fffffff) {
            *framesAddress = frames + 1;
        }
        return;
    }
    if (g_GlobalCO->mMode == MODE_WIFI) {
        if ((g_GlobalAA->mFlags & WIFI_RACE_SYNC_FLAG_IN_RACE) == 0) {
            return;
        }
        sequence->mCounting = TRUE;
        SetRaceUpdateFramesUnlimited();
        SetMapObjectsRunUpdateLists();
        return;
    }
    if (FinishDataSharingSync() == 1) {
        g_GlobalB358->mCounting = TRUE;
    }
}

void UpdateRaceStartSequenceSounds(void) {
    NNSSndSeqPlayer **seqPlayer;
    s32 frames = g_GlobalB358->mSequenceFrames;

    if (frames < -21) {
        return;
    }
    if (frames >= 200) {
        return;
    }
    if (frames == 0 || frames == 60 || frames == 120) {
        if (gRaceSoundKind & 1) {
            seqPlayer = TakeSoundHandleEntry(GetSoundHandlePool(0));
            if (gSoundModeHolder.mSeqStartEnabled != 0) {
                if (*seqPlayer != NULL) {
                    NNS_SndPlayerStopSeq(seqPlayer, 0);
                }
                if (*seqPlayer != NULL) {
                    NNS_SndPlayerStopSeq(seqPlayer, 0);
                }
                PlaySseqFromSarc(seqPlayer, 0, 0x27);
            }
        }
    }
    if (frames == 175) {
        if (gRaceSoundKind & 1) {
            seqPlayer = TakeSoundHandleEntry(GetSoundHandlePool(0));
            if (gSoundModeHolder.mSeqStartEnabled != 0) {
                if (*seqPlayer != NULL) {
                    NNS_SndPlayerStopSeq(seqPlayer, 0);
                }
                if (*seqPlayer != NULL) {
                    NNS_SndPlayerStopSeq(seqPlayer, 0);
                }
                PlaySseqFromSarc(seqPlayer, 0, 0x28);
            }
        }
    }
    if (frames == -21) {
        SetStemSet(STEM_SET_COUNT);
    }
    if (frames != 180) {
        return;
    }
    SetStemSet(STEM_SET_START);
}

s32 GetRaceStartCountdown(void) {
    if (g_GlobalB358 != NULL) {
        return g_GlobalB358->mSequenceFrames;
    }
    return -0x78;
}

s32 IsRaceCountdownEnded(void) {
    if (g_GlobalB358 != NULL) {
        return g_GlobalB358->mDone;
    }
    return 0;
}
