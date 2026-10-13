/* Decompiled C draft; module arm9; ROM address 02125fc0. No matching claim. */
#include "types.h"
#include "deps/02125fc0_TextSystem_CloseDialog_from_thumb.h"

void TextSystem_CloseDialog_from_thumb(void)

{
  int *piVar1;
  
  piVar1 = piRam02125fd0;
  *(undefined4 *)(*piRam02125fd0 + 0x34) = 0;
  *(undefined4 *)(*piVar1 + 0x38) = 1;
  return;
}

