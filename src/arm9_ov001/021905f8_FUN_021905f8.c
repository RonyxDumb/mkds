/* Decompiled C draft; module arm9_ov001; ROM address 021905f8. No matching claim. */
#include "types.h"
#include "deps/021905f8_FUN_021905f8.h"

/* WARNING: Removing unreachable block (ram,0x0219061e) */
/* WARNING: Removing unreachable block (ram,0x02190642) */

void FUN_021905f8(int param_1)

{
  undefined2 uVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  FUN_02187218(param_1,3,DAT_02190680);
  FUN_02188c90(param_1);
  if (*(int *)(*DAT_02190684 + 8) == 4) {
    uVar1 = FUN_02181b54();
    uVar3 = FUN_02181b68(uVar1);
  }
  else {
    uVar3 = 0;
  }
  if (*(int *)(*DAT_02190684 + 8) == 4) {
    sVar2 = FUN_02181b54();
    uVar4 = FUN_02181b68(sVar2 + 1);
  }
  else {
    uVar4 = 0;
  }
  if (*(int *)(param_1 + 0xa8) != 4) {
    FUN_02191e1c(uVar3);
    FUN_02191318(uVar4);
    return;
  }
  FUN_02191318(uVar3);
  FUN_02191e1c(uVar4);
  return;
}

