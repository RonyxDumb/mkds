/* Decompiled C draft; module arm9; ROM address 020de9f8. No matching claim. */
#include "types.h"
#include "deps/020de9f8_func_020de9f8.h"

undefined4 func_020de9f8(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar1 = param_1 + 0xf8U & 3;
  uVar2 = *(uint *)(param_1 + 0xf8U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    return uRam020dea4c;
  }
  uVar1 = param_1 + 0xa8U & 3;
  uVar2 = *(uint *)(param_1 + 0xa8U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    uVar3 = func_020d8828(param_1 + 0x108,param_1 + 4);
    return uVar3;
  }
  return 0;
}

