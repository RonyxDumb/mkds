/* Decompiled C draft; module arm9; ROM address 020e827c. No matching claim. */
#include "types.h"
#include "deps/020e827c_E7Fn2_7.h"

void E7Fn2_7(void)

{
  uint uVar1;
  uint uVar2;
  
  func_020ea1d4(uRam020e82c8,uRam020e82cc,uRam020e82d0);
  uVar2 = (*(uint *)(uRam020e82d4 & 0xfffffffc) >> (uRam020e82d4 & 3) * 8 |
          *(uint *)(uRam020e82d4 & 0xfffffffc) << (uRam020e82d4 & 3) * -8 + 0x20) + 0x48;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x800) != 0) {
    StateDualHandler_SetState(uRam020e82d8,5);
    return;
  }
  return;
}

