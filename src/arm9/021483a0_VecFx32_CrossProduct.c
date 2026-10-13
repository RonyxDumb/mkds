/* Decompiled C draft; module arm9; ROM address 021483a0. No matching claim. */
#include "types.h"
#include "deps/021483a0_VecFx32_CrossProduct.h"

void VecFx32_CrossProduct(uint param_1,uint param_2,uint *param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  
  uVar7 = param_2 + 8 & 3;
  uVar15 = *(uint *)(param_2 + 8 & 0xfffffffc);
  uVar16 = uVar15 >> uVar7 * 8 | uVar15 << uVar7 * -8 + 0x20;
  uVar7 = param_1 + 4 & 3;
  uVar15 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar12 = uVar15 >> uVar7 * 8 | uVar15 << uVar7 * -8 + 0x20;
  uVar8 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar7 = param_2 + 4 & 3;
  uVar15 = *(uint *)(param_2 + 4 & 0xfffffffc);
  uVar14 = uVar15 >> uVar7 * 8 | uVar15 << uVar7 * -8 + 0x20;
  uVar7 = param_1 + 8 & 3;
  uVar15 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar7 = uVar15 >> uVar7 * 8 | uVar15 << uVar7 * -8 + 0x20;
  uVar13 = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
           *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
  lVar1 = (longlong)(int)uVar12 * (longlong)(int)uVar16;
  uVar9 = (uint)lVar1;
  lVar2 = (longlong)(int)uVar7 * (longlong)(int)uVar14;
  uVar15 = (uint)lVar2;
  uVar11 = uVar9 - uVar15;
  lVar3 = (longlong)(int)uVar7 * (longlong)(int)uVar13;
  uVar10 = (uint)lVar3;
  lVar4 = (longlong)(int)uVar8 * (longlong)(int)uVar16;
  uVar16 = (uint)lVar4;
  lVar5 = (longlong)(int)uVar8 * (longlong)(int)uVar14;
  uVar7 = (uint)lVar5;
  lVar6 = (longlong)(int)uVar12 * (longlong)(int)uVar13;
  uVar13 = (uint)lVar6;
  uVar12 = uVar10 - uVar16;
  uVar8 = uVar7 - uVar13;
  *param_3 = uVar11 + 0x800 >> 0xc |
             (((int)((ulonglong)lVar1 >> 0x20) -
              ((int)((ulonglong)lVar2 >> 0x20) + (uint)(uVar9 < uVar15))) +
             (uint)(0xfffff7ff < uVar11)) * 0x100000;
  param_3[1] = uVar12 + 0x800 >> 0xc |
               (((int)((ulonglong)lVar3 >> 0x20) -
                ((int)((ulonglong)lVar4 >> 0x20) + (uint)(uVar10 < uVar16))) +
               (uint)(0xfffff7ff < uVar12)) * 0x100000;
  param_3[2] = uVar8 + 0x800 >> 0xc |
               (((int)((ulonglong)lVar5 >> 0x20) -
                ((int)((ulonglong)lVar6 >> 0x20) + (uint)(uVar7 < uVar13))) +
               (uint)(0xfffff7ff < uVar8)) * 0x100000;
  return;
}

