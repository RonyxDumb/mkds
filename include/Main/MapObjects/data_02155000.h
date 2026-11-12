#pragma once
#include "types.h"

// Objects whose layout isn't known yet.
extern const u32 data_usa_02155018[];

extern u32 data_02155048[];

extern u32 data_02155098[];

extern u32 data_021550a8[];

extern const u32 data_usa_02155068[];

extern const Vec3 data_usa_02155188;

struct Vec4;

extern const struct Vec4 data_usa_02155194;

extern void (*gNsbmdDrawFunctions[])(void *param_1);

extern const u16 gKartPaletteColors[];

extern const u16 gTeamPaletteColors[];

extern const u16 data_02155a2c[];

struct ParticleEmitter;

struct Kart;

// An effect id and its step function.
typedef struct OtherKartEffectKind {
    /* 00 */ s32 mEffectId;
    /* 04 */ void (*mAdvance)(struct ParticleEmitter *p, s32 a);
} OtherKartEffectKind;

extern Vec3 data_02155a08;

extern Vec3 gKartEffectVec3Zero;

extern Vec3 gOtherCameraDistanceLimitsSquared;

// 12-byte entries; BuildEmblemNsbtxPath reads the string pointer at 0x00.
typedef struct CharacterName {
    /* 00 */ const char *mName;
    /* 04 */ u8 mUnk_04[8];
} CharacterName;

extern const CharacterName gCharacterEmblemNames[];

extern const CharacterName gCharacterPNames[];

extern const CharacterName gCharacterENames[];

// 8-byte entries; BuildKartShadowNsbmdPath and BuildKartNsbtxPath read the string pointer at 0x00.
typedef struct KartName {
    /* 00 */ const char *mName;
    /* 04 */ u8 mUnk_04[4];
} KartName;

extern const KartName gKartNames[];

extern const KartName gKartShadowNames[];

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

extern const StemSetParams gGoalStems;

extern const StemSetParams gWinStems;

extern const StemSetParams gLoseStems;

extern const StemSetParams gCompleteStems;

extern const StemSetParams gFailedStems;

extern const u32 data_02155a54;

extern const Vec3 data_usa_021557c4;

extern const Vec3 data_usa_021557d0;

extern const s32 data_usa_021557bc;

extern const s32 data_usa_021557c0;

extern const s32 data_usa_021557dc[];

// 12-byte entries of gCharacterNsbcaStems (mUnk_00 counts the rows): the animation file stem and whether the animation loops.
typedef struct CharacterAnimationRow {
    /* 00 */ s32 mUnk_00;
    /* 04 */ const char *mStem;
    /* 08 */ s32 mLoopFlag;
} CharacterAnimationRow;

extern const CharacterAnimationRow gCharacterNsbcaStems[];

extern const s32 gFinishResultByRank[];

