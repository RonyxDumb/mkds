/* Decompiled C draft; module arm9_ov001; ROM address 021a0774. No matching claim. */
#include "types.h"
#include "deps/021a0774_FUN_021a0774.h"

void FUN_021a0774(void)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  ushort *puVar5;
  int iVar6;
  int local_18 [2];
  
  iVar3 = func_0x02029608();
  piVar1 = DAT_021a08c0;
  iVar6 = 0;
  *(undefined4 *)
   (*(int *)(*DAT_021a08c0 + 0x40) + (uint)*(ushort *)(DAT_021a08c4 + (iVar3 + -1) * 2) * 0x40) = 0;
  *(undefined4 *)(*(int *)(*piVar1 + 0x40) + DAT_021a08c8) = 0;
  puVar5 = DAT_021a08cc;
  do {
    *(undefined4 *)(*(int *)(*piVar1 + 0x40) + (uint)*puVar5 * 0x40) = 0;
    puVar5 = puVar5 + 1;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 9);
  iVar3 = *piVar1;
  if (*(short *)(iVar3 + 0x9e) == 8) {
    **(undefined4 **)(iVar3 + 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x40) + 0x40) = 1;
  }
  else {
    **(undefined4 **)(iVar3 + 0x40) = 1;
    *(undefined4 *)(*(int *)(*piVar1 + 0x40) + 0x40) = 0;
    iVar3 = func_0x02029608();
    piVar1 = DAT_021a08c0;
    *(undefined4 *)
     (*(int *)(*DAT_021a08c0 + 0x40) + (uint)*(ushort *)(DAT_021a08c4 + (iVar3 + -1) * 2) * 0x40) =
         1;
    *(undefined4 *)(*(int *)(*piVar1 + 0x40) + DAT_021a08c8) = 1;
    iVar3 = *piVar1;
    *(undefined4 *)(*(int *)(iVar3 + 0x40) + (uint)DAT_021a08cc[*(short *)(iVar3 + 0x9e)] * 0x40) =
         1;
  }
  uVar2 = func_0x02029608();
  iVar3 = func_0x0205fd78(uVar2,(int)*(short *)(*DAT_021a08c0 + 0x9e) + 1U & 0xff,local_18);
  piVar1 = DAT_021a08c0;
  iVar6 = 0;
  *(undefined4 *)(*(int *)(*DAT_021a08c0 + 0x40) + DAT_021a08d0) = 0;
  puVar5 = DAT_021a08d4;
  do {
    *(undefined4 *)(*(int *)(*piVar1 + 0x40) + (uint)*puVar5 * 0x40) = 0;
    puVar5 = puVar5 + 1;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 6);
  if ((iVar3 != 0) && (local_18[0] < 8)) {
    if (local_18[0] < 5) {
      *(undefined4 *)(*(int *)(*piVar1 + 0x40) + DAT_021a08d0) = 1;
    }
    *(undefined4 *)(*(int *)(*DAT_021a08c0 + 0x40) + (uint)DAT_021a08d4[local_18[0] + -2] * 0x40) =
         1;
  }
  iVar6 = *DAT_021a08c0;
  uVar4 = func_0x02029608();
  iVar3 = func_0x0203b680(*(undefined4 *)(*DAT_021a08c0 + 0x4c),uVar4,*(short *)(iVar6 + 0x9e) + 1);
  uVar4 = func_0x020b3f7c(*(undefined4 *)(iVar6 + 0x58),
                          *(undefined2 *)(*(int *)(iVar6 + 0x50) + (iVar3 + -1) * 0x2c + 0xc));
  func_0x0212426c(0,0,*(undefined4 *)(*DAT_021a08c0 + 8),uVar4,*(undefined4 *)(iVar6 + 4),
                  *(undefined4 *)(iVar6 + 0x40));
  return;
}

