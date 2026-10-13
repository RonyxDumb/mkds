/* Decompiled C draft; module arm9; ROM address 02080d34. No matching claim. */
#include "types.h"
#include "deps/02080d34_func_02080d34.h"

void func_02080d34(uint *param_1,undefined2 param_2)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  puVar2 = puRam02080db8;
  uVar5 = (*(uint *)(uRam02080db4 & 0xfffffffc) >> (uRam02080db4 & 3) * 8 |
          *(uint *)(uRam02080db4 & 0xfffffffc) << (uRam02080db4 & 3) * -8 + 0x20) + 0xa4;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *param_1 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  uVar5 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 0xc;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  param_1[1] = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  uVar5 = puVar2[1];
  uVar6 = puVar2[2];
  param_1[2] = *puVar2;
  param_1[3] = uVar5;
  param_1[4] = uVar6;
  uVar6 = (uint)(param_1 + 1) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  uVar5 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 0x18;
  uVar1 = uVar5 & 3;
  uVar3 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) + 0x18;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  VecFx32_Subtract(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,
                   uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,param_1 + 2);
  Vector3_MaybeNormalize(param_1 + 2,param_1 + 2);
  param_1[5] = 0;
  param_1[6] = 0;
  *(undefined2 *)(param_1 + 7) = param_2;
  *(undefined1 *)((int)param_1 + 0x1e) = 0;
  return;
}

