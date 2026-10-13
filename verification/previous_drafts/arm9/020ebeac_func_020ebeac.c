/* Decompiled C draft; module arm9; ROM address 020ebeac. No matching claim. */
#include "types.h"
#include "deps/020ebeac_func_020ebeac.h"

void func_020ebeac(int param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  
  puVar2 = puRam020ebef4;
  puVar1 = puRam020ebef0;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020ebeec;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puVar1;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puVar2;
  return;
}

