/* Decompiled C draft; module arm9; ROM address 0200c508. No matching claim. */
#include "types.h"
#include "deps/0200c508_func_0200c508.h"

void func_0200c508(int *param_1)

{
  ushort *puVar1;
  
  puVar1 = puRam0200c530;
  *puRam0200c530 = *puRam0200c530 & 0xfff3 | (ushort)(*param_1 << 2);
  *puVar1 = *puVar1 & 0xffef | (ushort)(param_1[1] << 4);
  return;
}

