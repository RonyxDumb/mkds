#include "Main/Net/parent_block_transfer.h"
#include "Main/Net/zero_word_received.h"
#include "Main/MapObjects/data_0217a000.h"

#pragma thumb on

void ParentBlockTransferCallback(WBTCommand *record) {
    s32 callbackCode = record->mEvent;
    if (callbackCode == XFER_EVENT_CUSTOM_ARRIVED) {
        SetZeroWordReceived(&record->mData.mUserDataWord, record->mData.mUserData.mSize);
        return;
    }
    switch (gConnectionWork->mParentTransferStep) {
        case PARENT_TRANSFER_WAIT_HANDSHAKE:
            if (callbackCode == XFER_EVENT_HANDSHAKE_ASKED) {
                gConnectionWork->mParentTransferStep = PARENT_TRANSFER_WAIT_FIRST_CHUNKS;
            }
            break;
        case PARENT_TRANSFER_WAIT_FIRST_CHUNKS:
            if (callbackCode == XFER_EVENT_ALL_CHUNKS_HELD) {
                gConnectionWork->mParentTransferStep = PARENT_TRANSFER_WAIT_SECOND_CHUNKS;
            }
            break;
        case PARENT_TRANSFER_WAIT_SECOND_CHUNKS:
            if (callbackCode == XFER_EVENT_ALL_CHUNKS_HELD) {
                gConnectionWork->mTransferFlags |= CONNECTION_TRANSFER_SEQUENCE_DONE;
                gConnectionWork->mParentTransferStep = PARENT_TRANSFER_WAIT_HANDSHAKE;
            }
            break;
    }
}

#pragma thumb off
