/* Decompiled C draft; module arm9; ROM address 020f03bc. No matching claim. */
#include "types.h"
#include "deps/020f03bc_func_020f03bc.h"

undefined4 func_020f03bc(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x14U & 3;
  uVar2 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  if (0 < (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) {
    uVar1 = param_1 + 4U & 3;
    uVar2 = *(uint *)(param_1 + 4U & 0xfffffffc);
    uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    func_020f0f70(param_1,uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
    return 1;
  }
  return 0;
}

