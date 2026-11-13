#include "Main/Net/packet_port.h"
#include "Main/Net/wbt_mp_parent_recv.h"
#include "Main/Net/append_bytes.h"
#include "Main/Net/wbt_requests.h"
#include "os_thread.h"
#include "Main/Net/disconnect.h"
#include "Main/MapObjects/data_02165000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/MapObjects/data_0217a000.h"
#include "code_0200eddc.h"
#include "code_02142eac.h"
#include "code_0214d018.h"

u16 gPacketSendTimerFrames = 0x3c;
QueueMPDataToPortParams gPacketPortParams = {PacketPortSendCallback, 0, {0, 0}, 1, 2, {0, 0}};

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
                gPacketPortParams.mMaxDataSize = 0x192;
                packetSize = WBT_MpParentSendHook(gConnectionWork->mPacketBuffer, 0x192);
                destMask = gConnectionWork->mChildren.mChildMask;
                break;
            case 2:
                gPacketPortParams.mMaxDataSize = 0xe;
                packetSize = WBT_MpChildSendHook(gConnectionWork->mPacketBuffer, 0xe);
                destMask = 1;
                break;
        }
        if (QueueMPDataToPort(gConnectionWork->mPacketBuffer, packetSize, destMask, NULL, &gPacketPortParams) ==
            FALSE) {
            gConnectionWork->mSendTimer = gPacketSendTimerFrames;
            gConnectionWork->mTransferFlags &= ~1;
        }
    }
}

void PacketPortCallback(WirelessMessage *result) {
    u8 packet[0x192];
    u32 connectionMode;
    if (result->mResultCode == 0 && result->mData != NULL && result->mLength <= 0x192) {
        DC_InvalidateRange(result->mData, result->mLength);
        MI_CpuCopy8(result->mData, packet, result->mLength);
        if (result->mState == 7) {
            return;
        }
        if (result->mState == 9) {
            return;
        }
        if (result->mState == 0x15) {
            if (gConnectionWork == NULL) {
                connectionMode = 0;
            } else {
                connectionMode = gConnectionWork->mConnectionMode;
            }
            switch (connectionMode) {
                case 1:
                    WBT_MpParentRecvHook(packet, result->mLength, result->mAid);
                    break;
                case 2:
                    WBT_MpChildRecvHook(packet, result->mLength);
                    break;
            }
        }
    }
}

#pragma thumb off
