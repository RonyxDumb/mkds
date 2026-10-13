/* Decompiled C draft; module arm9; ROM address 020d0e58. No matching claim. */
#include "types.h"
#include "deps/020d0e58_func_020d0e58.h"

int func_020d0e58(void)

{
  int iVar1;
  
  iVar1 = func_020d0ec4();
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(*piRam020d0e78 + 8) + 0xc;
  }
  return iVar1;
}

