/* Decompiled C draft; module arm7; ROM address 03804d90. No matching claim. */
#include "types.h"
#include "deps/03804d90_FUN_03804d90.h"

void FUN_03804d90(void)

{
  do {
  } while ((*DAT_03804dc8 & 0x80) != 0);
  *DAT_03804dc8 = 0x8100;
  *DAT_03804dcc = 6;
  do {
  } while ((*DAT_03804dc8 & 0x80) != 0);
  return;
}

