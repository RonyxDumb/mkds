/* Decompiled C draft; module arm9; ROM address 020d0ea0. No matching claim. */
#include "types.h"
#include "deps/020d0ea0_func_020d0ea0.h"

undefined4 func_020d0ea0(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = func_020d0ec4();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(*(int *)*puRam020d0ec0 + 0xc);
  }
  return uVar2;
}

