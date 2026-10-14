/* Decompiled C draft; module arm9; ROM address 020f504c. No matching claim. */
#include "types.h"
#include "deps/020f504c_func_020f504c.h"

void func_020f504c(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = param_2 + 4U & 3;
  uVar2 = *(uint *)(param_2 + 4U & 0xfffffffc);
  uVar1 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x1fc;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  DriverContext_ApplyShroomBoost(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
  func_020f4754((undefined4 *)(uintptr_t)(param_2),1);
  uVar2 = uRam020f50b0;
  uVar1 = param_1 + 0xcU & 3;
  uVar3 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  *(undefined4 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x204) = 1;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar1 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 8;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if ((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) == 5) {
    func_020fe958(3);
    return;
  }
  return;
}

