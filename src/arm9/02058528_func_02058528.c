/* Decompiled C draft; module arm9; ROM address 02058528. No matching claim. */
#include "types.h"
#include "deps/02058528_func_02058528.h"

void func_02058528(void)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  ushort uVar7;
  uint uVar8;
  undefined2 local_14 [2];
  undefined4 local_10 [2];
  
  iVar5 = iRam02058664;
  piVar4 = (int *)*piRam0205864c;
  if (piVar4 == (int *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = *piVar4;
  }
  if (iVar6 == 1) {
    bVar1 = *(byte *)(*piRam0205864c + 0x86);
    bVar2 = *(byte *)(*piRam0205864c + iRam02058650);
    if (bVar1 == (bVar1 & bVar2)) {
      iVar5 = func_020586ac(0xfe,0,bVar2 | 1,0,bVar2);
      if (iVar5 != 0) {
        iVar5 = *piRam0205864c + iRam02058654;
        *(undefined2 *)(iVar5 + 0x10) = 9;
        *(undefined2 *)(iVar5 + 0x12) = 1;
        return;
      }
    }
    else {
      uVar8 = uRam02058660;
      if ((*(ushort *)((int)piVar4 + iRam02058658) & 0x40) != 0) {
        uVar8 = uRam0205865c;
      }
      *(short *)((int)piVar4 + iRam02058664) = *(short *)((int)piVar4 + iRam02058664) + 1;
      iVar6 = *piRam0205864c;
      if (uVar8 < *(ushort *)(iVar6 + iVar5)) {
        *(undefined1 *)(iVar6 + 0x86) = *(undefined1 *)(iVar6 + 0x87);
        return;
      }
    }
  }
  else if ((*(byte *)((int)piVar4 + iRam02058668) & 1) != 0) {
    cVar3 = *(char *)(*piRam0205864c + iRam0205866c);
    if (*(int *)*piRam0205864c == 2) {
      uVar8 = (uint)*(ushort *)((int)piVar4 + iRam02058670);
    }
    else {
      uVar8 = 0;
    }
    iVar5 = func_0205867c((int)piVar4 + iRam02058678 * uVar8 + iRam02058674,cVar3,0x20,local_10,
                          local_14);
    if (iVar5 != 0) {
      if (*(int *)*piRam0205864c == 2) {
        uVar7 = *(ushort *)(*piRam0205864c + iRam02058670);
      }
      else {
        uVar7 = 0;
      }
      func_020586ac(cVar3,local_10[0],local_14[0],uVar7 & 0xff,1);
      *(char *)(*piRam0205864c + iRam0205866c) = cVar3 + '\x01';
      return;
    }
    *(undefined1 *)(*piRam0205864c + iRam0205866c) = 0;
  }
  return;
}

