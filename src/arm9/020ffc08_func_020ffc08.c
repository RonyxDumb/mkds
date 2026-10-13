/* Decompiled C draft; module arm9; ROM address 020ffc08. No matching claim. */
#include "types.h"
#include "deps/020ffc08_func_020ffc08.h"

void func_020ffc08(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  *(short *)(param_1 + 0xa6) = *(short *)(param_1 + 0xa6) + 0x96;
  uVar2 = param_1 + 0xbcU & 3;
  uVar1 = *(uint *)(param_1 + 0xbcU & 0xfffffffc);
  *(uint *)(param_1 + 0xbc) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) - 0x96;
  uVar2 = param_1 + 0xbcU & 3;
  uVar1 = *(uint *)(param_1 + 0xbcU & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (-1 < (int)uVar2) {
    return;
  }
  *(short *)(param_1 + 0xa6) = *(short *)(param_1 + 0xa6) + (short)uVar2;
  *(undefined2 *)(param_1 + 0x90) = 1;
  *(undefined2 *)(param_1 + 0x92) = 1;
  return;
}

