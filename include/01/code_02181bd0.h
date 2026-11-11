#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020e005c.h"

// Object updated by UpdateCoin, one state per value of mUnk_0f8.
typedef struct Coin {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ u16 mModelAlpha;
    /* 0a2 */ u8 mUnk_0a2[0x2];
    /* 0a4 */ s32 mNsbtpFrameIndex;
    /* 0a8 */ s32 mUnk_0a8;
    /* 0ac */ s32 mTimer;
    /* 0b0 */ s32 mScaleFactor;
    /* 0b4 */ GroupFollower mFollower;
    /* 0d8 */ Vec3 mUnk_0d8;
    /* 0e4 */ s32 mBounceY;
    /* 0e8 */ Vec3 *mTargetPos;
    /* 0ec */ Vec3 mUnk_0ec;
    /* 0f8 */ s32 mState;
    /* 0fc */ void *mEffect;
    /* 100 */ s32 mEffectTimer;
} Coin;

#include "Main/Unknown/code_0209b000.h"
#include "01/code_02182000.h"
#include "01/code_0218155c.h"
#include "01/unk_021a6000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_0219b250.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_02100000.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_020d22c0.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d4000.h"

void *CreateCoinUpdateList(void);
void *CreateCoinShadowDrawList(void);
void *CreateCoinDrawList(void);
void CreateCoinKindData(void);
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

#include "01/code_0219b540.h"
#include "Main/Unknown/code_02081000.h"
#include "Main/Unknown/code_02081618.h"
