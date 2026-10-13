/* Decompiled C draft; module arm9; ROM address 020ffd04. No matching claim. */
#include "types.h"
#include "deps/020ffd04_func_020ffd04.h"

void func_020ffd04(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  *(short *)(param_1 + 0xa6) = *(short *)(param_1 + 0xa6) + *(short *)(param_1 + 0xa8);
  uVar3 = (uint)*(ushort *)(param_1 + 0xa2);
  if (uVar3 != 0) {
    uVar2 = param_1 + 0x84U & 3;
    uVar1 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
    uVar1 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    uVar2 = uVar1;
    if (uVar3 < uVar1) {
      uVar2 = 4;
    }
    if (uVar3 < uVar1) {
      *(short *)(param_1 + 0x90) = (short)uVar2;
      *(undefined2 *)(param_1 + 0x92) = 1;
    }
    return;
  }
  return;
}

