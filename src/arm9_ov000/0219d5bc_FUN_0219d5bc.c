/* Decompiled C draft; module arm9_ov000; ROM address 0219d5bc. No matching claim. */
#include "types.h"
#include "deps/0219d5bc_FUN_0219d5bc.h"

void FUN_0219d5bc(void)

{
  undefined8 uVar1;
  
  if (*DAT_0219d5e0 != 0) {
    *(undefined4 *)(*DAT_0219d5e0 + 8) = 0;
    uVar1 = func_0x0200f5ac();
    *(undefined8 *)(*DAT_0219d5e0 + 0xc) = uVar1;
  }
  return;
}

