#pragma once

#include "types.h"
#include "03/code_021cdd28.h"
#include "03/unk_021da000.h"
#include "03/Tasks.h"

// Entry of the table at offset 0x1300 of the object at data_ov003_021da280.
typedef struct Unk021ce4d4_1300 {
    /* 00 */ u8 field0[6];
    /* 06 */ u8 field6;
} Unk021ce4d4_1300;

// Object at data_ov003_021da280, as far as func_ov003_021ce4d4 uses it.
typedef struct Unk021ce4d4 {
    /* 0000 */ u8 field0[0x1300];
    /* 1300 */ Unk021ce4d4_1300 field1300[0x10];
    /* 1370 */ void (*field1370)(s32);
    /* 1374 */ u8 field1374[0x800];
    /* 1b74 */ u32 field1B74[2];
    /* 1b7c */ u32 field1B7C;
    /* 1b80 */ u8 field1B80[2];
    /* 1b82 */ u8 field1B82;
} Unk021ce4d4;

extern u8 data_ov003_021d6688[][5];
extern u8 data_ov003_021d6698[][5];

void func_ov003_021ce110(TaskEntry *a);
void func_ov003_021ce190(TaskEntry *a);
void func_ov003_021ce230(TaskEntry *a);
void func_ov003_021ce2d0(TaskEntry *a);
void func_ov003_021ce370(TaskEntry *a);
// Declared here until the code that defines it is decompiled.

void func_ov003_021ce408(u32 a);
void func_ov003_021ce4d4(u32 a);
