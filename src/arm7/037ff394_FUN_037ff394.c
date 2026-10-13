/* Decompiled C draft; module arm7; ROM address 037ff394. No matching claim. */
#include "types.h"
#include "deps/037ff394_FUN_037ff394.h"

void FUN_037ff394(int param_1,undefined2 param_2)

{
  *(undefined2 *)
   ((*(uint *)(DAT_037ff3ac & 0xfffffffc) >> (DAT_037ff3ac & 3) * 8 |
    *(uint *)(DAT_037ff3ac & 0xfffffffc) << (DAT_037ff3ac & 3) * -8 + 0x20) + param_1 * 2 + 0x260) =
       param_2;
  return;
}

