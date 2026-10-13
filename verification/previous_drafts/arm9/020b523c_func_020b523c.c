/* Decompiled C draft; module arm9; ROM address 020b523c. No matching claim. */
#include "types.h"
#include "deps/020b523c_func_020b523c.h"

int func_020b523c(void)

{
  return (int)*(char *)((*(uint *)(uRam020b524c & 0xfffffffc) >> (uRam020b524c & 3) * 8 |
                        *(uint *)(uRam020b524c & 0xfffffffc) << (uRam020b524c & 3) * -8 + 0x20) +
                       0x57);
}

