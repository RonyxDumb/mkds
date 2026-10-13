/* Decompiled C draft; module arm9; ROM address 02027f1c. No matching claim. */
#include "types.h"
#include "deps/02027f1c_func_02027f1c.h"

void func_02027f1c(int param_1,int param_2,ushort param_3,ushort param_4)

{
  ushort *puVar1;
  
  puVar1 = puRam02027f64;
  *puRam02027f60 = (ushort)(param_1 << 8) | param_3 & 0xff;
  *puVar1 = (ushort)(param_2 << 8) | param_4 & 0xff;
  return;
}

