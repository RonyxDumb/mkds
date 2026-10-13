/* Decompiled C draft; module arm9; ROM address 01ffc67c. No matching claim. */
#include "types.h"
#include "deps/01ffc67c_func_01ffc67c.h"

undefined4 func_01ffc67c(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x180U & 3;
  uVar2 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) &&
      (uVar1 = param_1 + 0x48U & 3, uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
      ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & uRam01ffc6b8) == 0)) &&
     (uVar1 = param_1 + 0x7cU & 3, uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc),
     ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & uRam01ffc6bc) == 0)) {
    return 0;
  }
  return 1;
}

