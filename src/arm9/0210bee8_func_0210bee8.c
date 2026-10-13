/* Decompiled C draft; module arm9; ROM address 0210bee8. No matching claim. */
#include "types.h"
#include "deps/0210bee8_func_0210bee8.h"

void func_0210bee8(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = iRam0210bf20 + 0x10U & 3;
  uVar2 = *(uint *)(iRam0210bf20 + 0x10U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    func_0210bcf4();
    return;
  }
  return;
}

