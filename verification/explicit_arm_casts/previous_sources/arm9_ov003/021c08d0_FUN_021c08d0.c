/* Decompiled C draft; module arm9_ov003; ROM address 021c08d0. No matching claim. */
#include "types.h"
#include "deps/021c08d0_FUN_021c08d0.h"

void FUN_021c08d0(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_20 [12];
  
  iVar2 = FUN_021d2a34(DAT_021c09f4);
  if (iVar2 != 0) {
    iVar5 = 0;
    *(undefined1 *)(*DAT_021c09f8 + DAT_021c09fc) = 0xff;
    uVar1 = DAT_021c0a04;
    iVar2 = DAT_021c0a00;
    do {
      FUN_021d250c(iVar2,uVar1,auStack_20);
      iVar3 = FUN_021d2a34(auStack_20);
      if (iVar3 != 0) {
        if (*(char *)(*DAT_021c09f8 + DAT_021c0a08) != '\0') {
          FUN_021cdc10(0);
          *(char *)(*DAT_021c09f8 + DAT_021c09fc) = (char)iVar5;
          return;
        }
        FUN_021cdc10(9);
        return;
      }
      iVar2 = iVar2 + 4;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x2f);
    iVar3 = 0;
    iVar2 = DAT_021c0a10;
    iVar5 = DAT_021c0a0c;
    do {
      FUN_021d250c(iVar2,iVar5,auStack_20);
      iVar4 = FUN_021d2a34(auStack_20);
      uVar1 = DAT_021c0a20;
      if (iVar4 != 0) {
        if (((iVar3 != 3) || (*(char *)(*DAT_021c09f8 + DAT_021c0a14) != '\0')) &&
           ((iVar3 != 2 || (*(char *)(*DAT_021c09f8 + DAT_021c0a08) != '\0')))) {
          FUN_021cdc10(*(undefined4 *)(DAT_021c0a18 + iVar3 * 4));
          *(char *)(*DAT_021c09f8 + DAT_021c09fc) = (char)iVar3 + '/';
          return;
        }
        FUN_021cdc10(9);
        return;
      }
      iVar5 = iVar5 + 4;
      iVar2 = iVar2 + 4;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
    iVar5 = 0;
    iVar2 = DAT_021c0a1c;
    do {
      FUN_021d250c(iVar2,uVar1,auStack_20);
      iVar3 = FUN_021d2a34(auStack_20);
      if (iVar3 != 0) {
        FUN_021cdc10(0);
        *(char *)(*DAT_021c09f8 + DAT_021c09fc) = (char)iVar5 + '3';
        return;
      }
      iVar2 = iVar2 + 4;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 2);
  }
  return;
}

