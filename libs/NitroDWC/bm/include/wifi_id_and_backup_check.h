#pragma once

#include "types.h"

typedef struct DWCWiFiInfo DWCWiFiInfo;

typedef struct DWCAuthWiFiId {
    /* 00 */ u64 mUId;
    /* 08 */ u64 mNotAttestedId;
    /* 10 */ u32 mFlag;
    /* 14 */ u32 mUnk_14;
} DWCAuthWiFiId;

extern const u8 DWCi_SETTING_NONE[];

void StructDC_CleanDCSub_from_thumb(u8 *work, u32 page);
s32 StructDC_SomeFn_from_thumb(u8 *work);
BOOL StructDCSub_SomeFn_from_thumb(const u8 *ap);
s32 StructDC_SomeFn_2_from_thumb(u8 *work);
BOOL DWC_Auth_CheckWiFiIDNeedCreate(void);
void StructDW_SomeFn_GetSomething_from_thumb(DWCAuthWiFiId *id);
BOOL DWCi_AUTH_RemakeWiFiID(DWCWiFiInfo *info);
BOOL DWCi_AUTH_UpDateWiFiID(DWCWiFiInfo *info, u8 *work);
