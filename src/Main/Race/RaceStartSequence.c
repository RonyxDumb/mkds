#include "Main/Race/RaceStartSequence.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02089ef4.h"

#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_02054000.h"
#include "Main/Unknown/code_02089000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_020d3c7c.h"
#include "Main/Ui/ChoisesS.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_020b36c8.h"
#include "Main/Unknown/code_020b36dc.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0203c8dc.h"

void InitRaceStartSequence(void) {
    gRaceStartSequence = heap_alloc(proc_getHeap(proc_getCurrent()), 0xc);
    gRaceStartSequence->mCounting = FALSE;
    gRaceStartSequence->mDone = 0;
    gRaceStartSequence->mSequenceFrames = 0;
}

u32 ClearRaceStartSequencePointer(void) {
    u32 pointerAddress;
    u32 nullValue;
    pointerAddress = (u32) &gRaceStartSequence;
    nullValue = 0u;
    *(u32 *) ((pointerAddress) + (0)) = nullValue;
    return pointerAddress;
}

void ResetRaceStartSequenceFrames(void) {
    gRaceStartSequence->mCounting = FALSE;
    gRaceStartSequence->mSequenceFrames = -0x78;
}

// Per-frame step from race_update2d: no sounds (they are in the draw, UpdateRaceStartSequenceSounds).
void UpdateRaceStartSequence(void) {
    RaceStartSequence *sequence = gRaceStartSequence;
    s32 frames;
    s32 *framesAddress;

    if (sequence->mCounting != FALSE) {
        frames = sequence->mSequenceFrames;
        if (frames < 200) {
            sequence->mSequenceFrames = frames + 1;
            if (frames == -1) {
                rstat_initInputRecorders();
                return;
            }
            if (frames != 180) {
                return;
            }
            StartRaceSounds();
            race_start();
            gRaceStartSequence->mDone = 1;
            return;
        }
        framesAddress = &sequence->mSequenceFrames;
        if (frames < 0x7fffffff) {
            *framesAddress = frames + 1;
        }
        return;
    }
    if (gRaceMultiConfig->mMode == 5) {
        if ((gStruct217AA14->field75C & 2) == 0) {
            return;
        }
        sequence->mCounting = TRUE;
        race_setField34();
        mobj_enableLogicUpdates();
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
        if (data_0217c780 & 1) {
            seqPlayer = sp_acquireElement(sound_getPoolById(0));
            if (SoundHandle_217D084.fieldC != 0) {
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
        if (data_0217c780 & 1) {
            seqPlayer = sp_acquireElement(sound_getPoolById(0));
            if (SoundHandle_217D084.fieldC != 0) {
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
        SetStemSet(0);
    }
    if (frames != 180) {
        return;
    }
    SetStemSet(1);
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
