#include "Main/Unknown/code_0204ea94.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on

void func_0204eca0(void) {
    gStruct217AA00->fieldC = 0x2d;
    gStruct217AA00->mRequestPending = 1;
    StopBlockTransfer();
    gStruct217AA00->field454 &= ~0x200;
    gStruct217AA00->mRequestPending = 0;
}

void SetScanGhostInfo(u32 entryIndex, Unk0217aa00_24_50 *gameInfo) {
    gStruct217AA00->mScanGhostInfos[entryIndex].mKartIndex = gameInfo->fieldE.mKartIndex;
    gStruct217AA00->mScanGhostInfos[entryIndex].mCharacterIndex = gameInfo->mCharacterIndex;
    gStruct217AA00->mScanGhostInfos[entryIndex].mCourseId = GetCupCourseIdAtIndex((u8) gameInfo->mCupCourseIndex);
    gStruct217AA00->mScanGhostInfos[entryIndex].mMinute = gameInfo->mMinute;
    gStruct217AA00->mScanGhostInfos[entryIndex].mSecond = gameInfo->mSecond;
    gStruct217AA00->mScanGhostInfos[entryIndex].mMillisecond = gameInfo->mMillisecond;
}

static inline u32 func_0204eb08_inline(void) {
    if (gStruct217AA00 == NULL) {
        return 0;
    }
    return gStruct217AA00->field0;
}

BOOL TryGetScanGhostInfo(u8 entryIndex, void *destination, u8 *kartIndex, u8 *characterIndex, u8 *courseId, u8 *minute,
                         u8 *second, u16 *millisecond) {
    if (func_0204ff14(entryIndex, destination) == 0) {
        return FALSE;
    }
    *kartIndex = gStruct217AA00->mScanGhostInfos[entryIndex].mKartIndex;
    *characterIndex = gStruct217AA00->mScanGhostInfos[entryIndex].mCharacterIndex;
    *courseId = gStruct217AA00->mScanGhostInfos[entryIndex].mCourseId;
    *minute = gStruct217AA00->mScanGhostInfos[entryIndex].mMinute;
    *second = gStruct217AA00->mScanGhostInfos[entryIndex].mSecond;
    *millisecond = gStruct217AA00->mScanGhostInfos[entryIndex].mMillisecond;
    return TRUE;
}

BOOL func_0204eb08(void *destination) {
    BOOL found;
    u8 index;
    u8 childMask;
    u32 childCount;

    found = FALSE;
    if (func_0204eb08_inline() == 1) {
        if ((gStruct217AA00->field454 & 0x40) != 0) {
            childCount = gStruct217AA00->field1699;
        } else {
            childCount = gStruct217AA00->field44.mChildCount;
        }
    } else {
        childCount = 0;
    }
    if (childCount != 1) {
        return FALSE;
    }
    if (func_0204eb08_inline() != 1) {
        return FALSE;
    }
    index = 1;
    childMask = gStruct217AA00->field44.mChildMask;
    do {
        if ((childMask & (1 << index)) != 0) {
            MI_CpuCopy8(&gStruct217AA00->field45C[index], destination, 0x14);
            found = TRUE;
            break;
        }
        index = index + 1;
    } while (index < 8);
    return found;
}

void func_0204ead0(u16 a, s32 b) {
    s32 v;

    v = b;
    gStruct217AA00->fieldC = 0x2e;
    gStruct217AA00->mRequestPending = 1;
    if (RequestSendBytes(a, &v, 4, (void (*)(void)) func_0204ea94) == 0) {
        gStruct217AA00->mRequestPending = 0;
    }
}

void func_0204ea94(BlockTransferRecord *record) {
    if (record->mKind == 10) {
        if (record->mCallbackCode == 11) {
            gStruct217AA00->mRequestPending = 0;
            return;
        }
        func_02050e60(8);
    } else {
        func_02050e60(8);
    }
}

#pragma thumb off
