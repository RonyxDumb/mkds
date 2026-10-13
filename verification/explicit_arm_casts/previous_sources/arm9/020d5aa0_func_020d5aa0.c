/* Decompiled C draft; module arm9; ROM address 020d5aa0. No matching claim. */
#include "types.h"
#include "deps/020d5aa0_func_020d5aa0.h"

void func_020d5aa0(uint param_1,uint param_2,undefined4 *param_3,undefined4 param_4,
                  undefined4 param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (*(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 != 0 ||
      *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20 != 0) {
    if ((param_2 & 0x80000000) != 0) {
      *param_3 = 0;
      return;
    }
    func_020e0538(param_3,param_4);
    uVar3 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
    uVar2 = uVar3 + 4 & 3;
    uVar1 = *(uint *)(uVar3 + 4 & 0xfffffffc);
    if ((uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) &&
       ((*(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
        *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20) ==
        (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
        *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20))) {
      return;
    }
    *param_3 = 0;
    return;
  }
  if ((param_2 & 0x80000000) != 0) {
    return;
  }
  uVar1 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar2 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
  if (uVar2 != 0) {
    uVar3 = uVar1 + 4 & 3;
    uVar1 = *(uint *)(uVar1 + 4 & 0xfffffffc);
    if (uVar1 >> uVar3 * 8 != 0 || uVar1 << uVar3 * -8 + 0x20 != 0) {
      return;
    }
    if ((param_2 & uRam020d5b88) != 0) {
      func_020e0584(uVar2,param_4,param_5,param_3);
      return;
    }
    return;
  }
  return;
}

