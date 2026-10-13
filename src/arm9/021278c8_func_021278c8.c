/* Decompiled C draft; module arm9; ROM address 021278c8. No matching claim. */
#include "types.h"
#include "deps/021278c8_func_021278c8.h"

void func_021278c8(void)

{
  int iVar1;
  
  iVar1 = *piRam021278f0;
  if (((*(int *)(iVar1 + 4) == 0) && (*(int *)(iVar1 + 0x24) != 0)) || (*(int *)(iVar1 + 4) == 1)) {
    *(undefined4 *)(iVar1 + 0x28) = 1;
  }
  else {
    *(undefined4 *)(iVar1 + 0x28) = 0;
  }
  *(undefined4 *)(*piRam021278f0 + 0x24) = 1;
  return;
}

