#pragma once

#include "types.h"
#include "player.h"
#include "Main/Kart/kart_drift.h" // Kart
#include "Main/Menu/data_0217d000.h" // SeqPlayerControl
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_seq.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObjectSound

// Object gSeqVariableReadings: a signed halfword at 0x00, a signed halfword at 0x02, a signed word at 0x04 and four
// bytes at 0x08; GetSeqVariableSinceChangeFrames and IsSeqVariableChanged read the word at 0x04,
// UpdateSeqVariableReadings reads and writes all of them, and ResetSeqVariableReadings writes all of them.
typedef struct SeqVariableReading {
    /* 00 */ s16 mValue;
    /* 02 */ s16 mPrevValue;
    /* 04 */ s32 mSinceChangeFrames;
    /* 08 */ u8 mVariableNo[4];
} SeqVariableReading;

extern SeqVariableReading gSeqVariableReadings[];

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

unsigned int KartThunderShrinkNop();

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

extern u16 gLapProgressSoundIds[2];
extern const s32 gLapProgressSoundGapDividends[2];
extern s32 gUseKingTeresaSeqVolume;
extern s32 gKartNearSeqVolumeFactor;
extern s32 gKingTeresaStateFrames;
extern s32 gInitialVolumePerFrame;
extern u32 gThunderShrinkSoundCounter;
extern s32 gEmblemSoundValue;
extern s32 gKingTeresaStateLastFrame;
