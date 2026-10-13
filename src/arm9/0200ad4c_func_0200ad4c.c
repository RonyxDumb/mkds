/* Decompiled C draft; module arm9; ROM address 0200ad4c. No matching claim. */
#include "types.h"
#include "deps/0200ad4c_func_0200ad4c.h"

undefined4 func_0200ad4c(void)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = 0;
  bVar2 = false;
  bVar1 = false;
  iVar4 = *piRam0200ad90;
  if ((*(short *)(iVar4 + iRam0200ad94) == 1) && (*(char *)(iVar4 + iRam0200ad98) == '\0')) {
    bVar1 = true;
  }
  if ((bVar1) && (*(short *)(iVar4 + iRam0200ad9c) == 0)) {
    bVar2 = true;
  }
  if ((bVar2) && (*(short *)(iVar4 + iRam0200ada0) != 0)) {
    uVar3 = 1;
  }
  return uVar3;
}

