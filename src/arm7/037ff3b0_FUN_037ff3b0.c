/* Decompiled C draft; module arm7; ROM address 037ff3b0. No matching claim. */
#include "types.h"
#include "deps/037ff3b0_FUN_037ff3b0.h"

void FUN_037ff3b0(int param_1,int param_2,undefined2 param_3)

{
  *(undefined2 *)
   (param_1 * 0x24 +
    (*(uint *)(DAT_037ff3cc & 0xfffffffc) >> (DAT_037ff3cc & 3) * 8 |
    *(uint *)(DAT_037ff3cc & 0xfffffffc) << (DAT_037ff3cc & 3) * -8 + 0x20) + param_2 * 2 + 0x20) =
       param_3;
  return;
}

