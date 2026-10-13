/* Decompiled C draft; module arm9; ROM address 020cee28. No matching claim. */
#include "types.h"
#include "deps/020cee28_ResetB488HeyhoPaletteRows_from_thumb.h"

void ResetB488HeyhoPaletteRows_from_thumb(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = iRam020cee54;
  piVar1 = piRam020cee50;
  iVar3 = 0;
  do {
    *(undefined4 *)(*piVar1 + iVar3 * 4 + iVar2) = 0;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  *(undefined4 *)(*piVar1 + iRam020cee58) = 0;
  return;
}

