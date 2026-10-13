/* Decompiled C draft; module arm9; ROM address 020d3c7c. No matching claim. */
#include "types.h"
#include "deps/020d3c7c_func_020d3c7c.h"

void func_020d3c7c(void)

{
  *(undefined4 *)
   ((*(uint *)(uRam020d3c90 & 0xfffffffc) >> (uRam020d3c90 & 3) * 8 |
    *(uint *)(uRam020d3c90 & 0xfffffffc) << (uRam020d3c90 & 3) * -8 + 0x20) + 0x2b8) = 1;
  return;
}

