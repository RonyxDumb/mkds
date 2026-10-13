/* Decompiled C draft; module arm9; ROM address 0203fde0. No matching claim. */
#include "types.h"
#include "deps/0203fde0_func_0203fde0.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

bool func_0203fde0(uint param_1,uint param_2,uint param_3)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  uint unaff_r4;
  uint uVar4;
  uint unaff_r5;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint in_lr;
  uint uVar11;
  bool bVar12;
  uint uVar10;
  
  uVar4 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar5 = param_1 + 8 & 3;
  uVar11 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar11 = uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20;
  uVar7 = *(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
          *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20;
  uVar5 = param_3 + 4 & 3;
  uVar9 = *(uint *)(param_3 + 4 & 0xfffffffc);
  uVar10 = uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20;
  uVar5 = param_2 + 4 & 3;
  uVar9 = *(uint *)(param_2 + 4 & 0xfffffffc);
  lVar1 = (longlong)((int)((uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) - uVar10) >> 4) *
          (longlong)((int)(uVar4 - uVar7) >> 4) + 0x800;
  lVar2 = (longlong)
          ((int)((*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                 *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) - uVar7) >> 4) *
          (longlong)((int)(uVar11 - uVar10) >> 4) + 0x800;
  bVar12 = (int)(((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) -
                ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000)) < 0;
  uVar5 = 0x800;
  if (bVar12) {
    uVar4 = unaff_r4;
    uVar5 = unaff_r5;
    uVar11 = in_lr;
  }
  if (!bVar12) {
    uVar9 = param_2 + 8 & 3;
    uVar7 = *(uint *)(param_2 + 8 & 0xfffffffc);
    uVar8 = uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20;
    uVar9 = param_2 + 0xc & 3;
    uVar7 = *(uint *)(param_2 + 0xc & 0xfffffffc);
    uVar6 = uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20;
    uVar9 = param_3 + 0xc & 3;
    uVar3 = *(uint *)(param_3 + 0xc & 0xfffffffc);
    uVar7 = param_3 + 8 & 3;
    uVar10 = *(uint *)(param_3 + 8 & 0xfffffffc);
    lVar1 = (longlong)((int)((uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20) - uVar6) >> 4) *
            (longlong)((int)(uVar4 - uVar8) >> 4) + (ulonglong)uVar5;
    lVar2 = (longlong)((int)((uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) - uVar8) >> 4) *
            (longlong)((int)(uVar11 - uVar6) >> 4) + (ulonglong)uVar5;
    return -1 < (int)(((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) -
                     ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000));
  }
  return false;
}

