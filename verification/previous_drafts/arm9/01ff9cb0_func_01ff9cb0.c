/* Decompiled C draft; module arm9; ROM address 01ff9cb0. No matching claim. */
#include "types.h"
#include "deps/01ff9cb0_func_01ff9cb0.h"

void func_01ff9cb0(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_1 + 0x4cU & 3;
  uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if ((((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & 2) == 0) &&
     (iVar2 = IsAwardOrStaffRoll(), iVar2 == 1)) {
    func_01ffc9e8(param_1,0);
  }
  uVar3 = param_1 + 0x44U & 3;
  uVar1 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x44) = (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & 0xffffefff;
  uVar3 = param_1 + 0x208U & 3;
  uVar1 = *(uint *)(param_1 + 0x208U & 0xfffffffc);
  uVar3 = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
  if (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 != 0 ||
      *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20 != 0) {
    func_020e0538(uVar3,param_1 + 0x80);
    uVar3 = param_1 + 0x208U & 3;
    uVar1 = *(uint *)(param_1 + 0x208U & 0xfffffffc);
    *(undefined4 *)(uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) = 0;
    return;
  }
  return;
}

