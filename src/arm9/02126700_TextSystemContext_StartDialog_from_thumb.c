/* Decompiled C draft; module arm9; ROM address 02126700. No matching claim. */
#include "types.h"
#include "deps/02126700_TextSystemContext_StartDialog_from_thumb.h"

void TextSystemContext_StartDialog_from_thumb(void)

{
  int *piVar1;
  
  piVar1 = (int *)*piRam0212672c;
  if (((*piVar1 == 0) && (piVar1[0xd] != 0)) || (*piVar1 - 1U < 2)) {
    piVar1[0xe] = 1;
  }
  else {
    piVar1[0xe] = 0;
  }
  *(undefined4 *)(*piRam0212672c + 0x34) = 1;
  return;
}

