#pragma once

#include "types.h"
#include "00/types_021906e4.h"

// Object behind GpiOperation.mUnk_04: GpiCreateSearch clears and fills it, GpiOpenSearchSocket sets the
// word at 0x04 and gives it the buffer at 0x08 of 0x0c bytes.
typedef struct GPISearchData {
    /* 000 */ s32 mKind;
    /* 004 */ s32 mSocket;
    /* 008 */ void *mInputBuffer;
    /* 00c */ s32 mInputBufferCapacity;
    /* 010 */ u32 mInputBufferLength;
    /* 014 */ u32 mInputBufferPos;
    /* 018 */ void *mOutputBuffer;
    /* 01c */ s32 mOutputBufferCapacity;
    /* 020 */ u32 mOutputBufferLength;
    /* 024 */ u32 mOutputBufferPos;
    /* 028 */ s8 mNick[0x1f];
    /* 047 */ s8 mUniquenick[0x15];
    /* 05c */ s8 mEmail[0x33];
    /* 08f */ s8 mFirstname[0x1f];
    /* 0ae */ s8 mLastname[0x1f];
    /* 0cd */ s8 mPassword[0x1f];
    /* 0ec */ s8 mCdkey[0x44];
    /* 130 */ s32 mIcquin;
    /* 134 */ s32 mSkip;
    /* 138 */ s32 mProductId;
    /* 13c */ s32 mProcessing;
    /* 140 */ s32 mRemove;
} GPISearchData;

typedef struct GpiOperation {
    /* 00 */ u32 mType;
    /* 04 */ GPISearchData *mData;
    /* 08 */ u32 mBlocking;
    /* 0c */ GpiCallback mCallback;
    /* 14 */ s32 mState;
    /* 18 */ u32 mId;
    /* 1c */ u32 mResult;
    /* 20 */ struct GpiOperation *mNext;
} GpiOperation;

typedef struct GpiPeer {
    /* 00 */ s32 mState;
    /* 04 */ u32 mUnk_04;
    /* 08 */ s32 mSocket;
    /* 0c */ u32 mProfileId;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ void *mInputBuffer;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ BOOL mUnk_20;
    /* 24 */ u8 mUnk_24[4];
    /* 28 */ u8 mOutputBuffer[8];
    /* 30 */ s32 mOutputBufferLength;
    /* 34 */ u8 mUnk_34[4];
    /* 38 */ struct Darray *mQueuedMessages;
    /* 3c */ struct GpiPeer *mNext;
} GpiPeer;
