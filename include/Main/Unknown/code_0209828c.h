#pragma once

#include "types.h"
#include "Main/Unknown/code_02099020.h"
#include "Main/Course/MapObjectModel.h" // MapObjectModel
#include "Main/Unknown/code_020e005c.h" // GroupFollower
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject, MapObjectList

// Object up to 0x200 bytes: the shared part, a counter at 0xa4 that cycles between 0xac and 0xb0, a state at 0xb4,
// seven GroupFollower from 0xb8, then a count and an index at 0x1b8 and 0x1ba and seven values at 0x1bc.
typedef struct Pakkun {
    /* 000 */ MapObject field0;
    /* 0a0 */ u16 mPolygonId;
    /* 0a2 */ u8 fieldA2[2];
    /* 0a4 */ s32 fieldA4;
    /* 0a8 */ s32 fieldA8;
    /* 0ac */ s32 fieldAC;
    /* 0b0 */ s32 fieldB0;
    /* 0b4 */ s32 mState;
    /* 0b8 */ GroupFollower mFollowers[7];
    /* 1b4 */ s32 mTimer;
    /* 1b8 */ u16 mFollowerIndex;
    /* 1ba */ u16 mFollowerCount;
    /* 1bc */ s32 field1BC[7];
    /* 1d8 */ s32 field1D8;
    /* 1dc */ s32 field1DC;
    /* 1e0 */ s32 field1E0;
    /* 1e4 */ BOOL field1E4;
    /* 1e8 */ s32 field1E8;
    /* 1ec */ s32 field1EC;
    /* 1f0 */ s32 field1F0;
    /* 1f4 */ s32 field1F4;
    /* 1f8 */ s32 field1F8;
    /* 1fc */ s32 field1FC;
} Pakkun;

// Object returned by mobj_createRenderPart2d and mobj_createRenderPart3d here: a word at 0x1c is set to 1.
typedef struct Unk020982d4 {
    /* 00 */ u8 field0[0x1c];
    /* 1c */ BOOL field1C;
} Unk020982d4;

extern MapObjectList *pakn_sLogicPart;
extern MapObjectModel *gPakkunMouth;
extern void *gPakkunZHead;
extern void *pakn_sBodyRenderPart;
extern void *gPakkunBody;
extern Unk020982d4 *pakn_sHeadRenderPart;
extern Unk020982d4 *pakn_sMouthRenderPart;

void *pakn_setupLogicPart(void);
void *pakn_setupZHeadRenderPart(void);
void *pakn_setupBodyRenderPart(void);
void *pakn_setupMouthRenderPart(void);
void pakn_update(void *a, Pakkun *pakkun); /* skipped for objects with mFlags & 4 (parked pool objects) */
void pakn_globalLogicInit(void);
void pakn_renderBody(void *a, Pakkun *pakkun);
void pakn_applyBodyMaterial(void *a);
void pakn_loadBodyModel(void *a);
void pakn_renderHead(void *a, Pakkun *pakkun);
void pakn_applyHeadMaterial(void *a);
void pakn_loadHeadModel(void *a);
void pakn_renderMouth(void *a, Pakkun *pakkun);
void pakn_loadMouthModel(void *a);
void pakn_init(Pakkun *pakkun);
void pknf_spawn(GroupFollower *groupFollower, s32 b);
void *pknf_setupLogicPart(void);
