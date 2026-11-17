#pragma once

#include "types.h"
#include "particle_system.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Kart/kart_palette_stem_tables.h"

// The Stadium course emitters: six directions, the six emitters now running, and the countdown to the next time they
// are replaced.
typedef struct StadiumEmitters {
    /* 00 */ Vec3 mDirections[6];
    /* 48 */ ParticleEmitter *mEmitters[6];
    /* 60 */ s16 mEmitterTimer;
    /* 62 */ u8 mUnk_62[2];
} StadiumEmitters;

// AwardFirstEffectIds.mEffectIds: the two effect ids CreateAwardEmitters starts first.
typedef struct AwardFirstEffectIds {
    s16 mEffectIds[2];
} AwardFirstEffectIds;

// AwardSecondEffectIds.mEffectIds: the 24 effect ids CreateAwardEmitters starts second (after the rename of the row
// above).
typedef struct AwardEmitterEffectIds {
    s16 mUnk_00[24];
} AwardEmitterEffectIds;

// Type of gGetSPLManagerFunction: returns the SPLManager for effectId and writes the effect id inside that manager to
// *outIndex.
typedef SPLManager *GetSPLManagerFunc(s32 *outIndex, s32 effectId);

void CopyKartPhysicalParams(u32 slot, u16 kartRow, u16 characterRow);
void CreateKartPhysicalParamTable(void *heap, u32 entryCount);
void CreateAwardEmitters(void);
void AdvanceStadiumEmitters(void);
SPLManager *GetSPLManagerForEffectId(s32 *outIndex, s32 effectId);

extern const s32 gStadiumEmitterEffectIds[12];
extern const Vec3 gStadiumEmitterPositions[6];

extern struct KartPhysicalParamTable *gKartPhysicalParamTable;

extern const StemSetParams gCompleteStems;
extern const StemSetParams gLoseStems;
extern const StemSetParams gWinStems;
extern const StemSetParams gGoalStems;
extern const StemSetParams gFailedStems;
