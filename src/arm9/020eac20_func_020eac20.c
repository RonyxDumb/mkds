/* Decompiled C draft; module arm9; ROM address 020eac20. No matching claim. */
#include "types.h"
#include "deps/020eac20_func_020eac20.h"

void func_020eac20(uint *param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar2 = (uint)(param_1 + 1) & 3;
  uVar3 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  lVar1 = (longlong)(int)(uVar3 + 0x1000) * (longlong)param_2;
  uVar2 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  if (0x1000 < (int)uVar2) {
    uVar2 = 0x1000;
  }
  lVar1 = (longlong)(int)uVar2 * (longlong)(int)(0x1000 - uVar2);
  lVar1 = (longlong)(int)(0x1000 - uVar3) *
          (longlong)((int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14) >> 1);
  uVar5 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  iVar6 = (0x1000 - uVar2) + uVar5;
  lVar1 = (longlong)
          (int)(*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) *
          (longlong)iVar6;
  *param_1 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar3 = (uint)(param_1 + 1) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) * (longlong)iVar6;
  param_1[1] = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar3 = (uint)(param_1 + 2) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) * (longlong)iVar6;
  param_1[2] = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar3 = (uint)(param_1 + 1) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  param_1[1] = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + uVar2 + uVar5;
  return;
}

