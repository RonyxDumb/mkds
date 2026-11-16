#include "Main/Unknown/code_020ca6c4.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020caba4.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ca820.h"
#include "Main/Unknown/unk_0217b000.h"
#include "g2d_CharCanvas.h"

void echoi_NNS_G2dTextCanvasInit(TextCanvas *textCanvas, void *charCanvas, void *c, s32 d, s32 e) {
    textCanvas->mCharCanvas = charCanvas;
    textCanvas->mFont = c;
    textCanvas->mCharSpacing = d;
    textCanvas->mLineSpacing = e;
}

u32 echoi_NNS_G2dTextCanvasDrawText(TextCanvas *textCanvas, s32 x, s32 y, u32 d, u32 e, void *text) {
    return NNSi_G2dTextCanvasDrawText(textCanvas, x, y, d, e, text);
}

#pragma thumb on
#pragma optimize_for_size on
void echoi_init(void) {
    EmblemChoises *emblemChoises;

    echoi_sState = heap_alloc(echoi_proc_getCurrentHeap(), 0x6c);
    echoi_sState->mShown = 0;
    echoi_sState->field4 = 1;
    echoi_sState->mGraphicsUploadRequested = FALSE;
    echoi_sState->fieldC = NULL;
    echoi_resetSelectedOption();
    echoi_sState->field24 = 0;
    echoi_sState->field10 = FALSE;
    echoi_sState->field14 = 0;
    echoi_sState->field18 = 0;
    echoi_sState->mChoisesCount = 3;
    g2du_unpackPaletteData(&echoi_sState->mChoisesSBNclr, m2d_getSceneArcFile("choises_s_b.NCLR"));
    g2du_unpackCharacterDataBG(&echoi_sState->mChoisesSBNcgr, m2d_getSceneArcFile("choises_s_b.NCGR"));
    g2du_unpackScreenData(&echoi_sState->mChoisesS3Nscr, m2d_getSceneArcFile("choises_s_3.NSCR"));
    echoi_sState->field2C = m2d_getFont(2);
    NNS_G2dCharCanvasInitForBG(&echoi_sState->field30, echoi_sState->mChoisesSBNcgr->mData, 0x20, 0xc, 4);
    emblemChoises = echoi_sState;
    echoi_NNS_G2dTextCanvasInit(&emblemChoises->field50, &emblemChoises->field30, emblemChoises->field2C, g2du_getTextHSpace(), 0);
    {
        s32 bmgIndices[3] = {2, 0, 1};
        s32 i;

        for (i = 0; i < echoi_sState->mChoisesCount; i++) {
            echoi_NNS_G2dTextCanvasDrawText(&echoi_sState->field50, 0x90, i * 16 + 9, 12, 0x412,
                          jn_msg_getMessage(m2d_getSceneArcFile("emblem.bmg"), bmgIndices[i]));
        }
    }
}
#pragma thumb off
