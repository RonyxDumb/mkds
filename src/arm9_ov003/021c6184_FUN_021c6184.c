/* Decompiled C draft; module arm9_ov003; ROM address 021c6184. No matching claim. */
#include "types.h"
#include "deps/021c6184_FUN_021c6184.h"

void FUN_021c6184(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if ((*(int *)(*DAT_021c6340 + 0x38) == 0) && (*(char *)(*DAT_021c6340 + 0x57) == '\0')) {
    iVar1 = FUN_021d2a34((ushort *)(uintptr_t)(DAT_021c6344));
    if (iVar1 != 0) {
      uVar4 = 0;
      *(undefined1 *)(*DAT_021c6340 + 0x50) = 0xff;
      iVar1 = DAT_021c6348;
      do {
        iVar2 = FUN_021d2a34((ushort *)(uintptr_t)(iVar1));
        if (iVar2 != 0) {
          if (3 < (int)uVar4) {
            FUN_021bf31c(1);
            *DAT_021c634c = (char)uVar4;
            FUN_021c590c();
            return;
          }
          *(char *)(*DAT_021c6340 + 0x50) = (char)uVar4;
          break;
        }
        iVar1 = iVar1 + 8;
        uVar4 = uVar4 + 1;
      } while (uVar4 < 5);
    }
    iVar1 = FUN_021d299c((ushort *)(uintptr_t)(DAT_021c6344));
    if (iVar1 != 0) {
      iVar2 = 0;
      iVar1 = DAT_021c6348;
      do {
        iVar3 = FUN_021d299c((ushort *)(uintptr_t)(iVar1));
        if (iVar3 != 0) {
          if (*(char *)(*DAT_021c6340 + 0x50) == iVar2) {
            if (iVar2 < (int)(uint)*(byte *)(*DAT_021c6340 + 0x51)) {
              FUN_021bf31c(1);
              *DAT_021c634c = (char)iVar2;
              FUN_021c590c();
              return;
            }
            FUN_021cdc10(9);
          }
          break;
        }
        iVar1 = iVar1 + 8;
        iVar2 = iVar2 + 1;
      } while (iVar2 < 4);
    }
    iVar1 = FUN_021d2b04(1);
    if (iVar1 != 0) {
      FUN_021bf31c(1);
      FUN_021cce38();
      return;
    }
    iVar1 = FUN_021d2b04(2);
    if (iVar1 != 0) {
      FUN_021bf31c(0);
      return;
    }
    iVar1 = FUN_021d2ae8(DAT_021c6350);
    if (iVar1 != 0) {
      FUN_021c574c();
      return;
    }
    iVar1 = FUN_021d2acc(DAT_021c6350);
    if (iVar1 != 0) {
      *(undefined1 *)(*DAT_021c6340 + 0x59) = 0;
      return;
    }
    iVar1 = FUN_021d2ae8(DAT_021c6354);
    if (iVar1 != 0) {
      FUN_021c57b4();
      return;
    }
    iVar1 = FUN_021d2acc(DAT_021c6354);
    if (iVar1 != 0) {
      *(undefined1 *)(*DAT_021c6340 + 0x59) = 0;
      return;
    }
    iVar1 = FUN_021d2ae8(0x40);
    if (iVar1 != 0) {
      FUN_021c580c(1);
      return;
    }
    iVar1 = FUN_021d2acc(0x40);
    if (iVar1 != 0) {
      *(undefined1 *)(*DAT_021c6340 + 0x59) = 0;
      return;
    }
    iVar1 = FUN_021d2ae8(0x80);
    if (iVar1 != 0) {
      FUN_021c580c(3);
      return;
    }
    iVar1 = FUN_021d2acc(0x80);
    if (iVar1 != 0) {
      *(undefined1 *)(*DAT_021c6340 + 0x59) = 0;
    }
  }
  return;
}

