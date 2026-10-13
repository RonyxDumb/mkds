/* Decompiled C draft; module arm9_ov000; ROM address 02183548. No matching claim. */
#include "types.h"
#include "deps/02183548_FUN_02183548.h"

void FUN_02183548(void)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_30;
  byte *local_28;
  byte *local_24;
  int local_20;
  
  iVar7 = DAT_02183638;
  piVar2 = DAT_0218362c;
  uVar1 = *(ushort *)(*(int *)(*DAT_0218362c + DAT_02183630) + 6);
  local_30 = 0;
  iVar3 = DAT_02183634;
  do {
    iVar5 = 0;
    do {
      *(undefined2 *)(*(int *)(*piVar2 + iVar7) + (uint)*(byte *)(iVar3 + iVar5) * 0x40 + 4) =
           *(undefined2 *)(*piVar2 + 0x10);
      iVar5 = iVar5 + 1;
    } while (iVar5 < 5);
    iVar3 = iVar3 + 5;
    local_30 = local_30 + 1;
  } while (local_30 < 3);
  iVar5 = 0;
  local_20 = 0;
  local_28 = DAT_0218363c;
  local_24 = DAT_02183640;
  iVar3 = (uint)uVar1 * 0x40;
  iVar7 = DAT_02183644;
  do {
    iVar4 = *DAT_0218362c;
    *(short *)((uint)*local_28 * 0x40 + iVar3 + *(int *)(iVar4 + DAT_02183638) + 4) =
         *(short *)(iVar4 + 0x10) + *(short *)(iVar4 + iVar5 + 0x18);
    *(undefined2 *)((uint)*local_24 * 0x40 + iVar3 + *(int *)(*DAT_0218362c + DAT_02183638) + 4) =
         *(undefined2 *)(*DAT_0218362c + 0x10);
    iVar4 = 0;
    do {
      iVar6 = *DAT_0218362c;
      *(short *)((uint)*(byte *)(iVar7 + iVar4) * 0x40 + iVar3 + *(int *)(iVar6 + DAT_02183638) + 4)
           = *(short *)(iVar6 + 0x10) - *(short *)(iVar5 + iVar6 + 0x18);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 2);
    iVar5 = iVar5 + 2;
    local_28 = local_28 + 1;
    local_24 = local_24 + 1;
    iVar7 = iVar7 + 2;
    local_20 = local_20 + 1;
  } while (local_20 < 3);
  *(undefined2 *)(*(int *)(*DAT_0218362c + DAT_02183638) + iVar3 + DAT_02183648) =
       *(undefined2 *)(*DAT_0218362c + 0x10);
  return;
}

