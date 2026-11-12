#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/Kart/kart_drift.h"
#include "Main/MapObjects/water.h"
#include "Main/MapObjects/kuribo_init.h"
#include "Main/MapObjects/code_020e005c.h"
#include "Main/MapObjects/code_020e6b58.h"
#include "Main/Item/item_koura_w.h"
#include "Main/MapObjects/code_020d6dc0.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/wanwan.h"
#include "Main/Kart/shadow_model.h"
#include "Main/MapObjects/pendulum.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "code_02012b30.h"

// Object with the GroupFollower base at 0xc8 and its own fields from 0xec.
typedef struct Dossun {
    /* 00 */ MapObject mMapObject;
    /* a0 */ s32 mState;
    /* a4 */ s32 mTimer;
    /* a8 */ s32 mUnk_a8;
    /* ac */ s32 mUnk_ac;
    /* b0 */ BOOL mEnteredState5;
    /* b4 */ s32 mHitState;
    /* b8 */ s16 mSpinSpeed;
    /* ba */ s16 mSpinAngle;
    /* bc */ u32 mLastHitFrame;
    /* c0 */ u16 mKartMask;
    /* c2 */ u16 mUnk_c2;
    /* c4 */ s32 mUnk_c4;
    /* c8 */ GroupFollower mFollower;
    /* ec */ u16 mStartEntryIndex;
    /* ee */ u8 mUnk_ee[2];
    /* f0 */ s32 mIsSlowVariant;
    /* f4 */ s32 mUnk_f4;
    /* f8 */ s32 mHeightOffset;
    /* fc */ s32 mUnk_fc;
    /* 100 */ s32 mUnk_100;
    /* 104 */ s32 mUnk_104;
    /* 108 */ s32 mUnk_108;
} Dossun;

// 0x2c bytes: three functions at 0x08, 0x0c and 0x10.
typedef struct KuriboDrawList {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ void (*mInit)(void);
    /* 0c */ void (*mBeforeObjects)(void);
    /* 10 */ void (*mForEachObject)(void *a, Kuribo *p, void *c, u16 d);
    /* 14 */ u8 mUnk_14[0x18];
} KuriboDrawList;

// 0x2c bytes: a list and a word.
typedef struct DossunDrawList {
    /* 00 */ MapObjectList mList;
    /* 28 */ u32 mUnk_28;
} DossunDrawList;

MapObjectKindData *CreateDossunKindData(void);
DossunDrawList *CreateDossunDrawList(void);
MapObjectList *CreateDossunUpdateList(void);
MapObjectKindData *CreateKuriboKindData(void);
KuriboDrawList *CreateKuriboDrawList(void);
MapObjectList *CreateKuriboUpdateList(void);
s32 GetDossunMapDotOffset(Dossun *dossun);
void SetupDossunAtStartEntry(Dossun *dossun);
void CreateDossunAndDossunShadow(void);
void InitDossun(Dossun *dossun, CourseMapRow *row);
void SetupDrawKuribo(void);
void DrawKuribo(void *unused0, Kuribo *kuribo, void *unused1, u16 maxAlpha);
void UpdateKuribo(void *unused, Kuribo *kuribo); /* skipped for objects with mFlags & 4 (parked pool objects) */
void DrawDossun(void *unused0, Dossun *dossun, void *unused1, s32 maxAlpha);
u32 CollideKartWithDossun(Dossun *dossun, Kart *kart, u8 *firstResponsePtr, u8 *secondResponsePtr);
void UpdateDossun(void *unused, Dossun *dossun); /* skipped for objects with mFlags & 4 (parked pool objects) */

extern const MapObjectList gKuriboUpdateListData;
extern const struct KuriboDrawList gKuriboDrawListData;
extern const MapObjectKindData gKuriboKindData;

extern struct ShadowModel *gDossunShadow;
extern MapObjectList *gKuriboUpdateList;
extern struct KuriboDrawList *gKuriboDrawList;
extern struct DossunDrawList *gDossunDrawList;
extern struct NsbmdModel *gKuribo;
extern struct Nsbmd *gDossun;
extern MapObjectList *gDossunUpdateList;
extern MtxFx43 gDossunDrawMatrix;

