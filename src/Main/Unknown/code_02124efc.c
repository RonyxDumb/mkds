#include "Main/Unknown/code_02124efc.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02146c98.h"

#pragma thumb on

void InitLayoutTableEntries(LayoutTableEntry *entry, s32 count) {
    s32 entryIndex;

    for (entryIndex = 0; entryIndex < count; entryIndex++) {
        entry->mVisible = 1;
        entry->mOffsetX = 0;
        entry->mOffsetY = 0;
        entry->mUsePosition = FALSE;
        entry->mPositionX = 0;
        entry->mPositionY = 0;
        entry->mUseMatrix = 0;
        MTX_Identity22_(&entry->mInverseScaleMatrix);
        MTX_Identity22_(&entry->mMatrix);
        entry->mDoubleAffine = 1;
        entry->mLabelIndex = -1;
        entry->mLabelCanvas = NULL;
        entry++;
    }
}

#pragma thumb off
