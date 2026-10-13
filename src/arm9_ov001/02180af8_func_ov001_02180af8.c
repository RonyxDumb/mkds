/* Decompiled C draft; module arm9_ov001; ROM address 02180af8. No matching claim. */
#include "types.h"
#include "deps/02180af8_func_ov001_02180af8.h"

void func_ov001_02180af8(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x18U & 3;
  uVar2 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  (*(code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20))();
  return;
}

