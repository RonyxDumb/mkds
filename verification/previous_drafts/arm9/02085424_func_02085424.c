/* Decompiled C draft; module arm9; ROM address 02085424. No matching claim. */
#include "types.h"
#include "deps/02085424_func_02085424.h"

uint func_02085424(void)

{
  return *(uint *)(uRam02085430 & 0xfffffffc) >> (uRam02085430 & 3) * 8 |
         *(uint *)(uRam02085430 & 0xfffffffc) << (uRam02085430 & 3) * -8 + 0x20;
}

