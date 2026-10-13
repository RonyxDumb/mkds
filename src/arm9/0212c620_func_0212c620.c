/* Decompiled C draft; module arm9; ROM address 0212c620. No matching claim. */
#include "types.h"
#include "deps/0212c620_func_0212c620.h"

void func_0212c620(uint param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (uVar1 == 0) {
    return;
  }
  if (*(char *)(uVar1 + 0x2c) != '\x02') {
    func_0212f834(uVar1 + 0x1c,param_2 << 8);
    return;
  }
  return;
}

