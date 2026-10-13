/* Decompiled C draft; module arm7; ROM address 0600f118. No matching claim. */
#include "types.h"
#include "deps/0600f118_FUN_0600f118.h"

void FUN_0600f118(void)

{
  *(undefined2 *)
   ((*(uint *)(DAT_0600f130 & 0xfffffffc) >> (DAT_0600f130 & 3) * 8 |
    *(uint *)(DAT_0600f130 & 0xfffffffc) << (DAT_0600f130 & 3) * -8 + 0x20) + 0x428) = 0;
  return;
}

