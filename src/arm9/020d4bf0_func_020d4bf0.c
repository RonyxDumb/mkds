/* Decompiled C draft; module arm9; ROM address 020d4bf0. No matching claim. */
#include "types.h"
#include "deps/020d4bf0_func_020d4bf0.h"

void func_020d4bf0(void)

{
  int iVar1;
  
  iVar1 = iRam020d4c14;
  *(undefined4 *)(iRam020d4c14 + 0x50) = 1;
  *(undefined4 *)(iVar1 + 0x54) = 0;
  if (*(int *)(*piRam020d4c18 + 0xc) == 2) {
    *puRam020d4c20 = uRam020d4c1c;
    return;
  }
  *puRam020d4c20 = uRam020d4c24;
  return;
}

