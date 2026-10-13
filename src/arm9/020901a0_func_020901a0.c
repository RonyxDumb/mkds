/* Decompiled C draft; module arm9; ROM address 020901a0. No matching claim. */
#include "types.h"
#include "deps/020901a0_func_020901a0.h"

void func_020901a0(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = func_0207c078();
  if (iVar2 == 0) {
    return;
  }
  uVar1 = param_2 + 0x70U & 3;
  uVar3 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
  if ((int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) < 0xa000) {
    func_0207c614(param_1,param_2);
    return;
  }
  return;
}

