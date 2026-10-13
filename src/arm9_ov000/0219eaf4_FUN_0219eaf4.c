/* Decompiled C draft; module arm9_ov000; ROM address 0219eaf4. No matching claim. */
#include "types.h"
#include "deps/0219eaf4_FUN_0219eaf4.h"

undefined4 FUN_0219eaf4(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  longlong lVar8;
  undefined8 uVar9;
  
  iVar5 = *DAT_0219ec20;
  if ((*(int *)(iVar5 + DAT_0219ec24) != 8) && (1 < *(int *)(iVar5 + DAT_0219ec24) - 0xeU)) {
    return 1;
  }
  lVar8 = FUN_021a350c();
  iVar6 = DAT_0219ec34;
  lVar8 = lVar8 - CONCAT44(*(undefined4 *)(iVar5 + DAT_0219ec2c),
                           *(undefined4 *)(iVar5 + DAT_0219ec28));
  uVar2 = (uint)lVar8;
  iVar3 = (int)((ulonglong)lVar8 >> 0x20);
  iVar4 = *(int *)(iVar5 + DAT_0219ec24);
  if (iVar4 == 8) {
    if (((uint)(uVar2 <= DAT_0219ec30) <= (uint)-iVar3) &&
       (iVar5 = FUN_0219edb0(*(undefined4 *)(iVar5 + 0xf4),0xe,DAT_0219ec30,
                             -(uint)(uVar2 > DAT_0219ec30) - iVar3), iVar5 == 0)) {
      return 0;
    }
  }
  else if (iVar4 == 0xe) {
    bVar7 = uVar2 <= DAT_0219ec30;
    if ((uint)bVar7 <= (uint)-iVar3) {
      *(char *)(iVar5 + DAT_0219ec34) = *(char *)(iVar5 + DAT_0219ec34) + '\x01';
      piVar1 = DAT_0219ec20;
      iVar5 = *DAT_0219ec20;
      if (*(byte *)(iVar5 + iVar6) < 6) {
        iVar6 = 1;
        if (*(char *)(iVar5 + 0xd) != '\0') {
          iVar3 = 4;
          do {
            if (((*(uint *)(*piVar1 + DAT_0219ec38) &
                 1 << (uint)*(byte *)(*piVar1 + iVar6 + DAT_0219ec3c)) == 0) &&
               (iVar5 = FUN_0219edb0(*(undefined4 *)(iVar5 + iVar3 + 0xf4),0xd), iVar5 == 0)) {
              return 0;
            }
            iVar3 = iVar3 + 4;
            iVar6 = iVar6 + 1;
            iVar5 = *piVar1;
          } while (iVar6 <= (int)(uint)*(byte *)(iVar5 + 0xd));
        }
      }
      else {
        iVar5 = FUN_0219f00c(*(undefined4 *)(iVar5 + DAT_0219ec38),iVar5,iVar6,-(uint)!bVar7 - iVar3
                            );
        if (iVar5 == 0) {
          return 0;
        }
        if (*(char *)(*piVar1 + 0xd) == '\0') {
          FUN_0219f23c(2);
        }
        else {
          *(undefined1 *)(*piVar1 + DAT_0219ec34) = 0;
          uVar9 = FUN_021a350c();
          iVar5 = *piVar1;
          *(int *)(iVar5 + DAT_0219ec28) = (int)uVar9;
          *(int *)(iVar5 + DAT_0219ec2c) = (int)((ulonglong)uVar9 >> 0x20);
        }
      }
    }
  }
  else if ((iVar4 == 0xf) &&
          (bVar7 = uVar2 <= *(ushort *)(iVar5 + DAT_0219ec40), (uint)bVar7 <= (uint)-iVar3)) {
    FUN_0219f23c(2,iVar3,-(uint)!bVar7 - iVar3);
  }
  return 1;
}

