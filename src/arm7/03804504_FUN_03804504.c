/* Decompiled C draft; module arm7; ROM address 03804504. No matching claim. */
#include "types.h"
#include "deps/03804504_FUN_03804504.h"

void FUN_03804504(void)

{
  do {
  } while ((*DAT_0380453c & 0x80) != 0);
  *DAT_0380453c = 0x8100;
  *DAT_03804540 = 0xff;
  do {
  } while ((*DAT_0380453c & 0x80) != 0);
  return;
}

