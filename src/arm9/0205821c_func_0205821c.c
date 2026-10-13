/* Decompiled C draft; module arm9; ROM address 0205821c. No matching claim. */
#include "types.h"
#include "deps/0205821c_func_0205821c.h"

void func_0205821c(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = iRam020582cc;
  piVar4 = (int *)*piRam020582c0;
  if (piVar4 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *piVar4;
  }
  if (iVar2 == 1) {
    if (((uint)*(byte *)(*piRam020582c0 + iRam020582c8) &
        1 << (uint)*(byte *)(*piRam020582c0 + iRam020582c4)) == 0) {
      *(char *)((int)piVar4 + iRam020582c4) = *(char *)((int)piVar4 + iRam020582c4) + '\x01';
    }
    else {
      iVar3 = func_020504a4();
      if (iVar3 != 0) {
        *(char *)(*piRam020582c0 + iRam020582c4) = *(char *)(*piRam020582c0 + iRam020582c4) + '\x01'
        ;
      }
    }
    if (7 < *(byte *)(*piRam020582c0 + iRam020582c4)) {
      iVar3 = *piRam020582c0 + iRam020582cc;
      *(undefined2 *)(iVar3 + 0x10) = 6;
      *(undefined2 *)(iVar3 + 0x12) = 1;
      return;
    }
  }
  else {
    if (iVar2 != 2) {
      return;
    }
    bVar1 = *(byte *)(*piRam020582c0 + iRam020582c8);
    if (bVar1 == (bVar1 & *(byte *)(*piRam020582c0 + iRam020582d0))) {
      *(undefined2 *)((int)piVar4 + iRam020582cc + 0x10) = 6;
      *(undefined2 *)((int)piVar4 + iVar3 + 0x12) = 1;
    }
  }
  return;
}

