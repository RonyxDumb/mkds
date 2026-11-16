#include "Main/Unknown/code_020caba4.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020ca984.h"
#include "Main/Unknown/code_020ca9dc.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
s32 echoi_moveCursor(s32 step) {
    s32 previousIndex;
    s32 choisesCount;

    previousIndex = echoi_sState->mChoisesIndex;
    if (echoi_sState->mShown != 0) {
        choisesCount = echoi_sState->mChoisesCount;
        if (step != 0) {
            echoi_sState->field24 = 0;
            sfx_2105AC0(0);
        }
        echoi_sState->mChoisesIndex = (previousIndex + step + choisesCount) % choisesCount;
    }
    return previousIndex;
}

s32 echoi_handleTouch(void) {
    BOOL touched;
    s32 choisesCount;
    BOOL zeroStep;
    s32 i;
    s32 j;
    PairRect choiceRects[6];

    touched = FALSE;
    if (echoi_sState->mShown != 0) {
        echoi_moveCursor(touched);
        choisesCount = echoi_sState->mChoisesCount;
        for (i = 0; i < choisesCount; i++) {
            s32 minY;

            minY = (12 - choisesCount * 2 + i * 4) * 8 + 6;
            choiceRects[i].mMinX = 8;
            choiceRects[i].mMaxX = 0xf8;
            choiceRects[i].mMinY = minY;
            choiceRects[i].mMaxY = minY + 0x16;
        }
        zeroStep = FALSE;
        for (j = 0; j < choisesCount; j++) {
            if (IsNewPairInRect(echoi_input_getDefaultInputId(), choiceRects[j])) {
                if (echoi_sState->mChoisesIndex != j) {
                    echoi_sState->mChoisesIndex = j;
                    echoi_moveCursor(zeroStep);
                } else {
                    echoi_sState->field10 = TRUE;
                }
                switch (echoi_sState->mChoisesIndex) {
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

void echoi_resetSelectedOption(void) {
    echoi_sState->mResult = -1;
    echoi_sState->mChoisesIndex = 0;
    echoi_sState->field24 = 0;
    echoi_sState->field10 = FALSE;
    echoi_sState->field14 = 0;
    echoi_sState->field18 = 0;
}

void echoi_renderOptionBar(u16 *mapData, s32 column, s32 row) {
    m2d_setCharMapCharName2d(mapData, column, row, 1, 1, 4);
    m2d_setCharMapCharName2d(mapData, column, row + 1, 1, 1, 0x24);
}

void echoi_renderChoicesUnselected(void) {
    s32 choisesCount;
    u16 *mapData;
    s32 i;

    choisesCount = echoi_sState->mChoisesCount;
    mapData = echoi_sState->mChoisesS3Nscr->mData;
    if (mapData != NULL) {
        for (i = 0; i < choisesCount; i++) {
            echoi_renderOptionBar(mapData, 2, 13 - choisesCount * 2 + i * 4);
        }
        m2d_setCharMapPalette2d(mapData, 0, 0, 0x20, 0x18, 0xf);
    }
}

void echoi_renderSelection(s32 choiceIndex) {
    EmblemChoises *emblemChoises;
    s32 choisesCount;
    u16 *mapData;
    s32 firstRow;

    emblemChoises = echoi_sState;
    choisesCount = emblemChoises->mChoisesCount;
    mapData = emblemChoises->mChoisesS3Nscr->mData;
    if (mapData != NULL) {
        if (emblemChoises->field10 == FALSE || emblemChoises->field14 >= 5) {
            firstRow = 13 - choisesCount * 2 + choiceIndex * 4;
            if (emblemChoises->field24 < 0x1e) {
                m2d_setCharMapCharName2d(mapData, 2, firstRow, 1, 1, 0x21);
                m2d_setCharMapCharName2d(mapData, 2, firstRow + 1, 1, 1, 0x41);
            }
            m2d_setCharMapPalette2d(mapData, 0, firstRow - 1, 0x20, 4, 0xe);
        }
    }
}
#pragma thumb off
