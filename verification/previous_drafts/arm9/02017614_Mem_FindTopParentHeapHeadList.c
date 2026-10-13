/* Decompiled C draft; module arm9; ROM address 02017614. No matching claim. */
#include "types.h"
#include "deps/02017614_Mem_FindTopParentHeapHeadList.h"

int Mem_FindTopParentHeapHeadList(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = iRam0201763c;
  iVar1 = Mem_FindTopParentHeapHead(iRam0201763c,param_1);
  if (iVar1 != 0) {
    iVar2 = iVar1 + 0xc;
  }
  return iVar2;
}

