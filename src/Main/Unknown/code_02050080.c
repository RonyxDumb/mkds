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

#pragma opt_rebuildconditionals off

static inline u32 func_02050080_inline(void) {
    if (gStruct217AA00 == NULL) {
        return 0;
    }
    return gStruct217AA00->field0;
}

u32 func_020501b0(u32 entryIndex) {
    u32 result = 0;
    ScanSlot *entry;
    ConnectionWork *q;
    u32 entryValid;

    if (entryIndex >= 4) {
        return 0;
    }
    if ((gStruct217AA00->field454 & 0x40) != 0) {
        entryValid = result;
        if (func_02050080_inline() != 2) {
            entryValid = 0;
        } else if (*(u16 *) 0x027ffc40 == 2) {
            entryValid = 0;
        } else if (gStruct217AA00->fieldAC[entryIndex].fieldDC_0 != 0) {
            entryValid = 1;
        }
        if (entryValid != 0) {
            StartRequestEndScan();
            result = 1;
        }
    } else {
        gStruct217AA00->field43B = 0;
        gStruct217AA00->field438 = 0;
        entry = &gStruct217AA00->fieldAC[entryIndex];
        gStruct217AA00->field436 &= ~1;
        if (entry->fieldDC_0 != 0) {
            MI_CpuCopy8(entry, gStruct217AA00->field24, 0xc0);
            DC_StoreRange(gStruct217AA00->field24, 0xc0);
            q = gStruct217AA00;
            *(Unk0217aa00_42c *) &q->field42C = entry->mUnk_c0_42c;
            q->field43C = entry->fieldDC_1;
            result = 1;
        }
    }
    return result;
}

void func_02050080(void) {
    BOOL proceed;
    u16 index;
    u16 participantCount;

    proceed = FALSE;
    if (func_02050080_inline() != 0 && gStruct217AA00->field4 != 13) {
        proceed = TRUE;
    }
    if (proceed == FALSE) {
        return;
    }
    index = 0;
    participantCount = 0;
    for (; index < 8; index++) {
        if ((gStruct217AA00->mParticipantMask & (1 << index)) != 0) {
            gStruct217AA00->field1E52[index].mEntryIndex = participantCount;
            gStruct217AA00->field1E8C[participantCount] = index;
            gStruct217AA00->mParticipantIndices[participantCount] = index;
            participantCount++;
        } else {
            gStruct217AA00->field1E52[index].mEntryIndex = 0xffff;
        }
    }
    for (; participantCount < 8; participantCount++) {
        gStruct217AA00->field1E8C[participantCount] = 0xffff;
        gStruct217AA00->mParticipantIndices[participantCount] = 0xffff;
    }
    if (scproc_getCurrentScene() == 2) {
        input_20431E4();
    } else {
        input_2043410();
    }
}
