#include "Main/Net/parent_block_transfer.h"
#include "Main/Net/zero_word_received.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void ParentBlockTransferCallback(WBTCommand *record) {
    s32 callbackCode = record->mEvent;
    if (callbackCode == 10) {
        SetZeroWordReceived(&record->mData.mUserDataWord, record->mData.mUserData.mSize);
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
