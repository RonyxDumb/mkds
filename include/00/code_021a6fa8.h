#pragma once

#include "types.h"
#include "os_thread.h"

typedef struct OSThreadQueue OSThreadQueue;
typedef struct OSMutex OSMutex;
typedef struct OSMessageQueue OSMessageQueue;

struct Unk021a6fa8;
struct Unk021a78a4;

// Four bytes read by func_ov000_021a72a4: a size, a count and a byte.
typedef struct Unk021a72a4 {
    /* 00 */ u16 field0;
    /* 02 */ u8 field2;
    /* 03 */ u8 field3;
} Unk021a72a4;

// Start address and size of a part of an Unk021a6fa8 or of its blocks, set by func_ov000_021a71a4.
typedef struct SizedBuffer {
    /* 00 */ s32 mSize;
    /* 04 */ u8 *mStart;
} SizedBuffer;

// Shared start of the two blocks func_ov000_021a71c0 sets up behind an Unk021a6fa8.
typedef struct Unk021a7154 {
    /* 00 */ OSMessageQueue field0;
    /* 20 */ OSThread field20;
    /* d8 */ u8 fieldD8[8];
    /* e0 */ OSMutex fieldE0;
} Unk021a7154;

typedef struct Unk021a71c0 {
    /* 000 */ Unk021a7154 field0;
    /* 0f8 */ s32 fieldF8;
    /* 0fc */ u16 fieldFC;
    /* 0fe */ s8 fieldFE;
    /* 100 */ struct Unk021a78a4 *field100;
    /* 104 */ struct Unk021a78a4 *field104;
    /* 108 */ u16 field108;
    /* 10a */ u16 field10A;
    /* 10c */ OSThreadQueue field10C;
    /* 114 */ u8 field114[4];
} Unk021a71c0;

typedef struct Unk021a722a {
    /* 000 */ Unk021a7154 field0;
    /* 0f8 */ SizedBuffer fieldF8;
    /* 100 */ u16 field100;
    /* 102 */ u16 field102;
    /* 104 */ s32 field104;
    /* 108 */ s32 field108;
    /* 10c */ struct Unk021a6fa8 *field10C;
    /* 110 */ u8 field110[4];
} Unk021a722a;

typedef struct Unk021a6fa8 {
    /* 00 */ u8 field0[8];
    /* 08 */ u8 mState;
    /* 09 */ u8 field9;
    /* 0a */ u16 fieldA;
    /* 0c */ u8 fieldC[0xc];
    /* 18 */ u16 field18;
    /* 1a */ u16 field1A;
    /* 1c */ u32 field1C;
    /* 20 */ u32 field20;
    /* 24 */ u8 field24[0x18];
    /* 3c */ SizedBuffer mReceiveBuffer;
    /* 44 */ s32 mReceiveBufferLength;
    /* 48 */ SizedBuffer mSendBuffer;
    /* 50 */ SizedBuffer field50;
    /* 58 */ SizedBuffer field58;
    /* 60 */ u8 field60[4];
    /* 64 */ Unk021a71c0 *mReceiveBlock;
    /* 68 */ Unk021a722a *mSendBlock;
    /* 6c */ s32 mEntryResult;
    /* 70 */ s16 field70;
    /* 72 */ s8 field72;
    /* 73 */ s8 field73;
    /* 74 */ u16 field74;
    /* 76 */ u16 field76;
    /* 78 */ u16 *field78;
    /* 7c */ struct Unk021a6fa8 *mNext;
    /* 80 */ Unk021a71c0 field80;
} Unk021a6fa8;

s32 func_ov000_021a6fa8(Unk021a6fa8 *object, void *request);
