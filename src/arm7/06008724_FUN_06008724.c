/* Decompiled C draft; module arm7; ROM address 06008724. No matching claim. */
#include "types.h"
#include "deps/06008724_FUN_06008724.h"

int FUN_06008724(void)

{
  return (*(uint *)(DAT_06008734 & 0xfffffffc) >> (DAT_06008734 & 3) * 8 |
         *(uint *)(DAT_06008734 & 0xfffffffc) << (DAT_06008734 & 3) * -8 + 0x20) + 0x18;
}

