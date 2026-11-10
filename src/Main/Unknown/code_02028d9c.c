#include "Main/Unknown/code_02028d9c.h"
#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02028000.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_0201e000.h"

#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_0201ea30.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02027e78.h"

void *GetCellLayoutEntrySwapped(s32 index, LayoutEntryTable *cellLayout) {
    return GetCellLayoutEntry(cellLayout, index);
}

#pragma thumb on

void SetKartMenuParamElementOffset(s32 elementIndex, s32 endCellIndex, s32 paramValue, CellFileSet *parts) {
    LayoutAxis *startCell = GetCellLayoutEntrySwapped(elementIndex, parts->mCellLayout);
    LayoutAxis *endCell = GetCellLayoutEntrySwapped(endCellIndex, parts->mCellLayout);
    parts->mCellTable[elementIndex].mOffsetX = (100 - paramValue) * (endCell->mUnk_00_0 - startCell->mUnk_00_0) / 100;
}

#pragma thumb off

#pragma thumb on

void RefreshKartMenuParamElements(void) {
    int result;
    CellFileSet *parts;
    short *params;
    result = SelectKartMB_IsMultiBootChildWrapper();
    if (result == 0) {
        params = ComputeKartMenuParams(gSelectKart->mKartIndex, gSelectKart->mCharacterIndex);
        parts = &gSelectKart->mSelectKartSParts;
        SetKartMenuParamElementOffset(10, 0x10, *params, parts);
        SetKartMenuParamElementOffset(9, 0xf, params[1], parts);
        SetKartMenuParamElementOffset(8, 0xe, params[2], parts);
        SetKartMenuParamElementOffset(7, 0xd, params[3], parts);
        SetKartMenuParamElementOffset(6, 0xc, params[4], parts);
        SetKartMenuParamElementOffset(5, 0xb, params[5], parts);
    }
}

#pragma thumb off

void SelectKartMI_CpuFillFast(void *destination, u32 value, u32 size) {
    volatile u32 valueCopy = value;
    MIi_CpuClearFast(valueCopy, destination, size);
}

void SelectKartMI_CpuClearFast(void *destination, u32 size) {
    SelectKartMI_CpuFillFast(destination, 0, size);
}

u16 GetOwnIndexOrZero(void) {
    int index;
    if (gConnectionWork->mConnectionMode == 2) {
        index = gConnectionWork->mOwnIndex;
    } else {
        index = 0;
    }
    return index;
}

u32 GetParticipantEntryIndex(u32 participantIndex) {
    return (gConnectionWork->mUnk_1e52[participantIndex].mEntryIndex);
}

u32 GetOwnEntryIndex(void) {
    u32 value0;
    value0 = GetOwnIndexOrZero();
    value0 = GetParticipantEntryIndex(value0);
    return value0;
}
