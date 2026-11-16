#pragma once

#include "types.h"
#include "00/types_021906e4.h"

// Object behind GpiOperation.field4: GpiCreateSearch clears and fills it, GpiOpenSearchSocket sets the
// word at 0x04 and gives it the buffer at 0x08 of 0x0c bytes.
typedef struct Unk02196240 {
    /* 000 */ s32 mKind;
    /* 004 */ s32 mSocket;
    /* 008 */ void *mInputBuffer;
    /* 00c */ s32 fieldC;
    /* 010 */ u32 field10;
    /* 014 */ u32 field14;
    /* 018 */ void *mOutputBuffer;
    /* 01c */ s32 field1C;
    /* 020 */ u32 field20;
    /* 024 */ u32 field24;
    /* 028 */ s8 field28[0x1f];
    /* 047 */ s8 field47[0x15];
    /* 05c */ s8 field5C[0x33];
    /* 08f */ s8 field8F[0x1f];
    /* 0ae */ s8 fieldAE[0x1f];
    /* 0cd */ s8 fieldCD[0x1f];
    /* 0ec */ s8 fieldEC[0x44];
    /* 130 */ s32 field130;
    /* 134 */ s32 field134;
    /* 138 */ s32 field138;
    /* 13c */ s32 field13C;
    /* 140 */ s32 field140;
} Unk02196240;

typedef struct GpiOperation {
    /* 00 */ u32 mType;
    /* 04 */ Unk02196240 *field4;
    /* 08 */ u32 field8;
    /* 0c */ GpiCallback fieldC;
    /* 14 */ s32 field14;
    /* 18 */ u32 mId;
    /* 1c */ u32 field1C;
    /* 20 */ struct GpiOperation *mNext;
} GpiOperation;

typedef struct GpiPeer {
    /* 00 */ s32 mState;
    /* 04 */ u32 field4;
    /* 08 */ s32 mSocket;
    /* 0c */ u32 mProfileId;
    /* 10 */ s32 field10;
    /* 14 */ s32 field14;
    /* 18 */ void *mInputBuffer;
    /* 1c */ u32 field1C;
    /* 20 */ BOOL field20;
    /* 24 */ u8 field24[4];
    /* 28 */ u8 mOutputBuffer[8];
    /* 30 */ s32 mOutputBufferLength;
    /* 34 */ u8 field34[4];
    /* 38 */ struct Darray *mQueuedMessages;
    /* 3c */ struct GpiPeer *mNext;
} GpiPeer;
