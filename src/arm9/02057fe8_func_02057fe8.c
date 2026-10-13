/* Decompiled C draft; module arm9; ROM address 02057fe8. No matching claim. */
#include "types.h"
#include "deps/02057fe8_func_02057fe8.h"

void func_02057fe8(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = iRam02058088;
  piVar5 = (int *)*piRam0205807c;
  if (piVar5 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *piVar5;
  }
  if (iVar2 == 1) {
    uVar3 = (uint)*(byte *)(*piRam0205807c + iRam02058080);
    if (((uint)*(byte *)(*piRam0205807c + iRam02058084) & 1 << uVar3) == 0) {
      *(char *)((int)piVar5 + iRam02058080) = *(char *)((int)piVar5 + iRam02058080) + '\x01';
    }
    else {
      iVar4 = func_020503cc(uVar3,*(undefined1 *)((int)piVar5 + 0x87));
      if (iVar4 != 0) {
        *(char *)(*piRam0205807c + iRam02058080) = *(char *)(*piRam0205807c + iRam02058080) + '\x01'
        ;
      }
    }
    if (8 < *(byte *)(*piRam0205807c + iRam02058080)) {
      iVar4 = *piRam0205807c + iRam02058088;
      *(undefined2 *)(iVar4 + 0x10) = 0xb;
      *(undefined2 *)(iVar4 + 0x12) = 1;
      return;
    }
  }
  else {
    bVar1 = *(byte *)(*piRam0205807c + iRam02058084);
    if (bVar1 == (bVar1 & *(byte *)(*piRam0205807c + iRam0205808c))) {
      *(undefined2 *)((int)piVar5 + iRam02058088 + 0x10) = 0xb;
      *(undefined2 *)((int)piVar5 + iVar4 + 0x12) = 1;
    }
  }
  return;
}

