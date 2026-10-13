/* Decompiled C draft; module arm9; ROM address 020091e0. No matching claim. */
#include "types.h"
#include "deps/020091e0_func_020091e0.h"

void func_020091e0(int param_1,undefined4 param_2)

{
  *(undefined2 *)(param_1 + 10) = 0x20;
  *(short *)(param_1 + 0xc) = (short)param_2;
  *(ushort *)(param_1 + 0xe) =
       (ushort)((uint)param_2 >> 0x10) & (ushort)((uint)uRam020091f8 >> 0x10);
  *(undefined2 *)(param_1 + 0x10) = *(undefined2 *)(param_1 + 0x48);
  return;
}

