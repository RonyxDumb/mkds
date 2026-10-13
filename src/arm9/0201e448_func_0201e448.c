/* Decompiled C draft; module arm9; ROM address 0201e448. No matching claim. */
#include "types.h"
#include "deps/0201e448_func_0201e448.h"

uint func_0201e448(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  uVar3 = 0;
  if (uVar2 != 0) {
    *param_1 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
               *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
    if (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 == 0 &&
        *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 == 0) {
      *param_1 = 0;
      param_1[2] = 0;
    }
    else {
      *(undefined4 *)
       ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
        *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 4) = 0;
    }
    uVar3 = (uint)(param_1 + 1) & 3;
    uVar1 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    param_1[1] = (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) - 1;
    uVar3 = uVar2;
  }
  return uVar3;
}

