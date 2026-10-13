/* Decompiled C draft; module arm9; ROM address 02037a20. No matching claim. */
#include "types.h"
#include "deps/02037a20_func_02037a20.h"

bool func_02037a20(void)

{
  return (*(byte *)((*(uint *)(uRam02037a3c & 0xfffffffc) >> (uRam02037a3c & 3) * 8 |
                    *(uint *)(uRam02037a3c & 0xfffffffc) << (uRam02037a3c & 3) * -8 + 0x20) + 0xd8)
         & 2) != 0;
}

