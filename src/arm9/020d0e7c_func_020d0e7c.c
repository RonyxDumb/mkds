/* Decompiled C draft; module arm9; ROM address 020d0e7c. No matching claim. */
#include "types.h"
#include "deps/020d0e7c_func_020d0e7c.h"

undefined4 func_020d0e7c(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = func_020d0ec4();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(*(int *)(*piRam020d0e9c + 4) + 0x14);
  }
  return uVar2;
}

