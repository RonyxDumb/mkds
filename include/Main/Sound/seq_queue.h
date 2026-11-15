#pragma once

#include "types.h"
#include "sound_player_control.h"
#include "Main/Kart/kart_drift.h" // Kart
#include "Main/Menu/menu_screens_work.h" // SeqPlayerControl
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_seq.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h" // MapObjectSound

// The last readings of one sequence variable: its value, the previous value and the frames since it changed.
typedef struct SeqVariableReading {
    /* 00 */ s16 mValue;
    /* 02 */ s16 mPrevValue;
    /* 04 */ s32 mSinceChangeFrames;
    /* 08 */ u8 mVariableNo[4];
} SeqVariableReading;

void ResetSeqVariableReadings(void);
void UpdateSeqVariableReadings(NNSSndSeqPlayer **handle);
u32 IsSeqVariableChanged(u32 slot);
u32 GetSeqVariableSinceChangeFrames(u32 slot);

unsigned int IsAnySeqVariableEnabled(void);

typedef struct SoundSetPlayer SoundSetPlayer;

void StartThunderShrinkSound(void *kartAddress, int secondArgument);
void RequestThunderShrinkSound(Kart *kart);
void InitSoundSetPlayerWithVariables(SoundSetPlayer *player, s32 seqId, s32 firstBankId);
void SetSeqVariableEnabled(u32 slot, u32 enabled);

u32 *ResetThunderShrinkSoundCounter(void);

void KartThunderShrinkNop(void);

void SetThunderShrinkSoundFlag(u32 enabled);
void SetTeresaSoundFlag(u32 enabled, u32 isSelectedEntry);

typedef struct SeqPlayerControl SeqPlayerControl;

SeqPlayerControl *SetRestartedSeqPitchFlag(void);
u32 IsKartNear(void);

void UpdateSceneSeqPlayerControl(void);
u32 IsTeresaSoundFlagSet(void);

void StartKartRemovalSeqEffect(void);

SeqPlayerControl *FadeSeqVolumeToZeroAfterKartRemoval(void);
SeqPlayerControl *ResetSeqPlayerControl(void);

void StopSndHandleSeq(NNSSndSeqPlayer **handle, u32 fadeSteps);
void StartSeqOnHandleIfEnabled(u32 soundId, NNSSndSeqPlayer **handle);
void UpdateSeqPlayerControl(SeqPlayerControl *control, NNSSndSeqPlayer **handle);

u32 IsSndHandleSeq(NNSSndSeqPlayer **handle, u32 seqArcNo, u32 index);

void InitVolumeFade(void);
void StartKingTeresaAlphaSound(MapObjectSound *mapSound);
BOOL IsKingTeresaState0Or2Or5(void);
void UpdateKingTeresaSeqVolume(NNSSndSeqPlayer **handle);
u32 IsSndHandleSet(NNSSndSeqPlayer **handle);

u32 InitKartNearSoundFactors(void);
void InitKingTeresaSoundState(u32 kingTeresaFlag);

void SetLapProgressSoundGaps(u32 divisor);

u16 GetLapProgressSoundId(int index);

s32 GetLapProgressSoundGap(u32 index);

void StartCursorMoveSound(void);
s32 StepValueTowardTarget(PlayerVolumeFade *volumeFade, s32 target);
void InitSoundRequestQueues(void);
void ResetSoundRequestQueues(void);

void StartSeqPair(s32 pairNo, s32 pairSide);

void UpdateEmblemSound(void);
void ResetSeqQueue(void);
void UpdateSeqQueue(void);
void AddSeqQueueEntry(u32 pairNo, u32 pairSide);

void SetEmblemSoundValue(unsigned int value);

// Values of gKingTeresaState, named from the king_teresa.c functions that set them.
enum {
    KING_TERESA_STATE_WAIT_TO_APPROACH,
    KING_TERESA_STATE_APPROACH_KART,
    KING_TERESA_STATE_MOVE_TO_FORWARD_POINT,
    KING_TERESA_STATE_HIDDEN,
    KING_TERESA_STATE_SHOW_BOSS_COINS,
    KING_TERESA_STATE_GROUP_ENTRY,
    KING_TERESA_STATE_KART_ELIMINATED,
    KING_TERESA_STATE_END_REACHED,
};

extern u16 gLapProgressSoundIds[2];
extern const s32 gLapProgressSoundGapDividends[2];
extern s32 gUseKingTeresaSeqVolume;
extern s32 gKartNearSeqVolumeFactor;
extern s32 gKingTeresaStateFrames;
extern s32 gInitialVolumePerFrame;
extern u32 gThunderShrinkSoundCounter;
extern s32 gEmblemSoundValue;
extern s32 gKingTeresaStateLastFrame;

extern u32 gEmblemSoundCallsSincePlay;
extern u32 gAnySeqVariableEnabled;
extern s32 gKartNearPlayerVolumeFactor;
extern s32 gKingTeresaState;
extern s32 gPreviousKingTeresaState;
extern s32 gKingTeresaSeqVolumeFactor;
extern s32 gKingTeresaSoundVolumeFactor;
extern volatile s32 gReachedSeqVolume;
extern u32 gSeqVariableEnabled[2];
extern VolumeFade gVolumeFade;
extern s32 gLapProgressSoundGaps[2];
extern s32 gKingTeresaVolumePerFrame[2];
extern SeqPlayerControl gSeqPlayerControl;
extern SeqVariableReading gSeqVariableReadings[2];
