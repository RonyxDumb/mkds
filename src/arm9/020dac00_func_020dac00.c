/* Decompiled C draft; module arm9; ROM address 020dac00. No matching claim. */
#include "types.h"
#include "deps/020dac00_func_020dac00.h"

void func_020dac00(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 + 0xc4U & 3;
  uVar2 = *(uint *)(param_1 + 0xc4U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  lVar1 = (ulonglong)uRam020dac54 * (ulonglong)uVar3;
  *(uint *)(param_1 + 0xc4) =
       (uint)lVar1 >> 0xc |
       (((int)uVar3 >> 0x1f) * uRam020dac54 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  uVar3 = param_1 + 0xc4U & 3;
  uVar2 = *(uint *)(param_1 + 0xc4U & 0xfffffffc);
  uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar3 = uVar2;
  if (0x1800 < (int)uVar2) {
    uVar3 = 3;
  }
  if (0x1800 < (int)uVar2) {
    *(short *)(param_1 + 0x90) = (short)uVar3;
    *(undefined2 *)(param_1 + 0x92) = 1;
  }
  return;
}

