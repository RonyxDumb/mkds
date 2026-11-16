#include "Main/Net/parent_block_transfer.h"
#include "Main/Net/zero_word_received.h"
#include "Main/System/backup_net_camera_work.h"

#pragma thumb on

void ParentBlockTransferCallback(WBTCommand *record) {
    s32 callbackCode = record->mEvent;
    if (callbackCode == XFER_EVENT_CUSTOM_ARRIVED) {
        SetZeroWordReceived(&record->mData.mUserDataWord, record->mData.mUserData.mSize);
        return;
    }
    switch (g_GlobalZE->mParentTransferStep) {
        case PARENT_TRANSFER_WAIT_HANDSHAKE:
            if (callbackCode == XFER_EVENT_HANDSHAKE_ASKED) {
                g_GlobalZE->mParentTransferStep = PARENT_TRANSFER_WAIT_FIRST_CHUNKS;
            }
            break;
        case PARENT_TRANSFER_WAIT_FIRST_CHUNKS:
            if (callbackCode == XFER_EVENT_ALL_CHUNKS_HELD) {
                g_GlobalZE->mParentTransferStep = PARENT_TRANSFER_WAIT_SECOND_CHUNKS;
            }
            break;
        case PARENT_TRANSFER_WAIT_SECOND_CHUNKS:
            if (callbackCode == XFER_EVENT_ALL_CHUNKS_HELD) {
                g_GlobalZE->mTransferFlags |= CONNECTION_TRANSFER_SEQUENCE_DONE;
                g_GlobalZE->mParentTransferStep = PARENT_TRANSFER_WAIT_HANDSHAKE;
            }
            break;
    }
}

#pragma thumb off
