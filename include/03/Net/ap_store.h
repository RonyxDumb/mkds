#pragma once

#include "types.h"
#include "03/Net/ap_entries.h"

s32 ParseHexDigit(u32 value);

extern const u8 gSettingNone[4];
extern char gAddressTextFormat[13];
extern struct ApStore *gApStore;
