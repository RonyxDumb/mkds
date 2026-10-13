/* Decompiled C draft; module arm9; ROM address 0210d0ec. No matching claim. */
#include "types.h"
#include "deps/0210d0ec_func_0210d0ec.h"

void func_0210d0ec(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = uRam0210d11c;
  if (*(uint *)(uRam0210d11c & 0xfffffffc) >> (uRam0210d11c & 3) * 8 != 0 ||
      *(uint *)(uRam0210d11c & 0xfffffffc) << (uRam0210d11c & 3) * -8 + 0x20 != 0) {
    do {
      func_0210c3a8();
      uVar1 = uVar2 & 3;
      uVar3 = *(uint *)(uVar2 & 0xfffffffc);
    } while (uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0);
    return;
  }
  return;
}

