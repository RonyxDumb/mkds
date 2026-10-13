/* Decompiled C draft; module arm9; ROM address 020fcb9c. No matching claim. */
#include "types.h"
#include "deps/020fcb9c_func_020fcb9c.h"

void func_020fcb9c(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x228) =
       param_2 * 0x210 +
       (*(uint *)(uRam020fcbb4 & 0xfffffffc) >> (uRam020fcbb4 & 3) * 8 |
       *(uint *)(uRam020fcbb4 & 0xfffffffc) << (uRam020fcbb4 & 3) * -8 + 0x20);
  return;
}

