/* Decompiled C draft; module arm9; ROM address 0200b934. No matching claim. */
#include "types.h"
#include "deps/0200b934_func_0200b934.h"

void func_0200b934(void)

{
  int *piVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  
  puVar2 = puRam0200b9d0;
  piVar1 = piRam0200b9c0;
  iVar5 = *piRam0200b9c0;
  if (*(int *)(iVar5 + iRam0200b9c4) == 0) {
    puVar3 = (undefined1 *)(iVar5 + iRam0200b9cc);
    *puVar3 = *puRam0200b9d0;
    puVar3[1] = puVar2[1];
    puVar3[2] = puVar2[2];
    puVar3[3] = puVar2[3];
    puVar3[4] = puVar2[4];
    puVar3[5] = puVar2[5];
    *(undefined2 *)(*piVar1 + iRam0200b9c8) = 10;
    iVar5 = func_0200b72c();
    if (iVar5 == 0) {
      func_0200b820(0x1e,0);
      return;
    }
  }
  else {
    *(undefined2 *)(iVar5 + iRam0200b9c8) = 0xdc;
  }
  if (*(short *)(*piRam0200b9c0 + iRam0200b9d4) == 0) {
    *(short *)(*piRam0200b9c0 + iRam0200b9d4) = 1;
  }
  uVar4 = func_02143a78(uRam0200b9d8,*piRam0200b9c0 + iRam0200b9dc);
  if (uVar4 != 2) {
    func_0200b820(10,uVar4 & 0xffff);
  }
  return;
}

