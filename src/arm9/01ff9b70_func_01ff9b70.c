/* Decompiled C draft; module arm9; ROM address 01ff9b70. No matching claim. */
#include "types.h"
#include "deps/01ff9b70_func_01ff9b70.h"

void func_01ff9b70(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = param_1 + 0x4cU & 3;
  uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) & 0x8000) == 0) {
    func_0208c5b8(*(undefined2 *)(param_1 + 0x74));
    func_0208c534();
  }
  else {
    uVar2 = func_0208c5b8(*(undefined2 *)(param_1 + 0x74));
    iVar3 = func_020846a8(*(undefined2 *)(param_1 + 0x74));
    func_0208cb8c(uVar2,param_1);
    func_0208d4c4(uVar2,param_1);
    func_0208c930(uVar2,iVar3 + 0x4c,iVar3 + 0x34);
    func_0208c6dc(uVar2,iVar3 + 0x4c,iVar3 + 0x34);
  }
  *(undefined4 *)(param_1 + 0x3b0) = *(undefined4 *)(param_1 + 0xa4);
  *(undefined4 *)(param_1 + 0x3b4) = *(undefined4 *)(param_1 + 0xa8);
  *(undefined4 *)(param_1 + 0x3b8) = *(undefined4 *)(param_1 + 0xac);
  uVar5 = param_1 + 0x44U & 3;
  uVar1 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar5 = uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20;
  if (((uVar5 & 0x10) != 0) && ((uVar5 & 0x1000) == 0)) {
    uVar5 = param_1 + 0x3b4U & 3;
    uVar6 = *(uint *)(param_1 + 0x3b4U & 0xfffffffc);
    uVar1 = param_1 + 0x260U & 3;
    uVar4 = *(uint *)(param_1 + 0x260U & 0xfffffffc);
    *(uint *)(param_1 + 0x3b4) =
         (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) -
         (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  }
  uVar5 = param_1 + 0x3b0U & 3;
  uVar1 = *(uint *)(param_1 + 0x3b0U & 0xfffffffc);
  *(int *)(param_1 + 0x3b0) = (int)(uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) >> 4;
  uVar5 = param_1 + 0x3b4U & 3;
  uVar1 = *(uint *)(param_1 + 0x3b4U & 0xfffffffc);
  *(int *)(param_1 + 0x3b4) = (int)(uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) >> 4;
  uVar5 = param_1 + 0x3b8U & 3;
  uVar1 = *(uint *)(param_1 + 0x3b8U & 0xfffffffc);
  *(int *)(param_1 + 0x3b8) = (int)(uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) >> 4;
  return;
}

