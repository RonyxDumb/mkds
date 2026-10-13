/* Decompiled C draft; module arm9; ROM address 02078078. No matching claim. */
#include "types.h"
#include "deps/02078078_CopySomeHeyhoPaletteRows_from_thumb.h"

void CopySomeHeyhoPaletteRows_from_thumb(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = iRam020780ac;
  piVar2 = piRam020780a8;
  piVar1 = piRam020780a4;
  uVar4 = 0;
  do {
    *(short *)(*piVar2 + uVar4 * 2 + 0x18) = (short)*(undefined4 *)(*piVar1 + uVar4 * 4 + iVar3);
    uVar4 = uVar4 + 1 & 0xffff;
  } while (uVar4 < 8);
  return;
}

