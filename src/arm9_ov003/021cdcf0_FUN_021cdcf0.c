/* Decompiled C draft; module arm9_ov003; ROM address 021cdcf0. No matching claim. */
#include "types.h"
#include "deps/021cdcf0_FUN_021cdcf0.h"

void FUN_021cdcf0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_021bf650(*(undefined4 *)(DAT_021cdd1c + param_1 * 4));
  uVar1 = FUN_021d14b8(uVar1,0,4);
  *DAT_021cdd20 = uVar1;
  FUN_021d3544(1,DAT_021cdd24,0,0x78);
  return;
}

