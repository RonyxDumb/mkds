/* Decompiled C draft; module arm9; ROM address 02013b20. No matching claim. */
#include "types.h"
#include "deps/02013b20_func_02013b20.h"

int func_02013b20(int param_1,int param_2)

{
  return (uint)*(ushort *)(param_1 + 0xc + (uint)*(ushort *)(param_1 + 0x12)) * param_2 +
         param_1 + 0xc + (uint)*(ushort *)(param_1 + 0x12) + 4;
}

