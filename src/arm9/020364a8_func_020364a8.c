/* Decompiled C draft; module arm9; ROM address 020364a8. No matching claim. */
#include "types.h"
#include "deps/020364a8_func_020364a8.h"

void func_020364a8(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  *puRam020364dc =
       *puRam020364dc & 0x43 | (ushort)(param_1 << 0xe) | (ushort)(param_2 << 7) |
       (ushort)(param_3 << 8) | (ushort)(param_4 << 2) | (ushort)(param_5 << 0xd);
  return;
}

