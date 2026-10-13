/* Decompiled C draft; module arm9_ov000; ROM address 021b00b0. No matching claim. */
#include "types.h"
#include "deps/021b00b0_FUN_021b00b0.h"

undefined4 FUN_021b00b0(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_021b00fc();
  if ((iVar1 != 0) && (~*DAT_021b00dc == (~*DAT_021b00dc & param_1))) {
    uVar2 = 1;
  }
  return uVar2;
}

