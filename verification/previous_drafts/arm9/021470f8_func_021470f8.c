/* Decompiled C draft; module arm9; ROM address 021470f8. No matching claim. */
#include "types.h"
#include "deps/021470f8_func_021470f8.h"

void func_021470f8(uint param_1,uint *param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  
  lVar2 = (longlong)param_3 *
          (longlong)
          (int)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
               *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20);
  *param_2 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = param_1 + 4 & 3;
  uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
  lVar2 = (longlong)param_3 * (longlong)(int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  param_2[1] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = param_1 + 8 & 3;
  uVar3 = *(uint *)(param_1 + 8 & 0xfffffffc);
  lVar2 = (longlong)param_3 * (longlong)(int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  param_2[2] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = param_1 + 0xc & 3;
  uVar3 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  lVar2 = (longlong)param_4 * (longlong)(int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  param_2[3] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = param_1 + 0x10 & 3;
  uVar3 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
  lVar2 = (longlong)param_4 * (longlong)(int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  param_2[4] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = param_1 + 0x14 & 3;
  uVar3 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
  lVar2 = (longlong)param_4 * (longlong)(int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  param_2[5] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = param_1 + 0x18 & 3;
  uVar3 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
  lVar2 = (longlong)param_5 * (longlong)(int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  param_2[6] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = param_1 + 0x1c & 3;
  uVar3 = *(uint *)(param_1 + 0x1c & 0xfffffffc);
  lVar2 = (longlong)param_5 * (longlong)(int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  param_2[7] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = param_1 + 0x20 & 3;
  uVar3 = *(uint *)(param_1 + 0x20 & 0xfffffffc);
  lVar2 = (longlong)param_5 * (longlong)(int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  param_2[8] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  return;
}

