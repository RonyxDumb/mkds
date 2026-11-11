#pragma once

#include "types.h"

typedef struct SsidOrderTable {
    /* 00 */ u8 mUnk_00[24];
} SsidOrderTable;

extern s8 *gUsbWepFirstXorKey;
extern u8 gConvByteTable[];
extern s8 *gUsbWepSecondXorKey;
extern u8 gConv4BitTable[];
extern SsidOrderTable gSsidOrderTable;
extern s8 *gSsidDecodeFirstXorKey;
extern s8 *gSsidDecodeSecondXorKey;

s32 DecodeBase64(const u8 *encoded, u8 *decoded, s32 encodedLength, u32 capacity);
s32 CodeToValue(u32 code);
void MakeUsbWepKey(const u8 *name, u8 *wepKey);
void MakeShopWepKey(const u8 *decoded, u8 *wepKey);
void DecodeSsid(const u8 *ssid, u8 *decoded);
