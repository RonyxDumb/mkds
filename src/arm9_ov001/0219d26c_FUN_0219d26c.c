/* Decompiled C draft; module arm9_ov001; ROM address 0219d26c. No matching claim. */
#include "types.h"
#include "deps/0219d26c_FUN_0219d26c.h"

void FUN_0219d26c(void)

{
  *DAT_0219d2a4 = *DAT_0219d2a4 & 0x43 | (ushort)DAT_0219d2a8;
  *DAT_0219d2ac = *DAT_0219d2ac & DAT_0219d2b0 | DAT_0219d2b4;
  func_0x02036ab0(*(undefined4 *)(*DAT_0219d2b8 + DAT_0219d2bc));
  *DAT_0219d2b8 = 0;
  return;
}

