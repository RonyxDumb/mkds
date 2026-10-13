/* Decompiled C draft; module arm9; ROM address 0211d478. No matching claim. */
#include "types.h"
#include "deps/0211d478_func_0211d478.h"

short func_0211d478(int param_1)

{
  int iVar1;
  
  iVar1 = *piRam0211d4a4;
  if (*(int *)(iVar1 + 0x6c) == 0) {
    return *(short *)(iVar1 + param_1 * 2 + 0xac);
  }
  iVar1 = iVar1 + param_1 * 2;
  return *(short *)(iVar1 + 0xac) + *(short *)(iVar1 + 0xb0);
}

