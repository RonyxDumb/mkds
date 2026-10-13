/* Decompiled C draft; module arm9_ov001; ROM address 0219c950. No matching claim. */
#include "types.h"
#include "deps/0219c950_FUN_0219c950.h"

void FUN_0219c950(void)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int local_1c;
  int local_18;
  
  piVar1 = DAT_0219ca20;
  *(int *)(*DAT_0219ca20 + 0xc) = *(int *)(*DAT_0219ca20 + 0xc) + 1;
  if ((10 < *(int *)(*piVar1 + 0xc)) &&
     (((*(int *)(*piVar1 + 0x2c) != 0 && (iVar3 = func_0x02128274(), iVar3 != 0)) ||
      ((*(int *)(*DAT_0219ca20 + 0x2c) == 0 && (iVar3 = func_0x02128294(), iVar3 != 0)))))) {
    *(undefined4 *)(*DAT_0219ca20 + 0x24) = *(undefined4 *)(*DAT_0219ca20 + 0x28);
    return;
  }
  if (10 < *(int *)(*DAT_0219ca20 + 0xc)) {
    *(undefined4 *)(*DAT_0219ca20 + 0xc) = 10;
  }
  uVar4 = func_0x020ae4c0(1,0,0xa0,*(undefined4 *)(*DAT_0219ca20 + 0xc),10);
  piVar1 = DAT_0219ca20;
  *(undefined4 *)(*DAT_0219ca20 + 0x14) = uVar4;
  uVar4 = func_0x020ae4c0(1,0,0xffffff00,*(undefined4 *)(*piVar1 + 0xc),10);
  piVar1 = DAT_0219ca20;
  *(undefined4 *)(*DAT_0219ca20 + 0x18) = uVar4;
  local_1c = 0;
  local_18 = 0;
  iVar3 = local_18;
  iVar5 = DAT_0219ca24;
  do {
    do {
      uVar2 = func_0x020ae4c0(1,0,0xdc,*(undefined4 *)(*piVar1 + 0xc),10);
      *(undefined2 *)(*(int *)(*piVar1 + DAT_0219ca28) + (uint)*(byte *)(iVar5 + iVar3) * 0x40 + 4)
           = uVar2;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
    iVar5 = iVar5 + 3;
    local_1c = local_1c + 1;
    iVar3 = local_18;
  } while (local_1c < 6);
  return;
}

