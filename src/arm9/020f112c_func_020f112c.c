/* Decompiled C draft; module arm9; ROM address 020f112c. No matching claim. */
#include "types.h"
#include "deps/020f112c_func_020f112c.h"

void func_020f112c(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x228) =
       param_2 * 0x210 +
       (*(uint *)(uRam020f114c & 0xfffffffc) >> (uRam020f114c & 3) * 8 |
       *(uint *)(uRam020f114c & 0xfffffffc) << (uRam020f114c & 3) * -8 + 0x20);
  *(undefined4 *)(param_1 + 0x238) = 0;
  return;
}

