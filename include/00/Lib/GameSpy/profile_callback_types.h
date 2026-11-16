#pragma once

#include "types.h"

// Result of a profile request; 0 is OK. 4 is also stored when the connection could not be opened and when the server
// answered with an error.
typedef enum ProfileRequestResult {
    PROFILE_REQUEST_OK = 0,
    PROFILE_REQUEST_FAILED = 4
} ProfileRequestResult;

// A growable byte buffer: its data, capacity, length and the position up to which it was read or sent.
typedef struct GPIBuffer {
    /* 00 */ u8 *mBuffer;
    /* 04 */ s32 mCapacity;
    /* 08 */ s32 mLength;
    /* 0c */ s32 mPos;
} GPIBuffer;

// A callback function pointer as the library calls it: the connection, the argument and the stored parameter.
typedef void (*GPCallback)(void *connection, void *arg, u32 param);

// A callback function and the parameter it is called with.
typedef struct GPICallback {
    /* 00 */ GPCallback mCallback;
    /* 04 */ u32 mParam;
} GPICallback;

// The data a queued callback hands to its function: lists of nicks, matches or a transfer message.
typedef struct CallbackArgData {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ s32 mSuggestedNickCount;
    /* 08 */ void **mUnk_08;
    /* 0c */ void *mMatchList;
    /* 10 */ void *mTransferMessage;
    /* 14 */ u8 mUnk_14[0x24];
    /* 38 */ s32 mNickCount;
    /* 3c */ void **mNicknames;
    /* 40 */ void **mUniquenicks;
} CallbackArgData;

// Values of QueuedCallback.mType; the ones that free members say which CallbackArgData members
// gpiCallCallback frees after the call. The errors are delivered with every callback queue run. STATUS and
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

// One callback waiting in the queue: the function, its argument data, its kind, the operation it belongs to
// (mOperationId) and the next entry.
typedef struct QueuedCallback {
    /* 00 */ GPICallback mCallback;
    /* 08 */ struct CallbackArgData *mArg;
    /* 0c */ s32 mType;
    /* 10 */ u32 mOperationId;
    /* 14 */ struct QueuedCallback *mNext;
} QueuedCallback;

// The argument of the error callback: result, error code, error string and fatal flag.
typedef struct ErrorData {
    /* 00 */ s32 mResult;
    /* 04 */ u32 mErrorCode;
    /* 08 */ void *mErrorString;
    /* 0c */ s32 mFatal;
} ErrorData;
