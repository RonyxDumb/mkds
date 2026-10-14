/* Decompiled C draft; module arm7; ROM address 037fac40. No matching claim. */
#include "types.h"
#include "deps/037fac40_FUN_037fac40.h"

void FUN_037fac40(int param_1)

{
  ushort *puVar1;
  
  FUN_037f8944(4,DAT_037fac94);
  puVar1 = DAT_037fac98;
  *DAT_037fac98 =
       *DAT_037fac98 & 0x3f | (ushort)(((int)*(short *)(param_1 + 0x10) & 0xffU) << 8) |
       (ushort)((int)((int)*(short *)(param_1 + 0x10) & 0x100U) >> 1);
  *puVar1 = *puVar1 | 0x20;
  FUN_037f888c(4);
  return;
}

