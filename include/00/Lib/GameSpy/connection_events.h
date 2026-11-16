#pragma once

#include "types.h"

struct GTI2Socket;
struct GTI2Connection;

// Called with the socket, the connection, the address and port, the reset flag, the message and its length.
typedef void (*gt2DumpCallback)(struct GTI2Socket *socket, struct GTI2Connection *connection, u32 address, u32 port,
                                u32 reset, int message, int len);
// Called with the socket, the address and port, the message and its length; returns whether it handled the message.
typedef u32 (*UnmatchedDataCallback)(struct GTI2Socket *socket, s32 address, s32 port, void *message, s32 len);
// Called with the connection, the filter index, the message, its length and the reliable flag.
typedef u32 (*ConnectionFilterCallback)(struct GTI2Connection *connection, s32 filterId, void *message, s32 len, s32 reliable);

typedef struct GT2ConnectionCallbacks {
    /* 00 */ void (*mResultCallback)(struct GTI2Connection *connection, int result, void *message, int len);
    /* 04 */ void (*mDataCallback)(struct GTI2Connection *connection, void *message, int len, int reliable);
    /* 08 */ void (*mClosedCallback)(struct GTI2Connection *connection, void *reason);
    /* 0c */ void (*mElapsedTimeCallback)(struct GTI2Connection *connection, u32 latency);
} GT2ConnectionCallbacks;

// Object with the callbacks that the functions of this file call.
typedef struct GTI2Socket {
    /* 00 */ s32 mDescriptor;
    /* 04 */ u32 mAddress;
    /* 08 */ u16 mPort;
    /* 0a */ u8 mUnk_0a[2];
    /* 0c */ struct HashImplementation *mConnections;
    /* 10 */ void *mConnectionsToFree;
    /* 14 */ BOOL mDeletePending;
    /* 18 */ BOOL mError;
    /* 1c */ s32 mRunningCallbackCount;
    /* 20 */ void (*mIncomingConnectionCallback)(struct GTI2Socket *socket, struct GTI2Connection *connection,
                                                 int address, int port, int latency, const u8 *message, int len);
    /* 24 */ void (*mSocketErrorCallback)(struct GTI2Socket *socket);
    /* 28 */ gt2DumpCallback mSendDumpCallback;
    /* 2c */ gt2DumpCallback mReceiveDumpCallback;
    /* 30 */ UnmatchedDataCallback mUnmatchedDataCallback;
    /* 34 */ u32 mUnk_34;
    /* 38 */ u32 mSendBufferSize;
    /* 3c */ u32 mIncomingBufferSize;
    /* 40 */ u8 mUnk_40[4];
} GTI2Socket;

typedef struct Gt2Filter {
    /* 00 */ ConnectionFilterCallback mCallback;
} Gt2Filter;

typedef struct GTI2Buffer {
    /* 0 */ u8 *mData;
    /* 4 */ s32 mSize;
    /* 8 */ s32 mLength;
} GTI2Buffer;

// Values of GTI2Connection.mState. A connection that started the exchange has sent its offer (OFFER_SENT) and then its
// reply (REPLY_SENT); one that received an offer waits for it (AWAIT_OFFER), sends its challenge (CHALLENGE_SENT) and
// waits for the answer of the incoming connection callback (AWAIT_DECISION). CLOSING follows a close request or a
// reject; CLOSED connections are freed later.
enum {
    GT2_CONNECTION_OFFER_SENT = 0,
    GT2_CONNECTION_REPLY_SENT = 1,
    GT2_CONNECTION_AWAIT_OFFER = 2,
    GT2_CONNECTION_CHALLENGE_SENT = 3,
    GT2_CONNECTION_AWAIT_DECISION = 4,
    GT2_CONNECTION_CONNECTED = 5,
    GT2_CONNECTION_CLOSING = 6,
    GT2_CONNECTION_CLOSED = 7,
};

typedef struct GTI2Connection {
    /* 00 */ u32 mAddress;
    /* 04 */ u16 mPort;
    /* 06 */ u8 mUnk_06[2];
    /* 08 */ GTI2Socket *mSocket;
    /* 0c */ s32 mState;
    /* 10 */ BOOL mInitiated;
    /* 14 */ BOOL mFreeAtAcceptReject;
    /* 18 */ s32 mResult;
    /* 1c */ u32 mCreateTime;
    /* 20 */ u32 mTimeSinceCreateLimit;
    /* 24 */ s32 mCallbackLevel;
    /* 28 */ GT2ConnectionCallbacks mCallbacks;
    /* 38 */ u8 *mInitialMessageData;
    /* 3c */ s32 mInitialMessageSize;
    /* 40 */ u8 *mData;
    /* 44 */ GTI2Buffer mIncomingBuffer;
    /* 50 */ GTI2Buffer mSendBuffer;
    /* 5c */ struct DArrayImplementation *mIncomingBufferMessages;
    /* 60 */ struct DArrayImplementation *mOutgoingBufferMessages;
    /* 64 */ u16 mSerialNumber;
    /* 66 */ u16 mExpectedSerialNumber;
    /* 68 */ u8 mResponse[0x20];
    /* 88 */ u32 mLastSendTime;
    /* 8c */ u32 mChallengeTime;
    /* 90 */ u32 mPendingAck;
    /* 94 */ u32 mPendingAckTime;
    /* 98 */ struct DArrayImplementation *mSendFilters;
    /* 9c */ void *mReceiveFilters;
} GTI2Connection;

BOOL gti2UnrecognizedMessageCallback(GTI2Socket *socket, s32 address, s32 port, void *message, s32 len, s32 *handled);
BOOL gti2PingCallback(GTI2Connection *connection, s32 latency);

typedef struct GTI2Socket GTI2Socket;
typedef struct GTI2Connection GTI2Connection;

BOOL gti2ReceivedCallback(GTI2Connection *connection, void *message, int len, int reliable);
BOOL gti2ConnectedCallback(GTI2Connection *connection, int result, void *message, int len);
BOOL CallIncomingConnectionCallback(GTI2Socket *socket, GTI2Connection *connection, int address, int port,
                                    int latency, const u8 *message, int len);

u32 gti2DumpCallback(GTI2Socket *socket, GTI2Connection *connection, u32 address, u32 port, u32 reset, int message,
                     int len, int send);
BOOL gti2ReceiveFilterCallback(GTI2Connection *connection, s32 filterId, void *message, s32 len, s32 reliable);
BOOL gti2SendFilterCallback(GTI2Connection *connection, s32 filterId, void *message, s32 len, s32 reliable);
BOOL gti2ClosedCallback(GTI2Connection *connection, void *reason);
BOOL gti2SocketErrorCallback(GTI2Socket *socket);
void gti2ConnectionCleanup(GTI2Connection *connection);
void gti2ConnectionClosed(GTI2Connection *connection, ...);
void gti2CloseConnection(GTI2Connection *connection, int hard);
