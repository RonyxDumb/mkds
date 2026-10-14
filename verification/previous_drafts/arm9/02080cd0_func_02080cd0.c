/* Decompiled C draft; module arm9; ROM address 02080cd0. No matching claim. */
#include "types.h"
#include "deps/02080cd0_func_02080cd0.h"

void func_02080cd0(undefined4 *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  
  *param_1 = param_2;
  puVar3 = puRam02080d30;
  uVar7 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 0xc;
  uVar1 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  param_1[1] = uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20;
  param_1[5] = 0;
  param_1[6] = 0;
  uVar5 = puVar3[1];
  uVar8 = puVar3[2];
  param_1[2] = *puVar3;
  param_1[3] = uVar5;
  param_1[4] = uVar8;
  uVar1 = (uint)(param_1 + 1) & 3;
  uVar6 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  uVar7 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 0x18;
  uVar2 = uVar7 & 3;
  uVar4 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + 0x18;
  uVar1 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  VecFx32_Subtract(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20,
                   uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20,param_1 + 2);
  Vector3_MaybeNormalize((uint)(uintptr_t)(param_1 + 2),param_1 + 2);
  return;
}

