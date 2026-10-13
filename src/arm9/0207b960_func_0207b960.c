/* Decompiled C draft; module arm9; ROM address 0207b960. No matching claim. */
#include "types.h"
#include "deps/0207b960_func_0207b960.h"

void func_0207b960(int *param_1,uint param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar15;
  uint local_38 [5];
  uint uVar14;
  
  uVar6 = param_2 + 0x30 & 3;
  uVar13 = *(uint *)(param_2 + 0x30 & 0xfffffffc);
  uVar14 = uVar13 >> uVar6 * 8 | uVar13 << uVar6 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar14 * (longlong)(int)uVar14 + 0x800;
  uVar13 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
  lVar1 = (longlong)(int)uVar13 * (longlong)(int)uVar14 + 0x800;
  uVar11 = 0x1000 - uVar14;
  uVar6 = (uint)((ulonglong)uRam0207bc98 * (ulonglong)uVar11);
  iVar15 = 0;
  uVar8 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
  lVar1 = (longlong)(int)uVar11 * (longlong)(int)uVar11 + 0x800;
  lVar1 = (longlong)
          (int)(uVar6 + 0x800 >> 0xc |
               (((int)uVar11 >> 0x1f) * uRam0207bc98 +
                (int)((ulonglong)uRam0207bc98 * (ulonglong)uVar11 >> 0x20) +
               (uint)(0xfffff7ff < uVar6)) * 0x100000) *
          (longlong)(int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) + 0x800;
  uVar7 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
  lVar1 = (ulonglong)uVar8 * 0x3000 + 0x800;
  lVar2 = (ulonglong)uVar13 * 0x6000 + 0x800;
  uVar6 = (((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) -
          ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000)) + 0x4000;
  lVar1 = (ulonglong)uRam0207bc98 * (ulonglong)uVar6;
  uVar11 = (uint)lVar1;
  uVar11 = uVar11 + 0x800 >> 0xc |
           (((int)uVar6 >> 0x1f) * uRam0207bc98 + (int)((ulonglong)lVar1 >> 0x20) +
           (uint)(0xfffff7ff < uVar11)) * 0x100000;
  lVar1 = (ulonglong)(uVar14 + (uVar13 - uVar8)) * 0x3000 + 0x800;
  uVar6 = ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) + 0x1000;
  lVar1 = (ulonglong)uRam0207bc98 * (ulonglong)uVar6;
  uVar13 = (uint)lVar1;
  uVar13 = uVar13 + 0x800 >> 0xc |
           (((int)uVar6 >> 0x1f) * uRam0207bc98 + (int)((ulonglong)lVar1 >> 0x20) +
           (uint)(0xfffff7ff < uVar13)) * 0x100000;
  uVar6 = (uint)((ulonglong)uRam0207bc98 * (ulonglong)uVar8);
  uVar6 = uVar6 + 0x800 >> 0xc |
          (((int)uVar8 >> 0x1f) * uRam0207bc98 +
           (int)((ulonglong)uRam0207bc98 * (ulonglong)uVar8 >> 0x20) + (uint)(0xfffff7ff < uVar6)) *
          0x100000;
  do {
    local_38[iVar15] = param_2;
    iVar15 = iVar15 + 1;
    param_2 = param_2 + 0xc;
  } while (iVar15 < 4);
  lVar1 = (longlong)
          (int)(*(uint *)(local_38[3] & 0xfffffffc) >> (local_38[3] & 3) * 8 |
               *(uint *)(local_38[3] & 0xfffffffc) << (local_38[3] & 3) * -8 + 0x20) *
          (longlong)(int)uVar6 + 0x800;
  lVar2 = (longlong)
          (int)(*(uint *)(local_38[2] & 0xfffffffc) >> (local_38[2] & 3) * 8 |
               *(uint *)(local_38[2] & 0xfffffffc) << (local_38[2] & 3) * -8 + 0x20) *
          (longlong)(int)uVar13 + 0x800;
  lVar3 = (longlong)
          (int)(*(uint *)(local_38[0] & 0xfffffffc) >> (local_38[0] & 3) * 8 |
               *(uint *)(local_38[0] & 0xfffffffc) << (local_38[0] & 3) * -8 + 0x20) *
          (longlong)(int)uVar7 + 0x800;
  lVar4 = (longlong)
          (int)(*(uint *)(local_38[1] & 0xfffffffc) >> (local_38[1] & 3) * 8 |
               *(uint *)(local_38[1] & 0xfffffffc) << (local_38[1] & 3) * -8 + 0x20) *
          (longlong)(int)uVar11 + 0x800;
  *param_1 = ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) +
             ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000) +
             ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) +
             ((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000);
  uVar8 = local_38[3] + 4 & 3;
  uVar5 = *(uint *)(local_38[3] + 4 & 0xfffffffc);
  uVar14 = local_38[0] + 4 & 3;
  uVar9 = *(uint *)(local_38[0] + 4 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) * (longlong)(int)uVar6 +
          0x800;
  uVar8 = local_38[1] + 4 & 3;
  uVar12 = *(uint *)(local_38[1] + 4 & 0xfffffffc);
  uVar5 = local_38[2] + 4 & 3;
  uVar10 = *(uint *)(local_38[2] + 4 & 0xfffffffc);
  lVar3 = (longlong)(int)(uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20) * (longlong)(int)uVar13
          + 0x800;
  lVar2 = (longlong)(int)(uVar9 >> uVar14 * 8 | uVar9 << uVar14 * -8 + 0x20) * (longlong)(int)uVar7
          + 0x800;
  lVar4 = (longlong)(int)(uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20) * (longlong)(int)uVar11
          + 0x800;
  param_1[1] = ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) +
               ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) +
               ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000) +
               ((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000);
  uVar8 = local_38[3] + 8 & 3;
  uVar9 = *(uint *)(local_38[3] + 8 & 0xfffffffc);
  uVar14 = local_38[2] + 8 & 3;
  uVar5 = *(uint *)(local_38[2] + 8 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) * (longlong)(int)uVar6 +
          0x800;
  lVar2 = (longlong)(int)(uVar5 >> uVar14 * 8 | uVar5 << uVar14 * -8 + 0x20) * (longlong)(int)uVar13
          + 0x800;
  uVar6 = local_38[1] + 8 & 3;
  uVar8 = *(uint *)(local_38[1] + 8 & 0xfffffffc);
  uVar13 = local_38[0] + 8 & 3;
  uVar14 = *(uint *)(local_38[0] + 8 & 0xfffffffc);
  lVar4 = (longlong)(int)(uVar14 >> uVar13 * 8 | uVar14 << uVar13 * -8 + 0x20) *
          (longlong)(int)uVar7 + 0x800;
  lVar3 = (longlong)(int)(uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) * (longlong)(int)uVar11 +
          0x800;
  param_1[2] = ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) +
               ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000) +
               ((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000) +
               ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000);
  return;
}

