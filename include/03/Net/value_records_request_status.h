#pragma once

#include "types.h"

// One item of a value records request: its type, length and bytes.
typedef struct ValueRecordsRequestItem {
    /* 000 */ u8 mItemType;
    /* 002 */ u16 mItemLength;
    /* 004 */ u8 mItemBytes[0x100];
} ValueRecordsRequestItem;

// A clear value and an item built on the stack, then copied into the request's mItem.
typedef struct ValueRecordsRequestStagedItem {
    /* 000 */ u16 mClearValue;
    /* 002 */ ValueRecordsRequestItem mItem;
} ValueRecordsRequestStagedItem;

// Values RunValueRecordsRequestForStatus returns: try again later (no entry or a timeout), succeeded, failed.
#define VALUE_RECORDS_STATUS_RETRY 0
#define VALUE_RECORDS_STATUS_SUCCEEDED 1
#define VALUE_RECORDS_STATUS_FAILED 2

u32 RunValueRecordsRequestForStatus(void);
void ReleaseValueRecordsRequest(int succeeded);
void InitValueRecordsRequest(void);
