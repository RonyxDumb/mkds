/* Decompiled C draft; module arm9_ov000; ROM address 02189478. No matching claim. */
#include "types.h"
#include "deps/02189478_FUN_02189478.h"

void FUN_02189478(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_02188584(1);
  iVar2 = FUN_021884fc();
  if (iVar2 < 4) {
    FUN_02189440();
    return;
  }
  if (iVar2 < 5) {
    FUN_02189438();
    return;
  }
  if (iVar2 == 5) {
    FUN_02189420(uVar1);
    return;
  }
  FUN_02189350(uVar1);
  return;
}

