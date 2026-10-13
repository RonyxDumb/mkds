/* Decompiled C draft; module arm9; ROM address 0206182c. No matching claim. */
#include "types.h"
#include "deps/0206182c_func_0206182c.h"

uint func_0206182c(void)

{
  return *(uint *)(uRam02061838 & 0xfffffffc) >> (uRam02061838 & 3) * 8 |
         *(uint *)(uRam02061838 & 0xfffffffc) << (uRam02061838 & 3) * -8 + 0x20;
}

