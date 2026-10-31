#pragma once

#include "types.h"
#include "03/code_021bf43c.h"
#include "03/code_021bf5c8.h"
#include "03/code_021bf86c.h"
#include "03/code_021c20dc.h"
#include "03/code_021c2120.h"
#include "03/code_021c70a4.h"
#include "03/code_021d1c18.h"
#include "03/code_021d27d8.h"
#include "03/unk_021da000.h"
#include "code_0214d018.h"
#include "code_02134d30.h"

// Five functions called with the object at 0x08.
typedef struct Unk021d7310 {
    /* 00 */ void (*mUnk_00[5])(u8 *);
} Unk021d7310;

extern Unk021d7310 data_ov003_021d7310;
extern u8 data_ov003_021d7300[];
extern u8 data_ov003_021d73ac[];

// Declared here until the code that defines them is decompiled.
void func_ov003_021c7678(void);
void func_ov003_021c76b4(void);

void func_ov003_021c7748(void);
