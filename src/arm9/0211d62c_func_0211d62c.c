/* Decompiled C draft; module arm9; ROM address 0211d62c. No matching claim. */
#include "types.h"
#include "deps/0211d62c_func_0211d62c.h"

short func_0211d62c(void)

{
  int iVar1;
  
  iVar1 = *piRam0211d64c;
  if (*(int *)(iVar1 + 0x6c) == 0) {
    return 0;
  }
  return *(short *)(iVar1 + 0xb0) + *(short *)(iVar1 + 0xb2);
}

