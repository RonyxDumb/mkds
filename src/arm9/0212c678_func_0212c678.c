/* Decompiled C draft; module arm9; ROM address 0212c678. No matching claim. */
#include "types.h"
#include "deps/0212c678_func_0212c678.h"

void func_0212c678(uint param_1,undefined1 param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (uVar1 != 0) {
    *(undefined1 *)(uVar1 + 0x41) = param_2;
  }
  return;
}

