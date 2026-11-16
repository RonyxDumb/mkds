#pragma once

#include "types.h"
#include "Main/Unknown/code_020a2e4c.h" // Balloon

// List of entries: an array of pointers and its length.
typedef struct BalloonList {
    /* 00 */ Balloon **mObjects;
    /* 04 */ u16 mObjectCount;
} BalloonList;

#include "01/code_02181000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_02100000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "01/code_02188950.h"
#include "Main/Unknown/code_020a1728.h"

void mrcnt_regainStolenCoins(s32 stepCount);
void mrcnt_collectCoins(s32 stepCount);
void mrcnt_updateStolenCoinCount(short param_1);
void mrcnt_stealCoins(u16 amount);
void mrcnt_loseCoins(u32 amount);
void mrcnt_setCoinStealFunc(UnkFunc *callback);
void mrcnt_setCoinLoseFunc(UnkFunc *callback);
void mrcnt_setCoinCollectFunc(UnkFunc *callback);
BOOL func_ov001_021816b4(void);
void mrcnt_notifyMissionEndWinAreaReached(void);
void mrcnt_notifyPowerSlide(void);
void mrcnt_notifyPlayerDamage(void);
void mrcnt_notifyMObjDamage(s32 b);
void mrcnt_notifyBossDamage(void);
s32 mrcnt_getStolenCoinCount(void);
u32 mrcnt_getTargetValue(void);
unsigned int mrcnt_getCurrentValue(void);
void SetMissionRunTimer(unsigned int timer);
s32 GetMissionRunTimer(void);
void func_ov001_02181844(u16 a, u16 b, u16 c, u16 d);
void mrcnt_update(void);
void mrcnt_init(void);
u16 mrcnt_getPrevPlayerYRot(void);
u16 mrcnt_getPlayerYRot(void);
Vec3 *mrcnt_getPrevPlayerPosition(void);
Vec3 *mrcnt_getPlayerPosition(void);
void mrcnt_increaseValue(void);
u16 GetMissionRunMapObjectLastIndex(void);
u8 func_ov001_02181b54(void);
Unk02188950 *GetMissionRunMapObject(int entryIndex);
void AddMissionRunMapObject(Unk02188950 *mapObject);
