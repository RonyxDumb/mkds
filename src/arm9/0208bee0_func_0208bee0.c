/* Decompiled C draft; module arm9; ROM address 0208bee0. No matching claim. */
#include "types.h"
#include "deps/0208bee0_func_0208bee0.h"

bool func_0208bee0(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x3cU & 3;
  uVar2 = *(uint *)(param_1 + 0x3cU & 0xfffffffc);
  return uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0;
}

