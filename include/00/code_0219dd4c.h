#pragma once

#include "types.h"

// The first 0x14 bytes of each record ParseMatchingRecords walks; MatchingSendHeader is the same layout on the send
// side.
typedef struct MatchingReceiveHeader {
    /* 00 */ char mSignature[4];
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mCommand;
    /* 09 */ u8 mValuesSize;
    /* 0a */ u16 mPort;
    /* 0c */ u32 mAddress;
    /* 10 */ u32 mProfileId;
} MatchingReceiveHeader;

void ParseMatchingRecords(const void *data, u32 len);
void DWCi_QR2NatnegCallback(u32 cookie);
u32 DWCi_SendCancelMatchSynCommand(u32 profileId, u32 command);
void ReleaseMatching(void);
void ReportMatchingError(s32 isServer, s32 isSelf);
