/* Decompiled C draft; module arm9; ROM address 02011c58. No matching claim. */
#include "types.h"
#include "deps/02011c58_func_02011c58.h"

void func_02011c58(int *param_1)

{
  longlong lVar1;
  byte bVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  byte *pbVar11;
  uint uVar12;
  uint unaff_r5;
  uint uVar13;
  uint uVar15;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  uint uVar14;
  
  uVar13 = (uint)(param_1 + 1) & 3;
  uVar6 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  pbVar11 = (byte *)(*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                    *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20);
  uVar13 = (uVar6 >> uVar13 * 8 | uVar6 << uVar13 * -8 + 0x20) + 4;
  uVar6 = uVar13 & 3;
  uVar13 = *(uint *)(uVar13 & 0xfffffffc);
  uVar14 = uVar13 >> uVar6 * 8 | uVar13 << uVar6 * -8 + 0x20;
  uVar4 = (uint)pbVar11[2];
  uVar13 = uVar14 + 0x10;
  uVar6 = uVar13 & 3;
  uVar8 = *(uint *)(uVar13 & 0xfffffffc);
  uVar13 = 0;
  iVar9 = uVar14 + (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20);
  Mem_CpuFastMemorySet(0,&local_78,0x54);
  func_01ff9234();
  uVar6 = 0;
  *puRam020122b4 = 0;
  puVar3 = puRam020122bc;
  *puRam020122b8 = 1;
  *puVar3 = 0;
  *puRam020122b4 = 2;
  if (uVar4 != 0) {
    do {
      uVar12 = (uint)pbVar11[4];
      bVar2 = pbVar11[4] >> 5;
      uVar8 = 1 << (uVar12 & 0x1f);
      uVar14 = (uint)(param_1 + bVar2 + 0x33) & 3;
      uVar15 = *(uint *)((uint)(param_1 + bVar2 + 0x33) & 0xfffffffc);
      uVar15 = uVar8 & (uVar15 >> uVar14 * 8 | uVar15 << uVar14 * -8 + 0x20);
      uVar14 = iRam020122c0 + uVar12 * 100;
      if (uVar15 == 0) {
        uVar7 = (uint)(param_1 + bVar2 + 0x33) & 3;
        uVar10 = *(uint *)((uint)(param_1 + bVar2 + 0x33) & 0xfffffffc);
        param_1[bVar2 + 0x33] = uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20 | uVar8;
        *puRam020122c4 = (uint)pbVar11[3];
        *puRam020122b4 = 1;
        G3_MultMtx43(uVar12 * 0x54 + iVar9);
      }
      if (uVar6 != 0) {
        uVar8 = *(uint *)(unaff_r5 & 0xfffffffc) >> (unaff_r5 & 3) * 8 |
                *(uint *)(unaff_r5 & 0xfffffffc) << (unaff_r5 & 3) * -8 + 0x20;
        lVar1 = (ulonglong)uVar8 * (ulonglong)uVar13;
        local_48 = local_48 +
                   ((uint)lVar1 >> 0xc |
                   (uVar13 * ((int)uVar8 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
        uVar8 = unaff_r5 + 4 & 3;
        uVar7 = *(uint *)(unaff_r5 + 4 & 0xfffffffc);
        uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
        lVar1 = (ulonglong)uVar8 * (ulonglong)uVar13;
        local_44 = local_44 +
                   ((uint)lVar1 >> 0xc |
                   (uVar13 * ((int)uVar8 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
        uVar8 = unaff_r5 + 8 & 3;
        uVar7 = *(uint *)(unaff_r5 + 8 & 0xfffffffc);
        uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
        lVar1 = (ulonglong)uVar8 * (ulonglong)uVar13;
        local_40 = local_40 +
                   ((uint)lVar1 >> 0xc |
                   (uVar13 * ((int)uVar8 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
        uVar8 = unaff_r5 + 0xc & 3;
        uVar7 = *(uint *)(unaff_r5 + 0xc & 0xfffffffc);
        uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
        lVar1 = (ulonglong)uVar8 * (ulonglong)uVar13;
        local_3c = local_3c +
                   ((uint)lVar1 >> 0xc |
                   (uVar13 * ((int)uVar8 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
        uVar8 = unaff_r5 + 0x10 & 3;
        uVar7 = *(uint *)(unaff_r5 + 0x10 & 0xfffffffc);
        uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
        lVar1 = (ulonglong)uVar8 * (ulonglong)uVar13;
        local_38 = local_38 +
                   ((uint)lVar1 >> 0xc |
                   (uVar13 * ((int)uVar8 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
        uVar8 = unaff_r5 + 0x14 & 3;
        uVar7 = *(uint *)(unaff_r5 + 0x14 & 0xfffffffc);
        uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
        lVar1 = (ulonglong)uVar8 * (ulonglong)uVar13;
        local_34 = local_34 +
                   ((uint)lVar1 >> 0xc |
                   (uVar13 * ((int)uVar8 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
        uVar8 = unaff_r5 + 0x18 & 3;
        uVar7 = *(uint *)(unaff_r5 + 0x18 & 0xfffffffc);
        uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
        lVar1 = (ulonglong)uVar8 * (ulonglong)uVar13;
        local_30 = local_30 +
                   ((uint)lVar1 >> 0xc |
                   (uVar13 * ((int)uVar8 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
        uVar8 = unaff_r5 + 0x1c & 3;
        uVar7 = *(uint *)(unaff_r5 + 0x1c & 0xfffffffc);
        uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
        lVar1 = (ulonglong)uVar8 * (ulonglong)uVar13;
        local_2c = local_2c +
                   ((uint)lVar1 >> 0xc |
                   (uVar13 * ((int)uVar8 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
        uVar8 = unaff_r5 + 0x20 & 3;
        uVar7 = *(uint *)(unaff_r5 + 0x20 & 0xfffffffc);
        uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
        lVar1 = (ulonglong)uVar8 * (ulonglong)uVar13;
        local_28 = local_28 +
                   ((uint)lVar1 >> 0xc |
                   (uVar13 * ((int)uVar8 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
      }
      if (uVar15 == 0) {
        do {
          iVar5 = G3X_GetClipMtx(uVar14);
        } while (iVar5 != 0);
        *puRam020122b4 = 2;
        G3_MultMtx33(uVar12 * 0x54 + iVar9 + 0x30);
      }
      unaff_r5 = iRam020122c8 + uVar12 * 100;
      uVar13 = (uint)pbVar11[5] << 4;
      lVar1 = (longlong)(int)uVar13 *
              (longlong)
              (int)(*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                   *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20);
      local_78 = local_78 + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
      uVar8 = uVar14 + 4 & 3;
      uVar12 = *(uint *)(uVar14 + 4 & 0xfffffffc);
      lVar1 = (longlong)(int)uVar13 *
              (longlong)(int)(uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20);
      local_74 = local_74 + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
      uVar8 = uVar14 + 8 & 3;
      uVar12 = *(uint *)(uVar14 + 8 & 0xfffffffc);
      lVar1 = (longlong)(int)uVar13 *
              (longlong)(int)(uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20);
      local_70 = local_70 + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
      uVar8 = uVar14 + 0x10 & 3;
      uVar12 = *(uint *)(uVar14 + 0x10 & 0xfffffffc);
      lVar1 = (longlong)(int)uVar13 *
              (longlong)(int)(uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20);
      local_6c = local_6c + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
      uVar8 = uVar14 + 0x14 & 3;
      uVar12 = *(uint *)(uVar14 + 0x14 & 0xfffffffc);
      lVar1 = (longlong)(int)uVar13 *
              (longlong)(int)(uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20);
      local_68 = local_68 + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
      uVar8 = uVar14 + 0x18 & 3;
      uVar12 = *(uint *)(uVar14 + 0x18 & 0xfffffffc);
      lVar1 = (longlong)(int)uVar13 *
              (longlong)(int)(uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20);
      local_64 = local_64 + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
      uVar8 = uVar14 + 0x20 & 3;
      uVar12 = *(uint *)(uVar14 + 0x20 & 0xfffffffc);
      lVar1 = (longlong)(int)uVar13 *
              (longlong)(int)(uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20);
      local_60 = local_60 + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
      uVar8 = uVar14 + 0x24 & 3;
      uVar12 = *(uint *)(uVar14 + 0x24 & 0xfffffffc);
      lVar1 = (longlong)(int)uVar13 *
              (longlong)(int)(uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20);
      local_5c = local_5c + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
      uVar8 = uVar14 + 0x28 & 3;
      uVar12 = *(uint *)(uVar14 + 0x28 & 0xfffffffc);
      lVar1 = (longlong)(int)uVar13 *
              (longlong)(int)(uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20);
      local_58 = local_58 + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
      uVar8 = uVar14 + 0x30 & 3;
      uVar12 = *(uint *)(uVar14 + 0x30 & 0xfffffffc);
      lVar1 = (longlong)(int)uVar13 *
              (longlong)(int)(uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20);
      local_54 = local_54 + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
      uVar8 = uVar14 + 0x34 & 3;
      uVar12 = *(uint *)(uVar14 + 0x34 & 0xfffffffc);
      lVar1 = (longlong)(int)uVar13 *
              (longlong)(int)(uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20);
      local_50 = local_50 + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
      uVar8 = uVar14 + 0x38 & 3;
      uVar14 = *(uint *)(uVar14 + 0x38 & 0xfffffffc);
      lVar1 = (longlong)(int)uVar13 *
              (longlong)(int)(uVar14 >> uVar8 * 8 | uVar14 << uVar8 * -8 + 0x20);
      local_4c = local_4c + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
      if (uVar15 == 0) {
        do {
          iVar5 = G3X_GetVectorMtx(unaff_r5);
        } while (iVar5 != 0);
      }
      uVar6 = uVar6 + 1;
      pbVar11 = pbVar11 + 3;
    } while (uVar6 < uVar4);
  }
  uVar6 = *(uint *)(unaff_r5 & 0xfffffffc) >> (unaff_r5 & 3) * 8 |
          *(uint *)(unaff_r5 & 0xfffffffc) << (unaff_r5 & 3) * -8 + 0x20;
  lVar1 = (ulonglong)uVar6 * (ulonglong)uVar13;
  local_48 = local_48 +
             ((uint)lVar1 >> 0xc |
             (uVar13 * ((int)uVar6 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
  uVar6 = unaff_r5 + 4 & 3;
  uVar4 = *(uint *)(unaff_r5 + 4 & 0xfffffffc);
  uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  lVar1 = (ulonglong)uVar6 * (ulonglong)uVar13;
  local_44 = local_44 +
             ((uint)lVar1 >> 0xc |
             (uVar13 * ((int)uVar6 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
  uVar6 = unaff_r5 + 8 & 3;
  uVar4 = *(uint *)(unaff_r5 + 8 & 0xfffffffc);
  uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  lVar1 = (ulonglong)uVar6 * (ulonglong)uVar13;
  local_40 = local_40 +
             ((uint)lVar1 >> 0xc |
             (uVar13 * ((int)uVar6 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
  uVar6 = unaff_r5 + 0xc & 3;
  uVar4 = *(uint *)(unaff_r5 + 0xc & 0xfffffffc);
  uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  lVar1 = (ulonglong)uVar6 * (ulonglong)uVar13;
  local_3c = local_3c +
             ((uint)lVar1 >> 0xc |
             (uVar13 * ((int)uVar6 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
  uVar6 = unaff_r5 + 0x10 & 3;
  uVar4 = *(uint *)(unaff_r5 + 0x10 & 0xfffffffc);
  uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  lVar1 = (ulonglong)uVar6 * (ulonglong)uVar13;
  local_38 = local_38 +
             ((uint)lVar1 >> 0xc |
             (uVar13 * ((int)uVar6 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
  uVar6 = unaff_r5 + 0x14 & 3;
  uVar4 = *(uint *)(unaff_r5 + 0x14 & 0xfffffffc);
  uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  lVar1 = (ulonglong)uVar6 * (ulonglong)uVar13;
  local_34 = local_34 +
             ((uint)lVar1 >> 0xc |
             (uVar13 * ((int)uVar6 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
  uVar6 = unaff_r5 + 0x18 & 3;
  uVar4 = *(uint *)(unaff_r5 + 0x18 & 0xfffffffc);
  uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  lVar1 = (ulonglong)uVar6 * (ulonglong)uVar13;
  local_30 = local_30 +
             ((uint)lVar1 >> 0xc |
             (uVar13 * ((int)uVar6 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
  uVar6 = unaff_r5 + 0x1c & 3;
  uVar4 = *(uint *)(unaff_r5 + 0x1c & 0xfffffffc);
  uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  lVar1 = (ulonglong)uVar6 * (ulonglong)uVar13;
  local_2c = local_2c +
             ((uint)lVar1 >> 0xc |
             (uVar13 * ((int)uVar6 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
  uVar6 = unaff_r5 + 0x20 & 3;
  uVar4 = *(uint *)(unaff_r5 + 0x20 & 0xfffffffc);
  uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  lVar1 = (ulonglong)uVar6 * (ulonglong)uVar13;
  local_28 = local_28 +
             ((uint)lVar1 >> 0xc |
             (uVar13 * ((int)uVar6 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
  G3_LoadMtx43(&local_48);
  *puRam020122b4 = 1;
  G3_LoadMtx43(&local_78);
  puVar3 = puRam020122b4;
  *puRam020122b4 = 0;
  *puRam020122c4 = 1;
  *puVar3 = 2;
  *puRam020122b8 =
       (uint)*(byte *)((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                       *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 1
                      );
  uVar13 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
           *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  *param_1 = (*(byte *)(uVar13 + 2) + 1) * 3 + uVar13;
  return;
}

