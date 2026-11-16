#pragma once

#include "types.h"
#include "01/Menu/menu_screen_states_and_file_names.h"
#include "Main/System/input_slots.h"
#include "Main/Scene/display_settings.h" // DisplaySettings
#include "Main/Scene/run_scene_connection.h" // SceneNumbers

// Scene function of g_SceneFnTable[5] (scene 'Test' in g_SceneArchiveNameTable): copies the callbacks and calls
// OnSceneLoop. Returns 0.
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
void TestSceneSetSubBg2RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14,
                                    u32 cntVal7Or13, u32 cntVal8, u32 cntVal2);
void TestSceneSetMainBg2RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14,
                                     u32 cntVal7Or13, u32 cntVal8, u32 cntVal2);
void TestSceneSetMainBg1Record(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7,
                               u32 cntVal8, u32 cntVal2, u32 cntVal13);
void *TestSceneGetCurrentHeap(void);
void DrawTestScene(void);
unsigned int TestSceneDrawTextOnCanvas(TextCanvas *textCanvas, u32 drawX, u32 drawY, u32 color, u32 flags, u16 *text);
