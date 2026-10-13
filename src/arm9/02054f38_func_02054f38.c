/* Decompiled C draft; module arm9; ROM address 02054f38. No matching claim. */
#include "types.h"
#include "deps/02054f38_func_02054f38.h"

void func_02054f38(void)

{
  *(short *)((*(uint *)(uRam02054f50 & 0xfffffffc) >> (uRam02054f50 & 3) * 8 |
             *(uint *)(uRam02054f50 & 0xfffffffc) << (uRam02054f50 & 3) * -8 + 0x20) + 0x432) =
       (short)uRam02054f54;
  return;
}

