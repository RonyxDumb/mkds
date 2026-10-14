/* Decompiled C draft; module arm9; ROM address 02055f68. No matching claim. */
#include "types.h"
#include "deps/02055f68_func_02055f68.h"

void func_02055f68(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(uRam02055fc4 & 0xfffffffc) >> (uRam02055fc4 & 3) * 8 |
          *(uint *)(uRam02055fc4 & 0xfffffffc) << (uRam02055fc4 & 3) * -8 + 0x20;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 == 1) {
    func_02055fc8();
    return;
  }
  if (uVar2 != 2) {
    return;
  }
  ConfigureDispcntDisplay(0xe,0,1);
  return;
}

