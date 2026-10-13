/* Decompiled C draft; module arm9; ROM address 0213446c. No matching claim. */
#include "types.h"
#include "deps/0213446c_func_0213446c.h"

int func_0213446c(uint param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar1 = param_1 + 0x24 & 3;
  uVar5 = *(uint *)(param_1 + 0x24 & 0xfffffffc);
  uVar4 = param_1 + 0x1c & 3;
  uVar2 = *(uint *)(param_1 + 0x1c & 0xfffffffc);
  iVar3 = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) -
          (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20);
  if (iVar3 != 0) {
    *(int *)(param_1 + 0x28) = iVar3;
    uVar1 = param_1 + 4 & 3;
    uVar4 = *(uint *)(param_1 + 4 & 0xfffffffc);
    if (-1 < (int)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) << 0x13)) {
      uVar1 = param_1 + 0x1c & 3;
      uVar4 = *(uint *)(param_1 + 0x1c & 0xfffffffc);
      func_0213453c(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,param_1 + 0x28);
    }
    uVar1 = param_1 + 0x1c & 3;
    uVar5 = *(uint *)(param_1 + 0x1c & 0xfffffffc);
    uVar4 = param_1 + 0x48 & 3;
    uVar6 = *(uint *)(param_1 + 0x48 & 0xfffffffc);
    uVar2 = param_1 + 0x40 & 3;
    uVar7 = *(uint *)(param_1 + 0x40 & 0xfffffffc);
    iVar3 = (*(code *)(uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20))
                      (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                       *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20,
                       uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20,param_1 + 0x28,
                       uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20);
    if (param_2 != (uint *)0x0) {
      uVar1 = param_1 + 0x28 & 3;
      uVar4 = *(uint *)(param_1 + 0x28 & 0xfffffffc);
      *param_2 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
    }
    if (iVar3 != 0) {
      return iVar3;
    }
    uVar1 = param_1 + 0x18 & 3;
    uVar5 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
    uVar4 = param_1 + 0x28 & 3;
    uVar2 = *(uint *)(param_1 + 0x28 & 0xfffffffc);
    *(uint *)(param_1 + 0x18) =
         (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) +
         (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20);
  }
  func_02134508(param_1);
  return 0;
}

