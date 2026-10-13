/* Decompiled C draft; module arm9; ROM address 020b3f64. No matching claim. */
#include "types.h"
#include "deps/020b3f64_func_020b3f64.h"

void func_020b3f64(void)

{
  *(undefined4 *)
   ((*(uint *)(uRam020b3f78 & 0xfffffffc) >> (uRam020b3f78 & 3) * 8 |
    *(uint *)(uRam020b3f78 & 0xfffffffc) << (uRam020b3f78 & 3) * -8 + 0x20) + 4) = 1;
  return;
}

