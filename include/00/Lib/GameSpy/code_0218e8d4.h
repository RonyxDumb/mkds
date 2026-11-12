#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;

u32 GpSendMessage(GpConnection *connection, s32 profileRec, const char *message);
u32 GpSetStatus(GpConnection *connection, s32 status, const char *statusString, const char *locationString);

// Output of GpGetBuddyStatus: a copy of the entry's fields, two 0x100-byte strings included.
typedef struct GpBuddyStatus {
    /* 000 */ u32 mProfileId;
    /* 004 */ s32 mStatus;
    /* 008 */ char mStatusString[0x100];
    /* 108 */ char mLocationString[0x100];
    /* 208 */ u32 mIp;
    /* 20c */ s32 mPort;
} GpBuddyStatus;

typedef struct ProfileMatch ProfileMatch;

typedef struct GetInfoReply GetInfoReply;

typedef struct ProfileSearchReply ProfileSearchReply;

typedef void (*GpGetInfoCb)(GpConnection *a, GetInfoReply *b, u32 c);
typedef void (*GpProfileSearchCb)(GpConnection *a, ProfileSearchReply *b, u32 c);

u32 GpIsBuddy(GpConnection *connection, u32 profile);
u32 GpGetBuddyIndex(GpConnection *connection, u32 profile, s32 *index);
u32 GpGetBuddyStatus(GpConnection *connection, s32 index, GpBuddyStatus *status);
s32 GpGetBuddyCount(GpConnection *object, s32 *output);
u32 GpWriteAddbuddy(GpConnection *connection, u32 profile, const char *reason);
void GpDisconnect(GpConnection *connection);

u32 GpDeleteBuddy(GpConnection *connection, u32 profile);
u32 GpDenyBuddyRequest(GpConnection *connection, int profile);
u32 GpAuthBuddyRequest(GpConnection *connection, u32 profile);
u32 GpSetInfosA(GpConnection *connection, s32 info, const s8 *value);
u32 GpGetInfo(GpConnection *connection, u32 profile, s32 checkCache, u32 blocking, GpGetInfoCb callback, u32 param);
u32 GpProfileSearchA(GpConnection *connection, s8 *nick, s8 *uniquenick, s8 *email, s8 *firstname, s8 *lastname,
                     s32 icquin, u32 blocking, GpProfileSearchCb callback, u32 param);

typedef struct GpConnection GpConnection;

typedef struct ConnectReply ConnectReply;

typedef void (*GpConnectCb)(GpConnection *a, ConnectReply *b, u32 c);

u32 GpConnectPreAuthenticatedA(GpConnection *connection, s8 *authtoken, s8 *partnerchallenge, s32 firewall,
                               s32 blocking, GpConnectCb callback, u32 param);
u32 GpSetCallback(GpConnection *connection, s32 func, void (*callback)(void *connection, void *func, u32 callback),
                  u32 param);
u32 GpUpdate(GpConnection *connection);
void GpDestroy(GpConnection *connection);
u32 GpInitialize(GpConnection *connection, s32 productID, s32 namespaceID);
int GpiUpdateConnection(void *connectionArgument, int blockingOperationID);
u32 gpiProcessConnectionManager(GpConnection *connection);
u32 GpiResetConnection(GpConnection *connection);
