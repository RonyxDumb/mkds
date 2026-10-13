/* Decompiled C draft; module arm9_ov001; ROM address 0219caf4. No matching claim. */
#include "types.h"
#include "deps/0219caf4_FUN_0219caf4.h"

void FUN_0219caf4(void)

{
  int *piVar1;
  int iVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  piVar1 = DAT_0219cb90;
  *(int *)(*DAT_0219cb90 + 0xc) = *(int *)(*DAT_0219cb90 + 0xc) + 1;
  uVar3 = func_0x020ae488(*(undefined4 *)(*piVar1 + 0xc));
  iVar2 = DAT_0219cb98;
  iVar6 = DAT_0219cb94;
  piVar1 = DAT_0219cb90;
  iVar7 = 0;
  do {
    *(undefined2 *)
     (*(int *)(*piVar1 + iVar2) + (uint)*(byte *)(iVar7 + iVar6 + *(int *)(*piVar1 + 8) * 3) * 0x40
     + 4) = uVar3;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 3);
  iVar6 = *piVar1;
  if (9 < *(int *)(iVar6 + 0xc)) {
    *(undefined4 *)(iVar6 + 4) = 5;
    *(undefined4 *)(*piVar1 + 0xc) = 0;
    uVar4 = func_0x020b3f7c(*(undefined4 *)(*piVar1 + DAT_0219cb9c),4);
    uVar5 = func_0x020b3f7c(*(undefined4 *)(*DAT_0219cb90 + DAT_0219cb9c),2);
    func_0x021277f8(uVar4,uVar5,0);
    func_0x0212775c(0,7);
    func_0x0212775c(1,0x10);
    return;
  }
  if (4 < *(int *)(iVar6 + 0xc)) {
    *(undefined4 *)(iVar6 + 0x20) = 1;
  }
  return;
}

