/* Decompiled C draft; module arm9; ROM address 0207ffa4. No matching claim. */
#include "types.h"
#include "deps/0207ffa4_func_0207ffa4.h"

void func_0207ffa4(uint *param_1,undefined2 param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = puRam02080018[1];
  uVar5 = puRam02080018[2];
  param_1[2] = *puRam02080018;
  param_1[3] = uVar3;
  param_1[4] = uVar5;
  param_1[1] = param_3;
  uVar3 = (uint)(param_1 + 1) & 3;
  uVar5 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  uVar5 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *param_1 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  uVar5 = (uint)(param_1 + 1) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  uVar3 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 0x18;
  uVar1 = uVar3 & 3;
  uVar2 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x18;
  uVar5 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  VecFx32_Subtract(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,
                   uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20,param_1 + 2);
  Vector3_MaybeNormalize(param_1 + 2,param_1 + 2);
  param_1[5] = 0;
  param_1[6] = 0;
  *(undefined2 *)(param_1 + 7) = param_2;
  return;
}

