/* Decompiled C draft; module arm9_ov001; ROM address 021900ac. No matching claim. */
#include "types.h"
#include "deps/021900ac_FUN_021900ac.h"

/* WARNING: Removing unreachable block (ram,0x021900f8) */
/* WARNING: Removing unreachable block (ram,0x021900d4) */
/* WARNING: Removing unreachable block (ram,0x0219011e) */

void FUN_021900ac(undefined4 param_1)

{
  undefined2 uVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  FUN_02187218(param_1,3,DAT_02190160);
  FUN_02188c90(param_1);
  if (*(int *)(*DAT_02190164 + 8) == 4) {
    uVar1 = FUN_02181b54();
    uVar3 = FUN_02181b68(uVar1);
  }
  else {
    uVar3 = 0;
  }
  if (*(int *)(*DAT_02190164 + 8) == 4) {
    sVar2 = FUN_02181b54();
    uVar4 = FUN_02181b68(sVar2 + 1);
  }
  else {
    uVar4 = 0;
  }
  if (*(int *)(*DAT_02190164 + 8) == 4) {
    sVar2 = FUN_02181b54();
    uVar5 = FUN_02181b68(sVar2 + 2);
  }
  else {
    uVar5 = 0;
  }
  uVar6 = FUN_02188220(uVar5);
  if (uVar6 < 2) {
    FUN_02191064(uVar3);
    FUN_02191064(uVar4);
    return;
  }
  FUN_02190fc4(uVar3);
  FUN_02190fc4(uVar4);
  return;
}

