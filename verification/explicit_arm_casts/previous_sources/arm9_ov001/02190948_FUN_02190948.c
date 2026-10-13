/* Decompiled C draft; module arm9_ov001; ROM address 02190948. No matching claim. */
#include "types.h"
#include "deps/02190948_FUN_02190948.h"

/* WARNING: Removing unreachable block (ram,0x021909a0) */
/* WARNING: Removing unreachable block (ram,0x021909c4) */

void FUN_02190948(int param_1)

{
  undefined2 uVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  iVar3 = FUN_0218820c();
  if (iVar3 == 0) {
    FUN_02190acc(param_1);
    return;
  }
  iVar3 = func_0x0207a974((short)*(char *)(*DAT_02190a10 + 0x62));
  FUN_02187218(param_1,3,DAT_02190a14);
  FUN_02188c48(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02190a18),DAT_02190a1c);
  FUN_02188998(param_1,iVar3 + 0x80);
  if (*(int *)(*DAT_02190a10 + 8) == 4) {
    uVar1 = FUN_02181b54();
    uVar4 = FUN_02181b68(uVar1);
  }
  else {
    uVar4 = 0;
  }
  if (*(int *)(*DAT_02190a10 + 8) == 4) {
    sVar2 = FUN_02181b54();
    uVar5 = FUN_02181b68(sVar2 + 1);
  }
  else {
    uVar5 = 0;
  }
  if (*(int *)(param_1 + 0xa8) != 4) {
    FUN_021920dc(uVar4);
    FUN_02191c14(uVar5);
    return;
  }
  FUN_02191c14(uVar4);
  FUN_021920dc(uVar5);
  return;
}

