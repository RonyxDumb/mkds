#pragma once

#include "types.h"
#include "00/Lib/GameSpy/buddy_messages.h"

typedef struct WiFiMatching WiFiMatching;
typedef struct SBServer SBServer;

// The signature text of gMatchingSignature: four characters and a terminating zero; the send copies all five bytes onto
// the start of the header and the receive compares four.
typedef struct MatchingSignatureText {
    /* 0 */ char mText[5];
} MatchingSignatureText;

// The header in front of the values of a matching command: signature, version, command, size, port, address, profile.
typedef struct MatchingSendHeader {
    /* 00 */ char mSignature[4];
    /* 04 */ u32 mVersion;
    /* 08 */ u8 mCommand;
    /* 09 */ u8 mValuesSize;
    /* 0a */ u16 mPort;
    /* 0c */ u32 mAddress;
    /* 10 */ u32 mProfileId;
} MatchingSendHeader;

// The twelve bytes at WiFiMatching.mNNInfo.
typedef struct DWCNNInfo {
    /* 00 */ u8 mIsQR2;
    /* 01 */ u8 mRetryCount;
    /* 02 */ u16 mPort;
    /* 04 */ u32 mAddress;
    /* 08 */ u32 mCookie;
} DWCNNInfo;

s32 DWCi_GetGPBuddyAdditionalMsg(char *out, const char *text, s32 index);
s32 DWCi_SendGPBuddyMsgCommand(struct GPConnection *gpConnection, u32 command, u32 profileId, const char *text);
u32 DWCi_SendSBMsgCommand(u32 command, u32 address, u32 port, u32 *values, u32 valueCount);
u32 DWCi_SendMatchCommand(u32 command, u32 profileId, u32 address, u32 port, void *values, s32 valueCount);
u32 DWCi_DoNatNegotiationAsync(DWCNNInfo *nnInfo);
u32 DWCi_NNStartupAsync(s32 isQR2, s32 cookie, SBServer *server);
s32 DWCi_GetDefaultMatchFilter(char *buffer, s32 profileId, s32 numEntry, s32 mode);
u32 DWCi_SBUpdateAsync(u32 profileId);
void DWCi_CloseMatching(void);
