/* Decompiled C draft; module arm9; ROM address 020f36a0. No matching claim. */
#include "types.h"
#include "deps/020f36a0_func_020f36a0.h"

void func_020f36a0(uint param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (param_1 < 0xff) {
    uVar2 = (*(uint *)(uRam020f36d4 & 0xfffffffc) >> (uRam020f36d4 & 3) * 8 |
            *(uint *)(uRam020f36d4 & 0xfffffffc) << (uRam020f36d4 & 3) * -8 + 0x20) + 0xb0;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    *param_2 = param_1 * 0x28 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  }
  else {
    *param_2 = 0;
  }
  param_2[1] = 1;
  return;
}

