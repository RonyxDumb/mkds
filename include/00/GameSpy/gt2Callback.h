#pragma once

#include "types.h"

struct Gt2Socket;
struct Gt2Connection;

typedef struct Gt2ConnectionCallbacks {
    /* 00 */ void (*mResultCallback)(struct Gt2Connection *a, int b, void *c, int d);
    /* 04 */ void (*mDataCallback)(struct Gt2Connection *a, void *b, int c, int d);
    /* 08 */ void (*field8)(struct Gt2Connection *a, void *b);
    /* 0c */ UnkWordFunc *mElapsedTimeCallback;
} Gt2ConnectionCallbacks;

// Object with the callbacks that the functions of this file call.
typedef struct Gt2Socket {
    /* 00 */ s32 mDescriptor;
    /* 04 */ u32 mAddress;
    /* 08 */ u16 mPort;
    /* 0a */ u8 fieldA[2];
    /* 0c */ struct Hashtable *mConnections;
    /* 10 */ void *mConnectionsToFree;
    /* 14 */ BOOL mDeletePending;
    /* 18 */ BOOL field18;
    /* 1c */ s32 mRunningCallbackCount;
    /* 20 */ void (*mIncomingConnectionCallback)(struct Gt2Socket *a, struct Gt2Connection *b, int c, int d, int e,
                                                 const u8 *f, int g);
    /* 24 */ void (*field24)(struct Gt2Socket *a);
    /* 28 */ UnkWordFunc *mSentCallback;
    /* 2c */ UnkWordFunc *field2C;
    /* 30 */ UnkWordFunc *mUnmatchedDataCallback;
    /* 34 */ UnkWordFunc *field34;
    /* 38 */ u32 mSendBufferSize;
    /* 3c */ u32 field3C;
    /* 40 */ u8 field40[4];
} Gt2Socket;

typedef struct Unk02197fe8Entry {
    /* 00 */ UnkWordFunc *field0;
} Unk02197fe8Entry;

typedef struct Gt2Buffer {
    /* 0 */ u8 *mData;
    /* 4 */ s32 mSize;
    /* 8 */ s32 mLength;
} Gt2Buffer;

typedef struct Gt2Connection {
    /* 00 */ u32 mAddress;
    /* 04 */ u16 mPort;
    /* 06 */ u8 field6[2];
    /* 08 */ Gt2Socket *mSocket;
    /* 0c */ s32 fieldC;
    /* 10 */ BOOL field10;
    /* 14 */ BOOL field14;
    /* 18 */ s32 mResult;
    /* 1c */ u32 mCreateTime;
    /* 20 */ u32 mTimeSinceCreateLimit;
    /* 24 */ s32 field24;
    /* 28 */ Gt2ConnectionCallbacks mCallbacks;
    /* 38 */ Gt2Buffer field38;
    /* 44 */ Gt2Buffer field44;
    /* 50 */ Gt2Buffer mSendBuffer;
    /* 5c */ struct Darray *field5C;
    /* 60 */ void *field60;
    /* 64 */ u16 field64;
    /* 66 */ u16 field66;
    /* 68 */ u8 field68[0x20];
    /* 88 */ u32 mLastSendTime;
    /* 8c */ u32 field8C;
    /* 90 */ u32 field90;
    /* 94 */ u32 field94;
    /* 98 */ void *field98;
    /* 9c */ void *field9C;
} Gt2Connection;

BOOL CallUnmatchedDataCallback(Gt2Socket *a, s32 b, s32 c, void *d, s32 e, s32 *f);
BOOL Gt2CallElapsedTimeCallback(Gt2Connection *connection, s32 b);

typedef struct Gt2Socket Gt2Socket;
typedef struct Gt2Connection Gt2Connection;

typedef struct Unk02198af4 {
    /* 00 */ u32 field0;
    /* 04 */ u32 field4;
    /* 08 */ u8 field8[4];
    /* 0c */ u32 fieldC;
} Unk02198af4;

BOOL Gt2CallDataCallback(Gt2Connection *connection, void *b, int c, int d);
BOOL Gt2SetResultAndCallResultCallback(Gt2Connection *connection, int b, void *c, int d);
BOOL CallIncomingConnectionCallback(Gt2Socket *a, Gt2Connection *b, int c, int d, int e, const u8 *f, int g);

extern const char data_ov000_021b3f50[];
extern const char data_ov000_021b3f58[];
extern const char data_ov000_021b3f68[];

u32 func_ov000_02197f28(Gt2Socket *socket, Gt2Connection *b, u32 f, u32 g, u32 h, int l, int m, int n);
BOOL func_ov000_02197fe8(Gt2Connection *connection, s32 b, void *c, s32 d, s32 e);
BOOL func_ov000_02198098(Gt2Connection *connection, s32 b, s32 c, void *d, s32 e);
BOOL func_ov000_021981d0(Gt2Connection *connection, void *b);
BOOL func_ov000_02198448(Gt2Socket *socket);
void func_ov000_021984b4(Gt2Connection *a);
void func_ov000_02198514(Gt2Connection *a, ...);
void func_ov000_02198548(Gt2Connection *a, int b);
