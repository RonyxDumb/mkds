/* Decompiled C draft; module arm9_ov001; ROM address 021854d8. No matching claim. */
#include "types.h"
#include "deps/021854d8_FUN_021854d8.h"

void FUN_021854d8(int param_1)

{
  *DAT_021854f0 =
       (*(uint *)((uint)DAT_021854f0 & 0xfffffffc) >> ((uint)DAT_021854f0 & 3) * 8 |
       *(uint *)((uint)DAT_021854f0 & 0xfffffffc) << ((uint)DAT_021854f0 & 3) * -8 + 0x20) &
       0xffffe0ff | param_1 << 8;
  return;
}

