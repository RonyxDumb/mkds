/* Decompiled C draft; module arm9; ROM address 02010ed4. No matching claim. */
#include "types.h"
#include "deps/02010ed4_func_02010ed4.h"

undefined4 func_02010ed4(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = iRam02010f18 + 0xfcU & 3;
  uVar2 = *(uint *)(iRam02010f18 + 0xfcU & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 8) == 0) {
    func_0214755c((uint *)(uintptr_t)(uRam02010f1c),(uint *)(uintptr_t)(uRam02010f20));
    uVar1 = iRam02010f18 + 0xfcU & 3;
    uVar2 = *(uint *)(iRam02010f18 + 0xfcU & 0xfffffffc);
    *(uint *)(iRam02010f18 + 0xfc) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 8;
  }
  return uRam02010f20;
}

