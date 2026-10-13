/* Decompiled C draft; module arm9; ROM address 020f9320. No matching claim. */
#include "types.h"
#include "deps/020f9320_func_020f9320.h"

void func_020f9320(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0xfcU & 3;
  uVar2 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
  *(uint *)(param_1 + 0xfc) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & ~param_2;
  return;
}

