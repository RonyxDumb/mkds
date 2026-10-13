/* Decompiled C draft; module arm9; ROM address 01ffcb58. No matching claim. */
#include "types.h"
#include "deps/01ffcb58_func_01ffcb58.h"

void func_01ffcb58(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uVar2 = param_1 + 0x7cU & 3;
  uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x20) == 0) {
    uVar2 = param_1 + 0x44U & 3;
    uVar1 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x20;
    bVar4 = uVar2 != 0;
    if (bVar4) {
      uVar2 = param_1 + 0x44U & 3;
      uVar1 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    if (bVar4) {
      *(uint *)(param_1 + 0x44) = uVar2 | 0x80000;
    }
    else {
      uVar2 = param_1 + 0x44U & 3;
      uVar1 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
      *(uint *)(param_1 + 0x44) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0xfff7ffff;
    }
    func_01ffc008(param_1 + 0x1b8,param_1 + 0x98,0x400,param_1);
    func_01ffa4b4(param_1,&uStack_18);
    func_01ff9f60(param_1,&uStack_18);
    *(undefined4 *)(param_1 + 0x244) = uStack_18;
    *(undefined4 *)(param_1 + 0x248) = uStack_14;
    *(undefined4 *)(param_1 + 0x24c) = uStack_10;
    uVar2 = param_1 + 0x4d0U & 3;
    uVar1 = *(uint *)(param_1 + 0x4d0U & 0xfffffffc);
    *(uint *)(param_1 + 0x4d0) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 1;
    uVar2 = param_1 + 0x4cU & 3;
    uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x8000) != 0) {
      StructMQRacerEntry_SomeFn_61(param_1);
    }
    uVar2 = param_1 + 0x7cU & 3;
    uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if ((((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 1) != 0) &&
       (iVar3 = IsAwardOrStaffRoll(), iVar3 == 1)) {
      func_0207a790(*(undefined2 *)(param_1 + 0x74));
    }
    func_01ffc920(param_1);
    func_01ffc8cc(param_1);
    uVar2 = param_1 + 0x4cU & 3;
    uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 8) != 0) {
      StructMQRacerEntry_SomeFn_85(param_1);
    }
    uVar2 = param_1 + 0x230U & 3;
    uVar1 = *(uint *)(param_1 + 0x230U & 0xfffffffc);
    (*(code *)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20))(param_1);
    return;
  }
  return;
}

