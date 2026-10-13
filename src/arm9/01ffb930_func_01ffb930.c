/* Decompiled C draft; module arm9; ROM address 01ffb930. No matching claim. */
#include "types.h"
#include "deps/01ffb930_func_01ffb930.h"

void func_01ffb930(int *param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = param_2 + 0x180U & 3;
  uVar2 = *(uint *)(param_2 + 0x180U & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 != 0 || uVar2 << uVar3 * -8 + 0x20 != 0) {
    return;
  }
  uVar3 = param_2 + 0x44U & 3;
  uVar2 = *(uint *)(param_2 + 0x44U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if ((uVar3 & 8) != 0) {
    return;
  }
  if ((uVar3 & 0x10) == 0) {
    return;
  }
  uVar3 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  if (0x3000 < (int)uVar3) {
    uVar2 = param_2 + 0x2d4U & 3;
    uVar4 = *(uint *)(param_2 + 0x2d4U & 0xfffffffc);
    uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
    if ((int)uVar2 < 1) {
      uVar2 = -uVar2;
    }
    lVar1 = (longlong)(int)uVar3 *
            (longlong)
            (int)(*(uint *)(uRam01ffb9c8 & 0xfffffffc) >> (uRam01ffb9c8 & 3) * 8 |
                 *(uint *)(uRam01ffb9c8 & 0xfffffffc) << (uRam01ffb9c8 & 3) * -8 + 0x20);
    lVar1 = (longlong)(int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14) *
            (longlong)(int)uVar2;
    *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) -
               ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    return;
  }
  return;
}

