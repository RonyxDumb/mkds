/* Decompiled C draft; module arm9; ROM address 01ff8648. No matching claim. */
#include "types.h"
#include "deps/01ff8648_func_01ff8648.h"

void func_01ff8648(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint unaff_r5;
  
  uVar1 = param_1 + 0x20U & 3;
  uVar4 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  bVar2 = uVar4 >> uVar1 * 8 != 0;
  bVar3 = uVar4 << uVar1 * -8 + 0x20 != 0;
  if (bVar2 || bVar3) {
    unaff_r5 = (uint)*(byte *)(param_1 + 0x91);
  }
  uVar1 = param_1 + 8U & 3;
  uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
  if (!bVar2 && !bVar3) {
    unaff_r5 = 0;
  }
  if (((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0x100) == 0) {
    uVar1 = param_3 + 8U & 3;
    uVar5 = *(uint *)(param_3 + 8U & 0xfffffffc);
    uVar4 = param_3 + 0xcU & 3;
    uVar6 = *(uint *)(param_3 + 0xcU & 0xfffffffc);
    func_01ff9144(param_3 + (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20),
                  uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20);
  }
  if (unaff_r5 == 3) {
    uVar1 = param_1 + 8U & 3;
    uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
    *(uint *)(param_1 + 8) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0xffffffbf;
    uVar1 = param_1 + 0x20U & 3;
    uVar4 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    (*(code *)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20))(param_1);
    return;
  }
  return;
}

