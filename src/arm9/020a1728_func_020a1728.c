/* Decompiled C draft; module arm9; ROM address 020a1728. No matching claim. */
#include "types.h"
#include "deps/020a1728_func_020a1728.h"

void func_020a1728(int param_1)

{
  *(undefined4 *)
   (param_1 * 0x70 +
    (*(uint *)(uRam020a1744 & 0xfffffffc) >> (uRam020a1744 & 3) * 8 |
    *(uint *)(uRam020a1744 & 0xfffffffc) << (uRam020a1744 & 3) * -8 + 0x20) + 8) = 0;
  return;
}

