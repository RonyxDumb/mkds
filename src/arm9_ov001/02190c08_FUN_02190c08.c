/* Decompiled C draft; module arm9_ov001; ROM address 02190c08. No matching claim. */
#include "types.h"
#include "deps/02190c08_FUN_02190c08.h"

/* WARNING: Removing unreachable block (ram,0x02190ca8) */
/* WARNING: Removing unreachable block (ram,0x02190c5e) */
/* WARNING: Removing unreachable block (ram,0x02190ccc) */
/* WARNING: Removing unreachable block (ram,0x02190c3a) */

void FUN_02190c08(undefined4 param_1)

{
  undefined2 uVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  iVar3 = FUN_0218820c();
  if (iVar3 != 0) {
    FUN_02187218(param_1,3,DAT_02190cf4);
    FUN_02188c90(param_1);
    if (*(int *)(*DAT_02190cf8 + 8) == 4) {
      uVar1 = FUN_02181b54();
      uVar4 = FUN_02181b68(uVar1);
    }
    else {
      uVar4 = 0;
    }
    if (*(int *)(*DAT_02190cf8 + 8) == 4) {
      sVar2 = FUN_02181b54();
      uVar5 = FUN_02181b68(sVar2 + 1);
    }
    else {
      uVar5 = 0;
    }
    FUN_021911a8(uVar4);
    FUN_021911a8(uVar5);
    return;
  }
  FUN_02187218(param_1,3,DAT_02190cfc);
  FUN_02188c90(param_1);
  if (*(int *)(*DAT_02190cf8 + 8) == 4) {
    uVar1 = FUN_02181b54();
    uVar4 = FUN_02181b68(uVar1);
  }
  else {
    uVar4 = 0;
  }
  if (*(int *)(*DAT_02190cf8 + 8) == 4) {
    sVar2 = FUN_02181b54();
    uVar5 = FUN_02181b68(sVar2 + 1);
  }
  else {
    uVar5 = 0;
  }
  FUN_021918c8(uVar4);
  FUN_021918c8(uVar5);
  return;
}

