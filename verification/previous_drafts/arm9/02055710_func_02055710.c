/* Decompiled C draft; module arm9; ROM address 02055710. No matching claim. */
#include "types.h"
#include "deps/02055710_func_02055710.h"

void func_02055710(void)

{
  *(short *)((*(uint *)(uRam02055728 & 0xfffffffc) >> (uRam02055728 & 3) * 8 |
             *(uint *)(uRam02055728 & 0xfffffffc) << (uRam02055728 & 3) * -8 + 0x20) + 0x432) =
       (short)uRam0205572c;
  return;
}

