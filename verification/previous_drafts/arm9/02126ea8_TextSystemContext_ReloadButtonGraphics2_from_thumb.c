/* Decompiled C draft; module arm9; ROM address 02126ea8. No matching claim. */
#include "types.h"
#include "deps/02126ea8_TextSystemContext_ReloadButtonGraphics2_from_thumb.h"

void TextSystemContext_ReloadButtonGraphics2_from_thumb(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = iRam02126ef4;
  piVar1 = piRam02126ef0;
  if (0 < *(int *)(*piRam02126ef0 + 0x28)) {
    iVar3 = 0;
    do {
      AllocateReserveTEQSub(0x1f,(iVar3 + 0xed) * 2,*piVar1 + iVar2,2);
      AllocateReserveTEQSub(0x1f,(iVar3 + 0xfd) * 2,*piVar1 + iVar2,2);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 2);
  }
  return;
}

