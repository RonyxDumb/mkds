#pragma once

#include "types.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/unk_02175628.h"

// Argument of test_update.
typedef struct Unk0218052c {
    /* 00 */ u8 field0[4];
    /* 04 */ u16 field4;
} Unk0218052c;

// Object at the start of a 0xdc-byte allocation made by dc_createDisplayConfig.
typedef struct Unk02180774 {
    /* 00 */ u8 field0[0x28];
    /* 28 */ u8 mMainBgRecords[0x48];
    /* 70 */ u8 mSubBgRecords[0x6c];
} Unk02180774;

// Scene function of scproc_sSceneTable[5] (scene 'Test' in sSceneDefs): copies the callbacks and calls
// scene_runScene. Returns 0.
int test_run(void *sceneNumbers);
void testdef_update(Unk0218052c *sceneNumbers);
void testdef_vblank(void);
void testdef_finalize(void);
void testdef_init(void);
void test_update(Unk0218052c *sceneNumbers);
unsigned int func_ov001_021805bc(unsigned int slotIndex, unsigned int mask);
u16 func_ov001_021805d8(InputSlot *inputSlot, unsigned int mask);
unsigned int func_ov001_021805ec(void);
void test_finalize(void);
void test_init(void);
void func_ov001_02180728(TextCanvas *textCanvas, void *charCanvas, void *font, s32 charSpacing, s32 lineSpacing);
void func_ov001_02180740(Unk02180774 *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 p4, u32 cntVal8,
                         u32 cntVal2);
void func_ov001_02180774(Unk02180774 *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 p4, u32 cntVal8,
                         u32 cntVal2);
void func_ov001_021807a8(Unk02180774 *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7, u32 cntVal8,
                         u32 cntVal2, u32 cntVal13);
void *func_ov001_021807e4(void);
void test_vblank(void);
unsigned int func_ov001_02180ad0(TextCanvas *textCanvas, u32 drawX, u32 drawY, u32 color, u32 flags, u16 *text);
