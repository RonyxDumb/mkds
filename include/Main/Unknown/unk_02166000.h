#pragma once

#include "types.h"
#include "Main/Unknown/unk_02165000.h" // Unk02165ff0
#include "Main/Unknown/code_020846c0.h" // ResFileEntry
#include "Main/Unknown/code_0210b000.h" // Unk0210b7a8

struct ModelEffect;

// One row of expl_sEffectDefs: object count, which animation objects to make, start and update functions, size.
typedef struct ModelEffectKind {
    /* 00 */ u16 mObjectCount;
    /* 04 */ BOOL mUseNsbca;
    /* 08 */ BOOL mUseNsbma;
    /* 0c */ s32 mUseNsbta;
    /* 10 */ void (*mStart)(struct ModelEffect *, s32);
    /* 14 */ void (*mUpdate)(struct ModelEffect *);
    /* 18 */ u32 mObjectSize;
    /* 1c */ ResFileEntry mResFileEntry;
} ModelEffectKind;

extern ModelEffectKind expl_sEffectDefs[5];
extern ModelEffectKind data_021661b8;
extern ModelEffectKind data_021661e4;
extern ModelEffectKind data_02166210;
extern ModelEffectKind data_0216623c;
extern const char aMapobjBk_wave_[];
extern const char aMapobjBk_wav_3[];
extern const char aEffectBombcore[];
extern const char aEffectBombco_0[];
extern const char aEffectBombco_1[];
extern const char aEffectBombco_2[];
extern const char aEffectBombco_7[];
extern const char aEffectBombco_3[];
extern const char aEffectBombco_4[];
extern const char aEffectBombco_5[];
extern const char aMapobjBk_wav_2[];
extern const char aMapobjBk_wav_0[];

extern u8 trl_sFirstPolygonId;
extern u8 trl_sAgeFade;
extern u16 trl_sMaxAge;
extern u16 trl_sAvgPointsPerTrail;
extern s32 trl_sVisible;
extern s32 (*trl_sPointInitFunc)();
extern s32 trl_sSizeDecreaseSpeed;
// Object at trl_sTexParams.
typedef struct PosStripTexture {
    /* 00 */ u32 mTexImageParam;
    /* 04 */ u8 mUnk_04[0x14];
    /* 18 */ u32 mPlttBase;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
} PosStripTexture;

extern PosStripTexture trl_sTexParams;
extern s32 data_02166418[][2];
extern s32 data_0216641c[][2];
extern s32 trl_sKartYOffsetTable[];
extern const char aEffectAward_tr[];
extern const char aEffectHanegame[];
extern Unk02165ff0 data_0216600c;
extern Unk02165ff0 data_02166028;

extern const char aBasabasa_nsbmd[];
extern const char aBasabasa_nsbtp[];
extern const char aCow_nsbmd[];
extern const char aCow_nsbtp[];
extern const char aTeresa_nsbmd[];
extern const char aTeresa_nsbtp[];
extern const char aKanoke_64_nsbm[];
extern const char aKanoke_64_nsbc[];
extern const char aMkd_ef_burner_[];
extern const char aMkd_ef_burne_0[];
extern const char aNskiller2_nsbm[];
extern const char aNskiller2_s_ns[];
extern Unk0210b7a8 data_0216676c;
extern const char aNskiller1_nsbm[];
extern const char aBakubaku_nsbmd[];
extern const char aBaku_shadow_nsbmd[];
extern const char aMove_tree_nsbm[];
extern const char aMove_tree_nsbc[];
extern char aDataGhostStaff[];
extern char aSman_bottom_ns[];
extern char aSman_top_nsbmd[];
extern char aFlipper_nsbmd[];
extern char aFlipper_nsbtp[];
extern char aFlipper_nsbta[];
