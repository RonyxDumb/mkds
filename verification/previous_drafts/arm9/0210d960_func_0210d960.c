/* Decompiled C draft; module arm9; ROM address 0210d960. No matching claim. */
#include "types.h"
#include "deps/0210d960_func_0210d960.h"

uint func_0210d960(void)

{
  return *(uint *)(uRam0210d96c & 0xfffffffc) >> (uRam0210d96c & 3) * 8 |
         *(uint *)(uRam0210d96c & 0xfffffffc) << (uRam0210d96c & 3) * -8 + 0x20;
}

