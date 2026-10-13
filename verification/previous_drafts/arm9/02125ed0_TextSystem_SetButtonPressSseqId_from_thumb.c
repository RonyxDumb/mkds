/* Decompiled C draft; module arm9; ROM address 02125ed0. No matching claim. */
#include "types.h"
#include "deps/02125ed0_TextSystem_SetButtonPressSseqId_from_thumb.h"

void TextSystem_SetButtonPressSseqId_from_thumb(int param_1,undefined4 param_2)

{
  *(undefined4 *)(*piRam02125ee0 + param_1 * 4 + iRam02125ee4) = param_2;
  return;
}

