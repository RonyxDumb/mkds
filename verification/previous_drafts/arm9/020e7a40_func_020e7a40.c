/* Decompiled C draft; module arm9; ROM address 020e7a40. No matching claim. */
#include "types.h"
#include "deps/020e7a40_func_020e7a40.h"

void func_020e7a40(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020e7a7c & 0xfffffffc) >> (uRam020e7a7c & 3) * 8 |
          *(uint *)(uRam020e7a7c & 0xfffffffc) << (uRam020e7a7c & 3) * -8 + 0x20) + 0xc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) != 6) {
    StateDualHandler_SetState(uRam020e7a80,4);
    return;
  }
  return;
}

