/* Decompiled C draft; module arm9; ROM address 021213f4. No matching claim. */
#include "types.h"
#include "deps/021213f4_func_021213f4.h"

bool func_021213f4(void)

{
  return *(char *)((*(uint *)(uRam02121414 & 0xfffffffc) >> (uRam02121414 & 3) * 8 |
                   *(uint *)(uRam02121414 & 0xfffffffc) << (uRam02121414 & 3) * -8 + 0x20) + 0x194d)
         != '\0';
}

