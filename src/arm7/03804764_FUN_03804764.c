/* Decompiled C draft; module arm7; ROM address 03804764. No matching claim. */
#include "types.h"
#include "deps/03804764_FUN_03804764.h"

void FUN_03804764(undefined4 param_1)

{
  do {
  } while ((*DAT_03804820 & 0x80) != 0);
  *DAT_03804820 = 0x8900;
  *DAT_03804824 = 0xdb;
  do {
  } while ((*DAT_03804820 & 0x80) != 0);
  *DAT_03804824 = (ushort)((uint)param_1 >> 0x10) & 0xff;
  do {
  } while ((*DAT_03804820 & 0x80) != 0);
  *DAT_03804824 = (ushort)((uint)param_1 >> 8) & 0xff;
  do {
  } while ((*DAT_03804820 & 0x80) != 0);
  *DAT_03804820 = 0x8100;
  *DAT_03804824 = (ushort)param_1 & 0xff;
  do {
  } while ((*DAT_03804820 & 0x80) != 0);
  return;
}

