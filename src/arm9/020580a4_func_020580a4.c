/* Decompiled C draft; module arm9; ROM address 020580a4. No matching claim. */
#include "types.h"
#include "deps/020580a4_func_020580a4.h"

void func_020580a4(void)

{
  byte bVar1;
  int iVar2;
  ushort uVar3;
  int *piVar4;
  int iVar5;
  
  iVar2 = iRam02058128;
  piVar4 = (int *)*piRam02058120;
  if (piVar4 == (int *)0x0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *piVar4;
  }
  if (iVar5 == 1) {
    bVar1 = *(byte *)(*piRam02058120 + 0x87);
    if (bVar1 == (bVar1 & *(byte *)(*piRam02058120 + iRam02058124))) {
      *(undefined2 *)((int)piVar4 + iRam02058128 + 0x10) = 0xe;
      *(undefined2 *)((int)piVar4 + iVar2 + 0x12) = 1;
      return;
    }
  }
  else {
    if (*(char *)((int)piVar4 + iRam02058124) != '\0') {
      *(undefined2 *)((int)piVar4 + iRam02058128 + 0x10) = 0xe;
      *(undefined2 *)((int)piVar4 + iVar2 + 0x12) = 1;
      return;
    }
    if (*piVar4 == 2) {
      uVar3 = *(ushort *)((int)piVar4 + iRam0205812c);
    }
    else {
      uVar3 = 0;
    }
    func_020503cc(uVar3 & 0xff,1);
  }
  return;
}

