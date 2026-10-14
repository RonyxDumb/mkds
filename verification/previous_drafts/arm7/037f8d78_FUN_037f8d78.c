/* Decompiled C draft; module arm7; ROM address 037f8d78. No matching claim. */
#include "types.h"
#include "deps/037f8d78_FUN_037f8d78.h"

uint FUN_037f8d78(void)

{
  uint uVar1;
  uint unaff_r4;
  
  FUN_037faf70();
  uVar1 = *(uint *)((uint)DAT_037f8dac & 0xfffffffc) >> ((uint)DAT_037f8dac & 3) * 8 |
          *(uint *)((uint)DAT_037f8dac & 0xfffffffc) << ((uint)DAT_037f8dac & 3) * -8 + 0x20;
  if (uVar1 != 0xffffffff) {
    *DAT_037f8dac = uVar1 + 1;
    unaff_r4 = uVar1;
  }
  FUN_037faf84();
  return unaff_r4;
}

