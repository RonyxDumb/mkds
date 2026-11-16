#pragma once

#include "types.h"

typedef struct Unk021b6434 {
    /* 00 */ u32 field0;
    /* 04 */ u8 field4[6];
    /* 0a */ u16 fieldA;
} Unk021b6434;

typedef struct Unk021b69dc {
    /* 00 */ u32 field0;
    /* 04 */ u16 field4;
    /* 06 */ u16 field6;
    /* 08 */ u16 field8;
    /* 0a */ u16 fieldA;
    /* 0c */ u16 fieldC[8];
    /* 1c */ u16 field1C[8];
    /* 2c */ u32 field2C;
    /* 30 */ u8 *field30;
    /* 34 */ u8 *field34;
} Unk021b69dc;

typedef struct Unk021b6494 {
    /* 00 */ u8 field0[0x3c];
    /* 3c */ u32 mReceiveBufferSize;
    /* 40 */ u8 *mReceiveBuffer;
    /* 44 */ u8 field44[4];
    /* 48 */ u32 mSendBufferSize;
    /* 4c */ u8 *mSendBuffer;
    /* 50 */ u8 field50[0x14];
} Unk021b6494;

extern u64 data_ov000_021b63e0[3];
extern u32 data_ov000_021b638c;
extern u32 data_ov000_021b63a0;
extern u32 data_ov000_021b63b0;
extern u32 data_ov000_021b63b8;
extern u32 data_ov000_021b63bc;
extern u32 data_ov000_021b6398;
extern u16 data_ov000_021b63d0[3];
extern void (*data_ov000_021b6384)(void);
extern u8 data_ov000_021b4c34[];
extern u8 data_ov000_021b6706[];
extern u8 data_ov000_021b685c[];
extern u8 data_ov000_021b66dc[];
extern Unk021b6434 data_ov000_021b6434[8];
extern Unk021b69dc data_ov000_021b69dc[8];
extern Unk021b6494 data_ov000_021b6494;
