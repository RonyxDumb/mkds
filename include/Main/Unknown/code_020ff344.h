#pragma once

#include "types.h"
#include "Main/Unknown/code_020f2dac.h" // BouncingItemObject
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020ffc4c.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_021052fc.h"
#include "Main/Unknown/code_020ffdd4.h"

// Object of func_020ff97c: 0x144 bytes.
typedef struct Unk020ff97c {
    /* 000 */ MapObject field0;
    /* 0a0 */ MtxFx33 fieldA0;
    /* 0c4 */ u8 fieldC4[0x24];
    /* 0e8 */ Vec3 fieldE8;
    /* 0f4 */ Vec3 fieldF4;
    /* 100 */ s32 field100;
    /* 104 */ s32 field104;
    /* 108 */ s32 field108;
    /* 10c */ s32 field10C;
    /* 110 */ s32 field110;
    /* 114 */ s32 field114;
    /* 118 */ s32 field118;
    /* 11c */ s32 field11C;
    /* 120 */ s32 field120;
    /* 124 */ s32 field124;
    /* 128 */ s32 field128;
    /* 12c */ s32 field12C;
    /* 130 */ s32 field130;
    /* 134 */ s32 field134;
    /* 138 */ s32 field138;
    /* 13c */ s32 field13C;
    /* 140 */ u8 field140[4];
} Unk020ff97c;

// Object of item kind 7, element of it_sItemsets[7].
typedef struct ItemFBox {
    /* 000 */ BouncingItemObject field0;
    /* 130 */ Vec3 field130;
    /* 13c */ s32 mThrownForward;
    /* 140 */ PooledMapObject *mPooledMapObject;
} ItemFBox;

void itfbox_20FF344(ItemFBox *fbox);
s32 itfbox_20FF3C4(ItemFBox *fbox);
void itfbox_20FF438(ItemFBox *fbox);
u32 itfbox_20FF538(ItemInUse *inUse, ItemFBox *fbox);
void itfbox_20FF638(ItemInUse *inUse, ItemFBox *fbox);
void itfbox_20FF654(ItemFBox *fbox);
void itfbox_initInstance(ItemFBox *fbox);
void func_020ff6d8(ItemFBox *fbox, MtxFx43 *out);
void SetItemFBoxDrawMatrix(ItemFBox *fbox, MtxFx43 *out);
void func_020ff97c(Unk020ff97c *object);
BOOL IsWall(u32 kind);
Unk02100004 *func_020ffacc(void);
void dram_init(Dram *dram, struct CourseMapRow *courseRow);
void dram_loadModel(void);
