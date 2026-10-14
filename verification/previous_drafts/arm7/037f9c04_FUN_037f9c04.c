/* Decompiled C draft; module arm7; ROM address 037f9c04. No matching claim. */
#include "types.h"
#include "deps/037f9c04_FUN_037f9c04.h"

void FUN_037f9c04(void)

{
  undefined4 uVar1;
  
  if (*(uint *)((uint)DAT_037f9ca4 & 0xfffffffc) >> ((uint)DAT_037f9ca4 & 3) * 8 == 0 &&
      *(uint *)((uint)DAT_037f9ca4 & 0xfffffffc) << ((uint)DAT_037f9ca4 & 3) * -8 + 0x20 == 0) {
    *DAT_037f9ca4 = 1;
    uVar1 = FUN_037f9b6c();
    FUN_037f9b00(1,uVar1);
    uVar1 = FUN_037f9b14(1);
    FUN_037f9aec(1,uVar1);
    uVar1 = FUN_037f9b6c(7);
    FUN_037f9b00(7,uVar1);
    uVar1 = FUN_037f9b14(7);
    FUN_037f9aec(7,uVar1);
    uVar1 = FUN_037f9b6c(8);
    FUN_037f9b00(8,uVar1);
    uVar1 = FUN_037f9b14(8);
    FUN_037f9aec(8,uVar1);
  }
  return;
}

