#pragma once

#include "types.h"
#include "00/Lib/GameSpy/code_0218f960.h"

typedef struct DWCAccFriendData DWCAccFriendData;
typedef struct WiFiBuddySync WiFiBuddySync;

void StartBuddySync(s32 authToken, const char *partnerChallenge, void (*updateCallback)(s32, u8, void *),
                    void *updateParam, void (*statusCallback)(s32, u8, void *, void *), void *statusParam,
                    void (*deleteCallback)(s32, s32, void *), void *deleteParam);

u32 DWCi_GPSendBuddyRequest(u32 profileId);
s32 DWCi_RefreshFriendListAll(DWCAccFriendData *friendList, s32 friendListLength, s32 profileId);
BOOL DWCi_RefreshFriendListForth(DWCAccFriendData *friendList, s32 index, s32 profileId);
void DWCi_DeleteFriendFromList(DWCAccFriendData *friendData, s32 deleteIndex, s32 otherIndex);
void DWCi_EndUpdateServers(void);
void DWCi_UpdateFriendReq(DWCAccFriendData *friendList, s32 friendListLength);
void CloseStatsAndResetBuddySync(void);
int DWCi_GPProcess(void);
void DWCi_ShutdownFriend(void);
void DWCi_CallBuddyFriendCallback(s32 index);
u32 DWCi_SetGPStatus(s32 status, void *statusString, void *locationString);
void DWCi_InitGPProcessCount(void);
u32 DWCi_GetFriendListIndex(u32 profileId);
int DWCi_GetProfileIDFromList(int index);
s32 DWCi_GetFriendListLen(void);
void DWCi_GPRecvBuddyStatusCallback(struct GpConnection *connection, s32 *arg);
u32 DWCi_GPRecvBuddyAuthCallback(GpConnection *connection, u32 *arg, u32 param);
void DWCi_GPRecvBuddyRequestCallback(GpConnection *connection, u32 *arg);
void DWCi_StopFriendProcess(s32 error, s32 errorCode);
void DWCi_FriendProcess(void);
void DWCi_FriendInit(WiFiBuddySync *buddySync, struct GpConnection *gpConnection, char *playerName,
                     DWCAccFriendData *friendList, s32 friendListLength);
