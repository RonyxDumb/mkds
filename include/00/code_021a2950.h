#pragma once

#include "types.h"

extern u8 gMatchingKeyIsString[];
extern u8 gMatchingKeyPad[];
extern u8 gMatchingKeyString[];
extern u8 gMatchingKeyValue[];

s32 DWC_GetMOMinCompState(u64 *time);
u32 DWC_SetMatchingOption(u32 opttype, void *optval, u32 optlen);
s32 DWC_GetMatchIntValue(u32 index, void *keyString, s32 idefault);
u32 DWC_AddMatchKeyString(u32 keyId, char *keyString, void *valueSrc);
u32 DWC_AddMatchKeyInt(u32 keyId, char *keyString, void *valueSrc);
u32 DWC_IsValidCancelMatching(void);
