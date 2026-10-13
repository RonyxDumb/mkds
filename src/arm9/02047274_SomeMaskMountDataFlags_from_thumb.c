/* Decompiled C draft; module arm9; ROM address 02047274. No matching claim. */
#include "types.h"
#include "deps/02047274_SomeMaskMountDataFlags_from_thumb.h"

void SomeMaskMountDataFlags_from_thumb(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = uRam020472a4;
  iVar2 = iRam020472a0;
  piVar1 = piRam0204729c;
  iVar5 = 0;
  iVar4 = 0;
  do {
    *(uint *)(*piVar1 + iVar2 + iVar4) = *(uint *)(*piVar1 + iVar2 + iVar4) & uVar3;
    iVar4 = iVar4 + 0xc;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x10);
  return;
}

