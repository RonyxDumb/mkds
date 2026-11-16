#pragma once

#include "00/code_0219b580.h"
#include "00/code_0219c384.h"
#include "00/code_0219c93c.h"
#include "00/code_0219d934.h"
#include "00/code_0219de4c.h"
#include "types.h"
#include "00/code_021a4b98.h"
#include "00/code_021a2ccc.h"
#include "00/code_021a3760.h"
#include "code_02142eac.h" // Unk021438f0
#include "code_0200f790.h"
#include "00/code_021a6fa8.h"
#include "code_0200e77c.h"

// One element of the table at data_ov000_021b5dfc.
typedef struct Unk021b5dfc {
    /* 0 */ u32 field0;
} Unk021b5dfc;

typedef void (*Unk021b5f54Func)(void *param_1, void *param_2, void *param_3, u16 param_4);

typedef struct Unk021b5f54 {
    /* 00 */ u8 field0;
    /* 04 */ OSThreadQueue field4;
    /* 0c */ OSMutex fieldC;
    /* 24 */ s32 field24;
    /* 28 */ Unk021b5f54Func field28;
} Unk021b5f54;

typedef struct Unk021b5f94 {
    /* 00 */ s32 field0;
    /* 04 */ u32 field4;
    /* 08 */ u32 field8;
    /* 0c */ u32 fieldC;
    /* 10 */ u32 field10;
    /* 14 */ u32 field14;
    /* 18 */ void *(*field18)(u32 param_1);
    /* 1c */ void (*field1C)(void *param_1);
    /* 20 */ s32 field20;
    /* 24 */ s32 field24;
    /* 28 */ void *field28;
    /* 2c */ s32 field2C;
    /* 30 */ s32 field30;
    /* 34 */ s32 field34;
} Unk021b5f94;

typedef struct Unk021b5fa8 {
    /* 00 */ s32 field0;
    /* 04 */ void *(*field4)(u32 param_1);
    /* 08 */ void (*field8)(void *param_1);
    /* 0c */ void (*fieldC)(void);
    /* 10 */ u32 (*field10)(void);
    /* 14 */ s32 field14;
    /* 18 */ s32 field18;
    /* 1c */ void *field1C;
    /* 20 */ s32 field20;
    /* 24 */ s32 field24;
    /* 28 */ u32 field28;
    /* 2c */ u32 field2C;
} Unk021b5fa8;

// Objects whose layout isn't known yet.
extern u8 data_ov000_021b5dec[];
extern u8 data_ov000_021b5df0[];
extern Unk021b5f50 *data_ov000_021b5f50;
extern u8 data_ov000_021b5f98[];

extern u8 gMatchingMaskedParticipantIndices[0x20];

// Four bytes at data_ov000_021b5668.
typedef struct Unk021b5668 {
    /* 00 */ u8 field0;
    /* 01 */ u8 field1;
    /* 02 */ u16 field2;
} Unk021b5668;

extern Unk021b5668 data_ov000_021b5668;

typedef struct Unk021b5670 {
    /* 00 */ u8 field0;
    /* 01 */ u8 field1;
    /* 02 */ u8 field2;
    /* 03 */ u8 field3;
    /* 04 */ u32 field4;
    /* 08 */ u32 field8;
    /* 0c */ u32 fieldC;
    /* 10 */ u64 field10;
    /* 18 */ u64 field18;
} Unk021b5670;

extern Unk021b5670 *data_ov000_021b5670;
extern void *gMatchingFilterText;
extern Unk021b5f54 data_ov000_021b5f54;
extern u8 data_ov000_021b5f80;
extern u8 data_ov000_021b5f84[16];
extern Unk021b5f94 *data_ov000_021b5f94;
extern u32 data_ov000_021b5f9c;
extern Unk021a6fa8 *data_ov000_021b5fa4;
extern Unk021b5fa8 data_ov000_021b5fa8;
extern void *data_ov000_021b5fd8;
extern OSMessageQueue data_ov000_021b5fdc;

extern s32 data_ov000_021b5284;
extern char data_ov000_021b5288[2][0x16];
extern char *data_ov000_021b52b4;
extern char *data_ov000_021b52b8;
extern u32 data_ov000_021b52bc;
extern u32 data_ov000_021b52c0;
extern void *data_ov000_021b52c4;
extern u8 data_ov000_021b52c8[];
extern s32 data_ov000_021b54cc;
extern void *data_ov000_021b5658;
extern void (*data_ov000_021b5660)();
