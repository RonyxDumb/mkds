/* Decompiled C draft; module arm9; ROM address 021269b8. No matching claim. */
#include "types.h"
#include "deps/021269b8_TextSystemContext_UpdateFn_State3_from_thumb.h"

void TextSystemContext_UpdateFn_State3_from_thumb(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = piRam021269f8;
  *(int *)(*piRam021269f8 + 0xc) = *(int *)(*piRam021269f8 + 0xc) + 1;
  *(undefined4 *)(*piVar1 + iRam021269fc) = 0;
  iVar2 = *(int *)(*piVar1 + 0xc);
  if (9 < iVar2) {
    *(undefined4 *)(*piVar1 + 0x30) = 1;
    *(undefined4 *)(*piVar1 + 4) = 2;
    *(undefined4 *)(*piVar1 + 0xc) = 0;
    return;
  }
  if (4 < iVar2) {
    TextSystemContext_ReloadButtonGraphics_from_thumb();
  }
  return;
}

