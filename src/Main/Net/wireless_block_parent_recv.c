#include "Main/Net/wireless_block_parent_recv.h"
#include "Main/Net/wireless_block_requests.h"

#pragma thumb on

void WBT_MpParentRecvHook(const u8 *data, int size, u32 fromIndex) {
    if (((data != NULL) && (size != 0)) && (size != 0xffff)) {
        ReceivePacketFromIndex(fromIndex, data, size);
    }
}

#pragma thumb off
