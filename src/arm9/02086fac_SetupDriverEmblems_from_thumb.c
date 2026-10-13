/* Decompiled C draft; module arm9; ROM address 02086fac. No matching claim. */
#include "types.h"
#include "deps/02086fac_SetupDriverEmblems_from_thumb.h"

void SetupDriverEmblems_from_thumb(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  
  piVar3 = piRam02086ff4;
  iVar2 = iRam02086ff0;
  piVar1 = piRam02086fec;
  uVar5 = 0;
  if (*(char *)(*piRam02086fec + iRam02086ff0) != '\0') {
    do {
      iVar4 = *piVar3 + uVar5 * 4;
      DriverContext_SetupEmblem_from_thumb
                (uVar5,*(undefined4 *)(iVar4 + iRam02086ff8),*(undefined4 *)(iVar4 + iRam02086ffc));
      uVar5 = uVar5 + 1 & 0xffff;
    } while (uVar5 < *(byte *)(*piVar1 + iVar2));
  }
  return;
}

