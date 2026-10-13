/* Decompiled C draft; module arm9; ROM address 02090288. No matching claim. */
#include "types.h"
#include "deps/02090288_func_02090288.h"

void func_02090288(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = func_0207c078();
  if ((iVar2 == 0) &&
     (uVar1 = param_2 + 0xb0U & 3, uVar3 = *(uint *)(param_2 + 0xb0U & 0xfffffffc),
     uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0)) {
    return;
  }
  func_0207c614(param_1,param_2);
  return;
}

