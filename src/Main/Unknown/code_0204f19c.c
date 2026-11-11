#include "Main/Unknown/code_0204f19c.h"
#include "Main/Unknown/code_0204f220.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void ParentBlockTransferCallback(WBTCommand *record) {
    s32 callbackCode = record->mEvent;
    if (callbackCode == 10) {
        SetZeroWordReceived(&record->mUnk_14.w.mUnk_14, record->mUnk_14.b.mUnk_1d);
        return;
    }
    switch (gConnectionWork->mParentTransferStep) {
        case 0:
            if (callbackCode == 2) {
                gConnectionWork->mParentTransferStep = 1;
            }
            break;
        case 1:
            if (callbackCode == 8) {
                gConnectionWork->mParentTransferStep = 2;
            }
            break;
        case 2:
            if (callbackCode == 8) {
                gConnectionWork->mTransferFlags |= CONNECTION_TRANSFER_SEQUENCE_DONE;
                gConnectionWork->mParentTransferStep = 0;
            }
            break;
    }
}

#pragma thumb off
