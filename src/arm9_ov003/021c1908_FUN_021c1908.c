/* Decompiled C draft; module arm9_ov003; ROM address 021c1908. No matching claim. */
#include "types.h"
#include "deps/021c1908_FUN_021c1908.h"

void FUN_021c1908(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_20 [12];
  
  iVar3 = FUN_021d2a34((ushort *)(uintptr_t)(DAT_021c1a24));
  if (iVar3 != 0) {
    iVar5 = 0;
    *(undefined1 *)(*DAT_021c1a28 + 0x61) = 0xff;
    uVar1 = DAT_021c1a30;
    iVar3 = DAT_021c1a2c;
    do {
      FUN_021d250c((short *)(uintptr_t)(iVar3),(short *)(uintptr_t)(uVar1),(short *)(void *)(auStack_20));
      iVar4 = FUN_021d2a34((ushort *)(void *)(auStack_20));
      uVar2 = DAT_021c1a38;
      if (iVar4 != 0) {
        if (*(char *)(*DAT_021c1a28 + 0x67) != '\0') {
          FUN_021cdc10(0);
          *(char *)(*DAT_021c1a28 + 0x61) = (char)iVar5;
          return;
        }
        FUN_021cdc10(9);
        return;
      }
      iVar3 = iVar3 + 4;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 10);
    iVar5 = 0;
    iVar3 = DAT_021c1a34;
    do {
      FUN_021d250c((short *)(uintptr_t)(iVar3),(short *)(uintptr_t)(uVar2),(short *)(void *)(auStack_20));
      iVar4 = FUN_021d2a34((ushort *)(void *)(auStack_20));
      uVar1 = DAT_021c1a40;
      if (iVar4 != 0) {
        if (((iVar5 != 0) || (*(char *)(*DAT_021c1a28 + 0x66) != '\0')) &&
           ((iVar5 != 1 || (*(char *)(*DAT_021c1a28 + 0x68) != '\0')))) {
          FUN_021cdc10(0);
          *(char *)(*DAT_021c1a28 + 0x61) = (char)iVar5 + '\n';
          return;
        }
        FUN_021cdc10(9);
        return;
      }
      iVar3 = iVar3 + 4;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 2);
    iVar5 = 0;
    iVar3 = DAT_021c1a3c;
    do {
      FUN_021d250c((short *)(uintptr_t)(iVar3),(short *)(uintptr_t)(uVar1),(short *)(void *)(auStack_20));
      iVar4 = FUN_021d2a34((ushort *)(void *)(auStack_20));
      if (iVar4 != 0) {
        FUN_021cdc10(0);
        *(char *)(*DAT_021c1a28 + 0x61) = (char)iVar5 + '\f';
        return;
      }
      iVar3 = iVar3 + 4;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 2);
  }
  return;
}

