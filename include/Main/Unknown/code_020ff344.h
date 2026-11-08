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
    /* 000 */ MapObject mUnk_00;
    /* 0a0 */ Unk020e005c_a0 mUnk_a0;
    /* 13c */ s32 mUnk_13c;
    /* 140 */ u8 mUnk_140[4];
} Unk020ff97c;

// Object of item kind 7, element of gItemPools[7].
typedef struct ItemFBox {
    /* 000 */ BouncingItemObject mUnk_000;
    /* 130 */ Vec3 mUnk_130;
    /* 13c */ s32 mThrownForward;
    /* 140 */ ItemBox *mPooledMapObject;
} ItemFBox;

void func_020ff344(ItemFBox *fbox);
s32 func_020ff3c4(ItemFBox *fbox);
void AdvanceItemFBox(ItemFBox *fbox);
u32 InitItemFBox(ItemInUse *inUse, ItemFBox *fbox);
void AdvanceItemFBoxInUse(ItemInUse *inUse, ItemFBox *fbox);
void StartItemFBox(ItemFBox *fbox);
void ResetItemFBox(ItemFBox *fbox);
void func_020ff6d8(ItemFBox *fbox, MtxFx43 *out);
void SetItemFBoxDrawMatrix(ItemFBox *fbox, MtxFx43 *out);
void func_020ff97c(Unk020ff97c *object);
BOOL func_020ffabc(u32 kind);
Unk02100004 *func_020ffacc(void);
void InitDram(Dram *dram, struct CourseMapRow *courseRow);
void CreateDram(void);
