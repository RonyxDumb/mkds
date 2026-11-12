#pragma once
#include "types.h"
#include "Main/MapObjects/data_02165000.h" // BattleKartAiParams
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Graphics/nsbmd_render_obj.h" // ResFileEntry
#include "Main/Sound/data_0210b000.h" // SoundStartParams

struct ModelEffect;

// One row of gModelEffectKinds: object count, which animation objects to make, start and update functions, size.
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

extern ModelEffectKind gModelEffectKinds[5];

extern ModelEffectKind data_021661b8;

extern ModelEffectKind data_021661e4;

extern ModelEffectKind data_02166210;

extern ModelEffectKind data_0216623c;

extern const char gBkWaveNsbcaName[];

extern const char gBkWaveNsbmaName[];

extern const char gBombcoreNsbmdName[];

extern const char gBombcoreNsbcaName[];

extern const char gBombcoreNsbmaName[];

extern const char gBombcoreNsbtaName[];

extern const char gBombcore2NsbmdName[];

extern const char gBombcore2NsbcaName[];

extern const char gBombcore2NsbmaName[];

extern const char gBombcore2NsbtaName[];

extern const char data_021663a8[];

extern const char data_021663c0[];

// Object at gPosStripTexture.
typedef struct PosStripTexture {
    /* 00 */ u32 mTexImageParam;
    /* 04 */ u8 mUnk_04[0x14];
    /* 18 */ u32 mPlttBase;
    /* 1c */ s32 mLowHalfTexCoord;
    /* 20 */ s32 mHighHalfTexCoord;
} PosStripTexture;

