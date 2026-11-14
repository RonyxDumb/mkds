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

// Three words, three more words and two halfwords; gBattleKartAiParamsHard, gBattleKartAiParamsDefault and
// gBattleKartAiParamsNormal are one each.
typedef struct BattleKartAiParams {
    /* 00 */ s32 mSetupBalloonCountGoalLimits[3];
    /* 0c */ s32 mPickBalloonCountGoalLimits[3];
    /* 18 */ s16 mInflateWaitFrameCount;
    /* 1a */ s16 mInflateBalloonsLeftLimit;
} BattleKartAiParams;

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

