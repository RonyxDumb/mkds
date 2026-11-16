#pragma once

#include "types.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObjectList

typedef struct Wanwan Wanwan;

// Object of wanwan_setupRenderPart: functions at 0x08 and 0x10, a word at 0x18 and the address of the pointer that holds
// it at 0x28.
typedef struct Unk020dd804 {
    /* 00 */ u8 field0[8];
    /* 08 */ void (*field8)(void);
    /* 0c */ u8 fieldC[4];
    /* 10 */ void (*field10)(void *, Wanwan *, void *, u32);
    /* 14 */ u8 field14[4];
    /* 18 */ s32 field18;
    /* 1c */ u8 field1C[0xc];
    /* 28 */ struct Unk020dd804 **field28;
} Unk020dd804;

// Object of wanwan_setupCollision: two functions and words at 0x08, 0x0c, 0x1c, 0x20 and 0x24.
typedef struct Unk020dd860 {
    /* 00 */ u8 (*field0)(Wanwan *, void *, u8 *, u8 *);
    /* 04 */ u8 (*field4)(Wanwan *, void *, u8 *, u8 *);
    /* 08 */ s32 field8;
    /* 0c */ s32 fieldC;
    /* 10 */ u8 field10[0xc];
    /* 1c */ s32 field1C;
    /* 20 */ s32 field20;
    /* 24 */ s32 field24;
    /* 28 */ u8 field28[0x18];
} Unk020dd860;

extern const MapObjectList data_02158334;
extern const Unk020dd804 data_0215835c;
extern const Unk020dd860 data_02158388;
extern MapObjectList *wanwan_sLogicPart;
extern Unk020dd804 *wanwan_sRenderPart;

void wanwan_state5Init(Wanwan *wanwan);
void wanwan_state4Update(Wanwan *wanwan);
void wanwan_state2Update(Wanwan *wanwan);
void wanwan_state2Init(Wanwan *wanwan);
void wanwan_state1Update(Wanwan *wanwan);
void wanwan_state1Init(Wanwan *wanwan);
void wanwan_state0Update(Wanwan *wanwan);
void wanwan_state0Init(Wanwan *wanwan);
u8 wanwan_onItemCollide(Wanwan *wanwan, void *kart, u8 *b, u8 *c);
u8 wanwan_onDriverCollide(Wanwan *wanwan, void *kart, u8 *b, u8 *c);
void wanwan_update(void *unused, Wanwan *wanwan); /* skipped for objects with mFlags & 4 (parked pool objects) */
void wanwan_render(void *unused0, Wanwan *wanwan, void *unused1, u32 maxAlpha);
MapObjectList *wanwan_setupLogicPart(void);
Unk020dd804 *wanwan_setupRenderPart(void);
Unk020dd860 *wanwan_setupCollision(void);
