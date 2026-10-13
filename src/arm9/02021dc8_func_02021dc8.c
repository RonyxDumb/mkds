/* Decompiled C draft; module arm9; ROM address 02021dc8. No matching claim. */
#include "types.h"
#include "deps/02021dc8_func_02021dc8.h"

void func_02021dc8(ushort *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar10;
  uint uVar11;
  uint uVar9;
  
  uVar7 = (uint)(param_1 + 2) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  *(uint *)(param_1 + 2) = (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) + (int)param_1;
  uVar7 = (uint)(param_1 + 4) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
  *(uint *)(param_1 + 4) = (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) + (int)param_1;
  uVar7 = (uint)(param_1 + 6) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
  *(uint *)(param_1 + 6) = (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) + (int)param_1;
  uVar7 = (uint)(param_1 + 2) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  uVar4 = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20;
  uVar2 = (uint)(param_1 + 4) & 3;
  uVar11 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
  uVar1 = (uint)(param_1 + 6) & 3;
  uVar10 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
  uVar7 = 0;
  if (*param_1 != 0) {
    do {
      iVar3 = uVar4 + uVar7 * 0x10;
      uVar6 = iVar3 + 0xcU & 3;
      uVar5 = *(uint *)(iVar3 + 0xcU & 0xfffffffc);
      *(uint *)(iVar3 + 0xc) =
           (uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20) +
           (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
      uVar6 = 0;
      if (*(short *)(uVar4 + uVar7 * 0x10) != 0) {
        do {
          uVar5 = iVar3 + 0xcU & 3;
          uVar8 = *(uint *)(iVar3 + 0xcU & 0xfffffffc);
          uVar9 = uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20;
          uVar5 = uVar9 + uVar6 * 8;
          uVar8 = uVar5 & 3;
          uVar5 = *(uint *)(uVar5 & 0xfffffffc);
          *(uint *)(uVar9 + uVar6 * 8) =
               (uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20) +
               (uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20);
          uVar6 = uVar6 + 1 & 0xffff;
        } while (uVar6 < *(ushort *)(uVar4 + uVar7 * 0x10));
      }
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar7 < *param_1);
    return;
  }
  return;
}

