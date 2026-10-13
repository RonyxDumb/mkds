/* Decompiled C draft; module arm9; ROM address 02101c84. No matching claim. */
#include "types.h"
#include "deps/02101c84_func_02101c84.h"

void func_02101c84(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStack_18 [12];
  
  StateDualHandler_Execute(param_1 + 300);
  VecFx32_Subtract(param_1 + 0x50,param_1 + 0xe4,param_1 + 0x5c);
  uVar1 = param_1 + 0xd0U & 3;
  uVar3 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
  if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) != param_1 + 0xc4U) {
    return;
  }
  uVar1 = param_1 + 0x168U & 3;
  uVar3 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
  uVar1 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  if (uVar1 != 0) {
    iVar4 = uVar1 + 0x98;
    VecFx32_Subtract(param_1 + 0x50,iVar4,auStack_18);
    uVar2 = func_020e6b38();
    MTX_MultVec33(auStack_18,uVar2,auStack_18);
    VecFx32_Add(iVar4,auStack_18,param_1 + 0xc4);
    return;
  }
  return;
}

