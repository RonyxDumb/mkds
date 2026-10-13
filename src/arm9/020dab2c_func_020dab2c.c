/* Decompiled C draft; module arm9; ROM address 020dab2c. No matching claim. */
#include "types.h"
#include "deps/020dab2c_func_020dab2c.h"

void func_020dab2c(int param_1)

{
  uint uVar1;
  uint uVar2;
  short *psVar3;
  
  uVar2 = param_1 + 0xfcU & 3;
  uVar1 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
  if (uVar1 >> uVar2 * 8 != 0 || uVar1 << uVar2 * -8 + 0x20 != 0) {
    uVar2 = param_1 + 0x84U & 3;
    uVar1 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
    uVar1 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    uVar2 = uVar1;
    if (300 < uVar1) {
      uVar2 = 5;
    }
    if (300 < uVar1) {
      *(short *)(param_1 + 0x90) = (short)uVar2;
      *(undefined2 *)(param_1 + 0x92) = 1;
    }
    return;
  }
  psVar3 = (short *)(param_1 + 0x100);
  *psVar3 = *psVar3 + -1;
  if (*psVar3 == 0) {
    func_020d2398();
    return;
  }
  return;
}

