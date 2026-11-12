#include "Main/Menu/emblem_choises_shown.h"
#include "Main/Menu/data_020ae000.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Sound/sound_seq.h"
#include "Main/MapObjects/data_0217b000.h"
#include "registers.h"
#include "g2.h"
#include "gx_load2d.h"
#include "Main/Menu/data_02175628.h"
#include "Main/Menu/data_0217d068.h"
#include "player.h"
#include "code_0212df7c.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/System/file_in_loaded.h"
#include "g2d_CharCanvas.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

EmblemChoises *gEmblemChoises;

#pragma thumb on
#pragma optimize_for_size on
s32 MoveEmblemChoisesIndex(s32 step) {
    s32 previousIndex;
    s32 choisesCount;

    previousIndex = gEmblemChoises->mChoisesIndex;
    if (gEmblemChoises->mShown != 0) {
        choisesCount = gEmblemChoises->mChoisesCount;
        if (step != 0) {
            gEmblemChoises->mCycleFrames = 0;
            StartSoundOncePerFrame(0);
        }
        gEmblemChoises->mChoisesIndex = (previousIndex + step + choisesCount) % choisesCount;
    }
    return previousIndex;
}

s32 MoveEmblemChoisesIndexByTouch(void) {
    BOOL touched;
    s32 choisesCount;
    BOOL zeroStep;
    s32 rectIndex;
    s32 choiceIndex;
    PairRect choiceRects[6];

    touched = FALSE;
    if (gEmblemChoises->mShown != 0) {
        MoveEmblemChoisesIndex(touched);
        choisesCount = gEmblemChoises->mChoisesCount;
        for (rectIndex = 0; rectIndex < choisesCount; rectIndex++) {
            s32 minY;

            minY = (12 - choisesCount * 2 + rectIndex * 4) * 8 + 6;
            choiceRects[rectIndex].mMinX = 8;
            choiceRects[rectIndex].mMaxX = 0xf8;
            choiceRects[rectIndex].mMinY = minY;
            choiceRects[rectIndex].mMaxY = minY + 0x16;
        }
        zeroStep = FALSE;
        for (choiceIndex = 0; choiceIndex < choisesCount; choiceIndex++) {
            if (IsNewPairInRect(GetEmblemChoisesInputSlot(), choiceRects[choiceIndex])) {
                if (gEmblemChoises->mChoisesIndex != choiceIndex) {
                    gEmblemChoises->mChoisesIndex = choiceIndex;
                    MoveEmblemChoisesIndex(zeroStep);
                } else {
                    gEmblemChoises->mPickStartedOnSelected = TRUE;
                }
                switch (gEmblemChoises->mChoisesIndex) {
                    case 0:
                        StartEmblemChoisesSound(0x10);
                        break;
                    case 1:
                        StartEmblemChoisesSound(0xb);
                        break;
                    case 2:
                        StartEmblemChoisesSound(5);
                        break;
                }
                touched = TRUE;
            }
        }
    }
    return touched;
}

void ResetEmblemChoisesState(void) {
    gEmblemChoises->mResult = -1;
    gEmblemChoises->mChoisesIndex = 0;
    gEmblemChoises->mCycleFrames = 0;
    gEmblemChoises->mPickStartedOnSelected = FALSE;
    gEmblemChoises->mPickFrames = 0;
    gEmblemChoises->mCloseFrames = 0;
}

void WriteEmblemChoisesChoiceTiles(u16 *mapData, s32 column, s32 row) {
    SetScreenMapBlockLowBits(mapData, column, row, 1, 1, 4);
    SetScreenMapBlockLowBits(mapData, column, row + 1, 1, 1, 0x24);
}

void WriteEmblemChoisesTiles(void) {
    s32 choisesCount;
    u16 *mapData;
    s32 choiceIndex;

    choisesCount = gEmblemChoises->mChoisesCount;
    mapData = gEmblemChoises->mChoisesS3Nscr->mData;
    if (mapData != NULL) {
        for (choiceIndex = 0; choiceIndex < choisesCount; choiceIndex++) {
            WriteEmblemChoisesChoiceTiles(mapData, 2, 13 - choisesCount * 2 + choiceIndex * 4);
        }
        SetScreenMapBlockTopBits(mapData, 0, 0, 0x20, 0x18, 0xf);
    }
}

void WriteEmblemChoisesSelectedTiles(s32 choiceIndex) {
    EmblemChoises *emblemChoises;
    s32 choisesCount;
    u16 *mapData;
    s32 firstRow;

    emblemChoises = gEmblemChoises;
    choisesCount = emblemChoises->mChoisesCount;
    mapData = emblemChoises->mChoisesS3Nscr->mData;
    if (mapData != NULL) {
        if (emblemChoises->mPickStartedOnSelected == FALSE || emblemChoises->mPickFrames >= 5) {
            firstRow = 13 - choisesCount * 2 + choiceIndex * 4;
            if (emblemChoises->mCycleFrames < 0x1e) {
                SetScreenMapBlockLowBits(mapData, 2, firstRow, 1, 1, 0x21);
                SetScreenMapBlockLowBits(mapData, 2, firstRow + 1, 1, 1, 0x41);
            }
            SetScreenMapBlockTopBits(mapData, 0, firstRow - 1, 0x20, 4, 0xe);
        }
    }
}
#pragma thumb off

#pragma thumb on

void WriteEmblemChoisesScreenMap(void) {
    WriteEmblemChoisesTiles();
    WriteEmblemChoisesSelectedTiles(MoveEmblemChoisesIndex(0));
}

#pragma thumb off

u32 GetSubDispcntBits(void) {
    return (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
}

u32 EmblemChoisesGXS_SetVisiblePlane(u32 bits) {
    u32 value0 = bits;
    u32 registerValue;
    registerValue = reg_GXS_DB_DISPCNT;
    registerValue = (registerValue) & ~(0x1f00u);
    value0 = (registerValue) | ((value0 << 8));
    reg_GXS_DB_DISPCNT = value0;
    return value0;
}

void EmblemChoisesWriteSubBg0Offset(u32 offsetX, u32 offsetY) {
    reg_G2S_DB_BG0OFS = (offsetX & 0x1ff) | ((offsetY << 16) & 0x1ff0000);
}

void WriteSubBlendBrightness(u32 plane1, u32 plane2, u32 ev1, u32 ev2, s32 brightness) {
    G2x_SetBlendBrightnessExt_(&reg_G2S_DB_BLDCNT, plane1, plane2, ev1, ev2, brightness);
}

void EmblemChoisesWriteSubBlendAlpha(u32 plane1, u32 plane2, u32 ev1, u32 ev2) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, plane1, plane2, ev1, ev2);
}

#pragma thumb on
#pragma optimize_for_size on
void DrawEmblemChoises(void) {
    if (gEmblemChoises->mGraphicsUploadRequested != FALSE) {
        GXS_LoadBGPltt(gEmblemChoises->mChoisesSBNclr->mData + 0xe0, 0x1c0, 0x40);
        GXS_LoadBG0Char(gEmblemChoises->mChoisesSBNcgr->mData, 0, 0x3000);
        gEmblemChoises->mGraphicsUploadRequested = FALSE;
    }
    if (gEmblemChoises->mShown != 0) {
        GXS_LoadBG0Scr(gEmblemChoises->mChoisesS3Nscr->mData, 0, 0x600);
    }
    if (gEmblemChoises->mShown != gEmblemChoises->mDrawnShown) {
        if (gEmblemChoises->mShown != 0) {
            EmblemChoisesGXS_SetVisiblePlane(GetSubDispcntBits() | 1);
            EmblemChoisesWriteSubBg0Offset(0, 0);
            WriteSubBlendBrightness(0x3e, 0x3f, 8, 8, -7);
        } else {
            EmblemChoisesGXS_SetVisiblePlane(GetSubDispcntBits() & ~1);
            if (gEmblemChoises->mHideCallback != NULL) {
                gEmblemChoises->mHideCallback();
            } else {
                EmblemChoisesWriteSubBlendAlpha(0, 0, 6, 10);
            }
        }
    }
    gEmblemChoises->mDrawnShown = gEmblemChoises->mShown;
}
#pragma thumb off

u32 GetEmblemChoisesInputSlot(void) {
    return 0x8u;
}

u16 EmblemChoisesGetInputSlotNewBits(InputSlot *slot, u32 mask) {
    return slot->mPressedBits & mask;
}

u16 EmblemChoisesGetNewBits(u32 slotIndex, u32 mask) {
    return EmblemChoisesGetInputSlotNewBits(&gInputSlots[slotIndex], mask);
}

u32 EmblemChoisesStartSeqArc(u32 seqIndex, u32 seqArcNo) {
    return NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, seqArcNo, seqIndex);
}

u32 StartEmblemChoisesSound(u32 seqIndex) {
    return EmblemChoisesStartSeqArc(seqIndex, 0u);
}

#pragma thumb on
#pragma optimize_for_size on
void UpdateEmblemChoises(void) {
    gEmblemChoises->mCycleFrames++;
    if (gEmblemChoises->mCycleFrames >= 0x32) {
        gEmblemChoises->mCycleFrames = 0;
    }
    if (gEmblemChoises->mPickFrames == 0 && gEmblemChoises->mCloseFrames == 0 && gEmblemChoises->mShown != 0 &&
        gEmblemChoises->mDrawnShown != 0) {
        if (MoveEmblemChoisesIndexByTouch()) {
            gEmblemChoises->mPickFrames = 1;
        } else if (EmblemChoisesGetNewBits(GetEmblemChoisesInputSlot(), PAD_KEY_A)) {
            gEmblemChoises->mPickFrames = 1;
            gEmblemChoises->mPickStartedOnSelected = TRUE;
            switch (gEmblemChoises->mChoisesIndex) {
                case 0:
                    StartEmblemChoisesSound(0x10);
                    break;
                case 1:
                    StartEmblemChoisesSound(0xb);
                    break;
                case 2:
                    StartEmblemChoisesSound(5);
                    break;
            }
        } else if (EmblemChoisesGetNewBits(GetEmblemChoisesInputSlot(), PAD_KEY_B | PAD_KEY_START)) {
            gEmblemChoises->mCloseFrames = 1;
            StartEmblemChoisesSound(0x10);
        }
        if (EmblemChoisesGetNewBits(GetEmblemChoisesInputSlot(), PAD_KEY_UP)) {
            MoveEmblemChoisesIndex(-1);
        } else if (EmblemChoisesGetNewBits(GetEmblemChoisesInputSlot(), PAD_KEY_DOWN)) {
            MoveEmblemChoisesIndex(1);
        }
    }
    if (gEmblemChoises->mPickFrames != 0) {
        gEmblemChoises->mPickFrames++;
        if (gEmblemChoises->mPickFrames > 0xf) {
            if (gEmblemChoises->mShown != 0) {
                gEmblemChoises->mResult = gEmblemChoises->mChoisesIndex;
                gEmblemChoises->mPickFrames = 0;
            }
            gEmblemChoises->mPickFrames = 0;
            gEmblemChoises->mPickStartedOnSelected = FALSE;
        }
    }
    if (gEmblemChoises->mCloseFrames != 0) {
        gEmblemChoises->mCloseFrames++;
        if (gEmblemChoises->mCloseFrames > 4) {
            if (gEmblemChoises->mShown != 0) {
                gEmblemChoises->mResult = -2;
                gEmblemChoises->mPickFrames = 0;
            }
            gEmblemChoises->mCloseFrames = 0;
        }
    }
}
#pragma thumb off

#pragma thumb on
void WriteEmblemChoisesScreenMapWrapper(void) {
    u32 unusedValue;
    WriteEmblemChoisesScreenMap();
}
#pragma thumb off

void *EmblemChoisesGetCurrentHeap(void) {
    void *value0;
    value0 = GetCurrentHeapCall();
    value0 = GetHeap(value0);
    return value0;
}

void EmblemChoisesInitTextCanvas(TextCanvas *textCanvas, void *charCanvas, void *font, s32 charSpacing,
                                 s32 lineSpacing) {
    textCanvas->mCharCanvas = charCanvas;
    textCanvas->mFont = font;
    textCanvas->mCharSpacing = charSpacing;
    textCanvas->mLineSpacing = lineSpacing;
}

u32 EmblemChoisesDrawTextOnCanvas(TextCanvas *textCanvas, s32 textX, s32 textY, u32 color, u32 flags, void *text) {
    return NNSi_G2dTextCanvasDrawText(textCanvas, textX, textY, color, flags, text);
}

#pragma thumb on
#pragma optimize_for_size on
void InitEmblemChoises(void) {
    EmblemChoises *emblemChoises;

    gEmblemChoises = HeapAlloc(EmblemChoisesGetCurrentHeap(), 0x6c);
    gEmblemChoises->mShown = 0;
    gEmblemChoises->mDrawnShown = 1;
    gEmblemChoises->mGraphicsUploadRequested = FALSE;
    gEmblemChoises->mHideCallback = NULL;
    ResetEmblemChoisesState();
    gEmblemChoises->mCycleFrames = 0;
    gEmblemChoises->mPickStartedOnSelected = FALSE;
    gEmblemChoises->mPickFrames = 0;
    gEmblemChoises->mCloseFrames = 0;
    gEmblemChoises->mChoisesCount = 3;
    LoadNclrData(&gEmblemChoises->mChoisesSBNclr, FindSceneFileWrapper("choises_s_b.NCLR"));
    LoadNcgrData(&gEmblemChoises->mChoisesSBNcgr, FindSceneFileWrapper("choises_s_b.NCGR"));
    LoadNscrData(&gEmblemChoises->mChoisesS3Nscr, FindSceneFileWrapper("choises_s_3.NSCR"));
    gEmblemChoises->mFont = GetFontByIndex(2);
    NNS_G2dCharCanvasInitForBG(&gEmblemChoises->mCharCanvas, gEmblemChoises->mChoisesSBNcgr->mData, 0x20, 0xc, 4);
    emblemChoises = gEmblemChoises;
    EmblemChoisesInitTextCanvas(&emblemChoises->mTextCanvas, &emblemChoises->mCharCanvas, emblemChoises->mFont,
                                IsLanguageJa(), 0);
    {
        s32 bmgIndices[3] = {2, 0, 1};
        s32 choiseIndex;

        for (choiseIndex = 0; choiseIndex < gEmblemChoises->mChoisesCount; choiseIndex++) {
            EmblemChoisesDrawTextOnCanvas(&gEmblemChoises->mTextCanvas, 0x90, choiseIndex * 16 + 9, 12, 0x412,
                                          GetBmgEntry(FindSceneFileWrapper("emblem.bmg"), bmgIndices[choiseIndex]));
        }
    }
}
#pragma thumb off

#pragma thumb on
void ClearEmblemChoisesPointer(void) {
    gEmblemChoises = NULL;
}
#pragma thumb off

#pragma thumb on
void RequestEmblemChoisesGraphicsUpload(void) {
    gEmblemChoises->mGraphicsUploadRequested = TRUE;
}
#pragma thumb off

#pragma thumb on

u32 GetEmblemChoisesResult(void) {
    return (gEmblemChoises->mResult);
}

#pragma thumb off

#pragma thumb on
void SetEmblemChoisesShownAndReset(u32 shown) {
    gEmblemChoises->mShown = shown;
    ResetEmblemChoisesState();
}
#pragma thumb off

s32 CreateRaceHudSubScreenShine16Cells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenShine16Cells, MAP_OBJECT_KIND_SHINE16);
}
