/* Decompiled C draft; module arm9; ROM address 02118624. No matching claim. */
#include "types.h"
#include "deps/02118624_func_02118624.h"

void func_02118624(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  ushort *puVar5;
  ushort *puVar6;
  undefined2 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint local_1c;
  
  local_1c = 0;
  if (*DAT_021187ac != 2) {
    puVar4 = (undefined4 *)*DAT_021187b0;
    func_0211de00(puVar4[0x11],*puVar4,puVar4[1],0x13,0);
    iVar10 = 0;
    iVar8 = 0;
    puVar7 = DAT_021187b4;
    do {
      iVar9 = *DAT_021187b0;
      uVar3 = Bmg_GetRawStringPointer_from_thumb
                        (*(undefined4 *)(iVar9 + 0x24),
                         *(undefined2 *)(iVar8 + DAT_021187b8 + *(int *)(iVar9 + 0x44) * 8));
      func_0212426c(0,*puVar7,*(undefined4 *)(*DAT_021187b0 + 8),uVar3,*(undefined4 *)(iVar9 + 4),
                    *(undefined4 *)(iVar9 + 0x18));
      piVar1 = DAT_021187b0;
      iVar8 = iVar8 + 2;
      puVar7 = puVar7 + 1;
      iVar10 = iVar10 + 1;
    } while (iVar10 < 4);
    iVar8 = 0;
    iVar10 = 0;
    puVar5 = DAT_021187bc;
    do {
      *(undefined4 *)(*(int *)(*piVar1 + 0x18) + (uint)*puVar5 * 0x40) = 0;
      piVar2 = DAT_021187b0;
      puVar5 = puVar5 + 1;
      iVar8 = iVar8 + 1;
      puVar6 = DAT_021187c0;
    } while (iVar8 < 8);
    do {
      *(undefined4 *)(*(int *)(*piVar2 + 0x18) + (uint)*puVar6 * 0x40) = 0;
      iVar10 = iVar10 + 1;
      puVar6 = puVar6 + 1;
    } while (iVar10 < 4);
    if (*(int *)(*piVar2 + 0x3c) == 0) {
      iVar8 = func_0202967c();
      if (iVar8 == 0) {
        iVar8 = func_0202969c();
        iVar8 = *(int *)(DAT_021187c4 + iVar8 * 4);
      }
      else {
        iVar8 = 3;
      }
      uVar3 = *(undefined4 *)(DAT_021187c8 + iVar8 * 4);
      iVar8 = CupHasRecord(*(undefined4 *)(DAT_021187cc + *(int *)(*DAT_021187b0 + 0x44) * 4),uVar3)
      ;
      if (iVar8 != 0) {
        iVar8 = GetCupEntryRank(*(undefined4 *)(DAT_021187cc + *(int *)(*DAT_021187b0 + 0x44) * 4),
                                uVar3);
        *(undefined4 *)
         (*(int *)(*DAT_021187b0 + 0x18) +
         (uint)DAT_021187bc[*(int *)(DAT_021187d0 + iVar8 * 4)] * 0x40) = 1;
        piVar1 = DAT_021187b0;
        switch(iVar8) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
          local_1c = (uint)*DAT_021187c0;
          break;
        case 5:
          local_1c = (uint)DAT_021187c0[1];
          break;
        case 6:
          local_1c = (uint)DAT_021187c0[2];
          break;
        case 7:
          local_1c = (uint)DAT_021187c0[3];
        }
        *(undefined4 *)(*(int *)(*DAT_021187b0 + 0x18) + local_1c * 0x40) = 1;
        uVar3 = CupGetResult(*(undefined4 *)(DAT_021187cc + *(int *)(*piVar1 + 0x44) * 4),uVar3);
        puVar4 = (undefined4 *)*DAT_021187b0;
        func_0211f244(*(undefined4 *)(DAT_021187cc + puVar4[0x11] * 4),uVar3,*puVar4,puVar4[1],
                      local_1c,4,0);
      }
    }
    func_021187d4();
  }
  return;
}

