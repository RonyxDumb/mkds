/* Decompiled C draft; module arm9; ROM address 020ed98c. No matching claim. */
#include "types.h"
#include "deps/020ed98c_func_020ed98c.h"

int func_020ed98c(int param_1,undefined4 *param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = param_1 + 0xf4U & 3;
  uVar4 = *(uint *)(param_1 + 0xf4U & 0xfffffffc);
  if ((iRam020eda58 <= (int)(uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20)) &&
     (uVar8 = param_1 + 0x74U & 3, uVar4 = *(uint *)(param_1 + 0x74U & 0xfffffffc),
     ((uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) & 0x80) == 0)) {
    uVar8 = param_1 + 0xd0U & 3;
    uVar4 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
    iVar2 = func_020e6b94(uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20);
    return iVar2;
  }
  uVar3 = param_2[1];
  uVar5 = param_2[2];
  *(undefined4 *)(param_1 + 0xac) = *param_2;
  *(undefined4 *)(param_1 + 0xb0) = uVar3;
  *(undefined4 *)(param_1 + 0xb4) = uVar5;
  Vector3_Cross(param_1 + 0xf0,(uint)(uintptr_t)((undefined4 *)(param_1 + 0xac)),(uint *)(uintptr_t)(param_1 + 0x94));
  uVar8 = param_1 + 0x98U & 3;
  uVar4 = *(uint *)(param_1 + 0x98U & 0xfffffffc);
  uVar6 = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
  uVar8 = param_1 + 0x94U & 3;
  uVar4 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  uVar4 = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
  uVar8 = param_1 + 0x9cU & 3;
  uVar7 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
  uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar8 * (longlong)(int)uVar8 +
          (longlong)(int)uVar4 * (longlong)(int)uVar4 + (longlong)(int)uVar6 * (longlong)(int)uVar6;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    Vector3_MaybeNormalize(param_1 + 0x94,(int *)(uintptr_t)(param_1 + 0x94));
  }
  Vector3_Cross(param_1 + 0xac,param_1 + 0x94,(uint *)(uintptr_t)(param_1 + 0xa0));
  uVar8 = param_1 + 0xd0U & 3;
  uVar4 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
  uVar6 = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
  *(int *)(param_1 + 0xb8) =
       (int)(*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) >> 4;
  uVar8 = uVar6 + 4 & 3;
  uVar4 = *(uint *)(uVar6 + 4 & 0xfffffffc);
  *(int *)(param_1 + 0xbc) = (int)(uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) >> 4;
  uVar8 = uVar6 + 8 & 3;
  uVar4 = *(uint *)(uVar6 + 8 & 0xfffffffc);
  *(int *)(param_1 + 0xc0) = (int)(uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) >> 4;
  return param_1 + 0x94;
}

