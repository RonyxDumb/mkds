/* Decompiled C draft; module arm9; ROM address 0205950c. No matching claim. */
#include "types.h"
#include "deps/0205950c_func_0205950c.h"

void func_0205950c(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = piRam02059544;
  *(undefined4 *)(*piRam02059544 + iRam02059548) = 0;
  *(byte *)(*piVar1 + iRam0205954c) = *(byte *)(*piVar1 + iRam0205954c) & 0xfd;
  iVar2 = *piVar1 + iRam02059550;
  *(undefined2 *)(iVar2 + 0x10) = 0x10;
  *(undefined2 *)(iVar2 + 0x12) = 1;
  *(undefined4 *)(*piVar1 + iRam02059554) = param_1;
  *(undefined4 *)(*piVar1 + iRam02059558) = param_2;
  return;
}

