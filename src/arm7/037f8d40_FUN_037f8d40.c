/* Decompiled C draft; module arm7; ROM address 037f8d40. No matching claim. */
#include "types.h"
#include "deps/037f8d40_FUN_037f8d40.h"

uint FUN_037f8d40(void)

{
  uint uVar1;
  uint uVar2;
  
  FUN_037faf70();
  uVar1 = *(uint *)((uint)DAT_037f8d74 & 0xfffffffc) >> ((uint)DAT_037f8d74 & 3) * 8 |
          *(uint *)((uint)DAT_037f8d74 & 0xfffffffc) << ((uint)DAT_037f8d74 & 3) * -8 + 0x20;
  uVar2 = 0;
  if (uVar1 != 0) {
    *DAT_037f8d74 = uVar1 - 1;
    uVar2 = uVar1;
  }
  FUN_037faf84();
  return uVar2;
}

