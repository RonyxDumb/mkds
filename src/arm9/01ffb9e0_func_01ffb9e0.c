/* Decompiled C draft; module arm9; ROM address 01ffb9e0. No matching claim. */
#include "types.h"
#include "deps/01ffb9e0_func_01ffb9e0.h"

void func_01ffb9e0(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if ((((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0x400) != 0) ||
     (uVar4 = param_1 + 0x180U & 3, uVar2 = *(uint *)(param_1 + 0x180U & 0xfffffffc),
     uVar2 >> uVar4 * 8 != 0 || uVar2 << uVar4 * -8 + 0x20 != 0)) {
    uVar4 = param_1 + 0x2ccU & 3;
    uVar3 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
    uVar2 = param_1 + 0x2a8U & 3;
    uVar5 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
    uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x2c;
    uVar3 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) *
            (longlong)(int)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
    *(uint *)(param_1 + 0x2a8) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  }
  uVar4 = param_1 + 0x48U & 3;
  uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if (((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0x2000) != 0) {
    uVar4 = param_1 + 0x2a8U & 3;
    uVar2 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
    uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
    lVar1 = (ulonglong)uRam01ffba64 * (ulonglong)uVar4;
    *(uint *)(param_1 + 0x2a8) =
         (uint)lVar1 >> 0xc |
         (((int)uVar4 >> 0x1f) * uRam01ffba64 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
    return;
  }
  return;
}

