/* Decompiled C draft; module arm9; ROM address 02129b60. No matching claim. */
#include "types.h"
#include "deps/02129b60_func_02129b60.h"

void func_02129b60(void)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *pbRam02129bd4;
  iVar2 = func_020ab748();
  if ((bVar1 - 1 == iVar2) &&
     (iVar2 = *piRam02129bd8,
     *(short *)(iVar2 + *(int *)(iVar2 + 4) * 0x18 + (bVar1 - 1) * 2 + 0x2c) != 0)) {
    *(undefined4 *)(iVar2 + 0x1c) = 1;
  }
  else {
    *(undefined4 *)(*piRam02129bd8 + 0x1c) = 0;
  }
  iVar2 = func_020ab8c4();
  if (iVar2 == 1) {
    *(undefined4 *)(*piRam02129bd8 + 0x14) = 1;
  }
  else {
    *(undefined4 *)(*piRam02129bd8 + 0x14) = 0;
  }
  iVar2 = func_020ab8c4();
  if (iVar2 == 2) {
    *(undefined4 *)(*piRam02129bd8 + 0x18) = 1;
    return;
  }
  *(undefined4 *)(*piRam02129bd8 + 0x18) = 0;
  return;
}

