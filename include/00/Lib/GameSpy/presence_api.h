#pragma once

#include "types.h"

typedef struct GPConnection GPConnection;

u32 gpSendBuddyMessageA(GPConnection *connection, s32 profileRec, const char *message);
u32 gpSetStatusA(GPConnection *connection, s32 status, const char *statusString, const char *locationString);

// The status of a buddy: profile id, status, status and location strings, IP and port.
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

typedef void (*GetInfoCallback)(GPConnection *connection, GetInfoReply *reply, u32 param);
typedef void (*ProfileSearchCallback)(GPConnection *connection, ProfileSearchReply *reply, u32 param);

u32 gpIsBuddy(GPConnection *connection, u32 profile);
u32 gpGetBuddyIndex(GPConnection *connection, u32 profile, s32 *index);
u32 gpGetBuddyStatus(GPConnection *connection, s32 index, GpBuddyStatus *status);
s32 gpGetNumBuddies(GPConnection *object, s32 *output);
u32 gpSendBuddyRequestA(GPConnection *connection, u32 profile, const char *reason);
void gpDisconnect(GPConnection *connection);

u32 GpDeleteBuddy(GPConnection *connection, u32 profile);
u32 GpDenyBuddyRequest(GPConnection *connection, int profile);
u32 GpAuthBuddyRequest(GPConnection *connection, u32 profile);
u32 GpSetInfosA(GPConnection *connection, s32 info, const s8 *value);
u32 GpGetInfo(GPConnection *connection, u32 profile, s32 checkCache, u32 blocking, GetInfoCallback callback, u32 param);
u32 GpProfileSearchA(GPConnection *connection, s8 *nick, s8 *uniquenick, s8 *email, s8 *firstname, s8 *lastname,
                     s32 icquin, u32 blocking, ProfileSearchCallback callback, u32 param);

typedef struct GPConnection GPConnection;

typedef struct ConnectReply ConnectReply;

typedef void (*ConnectCallback)(GPConnection *connection, ConnectReply *reply, u32 param);

u32 GpConnectPreAuthenticatedA(GPConnection *connection, s8 *authtoken, s8 *partnerchallenge, s32 firewall,
                               s32 blocking, ConnectCallback callback, u32 param);
u32 GpSetCallback(GPConnection *connection, s32 func, void (*callback)(void *connection, void *func, u32 callback),
                  u32 param);
u32 gpProcess(GPConnection *connection);
void GpDestroy(GPConnection *connection);
u32 gpInitialize(GPConnection *connection, s32 productID, s32 namespaceID);
#include "00/Lib/GameSpy/connection_update.h"
