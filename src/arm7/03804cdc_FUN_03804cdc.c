/* Decompiled C draft; module arm7; ROM address 03804cdc. No matching claim. */
#include "types.h"
#include "deps/03804cdc_FUN_03804cdc.h"

void FUN_03804cdc(undefined1 *param_1)

{
  do {
  } while ((*DAT_03804d48 & 0x80) != 0);
  *DAT_03804d48 = 0x8900;
  *DAT_03804d4c = 5;
  do {
  } while ((*DAT_03804d48 & 0x80) != 0);
  *DAT_03804d48 = 0x8100;
  *DAT_03804d4c = 0;
  do {
  } while ((*DAT_03804d48 & 0x80) != 0);
  *param_1 = (char)*DAT_03804d4c;
  return;
}

