/* Decompiled C draft; module arm9_ov001; ROM address 02185490. No matching claim. */
#include "types.h"
#include "deps/02185490_FUN_02185490.h"

void FUN_02185490(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(DAT_021854a0 & 0xfffffffc) >> (DAT_021854a0 & 3) * 8 |
    *(uint *)(DAT_021854a0 & 0xfffffffc) << (DAT_021854a0 & 3) * -8 + 0x20) + 8) = param_1;
  return;
}

