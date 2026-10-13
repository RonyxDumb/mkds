/* Decompiled C draft; module arm9_ov001; ROM address 02190328. No matching claim. */
#include "types.h"
#include "deps/02190328_FUN_02190328.h"

/* WARNING: Removing unreachable block (ram,0x02190376) */
/* WARNING: Removing unreachable block (ram,0x0219039a) */

void FUN_02190328(int param_1)

{
  undefined2 uVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  func_0x0207a974((short)*(char *)(*DAT_021903d8 + 0x62));
  FUN_02187218(param_1,3,DAT_021903dc);
  FUN_02188c90(param_1);
  if (*(int *)(param_1 + 0xa8) == 5) {
    uVar4 = 4;
  }
  else {
    uVar4 = 5;
  }
  *(undefined4 *)(param_1 + 0xa8) = uVar4;
  if (*(int *)(*DAT_021903d8 + 8) == 4) {
    uVar1 = FUN_02181b54();
    uVar4 = FUN_02181b68(uVar1);
  }
  else {
    uVar4 = 0;
  }
  if (*(int *)(*DAT_021903d8 + 8) == 4) {
    sVar2 = FUN_02181b54();
    uVar3 = FUN_02181b68(sVar2 + 1);
  }
  else {
    uVar3 = 0;
  }
  if (*(int *)(param_1 + 0xa8) != 4) {
    FUN_02191e1c(uVar4);
    FUN_02191bc0(uVar3);
    return;
  }
  FUN_02191bc0(uVar4);
  FUN_02191e1c(uVar3);
  return;
}

