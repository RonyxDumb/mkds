/* Decompiled C draft; module arm9; ROM address 0214733c. No matching claim. */
#include "types.h"
#include "deps/0214733c_MTX_Concat43.h"

void MTX_Concat43(uint param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  longlong lVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar8;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uStack_50;
  uint uStack_4c;
  uint uStack_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  uint uStack_24;
  uint uVar7;
  uint uVar9;
  
  uVar1 = param_1 + 4 & 3;
  uVar8 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar9 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  uVar1 = (uint)(param_2 + 3) & 3;
  uVar4 = *(uint *)((uint)(param_2 + 3) & 0xfffffffc);
  uVar10 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
           *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar8 = param_1 + 8 & 3;
  uVar6 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar7 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
  uVar8 = (uint)(param_2 + 6) & 3;
  uVar6 = *(uint *)((uint)(param_2 + 6) & 0xfffffffc);
  puVar3 = param_3;
  if (param_3 == param_2) {
    puVar3 = &uStack_50;
  }
  lVar2 = (longlong)(int)(uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) * (longlong)(int)uVar7 +
          (longlong)
          (int)(*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
               *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) *
          (longlong)(int)uVar10 +
          (longlong)(int)uVar9 * (longlong)(int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  *puVar3 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = (uint)(param_2 + 4) & 3;
  uVar6 = *(uint *)((uint)(param_2 + 4) & 0xfffffffc);
  uVar8 = (uint)(param_2 + 1) & 3;
  uVar11 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
  uVar4 = (uint)(param_2 + 7) & 3;
  uVar5 = *(uint *)((uint)(param_2 + 7) & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) * (longlong)(int)uVar7 +
          (longlong)(int)(uVar11 >> uVar8 * 8 | uVar11 << uVar8 * -8 + 0x20) * (longlong)(int)uVar10
          + (longlong)(int)uVar9 * (longlong)(int)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
  puVar3[1] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = (uint)(param_2 + 5) & 3;
  uVar8 = *(uint *)((uint)(param_2 + 5) & 0xfffffffc);
  uVar8 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  uVar1 = (uint)(param_2 + 2) & 3;
  uVar4 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
  uVar11 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = (uint)(param_2 + 8) & 3;
  uVar4 = *(uint *)((uint)(param_2 + 8) & 0xfffffffc);
  uVar5 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  lVar2 = (longlong)(int)uVar5 * (longlong)(int)uVar7 +
          (longlong)(int)uVar11 * (longlong)(int)uVar10 +
          (longlong)(int)uVar9 * (longlong)(int)uVar8;
  puVar3[2] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = param_1 + 0x10 & 3;
  uVar4 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
  uVar7 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0xc & 3;
  uVar4 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  uVar9 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x14 & 3;
  uVar4 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
  uVar6 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  lVar2 = (longlong)(int)uVar5 * (longlong)(int)uVar6 +
          (longlong)(int)uVar11 * (longlong)(int)uVar9 + (longlong)(int)uVar7 * (longlong)(int)uVar8
  ;
  puVar3[5] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = (uint)(param_2 + 4) & 3;
  uVar10 = *(uint *)((uint)(param_2 + 4) & 0xfffffffc);
  uVar8 = (uint)(param_2 + 1) & 3;
  uVar11 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
  uVar4 = (uint)(param_2 + 7) & 3;
  uVar5 = *(uint *)((uint)(param_2 + 7) & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) * (longlong)(int)uVar6 +
          (longlong)(int)(uVar11 >> uVar8 * 8 | uVar11 << uVar8 * -8 + 0x20) * (longlong)(int)uVar9
          + (longlong)(int)uVar7 *
            (longlong)(int)(uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20);
  puVar3[4] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = (uint)(param_2 + 3) & 3;
  uVar8 = *(uint *)((uint)(param_2 + 3) & 0xfffffffc);
  uVar10 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  uVar5 = *(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
          *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20;
  uVar1 = (uint)(param_2 + 6) & 3;
  uVar8 = *(uint *)((uint)(param_2 + 6) & 0xfffffffc);
  uVar4 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  lVar2 = (longlong)(int)uVar4 * (longlong)(int)uVar6 +
          (longlong)(int)uVar5 * (longlong)(int)uVar9 + (longlong)(int)uVar7 * (longlong)(int)uVar10
  ;
  puVar3[3] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = param_1 + 0x1c & 3;
  uVar8 = *(uint *)(param_1 + 0x1c & 0xfffffffc);
  uVar7 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x18 & 3;
  uVar8 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
  uVar9 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x20 & 3;
  uVar8 = *(uint *)(param_1 + 0x20 & 0xfffffffc);
  uVar6 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  lVar2 = (longlong)(int)uVar4 * (longlong)(int)uVar6 +
          (longlong)(int)uVar5 * (longlong)(int)uVar9 + (longlong)(int)uVar7 * (longlong)(int)uVar10
  ;
  puVar3[6] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = (uint)(param_2 + 4) & 3;
  uVar10 = *(uint *)((uint)(param_2 + 4) & 0xfffffffc);
  uVar8 = (uint)(param_2 + 1) & 3;
  uVar5 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
  uVar4 = (uint)(param_2 + 7) & 3;
  uVar11 = *(uint *)((uint)(param_2 + 7) & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) * (longlong)(int)uVar6
          + (longlong)(int)(uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) * (longlong)(int)uVar9
            + (longlong)(int)uVar7 *
              (longlong)(int)(uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20);
  puVar3[7] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = (uint)(param_2 + 5) & 3;
  uVar8 = *(uint *)((uint)(param_2 + 5) & 0xfffffffc);
  uVar11 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  uVar1 = (uint)(param_2 + 2) & 3;
  uVar8 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
  uVar5 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  uVar1 = (uint)(param_2 + 8) & 3;
  uVar8 = *(uint *)((uint)(param_2 + 8) & 0xfffffffc);
  uVar4 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  lVar2 = (longlong)(int)uVar4 * (longlong)(int)uVar6 +
          (longlong)(int)uVar5 * (longlong)(int)uVar9 + (longlong)(int)uVar7 * (longlong)(int)uVar11
  ;
  puVar3[8] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = param_1 + 0x28 & 3;
  uVar8 = *(uint *)(param_1 + 0x28 & 0xfffffffc);
  uVar10 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x24 & 3;
  uVar8 = *(uint *)(param_1 + 0x24 & 0xfffffffc);
  uVar9 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x2c & 3;
  uVar8 = *(uint *)(param_1 + 0x2c & 0xfffffffc);
  uVar7 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  uVar1 = (uint)(param_2 + 0xb) & 3;
  uVar8 = *(uint *)((uint)(param_2 + 0xb) & 0xfffffffc);
  lVar2 = (longlong)(int)uVar4 * (longlong)(int)uVar7 +
          (longlong)(int)uVar5 * (longlong)(int)uVar9 +
          (longlong)(int)uVar10 * (longlong)(int)uVar11;
  puVar3[0xb] = (uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) +
                ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
  uVar1 = (uint)(param_2 + 4) & 3;
  uVar5 = *(uint *)((uint)(param_2 + 4) & 0xfffffffc);
  uVar8 = (uint)(param_2 + 1) & 3;
  uVar11 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
  uVar4 = (uint)(param_2 + 7) & 3;
  uVar12 = *(uint *)((uint)(param_2 + 7) & 0xfffffffc);
  uVar6 = (uint)(param_2 + 10) & 3;
  uVar13 = *(uint *)((uint)(param_2 + 10) & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) * (longlong)(int)uVar7
          + (longlong)(int)(uVar11 >> uVar8 * 8 | uVar11 << uVar8 * -8 + 0x20) *
            (longlong)(int)uVar9 +
            (longlong)(int)uVar10 * (longlong)(int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20)
  ;
  puVar3[10] = (uVar13 >> uVar6 * 8 | uVar13 << uVar6 * -8 + 0x20) +
               ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
  uVar1 = (uint)(param_2 + 9) & 3;
  uVar11 = *(uint *)((uint)(param_2 + 9) & 0xfffffffc);
  uVar8 = (uint)(param_2 + 6) & 3;
  uVar5 = *(uint *)((uint)(param_2 + 6) & 0xfffffffc);
  uVar4 = (uint)(param_2 + 3) & 3;
  uVar6 = *(uint *)((uint)(param_2 + 3) & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) * (longlong)(int)uVar7 +
          (longlong)
          (int)(*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
               *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) *
          (longlong)(int)uVar9 +
          (longlong)(int)uVar10 * (longlong)(int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20);
  puVar3[9] = (uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20) +
              ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
  if (puVar3 == &uStack_50) {
    *param_3 = uStack_50;
    param_3[1] = uStack_4c;
    param_3[2] = uStack_48;
    param_3[3] = uStack_44;
    param_3[4] = uStack_40;
    param_3[5] = uStack_3c;
    param_3[6] = uStack_38;
    param_3[7] = uStack_34;
    param_3[8] = uStack_30;
    param_3[9] = uStack_2c;
    param_3[10] = uStack_28;
    param_3[0xb] = uStack_24;
    return;
  }
  return;
}

