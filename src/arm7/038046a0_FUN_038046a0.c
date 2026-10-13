/* Decompiled C draft; module arm7; ROM address 038046a0. No matching claim. */
#include "types.h"
#include "deps/038046a0_FUN_038046a0.h"

void FUN_038046a0(undefined4 param_1)

{
  do {
  } while ((*DAT_0380475c & 0x80) != 0);
  *DAT_0380475c = 0x8900;
  *DAT_03804760 = 0xd8;
  do {
  } while ((*DAT_0380475c & 0x80) != 0);
  *DAT_03804760 = (ushort)((uint)param_1 >> 0x10) & 0xff;
  do {
  } while ((*DAT_0380475c & 0x80) != 0);
  *DAT_03804760 = (ushort)((uint)param_1 >> 8) & 0xff;
  do {
  } while ((*DAT_0380475c & 0x80) != 0);
  *DAT_0380475c = 0x8100;
  *DAT_03804760 = (ushort)param_1 & 0xff;
  do {
  } while ((*DAT_0380475c & 0x80) != 0);
  return;
}

