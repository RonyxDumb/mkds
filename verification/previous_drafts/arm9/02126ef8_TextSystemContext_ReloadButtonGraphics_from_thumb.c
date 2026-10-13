/* Decompiled C draft; module arm9; ROM address 02126ef8. No matching claim. */
#include "types.h"
#include "deps/02126ef8_TextSystemContext_ReloadButtonGraphics_from_thumb.h"

void TextSystemContext_ReloadButtonGraphics_from_thumb(void)

{
  int iVar1;
  
  iVar1 = *piRam02126f6c;
  if (0 < *(int *)(iVar1 + 0x28)) {
    AllocateReserveTEQSub(0x1f,(0xee - *(int *)(iVar1 + 0x2c)) * 2,iVar1 + iRam02126f70,2);
    AllocateReserveTEQSub
              (0x1f,(0xfe - *(int *)(*piRam02126f6c + 0x2c)) * 2,*piRam02126f6c + iRam02126f70,2);
    iVar1 = *piRam02126f6c;
    if (*(int *)(iVar1 + 0x28) == 2) {
      AllocateReserveTEQSub(0x1f,(*(int *)(iVar1 + 0x2c) + 0xed) * 2,iVar1 + iRam02126f74,2);
      AllocateReserveTEQSub
                (0x1f,(*(int *)(*piRam02126f6c + 0x2c) + 0xfd) * 2,*piRam02126f6c + iRam02126f74,2);
    }
  }
  return;
}

