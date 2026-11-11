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

// Element of the array behind Unk0218eff8Arg.mUnk_0c, 0xac bytes.
typedef struct Unk0219c400Entry {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 pad_04[0xa8];
} Unk0219c400Entry;

// Zeroed by GpGetInfo and passed to the callback (0x204 bytes); the callbacks name it Unk0219c400.
typedef struct Unk0218eff8Arg {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ Unk0219c400Entry *mUnk_0c;
    /* 10 */ u8 pad_10[0x7e];
    /* 8e */ s8 mUnk_8e[0x20];
    /* ae */ u8 pad_ae[0x156];
} Unk0218eff8Arg;

// Zeroed by GpProfileSearchA (0x08 set to 0x601) and passed to the callback.
typedef struct Unk0218f0a8Arg {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk0218f0a8Arg;

typedef void (*Unk0218eff8Cb)(GpConnection *a, Unk0218eff8Arg *b, u32 c);
typedef void (*Unk0218f0a8Cb)(GpConnection *a, Unk0218f0a8Arg *b, u32 c);

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
u32 GpGetInfo(GpConnection *connection, u32 profile, s32 checkCache, u32 blocking, Unk0218eff8Cb callback, u32 param);
u32 GpProfileSearchA(GpConnection *connection, s8 *nick, s8 *uniquenick, s8 *email, s8 *firstname, s8 *lastname,
                     s32 icquin, u32 blocking, Unk0218f0a8Cb callback, u32 param);
