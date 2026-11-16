#include "Main/Net/packet_port.h"
#include "Main/Net/wireless_block_parent_recv.h"
#include "Main/Net/append_bytes.h"
#include "Main/Net/wireless_block_requests.h"
#include "thread_scheduler.h"
#include "Main/Net/disconnect.h"
#include "Main/Net/mp_link.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/System/backup_net_camera_work.h"
#include "arena_cache_init.h"
#include "wireless_link_control.h"
#include "cpu_copy_fill.h"

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
            connectionMode = CONNECTION_MODE_NONE;
        } else {
            connectionMode = gConnectionWork->mConnectionMode;
        }
        switch (connectionMode) {
            case CONNECTION_MODE_PARENT:
                gPacketPortParams.mMaxDataSize = PACKET_PORT_PARENT_PACKET_SIZE;
                packetSize = WBT_MpParentSendHook(gConnectionWork->mPacketBuffer, PACKET_PORT_PARENT_PACKET_SIZE);
                destMask = gConnectionWork->mChildren.mChildMask;
                break;
            case CONNECTION_MODE_CHILD:
                gPacketPortParams.mMaxDataSize = PACKET_PORT_CHILD_PACKET_SIZE;
                packetSize = WBT_MpChildSendHook(gConnectionWork->mPacketBuffer, PACKET_PORT_CHILD_PACKET_SIZE);
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

void PacketPortCallback(void *portMessage) {
    WirelessMessage *result = portMessage;
    u8 packet[0x192];
    u32 connectionMode;
    if (result->mResultCode == 0 && result->mData != NULL && result->mLength <= PACKET_PORT_PARENT_PACKET_SIZE) {
        DC_InvalidateRange(result->mData, result->mLength);
        MI_CpuCopy8(result->mData, packet, result->mLength);
        if (result->mState == WIRELESS_STATE_LINKED) {
            return;
        }
        if (result->mState == WIRELESS_STATE_UNLINKED) {
            return;
        }
        if (result->mState == WIRELESS_STATE_PORT_DATA_ARRIVED) {
            if (gConnectionWork == NULL) {
                connectionMode = CONNECTION_MODE_NONE;
            } else {
                connectionMode = gConnectionWork->mConnectionMode;
            }
            switch (connectionMode) {
                case CONNECTION_MODE_PARENT:
                    WBT_MpParentRecvHook(packet, result->mLength, result->mAid);
                    break;
                case CONNECTION_MODE_CHILD:
                    WBT_MpChildRecvHook(packet, result->mLength);
                    break;
            }
        }
    }
}

#pragma thumb off
