/* Decompiled C draft; module arm7; ROM address 03804d50. No matching claim. */
#include "types.h"
#include "deps/03804d50_FUN_03804d50.h"

void FUN_03804d50(void)

{
  do {
  } while ((*DAT_03804d88 & 0x80) != 0);
  *DAT_03804d88 = 0x8100;
  *DAT_03804d8c = 4;
  do {
  } while ((*DAT_03804d88 & 0x80) != 0);
  return;
}

