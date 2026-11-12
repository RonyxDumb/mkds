#pragma once
#include "types.h"
#include "Main/Menu/second_menu_scene.h" // StateCallbacks
#include "Main/Menu/data_02175000.h" // SceneCallbacks
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"

extern u16 data_usa_021656d8;

extern u16 data_usa_021656dc;

extern s32 data_usa_021656e0;

extern s32 data_usa_021656e4;

extern u32 data_usa_021656e8;

extern s32 data_usa_021656ec;

extern Vec3 data_usa_021656f0;

extern Vec3 data_usa_021656fc;

extern Vec3 data_usa_02165708;

extern u8 data_usa_02165724[];

extern u8 data_usa_02165738[];

extern u8 data_usa_0216574c[];

extern u8 data_usa_02165760[];

extern u8 data_usa_0216577c[];

// Objects whose layout isn't known yet.
typedef struct QueueMPDataToPortParams {
    /* 00 */ void (*mCallback)();
    /* 04 */ u16 mMaxDataSize;
    /* 06 */ u8 mUnk_06[2];
    /* 08 */ s32 mPort;
    /* 0c */ u16 mPriority;
    /* 0e */ u8 mUnk_0e[2];
} QueueMPDataToPortParams;

struct Kart;

extern const char *gCharacterDirName;

extern const char *gKartDirName;

extern const char *gCharacterSubDirNames[13];

extern u16 gKartNameTagLineVertices[12];

extern TexPlttEntry data_021659ec;

extern TexPlttEntry data_02165a10;

extern TexPlttEntry data_02165a34;

extern TexPlttEntry data_02165a58;

// Three words, three more words and two halfwords; gBattleKartAiParamsHard, gBattleKartAiParamsDefault and gBattleKartAiParamsNormal are one each.
typedef struct BattleKartAiParams {
    /* 00 */ s32 mUnk_00[3];
    /* 0c */ s32 mUnk_0c[3];
    /* 18 */ s16 mInflateWaitFrameCount;
    /* 1a */ s16 mInflateBalloonsLeftLimit;
} BattleKartAiParams;

extern const s32 data_02166048;

extern const Vec3 data_0216608c;

extern const char *const gTeamEmblemNames[];

extern const char gTeamEmblemNsbtxFormat[];

// Three words.
typedef struct KartFollowEffectIds {
    /* 00 */ u32 mEffectIds[3];
} KartFollowEffectIds;

// Eight halfwords.
typedef struct KartKillerEndRankOffsets {
    /* 00 */ s16 mOffsets[8];
} KartKillerEndRankOffsets;

// 37 words.
typedef struct KartEffectScales {
    /* 00 */ s32 mScales[37];
} KartEffectScales;

extern u16 data_usa_021658f0;

extern const s32 *data_usa_021658f4;

extern const u16 data_usa_021658f8[3];

extern const u16 data_usa_02165900[3];

extern const u16 data_usa_02165908[3];

extern const s32 *const data_usa_02165910[];

