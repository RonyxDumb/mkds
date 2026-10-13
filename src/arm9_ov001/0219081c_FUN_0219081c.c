/* Decompiled C draft; module arm9_ov001; ROM address 0219081c. No matching claim. */
#include "types.h"
#include "deps/0219081c_FUN_0219081c.h"

/* WARNING: Removing unreachable block (ram,0x02190856) */
/* WARNING: Removing unreachable block (ram,0x0219087a) */

void FUN_0219081c(undefined4 param_1)

{
  undefined2 uVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  func_0x0207a974((short)*(char *)(*DAT_021908a0 + 0x62));
  FUN_02187218(param_1,3,DAT_021908a4);
  FUN_02188c90(param_1);
  if (*(int *)(*DAT_021908a0 + 8) == 4) {
    uVar1 = FUN_02181b54();
    uVar3 = FUN_02181b68(uVar1);
  }
  else {
    uVar3 = 0;
  }
  if (*(int *)(*DAT_021908a0 + 8) == 4) {
    sVar2 = FUN_02181b54();
    uVar4 = FUN_02181b68(sVar2 + 1);
  }
  else {
    uVar4 = 0;
  }
  FUN_02191b40(uVar3);
  FUN_02191b40(uVar4);
  return;
}

