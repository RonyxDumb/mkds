/* Decompiled C draft; module arm9; ROM address 020fa0b8. No matching claim. */
#include "types.h"
#include "deps/020fa0b8_func_020fa0b8.h"

undefined4 func_020fa0b8(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 0x70U & 3;
  uVar1 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if ((int)uVar2 < param_2) {
    *(uint *)(param_1 + 0x70) = uVar2 + param_3;
    uVar2 = param_1 + 0x70U & 3;
    uVar1 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
    if (param_2 < (int)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20)) {
      *(int *)(param_1 + 0x70) = param_2;
    }
    return 1;
  }
  return 0;
}

