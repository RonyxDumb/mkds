/* Decompiled C draft; module arm9; ROM address 02073e88. No matching claim. */
#include "types.h"
#include "deps/02073e88_func_02073e88.h"

uint func_02073e88(void)

{
  return *(uint *)(uRam02073e94 & 0xfffffffc) >> (uRam02073e94 & 3) * 8 |
         *(uint *)(uRam02073e94 & 0xfffffffc) << (uRam02073e94 & 3) * -8 + 0x20;
}

