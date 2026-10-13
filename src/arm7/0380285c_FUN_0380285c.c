/* Decompiled C draft; module arm7; ROM address 0380285c. No matching claim. */
#include "types.h"
#include "deps/0380285c_FUN_0380285c.h"

void FUN_0380285c(ushort param_1,ushort param_2)

{
  do {
  } while ((*DAT_038028c4 & 0x80) != 0);
  FUN_038028cc(1);
  *DAT_038028c8 = param_1 & 0xff;
  do {
  } while ((*DAT_038028c4 & 0x80) != 0);
  FUN_038028cc(0);
  *DAT_038028c8 = param_2 & 0xff;
  return;
}

