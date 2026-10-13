/* Decompiled C draft; module arm9_ov000; ROM address 0219ee14. No matching claim. */
#include "types.h"
#include "deps/0219ee14_FUN_0219ee14.h"

undefined4 FUN_0219ee14(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  longlong lVar9;
  undefined8 uVar10;
  
  iVar6 = *DAT_0219ef40;
  if ((*(int *)(iVar6 + DAT_0219ef44) != 9) && (1 < *(int *)(iVar6 + DAT_0219ef44) - 0x10U)) {
    return 1;
  }
  lVar9 = FUN_021a350c();
  iVar7 = DAT_0219ef58;
  lVar9 = lVar9 - CONCAT44(*(undefined4 *)(iVar6 + DAT_0219ef4c),
                           *(undefined4 *)(iVar6 + DAT_0219ef48));
  uVar2 = (uint)lVar9;
  iVar3 = (int)((ulonglong)lVar9 >> 0x20);
  iVar4 = *(int *)(iVar6 + DAT_0219ef44);
  if (iVar4 == 9) {
    if ((uint)(uVar2 <= DAT_0219ef50) <= (uint)-iVar3) {
      FUN_0219ef68(*(undefined1 *)(iVar6 + DAT_0219ef54),3,DAT_0219ef50,
                   -(uint)(uVar2 > DAT_0219ef50) - iVar3);
    }
  }
  else if (iVar4 == 0x10) {
    bVar8 = uVar2 <= DAT_0219ef50;
    if ((uint)bVar8 <= (uint)-iVar3) {
      iVar5 = *(byte *)(iVar6 + DAT_0219ef58) + 1;
      *(byte *)(iVar6 + DAT_0219ef58) = (byte)iVar5;
      iVar6 = DAT_0219ef5c;
      piVar1 = DAT_0219ef40;
      iVar4 = *DAT_0219ef40;
      if (*(byte *)(iVar4 + iVar7) < 6) {
        iVar7 = 1;
        if (*(char *)(iVar4 + 0xd) != '\0') {
          do {
            uVar2 = (uint)*(byte *)(*piVar1 + iVar7 + DAT_0219ef54);
            if ((*(uint *)(*piVar1 + iVar6) & 1 << uVar2) == 0) {
              FUN_0219ef68(uVar2,2);
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 <= (int)(uint)*(byte *)(*piVar1 + 0xd));
        }
      }
      else if ((*(char *)(iVar4 + 0x15) == '\0') || (*(char *)(iVar4 + 0x15) == '\x01')) {
        FUN_0219f0f4();
        FUN_0219f23c(1);
      }
      else {
        iVar6 = FUN_0219f00c(*(undefined4 *)(iVar4 + DAT_0219ef5c),DAT_0219ef5c,iVar5,
                             -(uint)!bVar8 - iVar3);
        if (iVar6 == 0) {
          return 0;
        }
        iVar6 = *piVar1;
        if (*(char *)(iVar6 + 0xd) == '\0') {
          iVar6 = FUN_0219f9bc(*(undefined4 *)(iVar6 + DAT_0219ef60));
          if (iVar6 == 0) {
            return 0;
          }
        }
        else {
          *(undefined1 *)(iVar6 + DAT_0219ef58) = 0;
          uVar10 = FUN_021a350c();
          iVar6 = *piVar1;
          *(int *)(iVar6 + DAT_0219ef48) = (int)uVar10;
          *(int *)(iVar6 + DAT_0219ef4c) = (int)((ulonglong)uVar10 >> 0x20);
        }
      }
    }
  }
  else if ((iVar4 == 0x11) &&
          (bVar8 = uVar2 <= *(ushort *)(iVar6 + DAT_0219ef64), (uint)bVar8 <= (uint)-iVar3)) {
    FUN_0219f544(4,iVar3,-(uint)!bVar8 - iVar3);
  }
  return 1;
}

