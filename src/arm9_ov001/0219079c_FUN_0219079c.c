/* Decompiled C draft; module arm9_ov001; ROM address 0219079c. No matching claim. */
#include "types.h"
#include "deps/0219079c_FUN_0219079c.h"

/* WARNING: Removing unreachable block (ram,0x021907b4) */
/* WARNING: Removing unreachable block (ram,0x021907d8) */

undefined4 FUN_0219079c(undefined4 param_1)

{
  undefined2 uVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (*(int *)(*DAT_02190818 + 8) == 4) {
    uVar1 = FUN_02181b54();
    uVar3 = FUN_02181b68(uVar1);
  }
  else {
    uVar3 = 0;
  }
  if (*(int *)(*DAT_02190818 + 8) == 4) {
    sVar2 = FUN_02181b54();
    uVar4 = FUN_02181b68(sVar2 + 1);
  }
  else {
    uVar4 = 0;
  }
  FUN_02192694();
  FUN_021924cc();
  iVar5 = FUN_021871f8(uVar3,3);
  if ((iVar5 != 0) && (iVar5 = FUN_021871f8(uVar4,3), iVar5 != 0)) {
    FUN_02188e88(param_1);
  }
  return 0;
}

