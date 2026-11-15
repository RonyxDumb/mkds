#pragma once

#include "types.h"
#include "00/code_0219eac8.h"
#include "00/unk_021b5000.h"
#include "00/code_0219de4c.h"

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

void DWCi_QR2ClientMsgCallback(const void *data, u32 len, void *userData);
void DWCi_QR2NatnegCallback(u32 cookie, void *userData);
u32 DWCi_SendCancelMatchSynCommand(u32 profileId, u32 command);
void DWCi_ShutdownMatch(void);
void DWCi_StopMatching(s32 isServer, s32 isSelf);

s32 DWC_GetMOMinCompState(u64 *time);
u32 DWC_SetMatchingOption(u32 opttype, void *optval, u32 optlen);
s32 DWC_GetMatchIntValue(u32 index, void *keyString, s32 idefault);
u32 DWC_AddMatchKeyString(u32 keyId, char *keyString, void *valueSrc);
u32 DWC_AddMatchKeyInt(u32 keyId, char *keyString, void *valueSrc);
u32 DWC_IsValidCancelMatching(void);

u32 DWC_CancelMatching(void);

extern MatchingSignatureText gMatchingSignature;
extern char gUnsignedFormat[3];
extern char gDwcPidKey[8];
extern char gDwcEvalKey[9];
extern MatchingKey gMatchingKeys[154];
extern u8 gMatchingMaskedParticipantIndices[0x20];
extern void *gMatchingFilterText;
extern struct DWCMatchOptMinCompleteIn *gOptMinComp;
// Points at WiFiConnection.mMatching: set by DWCi_MatchInit, set to NULL by DWCi_ShutdownMatch.
extern struct WiFiMatching *gWiFiMatching;
extern DWCMatchOptSCBlock gOptSCBlock;
