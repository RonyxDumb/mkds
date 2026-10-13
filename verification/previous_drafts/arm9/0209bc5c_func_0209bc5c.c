/* Decompiled C draft; module arm9; ROM address 0209bc5c. No matching claim. */
#include "types.h"
#include "deps/0209bc5c_func_0209bc5c.h"

uint func_0209bc5c(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = func_0210008c();
  uVar3 = iVar2 + param_2 * 4;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  return uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
}

