/* Decompiled C draft; module arm7; ROM address 03804620. No matching claim. */
#include "types.h"
#include "deps/03804620_FUN_03804620.h"

void FUN_03804620(void)

{
  do {
  } while ((*DAT_03804658 & 0x80) != 0);
  *DAT_03804658 = 0x8100;
  *DAT_0380465c = 0xab;
  do {
  } while ((*DAT_03804658 & 0x80) != 0);
  return;
}

