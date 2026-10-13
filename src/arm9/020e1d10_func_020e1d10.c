/* Decompiled C draft; module arm9; ROM address 020e1d10. No matching claim. */
#include "types.h"
#include "deps/020e1d10_func_020e1d10.h"

undefined4 func_020e1d10(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 + 0x134U & 3;
  uVar2 = *(uint *)(param_1 + 0x134U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 == 0) {
    uVar1 = func_020e0bac();
    return uVar1;
  }
  if (uVar3 != 1) {
    return 0;
  }
  uVar1 = func_020e0764();
  return uVar1;
}

