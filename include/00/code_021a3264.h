#pragma once

#include "types.h"

// State of the generator in DWCi_GetMathRand32.
typedef struct MATHRandContext32 {
    /* 00 */ u64 mX;
    /* 08 */ u64 mMul;
    /* 10 */ u64 mAdd;
} MATHRandContext32;

extern MATHRandContext32 gRandContext32;

BOOL SetPeerReceiveBuffer(u32 aid, void *recvBuffer, s32 size);
BOOL DWC_SendUnreliable(u32 aid, void *buffer, s32 size);
BOOL StartPeerMessageSend(u16 type, u32 aid, u8 *buffer, s32 size);
BOOL DWCi_IsSendableReliable(u32 aid, s32 type);
u32 DWCi_GetMathRand32(u32 max);
u64 MatchingGetTickMilliseconds(void);
s32 DWC_GetCommonValueString(const char *key, char *value, const char *string, int separator);
u32 DWC_AddCommonKeyValueString(void *key, void *value, void *string, u32 separator);
u32 DWC_SetCommonKeyValueString(void *key, void *value, void *string, u32 separator);
