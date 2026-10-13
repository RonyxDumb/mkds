/* Decompiled C draft; module arm9; ROM address 0205949c. No matching claim. */
#include "types.h"
#include "deps/0205949c_func_0205949c.h"

void func_0205949c(void)

{
  int *piVar1;
  byte *pbVar2;
  int iVar3;
  
  piVar1 = piRam020594c4;
  *(undefined4 *)(*piRam020594c4 + iRam020594c8) = 0;
  pbVar2 = (byte *)(*piVar1 + iRam020594cc);
  *pbVar2 = *pbVar2 & 0xfd;
  iVar3 = *piVar1 + iRam020594d0;
  *(undefined2 *)(iVar3 + 0x10) = 0x15;
  *(undefined2 *)(iVar3 + 0x12) = 1;
  return;
}

