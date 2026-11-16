#pragma once

#include "types.h"
#include "Main/Unknown/code_020f2dac.h"

// Kinoko: the mushroom. Object of item kind 3, element of it_sItemsets[3].
typedef struct ItemKinoko {
    /* 000 */ BouncingItemObject field0;
    /* 130 */ s32 mTimer;
    /* 134 */ BOOL mVisible;
} ItemKinoko;

typedef struct ItemKinoko ItemKinoko;

#include "Main/Unknown/code_020ec8bc.h"

// Koura: a shell. Object of the red shell (item kind 1), element of it_sItemsets[1].
typedef struct ItemKouraR {
    /* 000 */ LinkFollowingItemObject field0;
    /* 228 */ struct KartItems *mKartItems;
    /* 22c */ Vec3 field22C;
    /* 238 */ s32 field238;
    /* 23c */ Unk020e005c_080 mStateMachine;
    /* 250 */ s32 field250;
    /* 254 */ s32 mThrowForward;
    /* 258 */ SoundDistanceSquaredChange field258;
    /* 268 */ u8 field268[0xc];
} ItemKouraR;

// Object of item kind 2, element of it_sItemsets[2].
typedef struct ItemBanana {
    /* 000 */ BouncingItemObject field0;
    /* 130 */ s32 mThrowForward;
} ItemBanana;

// Object of the green shell (item kind 0), element of it_sItemsets[0].
typedef struct ItemKouraG {
    /* 000 */ DirectedItemObject field0;
    /* 168 */ s32 field168;
    /* 16c */ SoundDistanceSquaredChange field16C;
    /* 17c */ u8 field17C[0xc];
} ItemKouraG;

#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_0210b000.h" // SoundDistanceSquaredChange

void StartNextHeldItemObject(HeldItem *heldItem);
void it_initSlot(HeldItem *heldItem, KartItems *kartItems);
void it_initItemConfig(void);
void StartBouncingItemKinoko(void **kinokoSlot, Vec3 *b, s32 timer);
void func_020f4e78(ItemKinoko *kinoko, Vec3 *normal, Vec3 *pos);
ItemKinoko *itkino_20F4EE8(void);
void AdvanceBouncingItemKinoko(ItemKinoko *kinoko);
void AdvanceRestingItemKinoko(ItemKinoko *kinoko);
void itkino_20F5008(ItemKinoko *kinoko, void *b, void *c);
void itkino_initInstance(ItemKinoko *kinoko);
void itkino_activate(ItemInUse *itemInUse, HeldItem *heldItem);
void itbana_20F50B4(ItemBanana *banana);
void *itbana_20F5108(void *buffer, ItemBanana *banana, void *toBuffer);
void itbana_20F518C(ItemBanana *banana);
s32 itbana_20F5240(ItemInUse *itemInUse, ItemBanana *banana);
BOOL func_020f5324(void *kouraParam, s32 kartIndex);
void itkrar_20F53D0(ItemKouraR *kouraR);
void *itkrar_20F5550(void *buffer, ItemKouraR *kouraR, void *toBuffer);
void func_020f5614(void *kouraParam, s32 hitType, ItemObject *otherParam);
void UpdateItemKouraRState6(ItemKouraR *kouraR);
void UpdateItemKouraRState5(ItemKouraR *kouraR);
void UpdateItemKouraRState4(ItemKouraR *kouraR);
void EnterItemKouraRState4(ItemKouraR *kouraR);
s32 itkrar_20F5D6C(ItemInUse *itemInUse, ItemKouraR *kouraR);
void func_020f5f7c(ItemKouraR *kouraR, Vec3 *otherVelocity, Vec3 *normal);
void StartItemKouraRSound(void *kouraParam, s32 b);
void itkrag_20F5FFC(ItemKouraG *koura);
void *itkrag_20F6038(void *buffer, ItemKouraG *koura, void *toBuffer);
void itkrag_GreenShellRender(ItemKouraG *koura);
BOOL itkrag_20F6150(ItemInUse *itemInUse, ItemKouraG *koura);
void StartItemKouraGSound(void *kouraParam, s32 b);
void itstar_activate(ItemInUse *itemInUse, HeldItem *heldItem);
void itthun_activate(ItemInUse *itemInUse, HeldItem *heldItem);
void func_020f6388(ItemObject *item, Vec3 *otherVelocity, Vec3 *normal);
void AdvanceFallingItemObject(ItemObject *item);
void StartFallingItemObject(ItemObject *item);
void it_startThrowAnim(ItemObject *itemParam, s32 pushStrength, Vec3 *fromPos, Vec3 *fromVelocity, Vec3 *normal);
void func_020f6830(ItemObject *item, Vec3 *otherVelocity, Vec3 *normal);
void AdvanceRestingItemObject(ItemObject *item);
void StartRestingItemObject(ItemObject *item, void *b);
