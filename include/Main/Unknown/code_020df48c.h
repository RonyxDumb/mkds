#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020de214.h"
#include "Main/Unknown/code_020de588.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020f9c6c.h"

// Object at 0xe8 and 0xec of MkdEfBubbleObject: a word at 0x24.
typedef struct Unk020df6c8_e8 {
    /* 00 */ u8 field0[0x24];
    /* 24 */ u32 field24;
} Unk020df6c8_e8;

// Object of at least 0xf4 bytes, made by mobj_createObject and filled in by efbub_init.
typedef struct MkdEfBubbleObject {
    /* 00 */ MapObject field0;
    /* a0 */ s32 fieldA0;
    /* a4 */ s32 fieldA4;
    /* a8 */ u16 fieldA8;
    /* aa */ u8 fieldAA[2];
    /* ac */ s32 fieldAC;
    /* b0 */ ShadowMatrix fieldB0;
    /* e4 */ u8 fieldE4;
    /* e5 */ u8 fieldE5[3];
    /* e8 */ Unk020df6c8_e8 *fieldE8;
    /* ec */ Unk020df6c8_e8 *fieldEC;
    /* f0 */ s32 fieldF0;
} MkdEfBubbleObject;

void efbub_loadModel(void);
void efbub_init(MkdEfBubbleObject *bubble, CourseMapRow *row);
MapObjectKindData *mibox_setupCollision(void);
MapObjectList *mibox_setupLogicPart(void);
void mibox_globalPreUpdate(void);
void mibox_update(void *unused, ItemBox *itemBox);
