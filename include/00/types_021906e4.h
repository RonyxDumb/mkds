#pragma once

#include "types.h"

// Growable byte buffer: 0x00 data, 0x04 capacity, 0x08 length, 0x0c read position.
typedef struct GpiBuffer {
    /* 00 */ u8 *mBuffer;
    /* 04 */ s32 mCapacity;
    /* 08 */ s32 mLength;
    /* 0c */ s32 mPos;
} GpiBuffer;

// Callback and its argument, as stored in the object at 0x1a4 and passed by value to GpiQueueCallback.
typedef struct GpiCallback {
    /* 00 */ void (*mCallback)(void *a, void *b, u32 c);
    /* 04 */ u32 mParam;
} GpiCallback;

// Data behind GpiQueuedCallback.mArg: the members freed depend on the value at 0x0c.
typedef struct CallbackArgData {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ s32 mUnk_04;
    /* 08 */ void **mUnk_08;
    /* 0c */ void *mUnk_0c;
    /* 10 */ void *mUnk_10;
    /* 14 */ u8 mUnk_14[0x24];
    /* 38 */ s32 mUnk_38;
    /* 3c */ void **mUnk_3c;
    /* 40 */ void **mUnk_40;
} CallbackArgData;

// Entry of the list whose head and tail are at 0x438 and 0x43c of the object.
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

// Object GpiProcessConnectOperation allocates and hands to GpiQueueCallback.
typedef struct Unk02191284Node {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ char mUniquenick[0x18];
} Unk02191284Node;
