#pragma once

#include "types.h"
#include "Main/Unknown/code_020de214.h" // MapObjectDrawList
#include "Main/Unknown/code_02067cb0.h" // MapObject
#include "Main/Unknown/code_020e6fd4.h" // MapObjectKindData

typedef struct ItemBox ItemBox;

// 0x34 bytes: a word at 0x04 and five functions from 0x08.
typedef struct Unk0215a64c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ void (*mUnk_08)(void *, void *);
    /* 0c */ MapObjectKindData *(*mUnk_0c)(void);
    /* 10 */ MapObjectDrawList *(*mUnk_10)(void);
    /* 14 */ MapObjectDrawList *(*mUnk_14)(void);
    /* 18 */ MapObjectDrawList *(*mUnk_18)(void);
    /* 1c */ u8 mUnk_1c[0x18];
} Unk0215a64c;

extern const Unk0215a64c gPooledItemBoxKindDescriptor;
extern const MapObjectKindData gPooledItemBoxKindData;

BOOL IsRaceSceneNormalOrReplay(void);
BOOL IsMissionRunBossColumn(void);
MapObjectKindData *CreatePooledItemBoxKindData(void);
void InitPooledItemBox(void *mapObject, void *row);
MapObject *AllocPooledMapObject(void);
void ResetPooledMapObject(ItemBox *pooledObject);
