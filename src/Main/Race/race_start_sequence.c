#include "Main/Race/race_start_sequence.h"
#include "Main/System/heap.h"
#include "Main/Net/connection_sharing.h"
#include "Main/Race/race.h"
#include "Main/Graphics/stem_sets.h"

#include "Main/MapObjects/data_0217a000.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Sound/sound_request_queue.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Menu/choises_s.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
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
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "code_0212df7c.h"
#include "Main/System/heap_call.h"
#include "Main/Race/race_clock.h"
#include "Main/Race/data_0217b358.h"
#include "Main/Save/ghost_record_file.h"

RaceStartSequence *gRaceStartSequence;

void InitRaceStartSequence(void) {
    gRaceStartSequence = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0xc);
    gRaceStartSequence->mCounting = FALSE;
    gRaceStartSequence->mDone = 0;
    gRaceStartSequence->mSequenceFrames = 0;
}

void ClearRaceStartSequencePointer(void) {
    gRaceStartSequence = NULL;
}

void ResetRaceStartSequenceFrames(void) {
    gRaceStartSequence->mCounting = FALSE;
    gRaceStartSequence->mSequenceFrames = -0x78;
}

// Per-frame step from UpdateRaceHud: no sounds (they are in the draw, UpdateRaceStartSequenceSounds).
void UpdateRaceStartSequence(void) {
    RaceStartSequence *sequence = gRaceStartSequence;
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
            gRaceStartSequence->mDone = 1;
            return;
        }
        framesAddress = &sequence->mSequenceFrames;
        if (frames < 0x7fffffff) {
            *framesAddress = frames + 1;
        }
        return;
    }
    if (gRaceSetup->mMode == MODE_WIFI) {
        if ((gWiFiRaceSync->mFlags & WIFI_RACE_SYNC_FLAG_IN_RACE) == 0) {
            return;
        }
        sequence->mCounting = TRUE;
        SetRaceUpdateFramesUnlimited();
        SetMapObjectsRunUpdateLists();
        return;
    }
    if (FinishDataSharingSync() == 1) {
        gRaceStartSequence->mCounting = TRUE;
    }
}

void UpdateRaceStartSequenceSounds(void) {
    NNSSndSeqPlayer **seqPlayer;
    s32 frames = gRaceStartSequence->mSequenceFrames;

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
                NNS_SndArcPlayerStartSeqArc(seqPlayer, 0, 0x27);
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
                NNS_SndArcPlayerStartSeqArc(seqPlayer, 0, 0x28);
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

s32 GetRaceStartSequenceFrames(void) {
    if (gRaceStartSequence != NULL) {
        return gRaceStartSequence->mSequenceFrames;
    }
    return -0x78;
}

s32 IsRaceStartSequenceDone(void) {
    if (gRaceStartSequence != NULL) {
        return gRaceStartSequence->mDone;
    }
    return 0;
}
