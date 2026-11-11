#pragma once

#include "types.h"

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
