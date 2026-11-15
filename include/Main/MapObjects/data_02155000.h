#pragma once
#include "types.h"

// Objects whose layout isn't known yet.
extern const Vec3 gKartModelMenuReferenceAxis;

struct Vec4;

extern const struct Vec4 gQuaternionIdentity;

extern const u16 gKartPaletteColors[8];

extern const char gKartEmblemTextureName[16];

extern const u16 gTeamPaletteColors[];

extern const u16 gRegionPaletteColors[];

struct ParticleEmitter;

struct Kart;

// An effect id and its step function.
typedef struct OtherKartEffectKind {
    /* 00 */ s32 mEffectId;
    /* 04 */ void (*mAdvance)(struct ParticleEmitter *effect, s32 phase);
} OtherKartEffectKind;

// 12-byte entry: four bytes and two string pointers.
typedef struct StemSetParams {
    /* 00 */ u8 mNsbmdCount;
    /* 01 */ u8 mNsbcaCount;
    /* 02 */ u8 mNsbmaCount;
    // The nsbtp files are loaded only when mNsbmdCount is 1 and this is above 1.
    /* 03 */ u8 mNsbtpCount;
    /* 04 */ const char *mStems[2];
} StemSetParams;

extern const StemSetParams gCountStartStems[3];

static inline const StemSetParams *GetCountStartStem(u32 setIndex) {
    return &gCountStartStems[setIndex];
}

// 12-byte entries of gCharacterNsbcaStems (mUnk_00 counts the rows): the animation file stem and whether the animation
// loops.
typedef struct CharacterAnimationRow {
    /* 00 */ s32 mUnk_00;
    /* 04 */ const char *mStem;
    /* 08 */ s32 mLoopFlag;
} CharacterAnimationRow;

extern const CharacterAnimationRow gCharacterNsbcaStems[];

extern const s16 gFinishResultByRank[7][8];

