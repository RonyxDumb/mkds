#pragma once

#include "types.h"

typedef struct PeerAddress PeerAddress;

u32 DWCi_ProcessNNFailure(void);
void DWCi_NNCompletedCallback(s32 result, s32 gamesocket, PeerAddress *remoteaddr, void *userdata);

void DWCi_NNProgressCallback(void);

typedef struct MatchingReceiveHeader {
    /* 00 */ char mSignature[4];
    /* 04 */ u32 mVersion;
    /* 08 */ u8 mCommand;
    /* 09 */ u8 mValuesSize;
    /* 0a */ u16 mPort;
    /* 0c */ u32 mAddress;
    /* 10 */ u32 mProfileId;
} MatchingReceiveHeader;

void DWCi_QR2ClientMsgCallback(const void *data, u32 len);
void DWCi_QR2NatnegCallback(u32 cookie);
u32 DWCi_SendCancelMatchSynCommand(u32 profileId, u32 command);
void DWCi_ShutdownMatch(void);
void DWCi_StopMatching(s32 isServer, s32 isSelf);

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

u32 DWC_CancelMatching(void);
