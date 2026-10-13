/* Decompiled C draft; module arm9_ov001; ROM address 02194fd8. No matching claim. */
#include "types.h"
#include "deps/02194fd8_FUN_02194fd8.h"

void FUN_02194fd8(int param_1)

{
  int *piVar1;
  int iVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = DAT_021950cc;
  iVar5 = param_1 * 2;
  *(undefined4 *)(*(int *)(*DAT_021950cc + 0x54) + (uint)*(ushort *)(DAT_021950d0 + iVar5) * 0x40) =
       0;
  *(undefined4 *)(*(int *)(*piVar1 + 0x54) + (uint)*(ushort *)(DAT_021950d4 + param_1 * 4) * 0x40) =
       0;
  *(undefined4 *)(*(int *)(*piVar1 + 0x54) + (uint)*(ushort *)(DAT_021950d8 + param_1 * 4) * 0x40) =
       0;
  iVar2 = *piVar1;
  func_0x02124224(1,*(undefined2 *)(DAT_021950dc + iVar5),*(undefined4 *)(iVar2 + 0x24),DAT_021950e0
                  ,*(undefined4 *)(iVar2 + 0x1c),*(undefined4 *)(iVar2 + 0x54),7);
  iVar2 = *DAT_021950cc;
  func_0x02124248(1,*(undefined2 *)(DAT_021950e4 + iVar5),*(undefined4 *)(iVar2 + 0x24),DAT_021950e8
                  ,*(undefined4 *)(iVar2 + 0x1c),*(undefined4 *)(iVar2 + 0x54),7);
  piVar1 = DAT_021950cc;
  iVar4 = 0;
  iVar2 = param_1 * 6;
  puVar3 = (ushort *)(DAT_021950ec + iVar2);
  do {
    *(undefined4 *)(*(int *)(*piVar1 + 0x54) + (uint)*puVar3 * 0x40) = 0;
    puVar3 = puVar3 + 1;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 3);
  if ((param_1 != 3) || (iVar4 = FUN_02194d04(*(undefined4 *)(*piVar1 + 0x78)), iVar4 != 0)) {
    *(undefined4 *)(*(int *)(*DAT_021950cc + 0x54) + (uint)*(ushort *)(DAT_021950ec + iVar2) * 0x40)
         = 1;
  }
  piVar1 = DAT_021950cc;
  iVar4 = 0;
  puVar3 = (ushort *)(DAT_021950f0 + iVar2);
  do {
    *(undefined4 *)(*(int *)(*piVar1 + 0x54) + (uint)*puVar3 * 0x40) = 0;
    puVar3 = puVar3 + 1;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 3);
  iVar2 = *piVar1;
  func_0x0212426c(1,*(undefined2 *)(DAT_021950f4 + iVar5),*(undefined4 *)(iVar2 + 0x24),DAT_021950f8
                  ,*(undefined4 *)(iVar2 + 0x1c),*(undefined4 *)(iVar2 + 0x54));
  return;
}

