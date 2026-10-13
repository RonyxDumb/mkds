/* Decompiled C draft; module arm7; ROM address 03803f9c. No matching claim. */
#include "types.h"
#include "deps/03803f9c_FUN_03803f9c.h"

void FUN_03803f9c(void)

{
  if (*(uint *)((uint)DAT_03803fec & 0xfffffffc) >> ((uint)DAT_03803fec & 3) * 8 == 0 &&
      *(uint *)((uint)DAT_03803fec & 0xfffffffc) << ((uint)DAT_03803fec & 3) * -8 + 0x20 == 0) {
    *DAT_03803fec = 1;
    FUN_03803c24();
    thunk_FUN_037fb72c();
    FUN_037fb6c0(0xd,DAT_03803ff0);
    FUN_03803eb4();
    FUN_037fb6c0(0xd,DAT_03803ff4);
  }
  return;
}

