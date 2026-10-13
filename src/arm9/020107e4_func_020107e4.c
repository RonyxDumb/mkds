/* Decompiled C draft; module arm9; ROM address 020107e4. No matching claim. */
#include "types.h"
#include "deps/020107e4_func_020107e4.h"

uint func_020107e4(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  *(ushort *)(param_1 + 0x32) = *(ushort *)(param_1 + 0x32) & 0xfffe;
  uVar1 = param_1 + 0x2cU & 3;
  uVar2 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

