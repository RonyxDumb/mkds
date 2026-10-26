#pragma once

#include "types.h"

struct Unk02005210;

extern u8 data_0217eed4[];
extern struct Unk02005210 *data_0217eeb0;
// Function pointers called and cleared by func_02133e50 (data_0217e984) and func_02133f84 (data_0217e988).
extern void (*data_0217e984)(void);
extern void (*data_0217e988)(void);
// Count of the entries of data_0217e994 that func_02133e50 calls, last first.
extern int data_0217e98c;
// Set by func_02133fd8; func_02133f84 reads it.
extern int data_0217e990;
extern void (*data_0217e994[])(void);
// Word arrays; func_02133e50 uses entry 0 of each, func_02134890 entries 3-5, func_02135144 entry 3 and
// func_02139e20 entry 7.
extern u32 data_0217ea94[];
extern u32 data_0217eab8[];
// 0x14-byte entries passed to func_0200ec08, func_0200ecc4 and func_0200ed34; func_02133e50 uses entry 0,
// func_02134890 entries 3-5, func_02135144 entry 3 and func_02139e20 entry 7.
extern u8 data_0217eadc[][0x14];
