#pragma once

#include "types.h"

struct Unk020888b4;

// Entry of the table at data_0217b0a4, 0xc bytes.
typedef struct Unk0208fd8c_08 {
    /* 00 */ u8 mUnk_00[0xc];
} Unk0208fd8c_08;

// Object of 0x24 bytes at 0x11c of the object Unk020888b4 starts: a pointer to an entry of the table at data_0217b0a4
// at 0x08.
typedef struct Unk0208fd8c {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ Unk0208fd8c_08 *mUnk_08;
    /* 0c */ u8 mUnk_0c[0x18];
} Unk0208fd8c;

void func_0208fd8c(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0208fdcc(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0208fe1c(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0208fe58(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0208fefc(Unk0208fd8c *a, struct Unk020888b4 *b);
