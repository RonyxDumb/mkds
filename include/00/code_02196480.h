#pragma once

#include "types.h"

// Block filled by GpiOpenSearchSocket.
typedef struct Unk021962d4Addr {
    /* 00 */ u8 field0;
    /* 01 */ u8 field1;
    /* 02 */ u16 field2;
    /* 04 */ u32 field4;
} Unk021962d4Addr;

#include "00/GameSpy/gpiBuddy.h"
#include "00/code_02194000.h"
#include "00/GameSpy/gp.h"
#include "00/code_02190000.h"
#include "00/code_02193000.h"

extern char data_ov000_021b39a8[];
extern char data_ov000_021b39ac[];
extern char data_ov000_021b39c4[];
extern char data_ov000_021b39cc[];
extern u8 data_ov000_021b39fc[];

s32 func_ov000_02196480(GpConnection *a, s32 *b, GpiPeer *c, s32 d, const char *e);
s32 func_ov000_021964e4(GpConnection *a, GpiOperation *b, const char *c);
