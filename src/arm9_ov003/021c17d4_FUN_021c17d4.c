/* Decompiled C draft; module arm9_ov003; ROM address 021c17d4. No matching claim. */
#include "types.h"
#include "deps/021c17d4_FUN_021c17d4.h"

void FUN_021c17d4(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_20 [12];
  
  *(undefined1 *)(*DAT_021c18dc + 0x60) = 0;
  iVar4 = FUN_021d299c((ushort *)(uintptr_t)(DAT_021c18e0));
  uVar2 = DAT_021c18e8;
  if (iVar4 != 0) {
    iVar6 = 0;
    iVar4 = DAT_021c18e4;
    do {
      FUN_021d250c((short *)(uintptr_t)(iVar4),(short *)(uintptr_t)(uVar2),(short *)(void *)(auStack_20));
      iVar5 = FUN_021d299c((ushort *)(void *)(auStack_20));
      uVar3 = DAT_021c18f4;
      piVar1 = DAT_021c18dc;
      if (iVar5 != 0) {
        if (*(char *)(*DAT_021c18dc + 0x61) != iVar6) {
          return;
        }
        *(undefined1 *)(*DAT_021c18dc + 0x60) = *(undefined1 *)(DAT_021c18ec + iVar6);
        *(char *)(*piVar1 + 99) = (char)iVar6;
        FUN_021c1268();
        return;
      }
      iVar4 = iVar4 + 4;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 10);
    iVar6 = 0;
    iVar4 = DAT_021c18f0;
    do {
      FUN_021d250c((short *)(uintptr_t)(iVar4),(short *)(uintptr_t)(uVar3),(short *)(void *)(auStack_20));
      iVar5 = FUN_021d299c((ushort *)(void *)(auStack_20));
      uVar2 = DAT_021c1900;
      piVar1 = DAT_021c18dc;
      if (iVar5 != 0) {
        if ((int)*(char *)(*DAT_021c18dc + 0x61) != iVar6 + 10) {
          return;
        }
        *(undefined1 *)(*DAT_021c18dc + 0x60) = *(undefined1 *)(DAT_021c18f8 + iVar6);
        *(char *)(*piVar1 + 99) = (char)(iVar6 + 10);
        FUN_021c1268();
        return;
      }
      iVar4 = iVar4 + 4;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 2);
    iVar6 = 0;
    iVar4 = DAT_021c18fc;
    do {
      FUN_021d250c((short *)(uintptr_t)(iVar4),(short *)(uintptr_t)(uVar2),(short *)(void *)(auStack_20));
      iVar5 = FUN_021d299c((ushort *)(void *)(auStack_20));
      piVar1 = DAT_021c18dc;
      if (iVar5 != 0) {
        if ((int)*(char *)(*DAT_021c18dc + 0x61) != iVar6 + 0xc) {
          return;
        }
        *(undefined1 *)(*DAT_021c18dc + 0x60) = *(undefined1 *)(DAT_021c1904 + iVar6);
        *(char *)(*piVar1 + 99) = (char)(iVar6 + 0xc);
        FUN_021c1268();
        return;
      }
      iVar4 = iVar4 + 4;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 2);
  }
  return;
}

