#pragma once

#include "types.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/MapObjects/segment_group_collision.h"

enum {
    COIN_STATE_PLACED,
    COIN_STATE_RISE_OVER_KART,
    COIN_STATE_BOUNCE,
    COIN_STATE_DROP,
    COIN_STATE_FADE_OUT_DROP,
    COIN_STATE_TRANSFER_RISE,
    COIN_STATE_TRANSFER_FLY,
    COIN_STATE_TRANSFER_HELD,
    COIN_STATE_LAUNCH_FADE,
    COIN_STATE_HIDDEN_WAIT,
};

// Coin.mScaleFactor: scale a coin starts with when it rises over a kart or leaves one, its full scale and the growth
// added each frame
// while it drops or transfers to the boss.
#define COIN_SCALE_START 0x99a
#define COIN_SCALE_FULL TO_FIXED12(1)
#define COIN_SCALE_GROW_PER_FRAME 0x29

// mTimer start of a coin that rises over a kart (parked on the call that finds it 0 or below, the 31st) and of a boss
// transfer coin (counted only in the transfer fly state, which fades the coin from the call that finds it 0 or below);
// the kart follow
// effect starts when mTimer reaches COIN_RISE_KART_EFFECT_TIMER after its decrement, and the coin's own effect stops on
// the call that finds mEffectTimer below 0 (the 15th call).
#define COIN_RISE_TIMER_START 0x1e
#define COIN_RISE_KART_EFFECT_TIMER 3
#define COIN_RISE_EFFECT_TIMER_START 0xd

// mNsbtpFrameCounter steps that make mNsbtpFrameIndex advance by one.
#define COIN_NSBTP_FRAME_STEPS 5

// mModelAlpha at the start of COIN_STATE_DROP and COIN_STATE_TRANSFER_RISE (a coin leaving a kart), and at the start of
// COIN_STATE_LAUNCH_FADE.
#define COIN_LEAVE_KART_ALPHA 0x10
#define COIN_LAUNCH_FADE_START_ALPHA 0x32

// Sound a coin makes when it leaves a kart (drop and transfer rise).
#define COIN_LEAVE_KART_SOUND_ID 0x1d9

// A coin map object: its model alpha, animation frame, timer, scale, follower, positions, state and effect.
typedef struct Coin {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ u16 mModelAlpha;
    /* 0a2 */ u8 mUnk_0a2[0x2];
    /* 0a4 */ s32 mNsbtpFrameIndex;
    /* 0a8 */ s32 mNsbtpFrameCounter;
    /* 0ac */ s32 mTimer;
    /* 0b0 */ s32 mScaleFactor;
    /* 0b4 */ GroupFollower mFollower;
    /* 0d8 */ Vec3 mPosCopy;
    /* 0e4 */ s32 mBounceY;
    /* 0e8 */ Vec3 *mTargetPos;
    /* 0ec */ Vec3 mTargetOffset;
    /* 0f8 */ s32 mState;
    /* 0fc */ void *mEffect;
    /* 100 */ s32 mEffectTimer;
} Coin;

#include "Main/MapObjects/map_object_model_frame.h"
#include "01/Race/mission_run_state.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Graphics/effects.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/star_or_killer_hit_sound.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "touch_panel_sampling.h"
#include "01/MapObjects/map_object_model_animation_load.h"
#include "Main/Sound/sound_handle_accessors_and_mission_count_seq.h"
#include "sound_player_control.h"
#include "sound_archive_load_result.h"
#include "01/Menu/menu_screen_states_and_file_names.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"

#include "Main/MapObjects/map_object_kind_update_list.h"

MapObjectList *CreateCoinUpdateList(void);
MapObjectList *CreateCoinShadowDrawList(void);
MapObjectList *CreateCoinDrawList(void);
MapObjectKindData *CreateCoinKindData(void);
void UpdateCoin(void *mapObjectList, Coin *coin);
void CoinBeforeObjectsNop(void);
void InitCoinObjects(MapObjectList *coinList);
void DrawCoin(void *mapObjectList, Coin *coin);
void LoadCoin(MapObjectList *drawList);
u8 CollideKartWithCoin(Coin *coin, Kart *kart, u8 *firstResponsePtr, u8 *secondResponsePtr);
void SetMissionRunCoinCallbacks(void);
void StartCoinsFadeIn(void);
void StartCoinsFadeOut(void);
void ParkBossCoins(s32 parkCount);
void SetBossCoinShownCount(s32 shownCount);
void AddPendingBossTransferInMissionRun(u32 amount);
void StartCoinBossTransfer(void);
void StartCoinDrop(void);
void StartCoinCountUp(void);
void AdvanceCoinNsbtpFrame(Coin *coin, s32 counterAdd);
void StartCoinRiseOverKart(Coin *coin, Kart *kart);

#include "01/Menu/select_ghost.h"
#include "Main/Kart/kart_effects.h"
#include "01/MapObjects/kuriking_state_shared.h"

extern MapObjectKindDescriptor gCoinKindDescriptor;
extern const u16 gCoinShadowRotationAngles[3];

extern u16 gCoinShadowRotationIndex;
