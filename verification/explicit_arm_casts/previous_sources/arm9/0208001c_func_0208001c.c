/* Decompiled C draft; module arm9; ROM address 0208001c. No matching claim. */
#include "types.h"
#include "deps/0208001c_func_0208001c.h"

void func_0208001c(undefined4 *param_1,undefined4 param_2)

{
  longlong lVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  
  puVar2 = puRam0208009c;
  param_1[1] = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  *param_1 = param_2;
  uVar4 = puVar2[1];
  uVar7 = puVar2[2];
  param_1[2] = *puVar2;
  param_1[3] = uVar4;
  param_1[4] = uVar7;
  uVar8 = (uint)(param_1 + 1) & 3;
  uVar5 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  uVar6 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 0x20;
  uVar9 = uVar6 & 3;
  uVar3 = *(uint *)(uVar6 & 0xfffffffc);
  uVar6 = (uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) + 0x20;
  uVar8 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  VecFx32_Subtract(uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20,
                   uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20,param_1 + 2);
  uVar6 = (uint)(param_1 + 3) & 3;
  uVar8 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
  uVar9 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
  uVar6 = (uint)(param_1 + 2) & 3;
  uVar8 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  uVar8 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
  uVar6 = (uint)(param_1 + 4) & 3;
  uVar3 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
  uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar6 * (longlong)(int)uVar6 +
          (longlong)(int)uVar8 * (longlong)(int)uVar8 + (longlong)(int)uVar9 * (longlong)(int)uVar9;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    Vector3_MaybeNormalize(param_1 + 2,param_1 + 2);
    return;
  }
  return;
}

