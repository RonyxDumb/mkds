/* Decompiled C draft; module arm9; ROM address 01ffbe04. No matching claim. */
#include "types.h"
#include "deps/01ffbe04_func_01ffbe04.h"

void func_01ffbe04(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 + 0xccU & 3;
  uVar1 = *(uint *)(param_1 + 0xccU & 0xfffffffc);
  uVar1 = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
  uVar3 = param_1 + 0xd0U & 3;
  uVar2 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if ((int)uVar1 < (int)uVar3) {
    *(uint *)(param_1 + 0xd0) =
         (uint)((ulonglong)uRam01ffbe6c * (ulonglong)uVar3) >> 0xc |
         (((int)uVar3 >> 0x1f) * uRam01ffbe6c +
         (int)((ulonglong)uRam01ffbe6c * (ulonglong)uVar3 >> 0x20)) * 0x100000;
    uVar3 = param_1 + 0xccU & 3;
    uVar1 = *(uint *)(param_1 + 0xccU & 0xfffffffc);
    uVar2 = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
    uVar3 = param_1 + 0xd0U & 3;
    uVar1 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
    if ((int)(uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) < (int)uVar2) {
      *(uint *)(param_1 + 0xd0) = uVar2;
    }
    return;
  }
  *(uint *)(param_1 + 0xd0) = uVar1;
  return;
}

