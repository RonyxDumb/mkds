/* Decompiled C draft; module arm9_ov001; ROM address 02180bc0. No matching claim. */
#include "types.h"
#include "deps/02180bc0_func_ov001_02180bc0.h"

void func_ov001_02180bc0(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  *puRam02180bf4 =
       *puRam02180bf4 & 0x43 | (ushort)(param_1 << 0xe) | (ushort)(param_2 << 7) |
       (ushort)(param_3 << 8) | (ushort)(param_4 << 2) | (ushort)(param_5 << 0xd);
  return;
}

