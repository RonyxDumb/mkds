#pragma once

#include "types.h"
#include "Main/Item/held_item.h"
#include "Main/Menu/second_menu_scene.h" // StateMachine

// Kinoko: the mushroom. Object of item kind 3, element of gItemPools[3].
typedef struct ItemKinoko {
    /* 000 */ BouncingItemObject mBouncingItemObject;
    /* 130 */ s32 mTimer;
    /* 134 */ BOOL mVisible;
} ItemKinoko;

typedef struct ItemKinoko ItemKinoko;

#include "Main/Item/item_link_following.h"

// ItemKouraR.mStateMachine states, in the order of gItemKouraRStateTable.
typedef enum ItemKouraRState {
    ITEM_KOURA_R_STATE_STRAIGHT_FLAGGED = 0, // moves straight; set when the object has flag 0x8000000
    ITEM_KOURA_R_STATE_STRAIGHT = 1, // moves straight; set after a bounce off a wall
    ITEM_KOURA_R_STATE_SEEK_AFTER_THROW = 2, // moves straight until a kart is in reach
    ITEM_KOURA_R_STATE_FOLLOW_LINK = 3, // follows the link of the item list toward the kart ahead
    ITEM_KOURA_R_STATE_HOMING = 4, // steers toward its kart
    ITEM_KOURA_R_STATE_CLOSE_IN = 5, // steers fast toward the kart and fades out on reaching it
    ITEM_KOURA_R_STATE_GLIDE_TO_KART_VELOCITY = 6, // moves with the velocity added toward the kart
} ItemKouraRState;

// Koura: a shell. Object of the red shell (item kind 1), element of gItemPools[1].
typedef struct ItemKouraR {
    /* 000 */ LinkFollowingItemObject mLinkFollowingItemObject;
    /* 228 */ struct KartItems *mKartItems;
    /* 22c */ Vec3 mTowardKartVelocity;
    /* 238 */ s32 mNearKartFrames;
    /* 23c */ StateMachine mStateMachine;
    /* 250 */ s32 mReverse;
    /* 254 */ s32 mThrowForward;
    /* 258 */ SoundDistanceSquaredChange mSoundDistanceSquaredChange;
} ItemKouraR;

// Object of item kind 2, element of gItemPools[2].
typedef struct ItemBanana {
    /* 000 */ BouncingItemObject mBouncingItemObject;
    /* 130 */ s32 mThrowForward;
} ItemBanana;

// Object of the green shell (item kind 0), element of gItemPools[0].
typedef struct ItemKouraG {
    /* 000 */ DirectedItemObject mDirectedItemObject;
    /* 168 */ s32 mReverse;
    /* 16c */ SoundDistanceSquaredChange mSoundDistanceSquaredChange;
} ItemKouraG;

#include "Main/Race/data_020f36d8.h"
#include "Main/Item/item_pool.h"
#include "Main/Item/item_object_throw.h"
#include "Main/MapObjects/code_020e005c.h"
#include "Main/Sound/data_0210b000.h" // SoundDistanceSquaredChange

void StartNextHeldItemObject(HeldItem *heldItem);
void InitHeldItem(HeldItem *heldItem, KartItems *kartItems);
void CreateItemInfos(void);
void StartBouncingItemKinoko(void **kinokoSlot, Vec3 *velocity, s32 timer);
void ShowItemKinokoAt(ItemKinoko *kinoko, Vec3 *normal, Vec3 *pos);
ItemKinoko *StartItemKinokoOrZero(void);
void AdvanceBouncingItemKinoko(ItemKinoko *kinoko);
void AdvanceRestingItemKinoko(ItemKinoko *kinoko);
void DrawItemKinoko(ItemKinoko *kinoko, void *viewAxis, void *model);
void ResetItemKinoko(ItemKinoko *kinoko);
void StartItemKinokoBoost(ItemInUse *itemInUse, HeldItem *heldItem);
void InitItemBananaFromData(ItemBanana *banana);
void *CopyItemBananaData(void *buffer, ItemBanana *banana, void *toBuffer);
void AdvanceItemBanana(ItemBanana *banana);
s32 InitItemBanana(ItemInUse *itemInUse, ItemBanana *banana);
BOOL RequestItemKouraRState5IfFar(void *kouraParam, s32 kartIndex);
void InitItemKouraRFromData(ItemKouraR *kouraR);
void *CopyItemKouraRData(void *buffer, ItemKouraR *kouraR, void *toBuffer);
void StartTargetKartSoundOnOwnItemHit(void *kouraParam, s32 hitType, ItemObject *otherParam);
void UpdateItemKouraRState6(ItemKouraR *kouraR);
void UpdateItemKouraRState5(ItemKouraR *kouraR);
void UpdateItemKouraRState4(ItemKouraR *kouraR);
void EnterItemKouraRState4(ItemKouraR *kouraR);
s32 InitItemKouraR(ItemInUse *itemInUse, ItemKouraR *kouraR);
void DeflectItemKouraROnHit(ItemKouraR *kouraR, Vec3 *otherVelocity, Vec3 *normal);
void StartItemKouraRSound(void *kouraParam, s32 unused);
void InitItemKouraGFromData(ItemKouraG *koura);
void *CopyItemKouraGData(void *buffer, ItemKouraG *koura, void *toBuffer);
void AdvanceItemKouraG(ItemKouraG *koura);
BOOL InitItemKouraG(ItemInUse *itemInUse, ItemKouraG *koura);
void StartItemKouraGSound(void *kouraParam, s32 unused);
void StartItemStar(ItemInUse *itemInUse, HeldItem *heldItem);
void StartItemThunder(ItemInUse *itemInUse, HeldItem *heldItem);
void FallingBounceItemObject(ItemObject *item, Vec3 *otherVelocity, Vec3 *normal);
void AdvanceFallingItemObject(ItemObject *item);
void StartFallingItemObject(ItemObject *item);
void LaunchItemObjectFromPos(ItemObject *itemParam, s32 pushStrength, Vec3 *fromPos, Vec3 *fromVelocity, const Vec3 *normal);
void BounceRestingItemObject(ItemObject *item, Vec3 *otherVelocity, Vec3 *normal);
void AdvanceRestingItemObject(ItemObject *item);
void StartRestingItemObject(ItemObject *item, void *collisionHitLink);

typedef struct ItemKouraR ItemKouraR;

void UpdateItemKouraRState3(ItemKouraR *kouraR);

void EnterItemKouraRState3(ItemKouraR *kouraR);

void UpdateItemKouraRState2(ItemKouraR *kouraR);

void RequestItemKouraRState4ForKart(ItemKouraR *kouraR, u32 kartIndex);

void UpdateItemKouraRState0And1(ItemKouraR *kouraR);

void AdvanceItemKouraR(ItemKouraR *kouraR);

void ItemObjectBounceNop(ItemObject *item, Vec3 *otherVelocity, Vec3 *normal);

typedef struct ItemObject ItemObject;

Vec3 *CreateItemPushVector(void);
void ReleaseItemObjectToItsPool(ItemObject *item);

void StartItemObjectSoundOnSource(ItemObject *item, s32 soundId);

extern Vec3 *gItemPushVector;

extern const ItemInfo gItemInfoKinokoThree;
extern const ItemInfo gItemInfoBananaThree;
