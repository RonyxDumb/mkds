/* Decompiled C draft; module arm9_ov001; ROM address 02190b58. No matching claim. */
#include "types.h"
#include "deps/02190b58_FUN_02190b58.h"

/* WARNING: Removing unreachable block (ram,0x02190b70) */
/* WARNING: Removing unreachable block (ram,0x02190b94) */

undefined4 FUN_02190b58(int param_1)

{
  undefined2 uVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (*(int *)(*DAT_02190c00 + 8) == 4) {
    uVar1 = FUN_02181b54();
    uVar3 = FUN_02181b68(uVar1);
  }
  else {
    uVar3 = 0;
  }
  if (*(int *)(*DAT_02190c00 + 8) == 4) {
    sVar2 = FUN_02181b54();
    uVar4 = FUN_02181b68(sVar2 + 1);
  }
  else {
    uVar4 = 0;
  }
  iVar5 = func_0x0207a974((short)*(char *)(*DAT_02190c00 + 0x62));
  FUN_02188998(param_1,iVar5 + 0x80);
  FUN_021924cc();
  iVar5 = FUN_021871f8(uVar3,3);
  if ((iVar5 != 0) && (iVar5 = FUN_021871f8(uVar4,3), iVar5 != 0)) {
    FUN_02188218(param_1,*(uint *)(*(int *)(param_1 + 0xa0) + DAT_02190c04) & 0xffff);
    FUN_02190c08(param_1);
  }
  return 0;
}

