/* Decompiled C draft; module arm9; ROM address 021213a0. No matching claim. */
#include "types.h"
#include "deps/021213a0_func_021213a0.h"

undefined4 func_021213a0(void)

{
  int iVar1;
  
  iVar1 = func_0x021a2c64();
  if ((iVar1 != 0) &&
     (*(short *)((*(uint *)(uRam021213e4 & 0xfffffffc) >> (uRam021213e4 & 3) * 8 |
                 *(uint *)(uRam021213e4 & 0xfffffffc) << (uRam021213e4 & 3) * -8 + 0x20) + 0x16) ==
      3)) {
    return 1;
  }
  return 0;
}

