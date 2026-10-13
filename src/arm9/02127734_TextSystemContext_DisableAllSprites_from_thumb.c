/* Decompiled C draft; module arm9; ROM address 02127734. No matching claim. */
#include "types.h"
#include "deps/02127734_TextSystemContext_DisableAllSprites_from_thumb.h"

void TextSystemContext_DisableAllSprites_from_thumb(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = iRam02127758;
  piVar1 = piRam02127754;
  iVar4 = 0;
  iVar3 = 0;
  do {
    *(undefined4 *)(*piVar1 + iVar3 + iVar2) = 0;
    iVar3 = iVar3 + 4;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 7);
  return;
}

