/* Decompiled C draft; module arm7; ROM address 06009678. No matching claim. */
#include "types.h"
#include "deps/06009678_FUN_06009678.h"

void FUN_06009678(undefined2 param_1)

{
  *(undefined2 *)
   ((*(uint *)(DAT_0600968c & 0xfffffffc) >> (DAT_0600968c & 3) * 8 |
    *(uint *)(DAT_0600968c & 0xfffffffc) << (DAT_0600968c & 3) * -8 + 0x20) + 0x5f4) = param_1;
  return;
}

