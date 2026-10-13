/* Decompiled C draft; module arm9; ROM address 02010de8. No matching claim. */
#include "types.h"
#include "deps/02010de8_func_02010de8.h"

undefined4 func_02010de8(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = iRam02010e24 + 0xfcU & 3;
  uVar2 = *(uint *)(iRam02010e24 + 0xfcU & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x80) == 0) {
    func_02010e70();
    uVar1 = iRam02010e24 + 0xfcU & 3;
    uVar2 = *(uint *)(iRam02010e24 + 0xfcU & 0xfffffffc);
    *(uint *)(iRam02010e24 + 0xfc) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 0x80;
  }
  return uRam02010e28;
}

