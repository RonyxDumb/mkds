/* Decompiled C draft; module arm9; ROM address 0210cf9c. No matching claim. */
#include "types.h"
#include "deps/0210cf9c_func_0210cf9c.h"

void func_0210cf9c(int param_1,int param_2)

{
  if (param_2 == 1) {
    *(ushort *)(param_1 + 0x34) = *(ushort *)(param_1 + 0x34) | 1;
  }
  else {
    *(ushort *)(param_1 + 0x34) = *(ushort *)(param_1 + 0x34) & 0xfffe;
  }
  return;
}

