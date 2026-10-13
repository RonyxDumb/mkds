/* Decompiled C draft; module arm7; ROM address 037fc8cc. No matching claim. */
#include "types.h"
#include "deps/037fc8cc_FUN_037fc8cc.h"

void FUN_037fc8cc(uint param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    *DAT_037fc904 =
         (*(uint *)((uint)DAT_037fc904 & 0xfffffffc) >> ((uint)DAT_037fc904 & 3) * 8 |
         *(uint *)((uint)DAT_037fc904 & 0xfffffffc) << ((uint)DAT_037fc904 & 3) * -8 + 0x20) &
         ~param_1;
    return;
  }
  *DAT_037fc900 =
       (*(uint *)((uint)DAT_037fc900 & 0xfffffffc) >> ((uint)DAT_037fc900 & 3) * 8 |
       *(uint *)((uint)DAT_037fc900 & 0xfffffffc) << ((uint)DAT_037fc900 & 3) * -8 + 0x20) &
       ~param_1;
  return;
}

