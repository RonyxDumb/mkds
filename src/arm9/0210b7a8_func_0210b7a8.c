/* Decompiled C draft; module arm9; ROM address 0210b7a8. No matching claim. */
#include "types.h"
#include "deps/0210b7a8_func_0210b7a8.h"

void func_0210b7a8(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (((*(uint *)(uRam0210b7e8 & 0xfffffffc) >> (uRam0210b7e8 & 3) * 8 |
       *(uint *)(uRam0210b7e8 & 0xfffffffc) << (uRam0210b7e8 & 3) * -8 + 0x20) & 1) != 0) {
    uVar1 = param_1 + 4 & 3;
    uVar2 = *(uint *)(param_1 + 4 & 0xfffffffc);
    func_0210bf24(0,*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                    *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20,
                  uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
    return;
  }
  return;
}

