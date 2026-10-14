/* Decompiled C draft; module arm9; ROM address 020d3e18. No matching claim. */
#include "types.h"
#include "deps/020d3e18_func_020d3e18.h"

bool func_020d3e18(void)

{
  return *(uint *)(uRam020d3e30 & 0xfffffffc) >> (uRam020d3e30 & 3) * 8 != 0 ||
         *(uint *)(uRam020d3e30 & 0xfffffffc) << (uRam020d3e30 & 3) * -8 + 0x20 != 0;
}

