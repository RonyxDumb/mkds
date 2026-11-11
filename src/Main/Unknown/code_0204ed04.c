#include "Main/Unknown/code_0204ed04.h"
#include "Main/Unknown/code_0200692c.h"
#include "Main/Unknown/code_02006380.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200eddc.h"
#include "code_02142eac.h"
#include "code_0214d018.h"

#pragma thumb on
void SetBlockEntryBuffer(u32 entryIndex, void *buffer) {
    gConnectionWork->mBlockEntries[entryIndex].mBuffer = buffer;
}
#pragma thumb off

#pragma thumb on
void PacketPortSendCallback(void) {
    gConnectionWork->mTransferFlags &= ~1;
}
#pragma thumb off

#pragma thumb on

void QueuePacketToPort(void) {
    u16 packetSize;
    u16 destMask;
    if (!(gConnectionWork->mTransferFlags & 1)) {
        u32 connectionMode;
        if (gConnectionWork == NULL) {
            connectionMode = 0;
        } else {
            connectionMode = gConnectionWork->mConnectionMode;
        }
        switch (connectionMode) {
            case 1:
                data_usa_0216522c.mMaxDataSize = 0x192;
                packetSize = WBT_MpParentSendHook(gConnectionWork->mPacketBuffer, 0x192);
                destMask = gConnectionWork->mChildren.mChildMask;
                break;
            case 2:
                data_usa_0216522c.mMaxDataSize = 0xe;
                packetSize = WBT_MpChildSendHook(gConnectionWork->mPacketBuffer, 0xe);
                destMask = 1;
                break;
        }
        if (QueueMPDataToPort(gConnectionWork->mPacketBuffer, packetSize, destMask, NULL, &data_usa_0216522c) ==
            FALSE) {
            gConnectionWork->mSendTimer = data_usa_02165228;
            gConnectionWork->mTransferFlags &= ~1;
        }
    }
}

void PacketPortCallback(Unk021425e8 *result) {
    u8 packet[0x192];
    u32 v;
    if (result->mResultCode == 0 && result->mUnk_0c != NULL && result->mUnk_10 <= 0x192) {
        DC_InvalidateRange(result->mUnk_0c, result->mUnk_10);
        MI_CpuCopy8(result->mUnk_0c, packet, result->mUnk_10);
        if (result->mUnk_04 == 7) {
            return;
        }
        if (result->mUnk_04 == 9) {
            return;
        }
        if (result->mUnk_04 == 0x15) {
            if (gConnectionWork == NULL) {
                v = 0;
            } else {
                v = gConnectionWork->mConnectionMode;
            }
            switch (v) {
                case 1:
                    WBT_MpParentRecvHook(packet, result->mUnk_10, result->mUnk_12);
                    break;
                case 2:
                    WBT_MpChildRecvHook(packet, result->mUnk_10);
                    break;
            }
        }
    }
}

#pragma thumb off
