#include "01/Scene/test_scene.h"
#include "01/Scene/test_scene_display_settings.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "Main/System/input_slots.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "01/Scene/test_scene_sub_bg_registers.h"
#include "01/Menu/menu_screen_states_and_file_names.h"
#include "registers.h"
#include "01/Graphics/clear_char_canvas.h"
#include "01/Graphics/clear_chars_and_screen_map.h"
#include "01/Menu/emblem_state_and_lld.h"
#include "Main/System/heap.h"
#include "Main/System/heap_call.h"
#include "Main/Graphics/text_canvas.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/emblem_choises_shown.h"
#include "char_canvas_text_draw.h"
#include "fixed_point_graphics_setup.h"
#include "vram_load_2d_graphics.h"
#include "Main/System/last_tick.h"
#include "01/Menu/option_nickname_scenes.h"
#include "Main/System/startup.h"
#include "Main/System/init_after_startup.h"

#pragma thumb off

u32 GetDisplaySettings(void) {
    return ((u32) gDisplaySettings);
}

void TestSceneMTX_Identity22_(s32 *matrix) {
    matrix[0] = 0x1000u;
    matrix[1] = 0x0u;
    matrix[2] = 0x0u;
    matrix[3] = 0x1000u;
}

#pragma thumb off

void TestSceneGXS_SetVisiblePlane(u32 bits) {
    vu32 *reg = &reg_GXS_DB_DISPCNT;
    *reg = (*reg & ~0x1f00) | (bits << 8);
}

void WriteSubBg0Offset(u32 offsetX, u32 offsetY) {
    reg_G2S_DB_BG0OFS = (offsetX & 0x1ff) | ((offsetY << 16) & 0x1ff0000);
}

void WriteSubBg0CntBits(u32 bits) {
    vu16 *reg = &reg_G2S_DB_BG0CNT;
    *reg = (*reg & ~3) | bits;
}

void WriteSubBg0CntMosaic(u32 bit6Value) {
    vu16 *reg = &reg_G2S_DB_BG0CNT;
    if (bit6Value != 0) {
        *reg |= 0x40;
    } else {
        *reg &= ~0x40;
    }
}

void SetSubBg0Cnt(u32 cntVal14, u32 cntVal7, u32 cntVal8, u32 cntVal2, u32 cntVal13) {
    vu16 *reg = &reg_G2S_DB_BG0CNT;
    *reg = (*reg & 0x43) | (cntVal14 << 14) | (cntVal7 << 7) | (cntVal8 << 8) | (cntVal2 << 2) | (cntVal13 << 13);
}

void WriteSubBg1Offset(u32 offsetX, u32 offsetY) {
    reg_G2S_DB_BG1OFS = (offsetX & 0x1ff) | ((offsetY << 16) & 0x1ff0000);
}

void WriteSubBg1CntBits(u32 bits) {
    vu16 *reg = &reg_G2S_DB_BG1CNT;
    *reg = (*reg & ~3) | bits;
}

void WriteSubBg1CntMosaic(u32 bit6Value) {
    vu16 *reg = &reg_G2S_DB_BG1CNT;
    if (bit6Value != 0) {
        *reg |= 0x40;
    } else {
        *reg &= ~0x40;
    }
}

void TestSceneSetSubBg1Cnt(u32 cntVal14, u32 cntVal7, u32 cntVal8, u32 cntVal2, u32 cntVal13) {
    vu16 *reg = &reg_G2S_DB_BG1CNT;
    *reg = (*reg & 0x43) | (cntVal14 << 14) | (cntVal7 << 7) | (cntVal8 << 8) | (cntVal2 << 2) | (cntVal13 << 13);
}

#pragma thumb off

void ClearCharCanvas(u8 *charCanvas, u32 color) {
    u32 clearFunction = (*(u32 *) (((u32) charCanvas) + (24)));
    u32 clearResult = ((u32(*)(u32, u32))(clearFunction))((u32) charCanvas, color);
}

#pragma optimize_for_size on
#pragma thumb off

u32 TestSceneDrawTextOnCanvas(TextCanvas *textCanvas, u32 drawX, u32 drawY, u32 color, u32 flags, u16 *text) {
    return NNSi_G2dTextCanvasDrawText(textCanvas, drawX, drawY, color, flags, text);
}

#pragma thumb on

void DrawTestScene(void) {
    s32 identityMatrix[4];

    if (gTestScene->mStateChanged != 0) {
        GetDisplaySettings();
        TestSceneMTX_Identity22_(identityMatrix);
        switch (gTestScene->mState) {
            case TEST_SCENE_STATE_CHOISES:
                TestSceneGXS_SetVisiblePlane(1);
                GXS_SetGraphicsMode(GX_BGMODE_0);
                WriteSubBg0Offset(0, 0);
                WriteSubBg0CntBits(0);
                WriteSubBg0CntMosaic(0);
                SetSubBg0Cnt(0, 0, 4, 4, 0);
                SetEmblemChoisesShownAndReset(1);
                RequestEmblemChoisesGraphicsUpload();
                break;
            case TEST_SCENE_STATE_CHAR_TABLE_0:
            case TEST_SCENE_STATE_CHAR_TABLE_1:
            case TEST_SCENE_STATE_CHAR_TABLE_2:
                TestSceneGXS_SetVisiblePlane(2);
                GXS_SetGraphicsMode(GX_BGMODE_0);
                WriteSubBg1Offset(0, 0);
                WriteSubBg1CntBits(0);
                WriteSubBg1CntMosaic(0);
                TestSceneSetSubBg1Cnt(0, 0, 4, 4, 0);
                *(u16 *) 0x5000400 = 0;
                *(u16 *) 0x5000402 = 0x1f;
                *(u16 *) 0x5000404 = 0x3e0;
                *(u16 *) 0x5000406 = 0x3fff;
                *(u16 *) 0x5000408 = 0x7c00;
                *(u16 *) 0x500040a = 0x7c1f;
                *(u16 *) 0x500040c = 0;
                *(u16 *) 0x500040e = 0xffff;
                ClearChars(gTestScene->mChars);
                GXS_LoadBG1Scr(gTestScene->mScreenMap, 0, 0x600);
                break;
        }
    }
    if (gTestScene->mState == TEST_SCENE_STATE_CHOISES) {
        DrawEmblemChoises();
    } else if ((u32) (gTestScene->mState - TEST_SCENE_STATE_CHAR_TABLE_0) <= 2) {
        u32 slotIndex;
        BOOL moved;
        int canvasIndex;
        int col;
        int row;
        int textIndex;
        s32 charRangeStarts[8] = {0xe000, 0xe060, 0x20, 0x80, 0xa0, 0x100, 0x3040, 0x30a0};
        u16 charTable8Codes[0x5f] = {0x20ac, 0x201a, 0x201e, 0x2026, 0x2c6,  0x152,  0x2018, 0x2019, 0x201c, 0x201d, 0x2022,
                           0x2dc,  0x2122, 0x203a, 0x153,  0x3000, 0x3001, 0x3002, 0xff0c, 0xff0e, 0x30fb, 0xff1a,
                           0xff1b, 0xff1f, 0xff01, 0x309b, 0x309c, 0xb4,   0xff40, 0xa8,   0xff3e, 0xffe3, 0xffef,
                           0x309d, 0x309e, 0x3005, 0x30fc, 0x2015, 0x2010, 0xff0f, 0xff3c, 0xff5e, 0xff5c, 0x2026,
                           0x2018, 0x2019, 0x201c, 0x201d, 0xff08, 0xff09, 0x3014, 0x3015, 0xff3b, 0xff3d, 0xff5b,
                           0xff5d, 0x3008, 0x3009, 0x300c, 0x300d, 0xff0b, 0xff0d, 0xb1,   0xd7,   0xf7,   0xff1d,
                           0x221e, 0x2234, 0xb0,   0x2032, 0x2033, 0xff06, 0x2606, 0x2605, 0x25cb, 0x25cf, 0x25ce,
                           0x25c7, 0x25c6, 0x25a1, 0x25a0, 0x25b3, 0x25b2, 0x25bd, 0x25bc, 0x203b, 0x3012, 0x2192,
                           0x2190, 0x2191, 0x2193, 0x266f, 0x266d, 0x266a, 0x0};
        slotIndex = GetTestSceneInputSlot();
        moved = FALSE;
        if (gTestScene->mState == TEST_SCENE_STATE_CHAR_TABLE_0) {
            canvasIndex = 0;
        } else if (gTestScene->mState == TEST_SCENE_STATE_CHAR_TABLE_1) {
            canvasIndex = 1;
        } else if (gTestScene->mState == TEST_SCENE_STATE_CHAR_TABLE_2) {
            canvasIndex = 2;
        }
        if (GetInputSlotNewBitsByIndex(slotIndex, PAD_KEY_DIRECTION_LEFT) != 0) {
            gTestSceneCharTableIndex = (gTestSceneCharTableIndex + 8) % 9;
            ClearCharCanvas(gTestScene->mCharCanvases[canvasIndex], 0);
            moved = TRUE;
        } else if (GetInputSlotNewBitsByIndex(slotIndex, PAD_KEY_DIRECTION_RIGHT) != 0) {
            gTestSceneCharTableIndex = (gTestSceneCharTableIndex + 1) % 9;
            ClearCharCanvas(gTestScene->mCharCanvases[canvasIndex], 0);
            moved = TRUE;
        }
        if (moved != FALSE) {
            textIndex = 0;
            for (row = 0; row < 6; row++) {
                for (col = 0; col < 16; col++) {
                    if (gTestSceneCharTableIndex != 8) {
                        gTestSceneCharText[textIndex++] = row * 16 + col + charRangeStarts[gTestSceneCharTableIndex];
                    } else {
                        gTestSceneCharText[textIndex++] = charTable8Codes[row * 16 + col];
                    }
                }
                gTestSceneCharText[textIndex++] = 0xa;
            }
            TestSceneDrawTextOnCanvas(&gTestScene->mTextCanvases[canvasIndex], 0x80, 0x62,
                                      gTestScene->mState == TEST_SCENE_STATE_CHAR_TABLE_2 ? 6 : 7, 0x412,
                                      gTestSceneCharText);
        }
        GXS_LoadBG1Char(gTestScene->mChars, 0, 0x6000);
    }
    switch (gTestScene->mStateChanged) {
        case 0:
            WriteSubBg0Offset(0, 0);
            break;
        case 1:
        case 2:
        case 3:
            WriteSubBg1Offset(0, 0);
            break;
    }
    gTestScene->mStateChanged = 0;
}

#pragma thumb off

void *TestSceneGetCurrentHeap(void) {
    return GetHeap(GetCurrentHeapCall());
}

void TestSceneSetMainBg1Record(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7,
                               u32 cntVal8, u32 cntVal2, u32 cntVal13) {
    SetBg1Record(&displaySettings->mMainBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7, cntVal8, cntVal2, cntVal13);
}

void TestSceneSetMainBg2RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14,
                                     u32 cntVal7Or13, u32 cntVal8, u32 cntVal2) {
    SetBg2RecordParams(&displaySettings->mMainBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7Or13, cntVal8, cntVal2);
}

void TestSceneSetSubBg2RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14,
                                    u32 cntVal7Or13, u32 cntVal8, u32 cntVal2) {
    SetBg2RecordParams(&displaySettings->mSubBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7Or13, cntVal8, cntVal2);
}

void TestSceneInitTextCanvas(TextCanvas *textCanvas, void *charCanvas, void *font, s32 charSpacing, s32 lineSpacing) {
    textCanvas->mCharCanvas = charCanvas;
    textCanvas->mFont = font;
    textCanvas->mCharSpacing = charSpacing;
    textCanvas->mLineSpacing = lineSpacing;
}

#pragma thumb on

void InitTestSceneObject(void) {
    DisplaySettingsDesc displaySettingsDesc = {1, 0x16, 4, 1, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 4, 0, 0, 0, 8, 0};
    DisplaySettings *displaySettings;
    int canvasIndex;

    gTestScene = HeapAlloc(TestSceneGetCurrentHeap(), sizeof(TestScene));
    gTestScene->mUnk_0000 = 0;
    gTestScene->mState = TEST_SCENE_STATE_CHAR_TABLE_0;
    gTestScene->mStateChanged = 1;
    ClearChars(gTestScene->mChars);
    FillScreenMapIndices(gTestScene->mScreenMap);
    displaySettings = CreateDisplaySettings(TestSceneGetCurrentHeap(), &displaySettingsDesc);
    TestSceneSetMainBg1Record(displaySettings, 0, 0, 0, 0, 4, 0, 0);
    TestSceneSetMainBg2RecordParams(displaySettings, 2, 0, 0, 0, 0xe, 1);
    TestSceneSetSubBg2RecordParams(displaySettings, 2, 0, 0, 0, 4, 4);
    InitDisplayFromSettings(displaySettings);
    gTestScene->mFonts[0] = GetFontByIndex(0);
    gTestScene->mFonts[1] = GetFontByIndex(1);
    gTestScene->mFonts[2] = GetFontByIndex(2);
    for (canvasIndex = 0; canvasIndex < 3; canvasIndex++) {
        NNS_G2dCharCanvasInitForBG(gTestScene->mCharCanvases[canvasIndex], gTestScene->mChars, 0x20, 0x18, 4);
        TestSceneInitTextCanvas(&gTestScene->mTextCanvases[canvasIndex], gTestScene->mCharCanvases[canvasIndex],
                                gTestScene->mFonts[canvasIndex], 0, 0);
    }
    InitEmblemChoises();
}

void ReleaseTestSceneObject(void) {
    GetCurrentHeapCall();
    ClearEmblemChoisesPointer();
    gTestScene = NULL;
}

#pragma thumb off

u32 GetTestSceneInputSlot(void) {
    return 0x8u;
}

u16 TestSceneGetInputSlotNewBits(InputSlot *inputSlot, u32 mask) {
    return inputSlot->mPressedBits & mask;
}

u32 GetInputSlotNewBitsByIndex(u32 slotIndex, u32 mask) {
    return TestSceneGetInputSlotNewBits(&gInputSlots[slotIndex], mask);
}

#pragma thumb on

void UpdateTestSceneObject(SceneNumbers *sceneNumbers) {
    u32 slotIndex;
    TestScene *testScene;

    GetTestSceneInputSlot();
    SetLastTick();
    if (sceneNumbers != NULL) {
        slotIndex = GetTestSceneInputSlot();
        if (GetInputSlotNewBitsByIndex(slotIndex, PAD_KEY_A) != 0) {
            sceneNumbers->mNextScene = SCENE_TITLE;
        }
        if (GetInputSlotNewBitsByIndex(slotIndex, PAD_KEY_X) != 0) {
            testScene = gTestScene;
            testScene->mState = (testScene->mState + 1) % TEST_SCENE_STATE_COUNT;
            gTestScene->mStateChanged = 1;
            if (gTestScene->mState == TEST_SCENE_STATE_CHAR_TABLE_0) {
                SetEmblemChoisesShownAndReset(0);
            }
        }
    }
    switch (gTestScene->mState) {
        case TEST_SCENE_STATE_CHOISES:
            UpdateEmblemChoises();
            WriteEmblemChoisesScreenMapWrapper();
            break;
        case TEST_SCENE_STATE_CHAR_TABLE_0:
        case TEST_SCENE_STATE_CHAR_TABLE_1:
        case TEST_SCENE_STATE_CHAR_TABLE_2:
            break;
    }
}

void InitTestScene(void) {
    InitTestSceneObject();
}

void ReleaseTestScene(void) {
    ReleaseTestSceneObject();
}

void DrawTestSceneWrapper(void) {
    DrawTestScene();
}

void UpdateTestScene(SceneNumbers *sceneNumbers) {
    UpdateTestSceneObject(sceneNumbers);
}

int RunTestScene(void *sceneNumbers) {
    SceneCallbacks callbacks = {
        InitTestScene, UpdateTestScene, ReleaseTestScene, DrawTestSceneWrapper, 0, 0, 0x1e, 0x1e, 0};

    RunScene(sceneNumbers, &callbacks);
    return 0;
}
