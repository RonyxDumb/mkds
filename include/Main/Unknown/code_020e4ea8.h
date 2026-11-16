#pragma once

#include "types.h"

typedef struct Unk020e43a8 Unk020e43a8;

// 0x28-byte object built from a table.
typedef struct PukupukuUpdateList {
    /* 00 */ u32 field0;
    /* 04 */ u32 field4;
    /* 08 */ u32 field8;
    /* 0c */ u32 fieldC;
    /* 10 */ u32 field10;
    /* 14 */ u32 field14;
    /* 18 */ u32 field18;
    /* 1c */ u32 field1C;
    /* 20 */ u32 field20;
    /* 24 */ u32 field24;
} PukupukuUpdateList;

extern PukupukuUpdateList *puku_sLogicPart;

// 0x2c-byte object built from a table.
typedef struct PukupukuShadowDrawList {
    /* 00 */ u32 field0;
    /* 04 */ u32 field4;
    /* 08 */ u32 field8;
    /* 0c */ u32 fieldC;
    /* 10 */ u32 field10;
    /* 14 */ u32 field14;
    /* 18 */ u32 field18;
    /* 1c */ u32 field1C;
    /* 20 */ u32 field20;
    /* 24 */ u32 field24;
    /* 28 */ u32 field28;
} PukupukuShadowDrawList;

extern PukupukuShadowDrawList *puku_sShadowRenderPart;

// 0x2c-byte object built from a table.
typedef struct PukupukuDrawList {
    /* 00 */ u32 field0;
    /* 04 */ u32 field4;
    /* 08 */ u32 field8;
    /* 0c */ u32 fieldC;
    /* 10 */ u32 field10;
    /* 14 */ u32 field14;
    /* 18 */ u32 field18;
    /* 1c */ u32 field1C;
    /* 20 */ u32 field20;
    /* 24 */ u32 field24;
    /* 28 */ u32 field28;
} PukupukuDrawList;

extern PukupukuDrawList *puku_sMainRenderPart;

// 0x40-byte object built from a table.
typedef struct PukupukuKindData {
    /* 00 */ u32 field0;
    /* 04 */ u32 field4;
    /* 08 */ u32 field8;
    /* 0c */ u32 fieldC;
    /* 10 */ u32 field10;
    /* 14 */ u32 field14;
    /* 18 */ u32 field18;
    /* 1c */ u32 field1C;
    /* 20 */ u32 field20;
    /* 24 */ u32 field24;
    /* 28 */ u32 field28;
    /* 2c */ u32 field2C;
    /* 30 */ u32 field30;
    /* 34 */ u32 field34;
    /* 38 */ u32 field38;
    /* 3c */ u32 field3C;
} PukupukuKindData;

PukupukuKindData *puku_setupConfig(void);
PukupukuDrawList *puku_setupMainRenderPart(void);
PukupukuShadowDrawList *puku_setupShadowRenderPart(void);
PukupukuUpdateList *puku_setupLogicPart(void);
void puku_applyMainMaterial(void);
void puku_renderMain(u32 a, Unk020e43a8 *pukupuku, u32 b, u16 alpha);
