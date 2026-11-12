#pragma once

#include "types.h"

typedef struct SOCHostEnt SOCHostEnt;

// Entry of the list behind gServerReqs, appended by AddRequestCallback; the function at 0x18 takes the arguments of the entry's type.
typedef union ServerReqCallback {
    void (*mAuthCallback)(u32 a, u32 b, s32 c, const u8 *d, u32 e);
    void (*mDataCallback)(u32 a, u32 b, u32 c, u32 d, s32 e, s32 f, const u8 *g, s32 h, u32 i);
    void (*mSaveCallback)(u32 a, u32 b, u32 c, u32 d, s32 e, s32 f, u32 g);
    void (*mProfileCallback)(u32 a, u32 b, s32 c, u32 d);
} ServerReqCallback;

typedef struct ServerReq {
    /* 00 */ s32 mReqType;
    /* 04 */ u32 mLocalId;
    /* 08 */ u32 mProfileId;
    /* 0c */ u32 mPdType;
    /* 10 */ u32 mPdIndex;
    /* 14 */ u32 mInstance;
    /* 18 */ ServerReqCallback mCallback;
} ServerReq;

typedef struct ConnErrorBytes {
    /* 00 */ u8 mText[0x10];
} ConnErrorBytes;

typedef struct SetPersistRespformatText {
    /* 00 */ s8 mText[0x3f];
} SetPersistRespformatText;

typedef struct ConnErrorText {
    /* 00 */ s8 mText[0x10];
} ConnErrorText;

typedef struct KeyspecText {
    /* 00 */ s8 mText[0x100];
} KeyspecText;

typedef struct ChallengeRespformatText {
    /* 00 */ s8 mText[0x2c];
} ChallengeRespformatText;

extern s32 gSock;
extern u8 *gEnc;
extern char gSessKeyStr[];
extern char gChallengeStr[];
extern const ConnErrorText gConnErrorSendAuth;
extern ConnErrorBytes gConnErrorClosePending;
extern const ChallengeRespformatText gChallengeRespformat;
extern const SetPersistRespformatText gSetPersistRespformat;
extern const KeyspecText gValueForKeyKeyspec;
extern char gSetpdrKey[];
extern char gStatsPidKey[];
extern const char gLidKey[];
extern char gModKey[];
extern char gGetpdrKey[];
extern char gLengthKey[];
extern char gDataMarker[];
extern const s8 gEmptyValue[];
extern char gGetpidrKey[];
extern const char gPauthrKey[];
extern const char gErrmsgKey[];
extern const char gKeyspecDelimiter[];
extern const char gCreateChallengeFormat[];
extern const char gChallengeHashFormat[];
extern u32 gConnId;
extern void *gServerReqs;
extern s32 gValueIndex;
extern char gcd_gamename[];
extern char gcd_secret_key[];
extern s8 gValueForKeyValues[];

void ClosePendingCallbacks(void);
void CallReqCallback(s32 requestPos, s32 success, s32 modified, const u8 *data, s32 length);
s32 ProcessInBuffer(u8 *buff, s32 len);
void ProcessStatement(u8 *buff, s32 len);
void ProcessSetData(u8 *buf, s32 len);
void ProcessGetData(u8 *buf, s32 len);
void ProcessGetPid(u8 *buf, s32 len);
void ProcessPlayerAuth(u8 *buf, s32 len);
s32 FindRequest(s32 reqType, s32 ownId, s32 profileId);
const s8 *FindFinal(const s8 *buff, s32 len);
u32 SocketReadable(u32 socket);
void SetPersistDataHelper(s32 ownId, s32 profileId, s32 type, s32 index, const u8 *data, s32 len, UnkFunc *callback,
                          s32 instance, s32 kvset);
void SendPlayerAuthRequest(s8 *data, s32 len, s32 ownId, UnkFunc *callback, s32 instance);
void AddRequestCallback(s32 reqType, s32 ownId, s32 profileId, s32 dataKind, s32 dataIndex, UnkFunc *callback,
                        s32 instance);
BOOL ResolveStatsHostAddress(const s8 *host, u32 port, u8 *saddr, SOCHostEnt **savehent);
const s8 *value_for_key_safe(const s8 *text, const char *key);
const s8 *value_for_key(const s8 *text, const char *key);
void create_challenge(u32 challenge, s8 *chstr);
int g_crc32(const s8 *text, int len);
void xcode_buf(s8 *buf, s32 len);
s32 DoSend(s8 *data, s32 len);
s32 RecvSessionKey(void);
s32 SendChallengeResponse(const s8 *indata, u32 gameport);

typedef struct PreAuthPMRespformatText {
    /* 00 */ s8 mText[0x24];
} PreAuthPMRespformatText;

// 0x1d bytes written into the buffer of GenerateAuthA when the two strings are too long.
typedef struct CdKeyTooLongText {
    /* 00 */ s8 mUnk_00[0x1d];
} CdKeyTooLongText;

extern const PreAuthPMRespformatText gPreAuthPMRespformat;
extern const char gStatsServerHostname[];
extern const char gInitStatsThinkAssert[];
extern const char gGstatsFileName[];
extern const char gHostnameDot[];
extern const CdKeyTooLongText gCdKeyTooLongText;
extern const char gGenerateAuthFormat[];
extern u32 gInitStart;
extern s32 gRcvLen;
extern s8 *gRcvBuffer;
extern s32 gStatsInitState;
extern u32 gSessKey;
extern s32 gGamePort;
extern s8 *gStatsGame;
extern s32 gRcvMax;
extern s8 gChallenge[];

void InternalInit(void);
BOOL PersistThink(void);
void SetPersistDataValuesA(u32 ownId, u32 profileId, u32 type, u32 index, u32 valueString, u32 callback, u32 instance);
void PreAuthenticatePlayerPartner(s32 localId, s32 profileId, s32 challengeResponse, UnkFunc *callback, s32 instance);
s8 *GetChallenge(s8 *game);
void GstatsClose(void);
s32 GstatsConnect(s32 gameport);
s32 GstatsUpdateConnect(void);
s32 GstatsStartConnect(s32 theGamePort, s32 theInitTimeout);
s8 *GenerateAuthA(const char *challenge, const char *password, s8 *response);
