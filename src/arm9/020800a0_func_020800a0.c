/* Decompiled C draft; module arm9; ROM address 020800a0. No matching claim. */
#include "types.h"
#include "deps/020800a0_func_020800a0.h"

uint func_020800a0(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x28;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = (uint)*(short *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  if (uVar2 != 0) {
    return (uint)((ulonglong)uRam020800f0 * (ulonglong)uVar2) >> 0xc |
           (((int)uVar2 >> 0x1f) * uRam020800f0 +
           (int)((ulonglong)uRam020800f0 * (ulonglong)uVar2 >> 0x20)) * 0x100000;
  }
  return 0;
}

