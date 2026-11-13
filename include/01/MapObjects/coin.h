#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/MapObjects/code_020e005c.h"

// Object updated by UpdateCoin, one state per value of mUnk_0f8.
typedef struct Coin {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ u16 mModelAlpha;
    /* 0a2 */ u8 mUnk_0a2[0x2];
    /* 0a4 */ s32 mNsbtpFrameIndex;
    /* 0a8 */ s32 mNsbtpFrameCounter;
    /* 0ac */ s32 mTimer;
    /* 0b0 */ s32 mScaleFactor;
    /* 0b4 */ GroupFollower mFollower;
    /* 0d8 */ Vec3 mUnk_0d8;
    /* 0e4 */ s32 mBounceY;
    /* 0e8 */ Vec3 *mTargetPos;
    /* 0ec */ Vec3 mTargetOffset;
    /* 0f8 */ s32 mState;
    /* 0fc */ void *mEffect;
    /* 100 */ s32 mEffectTimer;
} Coin;

#include "Main/MapObjects/map_object_model_frame.h"
#include "01/code_02182000.h"
#include "01/Race/mission_run_state.h"
#include "01/unk_021a6000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Graphics/effects.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "tp.h"
#include "01/code_0219b250.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Sound/sound_handle_pool.h"
#include "player.h"
#include "code_0212df7c.h"
#include "01/unk_021a9000.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
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
#include "01/code_0218b9b4.h"

extern MapObjectKindDescriptor gCoinKindDescriptor;
extern const u16 gCoinShadowRotationAngles[3];

extern u16 gCoinShadowRotationIndex;
