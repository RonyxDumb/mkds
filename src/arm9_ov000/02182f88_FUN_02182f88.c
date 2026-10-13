/* Decompiled C draft; module arm9_ov000; ROM address 02182f88. No matching claim. */
#include "types.h"
#include "deps/02182f88_FUN_02182f88.h"

void FUN_02182f88(void)

{
  *DAT_02182fc4 =
       *DAT_02182fc4 & DAT_02182fcc | ((*DAT_02182fc4 & DAT_02182fc8) >> 8 & 0xfffffff7) << 8;
  *DAT_02182fd0 = *DAT_02182fd0 & 0x43 | (ushort)DAT_02182fd4;
  func_0x0212b91c();
  *DAT_02182fd8 = 0;
  return;
}

