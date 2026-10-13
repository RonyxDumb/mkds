/* Decompiled C draft; module arm9; ROM address 02128294. No matching claim. */
#include "types.h"
#include "deps/02128294_func_02128294.h"

undefined4 func_02128294(void)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = 0;
  bVar1 = false;
  iVar3 = *piRam021282bc;
  if ((*(int *)(iVar3 + 4) == 2) && (*(int *)(iVar3 + iRam021282c0) == 0)) {
    bVar1 = true;
  }
  if ((bVar1) && (*(int *)(iVar3 + iRam021282c4) == 0)) {
    uVar2 = 1;
  }
  return uVar2;
}

