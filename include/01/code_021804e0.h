#pragma once

#include "types.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_02036c5c.h" // DisplaySettings
#include "Main/Unknown/code_020487fc.h" // SceneNumbers

// Scene function of gSceneFuncs[5] (scene 'Test' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0.
int RunTestScene(void *sceneNumbers);
void UpdateTestScene(SceneNumbers *sceneNumbers);
void DrawTestSceneWrapper(void);
void ReleaseTestScene(void);
void InitTestScene(void);
void UpdateTestSceneObject(SceneNumbers *sceneNumbers);
unsigned int GetInputSlotNewBitsByIndex(unsigned int slotIndex, unsigned int mask);
u16 TestSceneGetInputSlotNewBits(InputSlot *inputSlot, unsigned int mask);
unsigned int GetTestSceneInputSlot(void);
void ReleaseTestSceneObject(void);
void InitTestSceneObject(void);
void TestSceneInitTextCanvas(TextCanvas *textCanvas, void *charCanvas, void *font, s32 charSpacing, s32 lineSpacing);
void TestSceneSetSubBg2RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14,
                                    u32 cntVal7Or13, u32 cntVal8, u32 cntVal2);
void TestSceneSetMainBg2RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14,
                                     u32 cntVal7Or13, u32 cntVal8, u32 cntVal2);
void TestSceneSetMainBg1Record(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7,
                               u32 cntVal8, u32 cntVal2, u32 cntVal13);
void *TestSceneGetCurrentHeap(void);
void DrawTestScene(void);
unsigned int TestSceneDrawTextOnCanvas(TextCanvas *textCanvas, u32 drawX, u32 drawY, u32 color, u32 flags, u16 *text);
