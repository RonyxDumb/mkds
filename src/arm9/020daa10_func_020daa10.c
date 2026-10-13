/* Decompiled C draft; module arm9; ROM address 020daa10. No matching claim. */
#include "types.h"
#include "deps/020daa10_func_020daa10.h"

void func_020daa10(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = param_1 + 0xc4U & 3;
  uVar2 = *(uint *)(param_1 + 0xc4U & 0xfffffffc);
  uVar4 = param_1 + 200U & 3;
  uVar5 = *(uint *)(param_1 + 200U & 0xfffffffc);
  uVar3 = 0x1000 - (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
  *(uint *)(param_1 + 200) =
       (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) +
       (uVar3 * 0x200 >> 0xc | (((int)uVar3 >> 0x1f) << 9 | uVar3 >> 0x17) << 0x14);
  uVar3 = param_1 + 200U & 3;
  uVar4 = *(uint *)(param_1 + 200U & 0xfffffffc);
  uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  lVar1 = (ulonglong)uRam020daa9c * (ulonglong)uVar3;
  *(uint *)(param_1 + 200) =
       (uint)lVar1 >> 0xc |
       (((int)uVar3 >> 0x1f) * uRam020daa9c + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  uVar3 = param_1 + 0xc4U & 3;
  uVar5 = *(uint *)(param_1 + 0xc4U & 0xfffffffc);
  uVar4 = param_1 + 200U & 3;
  uVar2 = *(uint *)(param_1 + 200U & 0xfffffffc);
  *(uint *)(param_1 + 0xc4) =
       (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) +
       (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20);
  uVar3 = param_1 + 0x84U & 3;
  uVar4 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  if (0x3c < (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20)) {
    *(undefined2 *)(param_1 + 0x90) = 0;
    *(undefined2 *)(param_1 + 0x92) = 1;
  }
  return;
}

