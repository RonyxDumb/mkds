/* Decompiled C draft; module arm9; ROM address 02146f98. No matching claim. */
#include "types.h"
#include "deps/02146f98_func_02146f98.h"

void func_02146f98(int *param_1,uint param_2,int param_3,int param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar8;
  
  uVar9 = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
  uVar5 = param_2 + 4 & 3;
  uVar7 = *(uint *)(param_2 + 4 & 0xfffffffc);
  uVar8 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
  uVar5 = param_2 + 8 & 3;
  uVar7 = *(uint *)(param_2 + 8 & 0xfffffffc);
  uVar6 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
  uVar1 = (longlong)(int)uVar9 * (longlong)(int)uVar9;
  uVar5 = 0x1000 - param_4;
  uVar2 = (longlong)(int)uVar5 * (longlong)(int)uVar9;
  lVar3 = (uVar2 & 0xffffffff) * (ulonglong)uVar8;
  lVar4 = (uVar1 & 0xffffffff) * (ulonglong)uVar5;
  uVar10 = (uint)((longlong)param_3 * (longlong)(int)uVar9) >> 0xc |
           (int)((ulonglong)((longlong)param_3 * (longlong)(int)uVar9) >> 0x20) << 0x14;
  *param_1 = ((uint)lVar4 >> 0x18 |
             (((int)uVar5 >> 0x1f) * (int)uVar1 +
             uVar5 * (int)(uVar1 >> 0x20) + (int)((ulonglong)lVar4 >> 0x20)) * 0x100) + param_4;
  uVar11 = (uint)lVar3 >> 0x18 |
           (((int)uVar8 >> 0x1f) * (int)uVar2 +
           uVar8 * (int)(uVar2 >> 0x20) + (int)((ulonglong)lVar3 >> 0x20)) * 0x100;
  lVar3 = (longlong)(int)uVar8 * (longlong)(int)uVar8 * (longlong)(int)uVar5;
  param_1[4] = ((uint)lVar3 >> 0x18 | (int)((ulonglong)lVar3 >> 0x20) * 0x100) + param_4;
  lVar3 = (longlong)(int)uVar6 * (longlong)(int)uVar6 * (longlong)(int)uVar5;
  param_1[8] = ((uint)lVar3 >> 0x18 | (int)((ulonglong)lVar3 >> 0x20) * 0x100) + param_4;
  uVar9 = (uint)((longlong)param_3 * (longlong)(int)uVar8) >> 0xc |
          (int)((ulonglong)((longlong)param_3 * (longlong)(int)uVar8) >> 0x20) << 0x14;
  uVar7 = (uint)((longlong)param_3 * (longlong)(int)uVar6) >> 0xc |
          (int)((ulonglong)((longlong)param_3 * (longlong)(int)uVar6) >> 0x20) << 0x14;
  param_1[1] = uVar11 + uVar7;
  param_1[3] = uVar11 - uVar7;
  uVar7 = (uint)(uVar2 * (longlong)(int)uVar6) >> 0x18 |
          (int)(uVar2 * (longlong)(int)uVar6 >> 0x20) * 0x100;
  param_1[2] = uVar7 - uVar9;
  param_1[6] = uVar7 + uVar9;
  lVar3 = (longlong)(int)uVar5 * (longlong)(int)uVar8 * (longlong)(int)uVar6;
  uVar5 = (uint)lVar3 >> 0x18 | (int)((ulonglong)lVar3 >> 0x20) * 0x100;
  param_1[5] = uVar5 + uVar10;
  param_1[7] = uVar5 - uVar10;
  return;
}

