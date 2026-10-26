#pragma once

#include "types.h"

// Local of func_0200d118 (sp+0x54); its address is passed to func_0200da58, func_0200dab8 and func_0200db20.
typedef struct Unk0200d118 {
    /* 00 */ u32 mUnk_00;   // func_0200db20 stores a byte only while this is nonzero, and lowers it
    /* 04 */ char *mUnk_04; // where func_0200db20 stores; raised for every byte, stored or not
    /* 08 */ char *mUnk_08; // first argument of func_0200d118
} Unk0200d118;

int func_0200d118(char *buf, u32 n, const char *p, char *q);
int func_0200d9e0(char *buf, u32 n, const char *p, ...);
int func_0200da10(char *buf, const char *p, char *q);
int func_0200da28(char *buf, const char *p, ...);
void func_0200da58(Unk0200d118 *s, const char *p, int n);
void func_0200dab8(Unk0200d118 *s, char c, int n);
void func_0200db20(Unk0200d118 *s, char c);
