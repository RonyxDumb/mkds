#pragma once

#include "types.h"
#include "03/code_021bf43c.h"
#include "03/code_021c20dc.h"
#include "03/code_021c2120.h"
#include "03/code_021c6ba0.h"
#include "03/code_021cdc10.h"
#include "03/code_021cef6c.h"
#include "03/code_021cef80.h"
#include "03/code_021ce000.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d2060.h"
#include "03/unk_021da000.h"

// Object behind data_ov003_021da1fc.
typedef struct Unk021da1fc {
    /* 00 */ Unk021d2188 *mUnk_00;
    /* 04 */ Unk021da1f8_04 *mUnk_04;
    /* 08 */ u8 mUnk_08[0xc];
    /* 14 */ u8 mUnk_14;
    /* 15 */ u8 mUnk_15;
} Unk021da1fc;

// Five functions called with the object at 0x08.
typedef struct Unk021d7324 {
    /* 00 */ void (*mUnk_00[5])(u8 *);
} Unk021d7324;

extern Unk021d7324 data_ov003_021d7324;
extern u16 data_ov003_021d7308[];
extern u16 data_ov003_021d63f8[];
extern u8 data_ov003_021d63fc[];

// Declared here until the code that defines them is decompiled.
void func_ov003_021c7614(void);
void func_ov003_021c722c(void);

void func_ov003_021c70a4(void);
void func_ov003_021c7118(void);
void func_ov003_021c7160(void);
void func_ov003_021c71a0(void);
