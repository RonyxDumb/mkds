/* Decompiled C draft; module arm9; ROM address 020cb340. No matching claim. */
#include "types.h"
#include "deps/020cb340_func_020cb340.h"

void func_020cb340(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(*piRam020cb3d0 + iRam020cb3d4);
  iVar3 = *(int *)(*piRam020cb3d0 + iRam020cb3d8);
  iVar2 = 0;
  do {
    *(undefined4 *)(iVar4 + iVar2 * 0x40) = 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 10);
  iVar2 = 10;
  do {
    *(undefined4 *)(iVar4 + iVar2 * 0x40) = 0;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xf);
  iVar2 = func_020ccca8();
  if (iVar2 == 3) {
    if ((*(int *)(*piRam020cb3d0 + iRam020cb3dc) != 0) && (iVar2 = func_020ccccc(), iVar2 < 5))
    goto LAB_020cb39a;
  }
  *(undefined4 *)(iVar4 + (iVar3 + 5) * 0x40) = 0;
  *(undefined4 *)(iVar4 + (iVar3 + 10) * 0x40) = 1;
LAB_020cb39a:
  iVar2 = iRam020cb3e0;
  piVar1 = piRam020cb3d0;
  if (*(int *)(*piRam020cb3d0 + 0xc) == 3) {
    *(undefined2 *)(iVar4 + iVar3 * 0x40 + 4) = *(undefined2 *)(*piRam020cb3d0 + iRam020cb3e0);
    *(undefined2 *)(iVar4 + (iVar3 + 5) * 0x40 + 4) = *(undefined2 *)(*piVar1 + iVar2);
    *(undefined2 *)(iVar4 + (iVar3 + 10) * 0x40 + 4) = *(undefined2 *)(*piVar1 + iVar2);
  }
  return;
}

