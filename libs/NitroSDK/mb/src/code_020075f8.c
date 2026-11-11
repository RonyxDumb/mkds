#include "code_020075f8.h"
#include "code_02008908.h"
#include "code_0200c0d8.h"
#include "mb_data.h"

#pragma thumb on

int MBi_CommParentSendMsg(u8 messageKind, u32 childMask) {
    u8 message[8];
    message[0] = messageKind;
    MBi_MakeParentSendBuffer(message, (u8 *) mbc);
    return MBi_BlockHeaderEnd(6, childMask, (u32) mbc);
}

#pragma thumb off
