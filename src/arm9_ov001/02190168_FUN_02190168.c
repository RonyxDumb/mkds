/* Decompiled C draft; module arm9_ov001; ROM address 02190168. No matching claim. */
#include "types.h"
#include "deps/02190168_FUN_02190168.h"

/* WARNING: Removing unreachable block (ram,0x021901e2) */
/* WARNING: Removing unreachable block (ram,0x02190180) */
/* WARNING: Removing unreachable block (ram,0x021901a4) */
/* WARNING: Removing unreachable block (ram,0x02190216) */

undefined4 FUN_02190168(undefined4 param_1)

{
  undefined2 uVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (*(int *)(*DAT_02190244 + 8) == 4) {
    uVar1 = FUN_02181b54();
    uVar3 = FUN_02181b68(uVar1);
  }
  else {
    uVar3 = 0;
  }
  if (*(int *)(*DAT_02190244 + 8) == 4) {
    sVar2 = FUN_02181b54();
    uVar4 = FUN_02181b68(sVar2 + 1);
  }
  else {
    uVar4 = 0;
  }
  iVar5 = FUN_021871f8(uVar3,3);
  if ((iVar5 != 0) && (iVar5 = FUN_021871f8(uVar4,3), iVar5 != 0)) {
    if (*(int *)(*DAT_02190244 + 8) == 4) {
      sVar2 = FUN_02181b54();
      uVar3 = FUN_02181b68(sVar2 + 2);
    }
    else {
      uVar3 = 0;
    }
    iVar5 = FUN_02188220(uVar3);
    if (iVar5 == 1) {
      FUN_02190270(param_1);
    }
    else {
      if (*(int *)(*DAT_02190244 + 8) == 4) {
        sVar2 = FUN_02181b54();
        uVar3 = FUN_02181b68(sVar2 + 2);
      }
      else {
        uVar3 = 0;
      }
      iVar5 = FUN_02188220(uVar3);
      if (iVar5 == 2) {
        FUN_02190248(param_1);
      }
      else {
        FUN_02188e88(param_1);
      }
    }
  }
  return 0;
}

