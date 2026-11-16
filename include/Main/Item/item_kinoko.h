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
    ITEM_KOURA_R_STATE_STRAIGHT_FLAGGED = 0, // moves straight; set when the object has ITEM_OBJECT_FLAG_WIFI_RACE
    ITEM_KOURA_R_STATE_STRAIGHT = 1, // moves straight; set after a bounce off a wall
    ITEM_KOURA_R_STATE_SEEK_AFTER_THROW = 2, // moves straight until a kart is in reach
    ITEM_KOURA_R_STATE_FOLLOW_LINK = 3, // follows the link of the item list toward the kart ahead
    ITEM_KOURA_R_STATE_HOMING = 4, // steers toward its kart
    ITEM_KOURA_R_STATE_CLOSE_IN = 5, // steers fast toward the kart and fades out on reaching it
    ITEM_KOURA_R_STATE_GLIDE_TO_KART_VELOCITY = 6, // moves with the velocity added toward the kart
} ItemKouraRState;

// State frames (calls) of the seek-after-throw and follow-link states of a red shell: above the first the state tests
// every kart for the nearest one it can target; above the second it tests only the kart whose index is the race frame
// modulo 8. In follow-link the test also drops karts that are not ahead of the owner (checkRank).
#define ITEM_KOURA_R_NEAREST_TARGET_FRAMES 4
#define ITEM_KOURA_R_SINGLE_KART_TEST_FRAMES 0x10
// State frames of the follow-link state after which the shell flies straight (30 seconds).
#define ITEM_KOURA_R_FOLLOW_LINK_LIMIT_FRAMES 0x708
// Frames of the close-in state during which the shell hits the kart only once its horizontal distance is below the kart
// radius plus one and a half shell radii; after them it hits at once.
#define ITEM_KOURA_R_CLOSE_IN_HIT_FRAMES 0x14
// An object without ITEM_OBJECT_FLAG_IN_USE that is active and has ITEM_OWNER_KOURA_R_TARGETED starts the sound only
// while its age is below this (2 seconds).
#define ITEM_KOURA_R_TARGET_SOUND_AGE_FRAMES 0x78
// Checks, one per two frames, in a Wi-Fi race that find the shell within the kart's radius (mRadius times the kart
// scale); above this count it fades out.
#define ITEM_KOURA_R_NEAR_KART_LIMIT_FRAMES 0x5a
// Age (10 seconds) above which a green shell has no hits left (mHitsRemaining is set to 0).
#define ITEM_KOURA_G_LIFETIME_FRAMES 0x258

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

#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Item/item_pool.h"
#include "Main/Item/item_object_throw.h"
#include "Main/MapObjects/segment_group_collision.h"
#include "Main/Sound/sound_distance_squared_change.h" // SoundDistanceSquaredChange

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
BOOL RequestItemKouraRCloseInIfFar(void *kouraParam, s32 kartIndex);
void InitItemKouraRFromData(ItemKouraR *kouraR);
void *CopyItemKouraRData(void *buffer, ItemKouraR *kouraR, void *toBuffer);
void StartTargetKartSoundOnOwnItemHit(void *kouraParam, s32 hitType, ItemObject *otherParam);
void UpdateItemKouraRGlide(void *stateObject);
void UpdateItemKouraRCloseIn(void *stateObject);
void UpdateItemKouraRSteerToKart(void *stateObject);
void EnterItemKouraRSteerToKart(void *stateObject);
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
void LaunchItemObjectFromPos(ItemObject *itemParam, s32 pushStrength, Vec3 *fromPos, Vec3 *fromVelocity,
                             const Vec3 *normal);
void BounceRestingItemObject(ItemObject *item, Vec3 *otherVelocity, Vec3 *normal);
void AdvanceRestingItemObject(ItemObject *item);
void StartRestingItemObject(ItemObject *item, void *collisionHitLink);

typedef struct ItemKouraR ItemKouraR;

void UpdateItemKouraRFollowLink(void *stateObject);

void EnterItemKouraRFollowLink(void *stateObject);

void UpdateItemKouraRSeekAfterThrow(void *stateObject);

void RequestItemKouraRSteerToKart(ItemKouraR *kouraR, u32 kartIndex);

void UpdateItemKouraRStraight(void *stateObject);

void AdvanceItemKouraR(ItemKouraR *kouraR);

void ItemObjectBounceNop(ItemObject *item, Vec3 *otherVelocity, Vec3 *normal);

typedef struct ItemObject ItemObject;

Vec3 *CreateItemPushVector(void);
void ReleaseItemObjectToItsPool(ItemObject *item);

void StartItemObjectSoundOnSource(ItemObject *item, s32 soundId);

extern Vec3 *gItemPushVector;

extern const ItemInfo gItemInfoKinokoThree;
extern const ItemInfo gItemInfoBananaThree;
