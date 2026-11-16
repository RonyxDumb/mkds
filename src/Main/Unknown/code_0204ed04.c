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
u32 SetBlockEntryBuffer(u32 entryIndex, u32 buffer) {
    u32 value0 = entryIndex;
    u32 value1 = buffer;
    u32 value2;
    u32 value3;
    value2 = (u32) &gStruct217AA00;
    value3 = *(const u32 *) ((value2) + 0u);
    value2 = 136u;
    value0 = (value0) * (value2);
    value2 = (value3) + (value0);
    value0 = 0x1714u;
    *(u32 *) ((value2) + (value0)) = value1;
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 func_0204ee30(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value0 = (u32) &gStruct217AA00;
    value1 = *(const u32 *) ((value0) + 0u);
    value0 = 0x1e44u;
    value1 = (value1) + (value0);
    value2 = *(const u8 *) ((value1) + 0u);
    value0 = 1u;
    value2 = (value2) & ~(value0);
    *(u8 *) ((value1) + 0u) = value2;
    return value0;
}
#pragma thumb off

#pragma thumb on

void func_0204ed84(void) {
    u16 packetSize;
    u16 destMask;
    if (!(gStruct217AA00->mUnk_1e44 & 1)) {
        u32 v;
        if (gStruct217AA00 == NULL) {
            v = 0;
        } else {
            v = gStruct217AA00->mUnk_0000;
        }
        switch (v) {
            case 1:
                data_0216522c.mMaxDataSize = 0x192;
                packetSize = WBT_MpParentSendHook(gStruct217AA00->mPacketBuffer, 0x192);
                destMask = gStruct217AA00->mUnk_0044.mChildMask;
                break;
            case 2:
                data_0216522c.mMaxDataSize = 0xe;
                packetSize = WBT_MpChildSendHook(gStruct217AA00->mPacketBuffer, 0xe);
                destMask = 1;
                break;
        }
        if (QueueMPDataToPort(gStruct217AA00->mPacketBuffer, packetSize, destMask, NULL, &data_0216522c) == FALSE) {
            gStruct217AA00->mSendTimer = data_02165228;
            gStruct217AA00->mUnk_1e44 &= ~1;
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
            if (gStruct217AA00 == NULL) {
                v = 0;
            } else {
                v = gStruct217AA00->mUnk_0000;
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
