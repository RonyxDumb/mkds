/* Decompiled C draft; module arm9; ROM address 02095f38. No matching claim. */
#include "types.h"
#include "deps/02095f38_func_02095f38.h"

undefined4 func_02095f38(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 0xb0U & 3;
  uVar1 = *(uint *)(param_1 + 0xb0U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if ((uVar2 != 1) && (uVar2 != 4)) {
    return 0;
  }
  return 1;
}

