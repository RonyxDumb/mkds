/* Decompiled C draft; module arm7; ROM address 038027cc. No matching claim. */
#include "types.h"
#include "deps/038027cc_FUN_038027cc.h"

ushort FUN_038027cc(ushort param_1)

{
  do {
  } while ((*DAT_03802854 & 0x80) != 0);
  FUN_038028cc(1);
  *DAT_03802858 = param_1 & 0xff | 0x80;
  do {
  } while ((*DAT_03802854 & 0x80) != 0);
  FUN_038028cc(0);
  *DAT_03802858 = 0;
  do {
  } while ((*DAT_03802854 & 0x80) != 0);
  return *DAT_03802858 & 0xff;
}

