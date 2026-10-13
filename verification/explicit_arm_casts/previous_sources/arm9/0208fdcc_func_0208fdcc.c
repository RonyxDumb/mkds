/* Decompiled C draft; module arm9; ROM address 0208fdcc. No matching claim. */
#include "types.h"
#include "deps/0208fdcc_func_0208fdcc.h"

void func_0208fdcc(undefined4 param_1,int param_2)

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
    func_0207c6d0(param_1,param_2);
    return;
  }
  return;
}

