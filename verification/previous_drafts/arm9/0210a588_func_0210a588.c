/* Decompiled C draft; module arm9; ROM address 0210a588. No matching claim. */
#include "types.h"
#include "deps/0210a588_func_0210a588.h"

uint func_0210a588(void)

{
  return *(uint *)(uRam0210a594 & 0xfffffffc) >> (uRam0210a594 & 3) * 8 |
         *(uint *)(uRam0210a594 & 0xfffffffc) << (uRam0210a594 & 3) * -8 + 0x20;
}

