#include "03/Net/value_records_request.h"
#include "03/Net/value_records_request_status.h"
#include "03/Net/essid_packet_steps.h"
#include "03/Net/ap_entries.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/System/exp_heap.h"
#include "03/Net/value_records_request_alloc.h"
#include "03/Menu/wifi_menu_tables.h"
#include "reset_interrupt_enable.h"
#include "cpu_copy_clear_16.h"
#include "cpu_copy_fill.h"

const u8 gNintendoDsItemBytes[12] = {0x4e, 0x49, 0x4e, 0x54, 0x45, 0x4e, 0x44, 0x4f, 0x2d, 0x44, 0x53, 0};
u8 gValueRecordsRequestSucceeded;
struct ValueRecordsRequest *gValueRecordsRequest;

void InitValueRecordsRequest(void) {
    ValueRecordsRequestView requestItem;
    ValueRecordsRequest *request;
    gValueRecordsRequest = AllocZeroedExpHeapBlock(0x26c, 4);
    gValueRecordsRequestSucceeded = 0;
    requestItem.mClearValue = 0;
    MIi_CpuClear16(requestItem.mClearValue, &requestItem.mItem, sizeof(ValueRecordsRequestItem));
    requestItem.mItem.mItemType = 0x50;
    requestItem.mItem.mItemLength = sizeof(gNintendoDsItemBytes);
    MI_CpuCopy8(gNintendoDsItemBytes, requestItem.mItem.mItemBytes, 0xc);
    gValueRecordsRequest->mWantedRecordMask = VALUE_RECORD_MASK_KEY_SET_FIRST | VALUE_RECORD_MASK_KEY_SET_SECOND;
    request = gValueRecordsRequest;
    request->mItem = requestItem.mItem;
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
        (gValueRecordsRequestSucceeded == 1)) {
        WriteApWorkFromAossResult((s32) &gValueRecordsRequest->mRecordBytes);
    }
    FreeExpHeapBlockAndClearPointer(&gValueRecordsRequest);
}

u32 RunValueRecordsRequestForStatus(void) {
    u8 resultCode;
    if (RunValueRecordsRequest(gValueRecordsRequest) == 0) {
        gValueRecordsRequestSucceeded = 1;
        return VALUE_RECORDS_STATUS_SUCCEEDED;
    }
    resultCode = gValueRecordsRequest->mResultCode;
    if (resultCode == VALUE_RECORDS_RESULT_NO_ENTRY_FOUND || (u8) (resultCode + 253) <= 2) {
        return VALUE_RECORDS_STATUS_RETRY;
    }
    return VALUE_RECORDS_STATUS_FAILED;
}

u32 EssidAllocExpHeapBlockWrapper(u32 size) {
    u32 allocResult = size;
    u32 alignment;
    u32 allocFunctionAddress;
    alignment = 32u;
    allocFunctionAddress = (u32) &AllocExpHeapBlock;
    allocResult = (u32) AllocExpHeapBlock(allocResult, alignment);
    return allocResult;
}

void EssidFreeExpHeapBlockWrapper(void *block) {
    FreeExpHeapBlock(block);
}
