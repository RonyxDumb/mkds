/* Decompiled C draft; module arm9; ROM address 021105a0. No matching claim. */
#include "types.h"
#include "deps/021105a0_func_021105a0.h"

void func_021105a0(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = iRam021105d4;
  do {
    func_0210e03c(iVar1);
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 8;
  } while (iVar2 < 7);
  return;
}

