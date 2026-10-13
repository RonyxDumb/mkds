/* Decompiled C draft; module arm9; ROM address 0214f54c. No matching claim. */
#include "types.h"
#include "deps/0214f54c_func_0214f54c.h"

void func_0214f54c(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 == (uint *)0x0) {
    return;
  }
  uVar2 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  uVar1 = uVar2;
  if (uVar2 != 0) {
    do {
      if (uVar1 == param_2) {
        if (uVar1 == uVar2) {
          uVar2 = uVar1 + 8 & 3;
          uVar1 = *(uint *)(uVar1 + 8 & 0xfffffffc);
          *param_1 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
        }
        else {
          uVar3 = uVar1 + 8 & 3;
          uVar1 = *(uint *)(uVar1 + 8 & 0xfffffffc);
          *(uint *)(uVar2 + 8) = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
        }
        return;
      }
      uVar2 = uVar1 + 8 & 3;
      uVar3 = *(uint *)(uVar1 + 8 & 0xfffffffc);
      uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
      uVar2 = uVar1;
      uVar1 = uVar3;
    } while (uVar3 != 0);
    return;
  }
  return;
}

