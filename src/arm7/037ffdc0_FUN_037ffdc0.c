/* Decompiled C draft; module arm7; ROM address 037ffdc0. No matching claim. */
#include "types.h"
#include "deps/037ffdc0_FUN_037ffdc0.h"

void FUN_037ffdc0(void)

{
  if (*(uint *)((uint)DAT_037ffdf0 & 0xfffffffc) >> ((uint)DAT_037ffdf0 & 3) * 8 == 0 &&
      *(uint *)((uint)DAT_037ffdf0 & 0xfffffffc) << ((uint)DAT_037ffdf0 & 3) * -8 + 0x20 == 0) {
    *DAT_037ffdf0 = 1;
    FUN_037ffdf4();
  }
  return;
}

