/* Decompiled C draft; module arm9; ROM address 020d95c0. No matching claim. */
#include "types.h"
#include "deps/020d95c0_func_020d95c0.h"

void func_020d95c0(uint param_1,uint *param_2,int param_3,int param_4,int param_5,int param_6)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  lVar2 = (longlong)
          (int)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
               *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) * (longlong)param_3;
  *param_2 = (uint)lVar2 >> 0x18 | (int)((ulonglong)lVar2 >> 0x20) << 8;
  uVar1 = param_1 + 4 & 3;
  uVar4 = *(uint *)(param_1 + 4 & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) * (longlong)param_3;
  param_2[1] = (uint)lVar2 >> 0x18 | (int)((ulonglong)lVar2 >> 0x20) << 8;
  uVar1 = param_1 + 8 & 3;
  uVar4 = *(uint *)(param_1 + 8 & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) * (longlong)param_3;
  param_2[2] = (uint)lVar2 >> 0x18 | (int)((ulonglong)lVar2 >> 0x20) << 8;
  uVar1 = param_1 + 0xc & 3;
  uVar4 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) * (longlong)param_4;
  *param_2 = (*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
             *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) +
             ((uint)lVar2 >> 0x18 | (int)((ulonglong)lVar2 >> 0x20) << 8);
  uVar1 = param_1 + 0x10 & 3;
  uVar3 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
  uVar4 = (uint)(param_2 + 1) & 3;
  uVar5 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * (longlong)param_4;
  param_2[1] = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) +
               ((uint)lVar2 >> 0x18 | (int)((ulonglong)lVar2 >> 0x20) << 8);
  uVar1 = param_1 + 0x14 & 3;
  uVar3 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
  uVar4 = (uint)(param_2 + 2) & 3;
  uVar5 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * (longlong)param_4;
  param_2[2] = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) +
               ((uint)lVar2 >> 0x18 | (int)((ulonglong)lVar2 >> 0x20) << 8);
  uVar1 = param_1 + 0x18 & 3;
  uVar4 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) * (longlong)param_5;
  *param_2 = (*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
             *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) +
             ((uint)lVar2 >> 0x18 | (int)((ulonglong)lVar2 >> 0x20) << 8);
  uVar1 = param_1 + 0x1c & 3;
  uVar3 = *(uint *)(param_1 + 0x1c & 0xfffffffc);
  uVar4 = (uint)(param_2 + 1) & 3;
  uVar5 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * (longlong)param_5;
  param_2[1] = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) +
               ((uint)lVar2 >> 0x18 | (int)((ulonglong)lVar2 >> 0x20) << 8);
  uVar1 = param_1 + 0x20 & 3;
  uVar3 = *(uint *)(param_1 + 0x20 & 0xfffffffc);
  uVar4 = (uint)(param_2 + 2) & 3;
  uVar5 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * (longlong)param_5;
  param_2[2] = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) +
               ((uint)lVar2 >> 0x18 | (int)((ulonglong)lVar2 >> 0x20) << 8);
  uVar1 = param_1 + 0x24 & 3;
  uVar4 = *(uint *)(param_1 + 0x24 & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) * (longlong)param_6;
  *param_2 = (*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
             *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) +
             ((uint)lVar2 >> 0x18 | (int)((ulonglong)lVar2 >> 0x20) << 8);
  uVar1 = param_1 + 0x28 & 3;
  uVar3 = *(uint *)(param_1 + 0x28 & 0xfffffffc);
  uVar4 = (uint)(param_2 + 1) & 3;
  uVar5 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * (longlong)param_6;
  param_2[1] = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) +
               ((uint)lVar2 >> 0x18 | (int)((ulonglong)lVar2 >> 0x20) << 8);
  uVar1 = param_1 + 0x2c & 3;
  uVar3 = *(uint *)(param_1 + 0x2c & 0xfffffffc);
  uVar4 = (uint)(param_2 + 2) & 3;
  uVar5 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * (longlong)param_6;
  param_2[2] = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) +
               ((uint)lVar2 >> 0x18 | (int)((ulonglong)lVar2 >> 0x20) << 8);
  return;
}

