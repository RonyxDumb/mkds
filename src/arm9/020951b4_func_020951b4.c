/* Decompiled C draft; module arm9; ROM address 020951b4. No matching claim. */
#include "types.h"
#include "deps/020951b4_func_020951b4.h"

uint func_020951b4(int *param_1)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar8;
  uint uVar9;
  uint uVar11;
  uint uVar7;
  uint uVar10;
  
  uVar1 = (uint)(param_1 + 2) & 3;
  uVar6 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  uVar7 = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
  uVar5 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  uVar1 = (uint)(param_1 + 1) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  lVar3 = (ulonglong)uVar5 * (ulonglong)uVar7;
  uVar11 = (uint)lVar3;
  uVar6 = (uint)(param_1 + 3) & 3;
  uVar8 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
  uVar2 = (uint)(param_1 + 4) & 3;
  uVar9 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
  uVar10 = uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20;
  uVar2 = (uint)(param_1 + 5) & 3;
  uVar9 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
  *param_1 = uVar10 + uVar11;
  param_1[1] = (uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20) +
               (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) * uVar5 +
               uVar7 * (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) +
               (int)((ulonglong)lVar3 >> 0x20) + (uint)CARRY4(uVar10,uVar11);
  uVar1 = (uint)(param_1 + 1) & 3;
  uVar6 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  return (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) >> 0x10;
}

