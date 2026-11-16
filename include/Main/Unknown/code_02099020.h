#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020e005c.h" // GroupFollower

// Entry of the list behind the word at 0x08 of Unk0209905c_d0: a link at 0x00 and two halfwords at 0x24 and 0x26.
typedef struct Unk0209905c_d0_08 {
    /* 00 */ struct Unk0209905c_d0_08 *field0;
    /* 04 */ u8 field4[0x20];
    /* 24 */ u16 field24;
    /* 26 */ u16 field26;
} Unk0209905c_d0_08;

// Object behind the word at 0xd0 of Unk0209905c: a list at 0x08 and a flags word at 0x24.
typedef struct Unk0209905c_d0 {
    /* 00 */ u8 field0[8];
    /* 08 */ Unk0209905c_d0_08 *field8;
    /* 0c */ u8 fieldC[0x18];
    /* 24 */ u32 field24;
} Unk0209905c_d0;

// Object up to 0xd4 bytes: the shared part, an GroupFollower at 0xa0, then three words and a pointer.
typedef struct Unk0209905c {
    /* 00 */ MapObject field0;
    /* a0 */ GroupFollower mFollower;
    /* c4 */ s32 mHeightOffset;
    /* c8 */ s32 fieldC8;
    /* cc */ s32 mState;
    /* d0 */ Unk0209905c_d0 *mEmitter;
} Unk0209905c;

#include "Main/Unknown/code_0206bcb0.h" // Kart

extern u16 data_02156590;
extern u32 data_02156594;

void pknf_setupConfig(void);
void pknf_update(void *a, Unk0209905c *p);
u32 pknf_onDriverCollide(Unk0209905c *a, Kart *kart, u8 *c, u8 *d);
void pknf_init(unsigned int mapObject);
