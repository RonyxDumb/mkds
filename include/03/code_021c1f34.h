#pragma once

#include "types.h"

// 0x104 bytes moved as one value.
typedef struct ValueRecordsRequestItem {
    /* 000 */ u16 mUnk_00[0x82];
} ValueRecordsRequestItem;

// Stack object of InitValueRecordsRequest.
typedef struct Unk021c1fc8 {
    /* 000 */ u16 mUnk_00;
    /* 002 */ u8 mItemType;
    /* 003 */ u8 pad_03;
    /* 004 */ u16 mItemLength;
    /* 006 */ u8 mItemBytes[0x100];
} Unk021c1fc8;

u32 RunValueRecordsRequestForStatus(void);
void ReleaseValueRecordsRequest(int succeeded);
void InitValueRecordsRequest(void);
