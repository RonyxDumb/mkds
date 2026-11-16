#pragma once

#include "types.h"
#include "code_02022030.h"

typedef struct RaceHudSubScreenCells RaceHudSubScreenCells;

// Second view of an OAM entry: two words, each with a two-bit part at bit 10.
typedef struct RaceHudOamBits {
    /* 0 */ u32 field0 : 10;
    /* 0 */ u32 fieldA : 2;
    /* 0 */ u32 fieldC : 20;
    /* 4 */ u32 field4 : 10;
    /* 4 */ u32 fieldE : 2;
    /* 4 */ u32 field10 : 20;
} RaceHudOamBits;

// Rotation matrix view of four OAM entries (0x20 bytes): a halfword at each of 0x06, 0x0e, 0x16 and 0x1e.
typedef struct RaceHudOamMatrix {
    /* 00 */ u8 field0[6];
    /* 06 */ s16 field6;
    /* 08 */ u8 field8[6];
    /* 0e */ s16 fieldE;
    /* 10 */ u8 field10[6];
    /* 16 */ s16 field16;
    /* 18 */ u8 field18[6];
    /* 1e */ s16 field1E;
} RaceHudOamMatrix;

// Argument of the race HUD draw functions: 0x80 elements of 8 bytes, then a halfword.
typedef struct RaceHudOamBuffer {
    union {
        /* 000 */ GXOamAttr mOams[0x80];
        /* 000 */ RaceHudOamBits mOamBits[0x80];
        /* 000 */ RaceHudOamMatrix mMatrices[0x20];
    };
    /* 400 */ u16 mOamCount;
} RaceHudOamBuffer;

void mpicn_renderMObjIcon(RaceHudOamBuffer *oamBuffer, RaceHudSubScreenCells *cells, s32 useRotation);
void mpicn_20C06C4(RaceHudOamBuffer *oamBuffer, RaceHudSubScreenCells *cells, s32 useRotation);
