/* Decompiled C draft; module arm9; ROM address 021296b4. No matching claim. */
#include "types.h"
#include "deps/021296b4_func_021296b4.h"

void func_021296b4(void)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  *(undefined4 *)(*piRam0212977c + 0x1c) = 0;
  iVar3 = func_020ab748();
  piVar2 = piRam0212977c;
  if (0 < iVar3) {
    iVar3 = 0;
    do {
      iVar4 = func_020ab798();
      if (*(short *)(iVar4 + iVar3) != 0x20) {
        iVar4 = func_020ab798();
        if (*(ushort *)(iVar4 + iVar3) != uRam02129780) {
          *(undefined4 *)(*piVar2 + 0x1c) = 1;
        }
      }
      iVar3 = iVar3 + 2;
      iVar5 = iVar5 + 1;
      iVar4 = func_020ab748();
    } while (iVar5 < iVar4);
  }
  bVar1 = *(byte *)(iRam02129784 + 1);
  iVar3 = func_020ab748();
  if (bVar1 - 1 == iVar3) {
    iVar5 = (uint)bVar1 * 2;
    iVar3 = func_020ab798();
    if (*(short *)(iVar3 + iVar5 + -2) != 0x20) {
      iVar3 = func_020ab798();
      if (*(ushort *)(iVar3 + iVar5 + -2) != uRam02129780) {
        iVar3 = func_020ab798();
        if (*(short *)(iVar3 + iVar5 + -2) != 0) {
          *(undefined4 *)(*piRam0212977c + 0x1c) = 1;
        }
      }
    }
  }
  iVar3 = func_020ab8c4();
  if (iVar3 == 1) {
    *(undefined4 *)(*piRam0212977c + 0x14) = 1;
  }
  else {
    *(undefined4 *)(*piRam0212977c + 0x14) = 0;
  }
  iVar3 = func_020ab8c4();
  if (iVar3 == 2) {
    *(undefined4 *)(*piRam0212977c + 0x18) = 1;
    return;
  }
  *(undefined4 *)(*piRam0212977c + 0x18) = 0;
  return;
}

