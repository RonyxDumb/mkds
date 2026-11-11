#include "Main/Unknown/code_02028f20.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Unknown/code_02027e78.h"
#include "Main/Unknown/code_02028ff8.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_0202b604.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02124094.h"

#pragma optimize_for_size on
#pragma thumb on
void SetSelectKartSPartsOffsetY(void) {
    CellFileSet *parts;
    s32 cellIndex;
    s32 count;
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        parts = &gSelectKart->mSelectKartSParts;
        count = GetCellLayoutCount(parts->mCellLayout) + GetLabelLayoutCount(parts->mLabelLayout);
        for (cellIndex = 0; cellIndex < count; cellIndex++) {
            parts->mCellTable[cellIndex].mOffsetY = GetInterpolatedValue(&gSelectKart->mInterpolations[4]);
        }
    }
}

u32 IsSelectKartModeAndTimerZero(void) {
    u32 result = 0;
    if (gSelectKart->mMode != 0 && IsPlayerEntryListTimerZero() != 0) {
        result = 1;
    }
    return result;
}

void PrintSelectKartMessage(void) {
    s32 labelIndex;
    CellFileSet *parts;
    void *message;
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        message = GetBmgEntry(gSelectKart->mKartSelectMessages, GetKartMessageIndex(gSelectKart->mKartIndex));
        parts = &gSelectKart->mSelectKartSParts;
        for (labelIndex = 8; labelIndex >= 7; labelIndex--) {
            PrintLabelLayoutTextNoFixedAdvance(1, data_usa_021537f4[labelIndex].mLabelIndex, parts->mLabelLayout,
                                               message, parts->mCellLayout, parts->mCellTable);
        }
    }
}
#pragma thumb off
