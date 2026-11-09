#include "Main/Unknown/code_020ca6c4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020caba4.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ca820.h"
#include "Main/Unknown/unk_0217b000.h"
#include "g2d_CharCanvas.h"

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
        s32 i;

        for (i = 0; i < gEmblemChoises->mChoisesCount; i++) {
            EmblemChoisesDrawTextOnCanvas(&gEmblemChoises->mTextCanvas, 0x90, i * 16 + 9, 12, 0x412,
                                          GetBmgEntry(FindSceneFileWrapper("emblem.bmg"), bmgIndices[i]));
        }
    }
}
#pragma thumb off
