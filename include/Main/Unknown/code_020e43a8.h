#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Three vectors, 0x24 bytes.
typedef struct Unk020e43a8_28 {
    /* 00 */ Vec3 field0;
    /* 0c */ Vec3 fieldC;
    /* 18 */ Vec3 field18;
} Unk020e43a8_28;

// Object read through field9C; only the s16 at 0x28 is seen.

// Object passed to rotcyl_state2Update and the functions after it, and to wbox_render and
// rdmo_onItemCollide to rdmo_initParams; the words from 0xa0 to 0xc8 are read two ways.
typedef struct Unk020e43a8 {
    /* 00 */ MapObject field0;
    /* a0 */ union {
        struct {
            /* a0 */ Unk020e43a8_28 fieldA0;
            /* c4 */ u16 fieldC4;
            /* c6 */ s16 fieldC6;
        };
        // As wbox_render, rdmo_20EC538, rdmo_20EC6E4, rdmo_dieUpdate and
        // rdmo_initParams read it: halfwords at 0xac and 0xae, a word at 0xc4.
        struct {
            /* a0 */ s32 fieldA0;
            /* a4 */ s32 fieldA4;
            /* a8 */ u32 fieldA8;
            /* ac */ u16 fieldAC;
            /* ae */ u16 fieldAE;
            /* b0 */ u32 fieldB0;
            /* b4 */ s32 fieldB4;
            /* b8 */ u8 fieldB8[4];
            /* bc */ s32 fieldBC;
            /* c0 */ s32 fieldC0;
            /* c4 */ s32 fieldC4;
        };
    };
    /* c8 */ s32 fieldC8;
    /* cc */ s32 fieldCC;
    /* d0 */ s32 fieldD0;
    /* d4 */ s32 fieldD4;
    /* d8 */ s32 fieldD8;
    /* dc */ s32 fieldDC;
    /* e0 */ u8 fieldE0[0x14];
    /* f4 */ Vec3 fieldF4;
    /* 100 */ s32 field100;
    /* 104 */ s32 field104;
    /* 108 */ s32 field108;
    /* 10c */ u8 field10C[0x08];
    /* 114 */ u8 field114[0x04];
    /* 118 */ u8 field118[0x0c];
    /* 124 */ s32 field124;
    /* 128 */ s32 field128;
    /* 12c */ s32 field12C;
    /* 130 */ u8 field130[0x14];
    /* 144 */ u16 field144;
    /* 146 */ u16 field146;
    /* 148 */ u8 field148[0x02];
    /* 14a */ s16 field14A;
    /* 14c */ s32 field14C;
    /* 150 */ s32 field150;
    /* 154 */ u8 field154[0x08];
    /* 15c */ s32 field15C;
} Unk020e43a8;

void rotcyl_state2Update(Unk020e43a8 *object);
