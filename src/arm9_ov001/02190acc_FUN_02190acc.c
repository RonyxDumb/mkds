/* Decompiled C draft; module arm9_ov001; ROM address 02190acc. No matching claim. */
#include "types.h"
#include "deps/02190acc_FUN_02190acc.h"

/* WARNING: Removing unreachable block (ram,0x02190b06) */
/* WARNING: Removing unreachable block (ram,0x02190b2a) */

void FUN_02190acc(undefined4 param_1)

{
  undefined2 uVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  func_0x0207a974((short)*(char *)(*DAT_02190b50 + 0x62));
  FUN_02187218(param_1,3,DAT_02190b54);
  FUN_02188c90(param_1);
  if (*(int *)(*DAT_02190b50 + 8) == 4) {
    uVar1 = FUN_02181b54();
    uVar3 = FUN_02181b68(uVar1);
  }
  else {
    uVar3 = 0;
  }
  if (*(int *)(*DAT_02190b50 + 8) == 4) {
    sVar2 = FUN_02181b54();
    uVar4 = FUN_02181b68(sVar2 + 1);
  }
  else {
    uVar4 = 0;
  }
  FUN_02191bc0(uVar3);
  FUN_02191bc0(uVar4);
  return;
}

