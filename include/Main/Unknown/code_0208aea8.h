#pragma once

#include "types.h"
#include "code_020184e4.h"

// The Stadium course emitters: six directions, the six emitters now running, and the countdown to the next round.
typedef struct StadiumEmitters {
    /* 00 */ Vec3 mDirections[6];
    /* 48 */ Unk0201ca6c *mEmitters[6];
    /* 60 */ s16 mEmitterTimer;
    /* 62 */ u8 field62[2];
} StadiumEmitters;

// Two halfwords at data_021660f8.
typedef struct Unk021660f8 {
    s16 field0[2];
} Unk021660f8;

// Twenty-four halfwords at data_02166108.
typedef struct Unk02166108 {
    s16 field0[24];
} Unk02166108;

// Function stored at ptcm_sGetParticleSetByIdFunc: writes a word to the first argument and returns the object.
typedef SPLManager *Unk0217b050Func(s32 *a, s32 b);
extern Unk0217b050Func *ptcm_sGetParticleSetByIdFunc;

extern StadiumEmitters *ptcm_sCamFlashes;
extern char aKartphysicalpa[];
extern char aCharphysicalpa[];
extern Unk021660f8 data_021660f8;
extern Unk02166108 data_02166108;
extern s32 ptcm_sCamFlashesParticleIds[];
extern Vec3 ptcm_sCamFlashesPositions[];
extern Vec3 data_02155fc0;

void physp_initForDriver(u32 slot, u32 kartRow, u32 characterRow);
void physp_init(void *heap, u32 entryCount);
void ptcm_initAwardEmitters(void);
void ptcm_updateCameraFlashes(void);
SPLManager *ptcm_getParticleSetByIdMr(s32 *outIndex, s32 effectId);
