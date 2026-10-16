/* Decompiled C draft; module arm9; ROM address 0202719c. No matching claim. */
#include "types.h"
#include "deps/0202719c_func_0202719c.h"

void func_0202719c(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *piRam020271d8;
  iVar2 = iRam020271dc + *(int *)(iVar1 + 0x60) * 8;
  *(undefined4 *)(*(int *)(iVar1 + 0x34) + iRam020271e0) = 1;
  *(undefined4 *)(*(int *)(iVar1 + 0x34) + iRam020271e4) = 0;
  *(undefined2 *)(*(int *)(iVar1 + 0x34) + *(short *)(iVar2 + 2) * 0x40 + 4) = 1;
  *(undefined2 *)(*(int *)(iVar1 + 0x34) + *(short *)(iVar2 + 2) * 0x40 + 6) = 1;
  return;
}

