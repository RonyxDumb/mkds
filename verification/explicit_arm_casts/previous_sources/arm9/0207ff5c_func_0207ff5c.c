/* Decompiled C draft; module arm9; ROM address 0207ff5c. No matching claim. */
#include "types.h"
#include "deps/0207ff5c_func_0207ff5c.h"

void func_0207ff5c(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  param_1[1] = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  uVar2 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  uVar5 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *param_1 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
  uVar2 = (uint)(param_1 + 1) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  uVar5 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 0x18;
  uVar1 = uVar5 & 3;
  uVar3 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + 0x18;
  uVar2 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  VecFx32_Subtract(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,
                   uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20,param_1 + 2);
  Vector3_MaybeNormalize(param_1 + 2,param_1 + 2);
  return;
}

