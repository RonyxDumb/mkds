/* Decompiled C draft; module arm9; ROM address 020fd754. No matching claim. */
#include "types.h"
#include "deps/020fd754_func_020fd754.h"

void func_020fd754(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xffff7fff;
  uVar1 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x180000) == 0) {
    *(undefined4 *)(param_1 + 0x120) = 0;
  }
  func_020f9c40(param_1);
  *(undefined4 *)(param_1 + 0x1a0) = 0;
  StateDualHandler_SetState(param_1 + 0x184,3);
  *(undefined4 *)(param_1 + 0x174) = 0;
  return;
}

