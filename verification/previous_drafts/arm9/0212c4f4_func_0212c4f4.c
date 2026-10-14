/* Decompiled C draft; module arm9; ROM address 0212c4f4. No matching claim. */
#include "types.h"
#include "deps/0212c4f4_func_0212c4f4.h"

void func_0212c4f4(uint param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (uVar1 != 0) {
    func_02020cbc(*(undefined1 *)(uVar1 + 0x3c));
    return;
  }
  return;
}

