/* Decompiled C draft; module arm7; ROM address 0600abf8. No matching claim. */
#include "types.h"
#include "deps/0600abf8_FUN_0600abf8.h"

void FUN_0600abf8(void)

{
  *(undefined2 *)
   ((*(uint *)(DAT_0600ac20 & 0xfffffffc) >> (DAT_0600ac20 & 3) * 8 |
    *(uint *)(DAT_0600ac20 & 0xfffffffc) << (DAT_0600ac20 & 3) * -8 + 0x20) + 0x3ea) = 0;
  *DAT_0600ac24 = *DAT_0600ac24 | 2;
  return;
}

