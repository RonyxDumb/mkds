/* Decompiled C draft; module arm9; ROM address 0202b888. No matching claim. */
#include "types.h"
#include "deps/0202b888_func_0202b888.h"

uint func_0202b888(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  piVar1 = piRam0202b8bc;
  uVar5 = 1;
  iVar4 = 0;
  if (0 < *(int *)(*piRam0202b8bc + 0x48)) {
    iVar3 = 0;
    do {
      iVar2 = GetGlobalCA_from_thumb();
      uVar5 = uVar5 & *(uint *)(iVar2 + iVar3 + 0x14);
      iVar3 = iVar3 + 0x18;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(*piVar1 + 0x48));
  }
  return uVar5;
}

