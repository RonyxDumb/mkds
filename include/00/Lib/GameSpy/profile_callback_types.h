#pragma once

#include "types.h"

// Result of a GP request, stored in the mResult of the operation and of every response argument.
// 4 is stored when the connection failed while a blocking request waited for it.
typedef enum GpRequestResult {
    GP_REQUEST_OK = 0,
    GP_REQUEST_CONNECT_FAILED = 4
} GpRequestResult;

// A growable byte buffer: its data, capacity, length and read position.
typedef struct GpiBuffer {
    /* 00 */ u8 *mBuffer;
    /* 04 */ s32 mCapacity;
    /* 08 */ s32 mLength;
    /* 0c */ s32 mPos;
} GpiBuffer;

// Callback and its argument, as stored in the object at 0x1a4 and passed by value to GpiQueueCallback.
typedef void (*GpiCallbackFn)(void *connection, void *arg, u32 param);

// A callback function and the parameter it is called with.
typedef struct GpiCallback {
    /* 00 */ GpiCallbackFn mCallback;
    /* 04 */ u32 mParam;
} GpiCallback;

// The data a queued callback hands to its function: lists of nicks, matches or a transfer message.
typedef struct CallbackArgData {
    /* 00 */ u8 mData[4];
    /* 04 */ s32 mSuggestedNickCount;
    /* 08 */ void **mField30;
    /* 0c */ void *mMatchList;
    /* 10 */ void *mTransferMessage;
    /* 14 */ u8 mField35[0x24];
    /* 38 */ s32 mNickCount;
    /* 3c */ void **mNicknames;
    /* 40 */ void **mUniquenicks;
} CallbackArgData;

// Values of GpiQueuedCallback.mType; the ones that free members say which CallbackArgData members
// GpiCallAndFreeCallback frees after the call. The errors are delivered with every callback queue run. STATUS and
// REQUEST are queued with the status and buddy request callbacks; FREE_TRANSFER_MESSAGE frees the transfer message
// and is not queued anywhere.
enum {
    PROFILE_CALLBACK_TYPE_PLAIN,
    PROFILE_CALLBACK_TYPE_ERROR,
    PROFILE_CALLBACK_TYPE_FREE_MESSAGE_TEXT,
    PROFILE_CALLBACK_TYPE_FREE_NICK_LISTS,
    PROFILE_CALLBACK_TYPE_FREE_MATCH_LIST,
    PROFILE_CALLBACK_TYPE_STATUS = 5,
    PROFILE_CALLBACK_TYPE_REQUEST,
    PROFILE_CALLBACK_TYPE_FREE_TRANSFER_MESSAGE,
    PROFILE_CALLBACK_TYPE_FREE_OTHERS_PROFILES_IF_SET = 8,
    PROFILE_CALLBACK_TYPE_FREE_SUGGESTED_NICKS,
};

// One callback waiting in the queue: the function, its argument data, its kind and the next entry.
typedef struct GpiQueuedCallback {
    /* 00 */ GpiCallback mCallback;
    /* 08 */ struct CallbackArgData *mArg;
    /* 0c */ s32 mType;
    /* 10 */ u32 mOperationId;
    /* 14 */ struct GpiQueuedCallback *mNext;
} GpiQueuedCallback;

// Object GpiQueueErrorCallback allocates and hands to GpiQueueCallback.
typedef struct ErrorData {
    /* 00 */ s32 mResult;
    /* 04 */ u32 mErrorCode;
    /* 08 */ void *mErrorString;
    /* 0c */ s32 mFatal;
} ErrorData;
