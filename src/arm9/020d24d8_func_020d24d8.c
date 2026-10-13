/* Decompiled C draft; module arm9; ROM address 020d24d8. No matching claim. */
#include "types.h"
#include "deps/020d24d8_func_020d24d8.h"

void func_020d24d8(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = uRam020d2520;
  *(undefined4 *)(param_1 + 0x6c) = param_2;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0xc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 3) {
    *(undefined4 *)(param_1 + 0x6c) = uRam020d2524;
    return;
  }
  uVar2 = (*(uint *)(uRam020d2528 & 0xfffffffc) >> (uRam020d2528 & 3) * 8 |
          *(uint *)(uRam020d2528 & 0xfffffffc) << (uRam020d2528 & 3) * -8 + 0x20) + 0x18;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if (uVar2 != 0) {
    uVar1 = param_1 + 0x6cU & 3;
    uVar3 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
    if ((int)uVar2 < (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) {
      *(uint *)(param_1 + 0x6c) = uVar2;
    }
    return;
  }
  return;
}

