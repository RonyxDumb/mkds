/* Decompiled C draft; module arm9; ROM address 02091f6c. No matching claim. */
#include "types.h"
#include "deps/02091f6c_func_02091f6c.h"

uint func_02091f6c(int *param_1,uint param_2)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar10;
  uint uVar9;
  uint uVar11;
  
  if (param_2 != 0) {
    uVar3 = (uint)(param_1 + 2) & 3;
    uVar8 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    uVar9 = uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20;
    uVar6 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
            *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
    uVar3 = (uint)(param_1 + 1) & 3;
    uVar4 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    lVar2 = (ulonglong)uVar6 * (ulonglong)uVar9;
    uVar7 = (uint)lVar2;
    uVar8 = (uint)(param_1 + 3) & 3;
    uVar5 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
    uVar1 = (uint)(param_1 + 4) & 3;
    uVar10 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
    uVar11 = uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20;
    uVar1 = (uint)(param_1 + 5) & 3;
    uVar10 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
    *param_1 = uVar11 + uVar7;
    param_1[1] = (uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20) +
                 (uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) * uVar6 +
                 uVar9 * (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) +
                 (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar11,uVar7);
    if (param_2 == 0) {
      uVar3 = (uint)(param_1 + 1) & 3;
      uVar8 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
      uVar3 = uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20;
    }
    else {
      uVar3 = (uint)(param_1 + 1) & 3;
      uVar8 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
      uVar3 = (uint)((ulonglong)param_2 *
                     (ulonglong)(uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) >> 0x20);
    }
    return uVar3;
  }
  return 0;
}

