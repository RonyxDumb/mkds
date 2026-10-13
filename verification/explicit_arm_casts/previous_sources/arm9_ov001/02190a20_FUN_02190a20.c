/* Decompiled C draft; module arm9_ov001; ROM address 02190a20. No matching claim. */
#include "types.h"
#include "deps/02190a20_FUN_02190a20.h"

/* WARNING: Removing unreachable block (ram,0x02190a38) */
/* WARNING: Removing unreachable block (ram,0x02190a5c) */

undefined4 FUN_02190a20(int param_1)

{
  undefined2 uVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (*(int *)(*DAT_02190ac8 + 8) == 4) {
    uVar1 = FUN_02181b54();
    uVar3 = FUN_02181b68(uVar1);
  }
  else {
    uVar3 = 0;
  }
  if (*(int *)(*DAT_02190ac8 + 8) == 4) {
    sVar2 = FUN_02181b54();
    uVar4 = FUN_02181b68(sVar2 + 1);
  }
  else {
    uVar4 = 0;
  }
  iVar5 = func_0x0207a974((short)*(char *)(*DAT_02190ac8 + 0x62));
  FUN_02188998(param_1,iVar5 + 0x80);
  FUN_021924cc();
  iVar5 = FUN_021871f8(uVar3,3);
  if ((iVar5 != 0) && (iVar5 = FUN_021871f8(uVar4,3), iVar5 != 0)) {
    if (*(int *)(param_1 + 0xa8) == 4) {
      uVar3 = 5;
    }
    else {
      uVar3 = 4;
    }
    *(undefined4 *)(param_1 + 0xa8) = uVar3;
    FUN_02190948(param_1);
  }
  return 0;
}

