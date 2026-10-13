/* Decompiled C draft; module arm9_ov001; ROM address 02190468. No matching claim. */
#include "types.h"
#include "deps/02190468_FUN_02190468.h"

/* WARNING: Removing unreachable block (ram,0x021904b8) */
/* WARNING: Removing unreachable block (ram,0x021904dc) */

void FUN_02190468(int param_1)

{
  undefined2 uVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  iVar3 = func_0x0207a974((short)*(char *)(*DAT_0219051c + 0x62));
  FUN_02187218(param_1,3,DAT_02190520);
  FUN_02188c48(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02190524),DAT_02190528);
  FUN_02188998(param_1,(undefined4 *)(uintptr_t)(iVar3 + 0x80));
  if (*(int *)(*DAT_0219051c + 8) == 4) {
    uVar1 = FUN_02181b54();
    uVar4 = FUN_02181b68(uVar1);
  }
  else {
    uVar4 = 0;
  }
  if (*(int *)(*DAT_0219051c + 8) == 4) {
    sVar2 = FUN_02181b54();
    uVar5 = FUN_02181b68(sVar2 + 1);
  }
  else {
    uVar5 = 0;
  }
  if (*(int *)(param_1 + 0xa8) != 4) {
    FUN_021920dc(uVar4);
    FUN_02192174(uVar5);
    return;
  }
  FUN_02192174(uVar4);
  FUN_021920dc(uVar5);
  return;
}

