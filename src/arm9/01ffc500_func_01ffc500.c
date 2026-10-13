/* Decompiled C draft; module arm9; ROM address 01ffc500. No matching claim. */
#include "types.h"
#include "deps/01ffc500_func_01ffc500.h"

void func_01ffc500(uint *param_1)

{
  longlong lVar1;
  uint uVar2;
  
  uVar2 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  lVar1 = (ulonglong)uRam01ffc554 * (ulonglong)uVar2;
  *param_1 = (uint)lVar1 >> 0xc |
             (((int)uVar2 >> 0x1f) * uRam01ffc554 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  uVar2 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  if ((int)uVar2 < 1) {
    uVar2 = -uVar2;
  }
  if ((int)uVar2 < 0x7b) {
    *param_1 = 0;
  }
  return;
}

