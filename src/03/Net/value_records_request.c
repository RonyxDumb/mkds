#include "03/Net/value_records_request.h"
#include "03/code_021c1f34.h"
#include "03/code_021cd000.h"
#include "03/Net/essid_packet_steps.h"
#include "03/code_021cd2e0.h"
#include "03/unk_021da000.h"
#include "03/System/exp_heap.h"
#include "03/code_021c1f28.h"
#include "03/unk_021d6000.h"
#include "code_0200fc8c.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"

const u8 gNintendoDsItemBytes[12] = {0x4e, 0x49, 0x4e, 0x54, 0x45, 0x4e, 0x44, 0x4f, 0x2d, 0x44, 0x53, 0};
u8 gValueRecordsRequestSucceeded[1];
struct ValueRecordsRequest *gValueRecordsRequest;

void InitValueRecordsRequest(void) {
    ValueRecordsRequestView requestItem;
    ValueRecordsRequest *request;
    gValueRecordsRequest = AllocZeroedExpHeapBlock(0x26c, 4);
    gValueRecordsRequestSucceeded[0] = 0;
    requestItem.mUnk_00 = 0;
    MIi_CpuClear16(requestItem.mUnk_00, &requestItem.mItemType, 0x104);
    requestItem.mItemType = 0x50;
    requestItem.mItemLength = 0xc;
    MI_CpuCopy8(gNintendoDsItemBytes, requestItem.mItemBytes, 0xc);
    gValueRecordsRequest->mWantedRecordMask = 3;
    request = gValueRecordsRequest;
    *(ValueRecordsRequestItem *) &request->mItemType = *(ValueRecordsRequestItem *) &requestItem.mItemType;
    request->mScanRetryLimit = 1;
    gValueRecordsRequest->mScanRetryDelayMs = -1;
    gValueRecordsRequest->mSendAttemptLimit = 1;
    gValueRecordsRequest->mSendAttemptDelayMs = -1;
    gValueRecordsRequest->mReceiveTimeoutMs = -1;
    OS_GetMacAddress(gValueRecordsRequest->mMacAddress);
    if (InitEssidWiFi((void *(*) (u32)) EssidAllocExpHeapBlockWrapper, EssidFreeExpHeapBlockWrapper) != 0) {
        OS_Terminate();
    }
}

void ReleaseValueRecordsRequest(int succeeded) {
    ReleaseEssidWiFi();
    if (((succeeded != 0) && (gValueRecordsRequest->mResultCode == 0)) &&
        ((*(u8 *) &gValueRecordsRequestSucceeded) == 1)) {
        WriteApWorkFromAossResult((s32) &gValueRecordsRequest->mUnk_117);
    }
    FreeExpHeapBlockAndClearPointer(&gValueRecordsRequest);
}

u32 RunValueRecordsRequestForStatus(void) {
    u8 resultCode;
    if (RunValueRecordsRequest(gValueRecordsRequest) == 0) {
        gValueRecordsRequestSucceeded[0] = 1;
        return 1;
    }
    resultCode = gValueRecordsRequest->mResultCode;
    if (resultCode == 1 || (u8) (resultCode + 253) <= 2) {
        return 0;
    }
    return 2;
}

u32 EssidAllocExpHeapBlockWrapper(u32 size) {
    u32 value0 = size;
    u32 alignment;
    u32 allocFunctionAddress;
    alignment = 32u;
    allocFunctionAddress = (u32) &AllocExpHeapBlock;
    value0 = (u32) AllocExpHeapBlock(value0, alignment);
    return value0;
}

void EssidFreeExpHeapBlockWrapper(void *block) {
    FreeExpHeapBlock(block);
}
