/* Decompiled C draft; module arm9; ROM address 020e4a34. No matching claim. */
#include "types.h"
#include "deps/020e4a34_func_020e4a34.h"

void func_020e4a34(int param_1)

{
  ushort *puVar1;
  
  puVar1 = puRam020e4a64;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020e4a60;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puVar1;
  return;
}

