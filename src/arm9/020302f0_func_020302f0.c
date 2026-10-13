/* Decompiled C draft; module arm9; ROM address 020302f0. No matching claim. */
#include "types.h"
#include "deps/020302f0_func_020302f0.h"

void func_020302f0(int param_1,int param_2,ushort param_3,ushort param_4)

{
  ushort *puVar1;
  
  puVar1 = puRam02030338;
  *puRam02030334 = (ushort)(param_1 << 8) | param_3 & 0xff;
  *puVar1 = (ushort)(param_2 << 8) | param_4 & 0xff;
  return;
}

