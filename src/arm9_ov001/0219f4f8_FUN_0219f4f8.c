/* Decompiled C draft; module arm9_ov001; ROM address 0219f4f8. No matching claim. */
#include "types.h"
#include "deps/0219f4f8_FUN_0219f4f8.h"

void FUN_0219f4f8(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  int local_20;
  ushort *local_1c;
  
  piVar1 = DAT_0219f678;
  uVar2 = (uint)*(ushort *)(*(int *)(*DAT_0219f678 + 4) + 6);
  local_20 = 0;
  local_1c = DAT_0219f680;
  puVar5 = DAT_0219f67c;
  do {
    *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uint)*puVar5 * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uint)puVar5[1] * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uint)puVar5[2] * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uint)puVar5[3] * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uint)puVar5[4] * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uint)puVar5[5] * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uint)puVar5[6] * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uint)puVar5[7] * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uint)puVar5[8] * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uint)puVar5[9] * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uint)puVar5[10] * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uVar2 + *local_1c) * 0x40) = 0;
    iVar3 = FUN_0219f688((int)(short)local_20);
    if (iVar3 == 0) {
      if (local_20 != 6) {
        *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uint)*puVar5 * 0x40) = 1;
        *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uint)puVar5[4] * 0x40) = 1;
        *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uint)puVar5[6] * 0x40) = 1;
      }
    }
    else {
      *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uint)*puVar5 * 0x40) = 1;
      *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uint)puVar5[1] * 0x40) = 1;
      *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uint)puVar5[5] * 0x40) = 1;
      iVar3 = FUN_0219f6a0((int)(short)local_20);
      if (iVar3 < 5) {
        *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uint)puVar5[7] * 0x40) = 1;
        *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uVar2 + *local_1c) * 0x40) = 1;
        iVar4 = *piVar1;
        func_0x0212426c(1,*local_1c,*(undefined4 *)(iVar4 + 0xc),
                        *(undefined4 *)(DAT_0219f684 + iVar3 * 4),*(undefined4 *)(iVar4 + 4),
                        *(undefined4 *)(iVar4 + 0x10));
      }
      else if (iVar3 < 8) {
        *(undefined4 *)(*(int *)(*piVar1 + 0x10) + (uint)puVar5[iVar3 + 3] * 0x40) = 1;
      }
    }
    func_0x02124a98(*puVar5,1,*(undefined4 *)*piVar1,((undefined4 *)*piVar1)[1]);
    puVar5 = puVar5 + 0xb;
    local_1c = local_1c + 1;
    local_20 = local_20 + 1;
  } while (local_20 < 7);
  return;
}

