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
    /* 04 */ u32 field4;
} GpiCallback;

// Data behind GpiQueuedCallback.mArg: the members freed depend on the value at 0x0c.
typedef struct Unk02190da0Data {
    /* 00 */ u8 field0[4];
    /* 04 */ s32 field4;
    /* 08 */ void **field8;
    /* 0c */ void *fieldC;
    /* 10 */ void *field10;
    /* 14 */ u8 field14[0x24];
    /* 38 */ s32 field38;
    /* 3c */ void **field3C;
    /* 40 */ void **field40;
} Unk02190da0Data;

// Entry of the list whose head and tail are at 0x438 and 0x43c of the object.
typedef struct GpiQueuedCallback {
    /* 00 */ GpiCallback mCallback;
    /* 08 */ struct Unk02190da0Data *mArg;
    /* 0c */ s32 fieldC;
    /* 10 */ u32 field10;
    /* 14 */ struct GpiQueuedCallback *mNext;
} GpiQueuedCallback;

// Object whose 0x28 member is a buffer; 0x08 is the descriptor written to.
typedef struct Unk02190988 {
    /* 00 */ u8 field0[8];
    /* 08 */ s32 mSocket;
    /* 0c */ u8 fieldC[0x1c];
    /* 28 */ GpiBuffer mOutputBuffer;
    /* 38 */ u32 *mQueuedMessages;
} Unk02190988;

// Object at 0x04 of GpiOperation.
typedef struct Unk02191284Data {
    /* 000 */ char field0[0x80];
    /* 080 */ char field80[0x21];
    /* 0a1 */ char fieldA1[0x21];
    /* 0c2 */ s8 fieldC2[0x200];
    /* 2c2 */ s8 field2C2[0x42];
    /* 304 */ s32 field304;
} Unk02191284Data;

// Object GpiQueueErrorCallback allocates and hands to GpiQueueCallback.
typedef struct Unk02190f4c {
    /* 00 */ s32 field0;
    /* 04 */ u32 field4;
    /* 08 */ void *field8;
    /* 0c */ s32 fieldC;
} Unk02190f4c;

// Object GpiProcessConnectOperation allocates and hands to GpiQueueCallback.
typedef struct Unk02191284Node {
    /* 00 */ s32 field0;
    /* 04 */ u32 field4;
    /* 08 */ char field8[0x18];
} Unk02191284Node;
