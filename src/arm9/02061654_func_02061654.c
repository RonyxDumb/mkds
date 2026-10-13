/* Decompiled C draft; module arm9; ROM address 02061654. No matching claim. */
#include "types.h"
#include "deps/02061654_func_02061654.h"

uint func_02061654(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
  if ((int)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) << 0x1f) < 0) {
    uVar1 = param_1 + 4U & 3;
    uVar2 = *(uint *)(param_1 + 4U & 0xfffffffc);
    uVar1 = ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) << 0x10) >> 0x1a;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

