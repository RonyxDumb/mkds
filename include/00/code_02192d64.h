#pragma once

#include "types.h"

// Values read from the text, as built by GpiProcessInfoOperation on its stack. The pointers at 0x00 to 0x14 point to
// buffers of its own; 0x1c, 0x27 and 0x34 are arrays inside.
typedef struct Unk02192e04 {
    /* 00 */ char *field0[6];
    /* 18 */ s32 field18;
    /* 1c */ char field1C[0xb];
    /* 27 */ char field27[3];
    /* 2a */ u8 field2A[2];
    /* 2c */ float field2C;
    /* 30 */ float field30;
    /* 34 */ char field34[0x80];
    /* b4 */ u32 fieldB4;
    /* b8 */ u32 fieldB8;
    /* bc */ u32 fieldBC;
    /* c0 */ s32 fieldC0;
    /* c4 */ s32 fieldC4;
    /* c8 */ char *fieldC8;
    /* cc */ s32 fieldCC[9];
} Unk02192e04;

// Copy of Unk02192e04 made by func_ov000_0219338c, 0x204 bytes.
typedef struct Unk0219338c {
    /* 000 */ u32 field0;
    /* 004 */ s32 field4;
    /* 008 */ char field8[0x1f];
    /* 027 */ char field27[0x15];
    /* 03c */ char field3C[0x33];
    /* 06f */ char field6F[0x1f];
    /* 08e */ char field8E[0x1f];
    /* 0ad */ char fieldAD[0x4c];
    /* 0f9 */ u8 fieldF9[3];
    /* 0fc */ s32 fieldFC;
    /* 100 */ char field100[0xb];
    /* 10b */ char field10B[3];
    /* 10e */ u8 field10E[2];
    /* 110 */ float field110;
    /* 114 */ float field114;
    /* 118 */ char field118[0x80];
    /* 198 */ u32 field198;
    /* 19c */ u32 field19C;
    /* 1a0 */ u32 field1A0;
    /* 1a4 */ s32 field1A4;
    /* 1a8 */ s32 field1A8;
    /* 1ac */ char field1AC[0x33];
    /* 1df */ u8 field1DF;
    /* 1e0 */ s32 field1E0;
    /* 1e4 */ s32 field1E4;
    /* 1e8 */ s32 field1E8;
    /* 1ec */ s32 field1EC;
    /* 1f0 */ s32 field1F0;
    /* 1f4 */ s32 field1F4;
    /* 1f8 */ s32 field1F8;
    /* 1fc */ s32 field1FC;
    /* 200 */ s32 field200;
} Unk0219338c;

#include "00/GameSpy/gpiBuffer.h"
#include "00/GameSpy/gpiBuddy.h"

u32 GpiWriteUpdateBuffers(GpConnection *a, GpiBuffer *b);
s32 GpiProcessInfoOperation(GpConnection *r, GpiOperation *s, const char *t);
void func_ov000_0219338c(Unk02192e04 *a, Unk0219338c *b);
u32 GpiUnpackDate(u32 *a, s32 b, u32 *c, u32 *d, u32 *e);
// Declared here until the code that defines them is decompiled.
