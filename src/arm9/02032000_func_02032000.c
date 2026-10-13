/* Decompiled C draft; module arm9; ROM address 02032000. No matching claim. */
#include "types.h"
#include "deps/02032000_func_02032000.h"

int func_02032000(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  uVar3 = 1;
  do {
    iVar1 = func_0204fcec(uVar3 & 0xffff,0);
    if (iVar1 != 0) {
      iVar2 = iVar2 + 1;
    }
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 8);
  return iVar2;
}

