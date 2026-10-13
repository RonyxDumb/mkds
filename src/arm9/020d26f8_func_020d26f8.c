/* Decompiled C draft; module arm9; ROM address 020d26f8. No matching claim. */
#include "types.h"
#include "deps/020d26f8_func_020d26f8.h"

undefined4 func_020d26f8(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_2 + 0x29cU & 3;
  uVar1 = *(uint *)(param_2 + 0x29cU & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if ((uVar2 != 1) && (uVar2 != 3)) {
    return 0;
  }
  uVar2 = param_1 + 0x94U & 3;
  uVar1 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 == 0) {
    func_020719bc(param_2,0xe8);
  }
  else {
    DriverContext_MaybeQueuePlaySfx(uVar2,0xe8,0x7f,0);
  }
  return 1;
}

