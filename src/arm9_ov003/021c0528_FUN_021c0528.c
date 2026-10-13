/* Decompiled C draft; module arm9_ov003; ROM address 021c0528. No matching claim. */
#include "types.h"
#include "deps/021c0528_FUN_021c0528.h"

void FUN_021c0528(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  undefined1 auStack_20 [12];
  
  iVar3 = FUN_021d2a80((ushort *)(uintptr_t)(DAT_021c0650));
  uVar1 = DAT_021c0658;
  if (iVar3 != 0) {
    iVar7 = 0;
    iVar3 = DAT_021c0654;
    do {
      FUN_021d250c((short *)(uintptr_t)(iVar3),(short *)(uintptr_t)(uVar1),(short *)(void *)(auStack_20));
      iVar4 = FUN_021d2a80((ushort *)(void *)(auStack_20));
      if (iVar4 != 0) {
        if (*(char *)(*DAT_021c065c + DAT_021c0660) != iVar7) goto LAB_021c0636;
        FUN_021c04ec(iVar7);
        goto LAB_021c063e;
      }
      iVar3 = iVar3 + 4;
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0x2f);
    iVar4 = 2;
    iVar3 = DAT_021c0668;
    iVar7 = DAT_021c0664;
    do {
      FUN_021d250c((short *)(uintptr_t)(iVar3),(short *)(uintptr_t)(iVar7),(short *)(void *)(auStack_20));
      iVar5 = FUN_021d2a80((ushort *)(void *)(auStack_20));
      uVar1 = DAT_021c067c;
      if (iVar5 != 0) {
        if ((int)*(char *)(*DAT_021c065c + DAT_021c0660) == iVar4 + 0x2f) {
          FUN_021c04ec();
          iVar3 = DAT_021c066c;
          piVar2 = DAT_021c065c;
          if (iVar4 != 3) {
            return;
          }
          *(char *)(*DAT_021c065c + DAT_021c066c) = *(char *)(*DAT_021c065c + DAT_021c066c) + '\x01'
          ;
          iVar7 = *piVar2;
          if (*(byte *)(iVar7 + iVar3) < 0x28) {
            return;
          }
          if (*(char *)(iVar7 + DAT_021c0670) != '\0') {
            *(undefined1 *)(iVar7 + DAT_021c0674) = 0x80;
            pcVar6 = (char *)(*piVar2 + iVar3);
            *pcVar6 = *pcVar6 + -7;
            return;
          }
          FUN_021cdc10(9);
          *(undefined1 *)(*DAT_021c065c + DAT_021c0660) = 0xff;
          return;
        }
        goto LAB_021c0636;
      }
      iVar7 = iVar7 + 4;
      iVar3 = iVar3 + 4;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 4);
    iVar7 = 0;
    iVar3 = DAT_021c0678;
    do {
      FUN_021d250c((short *)(uintptr_t)(iVar3),(short *)(uintptr_t)(uVar1),(short *)(void *)(auStack_20));
      iVar4 = FUN_021d2a80((ushort *)(void *)(auStack_20));
      if (iVar4 != 0) {
        if ((int)*(char *)(*DAT_021c065c + DAT_021c0660) == iVar7 + 0x33) {
          FUN_021c04ec(iVar7 + 0x33);
          goto LAB_021c063e;
        }
        break;
      }
      iVar3 = iVar3 + 4;
      iVar7 = iVar7 + 1;
    } while (iVar7 < 2);
  }
LAB_021c0636:
  FUN_021c04ec(0xffffffff);
LAB_021c063e:
  *(undefined1 *)(*DAT_021c065c + DAT_021c066c) = 0;
  return;
}

