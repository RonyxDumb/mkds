/* Decompiled C draft; module arm9_ov000; ROM address 0219ec44. No matching claim. */
#include "types.h"
#include "deps/0219ec44_FUN_0219ec44.h"

undefined4 FUN_0219ec44(undefined4 param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ushort *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  longlong lVar10;
  
  iVar2 = FUN_0219bab4();
  if (iVar2 != 6) {
    return 1;
  }
  if (param_2 == 0xd) {
    if (*(int *)(*DAT_0219ed90 + DAT_0219ed94) != 8) {
      *(int *)(*DAT_0219ed90 + DAT_0219ed94) = 8;
      FUN_0219f124(param_3);
    }
    iVar2 = FUN_0219edb0(param_1,0xe);
    if (iVar2 == 0) {
      return 0;
    }
  }
  else if (param_2 == 0xe) {
    if (*(int *)(*DAT_0219ed90 + DAT_0219ed94) == 0xe) {
      lVar10 = FUN_021a350c();
      uVar3 = (uint)((ulonglong)lVar10 >> 0x20);
      iVar2 = *DAT_0219ed90;
      uVar7 = *(uint *)(iVar2 + DAT_0219ed98);
      puVar6 = *(ushort **)(iVar2 + DAT_0219ed9c);
      uVar4 = (int)puVar6 + (uint)CARRY4(uVar7,DAT_0219eda0);
      if (uVar4 <= uVar3 && (uint)((uint)lVar10 <= uVar7 + DAT_0219eda0) <= uVar4 - uVar3) {
        lVar10 = lVar10 - CONCAT44(puVar6,uVar7);
        uVar9 = (uint)((ulonglong)lVar10 >> 0x20);
        uVar3 = (uint)lVar10 >> 1 | uVar9 * -0x80000000;
        uVar4 = uVar3 + DAT_0219eda4;
        puVar6 = (ushort *)(iVar2 + DAT_0219eda8);
        uVar7 = *puVar6 - uVar4;
        if ((uint)(uVar4 <= *puVar6) <= -(((uVar9 >> 1) - 1) + (uint)CARRY4(uVar3,DAT_0219eda4))) {
          *puVar6 = (ushort)uVar4;
        }
      }
      uVar3 = FUN_0219e948(param_1,0,puVar6,uVar7);
      if (uVar3 != 0xff) {
        *(uint *)(*DAT_0219ed90 + DAT_0219edac) =
             *(uint *)(*DAT_0219ed90 + DAT_0219edac) | 1 << (uVar3 & 0xff);
      }
      iVar2 = FUN_0219e8fc(1);
      piVar1 = DAT_0219ed90;
      iVar5 = *DAT_0219ed90;
      if (*(int *)(iVar5 + DAT_0219edac) == iVar2) {
        iVar2 = 1;
        if (*(char *)(iVar5 + 0xd) != '\0') {
          iVar8 = 4;
          do {
            iVar5 = FUN_0219edb0(*(undefined4 *)(iVar5 + iVar8 + 0xf4),0xf);
            if (iVar5 == 0) {
              return 0;
            }
            iVar8 = iVar8 + 4;
            iVar2 = iVar2 + 1;
            iVar5 = *piVar1;
          } while (iVar2 <= (int)(uint)*(byte *)(iVar5 + 0xd));
        }
        *(undefined4 *)(iVar5 + DAT_0219ed94) = 0xf;
      }
    }
    else {
      iVar2 = FUN_0219edb0(param_1,0xf);
      if (iVar2 == 0) {
        return 0;
      }
    }
  }
  else if ((param_2 == 0xf) && (*(int *)(*DAT_0219ed90 + DAT_0219ed94) == 8)) {
    FUN_0219f23c(2);
  }
  return 1;
}

