#include "Main/Unknown/code_02050080.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02043000.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200eddc.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0211d4a8.h"

#pragma opt_rebuildconditionals off

static inline u32 func_02050080_inline(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

u32 TrySelectScanSlot(u32 entryIndex) {
    u32 result = 0;
    ScanSlot *entry;
    ConnectionWork *connectionWork;
    u32 entryValid;

    if (entryIndex >= 4) {
        return 0;
    }
    if ((gConnectionWork->mUnk_0454 & 0x40) != 0) {
        entryValid = result;
        if (func_02050080_inline() != 2) {
            entryValid = 0;
        } else if (gBootInfo->mUnk_00 == 2) {
            entryValid = 0;
        } else if (gConnectionWork->mUnk_00ac[entryIndex].mInUse != 0) {
            entryValid = 1;
        }
        if (entryValid != 0) {
            StartRequestEndScan();
            result = 1;
        }
    } else {
        gConnectionWork->mUnk_043b = 0;
        gConnectionWork->mUnk_0438 = 0;
        entry = &gConnectionWork->mUnk_00ac[entryIndex];
        gConnectionWork->mUnk_0436 &= ~1;
        if (entry->mInUse != 0) {
            MI_CpuCopy8(entry, gConnectionWork->mParentBssDesc, 0xc0);
            DC_StoreRange(gConnectionWork->mParentBssDesc, 0xc0);
            connectionWork = gConnectionWork;
            connectionWork->mUnk_042c = entry->mKey;
            connectionWork->mUnk_043c = entry->mLanguageIndex;
            result = 1;
        }
    }
    return result;
}

void RefreshParticipantTables(void) {
    BOOL proceed;
    u16 index;
    u16 participantCount;

    proceed = FALSE;
    if (func_02050080_inline() != 0 && gConnectionWork->mState != 13) {
        proceed = TRUE;
    }
    if (proceed == FALSE) {
        return;
    }
    index = 0;
    participantCount = 0;
    for (; index < 8; index++) {
        if ((gConnectionWork->mParticipantMask & (1 << index)) != 0) {
            gConnectionWork->mUnk_1e52[index].mEntryIndex = participantCount;
            gConnectionWork->mUnk_1e8c[participantCount] = index;
            gConnectionWork->mParticipantIndices[participantCount] = index;
            participantCount++;
        } else {
            gConnectionWork->mUnk_1e52[index].mEntryIndex = 0xffff;
        }
    }
    for (; participantCount < 8; participantCount++) {
        gConnectionWork->mUnk_1e8c[participantCount] = 0xffff;
        gConnectionWork->mParticipantIndices[participantCount] = 0xffff;
    }
    if (GetCurrentSceneNumber() == 2) {
        ResetInputSlotsFromRaceSetup();
    } else {
        ResetInputSlotsFromParticipants();
    }
}
