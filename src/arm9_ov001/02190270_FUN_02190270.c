/* Decompiled C draft; module arm9_ov001; ROM address 02190270. No matching claim. */
#include "types.h"
#include "deps/02190270_FUN_02190270.h"

/* WARNING: Removing unreachable block (ram,0x021902be) */
/* WARNING: Removing unreachable block (ram,0x021902e2) */

void FUN_02190270(int param_1)

{
  undefined2 uVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  func_0x0207a974((short)*(char *)(*DAT_02190320 + 0x62));
  FUN_02187218(param_1,3,DAT_02190324);
  FUN_02188c90(param_1);
  if (*(int *)(param_1 + 0xa8) == 5) {
    uVar4 = 4;
  }
  else {
    uVar4 = 5;
  }
  *(undefined4 *)(param_1 + 0xa8) = uVar4;
  if (*(int *)(*DAT_02190320 + 8) == 4) {
    uVar1 = FUN_02181b54();
    uVar4 = FUN_02181b68(uVar1);
  }
  else {
    uVar4 = 0;
  }
  if (*(int *)(*DAT_02190320 + 8) == 4) {
    sVar2 = FUN_02181b54();
    uVar3 = FUN_02181b68(sVar2 + 1);
  }
  else {
    uVar3 = 0;
  }
  if (*(int *)(param_1 + 0xa8) != 4) {
    FUN_02191b40(uVar4);
    FUN_02191e90(uVar3);
    return;
  }
  FUN_02191e90(uVar4);
  FUN_02191b40(uVar3);
  return;
}

