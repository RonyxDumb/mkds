/* Decompiled C draft; module arm9; ROM address 0201e3c8. No matching claim. */
#include "types.h"
#include "deps/0201e3c8_func_0201e3c8.h"

uint func_0201e3c8(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
  if (uVar3 == 0) {
    if ((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
        *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) == param_2) {
      *param_1 = 0;
      param_1[2] = 0;
    }
    else {
      uVar3 = param_2 + 4 & 3;
      uVar1 = *(uint *)(param_2 + 4 & 0xfffffffc);
      *(undefined4 *)(uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) = 0;
      uVar3 = (uint)(param_1 + 2) & 3;
      uVar1 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
      uVar3 = (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) + 4;
      uVar1 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      param_1[2] = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    }
  }
  else if ((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
           *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) == param_2) {
    *param_1 = uVar3;
    *(undefined4 *)
     ((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
      *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 4) = 0;
  }
  else {
    uVar1 = param_2 + 4 & 3;
    uVar2 = *(uint *)(param_2 + 4 & 0xfffffffc);
    *(uint *)(uVar3 + 4) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    uVar3 = param_2 + 4 & 3;
    uVar1 = *(uint *)(param_2 + 4 & 0xfffffffc);
    *(uint *)(uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) =
         *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
         *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
  }
  uVar3 = (uint)(param_1 + 1) & 3;
  uVar1 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  param_1[1] = (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) - 1;
  return param_2;
}

