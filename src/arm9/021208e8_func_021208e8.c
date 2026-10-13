/* Decompiled C draft; module arm9; ROM address 021208e8. No matching claim. */
#include "types.h"
#include "deps/021208e8_func_021208e8.h"

void func_021208e8(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = uRam02120930;
  *(undefined4 *)
   ((*(uint *)(uRam02120930 & 0xfffffffc) >> (uRam02120930 & 3) * 8 |
    *(uint *)(uRam02120930 & 0xfffffffc) << (uRam02120930 & 3) * -8 + 0x20) + 8000) = param_1;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 8000;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 2) {
    func_0x021a2ccc();
    func_0x0219bbfc();
    return;
  }
  return;
}

