#pragma once

#include "types.h"
#include "code_020184e4.h"

// The Stadium course emitters: six directions, the six emitters now running, and the countdown to the next round.
typedef struct StadiumEmitters {
    /* 00 */ Vec3 mDirections[6];
    /* 48 */ ParticleEmitter *mEmitters[6];
    /* 60 */ s16 mEmitterTimer;
    /* 62 */ u8 mUnk_62[2];
} StadiumEmitters;

// Two halfwords at gAwardFirstEffectIds.
typedef struct AwardFirstEffectIds {
    s16 mEffectIds[2];
} AwardFirstEffectIds;

// Twenty-four halfwords at gAwardEmitterEffectIds.
typedef struct AwardEmitterEffectIds {
    s16 mUnk_00[24];
} AwardEmitterEffectIds;

// Function stored at gGetSPLManagerFunction: writes a word to the first argument and returns the object.
typedef SPLManager *GetSPLManagerFunc(s32 *a, s32 b);

void CopyKartPhysicalParams(u32 slot, u32 kartRow, u32 characterRow);
void CreateKartPhysicalParamTable(void *heap, u32 entryCount);
void CreateAwardEmitters(void);
void AdvanceStadiumEmitters(void);
SPLManager *GetSPLManagerForEffectId(s32 *outIndex, s32 effectId);

extern const s32 gStadiumEmitterEffectIds[12];
extern const Vec3 gStadiumEmitterPositions[6];
