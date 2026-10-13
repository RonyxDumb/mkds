/* Decompiled C draft; module arm9_ov003; ROM address 021c1680. No matching claim. */
#include "types.h"
#include "deps/021c1680_FUN_021c1680.h"

void FUN_021c1680(void)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_20 [12];
  
  iVar4 = FUN_021d2a80(DAT_021c17b4);
  uVar1 = DAT_021c17bc;
  if (iVar4 != 0) {
    iVar6 = 0;
    iVar4 = DAT_021c17b8;
    do {
      FUN_021d250c(iVar4,uVar1,auStack_20);
      iVar5 = FUN_021d2a80(auStack_20);
      uVar3 = DAT_021c17c8;
      if (iVar5 != 0) {
        if (*(char *)(*DAT_021c17c0 + 0x61) != iVar6) goto LAB_021c179a;
        FUN_021c1648(iVar6);
        goto LAB_021c17a2;
      }
      iVar4 = iVar4 + 4;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 10);
    iVar6 = 0;
    iVar4 = DAT_021c17c4;
    do {
      FUN_021d250c(iVar4,uVar3,auStack_20);
      iVar5 = FUN_021d2a80(auStack_20);
      uVar1 = DAT_021c17d0;
      if (iVar5 != 0) {
        if ((int)*(char *)(*DAT_021c17c0 + 0x61) != iVar6 + 10) goto LAB_021c179a;
        FUN_021c1648();
        piVar2 = DAT_021c17c0;
        if (iVar6 == 0) {
          *(char *)(*DAT_021c17c0 + 0x65) = *(char *)(*DAT_021c17c0 + 0x65) + '\x01';
          iVar4 = *piVar2;
          if (*(byte *)(iVar4 + 0x65) < 0x28) {
            return;
          }
          if (*(char *)(iVar4 + 0x66) == '\0') {
            FUN_021cdc10(9);
            *(undefined1 *)(*DAT_021c17c0 + 0x61) = 0xff;
            return;
          }
          *(undefined1 *)(iVar4 + 0x60) = 0x10;
          iVar4 = *piVar2;
          *(char *)(iVar4 + 0x65) = *(char *)(iVar4 + 0x65) + -7;
          return;
        }
        goto LAB_021c17a2;
      }
      iVar4 = iVar4 + 4;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 2);
    iVar6 = 0;
    iVar4 = DAT_021c17cc;
    do {
      FUN_021d250c(iVar4,uVar1,auStack_20);
      iVar5 = FUN_021d2a80(auStack_20);
      if (iVar5 != 0) {
        if ((int)*(char *)(*DAT_021c17c0 + 0x61) == iVar6 + 0xc) {
          FUN_021c1648(iVar6 + 0xc);
          goto LAB_021c17a2;
        }
        break;
      }
      iVar4 = iVar4 + 4;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 2);
  }
LAB_021c179a:
  FUN_021c1648(0xffffffff);
LAB_021c17a2:
  *(undefined1 *)(*DAT_021c17c0 + 0x65) = 0;
  return;
}

