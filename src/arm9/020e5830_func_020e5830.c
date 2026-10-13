/* Decompiled C draft; module arm9; ROM address 020e5830. No matching claim. */
#include "types.h"
#include "deps/020e5830_func_020e5830.h"

void func_020e5830(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x84U & 3;
  uVar2 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  if ((uint)*(ushort *)(param_1 + 0xc4) < (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) {
    *(undefined2 *)(param_1 + 0x90) = 0;
    *(undefined2 *)(param_1 + 0x92) = 1;
  }
  return;
}

