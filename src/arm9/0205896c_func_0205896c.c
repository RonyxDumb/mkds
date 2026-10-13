/* Decompiled C draft; module arm9; ROM address 0205896c. No matching claim. */
#include "types.h"
#include "deps/0205896c_func_0205896c.h"

void func_0205896c(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  
  bVar1 = true;
  bVar3 = false;
  piVar5 = (int *)*piRam020589d8;
  if ((*(ushort *)((int)piVar5 + iRam020589dc) & 0x40) != 0) {
    bVar2 = true;
    if (piVar5 == (int *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *piVar5;
    }
    if ((iVar4 != 1) && (*psRam020589e0 != 2)) {
      bVar2 = false;
    }
    if (bVar2) {
      bVar3 = true;
    }
  }
  if (bVar3) {
    iVar4 = func_0204bcdc();
    if (iVar4 == 2) {
      func_0204f8a0(*(undefined1 *)(*piRam020589d8 + iRam020589e4));
    }
    else {
      bVar1 = false;
    }
  }
  if (bVar1) {
    iVar4 = *piRam020589d8 + iRam020589e8;
    *(undefined2 *)(iVar4 + 0x10) = 2;
    *(undefined2 *)(iVar4 + 0x12) = 1;
  }
  return;
}

