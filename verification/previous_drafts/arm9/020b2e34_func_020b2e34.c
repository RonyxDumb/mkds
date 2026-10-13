/* Decompiled C draft; module arm9; ROM address 020b2e34. No matching claim. */
#include "types.h"
#include "deps/020b2e34_func_020b2e34.h"

int func_020b2e34(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*piRam020b2e54 + 0x24);
  if ((iVar2 == 2) && (iVar1 = func_020c3db4(), iVar1 != 0)) {
    iVar2 = 7;
  }
  return iVar2;
}

