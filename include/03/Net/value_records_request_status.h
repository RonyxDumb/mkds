#pragma once

#include "types.h"

typedef struct ValueRecordsRequestItem {
    /* 000 */ u8 mItemType;
    /* 002 */ u16 mItemLength;
    /* 004 */ u8 mItemBytes[0x100];
} ValueRecordsRequestItem;

// Stack object of InitValueRecordsRequest.
typedef struct ValueRecordsRequestView {
    /* 000 */ u16 mClearValue;
    /* 002 */ ValueRecordsRequestItem mItem;
} ValueRecordsRequestView;

// Values RunValueRecordsRequestForStatus returns: try again later (no entry or a timeout), succeeded, failed.
#define VALUE_RECORDS_STATUS_RETRY 0
#define VALUE_RECORDS_STATUS_SUCCEEDED 1
#define VALUE_RECORDS_STATUS_FAILED 2

u32 RunValueRecordsRequestForStatus(void);
void ReleaseValueRecordsRequest(int succeeded);
void InitValueRecordsRequest(void);
