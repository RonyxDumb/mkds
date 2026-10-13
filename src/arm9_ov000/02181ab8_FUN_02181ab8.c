/* Decompiled C draft; module arm9_ov000; ROM address 02181ab8. No matching claim. */
#include "types.h"
#include "deps/02181ab8_FUN_02181ab8.h"

void FUN_02181ab8(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  piVar1 = DAT_02181b40;
  *(int *)(*DAT_02181b40 + 0xc) = *(int *)(*DAT_02181b40 + 0xc) + 1;
  uVar4 = func_0x020ae488(*(undefined4 *)(*piVar1 + 0xc));
  iVar3 = DAT_02181b48;
  iVar2 = DAT_02181b44;
  piVar1 = DAT_02181b40;
  iVar7 = 0;
  iVar6 = *DAT_02181b40;
  iVar5 = *(int *)(iVar6 + 8);
  if (0 < *(int *)(DAT_02181b44 + iVar5 * 4)) {
    do {
      *(undefined2 *)
       (*(int *)(iVar6 + 0x1c) + (uint)*(byte *)(iVar7 + iVar3 + iVar5 * 5) * 0x40 + 4) = uVar4;
      iVar7 = iVar7 + 1;
      iVar6 = *piVar1;
      iVar5 = *(int *)(iVar6 + 8);
    } while (iVar7 < *(int *)(iVar2 + iVar5 * 4));
  }
  if (*(int *)(iVar6 + 0xc) < 10) {
    if (4 < *(int *)(iVar6 + 0xc)) {
      *(undefined4 *)(iVar6 + 0x18) = 1;
    }
    return;
  }
  *(undefined4 *)(iVar6 + 4) = 5;
  if ((*(int *)(*DAT_02181b40 + 8) == 0) || (*(int *)(*DAT_02181b40 + 8) == 2)) {
    func_0x021282c8();
  }
  *(undefined4 *)(*DAT_02181b40 + 0xc) = 0;
  return;
}

