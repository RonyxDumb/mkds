/* Decompiled C draft; module arm7; ROM address 0600aa30. No matching claim. */
#include "types.h"
#include "deps/0600aa30_FUN_0600aa30.h"

void FUN_0600aa30(void)

{
  *DAT_0600aa50 =
       *(undefined2 *)
        ((*(uint *)(DAT_0600aa4c & 0xfffffffc) >> (DAT_0600aa4c & 3) * 8 |
         *(uint *)(DAT_0600aa4c & 0xfffffffc) << (DAT_0600aa4c & 3) * -8 + 0x20) + 0x3ae);
  return;
}

