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

// Object counts of the first two rows of gModelEffectKinds (Bombcore, Bombcore2) per race mode.
#define BOMBCORE_OBJECT_COUNT 3
#define BOMBCORE2_OBJECT_COUNT 1
#define BOMBCORE_OBJECT_COUNT_WIFI 6
#define BOMBCORE2_OBJECT_COUNT_WIFI 4
#define BOMBCORE_OBJECT_COUNT_MISSION_RUN 0x14
// Rows 2, 3 and 4 (water_efct kinds and bk_wave).
#define WATER_EFCT_KIND2_OBJECT_COUNT 1
#define WATER_EFCT_KIND4_OBJECT_COUNT 2
#define BK_WAVE_OBJECT_COUNT 1

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

// Object at gPosStripTexture.
typedef struct PosStripTexture {
    /* 00 */ u32 mTexImageParam;
    /* 04 */ u8 mUnk_04[0x14];
    /* 18 */ u32 mPlttBase;
    /* 1c */ s32 mLowHalfTexCoord;
    /* 20 */ s32 mHighHalfTexCoord;
} PosStripTexture;

