/* Decompiled C draft; module arm9; ROM address 0212c3c8. No matching claim. */
#include "types.h"
#include "deps/0212c3c8_func_0212c3c8.h"

undefined4 func_0212c3c8(uint param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (uVar1 != 0) {
    func_02020d34(*(undefined1 *)(uVar1 + 0x3c));
    return 1;
  }
  return 0;
}

